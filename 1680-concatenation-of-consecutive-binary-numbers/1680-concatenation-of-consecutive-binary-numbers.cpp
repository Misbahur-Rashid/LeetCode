class Solution {
public:
    int concatenatedBinary(int n) {
        long res=0;
        int i,mod=1000000007;
        for(i=1;i<=n;i++)
        {
            int bits=(int)(log(i)/log(2)+1);
            res=((res<<bits)|i)%mod;
        }
        return (int)res;
    }   
};