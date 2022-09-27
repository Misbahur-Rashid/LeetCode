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



class Solution {
public:
    string pushDominoes(string dominoes) {
        int N = dominoes.size();
        //record the distance to left or right force
        vector<int> left(N, INT_MAX), right(N, INT_MAX);
        
        int last = -1;
        for(int i = 0; i < N; i++){
            switch(dominoes[i]){
                case 'R':
                    last = i;
                    break;
                case '.':
                    if(last != -1) right[i] = i - last;
                    break;
                case 'L':
                    last = -1;
                    break;
            }
            // cout << right[i];
        }
        // cout << endl;
        
        last = -1;
        for(int i = N-1; i >= 0; i--){
            switch(dominoes[i]){
                case 'L':
                    last = i;
                    break;
                case '.':
                    if(last != -1) left[i] = last - i;
                    break;
                case 'R':
                    last = -1;
                    break;
            }
            // cout << left[i];
        }
        // cout << endl;
        
        for(int i = 0; i < N; i++){
            if(dominoes[i] == '.'){
                //the smaller the stronger
                if(left[i] < right[i]){
                    dominoes[i] = 'L';
                }else if(left[i] > right[i]){
                    dominoes[i] = 'R';
                }
            }
        }
        
        return dominoes;
    }
};