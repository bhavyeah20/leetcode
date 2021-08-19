/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     ll val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(ll x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(ll x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#define ll long long
class Solution {
public:
    ll mod = 1e9 + 7;
    ll sum = 0;
    unordered_map<TreeNode*, ll> mp;

    int totalSum(TreeNode *root){
        if(!root)
            return 0;
        int curr = 0;
        curr += root->val;
        curr += totalSum(root->left);
        curr += totalSum(root->right);
        
        return mp[root] = curr;
    }

    ll split(TreeNode *root){
        if(!root)
            return 0;

        ll maxProduct = 0;
        maxProduct = max({maxProduct, split(root->left), split(root->right)});
        maxProduct = max({maxProduct, mp[root->left] * (sum - mp[root->left]), mp[root->right] * (sum - mp[root->right]) });

        return maxProduct;
    }
    int maxProduct(TreeNode* root) {
        mp.clear();
        int sumOfAllNodes = totalSum(root);
        sum = mp[root];
        return split(root) % mod;

    }
};