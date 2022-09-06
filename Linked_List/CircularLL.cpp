#include <bits/stdc++.h>
using namespace std;
class CircularLL
{
private:
    struct node
    {
        int data;
        node *next;
    };
    node *last;

public:
    CircularLL()
    {
        last = nullptr;
    }
    ~CircularLL();
    void createCLL(int a[], int n);
    void view();
    node *search(int x)
    {
        node *temp = last->next;
        do
        {
            if (temp->data == x)
                return temp;
            temp = temp->next;

        } while (temp != last->next);
        return NULL;
    }
    void insertAtFirst(int data);
    void insertAtLast(int data);
    void insertAtGiven(int data, int x);
    void insertBeforeNode(int x, int data);
    void DeleteAtFirst();
    void DeleteAtLast();
    void DeleteAtGiven(int x);
    void DeleteBeforeNode(int x);
};
void CircularLL::DeleteBeforeNode(int x)
{
    if (last == nullptr)
    {
        cout << "nullptr";
        return;
    }
    else
    {
        node *pre, *curr, *temp = last->next;
        curr = nullptr;
        pre = curr;
        while (temp->next != last->next)
        {
            if (temp->data == x)
                break;
            pre = curr;
            curr = temp;
            temp = temp->next;
        }
        if (last->next->data != x)
        {
            if (pre == nullptr)
            {
                last->next = curr->next;
                delete curr;
            }
            else
            {
                pre->next = curr->next;
                delete curr;
            }
        }
        else
            cout << "U CAN'T DELETE IT \n";
    }
}
void CircularLL::DeleteAtGiven(int x)
{
    if (last == nullptr)
        cout << "deletion not possible \n";
    else
    {
        if (last->next == last)
        {
            delete last;
            last = nullptr;
        }

        else
        {
            node *t = last->next;
            node *p = nullptr;
            while (t->next != last->next)
            {
                if (t->data == x)
                    break;
                p = t;
                t = t->next;
            }
            if (p == nullptr)
            {
                last->next = t->next;
                delete t;
            }
            else
            {
                if (t->next == last->next)
                {
                    p->next = t->next;
                    delete t;
                    last = p;
                }
                else
                {
                    p->next = t->next;
                    delete t;
                }
            }
        }
    }
}
void CircularLL::DeleteAtLast()
{
    node *t = last->next;
    if (last == nullptr)
        cout << "deletion not possible \n";
    else
    {
        if (last->next == last)
        {
            delete last;
            last = nullptr;
        }
        else
        {
            while (t->next != last)
            {
                t = t->next;
            }
            t->next = last->next;
            delete last;
            last = t;
        }
    }
}
void CircularLL::DeleteAtFirst()
{
    if (last == nullptr)
    {
        cout << "deletion not possible \n";
    }
    else
    {
        node *first = last->next;
        if (last->next == last)
        {
            delete last;
            last = nullptr;
        }
        else
        {
            last->next = first->next;
            delete first;
        }
    }
}
void CircularLL::insertBeforeNode(int x, int data)
{
    if (last == nullptr)
        cout << "insertion not possible here \n";
    node *new_node = new node;
    new_node->data = x;
    node *prev = nullptr;
    node *temp = last->next;
    while (temp->next != last->next)
    {
        if (temp->data == data)
            break;
        prev = temp;
        temp = temp->next;
    }
    if (prev == nullptr)
    {
        new_node->next = temp;
        last->next = new_node;
    }
    else
    {
        new_node->next = prev->next;
        prev->next = new_node;
    }
}
void CircularLL::insertAtGiven(int data, int x)
{
    node *n = new node;
    n->data = x;
    node *t = search(data);
    if (t == nullptr)
    {
        cout << "insertion not possible \n";
        return;
    }
    else
    {
        if (t == last)
        {
            n->next = t->next;
            t->next = n;
            last = n;
            return;
        }
        n->next = t->next;
        t->next = n;
    }
}
void CircularLL::insertAtLast(int data)
{
    node *n = new node;
    n->data = data;
    if (last == nullptr)
    {
        n->next = n;
        last = n;
    }
    else
    {
        n->next = last->next;
        last->next = n;
        last = n;
    }
}
void CircularLL::insertAtFirst(int data)
{
    node *n = new node;
    n->data = data;
    if (last == nullptr)
    {
        n->next = n;
        last = n;
    }
    else
    {
        // last->next poits to very first node.
        n->next = last->next;
        last->next = n;
    }
}

void CircularLL::createCLL(int a[], int n)
{
    node *first = new node;
    first->data = a[0];
    first->next = first;
    last = first;
    for (int i = 1; i < n; i++)
    {
        node *new_node = new node;
        new_node->data = a[i];
        new_node->next = last->next;
        last->next = new_node;
        last = new_node;
    }
}
void CircularLL::view()
{
    node *temp = last->next;
    if (last == 0)
    {
        cout << "no node \n";
        return;
    }
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last->next);
    cout << "\n";
}

CircularLL::~CircularLL()
{
    while (last)
    {
        DeleteAtFirst();
    }
}
int main()
{
    CircularLL CLL;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);
    CLL.createCLL(a, n);
    CLL.insertAtLast(1);
    CLL.insertAtLast(2);
    CLL.insertAtLast(3);
    CLL.insertAtLast(4);
    CLL.insertBeforeNode(0, 1);
    CLL.insertAtGiven(0, 5);
    CLL.view();
    CLL.DeleteBeforeNode(5);
    CLL.DeleteAtGiven(4);
    CLL.DeleteAtFirst();
    CLL.DeleteAtLast();
    CLL.insertBeforeNode(0,1);
    CLL.insertAtGiven(2,11);
    CLL.view();
}