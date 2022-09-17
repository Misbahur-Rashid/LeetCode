
// class TrieNode{
// public:
//     vector<TrieNode*> children;
//     int index;
//     string word;
    
//     TrieNode(){
//         children = vector<TrieNode*>(26);
//         word = "";
//         index = -1;
//     }
// };

// class Trie{
// public:
//     TrieNode* root;
    
//     Trie(){
//         root = new TrieNode();
//     }
    
//     void add(string& word, int index){
//         TrieNode* cur = root;
        
//         for(char c : word){
//             if(cur->children[c-'a'] == nullptr){
//                 cur->children[c-'a'] = new TrieNode();
//             }
//             cur = cur->children[c-'a'];
//         }
//         cur->word = word;
//         cur->index = index;
//     }
    
//     vector<TrieNode*> find(string& word){
//         //this function won't work for "word" which is empty
//         TrieNode* cur = root;
//         /*
//         if we want to find "sll",
//         both the trie node "s" and "sll" match
//         */
//         vector<TrieNode*> cands;
        
//         if(cur->index != -1 && cur->word != word){
//             //find for empty string
//             cands.push_back(cur);
//         }
        
//         for(int i = word.size()-1; i >= 0; --i){
//             char c = word[i];
//             if(cur->children[c-'a'] == nullptr){
//                 /*
//                 do not return {}!
//                 because we may have found a leaf node previously!
//                 */
//                 // cout << "end finding" << endl;
//                 return cands;
//             }
//             cur = cur->children[c-'a'];
            
//             // if((i == 0) && !(cur->index != -1 && cur->word != word)){
//             if(i == 0){
//                 //reach the end of "word"
//                 //put all leaves of "cur" into cands
//                 //testcase: word: "a", and it want to find "ab"
//                 stack<TrieNode*> stk;
//                 stk.push(cur);
                
//                 while(!stk.empty()){
//                     cur = stk.top(); stk.pop();
                    
//                     if(cur->index != -1 && cur->word != word){
//                         cands.push_back(cur);
//                     }
                    
//                     for(TrieNode* child : cur->children){
//                         if(child){
//                             stk.push(child);
//                         }
//                     }
//                 }
//             }else if(cur->index != -1 && cur->word != word){
//                 //cur->index != -1: current node serves as a leaf
//                 //cur->word != word: avoid finding itself!
//                 // cout << "find " << cur->word << endl;
//                 cands.push_back(cur);
//             }
//         }
        
//         return cands;
//     }
// };

// class Solution {
// public:
//     bool isPalindrome(string str){
//         int n = str.size();
        
//         for(int i = 0; i < n-1-i; ++i){
//             if(str[i] != str[n-1-i]){
//                 return false;
//             }
//         }
        
//         return true;
//     };
    
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         Trie* trie = new Trie();
//         int n = words.size();
        
//         for(int i = 0; i < n; ++i){
//             trie->add(words[i], i);
//         }
        
//         vector<vector<int>> ans;
        
//         for(int i = 0; i < n; ++i){
//             // cout << "===" << words[i] << "===" << endl;
//             if(words[i] == ""){
//                 for(int j = 0; j < n; ++j){
//                     if(j == i) continue;
//                     if(isPalindrome(words[j])){
//                         // cout << "push: " << words[j] << endl;
//                         ans.push_back({j, i});
//                     }
//                 }
//             }else{
//                 vector<TrieNode*> cands = trie->find(words[i]);
//                 if(cands.empty()) continue;

//                 for(TrieNode* cand : cands){
//                     int remainSize = words[i].size() - cand->word.size();
//                     // cout << "cand: " << cand->word << ", remainSize: " << remainSize << endl;
                    
//                     if(remainSize == 0){
//                         ans.push_back({cand->index, i});
//                     }else if(remainSize > 0){
//                         // cout << "check " << words[i].substr(0, remainSize) << " is palindrome? " << isPalindrome(words[i].substr(0, remainSize)) << endl;
//                         if(isPalindrome(words[i].substr(0, remainSize))){
//                             ans.push_back({cand->index, i});
//                         }
//                     }else{
//                         //remainSize < 0
//                         remainSize *= -1;
//                         // cout << "check " << cand->word.substr(cand->word.size()-remainSize, remainSize) << " is palindrome? " << isPalindrome(cand->word.substr(cand->word.size()-remainSize, remainSize)) << endl;
//                         if(isPalindrome(cand->word.substr(cand->word.size()-remainSize, remainSize))){
//                             ans.push_back({cand->index, i});
//                         }
//                     }
//                 }
//                 // cout << endl;
//             }
            
//         }
        
//         return ans;
//     }
// };



// class Solution {
// public:
//     bool isPalindrome(string& str) {
//         int left = 0, right = str.size() - 1;
//         while( left < right) {
//             if (str[left++] != str[right--]) return false;
//         }
//         return true;
//     }
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         unordered_map<string, int> dict;
//         for(int i=0; i<words.size(); i++){
//             string w = words[i];
//             reverse(w.begin(), w.end());
//             dict[w] = i;
//         }
        
        
//         vector<vector<int>> result;
        
//         //egde case: deal with empty string 
//         if ( dict.find("") != dict.end() ) {
//             for(int i=0; i<words.size(); i++) {
//                 if ( isPalindrome(words[i]) && dict[""] != i ) {
//                     result.push_back( { dict[""], i } );
//                 }
//             }
//         }
        
//         for(int i=0; i<words.size(); i++) {
//             for (int j=0; j<words[i].size(); j++) {
//                 //split the word to 2 parts
//                 string left = words[i].substr(0, j);
//                 string right = words[i].substr(j, words[i].size() - j);
                
//                 // if the `left` is found, which means there is a words has reversed sequence with it.
//                 // then we can check the `right` part is Palindrome or not. 
//                 if ( dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i ) {
//                     result.push_back( { i, dict[left] } );
//                 }
                
//                 if (dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i ) {
//                     result.push_back( { dict[right], i } );
//                 }
//             }

//         }
        
//         return result;
//     }
    
// };






class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wmap;
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++)
            wmap[words[i]] = i;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == "") {
                for (int j = 0; j < words.size(); j++) {
                    string& w = words[j];
                    if (isPal(w, 0, w.size()-1) && j != i) {
                        ans.push_back(vector<int> {i, j});
                        ans.push_back(vector<int> {j, i});
                    }
                }
                continue;
            }
            string bw = words[i];
            reverse(bw.begin(), bw.end());
            if (wmap.find(bw) != wmap.end()) {
                int res = wmap[bw];
                if (res != i) ans.push_back(vector<int> {i, res});
            }
            for (int j = 1; j < bw.size(); j++) {
                if (isPal(bw, 0, j-1)) {
                    string s = bw.substr(j, bw.size()-j);
                    if (wmap.find(s) != wmap.end())
                        ans.push_back(vector<int> {i, wmap[s]});
                }
                if (isPal(bw, j, bw.size()-1)) {
                    string s = bw.substr(0, j);
                    if (wmap.find(s) != wmap.end())
                        ans.push_back(vector<int> {wmap[s], i});
                }
            }
        }
        return ans;
    }

private:
    bool isPal(string& word, int i, int j) {
        while (i < j)
            if (word[i++] != word[j--]) return false;
        return true;
    }
};
