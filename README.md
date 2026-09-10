# Constraint-Based Board Coloring Solver

A C++ backtracking solver for an N×N board coloring puzzle: assign colors to cells subject to adjacency rules and per-color usage constraints.

## Problem

Given an N×N board (N ≤ 10), a set of colors, some pre-fixed cells, and a minimum/maximum usage count per color, find all valid colorings such that no two orthogonally adjacent cells share the same color, and every color's usage stays within its configured range.

## How it works

The solver uses classic backtracking: at each empty cell, every color that doesn't violate adjacency or the color's maximum usage is tried; the algorithm recurses to the next cell, then undoes the choice on backtrack. A solution is only accepted once the whole board is filled and every color's usage falls within its min/max range.

## Design

- `Casilla` — a single board cell (position, color, whether it's colored/fixed)
- `Color` — a color's name, ANSI display code, and usage constraints
- `Tablero` — the N×N grid and adjacency/constraint checks
- `SolucionColoreado` — a board configuration paired with color usage tracking
- `Estado` — the current search position (row, column) and valid next moves
- `Problema` — orchestrates the backtracking search and collects solutions

## Build

```bash
g++ -std=c++11 -o coloreado main.cpp Casilla.cpp Color.cpp Tablero.cpp estado.cpp problema.cpp solucioncoloreado.cpp
```

## Run

```bash
./coloreado
```

The program interactively asks for the board dimension, the colors to register, any fixed cells, and a min/max usage range per color, then prints every valid solution found.

## Notes

Originally written in Spanish; source comments and identifiers still reflect this.M essages have been translated to English.