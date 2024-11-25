#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ll long long
#define BIT_MASK 0x7
#define BYTE_MASK 0xFF

ll linear_filter1(ll *prime, ll max);
ll linear_filter2(char *filter, ll *prime, ll max);

/*returned array length is 3. */
ll gedebach(ll *prime, ll cnt, ll n) {
    FILE *f = fopen("Result.txt", "w");
    char *string = malloc(104857600 * sizeof(char));
    setvbuf(f, string, _IOFBF, 104857600);
    // int prime[10000000];
    // ll cnt = linear_filter1(prime, n);
    int solution = 0;
    ll k = 0;
    if (n % 2 == 0) {
        ll remain = n - 2;
        ll i = k, j = cnt - 1;
        while (i < j) {
            if (prime[i] + prime[j] < remain) {
                i++;
            } else if (prime[i] + prime[j] > remain) {
                j--;
            } else {
                // printf("Found %lld + %lld = %lld\n", prime[i], prime[j], n);
                fprintf(f, "%lld %lld %lld\n", prime[i], prime[j], prime[k]);
                solution++;
                j--;
            }
        }
    } else {
        while (k < cnt) {
            ll remain = n - prime[k];
            ll i = k, j = cnt - 1;
            while (i < j) {
                if (prime[i] + prime[j] < remain) {
                    i++;
                } else if (prime[i] + prime[j] > remain) {
                    j--;
                } else {
                    // printf("Found %lld + %lld = %lld\n", prime[i], prime[j],
                    // n);
                    fprintf(f, "%lld %lld %lld\n", prime[i], prime[j],
                            prime[k]);
                    solution++;
                    j--;
                }
            }
            k++;
        }
    }
    fflush(f);
    fclose(f);
    return solution;
}

/*PLEASE ENSURE THAT PRIME IS BIG ENOUGH*/
// ll linear_filter1(ll *prime, ll max) {
//     char *filter = (char *)malloc(max * sizeof(char));
//     ll cnt = 0;
//     for (ll i = 2; i < max; i++) {
//         filter[i] = 1;
//     }
//     filter[0] = filter[1] = 0;
//     prime[cnt++] = 2;
//     for (ll i = 3; i < max + 1; i += 2) {
//         if (filter[i] == 1) {
//             // printf("idx = %d, idx = %d\n", (int)(i + 1) >> 3,
//             //        (int)(i & 0b0111));
//             prime[cnt++] = i;
//             for (ll j = i * 3; j < max + 1; j += i * 2) {
//                 filter[j] = 0;
//                 // printf("idx = %d, idx = %d\n", (int)(j + 1) >> 3,
//                 //    (int)(j & 0b0111));
//             }
//         }
//     }
//     free(filter);
//     return cnt;
// }

ll linear_filter1(ll *prime, ll n) {
    ll l = (n >> 4) + 1;
    char *filter = (char *)malloc((l) * sizeof(char));
    ll cnt = 0;
    // optimized the even part.
    prime[cnt++] = 2;
    for (ll i = 0; i < l; i++) {
        filter[i] = BYTE_MASK;
    }
    filter[0] ^= 1;
    // `idx` & `pos` init refer as 3
    ll idx = 0;
    char pos = 0;
    for (ll _i = 0; _i < (n - 3) / 2; _i++) {
        // `pos` is the flag pos in the char elem
        // `idx` is the index of char array
        pos++;
        idx += pos >> 3;
        pos &= BIT_MASK;
        if (filter[idx] & (1 << pos)) { // (> 0)
            // printf("idx = %d, idx = %d\n", (int)(i + 1) >> 3,
            //        (int)(i >> 1) & BIT_MASK);

            // ALWAYS REMEMBER 2*N SHOULD LEFT SHIFT N!!!
            ll cur_prime = (ll)(idx << 4) | (ll)(pos << 1) | 1;
            prime[cnt++] = cur_prime;
            ll pos1 = (cur_prime * cur_prime) >> 1;
            ll idx1 = pos1 >> 3;
            pos1 = pos1 & BIT_MASK;

            
            for (; idx1 < l;) {
                filter[idx1] &= ~((1 << pos1));
                // init `pos` from `i`. `pos` is the flag pos in filter elem
                // it may not be fast, but straight.
                // `pos` add twice the `i`, in this circumstances it adds `i`
                pos1 += cur_prime;
                // so idx only adds pos / 8
                idx1 += pos1 >> 3;
                pos1 = pos1 & BIT_MASK;
                // set the bit to 0
                // printf("idx = %d, idx = %d\n", (int)(j + 1) >> 3,
                //    (int)(j & BIT_MASK));
            }
        }
    }
    free(filter);
    return cnt;
}

/*PLEASE ENSURE THAT ARRAY PRIME IS BIG ENOUGH*/
ll linear_filter2(char *filter, ll *prime, ll max) {
    ll cnt = 0;
    for (ll i = 0; i < max; i++) {
        filter[i] = i & 1;
    }
    filter[1] = 0;
    filter[2] = 1;
    prime[cnt++] = 2;
    for (ll i = 3; i <= max; i++) {
        if (filter[i] == 1) {
            prime[cnt++] = i;
        }
        for (ll j = 0, idx; j < cnt && (idx = (i * prime[j])) <= max; j++) {
            filter[idx] = 0;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    return cnt;
}

int main(void) {
    int n;
    clock_t start, end;
    scanf("%d", &n);
    ll *prime = (ll *)malloc((n / 2) * sizeof(ll));
    start = clock();
    ll cnt = linear_filter1(prime, n);
    end = clock();
    printf("Create Prime Table: %ldms\n",
           (end - start) * 1000 / CLOCKS_PER_SEC);
    start = clock();
    ll solution = gedebach(prime, cnt, n);
    end = clock();
    printf("共有%lld方案\n", solution);
    printf("Stat Solutions: %ldms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    return 0;
}