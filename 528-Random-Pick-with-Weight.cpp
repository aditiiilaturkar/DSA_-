class Solution {
public:
    vector<int>v;
    Solution(vector<int>& w) {
        v.resize(w.size(), 0);
        v[0] = w[0];
        for(int i=1; i<w.size(); i++){
            v[i] = v[i-1]+w[i];
        }
    }
    
    int pickIndex() {
        int n = rand()%v.back();
        // auto itr = upper_bound(v.begin(), v.end(), n);

        auto itr = lower_bound(v.begin(), v.end(), n+1); //n+1 here
        // because if n = (4%4)=0 then lower_bound will try to find
        // ele >= 0 which will always return 0th index i.e. not random

        return itr - v.begin();
    }
};

/*
v = {1, 2, 2, 3, 4, 4, 4, 5};
for val =  4
upper_bound => 7 (index) : return index of first ele > val
lower_bound => 4 (index) : return index of first ele >= val
*/

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */