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
     * @param pHead1 ListNode类
     * @param pHead2 ListNode类
     * @return ListNode类
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        // write code here
        if (pHead1 == nullptr) return pHead2;
        if (pHead2 == nullptr) return pHead1;

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        ListNode* pcur1 = pHead1;
        ListNode* pcur2 = pHead2;

        while (pcur2 != nullptr & pcur1 != nullptr) {
            if (pcur1->val < pcur2->val) {
                tail->next = pcur1;
                tail = pcur1;
                pcur1 = pcur1->next;
            } else {
                tail->next = pcur2;
                tail = pcur2;
                pcur2 = pcur2->next;
            }
        }

        if (pcur1)
            tail->next = pcur1;
        if (pcur2)
            tail->next = pcur2;

        ListNode* newHead = dummy->next;

        delete dummy;

        return newHead;
    }
};