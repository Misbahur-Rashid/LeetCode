class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> max_heap; // <高度, 右端>
        int i = 0, len = buildings.size();
        int cur_x, cur_h;
        while (i < len || !max_heap.empty()) {
            if (max_heap.empty() || i < len && buildings[i][0] <= max_heap.top().second) {
                cur_x = buildings[i][0];
                while (i < len && cur_x == buildings[i][0]) {
                    max_heap.emplace(buildings[i][2], buildings[i][1]);
                    ++i;
                }
            } else {
                cur_x = max_heap.top().second;
                while (!max_heap.empty() && cur_x >= max_heap.top().second) {
                    max_heap.pop();
                }
            }
            cur_h = (max_heap.empty()) ? 0 : max_heap.top().first;
            if (ans.empty() || cur_h != ans.back()[1]) {
                ans.push_back({cur_x, cur_h});
            }
        }
        return ans;
    }
};