def validate_ingredients(ingredients: str) -> str:
    from .light_spellbook import light_spell_allowed_ingredients

    allowed_ingredients = light_spell_allowed_ingredients()
    is_valid = any(
        allowed.lower() in ingredients.lower()
        for allowed in allowed_ingredients
    )
    result = "VALID" if is_valid else "INVALID"
    return f"{ingredients} - {result}"
