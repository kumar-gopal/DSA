#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
} *first = nullptr;

int issorted(node *temp)
{
    node *t2 = temp;

    while (t2 != nullptr && t2->next->data > t2->data)
    {
        return -1;
        t2 = t2->next;
    }
    return 1;
}
int maxMin(node *t)
{
    static int max1 = INT_MIN;
    if (t->next == 0)
        return t->data;
    if (t != 0)
    {
        if (max1 < t->data)
        {
            max1 = t->data;
        }
        maxMin(t->next);
    }
    return max1;
}
int sum(node *temp)
{
    int s = 0;
    if (temp != 0)
    {
        s += temp->data;
        return s + sum(temp->next);
    }
}
int count(node *temp)
{
    int cnt = 0;
    if (temp != nullptr)
        return 1 + (count(temp->next));
}
display(node *temp)
{
    if (temp == nullptr)
        return 0;
    cout << temp->data << " ";
    display(temp->next);
}

node *insertInMiddle(node *head, int x)
{
    int cnt = 0;
    node *t = head;
    node *currNode, *temp = head;
    while (t != 0)
    {
        cnt++;
        t = t->next;
    }
    int mid = 0;
    if (cnt % 2)
        cnt = cnt / 2 + 1;
    else
        cnt = cnt / 2;
    cout << cnt << endl;
    while (temp != 0)
    {
        if (cnt - 1 == mid)
        {
            node *n = new node;
            n->data = x;
            n->next = temp->next;
            temp->next = n;
            cout << temp->next << " " << temp->data << endl;
            break;
        }
        else
            temp = temp->next;
        mid++;
    }

    return head;
}
void createNode(int a[], int n)
{
    node *currNode;
    node *N = new node;
    N->data = a[0];
    N->next = nullptr;
    first = N;
    currNode = first;

    for (int i = 1; i < n; i++)
    {
        node *temp = new node;
        temp->data = a[i];
        temp->next = nullptr;
        currNode->next = temp;
        currNode = temp;
    }
}
void Display(node *First)
{
    node *temp = First;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
struct node *reverseList(struct node *head)
{
    node *prev, *curr, *nxt;
    prev = NULL;
    curr = head;
    nxt = head->next;
    if (head == NULL)
        return head;
    while (curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
int main()
{
    int a[] = {1, 2, 2, 1};
    createNode(a, sizeof(a) / sizeof(int));
    node *t = insertInMiddle(first, 3);
    display(t);
    cout<<endl;
    node *t1 = reverseList(t);
   
    display(t1);
    cout << endl;
    cout << count(t);
    cout << endl;
    cout << sum(t);
    cout << endl;
    cout << maxMin(t)<<endl;
    cout << issorted(t);
}