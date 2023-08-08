#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int M, N, i, x, r, ans = 0;
	cin >> M >> N;
	r = 0;
	for (i=0;i<N;i++) {
		cin >> x;
		cout << x << endl;
		ans += x;
		r += x % M;
	}
	if (r % M == 0) {
		cout << (ans / M) << endl;
	} else {
		cout << "0\n";
	}
	return 0;
}
