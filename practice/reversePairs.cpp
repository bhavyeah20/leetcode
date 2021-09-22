// Count inversions
// Multiset O(n^2) [distance is O(N)]
// Balanced BST O(NlogN)
// Mergesort O(NlogN)

class Solution {
public:
    
    void merge(vector<int> &left, vector<int> &right, vector<int> &nums){
        int i = 0, j = 0, k = 0;
        while(i < left.size() || j < right.size()){
            
            if(i == left.size()){
                nums[k] = right[j];
                j++;
            }
            
            else if(j == right.size()){
                nums[k] = left[i];
                i++;
            }
            
            else if(left[i] < right[j]){
                nums[k] = left[i];
                i++;
            }
            
            else{
                nums[k] = right[j];
                j++;
            }
            
            k++;
        }
    }
    
    int solve(vector<int> &nums){
        
        
        int n = nums.size();
        if(!n || n == 1)
            return 0;
        int mid = (n-1)/2;
        int cnt = 0;
        vector<int> left, right;

        for(int i = 0; i <= mid; i++){
            left.push_back(nums[i]);
            if(mid+1+i < n)
                right.push_back(nums[mid+i+1]);
        }

        cnt += solve(left);
        cnt += solve(right);

        int i = 0, j = 0;
        while(i < left.size()){
            while(j < right.size() && 1LL*2*right[j] < 1LL * left[i]){
                j++;
            }

            cnt += j;
            i++;
        }
        merge(left,right,nums);
        return cnt ;
    }
    int reversePairs(vector<int>& nums) {
        return solve(nums);
    }
};