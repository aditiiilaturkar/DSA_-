class Solution {
public:
    int calculate(string s) {
        int res=0, curr =0;
        int sign = 1;
        int i=0;
        stack<int>st;

        while(i<s.length()){
            if(isdigit(s[i])){
                curr = curr*10 + (s[i] - '0');
            }else if(s[i] == '('){
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }else if(s[i] == ')'){
                res+= curr*sign;
                res*= st.top();
                st.pop();
                res+= st.top();
                st.pop();
                curr=0;
            }else if(s[i] == '+' || s[i] == '-'){
                res += (curr*sign);
                sign = (s[i] == '+') ? 1 : -1;
                curr = 0;
            }
            i++;
        }
        return res + curr*sign;
    }
};