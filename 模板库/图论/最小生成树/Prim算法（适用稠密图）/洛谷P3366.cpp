#include <bits/stdc++.h>


using namespace std;

#define il inline

il int read() {
    int x = 0, f = 1;
    char c = getchar();

    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = getchar();
    }

    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

#define INF 0x3f3f3f3f;
#define maxn 5005
#define maxm 200005

struct Edge {
    int to;   // to代表这条边的目标节点
    int w;    // w代表了边权
    int next; // next指向了相同起始节点的下一条边。
} edge[maxm << 1];   // 无向图，一条边的来去都需要记录，故开双倍空间。

int head[maxn], dis[maxn];

int cnt, n, m, tot, now = 1, ans;

bool vis[maxn];

il void dfs(int from) {
    vis[from] = true;
    for (int i = head[from]; i ; i = edge[i].next) {
        int to = edge[i].to;
        if (!vis[to])
            dfs(to);
    }
}

// 加边
il void add(int from, int to, int w) {
    edge[++cnt].to = to;
    edge[cnt].w    = w;
    edge[cnt].next = head[from]; // 把当前新加的边的next指向原本的from节点指向的边
    head[from]     = cnt;        // 把from节点指向最后添加的一条边
}

// 读取数据
il bool init() {
    n = read(), m = read();
    for (int i = 1, from, to, w; i <= m; ++i) {
        from = read(), to = read(), w = read();
        add(from, to, w);
        add(to, from, w);
    }

    // 检查图的连通性
    dfs(1);
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            return false;

    memset(vis, false, sizeof vis);
    return true;

}

// 实现Prim算法计算最小生成树的总权重
il int prim() {
    // 初始化除了节点1之外的所有节点的dis数组为无穷大
    for (int i = 2; i <= n; ++i) {
        dis[i] = INF;
    }

    // 遍历与节点1相连的所有节点，初始化它们到节点1的距离
    for (int i = head[1]; i; i = edge[i].next) {
        int & d = dis[edge[i].to];
        d = min(d, edge[i].w);
    }

    // 主循环，直到生成树包含所有n个节点
    while (++tot < n) {
        int minn = INF; // 用于找到未访问节点中dis值最小的节点
        vis[now] = true; // 标记当前节点为已访问

        // 寻找dis值最小的未访问节点，并记录其索引到now
        for (int i = 1; i <= n; ++i) {
            int & di = dis[i];

            if (!vis[i] && minn > di) {
                minn = di;
                now = i;
            }
        }

        // 将找到的最小dis值加到答案中
        ans += minn;

        // 更新当前节点now的所有未访问邻居节点的dis值
        for (int i = head[now]; i; i = edge[i].next) {
            int to = edge[i].to;
            if (dis[to] > edge[i].w && !vis[to]) {
                dis[to] = edge[i].w; // 更新dis数组
            }
        }
    }

    return ans; // 返回最小生成树的总权重
}

//int main() {
//    bool valid = init();
//    if (!valid) {
//        printf("%s", "orz");
//        return 0;
//    }
//    int res = prim();
//
//    printf("%d", res);
//    return 0;
//}