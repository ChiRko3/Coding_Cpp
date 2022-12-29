#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[100006] = {0};
    int longestSquareStreak(vector<int>& nums) {
       int mx = 1;
       sort(nums.begin(),nums.end());
       for(int i = 0;i < nums.size();i++){
           int sq = sqrt(nums[i]);
           if((sq * sq == nums[i]) && dp[sq] != 0){
               dp[nums[i]] = 1 + dp[sq];
           }
           else{
               dp[nums[i]] = 1;
           }
           mx = max(mx,dp[nums[i]]);
       }
       return mx == 1 ? -1 : mx;
    }
};

// This is a LIS Pattern Ques,Sorting May Differ From Question to Question , But The Concept Here and Implementation Of LIS is Good.
// Dp With Hash Pattern In Linear Time