#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    int i = 1;
    struct ListNode *first = head;
    while (first != NULL) {
        if (first->next == NULL) {
            break;
        }
        first = first->next;
        i++;
    }
    if (i == 1)
        return NULL;

    int indexToRemove = i - n + 1;
    if (indexToRemove == 1) {
        return head->next;
    }
    i = 1;
    first = head;
    while (first != NULL) {
        if (i == indexToRemove - 1) {
            if (first->next->next == NULL) {
                first->next = NULL;
                return head;
            }
            first->next = first->next->next;
        }
        first = first->next;
        i++;
    }
    return head;
}

int main() {

    // linked list
    struct ListNode *head1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1->val = 1;
    head1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1->next->val = 4;

    removeNthFromEnd(head1, 1);

    return 0;
}
