class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr || head->next->next == nullptr) return head;

        ListNode* odd = head; // 奇数位置的节点
        ListNode* even = head->next; // 偶数位置的节点
        ListNode* evenHead = even; // 偶数位置链表的头节点，用于最后连接

        while(even != nullptr && even->next != nullptr) {
            odd->next = even->next; // 将奇数位置的下一个节点指向偶数位置的下一个节点
            odd = odd->next; // 移动到下一个奇数位置的节点
            even->next = odd->next; // 将偶数位置的下一个节点指向奇数位置的下一个节点
            even = even->next; // 移动到下一个偶数位置的节点
        }

        odd->next = evenHead; // 将最后一个奇数位置的节点的下一个节点指向偶数位置链表的头节点

        return head;
    }
};
