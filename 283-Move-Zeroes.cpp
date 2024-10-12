class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i =0, zeroPos = 0;
        while( i< nums.size() && zeroPos<nums.size()){
            if(nums[i]!=0 && nums[zeroPos]==0){
                if(i>zeroPos)
                  swap(nums[i], nums[zeroPos]);
                i++;
            }
            while(i<nums.size() && nums[i]==0) i++;
            while(zeroPos<nums.size() && nums[zeroPos]!=0) zeroPos++;

        }    
    }
};
/*
 132000
*/