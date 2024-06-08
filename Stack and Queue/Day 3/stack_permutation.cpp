#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Function to check if B is a valid stack permutation of A
int isStackPermutation(vector<int>& A, vector<int>& B) {
    stack<int> st; // Stack for pushing/popping elements
    int i = 0;      // Index for iterating through A
    int j = 0;      // Index for iterating through B

    while (i < A.size()) {
        st.push(A[i]); // Push element from A onto the stack
        i++;

        // Pop elements from stack while they match the current element in B
        while (!st.empty() && st.top() == B[j]) {
            st.pop();
            j++;
        }
    }

    // Return true if both stacks are empty and all elements of B have been matched
    return (st.empty() && j == B.size()); 
}

int main() {
    vector<int> A = {1, 2, 3};
    vector<int> B = {2, 1, 3};  // A valid permutation

    if (isStackPermutation(A, B)) {
        cout << "Output is a valid stack permutation of input." << endl;
    } else {
        cout << "Output is NOT a valid stack permutation of input." << endl;
    }

    return 0;
}

