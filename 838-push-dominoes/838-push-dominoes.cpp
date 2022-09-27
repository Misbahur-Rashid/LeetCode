// class Solution {
// public:
//     string pushDominoes(string dominoes) {
//         int n=dominoes.size();
//         int left[n];
//         int right[n];
//         int sum[n];
//         //R command from left to right 
//         int command=0;
//         for(int i=0;i<n;i++)
//         {
//             if(dominoes[i]=='R') command=n;
//             else if(dominoes[i]=='L') command=0;
//             else if(dominoes[i]=='.')
//                 command=max(command-1,0);
            
//             right[i]=command;
//         }
//         int p=0;
//         for(int i=n-1;i>=0;i--,p++)
//         {
//              if(dominoes[i]=='L') command=n;
//             else if(dominoes[i]=='R') command=0;
//             else if(dominoes[i]=='.')
//                 command=max(command-1,0);
            
//             left[i]=command*(-1);
//         }
//         for(int i=0;i<n;i++) {
//             sum[i]=right[i]+left[i];
//                           if(sum[i]==0) dominoes[i]='.';
//             else if(sum[i]>0) dominoes[i]='R';
//             else dominoes[i]='L';
//                              }
//         return dominoes;
//     }
// };



// class Solution {
// public:
//     string pushDominoes(string dominoes) {
//         int N = dominoes.size();
//         //record the distance to left or right force
//         vector<int> left(N, INT_MAX), right(N, INT_MAX);
        
//         int last = -1;
//         for(int i = 0; i < N; i++){
//             switch(dominoes[i]){
//                 case 'R':
//                     last = i;
//                     break;
//                 case '.':
//                     if(last != -1) right[i] = i - last;
//                     break;
//                 case 'L':
//                     last = -1;
//                     break;
//             }
//             // cout << right[i];
//         }
//         // cout << endl;
        
//         last = -1;
//         for(int i = N-1; i >= 0; i--){
//             switch(dominoes[i]){
//                 case 'L':
//                     last = i;
//                     break;
//                 case '.':
//                     if(last != -1) left[i] = last - i;
//                     break;
//                 case 'R':
//                     last = -1;
//                     break;
//             }
//             // cout << left[i];
//         }
//         // cout << endl;
        
//         for(int i = 0; i < N; i++){
//             if(dominoes[i] == '.'){
//                 //the smaller the stronger
//                 if(left[i] < right[i]){
//                     dominoes[i] = 'L';
//                 }else if(left[i] > right[i]){
//                     dominoes[i] = 'R';
//                 }
//             }
//         }
        
//         return dominoes;
//     }
// };


class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L' + dominoes + 'R';
        // cout << dominoes << endl;
        string res = "";
        for (int slow = 0, fast = 1; fast < dominoes.length(); fast++) {
            if (dominoes[fast] == '.') continue;
            //we've found a interval('R......R', 'R......L', 'L......R' or 'L......R')
            int middle = fast - slow - 1;
            
            //deal with slow(left bound)
            //slow == 0 is padding
            if (slow > 0){
                res += dominoes[slow];
            }
            
            //deal with middle(between left and right bound)
            if (dominoes[slow] == dominoes[fast]){
                //'R......R' => 'RRRRRRRR'
                //'L......L' => 'LLLLLLLL'
                res += string(middle, dominoes[slow]);
            }else if (dominoes[slow] == 'L' && dominoes[fast] == 'R'){
                //'L......R' => 'L......R'
                res += string(middle, '.');
            }else{
                //'R......L' => 'RRRRLLLL' or 'RRRR.LLLL'
                res += string(middle / 2, 'R') + string(middle % 2,'.') + string(middle / 2, 'L');
            }
            
            //don't need to deal with right bound because the rightmost char is padding
            // cout << slow << " " << fast << " " << middle << " " << res << endl;
            slow = fast;
        }
        return res;
    }
};