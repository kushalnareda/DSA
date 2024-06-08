#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    stack<int> st;

    int maxLength(const string &S) {
        st.push(-1);
        int maxlen = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    int len = i - st.top();
                    maxlen = max(maxlen, len);
                }
            }
        }
        return maxlen;
    }
};

int main() {
    Solution solution;

    string S1 = "((()";
    string S2 = ")()())";
    
    cout << "Example 1: " << solution.maxLength(S1) << endl;  // Output: 2
    cout << "Example 2: " << solution.maxLength(S2) << endl;  // Output: 4
    
    return 0;
}
