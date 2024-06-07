#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        if (k > q.size()) {
            return q;
        }
        
        stack<int> temp;
        
        // Push first k elements onto the stack
        for (int i = 0; i < k; ++i) {
            int curr = q.front();
            q.pop();
            temp.push(curr);
        }
        
        // Enqueue stack elements back into the queue
        while (!temp.empty()) {
            int curr = temp.top();
            temp.pop();
            q.push(curr);
        }
        
        // Move the remaining elements from front to back to maintain order
        int remaining = q.size() - k;
        for (int i = 0; i < remaining; ++i) {
            int curr = q.front();
            q.pop();
            q.push(curr);
        }
        
        return q;
    }
};

int main() {
    Solution sol;
    queue<int> q;
    
    // Test case 1
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int k = 3;
    
    queue<int> modifiedQueue = sol.modifyQueue(q, k);
    
    cout << "Modified Queue: ";
    while (!modifiedQueue.empty()) {
        cout << modifiedQueue.front() << " ";
        modifiedQueue.pop();
    }
    cout << endl;
    
    return 0;
}
