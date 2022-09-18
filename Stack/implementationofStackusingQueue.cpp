#include <iostream>
#include <queue>
using namespace std;
class stackUsingQueue
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int x)
    {

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop()
    {
        q1.pop();
    }
    void view()
    {
        while (!q1.empty())
        {
            cout << q1.front() << " ";
            q1.pop();
        }
    }
};
int main()
{
    stackUsingQueue sq;
    sq.push(1);
    sq.push(2);
    sq.push(3);
    sq.push(4);
    sq.pop();
    sq.push(7);
    sq.push(6);
    sq.pop();
    sq.view();
}