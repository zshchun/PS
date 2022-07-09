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
	ll T, i, j, k, x, l, r, ans;
	cin >> T;
	while(T--) {
		cin >> n;
		cout << 2 << endl;
		for (i=1;i<=n;i++) {
			if (i%2 == 0) continue;
			x = i;
			while (x <= n) {
				cout << x << ' ';
				x *= 2;
			}
		}
		cout << endl;
	}
	return 0;
}
