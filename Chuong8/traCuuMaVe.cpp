#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    unordered_map<string, int> map;
    string s_i, T_j;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s_i;
        map[s_i] = 1;
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> T_j;
        if (map.count(T_j) == 0) {
            cout << "INVALID\n";
        } else if (map[T_j] == 1) {
            cout << "VALID\n";
            map[T_j] = 2;
        } else if (map[T_j] == 2) {
            cout << "DUPLICATE\n";
        }
    }
    
    return 0;
}