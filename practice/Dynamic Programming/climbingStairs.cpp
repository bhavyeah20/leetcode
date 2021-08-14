class Solution {
public:
    int climbStairs(int n) {
       int f1 = 2, f2 = 1;
        if(n == 1)
            return f2;
        for(int i = 3; i <= n; i++){
            int f = f1 + f2;
            f2 = f1;
            f1 = f;
        }
        return f1;
    }
};