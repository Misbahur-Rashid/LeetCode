// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         auto it = lower_bound(arr.begin(), arr.end(), x);
        
//         if(it == arr.begin()){
//             return vector<int>(arr.begin(), arr.begin()+k);
//         }else if(it == arr.end()){
//             return vector<int>(arr.end() - k, arr.end());
//         }
        
//         int n = arr.size();
//         int idx = it - arr.begin();
//         int left, right;
//         left = idx - k/2;
//         right = left + k;
                
//         if(left < 0){
//             left = 0;
//             right = left +k;
//         }
        
//         if(right > n){
//             right = n;
//             left = right - k;
//         }
        
//         while(left > 0 && x - arr[left-1] <= arr[right-1] - x){
//             right--;
//             left--;
//         }
//         while(right < n && arr[(right-1)+1] - x < x - arr[left]){
//             right++;
//             left++;
//         }
                
//         return vector<int>(arr.begin()+left , arr.begin()+right);
//     }
// };


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](const int& a, const int& b){
            return (abs(a-x) == abs(b-x)) ? a < b : (abs(a-x) < abs(b-x));
        });
        
        vector<int> ans(arr.begin(), arr.begin()+k);
        //now ans is not ascending, need to sort it again
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
