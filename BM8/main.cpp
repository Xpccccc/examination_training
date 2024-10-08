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
     * @param pHead ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        if (pHead == nullptr) return nullptr;

        // 先走k个
        ListNode* p1 = pHead;
        ListNode* p2 = pHead;
        while (--k) {
            p2 = p2->next;
            if(!p2) return nullptr;
        }

        while (p2->next) {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;

    }
};