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
    struct LIstNode *second;
    while (first != NULL) {
        if (first->next == NULL) {
            break;
        }
        first = first->next;
        i++;
    }
    if (i == 1)
        return NULL;
    printf("length: %d\n", i);

    int indexToRemove = i - n + 1;
    printf("index to remove: %d\n", indexToRemove);
    i = 1;
    first = head;
    while (first != NULL) {
        if (i == indexToRemove - 1) {
            if (first->next->next == NULL) {
                first->next = NULL;
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
    // head1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    // head1->next->val = 4;
    // head1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    // head1->next->next->val = 3;
    // head1->next->next->next = NULL;

    removeNthFromEnd(head1, 1);

    return 0;
}
