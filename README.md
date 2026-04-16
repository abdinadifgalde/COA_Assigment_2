📦 FSM-Based Cache Controller Simulation
📖 Description

This project simulates a cache controller using a Finite State Machine (FSM). It demonstrates how a CPU interacts with cache and main memory while processing read and write requests.

The simulation highlights:

Cache hit and miss behavior
FSM state transitions
Memory access delays
Cycle-by-cycle execution

This project is part of a Computer Organization and Architecture (COA) assignment.

⚙️ System Overview

The simulator models three main components:

🧠 CPU
Generates read (lw) and write (sw) requests
Sends requests sequentially to the cache controller
⚡ Cache
Stores frequently accessed data
Determines:
Cache Hit → Data found
Cache Miss → Data not found
🗄️ Main Memory
Always contains correct data
Responds with a delay (simulated using cycles)
🔄 FSM Design

The cache controller is implemented using a Finite State Machine with the following states:

IDLE → Waiting for CPU request
CHECK_CACHE → Checking for hit/miss
READ_MISS → Cache miss detected
MEMORY_READ → Fetching data from memory
(Optional) WRITE_MISS / WRITE_BACK → Handling writes
🔁 FSM Flow
IDLE → CHECK_CACHE → (HIT → IDLE)
                    ↓
                  MISS → READ_MISS → MEMORY_READ → IDLE
🧾 Example Input
lw 0
sw 10 1
lw 1
▶️ How to Run
🔧 Compile
g++ project.cpp -o cache_sim
▶️ Execute
./cache_sim
