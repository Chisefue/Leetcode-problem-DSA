#include <bits/stdc++.h>
using namespace std;



int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    vector<int> q(Q);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < Q; i++) {
        cin >> q[i];
    }
    int costA = 0;
    int costB = 0;
    bool check = false;
    // Plan A
    for (int j = 0; j < Q; j++) {
        for (int i = 0; i < N; i++) {
            if (a[i] == q[j]) {
                costA += i + 1;
                check = true;
                break;
            }
        }
        if (!check) costA += N;
        check = false;
    }
    
    //Plan B
    int key, j;
    for (int i = 1; i < N; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            costB++;
            a[j+1] = a[j];
            j--;
        }
        if (j >= 0) costB++;
        a[j + 1] = key;
    }
    check = false;
    for (int j = 0; j < Q; j++) {
        for (int i = 0; i < N; i++) {
            if (a[i] == q[j]) {
                costB += i + 1;
                check = true;
                break;
            } else if (a[i] > q[j]) {
                costB += i + 1;
                check = true;
                break;
            }
        }
        if (!check) costB += N;
        check = false;
    }
    
    
    cout << costA << endl;
    cout << costB << endl;
    if (costA < costB) cout << "STRATEGY A";
    else cout << "STRATEGY B";
    return 0;
}