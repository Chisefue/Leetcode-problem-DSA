#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, j, key, shift = 0;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < N; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            
            a[j+1] = a[j];
            shift++;
            j--;
        }
        a[j+1] = key;
    }
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl << shift;
    return 0;
}