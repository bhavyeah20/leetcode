class Solution {
public:
    
     long long poww( long long a,  long long b, long long mod){
        a %= mod;
    long long res = 1;
        while(b){
            if(b&1){
                res = 1LL * ((res % mod) * (a % mod)) % mod;
                res %= mod;
            }

            a = ((a % mod) * (a % mod)) % mod;
            a%= mod;
            b >>= 1;
        }
        
        return res % mod;
    }
    int minNonZeroProduct(int p) {
         long long ans = 1;
         long long mod = 1000000007;
        
         long long highest = (1LL << p) - 1;
         long long times = (highest-1)/2;
        
        ans = poww(highest-1, times,mod);
        ans %= mod;
        ans =  ((ans % mod) * (highest % mod)) % mod;
        cout<<ans;
        return ans % mod;
        
    }
};

