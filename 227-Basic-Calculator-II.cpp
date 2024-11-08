class Solution {
public:
    int calculate(string s) {
        char op = '+';
        int prev = 0;
        int i=0;
        int curr = 0;
        int res = 0;
        while(i<s.length()){
            if(isdigit(s[i])){
                while(i<s.length() && isdigit(s[i])){
                    curr= (curr*10)+(s[i]-'0');
                    i++;
                }
                i--;
                if(op=='+'){
                    res += curr; // 5
                    prev = curr; //2
                }else if(op == '-'){
                    res-= curr;
                    prev = -curr;
                }else if(op == '*'){
                    res -= prev; //3
                    res+= prev*curr; //7
                    prev = prev*curr; 
                }else if(op == '/'){
                     res -= prev;
                    res += (int)prev/curr;
                    prev = (int)prev/curr;
                }
                curr =0;
            }else if(s[i] != ' '){
                op = s[i];
            }
            i++;
        }
        return res;
    }
};
/*
\3+2*2\

5 
*/