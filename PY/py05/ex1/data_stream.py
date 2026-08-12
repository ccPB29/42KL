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

        if isinstance(data, list):
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

        if isinstance(data, list):
            for item in data:
                self._data.append(
                    f"{item['log_level']}: {item['log_message']}"
                )
        else:
            self._data.append(f"{data['log_level']}: {data['log_message']}")


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
                    f"DataStream error - Can't "
                    f"process element in stream: {data}"
                )

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")

        if len(self._processors) == 0:
            print("No processor found, no data")
            return

        for proc in self._processors:
            total = proc._rank + len(proc._data)
            remaining = len(proc._data)
            class_name = proc.__class__.__name__

            print(
                f'{class_name.replace("Processor", " Processor")}: '
                f"total {total} items processed, "
                f"remaining {remaining} on processor"
            )


def main() -> None:
    print("=== Code Nexus - Data Stream ===")
    print()

    stream = DataStream()

    print("Initialize Data Stream...")
    stream.print_processors_stats()
    print()

    print("Registering Numeric Processor")
    print()
    numeric = NumericProcessor()
    stream.register_processor(numeric)

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
    stream.print_processors_stats()
    print()

    print("Registering other data processors")
    text = TextProcessor()
    log = LogProcessor()

    stream.register_processor(text)
    stream.register_processor(log)

    print("Send the same batch again")
    stream.process_stream(data)
    stream.print_processors_stats()
    print()

    print(
        "Consume some elements from the data processors: "
        "Numeric 3, Text 2, Log 1"
    )

    for _ in range(3):
        numeric.output()

    for _ in range(2):
        text.output()

    log.output()

    stream.print_processors_stats()


if __name__ == "__main__":
    main()
