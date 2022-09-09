class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& pts) {
        sort(pts.begin(), pts.end(),  [](auto &a, auto &b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int res = 0;
        int mn = INT_MIN;
        for(int i = pts.size() - 1; i>=0;i--){
            if(pts[i][1] < mn){
                res++;
            }
            mn = max(pts[i][1], mn);
        }
        return res;
    }
};