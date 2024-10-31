class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int>v(deck.size(), 0);
        sort(deck.begin(), deck.end());
        
        queue<int>pq;
        for(int i=0; i<deck.size(); i++){
            pq.push(i);
        }
        // pq = >   2 3 4 5 6 1
        //v=> 2 
        int i=0, j=0;
        while(!pq.empty() && i < deck.size()){
            int idx = pq.front();
            v[idx] = deck[i];
            pq.pop();
            if(pq.empty()) break;
            int ele = pq.front();
            pq.pop();
            pq.push(ele);
            i++;
        }
        return v;
    }
};