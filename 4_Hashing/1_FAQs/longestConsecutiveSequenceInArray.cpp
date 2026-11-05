#include<bits/stdc++.h>
using namespace std;

// with ordered set
int longestConsecutive(vector<int>& nums) {
    set<int> st;
    for(auto i:nums){
        st.insert(i);
    }
    int maxC = 0;
    int count = 1;
    int el = INT_MIN;
    for(auto i:st){
        cout<<i<<endl;
    }
    cout<<endl;
    for(auto i:st){
        if(i==(el+1)){
            el = i;
            count++;
            maxC = max(maxC, count);
        }else {
            el = i;
            count = 1;
        }
    }
    return maxC;
}
//complexcity
// time = n log n
// space n

// better
int betterLongestConsecutive(vector<int> &nums){
    sort(nums.begin(), nums.end());
    int el = INT_MIN;
    int Max = 0;
    int count = 1;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]-1==el){
            el = el+1;
            count++;
        }else if(nums[i]!=el){
            el = nums[i];
            count = 1;
        }
        Max = max(Max, count);
    }
    return Max;
}
// complexcity
// time = n log n

// optimal
int optimalLongestConsecutive(vector<int> &nums){
    unordered_set<int> st;
    if(nums.empty()) return 0;
    for(auto it:nums){
        st.insert(it);
    }

    int el = INT_MIN;
    int Max = 0;
    int count = 1;

    for(auto it:st){
        if(st.find(it-1)==st.end()){
            el = it;
            count = 1;
            while(st.find(el+1)!=st.end()){
                el = el+1;
                count+=1;
            }
            Max = max(Max, count);
        }
    }
    return Max;
}
// complexcity
// time O(n);
// space O(n);

int main(){
    vector<int> nums={100, 4, 200, 1, 3, 2};
    // cout<<longestConsecutive(nums)<<endl;
    // cout<<betterLongestConsecutive(nums)<<endl;
    cout<<optimalLongestConsecutive(nums)<<endl;
    return 0;
}