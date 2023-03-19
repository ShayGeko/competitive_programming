#include <algorithm>
struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int d = 0;
        if(root->left) d = maxDepth(root->left);
        if(root->right) d = std::max(d, maxDepth(root->right));
        
        return d + 1;
    }
};