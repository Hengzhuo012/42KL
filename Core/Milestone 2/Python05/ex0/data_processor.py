import typing
import abc


class ValidateError(Exception):
    "value does not pass validate"
    pass


class DataProcessor(abc.ABC):
    @abc.abstractmethod
    def validate(self, data: typing.Any) -> bool:
        pass

    @abc.abstractmethod
    def ingest(self, data: typing.Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        return


class NumericProcessor(DataProcessor):
    def ingest(self, data: typing.Any):
        try:
            if self.validate(data) is False:
                raise ValidateError()
            if isinstance(data, int | float):
                new_data = str(data)
            elif isinstance(data, list):
                new_data = []
                for value in data:
                    new_data.append(str(value))
            self.output(new_data)
        except ValidateError:
            print("Data is not validated")

    def validate(self, data: typing.Any) -> bool:
        try:
            if isinstance(data, int | float):
                str(data)
            elif isinstance(data, list):
                for value in data:
                    if isinstance(value, int) and isinstance(value, float):
                        return False
                    str(value)
            else:
                return False
            return True
        except ValueError:
            return False


class TextProcessor(DataProcessor):
    def ingest(self, data: typing.Any) -> None:
        try:
            if self.validate(data) is False:
                raise ValidateError()
        except ValidateError:
            print("Data is not validated")
