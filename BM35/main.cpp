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
     * @return bool布尔型
     */
    bool isCompleteTree(TreeNode* root) {
        // write code here
        if (!root) return true; // 空树是完全二叉树

        std::queue<TreeNode*> q;
        q.push(root);
        bool foundNull = false; // 标记是否遇到空节点

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // 如果遇到空节点
            if (!node) {
                foundNull = true; // 标记已经遇到空节点
            } else {
                // 如果之前遇到过空节点，现在又有非空节点，则不是完全二叉树
                if (foundNull) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true; // 如果遍历完毕没有返回 false，则是完全二叉树

    }
};