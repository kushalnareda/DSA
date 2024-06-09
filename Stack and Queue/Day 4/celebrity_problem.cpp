#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
private:
    bool knows(const vector<vector<int>>& M, int A, int B) const { // Removed 'n' parameter
        return M[A][B] == 1;
    }

public:
    int celebrity(const vector<vector<int>>& M, int n) const {
        stack<int> potentialCelebrities;
        for (int i = 0; i < n; i++) {
            potentialCelebrities.push(i);
        }

        while (potentialCelebrities.size() > 1) {
            int personA = potentialCelebrities.top(); potentialCelebrities.pop();
            int personB = potentialCelebrities.top(); potentialCelebrities.pop();
            potentialCelebrities.push(knows(M, personA, personB) ? personB : personA);
        }

        int candidate = potentialCelebrities.top();

        // Check if the candidate knows anyone (including themselves)
        for (int i = 0; i < n; i++) {
            if (knows(M, candidate, i)) {
                return -1; // Not a celebrity
            }
        }

        // Check if everyone else knows the candidate
        for (int i = 0; i < n; i++) {
            if (i != candidate && !knows(M, i, candidate)) {
                return -1; // Not a celebrity
            }
        }

        return candidate; // Is a celebrity
    }
};

// Example Usage (Optional)
int main() {
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    int n = 3;

    Solution sol;
    int celeb = sol.celebrity(M, n);

    if (celeb != -1) {
        cout << "Celebrity is: " << celeb << endl;
    } else {
        cout << "No celebrity found." << endl;
    }

    return 0;
}
