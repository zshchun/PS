#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int ans, n, m;
int days[20];
int pages[20];

void dfs(int cur, int remain, int total) {
	if (total > ans)
		ans = total;
	if (cur >= m) return;
	if (days[cur] <= remain)
		dfs(cur+1, remain - days[cur], total + pages[cur]);
	dfs(cur+1, remain, total);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0;i<m;i++)
		cin >> days[i] >> pages[i];
	dfs(0, n, 0);
	cout << ans << endl;
	return 0;
}
