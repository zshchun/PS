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
		cin >> k;
		ans = 0;
		if (k >= 1900)
			ans = 1;
		else if (k >= 1600)
			ans = 2;
		else if (k >= 1400)
			ans = 3;
		else
			ans = 4;
		cout << "Division " << ans << endl;
	}
	return 0;
}
