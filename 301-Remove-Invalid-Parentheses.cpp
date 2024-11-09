class Solution {
public:
    unordered_map<string, int>mp;
    bool validStr(string s){
        stack<char>st;
        int i=0;
        while(i<s.length()){
            if(s[i] == '('){
                st.push(s[i]);
            }else if(s[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                     st.push(s[i]);
                }
            }
            i++;
        }
        return st.empty();
    }
    void solve(string s, int totalRem, set<string>& ans){
        if(totalRem<0) return;
        if(mp.find(s)!=mp.end()) return;
        mp[s]++;
        if(totalRem == 0){
            if(validStr(s))
                ans.insert(s);
            return;
        }
        for(int i=0;i<s.length(); i++){
            string left = s.substr(0, i);
            string right = s.substr(i+1, s.length());
            solve(left+right, totalRem-1, ans);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        stack<char>st;
        int i=0;

        while(i<s.length()){
            if(s[i] == '('){
                st.push(s[i]);
            }else if(s[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                     st.push(s[i]);
                }
            }
            i++;
        }
        int totalRem = st.size();
        set<string> ans;
        solve(s, totalRem, ans);
        vector<string>res(ans.begin(), ans.end());
        return res;
    }
};