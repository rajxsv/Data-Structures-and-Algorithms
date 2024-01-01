/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* f(TreeNode* root,TreeNode* a,TreeNode* b){
        if(!root)return NULL;

        if(root == a || root == b){
            return root;
        }

        TreeNode* left = f(root->left,a,b);
        TreeNode* right = f(root->right,a,b);

        if(left && right){
            //you find both nodes one in left and one in right
            // we return this as lca
            return root;
        }
        //it could be it was found only in left
        if(left){
            //we return it this is case of lca in same line 
            return left;
        }
        // covers all cases that are left
        //    1.Both are NULL
        //    2.Left is NULL but not right  
        return right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};