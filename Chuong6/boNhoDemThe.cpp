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



void push_front(LinkedList* ll, int val) {
    Node *newNode = new Node{val, ll->head};
    if (ll->head == nullptr) {
        ll->head = newNode;
        ll->tail = newNode;
    }
    ll->head = newNode;
}

void push_back(LinkedList* ll, int val) {
    Node *newNode = new Node{val, nullptr};
    if (ll->head == nullptr) {
        ll->head = newNode;
        ll->tail = newNode;
    }
    ll->tail->next = newNode;
    ll->tail = newNode;
}


void pop_back(LinkedList *ll) {
    if (ll->head == nullptr) {
        return;
    }

    if (ll->head == ll->tail) {
        delete ll->head;
        ll->head = nullptr;
        ll->tail = nullptr;
        return;
    }

    Node *current = ll->head;
    while (current->next != ll->tail) {
        current = current->next;
    }

    delete ll->tail;
    ll->tail = current;
    ll->tail->next = nullptr;
}




void accessX(LinkedList *ll, int x) {
    if (ll == nullptr || ll->head == nullptr || ll->head->val == x) {
        return;
    }
    Node *current = ll->head;
    while (current->next != nullptr) {
        if (current->next->val == x) {
            Node *target = current->next;
            if (target == ll->tail) {
                ll->tail = current;
            }
            current->next = target->next;
            delete target;
            push_front(ll, x);
            return;
        }
        current = current->next;
    }
    pop_back(ll);
    push_front(ll, x);
}

void closeX(LinkedList *ll, int x, int &size) {
    if (ll == nullptr || ll->head == nullptr) {
        return;
    }
    if (ll->head->val == x) {
        Node *target = ll->head;
        if (ll->head->next == nullptr) {
            ll->head = nullptr;
            ll->tail = nullptr;
        } else {
            ll->head = ll->head->next;
        }
        delete target;
        size--;
        return;
    }
    Node *current = ll->head;
    while (current->next != nullptr) {
        if (current->next->val == x) {
            Node *target = current->next;
            if (target == ll->tail) {
                ll->tail = current;
            }
            current->next = target->next;
            delete target;
            size--;
            return;
        }
        current = current->next;
    }
}


int main() {
    int C, Q;
    cin >> C >> Q;
    LinkedList *ll = new LinkedList();
    cin.ignore();
    string s, command;
    int x, size = 0;
    for (int i = 0; i < Q; i++) {
        getline(cin, s);
        stringstream ss(s);
        while (ss >> command) {
            if (command == "ACCESS") {
                ss >> x;
                if (size < C) {
                    push_front(ll, x);
                    size++;
                } else {
                    accessX(ll, x);
                }
            } else if (command == "CLOSE") {
                ss >> x;
                closeX(ll, x, size);
            }
        }
    }
    cout << size << endl;
    while (ll->head != nullptr) {
        cout << ll->head->val << " ";
        ll->head = ll->head->next;
    }
    return 0;
}