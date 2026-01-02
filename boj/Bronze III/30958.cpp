#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int ans;
int a[256];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i;
	char c;
	cin >> n;
	while (cin >> c) {
		if ('a' <= c && c <= 'z') {
			a[c]++;
			ans = max(ans, a[c]);
		}
	}
	cout << ans << endl;
	return 0;
}
