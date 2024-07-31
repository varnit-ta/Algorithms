#include <iostream>

using namespace std;

struct node{
    node *next;
    int val;
    node *prev;
};

//Function to add a new node
void append(node*& start, int pos, int val){
    node *temp = new node();
    temp->val = val;

    node *ptr = start;

    if (pos == 0){
        if (!start){
            temp->prev = nullptr;
            temp->next = nullptr;
            start = temp;
            return;
        }
        temp->prev = nullptr;
        temp->next = start;
        start->prev = temp;
        return;
    }else if (pos == -1){

        while (ptr->next){
            ptr = ptr->next;
        }

        temp->prev = ptr;
        temp->next = nullptr;
        ptr->next = temp;
        return;
    }else {
        for (int i = 0; i < pos-1 && ptr != nullptr; i++){
            ptr = ptr->next;
        }

        if (!ptr){
            cout << "Position out of bound" << endl;
            return;
        }

        temp->next = ptr->next;
        temp->prev = ptr;
        ptr->next->prev = temp;
        ptr->next = temp;
        return;
    }
}

//Fucntion to delete a node
void remove(node*& start, int data) {
    node *temp = new node();
    node *ptr = start;

    if (start->val == data) {
        temp = start;
        start = start->next;
        start->prev = nullptr;
        delete temp;
        return;
    }

    while (ptr->val != data && ptr->next != nullptr) {
        ptr = ptr->next;
    }

    temp = ptr;
    ptr->prev->next = ptr->next;
    if (ptr->next != nullptr) {
        ptr->next->prev = ptr->prev;
    }
    delete temp;
}

void display(node *start){
    node *ptr = start;

    while (ptr){
        cout << ptr->val << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

int main(){
    node *start = nullptr;

    append(start, 0, 9);
    append(start, -1, 1);
    append(start, 1, 4);

    display(start);

    remove(start, 1);

    display(start);
}
