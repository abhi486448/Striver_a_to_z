#include<bits/stdc++.h>
using namespace std;

// 713. Union of two sorted arrays
// Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.

// The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.

// Example 1:
// Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]
// Output: [1, 2, 3, 4, 5, 7]
// Explanation:
// The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2
// Example 2:
// Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]
// Output: [1, 3, 4, 5, 6, 7, 8, 9]
// Explanation:
// The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2
// Example 3:
// Input: nums1 = [3, 4, 4, 4], nums2 = [6, 7, 7]
// Output:
// [3, 4, 6, 7]
// Constraints:
// 1 <= nums1.length, nums2.length <= 1000
// -104 <= nums1[i] , nums2[i] <= 104
// Both nums1 and nums2 are sorted in non-decreasing order

vector <int> unionOfArray(vector<int> &nums1,vector<int> &nums2){
    int p1 = 0;
    int p2 = 0;
    vector<int> new_arr;

    while(p1<nums1.size() || p2<nums2.size()){
        if(p1<nums1.size() && p2<nums2.size()){
            if(nums1[p1]<nums2[p2]){
                if(new_arr.size()==0 || new_arr.back()!=nums1[p1]){
                    new_arr.push_back(nums1[p1]);
                    p1++;
                } else {
                    p1++;
                }
            } else if(nums1[p1]>nums2[p2]){
                if(new_arr.size()==0 || new_arr.back()!=nums2[p2]){
                    new_arr.push_back(nums2[p2]);
                    p2++;
                } else {
                    p2++;
                }
            } else {
                if(new_arr.size()==0 || new_arr.back()!=nums2[p2]){
                    new_arr.push_back(nums1[p1]);
                    p1++;
                    p2++;
                } else {
                    p1++;
                    p2++;
                }
            }
        } else if(p1<nums1.size()){
            if(new_arr.size()==0 || new_arr.back()!=nums1[p1]){
                new_arr.push_back(nums1[p1]);
                p1++;
            } else {
                p1++;
            }
        } else {
            if(new_arr.size()==0 || new_arr.back()!=nums2[p2]){
                new_arr.push_back(nums2[p2]);
                p2++;
            } else {
                p2++;
            }
        }
    }
    return new_arr;
}

int main(){
    vector<int> nums1={1, 2, 3, 4, 5};
    vector<int> nums2={1, 2, 7};

    vector<int> new_arr;

    new_arr = unionOfArray(nums1, nums2);

    for(auto a:new_arr){
        cout<<a<<" ";
    }
    cout<<endl;

    return 0;
}

// note:- 
// - in new_arr there will be union of nums1 and nums2 that means all elements of nums1 and nums2 but unique and sorted
// dont forget edg cases like unique elements{ if both array have same element then push one of them and then increment pointer of both array }
// but before pushing any element we have to check whether that that element already exist in the new_arr or not