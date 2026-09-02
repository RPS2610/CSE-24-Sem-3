#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class MinPriorityQueue {
private:
    Node* front;

public:
    MinPriorityQueue() {
        front = NULL;
    }

    // Insert element
    void enqueue(int value) {
        Node* newNode = new Node(value);

        // If queue is empty or new value is smallest
        if (front == NULL || value < front->data) {
            newNode->next = front;
            front = newNode;
        }
        else {
            Node* temp = front;

            // Find correct position
            while (temp->next != NULL &&
                   temp->next->data <= value) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << value << " inserted successfully.\n";
    }

    // Delete minimum element
    void dequeue() {
        if (front == NULL) {
            cout << "Priority Queue is Empty.\n";
            return;
        }

        Node* temp = front;

        cout << temp->data << " deleted from queue.\n";

        front = front->next;
        delete temp;
    }

    // Display queue
    void display() {
        if (front == NULL) {
            cout << "Priority Queue is Empty.\n";
            return;
        }

        Node* temp = front;

        cout << "Min Priority Queue: ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    MinPriorityQueue pq;

    pq.enqueue(30);
    pq.enqueue(10);
    pq.enqueue(50);
    pq.enqueue(20);
    pq.enqueue(40);

    pq.display();

    pq.dequeue();
    pq.display();

    pq.dequeue();
    pq.display();

    return 0;
}