from .dark_spellbook import dark_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    allowed_ingredients = dark_spell_allowed_ingredients()
    is_valid = any(
        allowed.lower() in ingredients.lower()
        for allowed in allowed_ingredients
    )
    result = "VALID" if is_valid else "INVALID"
    return f"{ingredients} - {result}"
