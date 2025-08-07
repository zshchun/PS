#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, b;
	char ans = 'S';
	for (i=0;i<8;i++) {
		cin >> b;
		if (b == 9) {
			ans = 'F';
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
