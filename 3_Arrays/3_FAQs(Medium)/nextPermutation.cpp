#include <bits/stdc++.h>
using namespace std;

// with stl
void stlNextPermutation(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
}

// best
void nextPermutation(vector<int> &nums)
{
    int idx = -1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        for (int i = nums.size(); i > idx; i--)
        {
            if (nums[i] > nums[idx])
            {
                swap(nums[i], nums[idx]);
                break;
            }
        }
        reverse(nums.begin() + idx + 1, nums.end());
    }
}

int main()
{
    vector<int> nums = {4, 3, 2, 1};
    // stlNextPermutation(nums);
    nextPermutation(nums);

    for (auto a : nums)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}