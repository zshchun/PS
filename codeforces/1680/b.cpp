#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		string s;
		ll first = -1;
		bool ok = true;
		for (i=0;i<n;i++) {
			cin >> s;
			for (j=0;j<m;j++) {
				if (s[j] == 'R') {
					if (first == -1)
						first = j;
					else if (j < first)
						ok = false;
				}
			}
		}
		if (!ok || first == -1)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}
