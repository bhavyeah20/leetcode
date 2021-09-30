class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
     
        int s = 0, e = a.size()-1;
            
        while(s < e){
            int mid = (s+e)/2;
            
            if(mid-1 >= 0 && a[mid-1] == a[mid]){
                if(mid&1){
                    s = mid+1;
                }
                
                else
                    e = mid-1;
            }
            
            else if(mid+1<a.size() && a[mid+1] == a[mid]){
                if(mid&1){
                    e = mid-1;
                }
                
                else
                    s = mid+1;
            }
            
            else
                return a[mid];
        }
        
        return a[s];
        
    }
};