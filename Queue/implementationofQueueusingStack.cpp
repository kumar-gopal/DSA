#include <iostream>
#include <stack>
using namespace std;
class queueStack
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x)
    {
        s1.push(x);
    }
    void pop()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void view()
    {
        while (!s1.empty())
        {
            cout << s1.top() << " ";
            s1.pop();
        }
        cout << endl;
    }
};
int main()
{
    queueStack qs;
    qs.push(1);
    qs.push(2);
    qs.push(3);
    qs.push(4);
    qs.pop();
    qs.push(5);
    qs.pop();
    qs.push(9);
    qs.pop();
    qs.view();
}
