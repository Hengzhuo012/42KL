from pydantic import BaseModel, Field, ValidationError, model_validator
from datetime import datetime
from enum import Enum


class Rank(Enum):
    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class CrewMember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = "planned"
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode="after")
    def check_safety_requirements(self):
        if not self.mission_id.startswith("M"):
            raise ValueError("Mission ID must start with \"M\"")
        exists_commander_or_captain = False
        for crew_data in self.crew:
            if crew_data.rank in (Rank.COMMANDER, Rank.CAPTAIN):
                exists_commander_or_captain = True
                break
        if not exists_commander_or_captain:
            raise ValueError(
                "Must have at least one Commander or Captain"
                )
        if self.duration_days > 365:
            experienced_crew_count = sum(
                crew_data.years_experience >= 5 for crew_data in self.crew
            )
            if experienced_crew_count * 2 < len(self.crew):
                raise ValueError(
                    "Long missions (>365 days) need "
                    "50% experienced crew (5+ years)"
                    )
        for crew_data in self.crew:
            if not crew_data.is_active:
                raise ValueError("All crew member must be active")
        return self


def main():
    print("Space Mission Crew Validation")
    print("=" * 50)
    space_mission = SpaceMission(
        mission_id="M2024_MARS",
        mission_name="Mars Colony Establishment",
        destination="Mars",
        launch_date=datetime.now(),
        duration_days=900,
        crew=[
            CrewMember(
                member_id="123456",
                name="Sarah Connor",
                rank=Rank.COMMANDER,
                age=45,
                specialization="Mission Command",
                years_experience=15,
            ),
            CrewMember(
                member_id="123457",
                name="John Smith",
                rank=Rank.LIEUTENANT,
                age=39,
                specialization="Navigation",
                years_experience=10,
            ),
            CrewMember(
                member_id="123458",
                name="Alice Johnson",
                rank=Rank.OFFICER,
                age=27,
                specialization="Engineering",
                years_experience=3,
            )
        ],
        budget_millions=2500.0,
    )
    print("Valid mission created:")
    print(f"Mission: {space_mission.mission_name}")
    print(f"ID: {space_mission.mission_id}")
    print(f"Destination: {space_mission.destination}")
    print(f"Duration: {space_mission.duration_days} days")
    print(f"Budget: ${space_mission.budget_millions}M")
    print(f"Crew size: {len(space_mission.crew)}")
    print("Crew members:")
    for crew_data in space_mission.crew:
        print(f"- {crew_data.name} ({crew_data.rank.value})"
              f" - {crew_data.specialization}")
    print()
    print("=" * 40)
    print("Expected validation error:")
    try:
        space_mission = SpaceMission(
            mission_id="M2024_MARS",
            mission_name="Mars Colony Establishment",
            destination="Mars",
            launch_date=datetime.now(),
            duration_days=900,
            crew=[
                CrewMember(
                    member_id="123456",
                    name="Sarah Connor",
                    rank=Rank.OFFICER,
                    age=45,
                    specialization="Mission Command",
                    years_experience=15,
                ),
                CrewMember(
                    member_id="123457",
                    name="John Smith",
                    rank=Rank.LIEUTENANT,
                    age=39,
                    specialization="Navigation",
                    years_experience=10,
                ),
                CrewMember(
                    member_id="123458",
                    name="Alice Johnson",
                    rank=Rank.OFFICER,
                    age=27,
                    specialization="Engineering",
                    years_experience=3,
                )
            ],
            budget_millions=2500.0,
        )
    except ValidationError as error:
        print(error.errors()[0]["msg"])


if __name__ == "__main__":
    main()
