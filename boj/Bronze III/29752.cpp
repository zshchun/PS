#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i, v, ans = 0, streak = 0;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> v;
		if (v == 0)
			streak = 0;
		else
			streak++;
		ans = max(ans, streak);
	}

	cout << ans << endl;

	return 0;
}
