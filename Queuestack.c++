#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> s1, s2;

public:
   
    void enqueue(int x) {
        s1.push(x);
        cout << x << " inserted into queue.\n";
    }

    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue Underflow\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << s2.top() << " deleted from queue.\n";
        s2.pop();
    }

    void peek() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty.\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Front element: " << s2.top() << endl;
    }

    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty.\n";
            return;
        }

        stack<int> temp1 = s1;
        stack<int> temp2 = s2;

        cout << "Queue elements: ";

        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }

        stack<int> rev;
        while (!temp1.empty()) {
            rev.push(temp1.top());
            temp1.pop();
        }

        while (!rev.empty()) {
            cout << rev.top() << " ";
            rev.pop();
        }

        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue using Stack (STL) ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
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
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}