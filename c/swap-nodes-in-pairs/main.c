#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *beforehead = malloc(sizeof(struct ListNode));
    beforehead->next = head;
    struct ListNode *prevNode = beforehead;
    struct ListNode *currNode = head;

    while (currNode != NULL && currNode->next != NULL) {
        prevNode->next = currNode->next;
        currNode->next = prevNode->next->next;
        prevNode->next->next = currNode;

        prevNode = currNode;
        currNode = currNode->next;
    }

    return beforehead->next;
}

int main() {
    struct ListNode *head1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1->val = -9;
    head1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1->next->val = 3;
    head1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1->next->next->val = 5;
    head1->next->next->next =
        (struct ListNode *)malloc(sizeof(struct ListNode));
    head1->next->next->next->val = 8;
    head1->next->next->next->next = NULL;

    struct ListNode *result = swapPairs(head1);
    while (result != NULL) {
        printf("result: %d\n", result->val);
        result = result->next;
    }

    return 0;
}
