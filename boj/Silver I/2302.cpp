#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M, ans;
bool used[41];

void dfs(int cur) {
	if (cur >= N-1) {
		ans++;
		return;
	}
	if (!used[cur] && !used[cur+1]) {
		used[cur] = 1;
		used[cur+1] = 1;
		dfs(cur+1);
		used[cur] = 0;
		used[cur+1] = 0;
	}
	dfs(cur+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N >> M;

	for (i=0;i<M;i++) {
		cin >> j;
		j--;
		used[j] = 1;
	}
	dfs(0);

	cout << ans << endl;

	return 0;
}
