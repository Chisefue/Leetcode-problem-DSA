#include <bits/stdc++.h>
using namespace std;

void makeStackEmpty(stack<string> &stack) {
    while (!stack.empty()) {
        stack.pop();
    }
}

int main() {
    stack<string> undo;
    stack<string> redo;
    int Q;
    cin >> Q;
    cin.ignore();
    string s, command, x;
    for (int i = 0; i < Q; i++) {
        getline(cin, s);
        stringstream ss(s);
        while (ss >> command) {
            if (command == "TYPE") {
                ss >> x;
                undo.push(x);
                makeStackEmpty(redo);
            } else if (command == "UNDO") {
                if (undo.empty()) continue;
                else {
                    redo.push(undo.top());
                    undo.pop();
                }
            } else if (command == "REDO") {
                if (redo.empty()) continue;
                else {
                    undo.push(redo.top());
                    redo.pop();
                }
            }
        }
    }
    cout << undo.size() << endl;
    string string = "";
    while (!undo.empty() && undo.size() != 0) {
        string = undo.top() + " " + string;
        undo.pop();
    }
    cout << string;
    return 0;
}