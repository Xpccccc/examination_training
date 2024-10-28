/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // 调用递归函数，设置初始的范围为无穷小和无穷大
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

private:
    bool isValidBST(TreeNode* node, long min, long max) {
        if (node == nullptr) return true; // 空节点是有效的

        // 检查当前节点的值是否在合法范围内
        if (node->val <= min || node->val >= max) {
            return false; // 当前节点值不在合法范围内
        }

        // 递归检查左子树和右子树
        return isValidBST(node->left, min, node->val) &&
               isValidBST(node->right, node->val, max);
    }
};
