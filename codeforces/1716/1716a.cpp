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
		cin >> n;
		if ((n % 3) == 0) {
			cout << (n / 3) << endl;
			continue;
		} else if (n == 1 || n == 4) {
			cout << 2 << endl;
		} else if (n == 2) {
			cout << 1 << endl;
		} else if ((n % 3)) {
			cout << ((n / 3) + 1) << endl;
		}
	}
	return 0;
}
