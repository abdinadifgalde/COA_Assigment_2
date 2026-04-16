#include <bits/stdc++.h>
using namespace std;

// FSM States
enum State {
    IDLE,
    CHECK_CACHE,
    READ_HIT,
    READ_MISS,
    WRITE_HIT,
    WRITE_MISS,
    MEMORY_READ,
    MEMORY_WRITE,
    WAIT
};

string stateName(State s) {
    switch(s) {
        case IDLE: return "IDLE";
        case CHECK_CACHE: return "CHECK_CACHE";
        case READ_HIT: return "READ_HIT";
        case READ_MISS: return "READ_MISS";
        case WRITE_HIT: return "WRITE_HIT";
        case WRITE_MISS: return "WRITE_MISS";
        case MEMORY_READ: return "MEMORY_READ";
        case MEMORY_WRITE: return "MEMORY_WRITE";
        case WAIT: return "WAIT";
    }
    return "";
}

// Simple Cache (direct-mapped style)
map<int, int> cache;
map<int, int> memory;

int MEMORY_DELAY = 2;

int main() {
    ifstream file("input.txt");

    string op;
    int addr, data;
    int cycle = 0;

    State current = IDLE;

    while (file >> op) {
        cycle++;
        cout << "\n=== Cycle " << cycle << " ===\n";

        if (op == "lw") {
            file >> addr;
            cout << "CPU Request: READ " << addr << endl;

            current = CHECK_CACHE;
            cout << "State: " << stateName(current) << endl;

            if (cache.find(addr) != cache.end()) {
                current = READ_HIT;
                cout << "Cache HIT\n";
                cout << "State: " << stateName(current) << endl;
                cout << "Data = " << cache[addr] << endl;
            } else {
                current = READ_MISS;
                cout << "Cache MISS\n";
                cout << "State: " << stateName(current) << endl;

                current = MEMORY_READ;
                cout << "State: " << stateName(current) << endl;

                for (int i = 1; i <= MEMORY_DELAY; i++) {
                    cout << "Waiting... (" << i << ")\n";
                }

                // Load from memory (default value if not exist)
                if (memory.find(addr) == memory.end())
                    memory[addr] = addr * 10;

                cache[addr] = memory[addr];

                cout << "Loaded from memory: " << memory[addr] << endl;

                current = IDLE;
                cout << "State: " << stateName(current) << endl;
            }
        }

        else if (op == "sw") {
            file >> data >> addr;
            cout << "CPU Request: WRITE " << data << " -> " << addr << endl;

            current = CHECK_CACHE;
            cout << "State: " << stateName(current) << endl;

            if (cache.find(addr) != cache.end()) {
                current = WRITE_HIT;
                cout << "Cache HIT\n";
                cout << "State: " << stateName(current) << endl;
            } else {
                current = WRITE_MISS;
                cout << "Cache MISS\n";
                cout << "State: " << stateName(current) << endl;
            }

            current = MEMORY_WRITE;
            cout << "State: " << stateName(current) << endl;

            for (int i = 1; i <= MEMORY_DELAY; i++) {
                cout << "Writing... (" << i << ")\n";
            }

            memory[addr] = data;
            cache[addr] = data;

            cout << "Write complete\n";

            current = IDLE;
            cout << "State: " << stateName(current) << endl;
        }

        else if (op == "nop") {
            cout << "No Operation\n";
            current = IDLE;
            cout << "State: " << stateName(current) << endl;
        }
    }

    return 0;
}
