#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K = 0;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (a[j] < a[i]) K++;
        }
    } 
    cout << K << endl;
    if (K == 0) cout << "SORTED\n";
    else if (K >= 1 && K <= N) cout << "NEARLY SORTED\n";
    else cout << "HIGHLY DISORDERED\n";
    cout << K;
    return 0;
}