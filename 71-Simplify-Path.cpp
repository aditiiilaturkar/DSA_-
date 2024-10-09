class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string>v;
        string segment;
        while(getline(ss, segment, '/')){
            if(segment == \\ || segment == \.\) continue;
            else if(segment == \..\ && v.size()) {
                v.pop_back();
            }else if(segment != \..\){
                v.push_back(segment);
            }
        }

        if(!v.size()) return \/\;
        string ans = \\;
        for(int i=0;i<v.size(); i++){
            ans+= \/\+v[i];
        }
        return ans;
    }
};