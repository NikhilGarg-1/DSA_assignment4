#include <iostream>
#include <queue>
using namespace std;

int main() {
    string input;
    getline(cin, input);

    queue<char> q;
    int freq[256] = {0};

    for (char ch : input) {
        if (ch == ' ') continue;
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (!q.empty())
            cout << q.front() << " ";
        else
            cout << "-1 ";
    }

    return 0;
}
