
#include <bits/stdc++.h>

using namespace std;
const int MAX = 510;
bool graph[MAX][MAX];
int indegree[MAX];
int ans[MAX];
int n, m;



void toposort() {
    // 如果添加入度的操作在这里完成，则可以通过
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (graph[i][j])
                ++indegree[j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        int cur_node= 1;
        while (indegree[cur_node]  != 0)
            ++cur_node;
        ans[i] = cur_node;
        indegree[cur_node] = -1;
        for (int to = 1; to <= n; ++to)
            if (graph[cur_node][to])
                --indegree[to];

    }
}

int main() {
    while (cin >> n >> m) {
        memset(graph, 0, sizeof graph);
        memset(ans, 0, sizeof ans);
        memset(indegree, 0, sizeof indegree);

        int win, los;
        while (m--) {
            cin >> win >> los;
            graph[win][los] = true;


        // 如果在输入边的同时进行增加入度，则会错误
        // 因为重复的边可能导致入度被错误计算
        // indegree[los]++;
        }

        toposort();

        for (int i = 1; i < n; ++i)
            cout << ans[i] << " ";
        cout << ans[n] << endl;
    }
    return 0;
}
