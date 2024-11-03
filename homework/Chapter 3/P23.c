#include <stdio.h>

/*
Well, the program in fact not specify the output order, here assume output in
ascending order.

Maybe loop from 1 to 100 is more straighforward than using 'if' statement.
*/
void print_6or7_num(int start, int end) {
    int p6, p7;
    for (int i = start; i < start + 6; i++) {
        if (i % 6 == 0) {
            p6 = i;
            break;
        }
    }
    for (int i = start; i < start + 6; i++) {
        if (i % 7 == 0) {
            p7 = i;
            break;
        }
    }
    while (p6 <= end) {
        if (p6 < p7) {
            printf("%d ", p6);
            p6 += 6;
        } else if (p7 < p6) {
            printf("%d ", p7);
            p7 += 7;
        } else {
            printf("%d ", p6);
            p6 += 6;
            p7 += 7;
        }
    }
    printf("\n");
}

void print_6xor7_num(int start, int end) {
    int p6, p7;
    for (int i = start; i < start + 6; i++) {
        if (i % 6 == 0) {
            p6 = i;
            break;
        }
    }
    for (int i = start; i < start + 6; i++) {
        if (i % 7 == 0) {
            p7 = i;
            break;
        }
    }
    while (p6 <= end) {
        if (p6 < p7) {
            printf("%d ", p6);
            p6 += 6;
        } else if (p7 < p6) {
            printf("%d ", p7);
            p7 += 7;
        } else {
            p6 += 6;
            p7 += 7;
        }
    }
    printf("\n");
}

int main() {
    print_6or7_num(0, 100);
    print_6xor7_num(0, 100);
    return 0;
}