#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, ans=-1e18, v, n[3];
	vector<int> a[3];
	ll s[3];
	for (i=0;i<3;i++)
		cin >> n[i];
	for (i=0;i<3;i++) {
		a[i].clear();
		for (j=0;j<n[i];j++) {
			cin >> v;
			a[i].push_back(v);
		}
		sort(a[i].begin(), a[i].end());
	}
	for (k=0;k<3;k++) {
		if (k>0) swap(a[0], a[k]);
		for (i=0;i<3;i++) {
			ll s0=0, s1=0, s2=0, m1=a[1][0], m2=a[2][0];
			s0 = accumulate(a[0].begin(), a[0].end(), 0ll);
			s1 = accumulate(a[1].begin()+1, a[1].end(), 0ll);
			s2 = accumulate(a[2].begin()+1, a[2].end(), 0ll);
			s0 += max({s1-m1-m2+s2, s1+m1-s2-m2, s2+m2-s1-m1});
			ans = max(ans, s0);
		}
	}

	cout << ans << endl;
	return 0;
}
