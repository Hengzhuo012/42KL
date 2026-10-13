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


class ExportPlugin(typing.Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...


# Csv = Comma-Separated Values
class CsvExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        values = []
        for _, value in data:
            if any(char in value for char in ',"\r\n'):
                value = '"' + value.replace('"', '""') + '"'
            values.append(value)
        print("CSV Output:")
        print(",".join(values))


# Json = JavaScript Object Notation
class JsonExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        records = []
        for rank, value in data:
            escaped_chars = []
            for char in value:
                if char == '"':
                    escaped_chars.append('\\"')
                elif char == "\\":
                    escaped_chars.append("\\\\")
                elif char == "\b":
                    escaped_chars.append("\\b")
                elif char == "\f":
                    escaped_chars.append("\\f")
                elif char == "\n":
                    escaped_chars.append("\\n")
                elif char == "\r":
                    escaped_chars.append("\\r")
                elif char == "\t":
                    escaped_chars.append("\\t")
                elif ord(char) < 0x20:
                    escaped_chars.append(f"\\u{ord(char):04x}")
                else:
                    escaped_chars.append(char)
            escaped_value = "".join(escaped_chars)
            records.append(f'"item_{rank - 1}": "{escaped_value}"')
        print("JSON Output:")
        print("{" + ", ".join(records) + "}")


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

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for processor in self._processors:
            data: list[tuple[int, str]] = []
            for _ in range(nb):
                try:
                    data.append(processor.output())
                except IndexError:
                    break
            plugin.process_output(data)


def test_data_pipeline() -> None:
    print("=== Code Nexus - Data Pipeline ===")
    print("")
    print("Initialize Data Stream...")
    data_stream = DataStream()
    print("")
    data_stream.print_processors_stats()
    print("")
    print("Registering Processors")
    num_processor = NumericProcessor()
    text_processor = TextProcessor()
    log_processor = LogProcessor()
    data_stream.register_processor(num_processor)
    data_stream.register_processor(text_processor)
    data_stream.register_processor(log_processor)
    print("")

    data = ['Hello world', [3.14, -1, 2.71],
            [{'log_level': 'WARNING',
              'log_message': 'Telnet access! Use ssh instead'},
             {'log_level': 'INFO', 'log_message': 'User wil is connected'}],
            42, ['Hi', 'five']]
    print(f"Send first batch of data on stream: {data}")
    data_stream.process_stream(data)
    print("")
    data_stream.print_processors_stats()
    print("")

    n = 3
    print(f"Send {n} processed data from each processor to a CSV plugin:")
    csv_export_plugin = CsvExportPlugin()
    data_stream.output_pipeline(n, csv_export_plugin)
    print("")
    data_stream.print_processors_stats()
    print("")

    data_2 = [21, ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
              [{'log_level': 'ERROR', 'log_message': '500 server crash'},
               {'log_level': 'NOTICE',
                'log_message': 'Certificate expires in 10 days'}],
              [32, 42, 64, 84, 128, 168], 'World hello']
    print(f"Send another batch of data: {data_2}")
    data_stream.process_stream(data_2)
    print("")
    data_stream.print_processors_stats()
    print("")

    n = 5
    print(f"Send {n} processed data from each processor to a JSON plugin:")
    json_export_plugin = JsonExportPlugin()
    data_stream.output_pipeline(n, json_export_plugin)
    print("")
    data_stream.print_processors_stats()


if __name__ == "__main__":
    test_data_pipeline()
