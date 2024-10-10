class Solution {
public:
    vector<pair<int, int>>dir;
    Solution(){
        dir.push_back({0,1});
        dir.push_back({0,-1});
        dir.push_back({1,0});
        dir.push_back({1,1});
        dir.push_back({-1,0});
        dir.push_back({-1,-1});
        dir.push_back({-1,1});
        dir.push_back({1,-1});
    }
    bool isValid(int i, int j, int r, int c){
        if(i<0 || j<0 || i>=r || j>=c) return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>>pq;
        int r = grid.size();
        int c = grid[0].size();
        if(grid[0][0] == 1 || grid[r-1][c-1] == 1) 
            return -1;

        pq.push({0, 0});
        grid[0][0] = 1;
        int ans = 0;
        while(!pq.empty()) {
            int N = pq.size(); 
            while(N--) {
                pair<int, int>xy = pq.front();
                int x = xy.first;
                int y = xy.second;
                pq.pop();
                if(x == r-1 && y== c-1) return ans+1;
                for(pair<int, int>d: dir){
                    if(isValid(x+d.first, y+d.second, r, c) && grid[x+d.first][y+d.second] == 0){
                        grid[x+d.first][y+d.second] = 1;
                        pq.push({x+d.first, y+d.second});
                    }
                }
                 
            }
            ans++;
        }
        
        return -1;
    }
};