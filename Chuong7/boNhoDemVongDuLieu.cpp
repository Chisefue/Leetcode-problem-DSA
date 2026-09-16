#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, Q;
    cin >> K >> Q;
    cin.ignore();
    int *slots = new int(K);
    int front = 0, count = 0;
    string s, command;
    int x;
    for (int i = 0; i < Q; i++) {
        getline(cin, s);
        stringstream ss(s);
        while (ss >> command) {
            if (command == "RECORD") {
                ss >> x;
                if (count < K) {
                    slots[(front + count) % K] = x;
                    count++;
                } else {
                    slots[front] = x;
                    front = (front + 1) % K;
                }
            } else if (command == "READ") {
                if (count == 0) {
                    cout << "EMPTY\n";
                } else {
                    cout << slots[front] << endl;
                    front = (front + 1) % K;
                    count--;
                }
            } else if (command == "PEEK_OLDEST") {
                if (count == 0) {
                    cout << "EMPTY\n";
                } else {
                    cout << slots[front] << endl;
                }
            } else if (command == "SIZE") {
                cout << count << endl;
            }
        }
    }
    return 0;
}