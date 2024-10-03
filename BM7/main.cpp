/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

class Solution {
  public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (!pHead ||
                !pHead->next) return nullptr; // 检查链表是否为空或只有一个节点

        ListNode* slow = pHead;
        ListNode* fast = pHead;  // 将fast初始化为pHead，避免空指针解引用

        while (fast && fast->next) { // 确保fast和fast->next不为空
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break; // 当slow和fast相遇时，退出循环
        }

        if (!fast || !fast->next) return nullptr; // 如果没有环，返回nullptr

        slow = pHead; // slow重新指向头节点
        while (slow != fast) { // slow和fast每次都移动一步，直到相遇
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // slow和fast在环的入口节点相遇
    }
};