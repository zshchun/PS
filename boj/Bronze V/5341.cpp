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
	ll n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		cout << n * (n+1) / 2 << endl;
	}
	return 0;
}
