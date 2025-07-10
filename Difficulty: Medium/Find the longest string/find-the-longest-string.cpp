struct TrieNode {
    bool isEndOfWord;
    TrieNode* children[26];
    
    TrieNode() {
        isEndOfWord = false;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};
class Trie{
  private:
    TrieNode* root;
  public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string& word){
        TrieNode* crawl = root;
        
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            
            if(crawl -> children[idx] == NULL){
                crawl -> children[idx] = new TrieNode();
            }
            crawl = crawl -> children[idx];
        }
        crawl->isEndOfWord = true;
    }
    
    bool search(string& word){
        TrieNode* crawl = root;
        
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            
            if(crawl -> children[idx] == NULL || crawl->children[idx]->isEndOfWord == false){
                return false;
            }
            crawl = crawl -> children[idx];
        }
        return crawl->isEndOfWord;
    }
};

class Solution {
  public:
    string longestString(vector<string> &arr) {
        int n = arr.size();
        Trie trie;
        
        for(auto& a : arr){
            trie.insert(a);
        }
        
        string result = "";
        
        for(auto& a : arr){
            if(trie.search(a)){
                if(a.size() > result.size() || (a.size() == result.size() && a < result) ) {
                    result = a;
                }
            }
        }
            
        return result;
    }
};