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
		ans = 0;
		if (n % 2050ll != 0) {
			cout << "-1\n";
			continue;
		}
		x = n / 2050ll;
		while (x) {
			ans += x % 10;
			x /= 10;
		}
		cout << ans << endl;
	}
	return 0;
}
