/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // if(lists.size()==0) return NULL;
        // if(lists.size()==1 && lists[0]==NULL) return NULL;
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }
        ListNode dummy;
        ListNode* current = &dummy;
        while (!pq.empty()) {
            ListNode* temp = pq.top();
            current->next = temp;
            current = current->next;
            if (temp->next)
                pq.push(temp->next);
            pq.pop();
        }
        return dummy.next;
    }
};