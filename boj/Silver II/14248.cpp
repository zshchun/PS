#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, s;
int a[100001];
bool visited[100001];

void dfs(int x) {
	if (visited[x]) return;
	visited[x] = 1;
	int l = x - a[x];
	int r = x + a[x];
	if (l > 0) dfs(l);
	if (r <= n) dfs(r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin >> n;
	for (i=1;i<=n;i++)
		cin >> a[i];
	cin >> s;
	dfs(s);

	cout << accumulate(visited+1, visited + n + 1, 0) << endl;

	return 0;
}
