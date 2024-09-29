/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param lists ListNode类vector
     * @return ListNode类
     */

    struct Compare {
        bool operator()(ListNode* node1, ListNode* node2) {
            return node1->val > node2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // write code here
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        for (auto& list : lists) {
            if(list)
                pq.push(list); // 所有链表的头节点入队列
        }

        while (!pq.empty()) {
            ListNode* mincur = pq.top();
            pq.pop();

            tail->next = mincur;
            tail = tail->next;
            if (mincur->next) {
                pq.push(mincur->next);
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
