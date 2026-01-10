#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll n, ans;
vector<ll> a;

bool check(ll x) {
	for (ll &v : a)
		if ((x % v) != 0)
			return false;
	return true;
}

void bfs() {
	queue<ll> q;
	q.push(n);
	while (!q.empty()) {
		ll cur = q.front();
		q.pop();
		if (check(cur)) {
			ans = cur;
			break;
		}
		for (ll i=0;i<=9;i++)
			q.push(cur * 10ull + i);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j;
	cin >> n;
	ans = j = n;
	while (j) {
		if (j % 10 > 0)
			a.push_back(j % 10);
		j /= 10;
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	bfs();
	cout << ans << endl;
	return 0;
}
