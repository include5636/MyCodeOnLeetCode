#include<bits/stdc++.h>
using namespace std;

/* 不要忘记最后的进位!!! */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1 = l1, *ptr2 = l2;
        while (ptr1->next && ptr2->next) {
            ptr1->val += ptr2->val;
            if (ptr1->val > 9) {
                ptr1->val -= 10;
                ptr1->next->val += 1;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if (!ptr1->next) {
            ptr1->next = ptr2->next;
        }
        ptr1->val += ptr2->val;
        while (ptr1 && ptr1->val > 9 ) {
            ptr1->val -= 10;
            if (ptr1->next) {
                ptr1->next->val += 1;
            } else {
                ptr1->next = new ListNode(1);
            }
            ptr1 = ptr1->next;
        }
        return l1;
    }
};