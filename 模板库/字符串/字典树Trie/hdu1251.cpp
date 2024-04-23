
#include <bits/stdc++.h>

using namespace std;

const int MAXLEN = 1000010;

int trie[MAXLEN][26];
int num[MAXLEN] = {0};
int pos = 1;

void insert_str(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int n = str[i] - 'a';
        if (trie[p][n] == 0)
            trie[p][n] = pos++;
        p = trie[p][n];
        ++num[p];
    }
}

int find(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int n = str[i] - 'a';
        if (trie[p][n] == 0)
            return 0;
        p = trie[p][n];
    }

    return num[p];
}

int main() {



    char str[11];
    while (gets(str)) {
        if (!strlen(str)) break;
        insert_str(str);
    }
    while (gets(str))
        printf("%d\n", find(str));

    return 0;
}




