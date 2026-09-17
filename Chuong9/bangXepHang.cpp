#include <bits/stdc++.h>
using namespace std;

void swap(vector<pair<string, int>> &list, int idx1, int idx2) {
    pair<string, int> tmp = list[idx1];
    list[idx1] = list[idx2];
    list[idx2] = tmp;
}

int main() {
    int N, Diem, j;
    string Ten;
    pair<string,int> key;
    cin >> N;
    cin.ignore();
    vector<pair<string, int>> list(N);
    for (int i = 0; i < N; i++) {
        cin >> Ten >> Diem;
        list[i].first = Ten;
        list[i].second = Diem;
    }
    for (int i = 1; i < N; i++) {
        key = list[i];
        j = i - 1;
        while (j >= 0 && list[j].second < key.second) {
            list[j+1] = list[j];
            j--;
        }
        list[j + 1] = key;
    }
    for (int i = 0; i < N; i++) {
        cout << list[i].first << " " << list[i].second << endl;
    }
    return 0;
}