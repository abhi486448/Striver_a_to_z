#include<bits/stdc++.h>
using namespace std;

// better
void betterMergeTwoArrays(vector<int> &nums1,int m,vector<int> &nums2,int n){
    int p1 = m;
    int p2 = 0;
    for(int i=p2; i<n; i++){
        nums1[p1]=nums2[i];
        p1++;
    }
    sort(nums1.begin(), nums1.end());
}
// complexcity 
// time = n + (n+m log n+m);

// best 
void bestMergeTwoArrays(vector<int> &nums1, int m,vector<int> &nums2,int n){
    int p1 = m-1;
    int p2 = n-1;
    int p = n+m-1;
    while(p1>=0 && p2>=0){
        if(nums1[p1]>nums2[p2]){
            nums1[p]=nums1[p1];
            p--;
            p1--;
        } else {
            nums1[p]=nums2[p2];
            p--;
            p2--;
        }
    }
    while(p1>=0){
        nums1[p]=nums1[p1];
        p--;
        p1--;
    }
    while(p2>=0){
        nums1[p]=nums2[p2];
        p--;
        p2--;
    }
}
// complexcity
// time = O(n+m);

int main(){
    vector<int> nums1={-5, -2, 4, 5, 0, 0, 0};
    vector<int> nums2={-3, 1, 8};
    int n=nums2.size();
    // betterMergeTwoArrays(nums1, 4, nums2, n);
    bestMergeTwoArrays(nums1, 4, nums2, n);

    for(auto i:nums1){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}