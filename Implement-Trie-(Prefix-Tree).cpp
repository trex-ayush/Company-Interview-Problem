struct TrieNode{
    bool isEndOfWord;
    TrieNode* children[26];

    TrieNode(){
        isEndOfWord = false;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* crawl = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';

            if(crawl -> children[idx] == NULL){
                crawl->children[idx] = new TrieNode();
            }
            crawl = crawl->children[idx];
        }
        crawl -> isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* crawl = root;

        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';

            if(crawl -> children[idx] == NULL){
                return false;
            }
            crawl = crawl->children[idx];
        }

        return crawl->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawl = root;

        for(int i = 0; i < prefix.size(); i++){
            int idx = prefix[i] - 'a';

            if(crawl -> children[idx] == NULL){
                return false;
            }
            crawl = crawl->children[idx];
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