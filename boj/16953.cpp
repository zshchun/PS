#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define INF 1234567891
ll B, ans=INF;
void dfs(ll a, ll n) {
	if (a == B) {
		ans = n;
		return;
	}
	if (a > B) return;
	dfs(a*2, n+1);
	dfs(a*10+1, n+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll a;
	cin >> a >> B;
	dfs(a, 0);
	if (ans == INF)
		cout << "-1\n";
	else
		cout << ans+1 << '\n';
	return 0;
}

