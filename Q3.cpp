#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size should be even to interleave." << endl;
        return;
    }

    queue<int> firstHalf;
    for (int i = 0; i < n / 2; ++i) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n, val;

    cout << "Enter even number of elements in the queue: ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Please enter even number of elements." << endl;
        return 0;
    }

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        q.push(val);
    }

    interleaveQueue(q);

    cout << "Interleaved queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
