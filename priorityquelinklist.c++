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

class MaxPriorityQueue {
private:
    Node* front;

public:
    MaxPriorityQueue() {
        front = NULL;
    }

    // Insert element
    void enqueue(int value) {
        Node* newNode = new Node(value);

        // If queue is empty or new value has highest priority
        if (front == NULL || value > front->data) {
            newNode->next = front;
            front = newNode;
        }
        else {
            Node* temp = front;

            // Find correct position
            while (temp->next != NULL &&
                   temp->next->data >= value) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << value << " inserted successfully.\n";
    }

    // Delete highest priority element
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

        cout << "Max Priority Queue: ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    MaxPriorityQueue pq;

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