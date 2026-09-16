#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q, L, R, sum = 0;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < Q; i++) {
        cin >> L >> R;
        for (int j = L; j < R + 1; j++) {
            sum += a[j];
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}