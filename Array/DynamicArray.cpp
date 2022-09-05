#include <bits/stdc++.h>
using namespace std;
class DynamicArray
{
private:
    int *ptr;
    int lastIndex;
    int capacity;

public:
    DynamicArray(/* args */);
    ~DynamicArray();
    doubleArray();
    halfArray();
    createArray(int size);
    appendArray(int data);
    insert(int position, int data);
    Delete(int data);
    searchData(int data);
    view();
};
DynamicArray::searchData(int data)
{
    for (int i = 0; i <= lastIndex; i++)
    {
        if (ptr[i] == data)
            return i + 1;
    }
    return -1;
}
DynamicArray::DynamicArray()
{
    ptr = nullptr;
    lastIndex = -1;
    capacity = 0;
}
DynamicArray::doubleArray()
{
    capacity *= 2;
    int *temp = new int[capacity];
    for (int i = 0; i <= lastIndex; i++)
    {
        temp[i] = ptr[i];
    }
    ptr = temp;
    temp = nullptr;
    delete temp;
}
DynamicArray::halfArray()
{
    capacity = capacity / 2;
    int *temp = new int[capacity];
    for (int i = 0; i <= lastIndex; i++)
    {
        temp[i] = ptr[i];
    }
    ptr = temp;
    temp = nullptr;
    delete temp;
}
DynamicArray::createArray(int size)
{
    capacity = size;
    ptr = new int[capacity];
    lastIndex = -1;
}
DynamicArray::appendArray(int data)
{
    ++lastIndex;
    ptr[lastIndex] = data;
    if (lastIndex == capacity)
    {
        doubleArray();
    }
}
DynamicArray ::insert(int position, int data)
{
    if (position <= 0 || position > lastIndex + 2)
        cout << "overflow\n";
    else
    {

        for (int i = lastIndex; i >= position - 1; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ++lastIndex;
        ptr[position - 1] = data;
    }
    if (lastIndex == capacity)
    {
        doubleArray();
    }
}
DynamicArray::Delete(int data)
{
    int indx = searchData(data);
    if (indx != -1)
    {
        for (int i = indx - 1; i < lastIndex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        --lastIndex;
    }
    if (lastIndex >0 && lastIndex+1 == capacity / 2)
    {
        halfArray();
    }
}
DynamicArray::view()
{
    for (int i = 0; i <= lastIndex; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << "\n";
}
DynamicArray::~DynamicArray()
{
}
int main()
{
    DynamicArray da;
    da.createArray(6);
    da.appendArray(1);
    da.appendArray(2);
    da.appendArray(3);
    da.insert(1, -1);
    da.view();
    da.Delete(3);
    da.view();
    da.insert(7, -10);
}