class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i=0, j=0;
        stringstream ss(sentence);
        string token = "";
        while(getline(ss, token, ' ')) {
            if(token.length()>=searchWord.length()){
                j=0;
                while(j<searchWord.length()){
                    if(searchWord[j]==token[j]) {
                        j++;
                    }else{
                        break;
                    }
                }
                if(j==searchWord.length()) return i+1;        
            }
               i++;
        }
        return -1;
    }
};