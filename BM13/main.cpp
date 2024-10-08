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
     * @param head ListNode类 the head
     * @return bool布尔型
     */

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; // 前一个节点
        ListNode* curr = head;    // 当前节点

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; // 临时节点，用于保存下一个节点
            curr->next = prev;               // 反转当前节点的指针
            prev = curr;                     // 前一个节点移动到当前节点
            curr = nextTemp;                 // 当前节点移动到下一个节点
        }
        return prev; // 当循环结束时，prev将是新的头节点
    }
    bool isPail(ListNode* head) {
        // write code here
        if (head == nullptr) return true;
        // 双指针
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        // if (fast == nullptr)
        //     mid = slow->next;
        // else if (fast->next == nullptr)
        //     mid = slow;
        slow->next = nullptr;
        // 逆置mid
        mid = reverseList(mid);
        while (mid) {
            if (mid->val != head->val) return false;
            mid = mid->next;
            head = head->next;
        }

        return true;
    }
};