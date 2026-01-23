class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        int n=arr.size();
        vector<int> nge(n,n),pge(n,-1);
        
        stack<int> st;
        int i=n-1;
        
        while(i>=0){
            while(st.size() and arr[st.top()]<arr[i]) st.pop();
            if(st.size()) nge[i]=st.top();
            st.push(i--);
        }
        
        while(st.size()) st.pop();
        i=0;
        
        while(i<n){
            while(st.size() and arr[st.top()]<arr[i]) st.pop();
            if(st.size()) pge[i]=st.top();
            st.push(i++);
        }
        
        int ans=1;
        for(int i=0;i<n;i++){
            int l=i-1-pge[i],r=nge[i]-i-1;
            ans=max(ans,l+r+1);
        }
        
        return ans;
    }
};