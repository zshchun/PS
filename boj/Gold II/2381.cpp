#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
typedef tuple<ll,pl,pl> tup;
#define endl "\n"
#define INF 1234567890
ll N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, x, y, ans, d;
	cin >> N;
	ll diff_min = INF, sum_min = INF;
	ll diff_max = -INF, sum_max = -INF;
	for (i=0;i<N;i++) {
		cin >> x >> y;
		ll diff = x - y;
		ll sum = x + y;
		diff_min = min(diff_min, diff);
		diff_max = max(diff_max, diff);
		sum_min = min(sum_min, sum);
		sum_max = max(sum_max, sum);
	}

	ans = max(sum_max - sum_min, diff_max - diff_min);
	cout << ans << endl;
	return 0;
}
