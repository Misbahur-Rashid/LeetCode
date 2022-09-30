// class Solution {
// public:
//     vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
//         vector<vector<int>> ans;
//         priority_queue<pair<int, int>> max_heap; // <高度, 右端>
//         int i = 0, len = buildings.size();
//         int cur_x, cur_h;
//         while (i < len || !max_heap.empty()) {
//             if (max_heap.empty() || i < len && buildings[i][0] <= max_heap.top().second) {
//                 cur_x = buildings[i][0];
//                 while (i < len && cur_x == buildings[i][0]) {
//                     max_heap.emplace(buildings[i][2], buildings[i][1]);
//                     ++i;
//                 }
//             } else {
//                 cur_x = max_heap.top().second;
//                 while (!max_heap.empty() && cur_x >= max_heap.top().second) {
//                     max_heap.pop();
//                 }
//             }
//             cur_h = (max_heap.empty()) ? 0 : max_heap.top().first;
//             if (ans.empty() || cur_h != ans.back()[1]) {
//                 ans.push_back({cur_x, cur_h});
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    // entering and leaving point with the same x, process the entering point first -> set height of entering point to a negative value, and set height of leaving point to a positive value
    // entering point with same x, process the highest point first -> set height of entering point to a negative value
    // leaving point with same x, process the lowest point first -> set height of leaving point to a positive value
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int, int>> points;
        for (auto & b : buildings) {
            points.emplace_back(b[0], -b[2]);
            points.emplace_back(b[1], b[2]);
        }
        sort(points.begin(), points.end());
        multiset<int> m{0};
        int pre = 0, cur = 0;
        for (auto & p : points) {
            if (p.second < 0) {
                m.insert(-p.second);
            } else {
                m.erase(m.find(p.second));
            }
            cur = *m.rbegin();
            if (cur != pre) {
                res.push_back({p.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};