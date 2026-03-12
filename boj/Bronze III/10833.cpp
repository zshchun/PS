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
	int N, i, a, b;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> a >> b;
		ans += b % a;
	}
	cout << ans << endl;
	return 0;
}
