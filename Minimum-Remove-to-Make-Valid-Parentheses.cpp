// Company tags: Tencent, Netflix, Snap, Facebook, Amazon, Bloomberg, Google, tiktok, Adobe
class Solution {
public:
    // Approach 2   
    // Time Complexity:  O(n+n+n) = O(n)
    // Space Complexity: O(1)
    string minRemoveToMakeValid(string s) {
        int n =s.size();
        string temp = "";
        int parentheses = 0;

        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(ch == '('){
                parentheses++;
                temp += ch;
            }else if(ch == ')'){
                if(parentheses > 0) {
                    parentheses--;
                    temp += ch;
                }
            }else temp += ch;
        }

        string result = "";
        parentheses = 0;
        for(int i = temp.size() - 1; i >= 0; i--){
            char ch = temp[i];
            if(ch == ')'){
                parentheses++;
                result += ch;
            }else if(ch == '('){
                if(parentheses > 0) {
                    parentheses--;
                    result += ch;
                }
            }else result += ch;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    /* -------------------------------------------------------------- */
    // Approach 1 using Stack and set
    // Time Complexity:  O(n+n+n) = O(n)
    // Space Complexity: O(n) 
    // string minRemoveToMakeValid(string s) {
    //     int n =s.size();
    //     stack<int> st; // index
    //     unordered_set<int> set;

    //     for(int i = 0; i < n; i++){
    //         char ch = s[i];
    //         if(ch == '('){
    //             st.push(i);
    //         }else if(ch == ')'){
    //             if(!st.empty() && s[st.top()] == '(') st.pop();
    //             else st.push(i);
    //         }
    //     }

    //     while(!st.empty()){
    //         set.insert(st.top());
    //         st.pop();
    //     }

    //     string result = "";

    //     for(int i = 0; i < n; i++){
    //         if(set.find(i) != set.end()){
    //             set.erase(i);
    //             continue;
    //         }else result += s[i];
    //     }

    //     return result;
    // }
};
