from .light_validator import validate_ingredients


def light_spell_allowed_ingredients() -> list[str]:
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    result = validate_ingredients(ingredients)
    action = (
        "Spell recorded" if result.endswith(" - VALID") else "Spell rejected"
    )
    return f"{action}: {spell_name} ({result})"
