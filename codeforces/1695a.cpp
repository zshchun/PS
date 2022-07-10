#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r, ans;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		ll mx = -1e10, x, y;
		for (i=0;i<n;i++) {
			for (j=0;j<m;j++) {
				cin >> z;
				if (z > mx) {
					mx = z;
					y = i+1;
					x = j+1;
				}
			}
		}
		cout << max(x, m-x+1) * max(y, n-y+1) << endl;
	}
	return 0;
}
