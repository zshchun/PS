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
	int T, i;
	cin >> T;
	while (T--) {
		int y, k;
		int a[2] = {0, };
		for (i=0;i<9;i++) {
			cin >> y >> k;
			a[0] += y;
			a[1] += k;
		}
		if (a[0] > a[1])
			cout << "Yonsei\n";
		else if (a[0] < a[1])
			cout << "Korea\n";
		else
			cout << "Draw\n";
	}
	return 0;
}
