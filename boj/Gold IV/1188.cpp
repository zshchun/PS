#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, i, ans;
	cin >> n >> m;
	if (n % m == 0) {
		cout << "0\n";
		return 0;
	}
	i = gcd(n, m);
	ans = i * (m / i - 1);
	cout << ans << endl;
	
	return 0;
}
