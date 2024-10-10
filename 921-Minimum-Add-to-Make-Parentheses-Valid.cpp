class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1; i< s.length(); i++){
            if(s[i] ==')') {
                if(!st.empty() && st.top() == '('){
                    st.pop();
                    continue;
                }else{
                    st.push(s[i]);
                }
            }else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};