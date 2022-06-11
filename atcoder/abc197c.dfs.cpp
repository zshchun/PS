#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[30];
ll N;
ll mn = 1LL<<50;
void dfs(ll i, ll o, ll x) {
	if (i == N) {
		mn = min(mn, x^o);
	} else {
		dfs(i+1, o|a[i], x);
		dfs(i+1, a[i], x^o);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i;
	cin>>N;
	for(i=0;i<N;i++) cin>>a[i];
	dfs(0, 0, 0);
	cout << mn << '\n';
	return 0;
}
