#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
ll n, m;
string s, t;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, x, ans;
	cin >> T;
	while(T--) {
		cin >> n;
		cin >> s >> t;
		string sac, tac;
		vector<ll> sb(1, 0), tb(1, 0);
		bool ok = true;
		for (i=0;i<n;i++) {
			if (s[i] == 'b') {
				sb.back()++;
			} else {
				sac.push_back(s[i]);
				sb.push_back(0);
			}
			if (t[i] == 'b') {
				tb.back()++;
			} else {
				tac.push_back(t[i]);
				tb.push_back(0);
			}
		}
		ll ss = 0;
		for (i=0;i<sb.size()-1;i++) { 
			ss += sb[i] - tb[i];
			if (ss > 0 && sac[i] == 'a') {
				ok = false;
				break;
			} else if (ss < 0 && sac[i] == 'c') {
				ok = false;
				break;
			}
		}
		if (ok && sac == tac)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
