/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @param p int整型 
     * @param q int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        // write code here
        // 确保 p 和 q 的值是正确的
        if (root == nullptr) return -1;

        // 如果当前节点的值大于 p 和 q 的值，则向左子树查找
        if (root->val > p && root->val > q) {
            return lowestCommonAncestor(root->left, p, q);
        }
        // 如果当前节点的值小于 p 和 q 的值，则向右子树查找
        else if (root->val < p&& root->val < q) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            // 否则，当前节点就是最近公共祖先
            return root->val;
        }
    }
};