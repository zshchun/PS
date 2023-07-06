#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string S, T;

	cin >> S >> T;
	while (!T.empty() && S.size() <= T.size()) {
		if (T == S) {
			ans = 1;
			break;
		}
		if (T.back() == 'B') {
			T.pop_back();
			reverse(T.begin(), T.end());
		} else if (T.back() == 'A') {
			T.pop_back();
		}
	}

	cout << ans << endl;

	return 0;
}
