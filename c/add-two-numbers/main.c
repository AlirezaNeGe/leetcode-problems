#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *result = malloc(sizeof(struct ListNode));
    struct ListNode *tail = result;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = 0;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;
        sum %= 10;

        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = sum;
        newNode->next = NULL;

        tail->next = newNode;
        tail = tail->next;
    }

    free(tail);
    return result->next;
}

int main() {
    // linked list
    struct ListNode *head1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1->val = 2;
    head1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1->next->val = 4;
    head1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1->next->next->val = 3;
    head1->next->next->next = NULL;

    // linked list
    struct ListNode *head2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head2->val = 5;
    head2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head2->next->val = 6;
    head2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head2->next->next->val = 4;
    head2->next->next->next = NULL;

    struct ListNode *result = addTwoNumbers(head1, head2);
    printf("result = %d\n", result->val);
    free(result);

    return 0;
}
