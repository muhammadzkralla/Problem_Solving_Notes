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

    ListNode* mid(ListNode* head) {
        ListNode* slow = head;
        // fast is set to head->next to get the node just before the middle instead of the middle
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode front = ListNode();
        // tail is going to be the moving pointer while front is static.
        ListNode* tail = &front;

        while (head1 != NULL && head2 != NULL) {
            if (head1->val < head2->val) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }

            tail = tail->next;
        }

        if (head1 != NULL)
            tail->next = head1;

        if (head2 != NULL)
            tail->next = head2;

        return front.next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* left = head;
        ListNode* middle = mid(head);
        ListNode* right = middle->next;
        middle->next = NULL;

        left = sortList(left);
        right = sortList(right);

        return (merge(left, right));
    }
};