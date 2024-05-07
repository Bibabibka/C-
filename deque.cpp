#include <iostream>

using namespace std;

class Node
{
    public:
    int field;
    Node* next;
    Node* prev;
};

class Deque
{
    public:
    Node* front;
    Node* back;

    Deque() : front(nullptr), back(nullptr) {}

    bool empty() {
        return front == nullptr;
    }

    void pushBack(int val) {
        Node* newNode = new Node();
        newNode->field = val;
        newNode->next = nullptr;
        newNode->prev = back;

        if (empty()) {
            front = newNode;
        } else {
            back->next = newNode;
        }

        back = newNode;
    }

    void popBack() {
        if (empty()) {
            cout << "Двухсторонняя очередь пуста" << endl;
            return;
        }

        Node* numb = back;
        back = back->prev;

        if (back == nullptr) {
            front = nullptr;
        } else {
            back->next = nullptr;
        }

        delete numb;
    }

    void pushFront(int val) {
        Node* newNode = new Node();
        newNode->field = val;
        newNode->next = front;
        newNode->prev = nullptr;

        if (empty()) {
            back = newNode;
        } else {
            front->prev = newNode;
        }

        front = newNode;
    }

    void popFront() {
        if (empty()) {
            cout << "Двухсторонняя очередь пуста" << endl;
            return;
        }

        Node* numb = front;
        front = front->next;

        if (front == nullptr) {
            back = nullptr;
        } else {
            front->prev = nullptr;
        }

        delete numb;
    }
};

int main() {
    Deque deq;

    deq.pushBack(1);
    deq.pushBack(2);
    deq.pushFront(0);

    cout << "Двухсторонняя очередь: ";
    while (!deq.empty()) {
        cout << deq.front->field << " ";
        deq.popFront();
    }
    cout << endl;

    return 0;
}
