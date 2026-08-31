#include <iostream>
using namespace std;

#define MAXSIZE 5

class PriorityQueue {
    int arr[MAXSIZE];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    // Enqueue
    void enqueue(int value) {
        if (size == MAXSIZE) {
            cout << "Priority Queue is Full" << endl;
        }
        else {
            arr[size] = value;
            size++;
        }
    }

    // Dequeue - deletes highest priority (minimum) element
    void dequeue() {
        if (size == 0) {
            cout << "Priority Queue is Empty" << endl;
        }
        else {
            int minIndex = 0;

            // Find minimum element
            for (int i = 1; i < size; i++) {
                if (arr[i] < arr[minIndex]) {
                    minIndex = i;
                }
            }

            cout << arr[minIndex] << " deleted" << endl;

            // Shift elements left
            for (int i = minIndex; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }

            size--;
        }
    }

    // Display
    void display() {
        if (size == 0) {
            cout << "Priority Queue is Empty" << endl;
        }
        else {
            cout << "Priority Queue: ";

            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }
};

int main() {
    PriorityQueue pq;

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