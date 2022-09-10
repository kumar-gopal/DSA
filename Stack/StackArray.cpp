#include <iostream>
using namespace std;
class StackArray
{
private:
    int capacity;
    int lastindex;
    int *ptr;

public:
    StackArray(/* args */);
    ~StackArray();
    void createStack(int size);
    void push(int x);
    void pop();
    int peak();
    int empty();
    int size();
    void view();
};
void StackArray:: view()
{
    while (!empty())
    {
        cout<<peak()<<" ";
        pop();
    }
    
}
int StackArray:: size()
{
    return lastindex+1;
}
int StackArray:: empty()
{
    if(lastindex==-1)
    return 1;
    else
    return 0;
}
int StackArray::peak()
{
    return ptr[lastindex];
}
void StackArray:: pop()
{
    lastindex-=1;
}
void StackArray::push(int x)
{
    if (lastindex + 1 == capacity)
        cout << "Stack is fulled\n";
    else
    {
        lastindex += 1;
        ptr[lastindex] = x;
    }
}
void StackArray::createStack(int size)
{
    capacity = size;
    ptr = new int[capacity];
    lastindex = -1;
}
StackArray::StackArray(/* args */)
{
    capacity = 0;
    lastindex = -1;
    ptr = nullptr;
}

StackArray::~StackArray()
{
    while (!empty())
    {
        pop();
    }
    
}
int main()
{
    StackArray st;
    st.createStack(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.pop();
    st.push(6);
    cout<<st.peak()<<endl;
    cout<<st.size()<<endl;
    // st.~StackArray();
    cout<<st.empty()<<endl;
    st.view();
}