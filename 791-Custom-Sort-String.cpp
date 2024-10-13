class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>v(26, 0);
        for(int i=0; i<s.length(); i++){
            v[s[i]-'a']++;
        }   

        string ans = "";
        for(int i=0; i<order.length(); i++){
            while(v[order[i] - 'a'] > 0){
                v[order[i] - 'a']--;
                ans.push_back(order[i]);
            }
        }

        for(int i=0; i<26; i++){
            while(v[i]>0){
                char c = i+'a';
                ans.push_back(c);
                v[i]--;
            }
        }
        return ans;
    }
};