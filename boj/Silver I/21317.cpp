#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, k, ans = INF;
int a[21];
int b[21];

void dfs(int x, int y, int used) {
	if (x == N - 1)
		ans = min(ans, y);
	if (x >= N - 1)
		return;

	dfs(x+1, y+a[x], used);
	dfs(x+2, y+b[x], used);
	if (!used)
		dfs(x+3, y+k, 1);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;

	cin >> N;
	for (i=0;i<N-1;i++)
		cin >> a[i] >> b[i];

	cin >> k;
	
	dfs(0, 0, 0);

	cout << ans << endl;

	return 0;
}
