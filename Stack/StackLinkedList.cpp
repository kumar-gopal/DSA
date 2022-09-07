#include <iostream>
using namespace std;
class StackLinkedList
{
private:
    struct node
    {
        int data;
        node *next;
    };
    node *top;

public:
    StackLinkedList(/* args */);
    ~StackLinkedList();
    void pop();
    void push(int x);
    bool isempty();
    int peak();
    void view();
};
void StackLinkedList::view()
{
    while (!isempty())
    {
        cout << peak() << " ";
        pop();
    }
}
int StackLinkedList::peak()
{
    if (top == nullptr)
        return -1;
    return top->data;
}
bool StackLinkedList::isempty()
{
    if (top == nullptr)
        return 1;
    return 0;
}
void StackLinkedList::pop()
{
    if (top == nullptr)
        cout << "stack is empty \n";
    else
    {
        node *t = top;
        top = top->next;
        delete t;
    }
}
void StackLinkedList::push(int x)
{
    node *n = new node;
    n->data = x;
    n->next = top;
    top = n;
}
StackLinkedList::StackLinkedList(/* args */)
{
    top = nullptr;
}

StackLinkedList::~StackLinkedList()
{
    while (top)
    {
        pop();
    }
}
int main()
{
    StackLinkedList stll;
    stll.push(1);
    stll.push(2);
    stll.push(3);
    cout << stll.peak() << endl;
    cout << stll.isempty() << endl;
    stll.view();
    cout << endl;
    stll.~StackLinkedList();
    cout << stll.isempty() << endl;
    stll.push(10);
    stll.pop();
    cout<<stll.isempty()<<endl;
    stll.push(20);
    cout<<stll.peak()<<endl;
    stll.view();
}
