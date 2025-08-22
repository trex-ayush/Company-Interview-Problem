class Solution {
  public:
     int median(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        int count;
        int l=INT_MAX;
        int h=INT_MIN;
        for(int i=0;i<n;i++)
        {
            l=min(l,mat[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            h=max(h,mat[i][m-1]);
        }
        int ans=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            count=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(mat[i][j]<=mid)
                    {
                        count++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if(n*m-count<=count)
            {
                ans=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
