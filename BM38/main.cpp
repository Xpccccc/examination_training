class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param root TreeNode类
     * @param o1 int整型
     * @param o2 int整型
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        // 基本情况：如果当前节点为空，返回 -1
        if (root == nullptr) {
            return -1;
        }

        // 如果当前节点的值等于 p 或 q，返回当前节点的值
        if (root->val == p || root->val == q) {
            return root->val;
        }

        // 在左子树和右子树中查找 p 和 q
        int left = lowestCommonAncestor(root->left, p, q);
        int right = lowestCommonAncestor(root->right, p, q);

        // 如果 p 和 q 分别在左右子树中，则当前节点为最近公共祖先
        if (left != -1 && right != -1) {
            return root->val; // 修正这里，使用 root->val 而不是 root.val
        }

        // 否则返回非空的子树
        return left != -1 ? left : right; // 修正返回条件，确保返回 -1 时不返回 nullptr
    }
};
