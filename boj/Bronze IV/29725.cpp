#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, ans = 0;
	char c;
	for (i=0;i<8;i++) {
		for (j=0;j<8;j++) {
			cin >> c;
			switch (c) {
				case 'P': ans += 1; break;
				case 'N': ans += 3; break;
				case 'B': ans += 3; break;
				case 'R': ans += 5; break;
				case 'Q': ans += 9; break;
				case 'p': ans -= 1; break;
				case 'n': ans -= 3; break;
				case 'b': ans -= 3; break;
				case 'r': ans -= 5; break;
				case 'q': ans -= 9; break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
