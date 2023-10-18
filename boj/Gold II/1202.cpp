#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll N, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll m, v, i;
	cin >> N >> K;
	deque<pa> mv;
	for (i=0;i<N;i++) {
		cin >> m >> v;
		mv.push_back(pa(m, v));
	}
	sort(mv.begin(), mv.end());
	vector<ll> a(K);
	for (i=0;i<K;i++)
		cin >> a[i];
	sort(a.begin(), a.end());

	priority_queue<ll> pq;
	ll ans = 0;
	for (ll x : a) {
		while (!mv.empty() && mv.front().first <= x) {
			tie(m, v) = mv.front();
			mv.pop_front();
			pq.push(v);
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans << endl;

	return 0;
}
