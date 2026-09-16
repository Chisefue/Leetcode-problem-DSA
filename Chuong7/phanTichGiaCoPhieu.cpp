#include <bits/stdc++.h>
using namespace std;



int main() {
    int N, tmp; 
    cin >> N;
    string S = "";
    stack<pair<int, int>> monotonicStack;
    stack<int> input;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        input.push(tmp);
    }
    for (int i = N - 1; i >= 0; i--) {
        while (!monotonicStack.empty() && monotonicStack.top().first <= input.top()) {
                monotonicStack.pop();
        } //stack: 72,5 76,6 //S: 1 0 0
        if (monotonicStack.empty()) {
            monotonicStack.push({input.top(), i});
            S = "0 " + S; 
            input.pop();
        } else {
            S = to_string(monotonicStack.top().second - i) + " " + S;
            monotonicStack.push({input.top(), i});
            input.pop();
        }
    }
    cout << S;
    return 0;
}