#include <iostream>
#include <stack>

using namespace std; // Using the standard namespace

class SpecialStack {
    stack<int> s;
    int mini = INT_MAX; // Initialize to a large value for the first push

public:
    void push(int data) {
        if (s.empty()) {
            s.push(data);
            mini = data;
        } else {
            if (data < mini) {
                int val = 2 * data - mini; // Store encoded value
                s.push(val);
                mini = data; 
            } else {
                s.push(data);
            }
        }
    }

    void pop() {
        if (s.empty()) {
            cout << "Stack underflow!" << endl;
            return;
        }

        int current = s.top();
        s.pop();

        if (current < mini) {  // If the popped element was the minimum
            mini = 2 * mini - current; // Decode to restore the previous minimum
        }
    }

    int top() {
        if (s.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        int current = s.top();
        return (current < mini) ? mini : current; // Return actual or encoded minimum
    }

    int getMin() {
        if (s.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return mini;
    }
};

int main() {
    SpecialStack ss;
    ss.push(10);
    ss.push(20);
    ss.push(5);
    cout << "Minimum: " << ss.getMin() << endl;  // Output: 5

    ss.push(3);
    cout << "Minimum: " << ss.getMin() << endl; // Output: 3

    ss.pop();
    cout << "Minimum: " << ss.getMin() << endl; // Output: 5

    return 0;
}
