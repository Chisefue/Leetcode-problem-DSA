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

void push_back(LinkedList* ll, int val) {
    Node* newNode = new Node{val, nullptr};
    if (ll->head == nullptr) {
        ll->head = newNode;
        ll->tail = newNode;
        return;
    }
    ll->tail->next = newNode;
    ll->tail = newNode;
} 


int main() {
    int N, tmp, count = 0, size = 0;
    cin >> N;
    LinkedList *ll = new LinkedList();
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        push_back(ll, tmp);
        size++;
    }
    Node *slow = ll->head;
    Node *fast = ll->head;
    while (fast != nullptr && fast->next != nullptr)  {
        slow = slow->next;
        fast = fast->next->next;
        count++;
    }
    cout << slow->val << endl;
    cout << count << " ";
    while (ll->head != nullptr) {
        if (ll->head == slow) {
            cout << endl;
            cout << size-count << " ";
        } 
        cout << ll->head->val << " ";
        ll->head = ll->head->next;
    } 

    return 0;
}