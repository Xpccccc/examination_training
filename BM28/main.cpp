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
     * @param root TreeNode类
     * @return int整型
     */
    int maxDepth(TreeNode* root) {
        // write code here
        // 前序遍历
        int curdeep = 1;
        int deep = 0;
        preOrder(root, curdeep, deep);
        return deep;
    }

    void preOrder(TreeNode* root, int curdeep, int& deep) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            deep = max(deep, curdeep);
        }
        preOrder(root->left, curdeep + 1, deep);
        preOrder(root->right, curdeep + 1, deep);
    }
};