# Quantum Escape

Quantum Escape is a 2D action game built in C with SDL.

## Overview

The player navigates through different levels, avoids obstacles, and completes challenges in order to escape.

The project demonstrates:

- SDL-based rendering
- game state management
- level design
- sound integration
- gameplay logic in C

## Tech Stack

- C
- SDL

## Repository Structure

- `main.c` main game loop
- `background.*` background rendering
- `perso.*` player logic
- `ennemi.*` enemy logic
- `enigme.*` puzzle logic
- `sauvegarde.*` save and load logic
- `Makefile` build entry point
- asset folders for images, sounds, levels, and UI elements

## Getting Started

1. Install SDL and the required compiler toolchain.
2. Build the project with the provided `Makefile`.
3. Run the game executable.
4. Test the menu, level flow, and save/load behavior.

## Branching and Commits

- Use branches such as `feat/<area>`, `fix/<area>`, `docs/<area>`, or `game/<area>`
- Keep commits focused on one gameplay or asset change
- Prefer Conventional Commits such as `feat(game): add new obstacle pattern`
- Avoid vague messages like `final`, `update`, or `test`

## Contributing

- Keep gameplay changes easy to test
- Document asset or platform assumptions clearly
- Avoid committing build outputs or temporary generated files
