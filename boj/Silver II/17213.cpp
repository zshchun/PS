#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int n, m, ans;

void backtrack(int x, int sum) {
	if (x == n-1) {
		ans++;
		return;
	}
	int r = n - x - 1;
	for (int i=1;i<=m-sum-r;i++) {
		backtrack(x+1, sum+i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	backtrack(0, 0);
	cout << ans << endl;
	return 0;
}
