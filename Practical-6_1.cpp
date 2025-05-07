#include<iostream>
using namespace std;

class DynamicArray
{
    int size = 0;
    int capacity;
    int* data;

public:
    DynamicArray(int initialCapacity = 2)
    {
        capacity = initialCapacity;
        data = new int[capacity];
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    void resize()
    {
        capacity *= 2;
        int* newData = new int[capacity];

        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }

    void insert(int value)
    {
        if (size == capacity)
            resize();
        data[size++] = value;
    }

    int getValue(int index)
    {
        if (index < 0 || index >= size)
            return -1;
        return data[index];
    }

    void remove(int index)
    {
        if (index < 0 || index >= size)
            return;

        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }

        size--;
    }

    void display() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DynamicArray arr;

    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.insert(40);

    arr.display();

    int in, ch;

    cout << "Enter the index: ";
    cin >> in;
    cout << "Value is: " << arr.getValue(in) << endl;

    cout << "Enter the index of the value you want to remove: ";
    cin >> in;
    arr.remove(in);

    cout << "Do you want to add more elements (1 for Yes, 0 for No): ";
    cin >> ch;

    if (ch)
    {
        int num, value;
        cout << "Enter the number of elements: ";
        cin >> num;

        for (int i = 0; i < num; i++)
        {
            cout << "Enter " << i + 1 << " number: ";
            cin >> value;
            arr.insert(value);
        }
    }

    arr.display();

    cout<<endl;
    cout << "\nRIDHAM LAKKAD : 24CE059" << endl;

    return 0;
}