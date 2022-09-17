
class TrieNode{
public:
    vector<TrieNode*> children;
    int index;
    string word;
    
    TrieNode(){
        children = vector<TrieNode*>(26);
        word = "";
        index = -1;
    }
};

class Trie{
public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode();
    }
    
    void add(string& word, int index){
        TrieNode* cur = root;
        
        for(char c : word){
            if(cur->children[c-'a'] == nullptr){
                cur->children[c-'a'] = new TrieNode();
            }
            cur = cur->children[c-'a'];
        }
        cur->word = word;
        cur->index = index;
    }
    
    vector<TrieNode*> find(string& word){
        //this function won't work for "word" which is empty
        TrieNode* cur = root;
        /*
        if we want to find "sll",
        both the trie node "s" and "sll" match
        */
        vector<TrieNode*> cands;
        
        if(cur->index != -1 && cur->word != word){
            //find for empty string
            cands.push_back(cur);
        }
        
        for(int i = word.size()-1; i >= 0; --i){
            char c = word[i];
            if(cur->children[c-'a'] == nullptr){
                /*
                do not return {}!
                because we may have found a leaf node previously!
                */
                // cout << "end finding" << endl;
                return cands;
            }
            cur = cur->children[c-'a'];
            
            // if((i == 0) && !(cur->index != -1 && cur->word != word)){
            if(i == 0){
                //reach the end of "word"
                //put all leaves of "cur" into cands
                //testcase: word: "a", and it want to find "ab"
                stack<TrieNode*> stk;
                stk.push(cur);
                
                while(!stk.empty()){
                    cur = stk.top(); stk.pop();
                    
                    if(cur->index != -1 && cur->word != word){
                        cands.push_back(cur);
                    }
                    
                    for(TrieNode* child : cur->children){
                        if(child){
                            stk.push(child);
                        }
                    }
                }
            }else if(cur->index != -1 && cur->word != word){
                //cur->index != -1: current node serves as a leaf
                //cur->word != word: avoid finding itself!
                // cout << "find " << cur->word << endl;
                cands.push_back(cur);
            }
        }
        
        return cands;
    }
};

class Solution {
public:
    bool isPalindrome(string str){
        int n = str.size();
        
        for(int i = 0; i < n-1-i; ++i){
            if(str[i] != str[n-1-i]){
                return false;
            }
        }
        
        return true;
    };
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie* trie = new Trie();
        int n = words.size();
        
        for(int i = 0; i < n; ++i){
            trie->add(words[i], i);
        }
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; ++i){
            // cout << "===" << words[i] << "===" << endl;
            if(words[i] == ""){
                for(int j = 0; j < n; ++j){
                    if(j == i) continue;
                    if(isPalindrome(words[j])){
                        // cout << "push: " << words[j] << endl;
                        ans.push_back({j, i});
                    }
                }
            }else{
                vector<TrieNode*> cands = trie->find(words[i]);
                if(cands.empty()) continue;

                for(TrieNode* cand : cands){
                    int remainSize = words[i].size() - cand->word.size();
                    // cout << "cand: " << cand->word << ", remainSize: " << remainSize << endl;
                    
                    if(remainSize == 0){
                        ans.push_back({cand->index, i});
                    }else if(remainSize > 0){
                        // cout << "check " << words[i].substr(0, remainSize) << " is palindrome? " << isPalindrome(words[i].substr(0, remainSize)) << endl;
                        if(isPalindrome(words[i].substr(0, remainSize))){
                            ans.push_back({cand->index, i});
                        }
                    }else{
                        //remainSize < 0
                        remainSize *= -1;
                        // cout << "check " << cand->word.substr(cand->word.size()-remainSize, remainSize) << " is palindrome? " << isPalindrome(cand->word.substr(cand->word.size()-remainSize, remainSize)) << endl;
                        if(isPalindrome(cand->word.substr(cand->word.size()-remainSize, remainSize))){
                            ans.push_back({cand->index, i});
                        }
                    }
                }
                // cout << endl;
            }
            
        }
        
        return ans;
    }
};

