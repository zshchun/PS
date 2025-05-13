#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	char c;
	int i, cnt = 0;
	for (i=0;i<6;i++) {
		cin >> c;
		if (c == 'W')
			cnt++;
	}
	if (cnt >= 5) cout << 1 << endl;
	else if (cnt >= 3) cout << 2 << endl;
	else if (cnt >= 1) cout << 3 << endl;
	else cout << -1 << endl;
	return 0;
}
