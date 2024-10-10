/**
 * struct ListNode {
 *    int val;
 *    struct ListNode *next;
 *    ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 删除链表中的重复节点，保留链表中的非重复节点
     *
     * @param head ListNode类 链表头节点
     * @return ListNode类 返回处理后的链表头节点
     */
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;  // 空链表或只有一个节点

        // 创建虚拟头节点，方便处理
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* tail = dummy;  // 用于连接没有重复的节点
        ListNode* pre = head;
        ListNode* cur = head->next;

        while (pre) {
            // 判断当前节点是否存在重复
            bool isDuplicate = false;
            while (cur && pre->val == cur->val) {
                isDuplicate = true;
                cur = cur->next;
            }

            if (isDuplicate) {
                // 跳过所有重复节点
                tail->next = cur;
            } else {
                // 没有重复节点，更新 tail
                tail = pre;
            }

            // 更新前驱节点和当前节点
            pre = cur;
            if (cur) {
                cur = cur->next;
            }
        }

        return dummy->next;  // 返回去重后的链表头节点
    }
};
