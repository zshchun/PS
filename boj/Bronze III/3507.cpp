#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ate, i, j;
	cin >> ate;
	for (i=0;i<100;i++) {
		for (j=0;j<100;j++) {
			if (ate - i - j == 0)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
