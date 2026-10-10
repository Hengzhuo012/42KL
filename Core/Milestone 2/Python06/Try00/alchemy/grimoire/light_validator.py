import light_spellbook


def validate_ingredients(ingredients: str):
    allowed_list = light_spellbook.light_spell_allowed_ingredients()
    for allowed_ingredient in allowed_list:
        if (allowed_ingredient == ingredients):
            return f"{ingredients} - VALID"
    return f"{ingredients} - INVALID"
