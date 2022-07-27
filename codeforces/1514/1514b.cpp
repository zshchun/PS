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
		cin >> n >> k;
		ans = 1;
		for (i=0;i<k;i++) {
			ans = ans * n % 1000000007ll;
		}
		cout << ans << endl;
	}
	return 0;
}
