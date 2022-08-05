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
		cin >> n >> m;
		ans = 0;
		ll diff = max(1ll, abs(m-n));
		while (n>0 || m>0) {
			for (i=0;i<diff && i < n;i++)
				cout << '0';
			n -= i;
			for (i=0;i<diff && i < m;i++)
				cout << '1';
			m -= i;
		}
		cout << endl;
	}
	return 0;
}
