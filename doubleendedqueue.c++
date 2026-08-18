#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = nullptr;
        rear = nullptr;
    }

    // Insert at Front
    void insertFront(int value) {
        Node* newNode = new Node(value);

        if (front == nullptr) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        cout << value << " inserted at front.\n";
    }

    // Insert at Rear
    void insertRear(int value) {
        Node* newNode = new Node(value);

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " inserted at rear.\n";
    }

    // Delete from Front
    void deleteFront() {
        if (front == nullptr) {
            cout << "Deque is empty.\n";
            return;
        }

        Node* temp = front;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }

        cout << temp->data << " deleted from front.\n";
        delete temp;
    }

    // Delete from Rear
    void deleteRear() {
        if (rear == nullptr) {
            cout << "Deque is empty.\n";
            return;
        }

        Node* temp = rear;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }

        cout << temp->data << " deleted from rear.\n";
        delete temp;
    }

    // Peek Front
    void peekFront() {
        if (front == nullptr) {
            cout << "Deque is empty.\n";
        } else {
            cout << "Front element: " << front->data << endl;
        }
    }

    // Peek Rear
    void peekRear() {
        if (rear == nullptr) {
            cout << "Deque is empty.\n";
        } else {
            cout << "Rear element: " << rear->data << endl;
        }
    }

    // Display
    void display() {
        if (front == nullptr) {
            cout << "Deque is empty.\n";
            return;
        }

        Node* temp = front;

        cout << "Deque: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Deque dq;

    int choice, value;

    do {
        cout << "\n===== DOUBLE ENDED QUEUE =====\n";
        cout << "1. Insert Front\n";
        cout << "2. Insert Rear\n";
        cout << "3. Delete Front\n";
        cout << "4. Delete Rear\n";
        cout << "5. Peek Front\n";
        cout << "6. Peek Rear\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;
                dq.insertFront(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                dq.insertRear(value);
                break;

            case 3:
                dq.deleteFront();
                break;

            case 4:
                dq.deleteRear();
                break;

            case 5:
                dq.peekFront();
                break;

            case 6:
                dq.peekRear();
                break;

            case 7:
                dq.display();
                break;

            case 8:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 8);

    return 0;
}