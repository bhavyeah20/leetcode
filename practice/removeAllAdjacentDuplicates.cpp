class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        for(auto x: s){
            if(!st.empty() && st.top() == x){
                st.pop();
            }
                
            else
            st.push(x);
        }
        s = "";
        while(!st.empty()){
            char x = st.top();
            st.pop();
            s.push_back(x);
        }
        reverse(s.begin(), s.end());
        return s;
    }
};