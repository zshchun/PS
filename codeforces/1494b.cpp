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
		ll u, r, d, l;
		cin >> n >> u >> r >> d >> l;
		
		for (i=0;i<1<<4;i++) {
			ll uu=u, rr=r, dd=d, ll=l;
			if (i&1) { uu--; ll--; }
			if (i&2) { uu--; rr--; }
			if (i&4) { dd--; rr--; }
			if (i&8) { dd--; ll--; }
			if (uu>n-2 || uu<0) continue;
			if (ll>n-2 || ll<0) continue;
			if (dd>n-2 || dd<0) continue;
			if (rr>n-2 || rr<0) continue;
			break;
		}
		if (i == 1<<4)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}
