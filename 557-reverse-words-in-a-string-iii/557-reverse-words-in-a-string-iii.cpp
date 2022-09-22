class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string ans="";
        string temp="";
        
        for(int i =0;i<=s.length();i++){
            if(s[i]!=' '&& s[i]!='\0')temp+=s[i];
            else{
                
                reverse(temp.begin(), temp.end());
                // cout<<temp<<" ";
                v.push_back(temp);
                temp ="";
            }
            
        }
        for(int i=0;i<v.size();i++){
            ans+=v[i];
            if(i!=v.size()-1)ans+=" ";
        }
        return ans;
    }
};