#include <iostream>
using namespace std;
class TwoWayStack
{
private:
    int capacity;
    int top1;
    int top2;
    int *ptr;

public:
    TwoWayStack(/* args */);
    ~TwoWayStack();
    void createStack(int size);
    void pushfront(int x);
    void pushend(int x);
    void popfront();
    void popend();
    int peak1();
    int peak2();
    void view();
    bool isempty();
};
void TwoWayStack::view()
{
    while (top1 != -1)
    {
        cout << peak1() << " ";
        popfront();
    }
    cout << "\n\n";
    while (top2 != capacity)
    {
        cout << peak2() << " ";
        popend();
    }
}
bool TwoWayStack::isempty()
{
    if (top1 == -1 && top2 == capacity)
        return 1;
    return 0;
}
int TwoWayStack::peak2()
{
    if (top2 == capacity)
        return -1;
    return ptr[top2];
}
int TwoWayStack::peak1()
{
    if (top1 == -1)
        return -1;
    return ptr[top1];
}
void TwoWayStack::popfront()
{
    if (top1 != -1)
    {
        top1--;
    }
    else
        return;
}
void TwoWayStack::popend()
{
    if (top2 != capacity)
    {
        top2++;
    }
    else
        return;
}

void TwoWayStack::pushfront(int x)
{
    if (top2 != top1 + 1)
    {
        top1++;
        ptr[top1] = x;
    }
    else
        cout << "stack is fulled\n";
}
void TwoWayStack::pushend(int x)
{
    if (top2 != top1 + 1)
    {
        top2--;
        ptr[top2] = x;
    }
    else
        cout << "stack is fulled\n";
}
void TwoWayStack::createStack(int size)
{
    capacity = size;
    ptr = new int[capacity];
    top1 = -1;
    top2 = capacity;
}
TwoWayStack::TwoWayStack(/* args */)
{
    ptr = nullptr;
    capacity = 0;
    top1 = -1;
    top2 = capacity;
}

TwoWayStack::~TwoWayStack()
{
    while (top1 != -1)
        popfront();
    while (top2 != capacity)
        popend();
}
int main()
{
    TwoWayStack tws;
    tws.createStack(10);
    cout << "em " << tws.isempty() << endl;
    tws.pushend(10);
    tws.pushfront(1);
    tws.pushend(20);
    tws.pushfront(2);
    tws.pushend(50);
    tws.pushfront(5);
    tws.pushfront(6);
    tws.popend();
    tws.popend();
    tws.popend();
    tws.popend();
    tws.pushfront(7);
    tws.pushfront(15);
    tws.pushfront(7);
    tws.pushfront(15);
    tws.pushfront(7);
    tws.pushfront(15);
    tws.popfront();
    tws.popend();
    tws.pushfront(7);
    tws.popfront();
    tws.pushend(90);

    cout << tws.peak1() << endl;
    cout << tws.peak2() << endl;
    cout << "em " << tws.isempty() << endl;
    tws.view();
    cout << endl;
}