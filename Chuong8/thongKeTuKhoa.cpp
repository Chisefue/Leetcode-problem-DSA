#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    unordered_map<string, int> map;
    deque<pair<string,int>> topK;
    string s_i;
    for (int i = 0; i < N; i++) {
        cin >> s_i;
        if (map.count(s_i) == 0) {
            map[s_i] = 1;
        } else map[s_i]++;
        
    }
    for (auto it : map) {
        if (topK.empty() || it.second > topK.back().second) {
            topK.push_front(it);
            
        } else topK.push_back(it);
    }
    for (int i = 0; i < K; i++) {
        cout << topK.front().first << " " << topK.front().second << endl;
        topK.pop_front();
    }
    return 0;
}