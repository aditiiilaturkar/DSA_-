class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = -1;
        int sum = 0;
      
        for(int i=0;i<nums.size(); i++){
            sum+= nums[i];

            if(mp.find(sum%k) != mp.end()) {
                if(i-mp[sum%k] >=2)
                    return true;
            }  
            else
                mp[sum%k]=i;
        }
        return false;
    }
};
// 23 25 29

/*
    if(a%b == c)
    then (a + any multiple of b) % b will be c only
    so if % repeats itself samazlo mil gya subarray with sum multiple of b

*/