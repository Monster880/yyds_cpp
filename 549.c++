class Solution{
private:
    int maxval = 0;
public:
    int longestConsecutive(TreeNode* root){
        longstPath(root);
        return maxval;
    }
    pair<int, int>longstPath(TreeNode* root){
        if(root == null){
            return {0,0};
        }
        int inc = 1, dec = 1;
        if(root->left != nullptr){
            pair<int, int> l = longstPath(root->left);
            if(root->val == root->left->val + 1){
                dec = l.second + 1;
            }else if(root->val == root->left->val - 1){
                inc = l.first + 1;
            }
        }
        if(root->right != nullptr){
            pair<int, int> r = longstPath(root->right);
            if(root->val == root->right->val + 1){
                dec = max(dec, r.second + 1);
            }else if(root->val == root->right->val - 1){
                inc = max(inc, r.first + 1);
            }
        }
        maxval = max(maxval, inc + dec - 1);
        return {inc, dec};
    }
}