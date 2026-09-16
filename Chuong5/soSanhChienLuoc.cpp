#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int countDoubling = 0, countAdditive = 0;
    int size = 0, cap = 1;
    while (size < N) {
        size++;
        if (size > cap) {
            countDoubling += cap;
            cap *= 2;
        }
    }
    size = 0;
    cap = 1;
    while (size < N) {
        size++;
        if (size > cap) {
            countAdditive += cap;
            cap += K;
        }
    }
    
    cout << countDoubling << endl;
    cout << countAdditive << endl;
    if (countAdditive < countDoubling) cout << "ADDITIVE";
    else if (countDoubling < countAdditive) cout << "DOUBLING";
    else cout << "TIE";
    return 0;
}