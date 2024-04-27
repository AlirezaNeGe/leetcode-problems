#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
    struct ListNode *result = malloc(sizeof(struct ListNode));
    struct ListNode *tail = result;
    if (list1 == NULL && list2 == NULL) {
        return NULL;
    }

    while (list1 != NULL && list2 != NULL) {
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        if (list1->val >= list2->val) {
            newNode->val = list2->val;
            newNode->next = NULL;
            list2 = list2->next;
        } else {
            newNode->val = list1->val;
            newNode->next = NULL;
            list1 = list1->next;
        }
        tail->next = newNode;
        tail = tail->next;
    }

    while (list1 != NULL) {
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = list1->val;
        newNode->next = NULL;
        list1 = list1->next;
        tail->next = newNode;
        tail = tail->next;
    }
    while (list2 != NULL) {
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = list2->val;
        newNode->next = NULL;
        list2 = list2->next;
        tail->next = newNode;
        tail = tail->next;
    }

    return result->next;
}

int main() {
    struct ListNode *head1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1->val = -9;
    head1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1->next->val = 3;
    head1->next->next = NULL;

    struct ListNode *head2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head2->val = 5;
    head2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head2->next->val = 7;
    head2->next->next = NULL;

    struct ListNode *result = mergeTwoLists(head1, head2);
    while (result != NULL) {
        printf("result: %d\n", result->val);
        result = result->next;
    }

    return 0;
}
