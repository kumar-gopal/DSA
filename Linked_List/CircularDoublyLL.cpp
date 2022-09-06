#include <bits/stdc++.h>
using namespace std;
class CircularDoublyLL
{
private:
    struct node
    {
        int data;
        node *prev;
        node *next;
    };
    node *head;

public:
    CircularDoublyLL(/* args */);
    ~CircularDoublyLL();
    void viewForward();
    void createCdLL(int a[], int n);
    void viewBacckward();
    node *search(int x)
    {
        node *temp = head;
        do
        {
            if (temp->data == x)
                return temp;
            temp = temp->next;
        } while (temp != head);
        return nullptr;
    }
    void insertAtFirst(int x);
    void insertAtLast(int x);
    void insertAtAfter(int data, int x);
    void insertAtBefore(int x, int data);
    void DeleteAtFirst();
    void DeleteAtLast();
    void DeleteGiven(int x);
    void DeleteBefore(int data);
};
void CircularDoublyLL::DeleteBefore(int data)
{
    if (head == nullptr)
        cout << "underflow conditon hit \n";
    else
    {
        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            node *temp = search(data);
            if (temp != head && temp)
            {
                node *del = temp->prev;
                if (del == head)
                    head = head->next;
                del->prev->next = del->next;
                temp->prev = del->prev;
                delete del;
            }
            else
                cout << "CAN'T DELETE BEFORE IT \n";
        }
    }
}
void CircularDoublyLL::DeleteGiven(int x)
{
    if (head == nullptr)
        cout << "underflow condition hit \n";
    else
    {
        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            node *t = search(x);
            if (t->prev == t->next || t == head)
                head = t->next;

            t->next->prev = t->prev;
            t->prev->next = t->next;
            delete t;
        }
    }
}
void CircularDoublyLL::insertAtBefore(int x, int data)
{
    if (head == nullptr)
        cout << "underflow condition hit \n";
    else
    {
        node *t = search(data);
        node *n = new node;
        if (t)
        {
            if (t == head)
                head = n;
            n->data = x;
            n->next = t;
            n->prev = t->prev;
            t->prev = n;
            n->prev->next = n;
        }
        else
            cout << "CAN'T INSERT BEFORE THIS \n";
    }
}
void CircularDoublyLL::insertAtAfter(int data, int x)
{
    if (head == nullptr)
        cout << "insertion not possible here \n";
    else
    {
        node *n = new node;
        n->data = x;
        node *temp = search(data);
        if (temp)
        {
            n->next = temp->next;
            n->prev = temp;
            temp->next = n;
            n->next->prev = n;
        }
        else
            cout << "CAN'T INSERT BEFORE THIS \n";
    }
}
void CircularDoublyLL::DeleteAtLast()
{
    if (head == nullptr)
        cout << "underflow \n";
    else
    {
        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            node *last = head->prev;
            last->prev->next = last->next;
            head->prev = last->prev;
        }
    }
}
void CircularDoublyLL::DeleteAtFirst()
{
    if (head == nullptr)
        cout << "underflow \n";
    else
    {
        node *first = head;
        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            head->next->prev = head->prev;
            head->prev->next = head->next;
            head = head->next;
            delete first;
        }
    }
}
void CircularDoublyLL::insertAtLast(int x)
{
    node *n = new node;
    n->data = x;
    if (head == nullptr)
    {
        n->next = n;
        n->prev = n;
        head = n;
    }
    else
    {
        n->next = head->prev->next;
        n->prev = head->prev;
        head->prev->next = n;
        head->prev = n;
    }
}
void CircularDoublyLL::insertAtFirst(int x)
{
    node *n = new node;
    n->data = x;
    if (head == nullptr)
    {
        n->next = n;
        n->prev = n;
        head = n;
    }
    else
    {
        n->next = head;
        n->prev = head->prev;
        head->prev->next = n;
        head->prev = n;
        head = n;
    }
}
void CircularDoublyLL::viewForward()
{
    node *t = head;
    do
    {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << endl;
}
void CircularDoublyLL::viewBacckward()
{
    node *last = head->prev;
    do
    {
        cout << last->data << " ";
        last = last->prev;
    } while (last != head->prev);
}
void CircularDoublyLL::createCdLL(int a[], int n)
{
    node *first = new node;
    first->data = a[0];
    first->next = first;
    first->prev = first;
    head = first;
    node *curr = first;
    for (int i = 1; i < n; i++)
    {
        node *n = new node;
        n->data = a[i];
        n->next = curr->next;
        n->prev = curr;
        curr->next = n;
        curr = n;
    }
    head->prev = curr;
}

CircularDoublyLL::CircularDoublyLL(/* args */)
{
    head = nullptr;
}

CircularDoublyLL::~CircularDoublyLL()
{
    node *temp = head;
    do
    {
        DeleteAtFirst();
        temp = temp->next;
    } while (temp != head->next);
    head = nullptr;
}

int main()
{
    CircularDoublyLL CDLL;
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    // CDLL.createCdLL(a, n);
    CDLL.insertAtFirst(1);
    CDLL.insertAtFirst(2);
    CDLL.insertAtLast(11);
    // CDLL.insertAtLast(22);
    CDLL.viewForward();
    CDLL.DeleteGiven(1);
    // CDLL.insertAtFirst(-11);
    // CDLL.insertAtLast(9);
    CDLL.viewForward();
    // CDLL.DeleteAtLast();
    CDLL.insertAtAfter(2, 13);
    CDLL.viewForward();
    CDLL.insertAtBefore(66, 13);
    cout << CDLL.search(100) << endl;
    CDLL.viewForward();
    cout << "gopal\n";
    CDLL.insertAtAfter(1, 7);
    CDLL.insertAtAfter(7, 9);
    CDLL.viewForward();
    CDLL.insertAtBefore(0, 1);
    CDLL.insertAtAfter(1, 91);
    CDLL.insertAtBefore(90, 91);
    CDLL.insertAtFirst(0);
    CDLL.insertAtLast(17);
    CDLL.viewForward();
    CDLL.DeleteAtLast();
    CDLL.DeleteAtFirst();
    CDLL.viewForward();
    CDLL.DeleteBefore(66);
    CDLL.insertAtLast(2);
    CDLL.insertAtBefore(9, 3);
    CDLL.insertAtAfter(3, 13);
    CDLL.viewForward();
    // CDLL.insertAtLast(2);
    // CDLL.insertAtLast(3);
    CDLL.~CircularDoublyLL();
    cout << "Below \n";

    CDLL.insertAtLast(3999);
    CDLL.insertAtLast(2);
    CDLL.insertAtBefore(9, 2);
    CDLL.insertAtAfter(9, 13);
    // CDLL.viewBacckward();
    CDLL.viewForward();
}