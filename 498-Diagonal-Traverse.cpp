class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>>mp;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }   
    vector<int> ans;
    bool flip = true;
    for(auto itr = mp.begin(); itr!=mp.end(); itr++){
        vector<int>curr = itr->second;
        if(flip){
            reverse(curr.begin(), curr.end());
        }

        ans.insert(ans.end(), curr.begin(), curr.end());
        flip = !flip;
    }
    return ans;

    }
};

/*
  i+j
*/