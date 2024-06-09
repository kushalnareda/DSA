#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

class FirstNonRepeatingCharacter {
public:
    unordered_map<char, int> frequency;
    queue<char> q;
    string s = "";  

    string FirstNonRepeating(string A) {
        for (int i = 0; i < A.size(); i++) {
            char ch = A[i];
            frequency[ch]++;
            q.push(ch);

            while (!q.empty()) {
                char frontChar = q.front();
                if (frequency[frontChar] > 1) {
                    q.pop();
                } else {
                    s += frontChar;
                    break;
                }
            }
            
            if (q.empty()) {
                s += "#";  // Added semicolon
            }
        }
        return s;
    }
};

int main() {
   FirstNonRepeatingCharacter obj;
    string A = "aabc";
    string output = obj.FirstNonRepeating(A);
    cout << "Output: " << output << endl; // Output: a#bb
    return 0;
}
