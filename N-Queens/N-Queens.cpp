#include <bits/stdc++.h>
using namespace std;

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    // Maximum moves in each direction before hitting the board boundary
    int up = n - r_q, down = r_q - 1, left = c_q - 1, right = n - c_q;
    int up_left = min(up, left), up_right = min(up, right);
    int down_left = min(down, left), down_right = min(down, right);

    // Store obstacles in a set for fast lookup
    set<pair<int, int>> obstacle_set;
    for (auto &obstacle : obstacles) {
        obstacle_set.insert({obstacle[0], obstacle[1]});
    }

    int attackable_squares = 0;
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, -1}, {0, 1},  // Up, Down, Left, Right
        {1, -1}, {1, 1}, {-1, -1}, {-1, 1} // Diagonals: UL, UR, DL, DR
    };

    // Move in each direction until we hit an obstacle or boundary
    for (auto dir : directions) {
        int row = r_q, col = c_q;
        while (true) {
            row += dir.first;
            col += dir.second;

            if (row < 1 || row > n || col < 1 || col > n) break; // Board boundary
            if (obstacle_set.count({row, col})) break; // Obstacle found

            attackable_squares++;
        }
    }

    return attackable_squares;
}

int main() {
    int n, k;
    cin >> n >> k;
    int r_q, c_q;
    cin >> r_q >> c_q;

    vector<vector<int>> obstacles(k, vector<int>(2));
    for (int i = 0; i < k; i++) {
        cin >> obstacles[i][0] >> obstacles[i][1];
    }

    cout << queensAttack(n, k, r_q, c_q, obstacles) << endl;
    return 0;
}
