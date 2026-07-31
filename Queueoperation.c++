#include <iostream>
using namespace std;

#define SIZE 5

class Queue
{
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1 || front > rear);
    }

    bool isFull()
    {
        return (rear == SIZE - 1);
    }

    // Enqueue operation
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        arr[rear] = value;

        cout << value << " inserted into the queue." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow! Queue is empty." << endl;
            return;
        }

        cout << arr[front] << " deleted from the queue." << endl;
        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Front element is: " << arr[front] << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements are: ";

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\n===== Queue Menu =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Check Full" << endl;
        cout << "7. Exit" << endl;

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
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            if (q.isEmpty())
                cout << "Queue is Empty." << endl;
            else
                cout << "Queue is Not Empty." << endl;
            break;

        case 6:
            if (q.isFull())
                cout << "Queue is Full." << endl;
            else
                cout << "Queue is Not Full." << endl;
            break;

        case 7:
            cout << "Program Ended." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}