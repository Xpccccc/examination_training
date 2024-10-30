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
     * @param t1 TreeNode类 
     * @param t2 TreeNode类 
     * @return TreeNode类
     */
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // write code here
        if(t1 == nullptr && t2 ==nullptr) return nullptr;
        if(t1 == nullptr ) return t2;
        if(t2 == nullptr ) return t1;

        // 创建新节点
        TreeNode* newnode = new TreeNode(t1->val + t2->val);
        newnode->left = mergeTrees(t1->left, t2->left);
        newnode->right = mergeTrees(t1->right, t2->right);
        return newnode;
    }
};