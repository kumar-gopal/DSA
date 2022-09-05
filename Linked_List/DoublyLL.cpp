#include <bits/stdc++.h>
using namespace std;
class DoublyLL
{
private:
    struct Node
    {
        int data;
        Node *pre;
        Node *next;
    };
    Node *head;

public:
    DoublyLL(/* args */);
    ~DoublyLL();
    viewData();
    void viewBackward();
    createDoublyLL(int a[], int n);
    Node *search(int data)
    {
        Node *t = head;
        while (t != nullptr)
        {
            if (t->data == data)
                return t;
            t = t->next;
        }
        return NULL;
    }
    insertAtFirst(int data);
    insertAtLast(int data);
    insertAtGivenPosition(int x, int data);
    void insertBeforeNode(int data, int x);
    DeleteAtFirst();
    void DeleteAtLast();
    void DeleteAtGivenNode(int x);
    void DeleteBeforeNode(int x);
};

void DoublyLL::DeleteBeforeNode(int x)
{
    Node *temp = search(x);
    if (temp == nullptr)
    {
        cout << "element not found \n";
        return;
    }
    if (temp->pre != nullptr)
    {
        Node *del = temp->pre;
        if (del->pre == nullptr)
        {
            temp->pre = del->pre;
            head = del->next;
            del->next = nullptr;
            delete del;
            return;
        }
        else
        {
            temp->pre = del->pre;
            del->pre->next = del->next;
            del->pre = nullptr;
            del->next = nullptr;
            delete del;
            return;
        }
    }
    else
        cout << "can't delete \n";
}
void DoublyLL::DeleteAtGivenNode(int x)
{
    Node *t = search(x);
    if (t == NULL)
    {
        cout << "element not found \n";
        return;
    }
    if (head == nullptr)
        cout << "deletion not possible \n";
    // only one node present
    else if (head->next == nullptr)
    {
        head = nullptr;
        return;
    }
    else
    {
        // for 1st node.
        if (t->pre == nullptr)
        {
            t->next->pre = t->pre;
            head = head->next;
            t->next = nullptr;
            delete t;
            return;
        }
        else
        {
            // for last node
            if (t->next == nullptr)
            {
                t->pre->next = t->next;
                t->pre = nullptr;
                delete t;
                return;
            }
            else
            {
                t->next->pre = t->pre;
                t->pre->next = t->next;
                t->pre = nullptr;
                t->next = nullptr;
                delete t;
                return;
            }
        }
    }
}

void DoublyLL::DeleteAtLast()
{
    Node *last = head;
    if (head == nullptr)
        cout << "deletion not psbl in last";
    while (last->next != nullptr)
    {
        last = last->next;
    }
    if (head->next == nullptr)
    {
        head = nullptr;
        return;
    }
    else
    {
        last->pre->next = nullptr;
        last->pre = nullptr;
        delete last;
    }
}
DoublyLL::DeleteAtFirst()
{
    if (head == nullptr)
        cout << "deletion not psblv\n";
    else if (head->next == nullptr)
        head = nullptr;
    else
    {
        Node *first = head;
        first->next->pre = nullptr;
        Node *temp = first->next;
        first->next = nullptr;
        delete first;
        head = temp;
    }
}
void DoublyLL::insertBeforeNode(int data, int x)
{
    Node *n = new Node;
    n->data = data;
    Node *ptr = search(x);
    if (ptr == nullptr)
    {
        cout << "element is not found \n";
        return;
    }
    n->next = ptr;
    n->pre = ptr->pre;
    ptr->pre = n;

    if (n->pre == nullptr)
    {
        head = n;
    }
    else
        n->pre->next = n;
}
DoublyLL::insertAtGivenPosition(int x, int data)
{
    Node *n = new Node;
    n->data = data;
    Node *ptr = search(x);
    if (ptr == nullptr)
    {
        cout << "element not found\n";
    }
    else if (ptr->next != nullptr)
    {
        n->next = ptr->next;
        // edge condition we change the pre of new node because pre is points the
        // previous node before inserting that's why we change pre to new node
        ptr->next->pre = n;
        ptr->next = n;
        n->pre = ptr;
    }
    else
    {
        n->next = ptr->next;
        ptr->next = n;
        n->pre = ptr;
    }
}
DoublyLL::insertAtFirst(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->pre = nullptr;
    new_node->next = head;
    if (head != nullptr)
    {
        head->pre = new_node;
    }
    head = new_node;
}
DoublyLL::insertAtLast(int data)
{
    Node *n = new Node;
    n->data = data;
    n->next = nullptr;
    if (head == nullptr)
    {
        n->pre = nullptr;
        head = n;
    }
    else
    {
        Node *last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = n;
        n->pre = last;
    }
}
DoublyLL::DoublyLL(/* args */)
{
    head = nullptr;
}
DoublyLL::createDoublyLL(int a[], int n)
{
    Node *currNode, *first = new Node;
    first->data = a[0];
    first->next = nullptr;
    first->pre = nullptr;
    head = first;
    currNode = head;
    for (int i = 1; i < n; i++)
    {
        Node *new_node = new Node;
        new_node->data = a[i];
        new_node->next = nullptr;
        new_node->pre = currNode;
        currNode->next = new_node;
        currNode = new_node;
    }
}
void DoublyLL::viewBackward()
{
    Node *last = head;
    if (head == NULL)
    {
        cout << "no prev node \n";
        return;
    }
    while (last->next != nullptr)
    {
        last = last->next;
    }
    while (last != head)
    {
        cout << last->data << " ";
        last = last->pre;
    }
    // when last==head will true then left the data of head (1st value)
    if (last != nullptr)
        cout << last->data << " ";
    cout << "\n";
}
DoublyLL::viewData()
{
    Node *temp = head;
    if (head == nullptr)
        cout << "no node here \n";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

DoublyLL::~DoublyLL()
{
}

int main()
{
    DoublyLL dll;
    int a[] = {1, 2, 3, 4, 5};
    dll.createDoublyLL(a, sizeof(a) / sizeof(a[0]));
    dll.insertAtFirst(-7);
    dll.insertAtFirst(110);
    dll.insertAtFirst(100);
    dll.insertAtFirst(1190);
    dll.insertAtLast(-2);
    dll.insertAtLast(3);
    dll.insertAtLast(-1);
    dll.insertAtLast(14);
    dll.viewData();
    dll.DeleteAtFirst();
    dll.DeleteAtLast();
    dll.DeleteAtGivenNode(-1);
    dll.DeleteBeforeNode(3);
    dll.viewData();
    dll.insertAtGivenPosition(3, 7);
    dll.viewData();
    dll.insertBeforeNode(17, 7);
    dll.viewBackward();
    dll.viewData();

}
