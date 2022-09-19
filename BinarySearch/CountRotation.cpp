// Find the Rotation Count in Rotated Sorted array
#include <iostream>
using namespace std;

int findKRotation(int arr[], int n)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start);
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
            return mid;
        else if (arr[start] <= arr[mid])
            start = (mid + 1);
        else
            end = mid - 1;
    }
    return 0;
}
int main()
{
    int arr[] = {4,5,6,7,0,1,2};
    
    cout << findKRotation(arr, 7);
}