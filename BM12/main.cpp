/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        // write code here
        if (!head || !head->next) return head;

        // 使用快慢指针找中点
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 切割链表
        ListNode* mid = slow->next;
        slow->next = nullptr;

        // 递归排序左右两部分
        ListNode* left = sortInList(head);
        ListNode* right = sortInList(mid);

        // 合并排序好的链表
        return merge(left, right);
    }

    // 合并两个已排序的链表
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        // 将剩余部分接上
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;

        return dummy.next;
    }
};
