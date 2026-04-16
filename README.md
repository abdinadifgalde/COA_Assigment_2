# FSM-Based Cache Controller Simulation

## Description
This project simulates a simple cache controller using a Finite State Machine (FSM). 
It processes CPU read/write requests and shows cache hit/miss behavior and memory delays.

## Features
- FSM-based state transitions
- Cache hit/miss detection
- Memory delay simulation
- Cycle-by-cycle output

## Files
- project.cpp → main simulation code
- input.txt → CPU request sequence

## How to Run

### Compile
g++ project.cpp -o cache_sim

### Run
./cache_sim

## Example Input
lw 0
sw 10 1
lw 1

## Output
Shows state transitions, memory wait cycles, and results.
