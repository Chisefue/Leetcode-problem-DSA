#include <bits/stdc++.h>
using namespace std;

int sumString(string s) {
    int sum = 0;
    for (char a : s) {
        sum += a;
    }
}

int main() {
    int N;
    cin >> N;
    string s_i; 
    unordered_map<int, bool> keys;
    unordered_map<int, string> map;
    for (int i = 0; i < N; i++) {
        cin >> s_i;
        map[sumString(s_i)] = s_i;
        if (keys.count(sumString(s_i)) == 0) keys[sumString(s_i)] = true; 
    }
    for (auto key : keys) {
        for (auto it : map) {
            if (key.first == it.first) cout << it.second << " ";
        }
        cout << endl;
    }
    
    return 0;
}