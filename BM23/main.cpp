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
     * @return int整型vector
     */
    vector<int> path;
    vector<int> preorderTraversal(TreeNode* root) {
        // write code here
        preOrder(root);
        return path;
    }

    void preOrder(TreeNode* root){
        if(root == nullptr)
            return ;
        path.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
};