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
	ll n, i, v;
	__int128 s;
	while (cin >> n) {
		s = 0;
		for (i=0;i<n;i++) {
			cin >> v;
			s += v;
		}
		if (s > 0)
			cout << "+\n";
		else if (s < 0)
			cout << "-\n";
		else
			cout << "0\n";
	}
	return 0;
}
