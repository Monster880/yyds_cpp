class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    ~Trie(){
        for(int i=0; i < 26; i++){
            if(next[i] != nullptr) delete next[i];
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for(auto ch : word){
            if(node->next[ch - 'a'] == nullptr){
                node->next[ch - 'a'] = new Trie;
            }
            node = node->next[ch - 'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for(auto ch : word){
            if(node->next[ch - 'a'] != nullptr){
                node = node->next[ch - 'a'];
            }else{
                return false;
            }
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for(auto ch : prefix){
            if(node->next[ch - 'a'] != nullptr){
                node = node->next[ch - 'a'];
            }else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */