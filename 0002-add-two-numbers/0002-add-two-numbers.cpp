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
private:
    void addNode(ListNode** l, int val)
    {
        if (!*l)
        {
            *l = new ListNode(val);
            return ;
        }
        ListNode* tmp = *l;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new ListNode(val);
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int remainder = 0;
        int result = 0;
        int i1 = 0;
        int i2 = 0;
        ListNode* finalList;
        while (l1 || l2)
        {
            if (l1 && l2)
                remainder += l1->val + l2->val;
            else if (l1)
                remainder += l1->val;
            else
                remainder += l2->val;
            result = remainder % 10;
            remainder /= 10;
            // ***
            addNode(&finalList, result);
            // ***
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (remainder)
            addNode(&finalList, remainder);
        return (finalList);
    }
};