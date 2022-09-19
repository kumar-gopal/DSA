#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int> &nums)
{
    if (nums[0] < nums[nums.size() - 1])
        return nums[0];
    int low = 0, high = nums.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[0] <= nums[mid])
            low = mid + 1;
        else
            high = mid;
    }
    return nums[low];
}
int main()
{
    vector<int>arr={10,1,10,10,10};
    cout<<findMin(arr);
}