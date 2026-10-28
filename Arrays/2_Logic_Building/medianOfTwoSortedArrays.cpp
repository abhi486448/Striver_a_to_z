#include<bits/stdc++.h>
using namespace std;

// 4. Median of Two Sorted Arrays
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).
// Example 1:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 
// Constraints:
// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0;
        int p2 = 0;

        vector<int> new_arr;

        while(p1<nums1.size() || p2<nums2.size()){
            if(p1<nums1.size() && p2<nums2.size()){
                if(nums1[p1]<nums2[p2]){
                    new_arr.push_back(nums1[p1]);
                    p1++;
                } else if(nums2[p2]<nums1[p1]){
                    new_arr.push_back(nums2[p2]);
                    p2++;
                } else {
                    new_arr.push_back(nums2[p2]);
                    new_arr.push_back(nums2[p2]);
                    p2++;
                    p1++;
                }
            } else if(p1<nums1.size()){
                new_arr.push_back(nums1[p1]);
                p1++;
            } else {
                new_arr.push_back(nums2[p2]);
                p2++;
            }
        }
        int n = new_arr.size()/2;
        if(new_arr.size()%2 == 0){
            double sum = double(new_arr[n-1]) + double(new_arr[n]);
            return sum/2;
        } else {
            return new_arr[n];
        }
    }

int main(){
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3};

    cout<<findMedianSortedArrays(nums1, nums2)<<endl;
    return 0;
}

// note:-
// - don't overdo in code first reade carefully what needed then only solve