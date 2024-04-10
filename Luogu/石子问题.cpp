#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;
const int N = 3000;
int sum[N], n;


int MinVal() {
	int dp[N][N], s[N][N];
	for (int i = 1; i <= n; ++i){
		s[i][i] = i;
		dp[i][i] = 0;
	}
	
	for (int len = 1; len < n; ++len) 
		for (int i = 1; i <= n - len; ++i) {
			int j = i + len;
			dp[i][j] = INF;
			
			for (int k = s[i][j - 1]; k <= s[i + 1][j]; ++k) {
				cout << k << endl;
				if (dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]
					<
					dp[i][j]
				){
					dp[i][j] = dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1];
					s[i][j] = k;
				}
			}
			
		}
	
	return dp[1][n];
}

int main() {
	
	while (cin >> n) {
		sum[0] = 0;
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			sum[i] = sum[i - 1] + x;
		}
		cout << MinVal() << endl;
	}
	
	return 0;
}


