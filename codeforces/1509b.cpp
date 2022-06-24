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
		cin >> n;
		string s;
		cin >> s;
		ll t = 0;
		ll m = 0;
		bool ok = true;
		for (i=0;i<n;i++) {
			if (s[i] == 'T')
				t++;
			else if (s[i] == 'M')
				m++;
			if (m > t) {
				ok = false;
				break;
			}
		}
		t = 0; m = 0;
		for (i=n-1;i>=0;i--) {
			if (s[i] == 'T')
				t++;
			else if (s[i] == 'M')
				m++;
			if (m > t) {
				ok = false;
				break;
			}
		}
		if (ok && t == m * 2)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
