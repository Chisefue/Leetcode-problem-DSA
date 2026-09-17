#include <bits/stdc++.h>
using namespace std;
void swap(vector<int> &arr, int idx1, int idx2) {
    arr[idx1] = arr[idx1] ^ arr[idx2];
    arr[idx2] = arr[idx1] ^ arr[idx2];
    arr[idx1] = arr[idx1] ^ arr[idx2];
}
int main() {
    int N, min, minIdx, count = 0;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        min = a[i];
        minIdx = i;
        for (int j = i+1; j < N; j++) {
            if (a[j] < min) {
                min = a[j];
                minIdx = j;
            }
        }
        if (minIdx == i) continue;
        else {
            swap(a, i, minIdx);
            count++;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl << count;
    return 0;
}