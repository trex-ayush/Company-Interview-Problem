class Solution {
  public:
    bool areRotations(string &s, string &goal) {
        if(s.size() != goal.size()) return false;
        string k = s + s;
        return k.find(goal) != string::npos;
    }
};