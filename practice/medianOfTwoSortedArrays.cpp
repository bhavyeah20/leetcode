class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        
        if(n < m)
            return findMedianSortedArrays(nums2,nums1);
        
        int elementsNeeded = (m+n)/2;
        
        int s = 0, e = m;
        
        while(s <= e){
            int leftAbove = (s+e)/2;
            int leftBelow = elementsNeeded-leftAbove;
            
            int lA = INT_MIN,rA = INT_MAX,lB = INT_MIN,rB = INT_MAX;
            
            if(leftAbove != 0)
                lA = nums1[leftAbove-1];
            
            if(leftAbove != m)
                rA = nums1[leftAbove];
            
            
            if(leftBelow != 0)
                lB = nums2[leftBelow-1];
            
            if(leftBelow != n)
                rB = nums2[leftBelow];
            
            if(lA <= rB && lB <= rA){
                if((m+n)&1){
                    return min(rA,rB);
                }
                
                else
                    return (double)(max(lA,lB)+min(rA,rB))/2;
            }
            
            if(lA > rB){
                e = leftAbove-1;
            }
            
            else
                s = leftAbove+1;
        }
        
        return 0;
        
    }
};