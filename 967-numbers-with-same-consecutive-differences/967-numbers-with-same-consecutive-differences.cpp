class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        std::queue<int> que;
        for(int startnum = 1; startnum < 10; startnum++) que.push(startnum);
        for(int i=1; i<n; i++){
            int que_size = que.size();
            for(int i=0; i<que_size; i++){
                int curNum = que.front(); que.pop();
                int right_most_num = curNum % 10;
                if( right_most_num + k < 10 ) 
                    que.push(curNum * 10 + right_most_num + k);
                if( k != 0 && right_most_num - k >= 0 ) 
                    que.push(curNum * 10 + right_most_num - k);
            }
        }
        vector<int> res;
        while( !que.empty() ){
            res.push_back(que.front()); que.pop();
        } return res;
    }
};