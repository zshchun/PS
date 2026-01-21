#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M, ans;
deque<int> a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, v, cnt, mn, mx, l, r, m, alen, blen;
	cin >> N >> M;
	for (i=0;i<N;i++) {
		cin >> v;
		if (v > 0)
			a.push_back(v);
		else
			b.push_back(v);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	alen = min((int)a.size(), M);
	blen = min((int)b.size(), M);
	l = *max_element(a.end()-alen, a.end());
	r = *min_element(b.begin(), b.begin()+blen);
	if (l > abs(r)) {
		ans += l;
		a.erase(a.end()-alen, a.end());
	} else {
		ans += abs(r);
		b.erase(b.begin(), b.begin()+blen);
	}

	while (!a.empty()) {
		cnt = mx = 0;
		while (!a.empty() && cnt < M) {
			mx = max(a.back(), mx);
			a.pop_back();
			cnt++;
		}
		ans += mx * 2;
	}
	while (!b.empty()) {
		cnt = mn = 0;
		while (!b.empty() && cnt < M) {
			mn = min(b.front(), mn);
			b.pop_front();
			cnt++;
		}
		ans += abs(mn) * 2;
	}
	cout << ans << endl;

	return 0;
}
