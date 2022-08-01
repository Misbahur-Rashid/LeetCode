class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;n--;
        
        if(n<m){
            swap(n,m);
        }
        double ans=1.0;
        for(int i=1;i<=n;i++){
            ans=(ans*(m+i)/i);
        }
        return ans;
    }
};