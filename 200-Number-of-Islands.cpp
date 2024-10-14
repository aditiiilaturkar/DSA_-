class Solution {
public:
    vector<pair<int,int>>dir;
    Solution(){
        dir.push_back({1, 0});
        dir.push_back({0, 1});
        dir.push_back({-1, 0});
        dir.push_back({0, -1});
    }
    bool isValid(int x, int y, int r, int c){
        if(x<0 || y< 0 || x>=r || y>=c) return false;
        return true;
    }
    void solve(vector<vector<char>>& grid, int i, int j) {
        if(i>= grid.size() || j>=grid[0].size()) return;

       

        for(int k=0; k<dir.size(); k++){
            pair<int,int>d = dir[k];
            int x = i + d.first;
            int y = j + d.second;
            if(isValid(x, y, grid.size(), grid[0].size()) && grid[x][y] == '1') {
                grid[x][y] = '0';
                solve(grid, x, y);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int i=0, j=0;
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1') {
                    cout<<\\
 calling solve for \<<i<<\ \<<j<<\ \<<grid[i][j];
                    solve(grid, i, j);
                    ans++;
                }
            }
        }   
        return ans;
    }
};