#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode node;
node* addTwoNumbers(node* l1, node* l2) {
    node fakeStart;
    int add = 0;
    int carry = 0;
    node* cur = &fakeStart;
    do {
        cur->next = malloc(sizeof(node));
        cur = cur->next;
        add = l1->val + l2->val + carry;
        carry = add / 10;
        cur->val = add - carry * 10;
        l1 = l1->next;
        l2 = l2->next;
    } while (l1 != NULL && l2 != NULL);
    if (l2 != NULL) {
        l1 = l2;
    }
    if (l1 != NULL) {
        do {
            cur->next = malloc(sizeof(node));
            cur = cur->next;
            add = l1->val + carry;
            carry = add / 10;
            cur->val = add - carry * 10;
            l1 = l1->next;
        } while (l1 != NULL);
    }
    if (carry != 0) {
        cur->next = malloc(sizeof(node));
        cur = cur->next;
        cur->val = 1; // Only can be 1
    }
    cur->next = NULL;
    return fakeStart.next;
}

node* createByArray(int *a, int n) {
    node fakeStart;
    node* p = &fakeStart;
    for (int i = 0; i < n; i++) {
        p->next = malloc(sizeof(node));
        p = p->next;
        p->val = a[i];
    }
    p->next = NULL;
    return fakeStart.next;
}

int main() {
    int d1[7] = {9,9,9,9,9,9,9};
    int d2[4] = {9,9,9,9};
    node* l1 = createByArray(d1, 7);
    node* l2 = createByArray(d2, 4);
    node* res = addTwoNumbers(l1, l2);
    node* p = res;
    while (p != NULL) {
        printf("%d", p->val);
        p = p->next;
    }
    printf("\n");
}