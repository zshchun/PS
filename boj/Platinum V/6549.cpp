#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll w, h, n, ans;

ll a[100001];
stack<ll> s;

void solve(ll i) {
	h = a[s.top()];
	s.pop();
	if (s.empty())
		w = i;
	else
		w = i - s.top() - 1;
	ans = max(ans, h * w);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i;
	while (1) {
		cin >> n;
		if (n == 0) break;
		s = stack<ll>();
		ans = 0;
		for (i=0;i<n;i++)
			cin >> a[i];
		for (i=0;i<n;i++) {
			while (!s.empty() && a[i] < a[s.top()])
				solve(i);
			s.push(i);
		}
		while (!s.empty())
			solve(n);
		cout << ans << endl;
	}
	return 0;
}
