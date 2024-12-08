#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    char flag[128] = {0};
    int left = 0, right = 0, max = 0;
    while (s[right] != '\0') {
        while (flag[s[right]] == 1 && left < right) {
            flag[s[left]] = 0;
            left++;
        }
        flag[s[right]] = 1;
        int sub = right - left;
        if (sub > max) {
            max = sub;
        }
        right++;
    }
    return max + 1;
}

int main() {
    char s[] = "abcabceee";
    printf("%d\n", lengthOfLongestSubstring(s));
}