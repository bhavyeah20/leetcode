/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<TreeNode*> getTree(int s, int e){
        vector<TreeNode*> res;
        
        if(s > e){
            TreeNode *curr = NULL;
            res.push_back(curr);
            return res;
        }
        
        
        if(s == e){
            TreeNode *curr = new TreeNode(s);
            res.push_back(curr);
            return res;
        }
        
        
        for(int i = s; i <= e; i++){
            
            
            vector<TreeNode*> left = getTree(s,i-1);
            
            vector<TreeNode*> right = getTree(i+1,e);
            
            for(int j = 0; j < left.size(); j++){
                for(int k = 0; k < right.size(); k++){
                    TreeNode *curr = new TreeNode(i);
                    curr->left = left[j];
                    curr->right = right[k];
                    res.push_back(curr);
                }
            }
        }
            
        return res;
        
    }
    
    
    vector<TreeNode*> generateTrees(int n) {
        return getTree(1,n);
    }
};