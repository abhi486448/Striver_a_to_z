#include<bits/stdc++.h>
using namespace std;

// 706. Intersection of two sorted arrays
// Given two sorted arrays, nums1 and nums2, return an array containing the intersection of these two arrays. Each element in the result must appear as many times as it appears in both arrays; that is, if an element appears x times in nums1 and y times in nums2, it should appear min(x, y) times in the result.

// The intersection of two arrays is an array where all values are present in both arrays. Since both input arrays are sorted, the resulting intersection array should also be in sorted order.

// Example 1:
// Input: nums1 = [1, 2, 2, 3, 5], nums2 = [1, 2, 7]
// Output: [1, 2]
// Explanation:
// The elements 1, 2 are the only elements present in both nums1 and nums2
// Example 2:
// Input: nums1 = [1, 2, 2, 3, 3, 3], nums2 = [2, 3, 3, 4, 5, 7]
// Output: [2, 3, 3]
// Explanation:
// The element 2 appears in both arrays only one time.
// The element 3 appears in both arrays two times so we add element 3 equal to its number of occurrences.
// Constraints:
// 1 <= nums1.length, nums2.length <= 1000
// -104 <= nums1[i], nums2[i] <= 104
// Both nums1 and nums2 are sorted in non-decreasing order.

vector<int> intersectionOfTwoArrays(vector<int> &nums1,vector<int> &nums2){
    int p1 = 0;
    int p2 = 0;
    vector<int> new_arr;

    while(p1<nums1.size() || p2<nums2.size()){
        if(nums1[p1]<nums2[p2]){
            p2++;
        } else if(nums2[p2]<nums1[p1]){
            p1++;
        } else {
            new_arr.push_back(nums1[p1]);
            p1++;
            p2++;
        }
    }

    return new_arr;
}

int main(){
    vector<int> nums1={1, 2, 2, 3, 5};
    vector<int> nums2={1, 2, 7};

    vector<int> new_arr;

    new_arr = intersectionOfTwoArrays(nums1, nums2);

    for(auto a:new_arr){
        cout<<a<<" ";
    }
    cout<<endl;

    return 0;
}