#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *next;
};

Node *top = NULL;

void push(int x)
{
    Node *temp = new Node;
    temp->info = x;
    temp->next = top;
    top = temp;

    cout << "Element pushed successfully.\n";
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack is Empty.\n";
        return;
    }

    Node *temp = top;
    cout << "Deleted Element: " << temp->info << endl;
    top = top->next;
    delete temp;
}

void peek()
{
    if (top == NULL)
    {
        cout << "Stack is Empty.\n";
        return;
    }

    cout << "Top Element: " << top->info << endl;
}

void traverse()
{
    if (top == NULL)
    {
        cout << "Stack is Empty.\n";
        return;
    }

    Node *temp = top;

    cout << "Stack Elements: ";

    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n========== STACK MENU ==========\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Element: ";
            cin >> value;
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            traverse();
            break;

        case 5:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}