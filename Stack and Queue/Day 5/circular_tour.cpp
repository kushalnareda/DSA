#include <iostream>

using namespace std;

// Structure to represent a petrol pump
struct petrolPump {
    int petrol;
    int distance;
};

// Function to find the starting petrol pump index
int tour(petrolPump p[], int n) {
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        balance = balance + p[i].petrol - p[i].distance;
        if (balance < 0) {
            deficit = deficit + balance;
            start = i + 1;
            balance = 0;
        }
    }
    if (deficit + balance >= 0) {
        return start;
    } else {
        return -1;
    }
}

int main() {
    petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};
    int n = sizeof(arr) / sizeof(arr[0]);

    int start = tour(arr, n);
    if (start != -1) {
        cout << "Start from petrol pump index: " << start << endl;
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
