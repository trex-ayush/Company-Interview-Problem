class Solution {
    int curr = -1;
    vector<char>doc;
    
  public:
    void append(char x) {
        while(curr < (int)doc.size()-1){
            doc.pop_back();
        }
        
        doc.push_back(x);
        curr++;
        
    }

    void undo() {
        if(curr >= 0){
            curr--;
        }
    }

    void redo() {
        if(curr < (int)doc.size()-1){
            curr++;
        }
    }

    string read() {
        string res = "";
        for(int i=0;i<=curr;i++){
            res += doc[i];
        }
        return res;
    }
};

