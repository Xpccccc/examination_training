/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        if(!head) return nullptr;
        if(head->next == nullptr) return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur){
            if(pre->val != cur->val){
                pre->next = cur;
                pre = cur;
            }
                
            cur = cur->next;
        }
        pre->next = nullptr; // 最后一个元素也可能是重复元素
        return head;
    }
};