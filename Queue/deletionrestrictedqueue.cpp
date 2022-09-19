
// deletion restricted queue :-- in this queue deletion is
// allow rear end only and insertion allowed both ended
// rear as well as front.

#include <iostream>
using namespace std;
class deletionRestrictedQueue
{
private:
    int capacity;
    int front, rear;
    int *ptr;

public:
    deletionRestrictedQueue()
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
    void insertAtfront(int x)
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
    void insert_rear(int x)
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

    ~deletionRestrictedQueue()
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
