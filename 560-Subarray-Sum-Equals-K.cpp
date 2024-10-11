class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int sum =0;
        int ans = 0;
        for(int i=0; i< nums.size(); i++){
            sum += nums[i];
            if(mp.find(sum-k) != mp.end()){
                ans += mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};
/* ans = 1
1 1 1 k=2
0 => 2
1 => 1
*/

// [1,2,3] k=3 
/*
    0 -> 1
    1 -> 1
    3 => 1


*/