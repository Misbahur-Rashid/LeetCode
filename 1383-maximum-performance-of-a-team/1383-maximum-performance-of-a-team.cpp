// class Solution {
// public:
//     int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
//         vector<pair<int, int>> ord;
//         for (int i = 0; i < n; i++)
//             ord.push_back({efficiency[i], speed[i]});
//         sort(ord.rbegin(), ord.rend());
//         priority_queue<int> sppq;
//         long totalSpeed = 0, best = 0;
//         for (auto& p : ord) {
//             int spd = p.second;
//             sppq.push(-spd);
//             if (sppq.size() <= k) totalSpeed += spd;
//             else {
//                 totalSpeed += spd + sppq.top();
//                 sppq.pop();
//             }
//             best = max(best, totalSpeed * p.first);
//         }
//         return best % 1000000007;
//     }
// };

// class Solution {
// public:
//   int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
//     vector<pair<int, int>> es;
//     for (int i = 0; i < n; ++i)
//       es.push_back({efficiency[i], speed[i]});
//     sort(rbegin(es), rend(es));
//     priority_queue<int, vector<int>, greater<int>> q;
//     long sum = 0;
//     long ans = 0;
//     for (int i = 0; i < n; ++i) {
//       if (i >= k) {
//         sum -= q.top();
//         q.pop();
//       }
//       sum += es[i].second;
//       q.push(es[i].second);
//       ans = max(ans, sum * es[i].first);
//     }
//     return ans % static_cast<int>(1e9 + 7);
//   }
// };


// class Solution {
// public:
//     int ans;
//     int n, k;
//     vector<int> speed, efficiency;
//     long mod = 1e9 + 7;
    
//     void backtrack(vector<int>& ids, vector<int>& combIds, int start){
//         if(combIds.size() == k){
//             long perf = 0;
//             int eff = INT_MAX;
//             int speedSum = 0;
//             for(int combId : combIds){
//                 eff = min(efficiency[combId], eff);
//                 speedSum += speed[combId];
//             }
//             perf = ((eff % mod) * (speedSum % mod)) % mod;
//             // if((int)perf > ans){
//             //     for(int i = 0; i < k; i++){
//             //         cout << combIds[i] << " ";
//             //     }
//             //     cout << endl;
//             // }
//             ans = max((int)perf, ans);
//         }else{
//             for(int i = start; i < n; i++){
//                 combIds.push_back(i);
//                 backtrack(ids, combIds, i+1);
//                 combIds.pop_back();
//             }
//         }
//     }
    
//     int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
//         ans = 0;
//         this->n = n;
//         this->speed = speed;
//         this->efficiency = efficiency;
//         //we can have 1 to k engineers!
//         //not necessary k!
//         vector<int> combIds;
        
//         vector<int> ids(n);
//         iota(ids.begin(), ids.end(), 0);
        
//         for(int i = 1; i <= k; i++){
//             this->k = i;
//             backtrack(ids, combIds, 0);
//         }
        
//         // cout << endl;
//         return ans;
//     }
// };



class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> ess;
        for (int i = 0; i < n; i++){
            ess.push_back({efficiency[i], speed[i]});
        }
        //sort by efficiency and then by speed, descending
        sort(ess.rbegin(), ess.rend());

        long sumS = 0, res = 0;
        priority_queue <int, vector<int>, greater<int> > pq;
        //itereate through efficiency
        for (int i = 0; i < n; i++) {
            //for each efficiency, find the maximum possible combination(of size <= k) of speed
            //possible speeds are the speed whose efficiency >= current efficiency
            pq.push(ess[i].second);
            //sumS: the sum of the combination of speed for current efficiency
            sumS += ess[i].second;
            // cout << "push " << ess[i].second << ", sumS: " << sumS << endl;
            if (pq.size() > k) {
                sumS -= pq.top();
                // cout << "pop " << pq.top() << ", sumS: " << sumS << endl;
                pq.pop();
            }
            // cout << "current res: " << sumS * ess[i].first << endl;
            res = max(res, sumS * ess[i].first);
        }
        return res % (int)(1e9+7);
    }
};
