#include <bits/stdc++.h>
using namespace std;
class singlyLL
{
private:
    struct node
    {
        int item;
        node *next;
    };
    node *start;

public:
    singlyLL();
    ~singlyLL();
    void insertAtFirstNode(int data);
    void insertAtLastNode(int data);
    void insertAtGiventNode(int data, int item);
    void DeleteAtFirstNode();
    void DeleteAtLastNode();
    void DeleteAtGivenNode(int item);
    void viewData();
    createNode(int a[], int n);
    reverseLinkedList();
    node *searchData(int data)
    {
        node *temp = start;
        while (temp)
        {
            if (temp->item == data)
                return temp;
            temp = temp->next;
        }
        return 0;
    }
};

singlyLL::singlyLL(/* args */)
{
    start = NULL;
}
// create n size of linked list;
singlyLL::createNode(int a[], int n)
{
    node *currNode;
    node *N = new node;
    N->data = a[0];
    N->next = nullptr;
    start = N;
    currNode = start;

    for (int i = 1; i < n; i++)
    {
        node *temp = new node;
        temp->data = a[i];
        temp->next = nullptr;
        currNode->next = temp;
        currNode = temp;
    }
}
node singlyLL:: *reverseList()
{
    node *prev, *curr, *nxt;
    prev = NULL;
    curr = head;
    nxt = head->next;
    while (curr != NULL)
    {
        nxt=curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        
    } 
    return prev;
}

void singlyLL::viewData()
{
    node *temp = start;
    if (start == 0)
        cout << "no node\n";
    while (temp != NULL)
    {
        cout << temp->item << " ";
        temp = temp->next;
    }
    cout << endl;
}
void singlyLL::insertAtFirstNode(int data)
{
    // create new node
    node *n = new node;
    n->item = data;
    n->next = start;
    start = n;
}
void singlyLL::insertAtLastNode(int data)
{
    // create new node
    node *n = new node;
    n->item = data;
    n->next = NULL;
    if (start == NULL)
    {
        start = n;
    }
    else
    {
        node *temp;
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = n;
    }
}

void singlyLL::insertAtGiventNode(int data, int item)
{
    node *n = new node;
    n->item = data;
    node *temp = searchData(item);
    node *nxtNode = temp->next;
    temp->next = n;
    n->next = nxtNode;
}
void singlyLL::DeleteAtFirstNode()
{
    if (start == NULL)
    {
        cout << "\n1overflow ";
    }
    else
    {
        node *temp = start;
        start = temp->next;
        temp->next = NULL;
        delete temp;
    }
}
void singlyLL::DeleteAtLastNode()
{
    node *t1, *t2;
    if (start == 0)
        cout << "Lunderflow\n";
    else
    {
        t1 = start;
        t2 = NULL;
        while (t1->next != NULL)
        {
            t2 = t1;
            t1 = t1->next;
        }
        // VVI only one node present(hmse missed ho jata ye )
        if (t2 == NULL)
            start = NULL;
        else
            t2->next = NULL;
        delete t1;
    }
}
// VVI
void singlyLL::DeleteAtGivenNode(int item)
{
    node *t1, *t2;
    if (start == NULL)
        cout << "\n Gunderflow ";
    else
    {
        t1 = start;
        t2 = NULL;
        while (t1 != NULL)
        {
            if (t1->item == item)
                break;
            t2 = t1;
            t1 = t1->next;
        }
        if (t1 == nullptr)
            cout << "element not found \n";
        // 1ST NODE DELETE
        else if (t2 == nullptr)
        {
            start = t1->next;
            t1->next = nullptr;
            delete t1;
        }
        else
        {
            t2->next = t1->next;
            t1->next = NULL;
            delete t1;
        }
    }
}
singlyLL::~singlyLL()
{
}
