#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int v[],int n ,int key)
{
    int start = 0, end = n - 1;
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
int binarySearch1(int a[], int n, int key)
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
int ordersearch(int a[],int n,int key)
{
   if(a[0]<a[1])
   {
      return BinarySearch(a,n,key);
   }
   else
   {
      return binarySearch1(a,n,key);
   }
}
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,11};
    cout<<ordersearch(a,10,11)<<endl;
    int b[]={10,9,8,7,6,4,3,2,1,0};
    cout<<ordersearch(b,10,4);
}
