class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int lMax =0, rMax= 0, ans =0;
        while(left < right) {
            lMax = max(lMax, height[left]);
            rMax = max(rMax, height[right]);

            if(lMax <= rMax){
                ans+= lMax-height[left];
                left++;
            }else{
                ans+= rMax-height[right];
                right--;
            }
        }
        return ans;
    }
};