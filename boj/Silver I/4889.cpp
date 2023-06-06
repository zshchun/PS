#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int ans;
string s;

void dfs(int n, int m, int sum) {
	if (n >= s.size()) {
		m += sum / 2;
		if (m < ans)
			ans = m;
		return;
	}
	if (s[n] == '{') {
		dfs(n+1, m, sum+1);
	} else {
		if (sum-1 < 0)
			dfs(n+1, m+1, sum+1);
		else
			dfs(n+1, m, sum-1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int idx = 1;
	cin >> s;
	while (s[0] != '-') {
		ans = INF;
		dfs(0, 0, 0);
		cout << idx << ". " << ans << endl;
		idx++;
		cin >> s;
	}

	return 0;
}
