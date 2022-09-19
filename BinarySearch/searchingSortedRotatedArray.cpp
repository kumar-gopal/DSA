#include <iostream>
using namespace std;
int find(int a[], int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == k)
            return mid;
        if (a[low] < a[mid])
        {
            if (k >= a[low] && k < a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (k >= a[mid] && k < a[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
}
int main()
{
}