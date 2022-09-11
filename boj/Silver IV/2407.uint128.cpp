#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> P;

string ncr(ull n, ull r) {
	__uint128_t i, p = 1;
	for (i=1;i<=r;i++) {
		p *= n - i + 1;
		p /= i;
	}

	string ans;
	while (p) {
		ans += (p % 10) + '0';
		p /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ull n, m;
	cin >> n >> m;
	cout << ncr(n, m) << '\n';
	return 0;
}
