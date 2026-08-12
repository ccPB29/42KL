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


def main() -> None:
    numeric = NumericProcessor()
    text = TextProcessor()
    log = LogProcessor()

    print("=== Code Nexus - Data Processor ===")
    print()

    print("Testing Numeric Processor...")
    print(f" Trying to validate input '42': {numeric.validate(42)}")
    print(f" Trying to validate input 'Hello': {numeric.validate('Hello')}")

    print(" Test invalid ingestion of string 'foo' without prior validation:")
    try:
        numeric.ingest("foo")
    except ValueError as error:
        print(f" Got exception: {error}")

    numeric.ingest([1, 2, 3, 4, 5])

    print(" Processing data: [1, 2, 3, 4, 5]")
    print(" Extracting 3 values...")

    for _ in range(3):
        rank, value = numeric.output()
        print(f" Numeric value {rank}: {value}")

    print()
    print("Testing Text Processor...")
    print(f" Trying to validate input '42': {text.validate(42)}")
    print(f" Trying to validate input 'Hello': {text.validate('Hello')}")

    text.ingest(["Hello", "Nexus", "World"])
    print(" Processing data: ['Hello', 'Nexus', 'World']")
    print(" Extracting 1 value...")

    rank, value = text.output()
    print(f" Text value {rank}: {value}")

    print()
    print("Testing Log Processor...")
    print(f" Trying to validate input 'Hello': {log.validate('Hello')}")

    logs = [
        {
            "log_level": "NOTICE",
            "log_message": "Connection to server"
        },
        {
            "log_level": "ERROR",
            "log_message": "Unauthorized access!!"
        }
    ]
    print(f" Trying to validate input '{logs}': {log.validate(logs)}")

    log.ingest(logs)
    print(f" Processing data: {logs}")
    print(" Extracting 2 values...")

    for _ in range(2):
        rank, value = log.output()
        print(f" Log entry {rank}: {value}")


if __name__ == "__main__":
    main()
