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
        queue<string>pq;
        pq.push(s);
        while(!pq.empty()){
            int size = pq.size();
            while(size>0){
                string curr = pq.front();
                if(mp.find(curr) != mp.end()){
                    pq.pop();
                    break;
                }
                mp[curr]++;
                if(curr.length() == s.length() - totalRem  && validStr(curr)){
                    ans.insert(curr);
                }
                for(int i=0; i<curr.length(); i++){
                    string left = curr.substr(0, i);
                    string right = curr.substr(i+1, curr.length());
                    pq.push(left+right);
                }
                size--;
                pq.pop();
            }
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