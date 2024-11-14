class Solution {
public:
    bool isSorted(string w1, string w2, unordered_map<char, int>mp){
        int i=0, j=0;
        while(i<w1.size() && j<w2.size()){
            int w1c = mp[w1[i]];
            int w2c = mp[w2[j]];
            if(w1c>w2c) return false;
            else if(w1c<w2c) return true;
            i++;
            j++;
        }
        if(i<w1.size() && j==w2.size()) return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
       unordered_map<char, int>mp;
        for(int i=0; i<order.length(); i++){
            mp[order[i]] = i;
        }

        for(int i=0; i<words.size()-1;i++){
            if(!isSorted(words[i], words[i+1], mp)){
                return false;
            }
        }
        return true;
    }
};