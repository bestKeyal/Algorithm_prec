#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1100;

char str[MAXN], pattern[MAXN];
int Next[MAXN];
int cnt;

void getFail(char * p, int plen) {
    // 计算出Next数组
    Next[0] = 0, Next[1] = 0;
    int i = 1;
    for ( ; i < plen; ++i) {
        int j = Next[i];
        while (j && p[i] != p[j])
            j = Next[j]; // 失配回溯
        Next[i + 1] = ( p[i] == p[j] ) ? j + 1 : 0;
    }
}

void kmp(char * s, char * p) {
    int last = -1;
    int slen = strlen(s), plen = strlen(p);
    getFail(p, plen);
    int j = 0, i = 0;
    for ( ; i < slen; ++i ) {
        while ( j && s[i] != p[j] )
            j = Next[j];
        if ( s[i] == p[j] )
            ++j;
        if ( j == plen ) {
            // 防止与上一次分割出来的小饰条(模式串)重叠。
            if ( i - last >= plen ) {
                ++cnt;
                last = i;
            }
        }
    }
}
int main() {
    while ( ~scanf("%s", str) ) {
        if (str[0] == '#')
            break;
        scanf("%s", pattern);
        cnt = 0;
        kmp(str, pattern);
        printf("%d\n", cnt);
    }

    return 0;
}