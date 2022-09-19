#include <bits/stdc++.h>
using namespace std;
void print(deque<int> &d)
{
    for (auto it : d)
        cout << it << " ";
    cout << "\n";
}
int main()
{
    deque<int> d = {2, 3, 4};
    print(d);
    d.push_front(-1);
    // push data at end
    d.push_back(5);
    d.push_back(6);
    print(d);
    // push data at beginning
    d.push_front(1);
    d.push_front(0);
    print(d);// 0 1 -1 2 3 4 5 6 

    // poping data from end 
    d.pop_back();
    d.pop_back();
    print(d);//0 1 -1 2 3 4 
    // poping data from beginning
    d.pop_front();
    print(d);//1 -1 2 3 4 
    d.pop_front();
    print(d);//-1 2 3 4
    d.pop_front();
    print(d);//2 3 4

    // now push data at end;
    d.push_back(10);
    d.push_back(10);
    print(d);//2 3 4 10 10
    // here also push the data at beginning
    d.push_front(-10);
    d.push_front(-20);
    print(d);//-20 -10 2 3 4 10 10

}