#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, N;
	cin >> T;
	while(T--) {
		cin >> N;
		int x = 31-__builtin_clz(N);
		cout <<((1<<x)-1)<<'\n';
	}
	return 0;
}
