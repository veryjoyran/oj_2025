#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Process {
    string name;
    int time;
};

int main() {
    int n, q;
    cin >> n >> q;
    queue<Process> processes;
    for (int i = 0; i < n; ++i) {
        Process p;
        cin >> p.name >> p.time;
        processes.push(p);
    }

    int currentTime = 0;
    while (!processes.empty()) {
        Process p = processes.front();
        processes.pop();
        if (p.time <= q) {
            currentTime += p.time;
            cout << p.name << " " << currentTime << std::endl;
        } else {
            currentTime += q;
            p.time -= q;
            processes.push(p);
        }
    }

    return 0;
}
