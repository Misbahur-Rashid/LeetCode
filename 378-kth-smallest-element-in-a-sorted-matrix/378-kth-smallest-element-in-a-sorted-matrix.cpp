class Solution {
public:
        
    int find_smaller(vector<vector<int>>& matrix, int mid)
    {
        int n = matrix.size();
        
        int count = 0;        
        for(int i = 0; i < n; i++)
        {

            int idx = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

            count += idx;
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
                
        int low = matrix[0][0];
        
        int high = matrix[n - 1][n - 1];
        
        int ans = -1;
        
        while(low <= high)
        {            
            int mid = low + (high - low) / 2;
                        
            int pos = find_smaller(matrix, mid);
            
            if(pos >= k)
            {
                ans = mid;
                
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};