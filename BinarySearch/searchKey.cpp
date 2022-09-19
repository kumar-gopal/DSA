#include <bits/stdc++.h>
using namespace std;
int BinarySearch(vector<int> &v, int key)
{
    int start = 0, end = v.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] == key)
            return mid;
        else if (v[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}
int main()
{
    vector<int>v={1,2,3,4,5,6,7,8,9,10};
    cout<<BinarySearch(v,100);
}