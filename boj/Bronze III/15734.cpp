#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int l, r, a, x, prev = INF;
	cin >> l >> r >> a;
	while (a) {
		if (l > r)
			r++;
		else 
			l++;
		a--;
	}
	cout << min(l, r) * 2 << endl;
	return 0;
}
