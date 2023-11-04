#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 12345678912345ULL
ll N, S;
int a[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, l, r, sum, ans = INF;
	cin >> N >> S;
	for (i=0;i<N;i++)
		cin >> a[i];
	l = 0;
	r = 0;
	sum = 0;
	while (l < N) {
		while (sum < S && r < N) {
			sum += a[r];
			r++;
		}
		if (sum >= S && ans > r - l) {
			ans = r - l;
		}
		sum -= a[l];
		l++;
	}
	if (ans == INF)
		cout << "0\n";
	else
		cout << ans << endl;
	return 0;
}
