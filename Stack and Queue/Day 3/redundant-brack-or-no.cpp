#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    stack<char> st;

    int checkRedundancy(const string &s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '(') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                if (st.top() == '(') {
                    return 1;
                } else {
                    while (st.top() != '(') {
                        st.pop();
                    }
                    st.pop();
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution solution;

    string s1 = "((a+b))";    // Example with redundancy
    string s2 = "(a+(b*c))";  // Example without redundancy

    cout << "Example 1: " << solution.checkRedundancy(s1) << endl;  // Output: 1 (redundant)
    cout << "Example 2: " << solution.checkRedundancy(s2) << endl;  // Output: 0 (not redundant)

    return 0;
}
