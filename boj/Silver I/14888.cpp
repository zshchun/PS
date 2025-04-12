#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 1234567890123ULL

enum {
	PLUS = 0,
	MINUS,
	MULT,
	DIV,
	NR_OPS,
};

ll N, mn = INF, mx = -INF;
ll op[NR_OPS];
ll a[12];

void backtrack(ll n, ll sum) {
	ll next_sum, i;
	if (n == N) {
		mn = min(mn, sum);
		mx = max(mx, sum);
		return;
	}

	for (i=0;i<NR_OPS;i++) {
		if (op[i] <= 0) continue;
		op[i]--;
		if (i == PLUS)
			next_sum = sum + a[n];
		else if (i == MINUS)
			next_sum = sum - a[n];
		else if (i == MULT)
			next_sum = sum * a[n];
		else if (i == DIV)
			next_sum = sum / a[n];
		backtrack(n+1, next_sum);
		op[i]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j;
	cin >> N;
	for (i=0;i<N;i++)
		cin >> a[i];
	for (i=0;i<NR_OPS;i++)
		cin >> op[i];

	backtrack(1, a[0]);

	cout << mx << endl;
	cout << mn << endl;

	return 0;
}
