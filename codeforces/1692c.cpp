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
		ll ansr = 0, ansc = 0;
		string s[8];
		vector<ll> r(8, 0), c(8, 0);
		for (j=0;j<8;j++) {
			cin >> s[j];
		}
		bool ok = false;
		for (j=2;j<8 && !ok;j++) {
			for (k=2;k<8 && !ok;k++) {
				if (s[j][k] == '#' && s[j][k-2] == '#' && s[j-2][k] == '#' && s[j-2][k-2] == '#') {
					ok = true;
					ansr = j;
					ansc = k;
					break;
				}

			}
		}
		cout << ansr << ' ' << ansc << endl;
	}
	return 0;
}
