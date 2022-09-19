#include <bits/stdc++.h>
using namespace std;
int binarySearchInDecentarray(int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == key)
            return mid + 1;
        else if (a[mid] > key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int a[]={10,9,8,7,6,1,0,-1,-3};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<n<<endl;
    cout<<binarySearchInDecentarray(a,n,8);
}