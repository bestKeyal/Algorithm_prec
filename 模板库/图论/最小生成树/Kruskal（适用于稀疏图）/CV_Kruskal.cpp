#include<bits/stdc++.h>

using namespace std;


struct Edge {
    int from, to, w;
} edge[200005];


int fa[5005], n, m;
int ans, efrom, eto, cnt;


// 实现对边排序的依赖函数
inline bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

// 并查集的查询函数，使用了路径压缩
inline int find(int x) {
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}

inline void kruskal() {
    //
    sort(edge, edge + m, cmp);

    for (int i = 0; i < m; ++i) {
        efrom = find(edge[i].from);
        eto = find(edge[i].to);

        if (efrom == eto) {
            // 两个点已经连通，这一条边也不需要了
            continue;
        }

        // 找到一条边，计入答案
        ans += edge[i].w;

        // 合并两个点
        fa[eto] = efrom;

        // 如果边的数量足够构建一棵树，那么就可以结束循环了。
        if (++cnt == n - 1) {
            break;
        }
    }
}