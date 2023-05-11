#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int ct; // completion time
    int tat; // turnaround time
    int wt; // waiting time
};

int main() {
    int n;
    queue<Process> q;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Process p;
        cout << "Enter the arrival time and burst time for process " << i + 1 << ": ";
        cin >> p.arrival_time >> p.burst_time;
        p.pid = i + 1;
        q.push(p);
    }

    int current_time = 0;
    float average_waiting_time = 0;

    while (!q.empty()) {
        Process p = q.front();
        q.pop();

        if (p.arrival_time > current_time) {
            current_time = p.arrival_time;
        }

        p.ct = current_time + p.burst_time;
        p.tat = p.ct - p.arrival_time;
        p.wt = p.tat - p.burst_time;

        average_waiting_time += p.wt;
        current_time = p.ct;
        cout << "Process " << p.pid << ":\t CT: " << p.ct << "  TAT: " << p.tat << "  WT: " << p.wt << endl;
    }

    average_waiting_time /= n;

    cout << "Average waiting time: " << fixed << setprecision(2) << average_waiting_time << endl;

    return 0;
}
