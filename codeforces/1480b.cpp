#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, x, ans;
	cin >> T;
	while(T--) {
		ll hp, ap;
		cin >> ap >> hp >> n;
		ans = 0;
		vector<pl> a(n);
		for (i=0;i<n;i++)
			cin >> a[i].first;
		for (i=0;i<n;i++)
			cin >> a[i].second;
		sort(a.begin(), a.end(), [&](const pl lhs, const pl rhs) {
			if (lhs.second == lhs.second) return lhs.first < rhs.first;
			else return lhs.second < rhs.second;
		});
		ll map=0, mhp=0;
		for (i=0;i<n && hp;i++) {
			map = a[i].first;
			mhp = a[i].second;
			ll t = (mhp+ap-1) / ap;
			hp -= t * map;
		}
		if (i == n && hp > -map)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
