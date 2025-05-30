#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef pair<uint,uint> pa;
#define endl "\n"
#define INF 123456789
int n, k, ans;
vector<pa> a;
uint t[6];

void backtrack(int x, int s) {
	if (x == a.size()) {
		if (s == k)
			ans++;
		return;
	}
	if (s > k) return;
	int day = a[x].second >> 16;
	int hour = a[x].second & 0xffff;
	backtrack(x+1, s);
	if (!(t[day] & hour)) {
		t[day] |= hour;
		backtrack(x+1, s+a[x].first);
		t[day] &= ~hour;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	uint w, s, e, i;
	cin >> n >> k;
	for (i=0;i<n;i++) {
		cin >> w >> s >> e;
		if (w == 5) continue;
		uint em = (1 << (e+1)) - 1;
		uint sm = -(1<<s);
		uint mask = (w << 16) | (em & sm);
		a.push_back(pa(e - s + 1, mask));
	}
	backtrack(0, 0);
	cout << ans << endl;
	return 0;
}
