
// Insertion restricted queue :-- in this queue insertinon is
// allow rear end only and deletion allowed both ended
// rear as well as front.

#include <iostream>
using namespace std;
class insertionRestrictedQueue
{
private:
    int capacity;
    int front, rear;
    int *ptr;

public:
    insertionRestrictedQueue()
    {
        capacity = 0;
        ptr = nullptr;
        front = rear = -1;
    }
    void createQueue(int size)
    {
        capacity = size;
        ptr = new int[capacity];
        front = rear = -1;
    }
    void insertion(int x)
    {
        if ((rear + 1) % capacity == front)
        {
            cout << "overflow queue is full \n";
            return;
        }
        else if (rear == -1 && front == -1)
        {
            front = rear = 0;
            ptr[rear] = x;
            return;
        }
        else
        {
            rear = (rear + 1) % capacity;
            ptr[rear] = x;
        }
    }
    void delete_front()
    {
        if (ptr == nullptr)
        {
            cout << "underflow\n";
            return;
        }
        else if (rear == front)
        {
            rear = front = -1;
            return;
        }
        else
        {
            front = (front + 1) % capacity;
        }
    }
    void delete_rear()
    {
        if (ptr == nullptr)
        {
            cout << "underflow\n";
            return;
        }
        else if (rear == front)
        {
            rear = front = -1;
            return;
        }
        else
        {
            int n = capacity;
            rear = (rear - 1 + n) % n;
        }
    }
    ~insertionRestrictedQueue()
    {
        while (front != rear)
        {
            front = (front + 1) % capacity;
        }
        if ((front == rear))
            front = rear = -1;
    }
    void view()
    {
        int temp = front;
        while (temp != rear)
        {
            cout << ptr[temp] << " ";
            temp = (temp + 1) % capacity;
        }
        if (temp != -1)
            cout << ptr[temp] << endl;
        else
        {
            cout << "queue is empty";
            return;
        }
    }
};
