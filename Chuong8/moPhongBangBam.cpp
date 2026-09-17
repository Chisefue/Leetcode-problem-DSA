#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, Q, prev;
    cin >> M >> Q;
    cin.ignore();

    string s, command;
    vector<pair<int, int>> a(M);
    int K, V;
    for (int i = 0; i < Q; i++) {
        getline(cin, s);
        stringstream ss(s);
        while (ss >> command) {
            if (command == "PUT") {
                ss >> K >> V;
                prev = K;
                while (a[K % M].first != 0 && 
                a[K % M].first != -1) {
                    K++;
                }
                if (K == prev + M) {
                    cout << "FULL\n";
                    break;
                } else if (a[K % M].first == 0 || 
                a[K & M].first == -1) {
                    a[K % M] = {K, V};
                }
            } else if (command == "GET") {
                ss >> K;
                prev = K;
                while (a[K % M].first != K) {
                    K++;
                    if (K == prev + M) {
                        cout << "NOT FOUND\n";
                        break;
                    } else if (a[K % M].first == K) {
                        cout << a[K % M].second << endl;
                    } else if (a[K % M].first == -1) {
                        cout << "DELETED\n";
                    }
                }
                if (prev == K) cout << a[K % M].second << endl;
            } else if (command == "DEL") {
                ss >> K;
                prev = K;
                while (a[K % M].first != K) {
                    K++;
                    if (K == prev + M) {
                        cout << "NOT FOUND\n";
                        break;
                    } else if (a[K % M].first == K) {
                        a[K % M].first = -1;
                        cout << "DELETE\n";
                        break;
                    } else if (a[K % M].first == -1 ||
                    a[K % M].first == 0) {
                        cout << "NOT_FOUND\n";
                        break;
                    }
                }
            }
        }
    }
    return 0;
}