#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue
{
private:
    int queue[SIZE];
    int front, rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value)
    {
        // Queue is full
        if ((rear + 1) % SIZE == front)
        {
            cout << "Queue is Full!" << endl;
            return;
        }

        // First element
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % SIZE;
        }

        queue[rear] = value;
        cout << value << " inserted into queue." << endl;
    }

    // Dequeue operation
    void dequeue()
    {
        // Queue is empty
        if (front == -1)
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << queue[front] << " deleted from queue." << endl;

        // Only one element
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }

    // Display operation
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Circular Queue: ";

        int i = front;

        while (true)
        {
            cout << queue[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue q;
    int choice, value;

    do
    {
        cout << "\n===== CIRCULAR QUEUE =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Program Ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}