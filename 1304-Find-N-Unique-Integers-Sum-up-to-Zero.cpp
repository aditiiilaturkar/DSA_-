class Solution {
public:
    typedef pair<int, char> p;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<p>pq;
        if(a) pq.push({a, 'a'});
        if(b) pq.push({b, 'b'});
        if(c) pq.push({c, 'c'});

        string ans = \\;
        while(!pq.empty()){
            int maxFreq = pq.top().first;
            char maxFreqChar = pq.top().second;
            pq.pop();
            if(ans.length()>=2 && ans[ans.size()-1] == maxFreqChar && ans[ans.size()-2] == maxFreqChar){
                //cant use this . go for next
                if(pq.empty()) break;
                int maxFreq2 = pq.top().first;
                char maxFreqChar2 = pq.top().second;
                pq.pop();
                ans+=maxFreqChar2;
                maxFreq2--;
                if(maxFreq2>0){
                    pq.push({maxFreq2, maxFreqChar2});
                }
            }else{
                ans+=maxFreqChar;
                maxFreq--;
            }
            if(maxFreq>0){
                pq.push({maxFreq, maxFreqChar});
            }

        }
        return ans;
    }
};