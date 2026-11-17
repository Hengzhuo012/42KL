# • install: Install project dependencies using pip, uv, pipx, or any other package
# manager of your choice.
# • run: Execute the main script of your project (e.g., via Python interpreter).
# • debug: Run the main script in debug mode using Python’s built-in debugger (e.g.,
# pdb).
# • clean: Remove temporary files or caches (e.g., __pycache__, .mypy_cache) to
# keep the project environment clean.
# • lint: Execute the commands flake8 . and mypy . --warn-return-any
# --warn-unused-ignores --ignore-missing-imports --disallow-untyped-defs
# --check-untyped-defs
# • lint-strict (optional): Execute the commands flake8 . and mypy . --strict
# Create test programs to verify project functionality (not submitted or graded). Use
# frameworks like pytest or unittest for unit tests, covering edge cases.
# • Include a .gitignore file to exclude Python artifacts.
# • It is recommended to use virtual environments (e.g., venv or conda) for dependency
# isolation during development.
# If any additional project-specific requirements apply, they will be stated immediately below
# this section.

#installed mypy, flake8, pydantic

install:
	command -v uv > /dev/null 2>&1 || python -m pipx install uv
	uv sync

run:
	uv run python src/amazing.py config.txt

debug:
	uv run python -m pdb src/amazing.py config.txt

lint:
	uv run flake8 . 
	uv run mypy . --warn-return-any --warn-unused-ignores --ignore-missing-imports --disallow-untyped-defs \
	--check-untyped-defs

clean:
	find . -path ./.venv -prune -o -type d \
		\( -name __pycache__ -o -name .mypy_cache \
		-o -name .pytest_cache -o -name .ruff_cache \
		-o -name '*.egg-info' \) -exec rm -rf {} +
	rm -rf build dist

fix:
	uvx ruff format --line-length 79 src
	uvx ruff check --fix --select E,W,F src

check:
	python3 maze_analyzer.py output_maze.txt

.PHONY: install run clean lint lint-strict fix debug check
# .SILENT: install run clean lint lint-strict fix debug