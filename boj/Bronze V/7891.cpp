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
	ll x, y, n, i;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> x >> y;
		cout << x + y << endl;
	}
	return 0;
}
