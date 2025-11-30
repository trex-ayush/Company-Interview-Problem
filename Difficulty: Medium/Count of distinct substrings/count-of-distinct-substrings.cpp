class Node{
public:
    Node* links[26];
    
    bool containsKey(char ch){
        return links[ch - 'a'];
    }
    
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch - 'a'];
    }
};

class Solution {
public:
    int countSubs(string& s) {
        int n = s.size();
        int cnt = 0;
        Node* root = new Node();
        
        for(int i = 0; i < n; i++){
            Node* node = root;
            for(int j = i; j < n; j++){
                char ch = s[j];
                if(!node->containsKey(ch)){
                    cnt++;
                    node->put(ch, new Node());
                }
                node = node->get(ch);
            }
        }
        
        return cnt;
    }
};
