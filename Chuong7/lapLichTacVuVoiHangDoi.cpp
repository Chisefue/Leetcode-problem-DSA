#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> deque;
    int Q;
    cin >> Q;
    cin.ignore();
    string s, command;
    int id;
    for (int i = 0; i < Q; i++) {
        getline(cin, s);
        stringstream ss(s);
        while (ss >> command) {
            if (command == "PUSH_BACK") {
                ss >> id;
                deque.push_back(id);
            } else if (command == "PUSH_FRONT") {
                ss >> id;
                deque.push_front(id);
            } else if (command == "POP_FRONT") {
                if (deque.empty()) cout << -1 << endl;
                else {
                    cout << deque.front() << endl;
                    deque.pop_front();
                }
            } else if (command == "POP_BACK") {
                if (deque.empty()) cout << -1 << endl;
                else {
                    cout << deque.back() << endl;
                    deque.pop_back();
                }
            } else if (command == "GET_FRONT") {
                if (deque.empty()) cout << -1 << endl;
                else cout << deque.front() << endl;
            } else if (command == "GET_BACK") {
                if (deque.empty()) cout << -1 << endl;
                else cout << deque.back() << endl;
            }
        }
    }
    return 0;
}