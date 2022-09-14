#include <iostream>
using namespace std;
class LinearQueue
{
private:
    int capacity;
    int rear, front;
    int *ptr;

public:
    LinearQueue()
    {
        ptr = nullptr;
        rear = -1;
        front = -1;
    }
    void createQueue(int size)
    {
        capacity = size;
        ptr = new int[capacity];
        rear = -1;
        front = -1;
    }
    void insert(int x)
    {
        if (rear == -1)
        {
            front++;
            rear++;
            ptr[rear] = x;
        }
        else if (rear != capacity - 1)
        {
            rear++;
            ptr[rear] = x;
        }
        else
            cout << "overflow\n";
    }
    int last()
    {
        return ptr[rear];
    }
    int first()
    {
        return ptr[front];
    }
    void view()
    {
        while (front <= rear)
        {
            cout << first() << " ";
            dequeue();
        }
        cout << "\n";
    }
    void dequeue()
    {
        if (rear != -1 && front <= rear)
            front++;
    }
    ~LinearQueue()
    {
        while (front <= rear)
        {
            dequeue();
        }
    }
    int isempty()
    {
        return (rear == -1 && front == -1);
    }
    bool isfull()
    {
        return (front == 0 && rear == capacity - 1);
    }
    int size()
    {
        return (rear - front) + 1;
    }
};
int main()
{
    LinearQueue q;
    q.createQueue(5);
    cout << q.isempty() << endl;
    q.insert(-1);
    q.view();
    q.insert(7);
    q.insert(9);
    q.insert(11);
    q.insert(13);
    cout << "size -> " << q.size() << endl;
    cout << q.isfull() << endl;
    q.insert(5);
    cout << q.isempty() << endl;
    cout << q.last() << endl;
    cout << q.first() << endl;
    q.view();
}
