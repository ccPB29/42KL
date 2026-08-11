import abc
import typing


class DataProcessor(abc.ABC):
    def __init__(self) -> None:
        self._data: list[str] = []
        self._rank = 0

    @abc.abstractmethod
    def validate(self, data: typing.Any) -> bool:
        pass

    @abc.abstractmethod
    def ingest(self, data: typing.Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if len(self._data) == 0:
            raise ValueError("No data available")

        data = self._data.pop(0)
        rank = self._rank
        self._rank += 1

        return (rank, data)


class NumericProcessor(DataProcessor):
    def validate(self, data: typing.Any) -> bool:
        if type(data) in (int, float):
            return True

        if type(data) is list:
            for item in data:
                if type(item) not in (int, float):
                    return False
            return True

        return False

    def ingest(
        self,
        data: int | float | list[int | float]
    ) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")

        if type(data) is list:
            for item in data:
                self._data.append(str(item))
        else:
            self._data.append(str(data))


class TextProcessor(DataProcessor):
    def validate(self, data: typing.Any) -> bool:
        if type(data) is str:
            return True

        if type(data) is list:
            for item in data:
                if type(item) is not str:
                    return False
            return True

        return False

    def ingest(
        self,
        data: str | list[str]
    ) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")

        if type(data) is list:
            for item in data:
                self._data.append(item)
        else:
            self._data.append(data)


class LogProcessor(DataProcessor):
    def validate(self, data: typing.Any) -> bool:
        if type(data) is dict:
            for key, value in data.items():
                if type(key) is not str or type(value) is not str:
                    return False
            return True

        if type(data) is list:
            for item in data:
                if type(item) is not dict:
                    return False
                for key, value in item.items():
                    if type(key) is not str or type(value) is not str:
                        return False
            return True

        return False

    def ingest(
        self,
        data: dict[str, str] | list[dict[str, str]]
    ) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")

        if type(data) is list:
            for item in data:
                self._data.append(f"{item['log_level']}: {item['log_message']}")
        else:
            self._data.append(f"{data['log_level']}: {data['log_message']}")


class ExportPlugin(typing.Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...


class DataStream:
    def __init__(self) -> None:
        self._processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self._processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        for data in stream:
            handled = False

            for proc in self._processors:
                if proc.validate(data):
                    proc.ingest(data)
                    handled = True
                    break
            
            if not handled:
                print(
                    f"DataStream error - Can't process element in stream: {data}"
                )

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")

        if len(self._processors) == 0:
            print("No processor found, no data")
            return

        for proc in self._processors:
            total = proc._rank + len(proc._data)
            remaining = len(proc._data)

            print(
                f'{proc.__class__.__name__.replace("Processor", " Processor")}: '
                f"total {total} items processed, "
                f"remaining {remaining} on processor"
            )

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for proc in self._processors:
            data: list[tuple[int, str]] = []
            for _ in range(nb):
                if len(proc._data) == 0:
                    break
                data.append(proc.output())
            plugin.process_output(data)


class CSVPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        values: list[str] = []

        for _, value in data:
            values.append(value)

        print("CSV Output:")
        print(",".join(values))


class JSONPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        items: list[str] = []

        for rank, value in data:
            items.append(f'"item_{rank}": "{value}"')

        print("JSON Output:")
        print("{" + ", ".join(items) + "}")


def main() -> None:
    print("=== Code Nexus - Data Pipeline ===")
    print()

    stream = DataStream()

    print("Initialize Data Stream...")
    print()
    stream.print_processors_stats()
    print()

    print("Registering Processors")
    print()

    numeric = NumericProcessor()
    text = TextProcessor()
    log = LogProcessor()

    stream.register_processor(numeric)
    stream.register_processor(text)
    stream.register_processor(log)
    
    data = [
        "Hello world",
        [3.14, -1, 2.71],
        [
            {
                "log_level": "WARNING",
                "log_message": "Telnet access! Use ssh instead"
            },
            {
                "log_level": "INFO",
                "log_message": "User Wil is connected"
            }
        ],
        42,
        ["Hi", "five"]
    ]

    print(f"Send first batch of data on stream: {data}")

    stream.process_stream(data)
    print()
    stream.print_processors_stats()
    print()

    print("Send 3 processed data from each processor to a CSV plugin:")
    csv_plugin = CSVPlugin()
    stream.output_pipeline(3, csv_plugin)
    print()

    stream.print_processors_stats()
    print()

    da = [
        21,
        ["I love AI", "LLMs are wonderful", "Stay healthy"],
        [
            {
                "log_level": "ERROR",
                "log_message": "500 server crash"
            },
            {
                "log_level": "NOTICE",
                "log_message": "Certificate expires in 10 days"
            }
        ],
        [32, 42, 64, 84, 128, 168],
        "World hello"
    ]

    print(f"Send another batch of data: {da}")

    stream.process_stream(da)
    print()
    stream.print_processors_stats()
    print()

    print("Send 5 processed data from each processor to a JSON plugin:")
    json_plugin = JSONPlugin()
    stream.output_pipeline(5, json_plugin)
    print()

    stream.print_processors_stats()


if __name__ == "__main__":
    main()
