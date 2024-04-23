#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000000 + 100;
const int SIGMA_SIZE = 26;
const int MAXNODE = 1000000 + 100;

int n, ans;

bool vis[MAXN];
int ch[MAXNODE][SIGMA_SIZE + 5];
int val[MAXNODE];
int idx(char c) {return c - 'a';}

struct Trie {
    int sz;
    Trie() {
        sz = 1;
        memset(ch[0], 0, sizeof ch[0]);
        memset(vis, 0, sizeof vis);


    }
    void insert(char * s) {
            int u = 0, n = strlen(s);
            int i;
            for (i = 0; i < n; ++i) {
                int c = idx(s[i]);
                if (!ch[u][c]) {
                    memset(ch[sz], 0, sizeof ch[sz]);
                    val[sz] = 0;
                    ch[u][c] = sz++;
                }
                u = ch[u][c];
            }
            ++val[u];
        }
};


int last[MAXN], f[MAXN];

// AC automaton
void print(int j) {
    if ( j && !vis[j] ) {
        ans += val[j];
        vis[j] = 1;
        print(last[j]);
    }
}

void getFail() {
    queue<int> q;
    f[0] = 0;
    int c = 0;
    for (; c < SIGMA_SIZE; ++c) {
        int u = ch[0][c];
        if (u) {
            f[u] = 0;
            q.push(u);
            last[u] = 0;
        }
    }

    while (!q.empty()) {
        int r = q.front(); q.pop();
        c = 0;
        for (; c < SIGMA_SIZE; ++c) {
            int u = ch[r][c];
            if (!u) {
                ch[r][c] = ch[f[r]][c];
                continue;
            }

            q.push(u);
            int v = f[r];
            while (v && !ch[v][c]) v = f[v];
            f[u] = ch[v][c];
            last[u] = val[f[u]] ? f[u] : last[f[u]];
        }
    }
}

void find_T(char * T) {
    int n = strlen(T);
    int j = 0;

    int i = 0;
    for (; i < n; ++i) {
        int c = idx(T[i]);
        j = ch[j][c];
        if (val[j])
            print(j);
        else if (last[j])
            print(last[j]);

    }
}

char tmp[105];
char text[MAXNODE];

int main() {
    int T;
    cin >> T;

    while (T--) {
        scanf("%d", &n);
        Trie trie;
        ans = 0;

        int i = 0;
        for (; i < n; ++i) {
            scanf("%s", tmp);
            trie.insert(tmp);
        }
        getFail();
        scanf("%s", text);
        find_T(text);
        cout << ans << endl;
    }

    return 0;

}



