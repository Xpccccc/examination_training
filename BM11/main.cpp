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
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */

    ListNode* Reverse(ListNode* list) {
        if (list == nullptr) return nullptr;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        ListNode* ltail = list;
        while (list) {
            ltail = list->next;
            list->next = tail->next;
            tail->next = list;  // 修改这里，将list插入到tail的后面
            list = ltail;
        }

        ListNode* newhead = dummy->next;
        delete dummy;

        return newhead;
    }
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        if (head1 == nullptr) return head2;
        if (head2 == nullptr) return head1;

        ListNode* newhead1 = Reverse(head1);
        ListNode* newhead2 = Reverse(head2);
        ListNode* ret = new ListNode(0);
        ListNode* tail = ret;

        int carry = 0;
        while (newhead1 != nullptr || newhead2 != nullptr || carry > 0) {
            int val1 = (newhead1 != nullptr) ? newhead1->val : 0;
            int val2 = (newhead2 != nullptr) ? newhead2->val : 0;
            int sum = val1 + val2 + carry;

            carry = sum / 10;
            ListNode* newnode = new ListNode(sum % 10);

            // 添加到结果链表尾部
            tail->next = newnode;
            tail = newnode;

            if (newhead1 != nullptr) newhead1 = newhead1->next;
            if (newhead2 != nullptr) newhead2 = newhead2->next;
        }

        // 最终将结果链表反转回去
        ListNode* finalResult = Reverse(ret->next);
        delete ret;
        return finalResult;
    }
};
