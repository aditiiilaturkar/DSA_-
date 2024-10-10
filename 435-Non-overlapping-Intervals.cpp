class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        if(intervals.size()==1) return 0;
        int i=0, j=i+1;
        int ans = 0;
        // [1,2],[1,2],[1,2]
        while(j<intervals.size()){
            int cs = intervals[i][0];
            int ce = intervals[i][1];
            int ns = intervals[j][0];
            int ne = intervals[j][1];
            if(ce <= ns){
               i=j;
               j++;
            }else{
                if(ce >= ne){ //rem curr
                    i=j;
                    j++;
                    ans++;
                }else{  //rem next
                    j++;
                    ans++;
                }
            }
        }
        return ans;
       
    }
};