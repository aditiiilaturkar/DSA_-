class Solution {
public:
    void getArr(vector<vector<int>>&ans,vector<int>& nums, vector<int>& output, int i){
        if(i>=nums.size()){
            ans.push_back(output);
            return; 
        }

        //include
        vector<int>temp(output.begin(), output.end());
        temp.push_back(nums[i]);
        getArr(ans,nums, temp,i+1);
        //exclude
        getArr(ans,nums, output,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;

        getArr(ans,nums, output,0);
        return ans;
    }
};

/*
The total number of subsets for a set of size n is 2^n.
 This is because each element has two choices: to be included in a subset or not.
 The recursion goes as deep as the number of elements in nums, which is n.
 Work Done at Each Level: At each level of recursion, a new subset (a vector) is created. The time complexity for copying the output vector to a temporary vector is 
O(n), as it involves copying all elements from output.


hence T.C. = O(n*2^n)
*/
