#include <bits/stdc++.h>
using namespace std;

int sumString(string s) {
    int sum = 0;
    for (char a : s) {
        sum += a;
    }
    return sum;
}

int main() {
    int N, key;
    cin >> N;
    string s_i; 
    vector<int> keys;
    unordered_map<int, vector<string>> map;
    for (int i = 0; i < N; i++) {
        cin >> s_i;
        key = sumString(s_i);
        if (map.count(key) == 0) {
            keys.push_back(key);
        }
        map[key].push_back(s_i);
    }
    for (int key : keys) {
        for (auto it : map) {
            if (it.first == key) {
                for (string word : it.second) {
                    cout << word << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}