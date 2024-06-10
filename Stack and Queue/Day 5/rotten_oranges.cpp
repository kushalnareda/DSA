#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Function to find the minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int r = grid.size();
        int c = grid[0].size();

        // Push all initially rotten oranges to the queue
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int count = 0;
        q.push({-1, -1});

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;

            if (i == -1 && j == -1 && q.size() == 1) {
                q.pop();
                break;
            } else if (i == -1 && j == -1 && q.size() > 1) {
                count++;
                q.pop();
                q.push({-1, -1});
            } else {
                // Check all four adjacent cells and rot fresh oranges
                if ((i - 1) >= 0 && grid[i - 1][j] == 1) {
                    grid[i - 1][j] = 2;
                    q.push({i - 1, j});
                }
                if ((j - 1) >= 0 && grid[i][j - 1] == 1) {
                    grid[i][j - 1] = 2;
                    q.push({i, j - 1});
                }
                if ((i + 1) < r && grid[i + 1][j] == 1) {
                    grid[i + 1][j] = 2;
                    q.push({i + 1, j});
                }
                if ((j + 1) < c && grid[i][j + 1] == 1) {
                    grid[i][j + 1] = 2;
                    q.push({i, j + 1});
                }
                q.pop();
            }
        }

        // Check for any remaining fresh oranges
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = sol.orangesRotting(grid);
    cout << "Minimum time required to rot all oranges: " << result << endl;

    return 0;
}
