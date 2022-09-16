// class Solution {
// public:
//     int maximumScore(vector<int>& nums, vector<int>& multipliers) {
//         int n = nums.size();
//         int m = multipliers.size();
//         vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
        
//         int score = INT_MIN;
//         for (int k = 1; k <= m; k++) {
//             for (int l = 0; l <= k; l++) {
//                 int pick_left = (l == 0 ? INT_MIN : dp[l-1][k-l] + multipliers[k-1] * nums[l-1]);
//                 int pick_right = (l == k ? INT_MIN : dp[l][k-l-1] + multipliers[k-1] * nums[n-k+l]);
//                 dp[l][k-l] = max(pick_left, pick_right);

//                 if (k == m) {
//                     score = max(score, dp[l][k-l]);
//                 }
//             }
//         }
        
//         return score;
//     }
// };


// class Solution {
// public:
//   int maximumScore(vector<int>& nums, vector<int>& multipliers) {
//     const int m = multipliers.size();
//     const int n = nums.size();
//     vector<vector<int>> cache(m, vector<int>(m, INT_MIN));
//     function<int(int, int)> dp = [&](int i, int j) {
//       const int k = n - (j - i + 1);
//       if (k == m) return 0;
//       int& ans = cache[i][k];
//       if (ans != INT_MIN) return ans;
//       return ans = max(dp(i + 1, j) + nums[i] * multipliers[k],
//                        dp(i, j - 1) + nums[j] * multipliers[k]);
//     };
//     return dp(0, n - 1);
//   }
// };



class Solution {
public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    const int m = multipliers.size();
    const int n = nums.size();
    // dp[i][j] := max score of using first i elements and last j elements
    vector<vector<int>> dp(m + 1, vector<int>(m + 1));
    for (int k = 1; k <= m; ++k)
      for (int i = 0, j = k - i; i <= k; ++i, --j)
        dp[i][j] = max((i ? dp[i - 1][j] + nums[i - 1] * multipliers[k - 1] : INT_MIN),
                       (j ? dp[i][j - 1] + nums[n - j] * multipliers[k - 1] : INT_MIN));
    int ans = INT_MIN;
    for (int i = 0; i <= m; ++i)
      ans = max(ans, dp[i][m - i]);
    return ans;
  }
};