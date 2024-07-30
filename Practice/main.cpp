#include <iostream>

using namespace std;

struct node{
    int val;
    node *next;
};

void display(node *ptr){
    node *p = ptr;

    while (p != nullptr){
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

void append(node*& ptr, int pos, int data) {
    node* temp = new node();
    temp->val = data;
    temp->next = nullptr;

    if (pos == 0) {
        temp->next = ptr;
        ptr = temp;
    } else if (pos == -1) {
        node* p = ptr;

        if (p == nullptr) {
            ptr = temp;
        } else {
            while (p->next != nullptr) {
                p = p->next;
            }
            p->next = temp;
        }
    } else {
        node* p = ptr;

        for (int i = 0; i < pos - 1 && p != nullptr; i++) {
            p = p->next;
        }

        if (p == nullptr) {
            cout << "Position out of bounds" << endl;
            delete temp;
            return;
        }

        temp->next = p->next;
        p->next = temp;
    }
}

void remove(node*& ptr, int data){
    node* p = new node();
    p = ptr;
    
}

int main(){
    node *start = nullptr;

    append(start, 0, 1);
    append(start, -1, 4);
    append(start, -1, 6);
    append(start, 2, 9);
    display(start);
}