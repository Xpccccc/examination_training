/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
  public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
         int len1 = 0, len2 = 0;
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;

        // 计算两个链表的长度
        while (cur1) {
            cur1 = cur1->next;
            len1++;
        }
        while (cur2) {
            cur2 = cur2->next;
            len2++;
        }

        // 让较长的链表先走长度之差的步数
        cur1 = pHead1;
        cur2 = pHead2;
        int gap = len1 - len2;
        if (gap > 0) {
            while (gap--) {
                cur1 = cur1->next;
            }
        } else {
            gap = -gap;
            while (gap--) {
                cur2 = cur2->next;
            }
        }

        // 同时走，直到找到第一个公共节点
        while (cur1 != cur2) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        return cur1; // 返回第一个公共节点，如果不存在公共节点则返回NULL
    }
};
