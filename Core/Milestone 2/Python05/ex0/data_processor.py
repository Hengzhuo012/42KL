import abc
import typing


class ValidateError(Exception):
    "value does not pass validate"
    pass


class DataProcessor(abc.ABC):
    def __init__(self) -> None:
        self._data: list[tuple[int, str]] = []
        self._next_rank = 1

    @abc.abstractmethod
    def validate(self, data: typing.Any) -> bool:
        raise NotImplementedError

    @abc.abstractmethod
    def ingest(self, data: typing.Any) -> None:
        raise NotImplementedError

    def output(self) -> tuple[int, str]:
        return self._data.pop(0)


class NumericProcessor(DataProcessor):
    def ingest(self, data: int | float | list[int | float]) -> None:
        if not self.validate(data):
            raise ValidateError("Improper numeric data")
        values = data if isinstance(data, list) else [data]
        for value in values:
            self._data.append((self._next_rank, str(value)))
            self._next_rank += 1

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, (int, float)):
            return True
        return isinstance(data, list) and all(
            isinstance(value, (int, float)) for value in data
        )


class TextProcessor(DataProcessor):
    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise ValidateError("data must be a string or a list of strings")
        values = data if isinstance(data, list) else [data]
        for value in values:
            self._data.append((self._next_rank, value))
            self._next_rank += 1

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, str):
            return True
        return isinstance(data, list) and all(
            isinstance(value, str) for value in data
        )


class LogProcessor(DataProcessor):
    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise ValidateError(
                "data must be a string mapping or a list of mappings"
            )
        values = data if isinstance(data, list) else [data]
        for value in values:
            formatted_value = ": ".join(value.values())
            self._data.append((self._next_rank, formatted_value))
            self._next_rank += 1

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, dict):
            return all(
                isinstance(key, str) and isinstance(value, str)
                for key, value in data.items()
            )
        return isinstance(data, list) and all(
            isinstance(item, dict)
            and all(
                isinstance(key, str) and isinstance(value, str)
                for key, value in item.items()
            )
            for item in data
        )


def test_numeric_processor():
    print("Testing Numeric Processor...")
    num_processor = NumericProcessor()
    num = 42
    print(f" Trying to validate input '{num}': {num_processor.validate(num)}")
    num = "Hello"
    print(f" Trying to validate input '{num}': {num_processor.validate(num)}")
    num = "foo"
    print(f" Test invalid ingestion of string '{num}' "
          "without prior validation:")
    try:
        num_processor.ingest(num)
    except ValidateError as error:
        print(f" Got exception: {error}")
    num = [1, 2, 3, 4, 5]
    print(f" Processing data: {num}")
    num_processor.ingest(num)
    n = 3
    print(f" Extracting {n} values...")
    for i in range(n):
        _, value = num_processor.output()
        print(f" Numeric value {i}: {value}")


def test_text_processor():
    print("Testing Text Processor...")
    text_processor = TextProcessor()
    text = 42
    print(f" Trying to validate input '{text}': "
          "{text_processor.validate(text)}")
    text = ["Hello", "Nexus", "World"]
    print(f" Processing data: {text}")
    text_processor.ingest(text)
    n = 1
    print(f" Extracting {n} values...")
    for i in range(n):
        _, value = text_processor.output()
        print(f" Text value {i}: {value}")


def test_log_processor():
    print("Testing Log Processor...")
    log_processor = LogProcessor()
    log = "Hello"
    print(f" Trying to validate input '{log}': {log_processor.validate(log)}")
    log = [{'log_level': 'NOTICE', 'log_message': 'Connection to server'},
           {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}]
    print(f" Processing data: {log}")
    log_processor.ingest(log)
    n = 2
    print(f" Extracting {n} values...")
    for i in range(n):
        _, value = log_processor.output()
        print(f" Log entry {i}: {value}")


def test_data_processor():
    print("=== Code Nexus - Data Processor ===")
    print("")
    test_numeric_processor()
    print("")
    test_text_processor()
    print("")
    test_log_processor()


if __name__ == "__main__":
    test_data_processor()
