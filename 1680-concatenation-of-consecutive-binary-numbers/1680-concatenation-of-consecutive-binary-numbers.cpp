// class Solution {
// public:
//     int concatenatedBinary(int n) {
//         long res=0;
//         int i,mod=1000000007;
//         for(i=1;i<=n;i++)
//         {
//             int bits=(int)(log(i)/log(2)+1);
//             res=((res<<bits)|i)%mod;
//         }
//         return (int)res;
//     }   
// };

class Solution {
public:
  int concatenatedBinary(int n) {
    constexpr int kMod = 1e9 + 7;
    long ans = 0;    
    for (int i = 1, len = 0; i <= n; ++i) {
      if ((i & (i - 1)) == 0) ++len;
      ans = ((ans << len) % kMod + i) % kMod;
    }
    return ans;
  }
};