#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T;
    int count = 0, countMin = INT_MAX, sum = 0;
    int left = 0, right = 0;
    cin >> N >> T;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    while (right < N && left < N) {
        sum += a[right];
        count++;
        if (sum < T) {
            right++;
        } else if (sum >= T) {
            if (countMin > count) countMin = count;
            sum = 0;
            count = 0;
            left++;
            right = left;
        }
    }
    cout << countMin;
    return 0;
}