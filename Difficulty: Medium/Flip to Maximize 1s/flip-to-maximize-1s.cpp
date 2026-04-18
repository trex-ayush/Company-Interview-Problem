class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        int n = arr.size();
        int c =0 , s =0;
         int n1=0;
         for(int i =0;i<n;i++){
             
              if( arr[i]==0) c++;
              else{
                  c--;
                   n1++;
                  if( c<0) c=0;
                  
              }
               s = max(s , c);
         }
          return n1+s;
    }
};