import alchemy.grimoire as grimoire

if __name__ == "__main__":
    print("=== Kaboom 0 ===")
    print("Using grimoire module directly")
    spell_record = grimoire.light_spellbook.light_spell_record(
        "Fantasy", "Earth, wind and fire"
    )
    print(f"Testing record light spell: {spell_record}")
