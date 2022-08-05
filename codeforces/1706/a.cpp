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
		ans = 0;
		vector<char> a(m+1, 'B');
		for (i=0;i<n;i++) {
			cin >> z;
			ll mx = max(z, m+1-z);
			ll mn = min(z, m+1-z);
			if (a[mn] == 'B')
				a[mn] = 'A';
			else if (a[mx] == 'B')
				a[mx] = 'A';
		}
		for (i=1;i<=m;i++) {
			cout << a[i];
		}
		cout << endl;
	}
	return 0;
}
