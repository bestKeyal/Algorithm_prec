#include<bits/stdc++.h>

using namespace std;
#define il inline

const int MAX_EDGE_NUM = 200005;
const int MAX_NODE_NUM = 5005;  // 如果是完全图

il int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}

struct Edge {
    int from, to, w;
} edge[200005];


int fa[5005], n, m;
int ans, root_from, root_to, cnt;



// 实现对边排序的依赖函数
il bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

// 并查集的查询函数，使用了路径压缩
il int find(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

il void kruskal() {
    sort(edge, edge + m, cmp);

    for (int i = 0; i < m; ++i) {
        root_from = find(edge[i].from);
        root_to = find(edge[i].to);

        if (root_from == root_to) {
            // 两个点已经连通，这一条边也不需要了
            continue;
        }

        // 找到一条边，计入答案
        ans += edge[i].w;

        // 合并两个点
        fa[root_to] = root_from;

        // 如果边的数量足够构建一棵树，那么就可以结束循环了。
        if (++cnt == n - 1) {
            break;
        }
    }
}

bool vis[MAX_NODE_NUM];

int g[MAX_NODE_NUM][MAX_NODE_NUM];

int true_cnt = 0;
il void dfs(int from) {
    vis[from] = true;
    ++true_cnt;
    for (int i = 1; i <= n; ++i) {
        if (g[from][i] && i != from && !vis[i])
            dfs(i);
        if (true_cnt == n)
            break;
    }
}

bool verify() {
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            return false;
    }
    return true;
}

//int main() {
//    n = read(), m = read();
//
//    for (int i = 1; i <= n; ++i) {
//        fa[i] = i;
//    }
//
//    for (int i = 0; i < m; ++i) {
//        int & from = edge[i].from;
//        int & to   = edge[i].to;
//        int & w    = edge[i].w;
//        from = read();
//        to = read();
//        w = read();
//        g[from][to] = 1;
//        g[to][from] = 1;
//
//    }
//
//    bool res = verify();
//    if (!res) {
//        printf("%s", "orz");
//        return 0;
//    }
//    kruskal();
//
//    printf("%d", ans);
//
//    return 0;
//}
