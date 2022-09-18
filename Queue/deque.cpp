#include <iostream>
#include <limits.h>
using namespace std;
class deque
{
private:
    int capacity;
    int front, rear;
    int *ptr;

public:
    deque();
    ~deque();
    void createdeque(int size);
    void insertAtfront(int x);
    void insertAtrear(int x);
    void deleteAtfront();
    void deleteAtrear();
    void view()
    {
        int temp = front;
        while (temp != rear)
        {
            cout << ptr[temp] << " ";
            temp = (temp + 1) % capacity;
        }
        if (temp == -1)
        {
            cout << "empty\n";
        }
        else
            cout << ptr[temp] << endl;
    }
};
void deque::createdeque(int size)
{
    capacity = size;
    ptr = new int[capacity];
}
void deque::insertAtfront(int x)
{
    // check if queue is full ?
    // if((front==0&&rear==capacity-1)||(rear+1==front))
    // or below work in both cases (which is mentioned above condition)
    if (((rear + 1) % capacity == front))
    {
        cout << "queue is full \n";
        return;
    }
    // insert 1st data in front
    else if (rear == -1 && front == -1)
    {
        front = rear = 0;
        ptr[front] = x;
    }
    // normal cases
    else
    {
        int n = capacity;
        front = (front - 1 + n) % n;
        ptr[front] = x;
    }
}
void deque::insertAtrear(int x)
{
    if (((rear + 1) % capacity == front))
    {
        cout << "queue is full \n";
        return;
    }
    // insert 1st data in front
    else if (rear == -1 && front == -1)
    {
        front = rear = 0;
        ptr[front] = x;
    }
    else
    {
        rear = (rear + 1) % capacity;
        ptr[rear] = x;
    }
}
void deque::deleteAtfront()
{
    if (ptr == nullptr)
    {
        cout << "underflow \n";
        return;
    }
    else if (rear == 0 && front == 0)
    {
        rear = front = -1;
    }
    else if (rear == front)
    {
        rear = front = -1;
    }

    else
    {
        front = (front + 1) % capacity;
    }
}
void deque::deleteAtrear()
{
    if (ptr == nullptr)
    {
        cout << "underflow \n";
        return;
    }
    else if (rear == 0 && front == 0)
    {
        rear = front = -1;
    }
    else if (rear == front)
    {
        rear = front = -1;
    }
    else
    {
        rear = (rear - 1 + capacity) % capacity;
    }
}
deque::deque()
{
    capacity = 0;
    ptr = nullptr;
    rear = front = -1;
}

deque::~deque()
{
    int temp = front;
    while (temp != rear)
    {
        temp = (temp + 1) % capacity;
    }
}
