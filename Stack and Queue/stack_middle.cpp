#include <iostream>
using namespace std;

class DLLNode {
public:
    DLLNode* prev;
    int data;
    DLLNode* next;
};

class myStack {
public:
    DLLNode* head;
    DLLNode* mid;
    int count;
};

myStack* createMyStack() {
    myStack* ms = new myStack();
    ms->count = 0;
    ms->head = nullptr;
    ms->mid = nullptr;
    return ms;
}

void push(myStack* ms, int new_data) {
    DLLNode* new_DLLNode = new DLLNode();
    new_DLLNode->data = new_data;
    new_DLLNode->prev = nullptr;
    new_DLLNode->next = ms->head;

    ms->count += 1;

    if (ms->count == 1) {
        ms->mid = new_DLLNode;
    } else {
        ms->head->prev = new_DLLNode;

        if (!(ms->count & 1))
            ms->mid = ms->mid->prev;
    }

    ms->head = new_DLLNode;
}

int pop(myStack* ms) {
    if (ms->count == 0) {
        cout << "Stack is empty" << endl;
        return -1;
    }

    DLLNode* head = ms->head;
    int item = head->data;
    ms->head = head->next;

    if (ms->head != nullptr) {
        ms->head->prev = nullptr;
    }

    ms->count -= 1;

    if ((ms->count) & 1) {
        ms->mid = ms->mid->next;
    } else {
        ms->mid = ms->mid->prev;
    }

    delete head;
    return item;
}

int findMiddle(myStack* ms) {
    if (ms->count == 0) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return ms->mid->data;
}

int deleteMiddle(myStack* ms) {
    if (ms->count == 0) {
        cout << "Stack is empty" << endl;
        return -1;
    }

    DLLNode* mid = ms->mid;
    int item = mid->data;
    ms->count -= 1;

    if (ms->count == 0) {
        ms->head = nullptr;
        ms->mid = nullptr;
    } else if (ms->count == 1) {
        ms->head = ms->head->next;
        ms->head->prev = nullptr;
        ms->mid = ms->head;
    } else {
        if (mid->prev != nullptr) {
            mid->prev->next = mid->next;
        }
        if (mid->next != nullptr) {
            mid->next->prev = mid->prev;
        }

        if (ms->count & 1) {
            ms->mid = mid->next;
        } else {
            ms->mid = mid->prev;
        }
    }

    delete mid;
    return item;
}

int main() {
    myStack* ms = createMyStack();
    push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);

    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Middle Element is " << findMiddle(ms) << endl;
    cout << "Deleted Middle Element is " << deleteMiddle(ms) << endl;
    cout << "Middle Element is " << findMiddle(ms) << endl;

    return 0;
}
