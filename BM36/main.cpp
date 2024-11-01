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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pRoot TreeNode类
     * @return bool布尔型
     */
    int height(TreeNode* node) {
        if (!node) return 0; // 空节点高度为0

        int leftHeight = height(node->left);
        if (leftHeight == -1) return -1; // 左子树不平衡

        int rightHeight = height(node->right);
        if (rightHeight == -1) return -1; // 右子树不平衡

        // 检查当前节点的左右子树高度差
        if (std::abs(leftHeight - rightHeight) > 1) {
            return -1; // 不平衡
        }

        // 返回当前节点的高度
        return std::max(leftHeight, rightHeight) + 1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        // write code here
        return height(pRoot) != -1;
    }
};