#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " inserted into the queue." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
            return;
        }

        Node *temp = front;
        cout << temp->data << " deleted from the queue." << endl;

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            cout << "Front element: " << front->data << endl;
        }
    }

    void traverse()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        Node *temp = front;
        cout << "Queue elements: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
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
        cout << "\n===== Dynamic Queue Menu =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Traverse\n";
        cout << "5. Exit\n";
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
            q.traverse();
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}