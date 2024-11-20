class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        vector<int>sv(26,0); 
        vector<int>diff;
        bool sfreqMoreThanOne = false;
        for(int i=0; i<s.length();i++){
            sv[s[i]-'a']++;
            if(sv[s[i]-'a'] >= 2) {
                sfreqMoreThanOne = true;
            }
            if(s[i]!=goal[i]) diff.push_back(i);
        }
        if(s==goal){
            if(sfreqMoreThanOne) return true; 
        }
        if(diff.size()!=2) return false;
        return (s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]]);
    }
};