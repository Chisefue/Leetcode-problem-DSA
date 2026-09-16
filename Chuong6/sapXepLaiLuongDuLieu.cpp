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

void reverseFromNode(Node *&node) {
    if (node == nullptr || node->next == nullptr) return;
    Node *current = node;
    Node *previous = nullptr;
    Node *next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = previous;

        previous = current;
        current = next;
    }
    
    node = previous;
}

void merge(Node *&head, Node *&mid) {
    Node *current1 = head;
    Node *current2 = mid;
    Node *next1 = nullptr;
    Node *next2 = nullptr;
    if (((head == nullptr) && (mid == nullptr)) || (mid == nullptr)) {
        return;
    } else if (head == nullptr) {
        head = mid;
        return;
    } else {
        while (current1 != nullptr && current2 != nullptr) {
            next1 = current1->next;
            next2 = current2->next;
            current1->next = current2;
            if (next1 == nullptr) return; 
            current2->next = next1;
            current1 = next1;
            current2 = next2;
        }
    }
}

int main() {
    int N, tmp;
    LinkedList *ll = new LinkedList();
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        push_back(ll, tmp);
    }
    Node* mid = ll->head; //day la slow nhung sau khi tim thi no la mid
    Node* fast= ll->head; 
    Node* previous = nullptr;
    while (fast != nullptr && fast->next != nullptr) {
        previous = mid;
        mid = mid->next;
        fast = fast->next->next;
    }

    if (previous != nullptr) previous->next = nullptr;
    reverseFromNode(mid);
    merge(ll->head, mid);
    cout << N << endl;
    while (ll->head != nullptr) {
        cout << ll->head->val << " ";
        ll->head = ll->head->next;
    }
    return 0;
}