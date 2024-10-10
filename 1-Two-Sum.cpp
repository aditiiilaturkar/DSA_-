class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        for(int i=0;i<nums.size(); i++){
         
            int rem = target-nums[i];
            
            if(mp.find(rem) != mp.end() && mp[rem]!=i){
                return {mp[rem], i};
            }
               mp[nums[i]] = i;
        }
        return {};
    }
};
/*
[3,3]
3 => 0
*/