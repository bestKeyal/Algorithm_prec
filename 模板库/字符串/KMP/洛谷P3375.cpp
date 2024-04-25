#include <bits/stdc++.h>

using namespace std;


// --------------------------------------------------------------------

/*

         索引从0开始的写法

 */

const int MN = 10001000;

char s1[MN], s2[MN];
int nxt[MN];
int l1, l2;
void get_nxt() {

    memset(nxt, 0, sizeof nxt);

    int j = 0;
    // 计算出从左边开始截至第i个字符的子串的nxt状态转移边。
    for (int i = 1; i <= l2; ++i) {
        while (j > 0 && s2[j] != s2[i])
            j = nxt[j - 1];

        if (s2[i] == s2[j])
            ++j;
        nxt[i] = j;
    }
}

void kmp_idx_0() {
    get_nxt();
    int j = 0;
    for (int i = 0; i < l1; ++i) {
        while (j != 0 && s1[i] != s2[j]) {
            j = nxt[j - 1];
        }

        if (s1[i] == s2[j])
            ++j;

        if (j == l2)
        // 因为索引从0开始，
        // 所以i - j + 1 之后得到的是原来的从0开始的索引
        // 需要额外 + 1，才能满足题目要求的从1开始
         printf("%d\n", i - j + 2);
    }

    for (int i = 0; i < l2 - 1; ++i)
        printf("%d ", nxt[i]);
    printf("%d", nxt[l2 - 1]);

}


//signed main() {
////    freopen("D:\\BrowserDownload\\P3375_11.in", "r", stdin);
//    scanf("%s%s", s1, s2);
//    l1 = strlen(s1);
//    l2 = strlen(s2);
//    kmp_idx_1();
//}

// --------------------------------------------------------------------

/*

         索引从1开始的写法

 */
#define MAXN 1000010

int kmp[MAXN];
int la, lb, j;

char a[MAXN], b[MAXN];

int kmp_idx_1() {
    cin >> a + 1;
    cin >> b + 1;
    la = strlen(a + 1);
    lb = strlen(b + 1);
    // 索引从1开始
    // j + 1 代表了当前需要匹配的位置
    // j 代表了当前已经匹配的长度

    for (int i = 2; i <= lb; ++i) {
        while (j && b[i] != b[j + 1]) {
            j = kmp[j];
        }
        if (b[j + 1] == b[i])
            ++j;
        kmp[i] = j;
    }
    j = 0;
    for (int i = 1; i <= la; ++i) {
        while (j > 0 && b[j + 1] != a[i])
            j = kmp[j];


        if (b[j + 1] == a[i])
            ++j;

        if (j == lb) {
            cout << i - lb + 1 << endl;
            j = kmp[j];
        }
    }

    for (int i = 1; i <= lb; ++i)
        cout << kmp[i] << " ";
}


