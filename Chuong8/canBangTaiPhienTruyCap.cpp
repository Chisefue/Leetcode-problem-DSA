#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, tmp;
    unordered_map<int, int> map;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        if (i == 0) (map[i] == tmp);
        else map[i] = tmp + map[i-1];
    }
    return 0;
}