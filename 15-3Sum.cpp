class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>s;
        int i=0, j, k;
        while(i<nums.size()-2){
            j=i+1;
            k=nums.size()-1;
            if(nums[i]> 0) break;
            while(j<k && j<=nums.size()-2 && k>=2){
                int curr = nums[i]+nums[j];
                int sum = curr+nums[k];
                if(sum == 0){
                    vector<int>v = {nums[i], nums[j], nums[k]};
                    sort(v.begin(), v.end());
                    s.insert(v);
                    j++;
                }else if(sum > 0){
                    k--;
                }else{
                    j++;
                }
            }
            while((nums[i] == nums[++i]) && i<nums.size()-2);  
            // i++;
        }

        vector<vector<int>>v(s.begin(), s.end());
        return v;
    }
};