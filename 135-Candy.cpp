class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n;
        int i=1;
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            // pahad chad rhe hai, increaing slope
            int peak =0;
            while(i<n && ratings[i] > ratings[i-1]){
                peak++;
                candy += peak;
                i++;
            }
            // pahad utar rhe hai, decreasing slope
            int dip=0;
            while(i<n && ratings[i] < ratings[i-1]){
                dip++;
                candy += dip;
                i++;
            }

            candy -= min(dip, peak);
        }
        return candy;




        // int ans = 0;
        // vector<int>can(ratings.size(), 1);
        // for(int i=1; i<ratings.size(); i++){
        //     if(ratings[i]>ratings[i-1]) {   //check left neighbour when coming left to right
        //         can[i] = 1+can[i-1];
        //     }
        // }
        // for(int i=ratings.size()-2;i>=0; i--){
        //     if(ratings[i]>ratings[i+1] ){   //check right neighbour when coming right to left
        //         can[i]=max(can[i], can[i+1] + 1);
        //     }
        // }

        // for(int i=0;i<can.size();i++){
        //     ans+=can[i];
        // }
        // return ans;
    }

    
};


/*
    why below is wrong?
    see, here also you are moving left to right once and right to left once.
    What is diff?
    in correct approch, when u comapre curr  to left child, at any point u are sure that the candies of left child 
    are not going to change at least in this iteration.
    but here see if i check ratings[i] and ratings[i+1] and update can[i], and move ahead, when i goes to next index it is 
    a possibility that can[i] for is changing because its rating is > its right neighbour.
    thats why this is wrong.

    Always see, when we are updating based on comparision, the value with which we are comparing
    to update our curr ele value, should stay constat in that iteration

        for(int i=0; i<ratings.size()-1; i++){
            if(ratings[i]>ratings[i+1]) {
                can[i] = 1+can[i+1];
            }
        }
        for(int i=ratings.size()-1;i>0; i--){
            if(ratings[i]>ratings[i-1]){
                can[i]=max(can[i], can[i-1] + 1);
            }
        }

       
*/