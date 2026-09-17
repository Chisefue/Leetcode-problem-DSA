#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, tmp, count = 0, max = -1;
    bool check = false, checkConstraint = false;
    unordered_map<int, int> map;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        if (i == 0) map[i] = tmp;
        else map[i] = tmp + map[i-1];
        if (map[i] == 0 && !checkConstraint) checkConstraint = true;
    }
    for (int i = 0; i < N; i++)
    {
        if (!check && map[i] != 0) {
            count++;
        } else if (!check && map[i] == 0) {
            count++;
            if (max < count) max = count;
            count = 0;
            check = true;
        } if (check && map[i] != 0) {
            count++;
        } else if (check && map[i] == 0) {
            count++;
            if (max < count) max = count;
            count = 0;
        }
    }
    if (!checkConstraint) cout << 0;
    else cout << count;
    
    return 0;
}
