#include <stdio.h>

void allCombinations(int x, int y, int m) {
    // x = price 0f bread, y = price 0f milk,m = budget
    // not saying using all the budget.int bread = 0, milk, bread_price;
    int bread = 0, bread_price, milk;
    while ((bread_price = x * bread) < m) {
        milk = 0;
        while (bread_price + y * milk < m) {
            printf("买面包%d个,牛奶%d袋\n", bread, milk);
            milk++;
        }
        bread++;
    }
}

int main() {
    int x = 1, y = 2, m = 5;
    printf(" 所有方案： \n");
    allCombinations(x, y, m);
}