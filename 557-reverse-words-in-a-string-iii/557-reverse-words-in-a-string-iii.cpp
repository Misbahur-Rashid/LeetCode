// class Solution {
// public:
//     string reverseWords(string s) {
//         vector<string> v;
//         string ans="";
//         string temp="";
        
//         for(int i =0;i<=s.length();i++){
//             if(s[i]!=' '&& s[i]!='\0')temp+=s[i];
//             else{
                
//                 reverse(temp.begin(), temp.end());
//                 // cout<<temp<<" ";
//                 v.push_back(temp);
//                 temp ="";
//             }
            
//         }
//         for(int i=0;i<v.size();i++){
//             ans+=v[i];
//             if(i!=v.size()-1)ans+=" ";
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     string reverseWords(string s) {

//         vector<string> words;
//         int start = 0;
//         for(int i = start + 1; i <= s.size(); )
//             if(i == s.size() || s[i] == ' '){
//                 words.push_back(s.substr(start, i - start));
//                 reverse(words.back().begin(), words.back().end());
//                 start = i + 1;
//                 i = start + 1;
//             }
//             else
//                 i ++;

//         if(words.size() == 0)
//             return "";

//         string res = words[0];
//         for(int i = 1;  i < words.size() ; i ++)
//             res += " " + words[i];

//         return res;
//     }
// };



class Solution {
public:
    string reverseWords(string s) {

        int start = 0;
        for(int i = start + 1; i <= s.size(); )
            if(i == s.size() || s[i] == ' '){
                reverse(s, start, i - 1);
                start = i + 1;
                i = start + 1;
            }
            else
                i ++;
        return s;
    }

private:
    void reverse(string& s, int start, int end){
        for(int i = start, j = end; i < j; i ++, j --)
            swap(s[i], s[j]);
    }
};

