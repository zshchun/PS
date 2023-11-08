#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define BEGIN 0

int a[16][16];
int dp[16][1<<16];
int N;

// traveling salesman problem (TSP)
int dfs(int from, int visited) {
	if (__builtin_popcount(visited) == N) {
		return a[from][BEGIN] ? a[from][BEGIN] : INF;
	}
	int &cur = dp[from][visited];

	if (cur != INF)
		return cur;
	cur--;

	for (int to=0;to<N;to++) {
		if (!a[from][to]) continue;
		if (visited & (1<<to)) continue;
		cur = min(cur, dfs(to, visited | (1<<to)) + a[from][to]);
	}

	return cur;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N;
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			cin >> a[i][j];
		}
	}
	fill_n(&dp[0][0], sizeof(dp)/sizeof(dp[0][0]), INF);
	
	cout << dfs(BEGIN, 1<<BEGIN) << endl;
	return 0;
}
