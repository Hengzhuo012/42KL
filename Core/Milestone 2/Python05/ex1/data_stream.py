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


class DataStream:
    def __init__(self) -> None:
        self._processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self._processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        for element in stream:
            for processor in self._processors:
                if processor.validate(element):
                    processor.ingest(element)
                    break
            else:
                print(
                    "DataStream error - Can't process element in stream: "
                    f"{element}"
                )

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if not self._processors:
            print("No processor found, no data")
            return
        for processor in self._processors:
            processor_name = type(processor).__name__.replace(
                "Processor", " Processor"
            )
            print(
                f"{processor_name}: total {processor._next_rank - 1} "
                f"items processed, remaining {len(processor._data)} "
                "on processor"
            )


def test_data_stream() -> None:
    print("=== Code Nexus - Data Stream ===")
    print("")
    print("Initialize Data Stream...")
    data_stream = DataStream()
    numeric_processor = NumericProcessor()
    text_processor = TextProcessor()
    log_processor = LogProcessor()
    data_stream.print_processors_stats()
    print("")

    print("Registering Numeric Processor")
    data_stream.register_processor(numeric_processor)
    print("")
    data = ['Hello world', [3.14, -1, 2.71],
            [{'log_level': 'WARNING',
              'log_message': 'Telnet access! Use ssh instead'},
             {'log_level': 'INFO', 'log_message': 'User wil is connected'}],
            42, ['Hi', 'five']]
    print(f"Send first batch of data on stream: {data}")
    data_stream.process_stream(data)
    data_stream.print_processors_stats()
    print("")

    print("Registering other data processors")
    data_stream.register_processor(text_processor)
    data_stream.register_processor(log_processor)
    print("Send the same batch again")
    data_stream.process_stream(data)
    data_stream.print_processors_stats()
    print("")

    n_num = 3
    n_text = 2
    n_log = 1
    print(f"Consume some elements from the data processors: "
          f"Numeric {n_num}, Text {n_text}, Log {n_log}")
    for _ in range(n_num):
        numeric_processor.output()
    for _ in range(n_text):
        text_processor.output()
    for _ in range(n_log):
        log_processor.output()
    data_stream.print_processors_stats()


if __name__ == "__main__":
    test_data_stream()