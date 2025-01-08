#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define INF INT32_MAX

int N, ans = INF;
int a[10][10];

void dfs(int s, int p, int visited, int sum) {
	if (__builtin_popcount((1<<p) | visited) == N) {
		if (a[p][s] && sum+a[p][s] < ans)
			ans = sum + a[p][s];
		return;
	}

	for (int i=0;i<N;i++) {
		if (a[p][i] == 0 || visited & (1<<i))
			continue;
		dfs(s, i, visited | (1 << p), sum + a[p][i]);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N;
	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			cin >> a[i][j];

//	for (i=0;i<N;i++) {
		dfs(0, 0, 0, 0);
//	}

	cout << ans << endl;

	return 0;
}
