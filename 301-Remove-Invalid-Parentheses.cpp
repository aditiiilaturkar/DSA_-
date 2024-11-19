class Solution {
    bool isValid(string s){
        int c = 0, i=0;
        while(i<s.length()){
            if(s[i] =='(') c++;
            if(s[i]==')') c--;
            if(c<0) return false;
            i++;
        }
        return c==0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string>visited;
        queue<string>pq;
        vector<string>res;
        int i=0;
        if(s == \\) {
            res.push_back(\\);
            return res;
        }
        pq.push(s);
        visited.insert(s);
        bool found = false;

        while(!pq.empty()){
            int size = pq.size();
            //level refers to all the strings with the same number of parentheses removed:
            while(size>0){
                string curr = pq.front();
                if(isValid(curr)){
                    found = true;
                    res.push_back(curr);
                }
                if(found) {

                }else{
                    for(int i=0; i<curr.length(); i++){
                        if(s[i] != '(' && s[i]!= ')') continue;
                        string left = curr.substr(0, i);
                        string right = curr.substr(i+1, curr.length()-1);
                        if(visited.find(left+right) == visited.end()){
                            visited.insert(left+right);
                            pq.push(left+right);
                        }
                    }
                
                }
                pq.pop();
                size--;
            }    
            if(found) break;
        }
        return res;
    }
};