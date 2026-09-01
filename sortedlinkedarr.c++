#include <iostream>
using namespace std;

class SortedArray
{
    int arr[100];
    int n;

public:

    SortedArray()
    {
        n = 0;
    }

    // Insert element in sorted order
    void insert(int value)
    {
        int i = n - 1;

        while(i >= 0 && arr[i] > value)
        {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = value;
        n++;
    }

    // Peek maximum element
    void peek()
    {
        if(n == 0)
        {
            cout << "Array is empty" << endl;
            return;
        }

        cout << "Peek: " << arr[n - 1] << endl;
    }

    // Delete maximum element
    void deleteMax()
    {
        if(n == 0)
        {
            cout << "Array is empty" << endl;
            return;
        }

        cout << "Deleted: " << arr[n - 1] << endl;
        n--;
    }

    // Display array
    void display()
    {
        if(n == 0)
        {
            cout << "Array is empty" << endl;
            return;
        }

        cout << "Array: ";

        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Check empty
    void isEmpty()
    {
        if(n == 0)
            cout << "Array is empty" << endl;
        else
            cout << "Array is not empty" << endl;
    }
};

int main()
{
    SortedArray s;

    s.insert(40);
    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(50);

    s.display();

    s.peek();

    s.deleteMax();

    s.display();

    s.isEmpty();

    return 0;
}
