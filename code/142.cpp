#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *ptr1 = head;
        ListNode *ptr2 = head;
        do {
            if (!ptr1 || !ptr1->next) {
                return NULL;
            }
            ptr1 = ptr1->next->next;
            ptr2 = ptr2->next;
        } while (ptr1 != ptr2);
        ptr1 = head;
        while(ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};