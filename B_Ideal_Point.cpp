#include <bits/stdc++.h>
using namespace std;

int optimal_elevator_floor(vector<int>& ai) {
    int n = ai.size();
    int min_electricity = INT_MAX;
    int best_floor = -1;

    for (int x = 0; x < n; x++) {
        int total_distance = 0;
        for (int i = 0; i < n; i++) {
            if (ai[i] > 0) {
                int distance = abs(i - x) + abs(i - 1) + abs(x - 1);
                if (i == x) {
                    distance = abs(i - 1) + abs(x - 1);
                }
                total_distance += distance * ai[i];
            }
        }
        int total_electricity = 2 * total_distance;
        if (total_electricity < min_electricity) {
            min_electricity = total_electricity;
            best_floor = x;
        }
    }

    return best_floor;
}

int main() {
    // Example usage
    vector<int> ai = { 1,1 };
    int best_floor = optimal_elevator_floor(ai);
    cout << "The optimal floor for the elevator is: " << best_floor << endl;
    return 0;
}
