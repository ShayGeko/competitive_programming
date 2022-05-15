
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
    int deepestLeavesSum(TreeNode* root) {
        return deepestLeavesPair(root).second;
    }
    pair<int, int> deepestLeavesPair(TreeNode* v){
        if(!v->left && !v->right) return {0, v->val};
        
        pair<int, int> l = {0, 0}, r = {0, 0};
        if(v->left) l = deepestLeavesPair(v->left);
        if(v->right) r = deepestLeavesPair(v->right);
        
        if(l.first > r.first) return {l.first + 1, l.second};
        else if(l.first == r.first) return {l.first + 1, l.second + r.second};
        else return {r.first + 1, r.second};
    }
};