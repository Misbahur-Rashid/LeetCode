class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int len = equations.size(), label = 0;
        map<char, int> M;
        for (string s : equations) {
            if (s[1] == '!') continue;
            if (M.find(s[0]) != M.end() and M.find(s[3]) == M.end()) M[s[3]] = M[s[0]];
            else if (M.find(s[3]) != M.end() and M.find(s[0]) == M.end()) M[s[0]] = M[s[3]];
            else if (M.find(s[3]) != M.end() and M.find(s[0]) != M.end()) {
                map<char, int>::iterator iter;
                int tmp = M[s[3]];
                iter = M.begin();
                
                while(iter != M.end()) {
                    if(iter->second == tmp) M[iter->first] = M[s[0]];
                    iter++;
                }
            } else {
                M[s[0]] = M[s[3]] = label;
                label++;
            }
        }
        
        for (string s : equations) {
            if (s[1] == '=') continue;
            //cout<<M[s[0]]<<M[s[3]]<<endl;
            if (s[0] == s[3] or M.find(s[0]) != M.end() and M.find(s[3]) != M.end() and M[s[0]] == M[s[3]]) return false;
        }
        return true;
    }
};