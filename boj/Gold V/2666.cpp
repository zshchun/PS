#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int A, B, N, M;
int a[21];
int dfs(int x, int y, int n) {
	int ret = INF;
	if (n == M) return 0;
	if (x == a[n] || y == a[n]) ret = dfs(x, y, n + 1);
	if (a[n] < x)
		ret = min(ret, dfs(a[n], y, n + 1) + x - a[n]);
	if (y < a[n])
		ret = min(ret, dfs(x, a[n], n + 1) + a[n] - y);
	if (x < a[n] && a[n] < y)
		ret = min({ret, dfs(a[n], y, n + 1) + a[n] - x, dfs(x, a[n], n + 1) + y - a[n]});
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, ans;
	cin >> N >> A >> B >> M;
	for (i=0;i<M;i++)
		cin >> a[i];
	if (A > B)
		swap(A, B);
	ans = dfs(A, B, 0);

	cout << ans << endl;
	return 0;
}
