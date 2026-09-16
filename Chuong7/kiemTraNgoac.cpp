#include <bits/stdc++.h>
using namespace std;

bool check (string s) {
    stack<char> stack;
    for (char a : s) {
        if (a == '(' || a == '[' || a == '{') {
            stack.push(a);
        } else if (a == ')' && stack.top() != '(') return false; 
        else if (a == ']' && stack.top() != '[') return false; 
        else if (a == '}' && stack.top() != '{') return false; 
        if (a == ')' || a == ']' || a == '}') stack.pop();
    } 
    if (!stack.empty()) return false;
    return true;
}

int main() {
    string S;
    getline(cin, S);
    if (check(S)) cout << "YES";
    else cout << "NO";
    return 0;
}