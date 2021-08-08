class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& A, int k) {
        int N = A.size();
        vector<int> ans = A;
        vector<int> prefix(N,0), suffix(N,0);
        prefix[0] = A[0];
        for(int i = 1; i < N; i++){
            prefix[i] += prefix[i-1];
        }

        suffix[N-1] = A[N-1];
        for(int i = N-1; i >= 0; i--){
            suffix[i] += suffix[i+1];
        }


        int n = N-1;
        while(n != k){
            stack<int> s;
            vector<vector<int>> diff(2,vector<int> (N,1e6+1));
            for(int i = 0; i < N; i++){
                while(!s.empty() && A[s.top()] < A[i]){
                    diff[s.top()][0] = (i-s.top()+1)*A[i] - prefix[i] + prefix[s.top()-1];
                    diff[s.top()][1] = i;
                    s.pop();
                }

                s.push(i);
            }

            s.clear();
            for(int i = N-1; i >= 0; i--){
                while(!s.empty() && A[s.top()] < A[i]){
                    if(diff[s.top()][0] > -i+s.top()+1*A[i] - suffix[i] + suffix[s.top()-1])
                        diff[s.top()][0] =  -i+s.top()+1*A[i] - suffix[i] + suffix[s.top()-1], diff[s.top()][1] = i;
                    s.pop();
                }

                s.push(i);
            }


            int pos = 0;
            int curr =1e9+1;
            for(int i = 0; i < N; i++){
                if(curr > diff[i][0]){
                    curr = diff[i][0];
                    pos = i;
                }
            }


            if(pos < diff[pos][1]){
                for(int j = pos; j <= diff[pos][1]; j++){
                    ans[j] += diff[pos][0];
                }
            }

            else{
                for(int j = pos; j >= diff[pos][1]; j--){
                    ans[j] += diff[pos][0];
                }            
            }

            n--;
        }

        int res = 0;

        for(int i = 0; i < N; i++){
            res += ans[i]-A[i];
        }

        return res;
    }
};