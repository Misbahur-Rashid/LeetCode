// class Solution {
// public:
//     vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
//         int sum = 0;
//         for(int i=0; i<A.size(); i++) {
//             if (A[i] % 2 == 0) sum += A[i];
//         }
//         vector<int> result;
//         for(auto query : queries) {
//             int i = query[1];
//             int x = A[i] + query[0];
            
//             if (A[i] % 2 == 0 && x %2 == 0) {
//                 sum += ( -A[i] + x ); 
//                 A[i] = x;
//             } else if (A[i] % 2 != 0 && x %2 == 0) {
//                 sum += x;
//                 A[i] = x;
//             } else if (A[i] % 2 == 0 && x %2 != 0) {
//                 sum -= A[i];
//                 A[i] = x;
//             } else if (A[i] % 2 != 0 && x %2 != 0){ 
//                 A[i] = x;
//             }
//             result.push_back(sum);
//         }
        
//         if (result.size()<=0) result.push_back(0);
//         return result;
//     }
// };


class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int odd_sum = 0, even_sum = 0;
        for (auto &a : A) {
            if (a % 2 == 0) even_sum += a;
            else odd_sum += a;
        }
        vector<int> res;
        for (auto &q : queries) {
            int val = q[0], index = q[1];
            if (A[index] % 2 == 0) {
                if (val % 2 == 0) {
                    A[index] += val;
                    even_sum += val;
                } else {
                    even_sum -= A[index];
                    A[index] += val;
                    odd_sum += A[index];
                }
            } else {
                if (val % 2 == 0) {
                    A[index] += val;
                    odd_sum += val;
                } else {
                    odd_sum -= A[index];
                    A[index] += val;
                    even_sum += A[index];
                }
            }
            res.push_back(even_sum);
        }
        return res;
    }
};