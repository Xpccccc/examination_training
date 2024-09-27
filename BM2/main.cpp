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
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here

        ListNode* tmpnode = new ListNode(0);
        tmpnode->next = head;
        ListNode* prev = tmpnode;
        // 找到第m-1个节点
        for(int i = 1; i<m; ++i){
            prev = prev->next;
        }

        ListNode* start = prev->next;
        ListNode* start1 = prev->next;
        ListNode* tail = nullptr;
        ListNode* curr = start;
        prev->next = nullptr;
        // 反转第m到n的链表，头插
        for(int i=m; i<=n; ++i){
            curr = curr->next;
            tail = start->next;
            start->next = prev->next;
            prev->next = start;
            start = tail;
        }
        start1->next = curr;
        return tmpnode->next;
    }
};