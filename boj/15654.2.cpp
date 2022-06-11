#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N, M;
int a[9];
int ans[9];
bool used[9];
void dfs(int c) {
	int i;
	if (c == M) {
		for (i=0;i<M;i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	for (i=0;i<N;i++) {
		if (used[i]) continue;
		used[i] = 1;
		ans[c] = a[i];
		dfs(c+1);
		used[i] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i=0;i<N;i++)
		cin >> a[i];
	sort(a, a+N);
	dfs(0);
	return 0;
}

