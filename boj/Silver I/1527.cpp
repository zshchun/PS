#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll A, B, ans;

void backtrack(ll c) {
	if (c > B) return;
	if (c >= A)
		ans++;
	backtrack(c * 10 + 4);
	backtrack(c * 10 + 7);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B;

	backtrack(0);
	cout << ans << endl;

	return 0;
}
