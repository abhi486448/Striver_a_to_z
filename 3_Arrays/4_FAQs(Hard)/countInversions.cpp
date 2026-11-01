#include<bits/stdc++.h>
using namespace std;

int Merge(vector<int> &nums, int low, int mid, int high){
    int cnt = 0;
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            cnt += (mid-left+1);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i=low; i<=high; i++){
        nums[i]=temp[i-low];
    }
    return cnt;
}

int mergeSort(vector<int> &nums, int low, int high){
    int cnt = 0;
    if(low==high) return cnt;
    int mid = (low+high)/2;
    cnt += mergeSort(nums, low, mid);
    cnt += mergeSort(nums, mid+1, high);
    cnt += Merge(nums, low, mid, high);
    return cnt;

}

int countInversions(vector<int> &nums){
    return mergeSort(nums, 0, nums.size()-1);
}

int main(){
    vector<int> nums={2, 3, 7, 1, 3, 5};
    cout<<countInversions(nums)<<endl;
    return 0;
}