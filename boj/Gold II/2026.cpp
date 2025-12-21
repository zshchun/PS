#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
bool g[901][901];
int cnt[901];
int K, N, F;
vector<int> selected;

bool is_mutual_friend(int x) {
	for (int i : selected)
		if (!g[x][i])
			return false;
	return true;
}

void backtrack(int x, int k) {
	if (!is_mutual_friend(x))
		return;

	selected.push_back(x);
	if (k == K) {
		for (int i : selected)
			cout << i << endl;
		exit(0);
	}
	for (int i=x+1;i<=N;i++)
		backtrack(i, k+1);
	selected.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, u, v;
	cin >> K >> N >> F;
	for (i=0;i<F;i++) {
		cin >> u >> v;
		g[v][u] = g[u][v] = 1;
		cnt[u]++; cnt[v]++;
	}

	for (i=1;i<=N;i++) {
		if (cnt[i] < K-1) continue;
		backtrack(i, 1);
	}

	cout << "-1\n";
	return 0;
}
