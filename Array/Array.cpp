#include <bits/stdc++.h>
using namespace std;
class Array
{
private:
    int *ptr;
    int lastIndex;
    int capacity;

public:
    Array();
    ~Array();
    createArray(int size);
    appendArray(int data);
    insert(int position, int data);
    Delete(int data);
    int searchData(int data);
    int getData(int index);
    edit(int pos, int newData);
    view();
    int countData();
};
Array::Delete(int data)
{
    int indx=searchData(data);
    if(indx!=-1)
    {
      for (int i = indx-1; i <lastIndex; i++)
      {
            ptr[i]=ptr[i+1];
      }
      --lastIndex;
      
    }
    else
    cout<<"element not found \n";
    
}
int Array::getData(int index)
{
    return ptr[index-1];
}
int Array::countData()
{
    if (lastIndex == -1)
        cout << "no data here\n";
    else
        return lastIndex + 1;
}
int Array::searchData(int data)
{
    for (int i = 0; i <= lastIndex; i++)
    {
        if (ptr[i] == data)
            return i + 1;
    }
    return -1;
}
Array::edit(int pos, int newData)
{
    if (pos >= 0 && pos <= lastIndex + 1)
        ptr[pos - 1] = newData;
    else
        cout << "overflow\n";
}
Array::insert(int position, int data)
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
}
Array::Array()
{
    ptr = nullptr;
    lastIndex = -1;
    capacity = 0;
}
Array::createArray(int size)
{
    capacity = size;
    ptr = new int[capacity];
    lastIndex = -1;
}
Array::view()
{
    for (int i = 0; i <= lastIndex; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << "\n";
}
Array::appendArray(int data)
{
    if (lastIndex + 1 == capacity)
        cout << "overflow\n";
    else
    {
        ++lastIndex;
        ptr[lastIndex] = data;
    }
}
Array::~Array()
{
}
// int main()
// {
//     Array A;
//     A.createArray(5);
//     A.appendArray(1);
//     A.appendArray(2);
//     A.appendArray(3);
//     A.appendArray(4);
//     A.insert(5, -2);
//     A.edit(5, 5);
//     A.Delete(5);
//    cout<< A.countData()<<endl;
//   cout<< A.getData(1)<<endl;

//     A.view();
// }