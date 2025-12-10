#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 1234567890
ll ans = INF;
unordered_set<ll> visited;

ll abc(ll a, ll b, ll c) {
	return (c << 40) | (b << 20) | a;
}

bool is_visited(ll v, ll cnt) {
	if (visited.find(v) != visited.end())
		return true;
	visited.insert(v);
	return false;
}

bool check(ll a, ll b, ll c) {
	while (a) {
		if ((a & 3) != 1)
			return false;
		a >>= 2;
	}
	while (b) {
		if ((b & 3) != 2)
			return false;
		b >>= 2;
	}
	while (c) {
		if ((c & 3) != 3)
			return false;
		c >>= 2;
	}
	return true;
}

void bfs(ll start) {
	queue<pa> q;
	q.push(pa(start, 0));
	ll v, cnt;

	while(!q.empty()) {
		tie(v, cnt) = q.front();
		q.pop();

		ll c = (v >> 40) & 0xfffff;
		ll b = (v >> 20) & 0xfffff;
		ll a = v & 0xfffff;
		ll nv;

		if (is_visited(v, cnt))
			continue;

		if (check(a, b, c)) {
			ans = cnt;
			ans = min(ans, cnt);
			break;
		}

		if (a) {
			nv = abc(a >> 2, (b << 2) | (a & 3), c);
			q.push(pa(nv, cnt+1));
			nv = abc(a >> 2, b, (c << 2) | (a & 3));
			q.push(pa(nv, cnt+1));
		}
		if (b) {
			nv = abc((a << 2) | (b & 3), b >> 2, c);
			q.push(pa(nv, cnt+1));
			nv = abc(a, b >> 2, (c << 2) | (b & 3));
			q.push(pa(nv, cnt+1));
		}
		if (c) {
			nv = abc((a << 2) | (c & 3), b, c >> 2);
			q.push(pa(nv, cnt+1));
			nv = abc(a, (b << 2) | (c & 3), c >> 2);
			q.push(pa(nv, cnt+1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k, n, v[3] = {0, };
	char ch;
	for (i=0;i<3;i++) {
		cin >> n;
		for (j=0;j<n;j++) {
			cin >> ch;
			if (ch == 'A')
				v[i] = (v[i] << 2) | 1ull;
			else if (ch == 'B')
				v[i] = (v[i] << 2) | 2ull;
			else if (ch == 'C')
				v[i] = (v[i] << 2) | 3ull;
		}
	}
	bfs(abc(v[0], v[1], v[2]));
	cout << ans << endl;
	return 0;
}
