class Solution {
  public:
    int andInRange(int l, int r) {
        while(r > l) {
            r = r & (r - 1);
        }
        return r;
    }
};
