#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, M, i, x, y;
	cin >> N >> M;
	a[0] = 0;
	for (i=1;i<=N;i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	for (i=1;i<=M;i++) {
		cin >> x >> y;
		cout << (a[y] - a[x-1]) << '\n';
	}
	return 0;
}

