#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int pointerA = 0, pointerB = 0, count = 0;
    vector<int> A(N);
    vector<int> B(M);
    vector<int> combined;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    while (pointerA < N && pointerB < M) {
        if (A[pointerA] < B[pointerB]) {
            combined.push_back(A[pointerA]);
            pointerA++;
        } else if (B[pointerB] < A[pointerA]) {
            combined.push_back(B[pointerB]);
            pointerB++;
        } else {
            count++;
            combined.push_back(A[pointerA]);
            pointerA++;
            pointerB++;
        }
    }
    while (pointerA < N) {
        combined.push_back(A[pointerA]);
        pointerA++;
    }
    while (pointerB < M) {
        combined.push_back(B[pointerB]);
        pointerB++;
    }

    cout << combined.size() << endl;
    for (int i = 0; i < combined.size(); i++) {
        cout << combined[i] << " ";
    }
    cout << "\n" << count;
    
    return 0;
}