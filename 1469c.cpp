#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
ll n, m;

ll h[200001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, ans=0;
	ll k, mg, mh;
	cin >> T;
	while(T--) {
		cin >> n >> k;
		for (i=0;i<n;i++)
			cin >> h[i];
		mg = mh = h[0];
		for (i=1;i<n;i++) {
			mg = max(mg-k+1, h[i]);
			mh = min(mh+k-1, h[i]+k-1);
			if (mg > mh) break;
		}
		if (i == n && h[n-1] >= mg && h[n-1] <= mh)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
