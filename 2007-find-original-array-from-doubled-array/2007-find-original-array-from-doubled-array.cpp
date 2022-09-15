// class Solution {
// public:
//   vector<int> findOriginalArray(vector<int>& changed) {
//     if (changed.size() & 1) return {};
//     const int n = changed.size() / 2;
//     const int kMax = *max_element(begin(changed), end(changed));
//     vector<int> m(kMax + 1);
//     for (int x : changed) ++m[x];
//     if (m[0] & 1) return {};
//     vector<int> ans(m[0] / 2, 0);
//     for (int x = 1; ans.size() != n; ++x) {
//       if (x * 2 > kMax || m[x * 2] < m[x]) return {};      
//       ans.insert(end(ans), m[x], x);
//       m[x * 2] -= m[x];   
//     }
//     return ans;
//   }
// };

// class Solution {
// public:
//     vector<int> findOriginalArray(vector<int>& changed) {
//         if(changed.size() % 2 == 1) return {}; 
//         vector<int> rets;   // odds firstly
//         multiset<int> mset{changed.begin(), changed.end()};
//         while(!mset.empty()) {
//             int cur = *mset.begin();
//             mset.erase(mset.begin());
//             auto it = mset.lower_bound(2 * cur);
//             if(it == mset.end() || *it != 2 * cur) return {};
//             rets.push_back(cur);
//             mset.erase(it);
//         }
        
//         return rets;
//     }
// };


// class Solution {
// public:
//     vector<int> findOriginalArray(vector<int>& changed) {
//         if(changed.size() % 2 == 1) return {}; 
//         vector<int> rets;   // odds firstly
//         multiset<int> evens;
//         for(int x: changed) {
//             if(x % 2 == 0) evens.insert(x);
//             else rets.push_back(x);
//         }
//         int m = rets.size();
//         for(int i = 0; i < m; ++i) {
//             int cur = rets[i];
//             auto it = evens.lower_bound(2 * cur);
//             if(it == evens.end() || *it != 2 * cur) return {};
//             evens.erase(it);
//         }
//         while(!evens.empty()) {
//             int cur = *evens.begin();
//             evens.erase(evens.begin());
//             auto it = evens.lower_bound(2 * cur);
//             if(it == evens.end() || *it != 2 * cur) return {};
//             rets.push_back(cur);
//             evens.erase(it);
//         }
//         return rets;
//     }
// };


class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int, int> doubled;
        vector<int> res;
        sort(changed.rbegin(), changed.rend());
        for (int c : changed) {
            if (doubled[c * 2] > 0) {
                res.push_back(c);
                doubled[c * 2]--;
            } else {                
                doubled[c] ++;
            }
        }
        int sz = changed.size();
        if (sz % 2 == 1) {
            sz++;
        }
        return res.size() == (sz / 2) ? res : vector<int>();
    }
};
