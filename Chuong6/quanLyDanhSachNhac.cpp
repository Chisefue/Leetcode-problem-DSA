#include <bits/stdc++.h>
using namespace std;

void delByVal(list<int>& ll, int val) {
    stack<int> stack;
    while (!ll.empty()) {
        if (ll.back() != val) {
            stack.push(ll.back());
            ll.pop_back();
        } else {
            ll.pop_back();
        }
    }
    while (!stack.empty()) {
        ll.push_back(stack.top());
        stack.pop();
    }
    return;
}


int main() {
    list<int> ll;
    int N, Q, tmp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        ll.push_back(tmp);
    }
    cin >> Q;
    cin.ignore();
    string s, command;
    int x;
    for (int i = 0; i < Q; i++) {
        getline(cin, s);
        stringstream ss(s);
        while (ss >> command) {
            if (command == "PUSH_FRONT") {
                ss >> x;
                ll.push_front(x);
            } else if (command == "PUSH_BACK") {
                ss >> x;
                ll.push_back(x);
            } else if (command == "POP_FRONT") {
                ll.pop_front();
            } else if (command == "DELETE_VALUE") {
                ss >> x;
                delByVal(ll, x);
            }
        }
    }
    cout << ll.size() << endl;
    while (!ll.empty()) {
        cout << ll.front() << " ";
        ll.pop_front();
    }
    return 0;
}