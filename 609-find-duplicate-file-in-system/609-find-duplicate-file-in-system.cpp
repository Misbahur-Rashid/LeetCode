class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> cnt;// <content, filePath>
        vector<vector<string>> res;
        for(auto path : paths) {
            istringstream ss(path);
            string str;
            ss >> str;
            string prefix = str;  // filePath without fileName
            while(ss >> str) {
                int start = str.find('(', 0);
                string filePath =  prefix + '/' + str.substr(0, start); //filePath with fileName
                string content = str.substr(start);
                if(cnt.find(content) != cnt.end()) {
                    cnt[content].push_back(filePath);
                }
                else {
                    vector<string> vec;
                    vec.push_back(filePath);
                    cnt.insert(make_pair(content, vec));
                }
            }
        }
        for(auto p : cnt) {
            if(p.second.size() > 1) {//only count contents occur more than once
                res.push_back(p.second);
            }
        }
        return res;  
    }
};