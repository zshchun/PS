#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<ll,ll,ll> tup;
#define INF 123456789
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, x, y, r, start, end, i, j;
	cin >> n;
	vector<pa> ts;
	for (i=0;i<n;i++) {
		cin >> x >> y >> r;
		x = -x;
		start = (x-1) * r;
		end = start + r;
		ts.push_back(pa(start, y));
		ts.push_back(pa(end, -y));
	}
	sort(ts.begin(), ts.end());
	set<ll> status;
	set<ll> ans;
	for (i=0;i<(ll)ts.size();i++) {
		for (j=i;j<(ll)ts.size() && ts[i].first == ts[j].first; j++) {
			if (ts[j].second > 0)
				status.insert(ts[j].second);
			else
				status.erase(-ts[j].second);
		}
		if (!status.empty())
			ans.insert(*status.begin());
	}

	cout << ans.size() << endl;
	return 0;
}
