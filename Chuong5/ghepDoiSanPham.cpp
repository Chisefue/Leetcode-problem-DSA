#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T;
    bool check = false;
    cin >> N >> T;
    int left = 0, right = N - 1;
    int sum;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    while (right > left) {
        sum = a[right] + a[left];
        if (sum < T) left++;
        else if (sum > T) right--;
        else {
            while (right > left) {
                if (a[right - 1] == a[right] && right - 1 != left) right--;
                else break;
            }
            cout << left << " " << right;
            check = true;
            break; 
        }
    }
    if (!check) cout << -1;
    return 0;
}