class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        ans.reserve(s.length() + spaces.size());
        int i=0, j=0;
        while(j<spaces.size() && i< s.length()){
            if(i == spaces[j]){
                ans+= ' ';
                j++;
            }
            ans+= s[i];
            i++;
        }
        if(i<s.length()){
            ans+= s.substr(i, s.length()-i);
        }
        return ans;
    }
};