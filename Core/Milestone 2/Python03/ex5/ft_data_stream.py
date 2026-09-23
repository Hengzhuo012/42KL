import typing
import random
# typing.Generator[YieldType, SendType, ReturnType]


def gen_event() -> typing.Generator[tuple[str, str], None, None]:
    name_list = ["alice", "bob", "charlie", "dylan"]
    action_list = ["run", "eat", "sleep", "grab", "move", "climb", "swim"]

    while True:
        yield random.choice(name_list), random.choice(action_list)


def consume_event(event_list: list[tuple[str, str]]) \
                  -> typing.Generator[tuple[str, str], None, None]:
    while event_list:
        one_event = random.choice(event_list)
        event_list.remove(one_event)
        yield one_event


def ft_data_stream():
    event = gen_event()
    print("=== Game Data Stream Processor ===")
    for i in range(1000):
        name, action = next(event)
        print(f"Event {i}: Player {name} did action {action}")

    event_list: list[tuple[str, str]] = []
    for i in range(10):
        event_list.append(next(event))
    print(f"Built list of 10 events: {event_list}")
    for one_event in consume_event(event_list):
        print(f"Got event from list: {one_event}")
        print(f"Remains in list: {event_list}")


if __name__ == "__main__":
    ft_data_stream()
