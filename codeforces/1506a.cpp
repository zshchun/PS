#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, n, m, a;
	cin >> T;
	while(T--) {
		cin >> n>>m>>a;
		cout << (((a-1)%n)*m+1) + (a-1)/n << '\n';
//		cout << ((a-1)/m)*m+1 + (a-1)%m << '\n';
	}
	return 0;
}
