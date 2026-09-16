#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
};

struct LinkedList {
    Node* head;
    Node* tail;
};

void push_back(LinkedList *ll, int val) {
    Node *newNode = new Node{val, nullptr};
    if (ll->head == nullptr) {
        ll->head = newNode;
        ll->tail = newNode;
    }
    ll->tail->next = newNode;
    ll->tail = newNode;
}

int main() {
    int N, tmp, size = 0;
    LinkedList *ll = new LinkedList();
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        push_back(ll, tmp);
        size++;
    }
    int pos, count = 0;
    cin >> pos;
    if (pos == -1) cout << "NO";
    else {
        while (ll->head != nullptr && count != pos) {
            count++;
            ll->head = ll->head->next;
        }
        int cycle_length = size - count;
        int entry_val = ll->head->val;
        cout << "YES\n";
        cout << cycle_length << " " << entry_val;
    }
    return 0;
}