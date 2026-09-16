#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, sum = 0, max = 0, count = 0;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N - (K-1); i++) {
        for (int j = i; j < N; j++) {
            count++;
            if (count < 4) sum += a[j];
            else {
                sum = 0;
                count = 0;
                break;
            }
            if (sum > max) max = sum;
        }
    }
    cout << max;
    return 0;
}