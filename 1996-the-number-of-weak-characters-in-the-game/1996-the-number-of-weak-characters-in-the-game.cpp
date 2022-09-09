// class Solution {
// public:
//     int numberOfWeakCharacters(vector<vector<int>>& pts) {
//         sort(pts.begin(), pts.end(),  [](auto &a, auto &b){
//             if(a[0] == b[0]){
//                 return a[1] > b[1];
//             }
//             return a[0] < b[0];
//         });
//         int res = 0;
//         int mn = INT_MIN;
//         for(int i = pts.size() - 1; i>=0;i--){
//             if(pts[i][1] < mn){
//                 res++;
//             }
//             mn = max(pts[i][1], mn);
//         }
//         return res;
//     }
// };

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        map<int, vector<int>> Map;

        for(auto& p: properties) {
            Map[p[0]].push_back(p[1]);
        }

        int currentMax = 0;

        int ret = 0;
        for(auto it = Map.rbegin(); it != Map.rend(); ++it) {
            int a = it->first;
            auto& bs = it->second;

            sort(bs.begin(), bs.end());

            if(currentMax != 0) {
                auto it = upper_bound(bs.begin(), bs.end(), currentMax-1);
                ret += it - bs.begin();
            }

            // update currentMax
            currentMax = max(currentMax, *max_element(bs.begin(), bs.end()));
        }

        return ret;
    }
};

