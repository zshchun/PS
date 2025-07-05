#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll n, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, s, e, d;
	cin >> n;
	vector<pa> a(n);
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (i=0;i<n;i++) {
		cin >> a[i].first >> a[i].second;
		if (a[i].first < a[i].second)
			swap(a[i].first, a[i].second);
	}
	sort(a.begin(), a.end());
	cin >> d;
	for (i=0;i<n;i++) {
		e = a[i].first;
		s = a[i].second;
		if (s < e - d) continue;
		pq.push(s);
		while (!pq.empty() && pq.top() < e - d)
			pq.pop();
		ans = max<size_t>(ans, pq.size());
	}
	cout << ans << endl;
	return 0;
}
