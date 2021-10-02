#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl "\n" 

int main(){
    
    int t;
    cin >> t;
    while(t--){

    int n, k;
    cin >> n >> k;

    vector<int> wt(n), taste(n);

    for(int i = 0; i < n; i++){
        cin >> wt[i];
    }

    for(int i = 0; i < n; i++){
        cin >> taste[i];
    }

    vector<int> maxWt;
    deque<int> dq;

    for(int i = 0; i < n; i++){
        while(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }

        while(!dq.empty() && wt[dq.back()] < wt[i]){
            dq.pop_back();
        }

        dq.push_back(i);

        if(i >= k-1){
            maxWt.push_back(dq.front());
        }
    }

    vector<int> suffix;
    int j = n-1;
    for(int i = n-1; i > n-k; i--){
        if(wt[i] > wt[j]){
            j = i;
        }
        suffix.push_back(j);
    }

    for(int i = suffix.size()-1; i >= 0; i--){
        maxWt.push_back(suffix[i]);
    }

    vector<int> dp(n,0);
    int ans = 0;

    for(int i = n-1; i >= 0; i--){
        int window = 0;
        if(i+1 < n)
            window = dp[maxWt[i+1]];

        dp[i] = max(dp[i], taste[i] + window);

        // cout<<dp[i]<<" ";
        ans = max(ans,dp[i]);
    }

    cout<<ans<<endl;
    }

} 