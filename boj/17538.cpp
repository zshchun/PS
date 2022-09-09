#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define INF 123456789
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, K, i, j, x, card_min, min_idx, ans;
	char c;
	cin >> N >> K;
	K--;
	vector<vector<ll>> deck(N, vector<ll>(14));
	for (i=0;i<N;i++) {
		for (j=0;j<4;j++) {
			cin >> c;
			if (c <= '9') x = c - '0';
			else if (c == 'A') x = 1;
			else if (c == 'D') x = 10;
			else if (c == 'Q') x = 11;
			else if (c == 'J') x = 12;
			else if (c == 'K') x = 13;
			deck[i][x]++;
		}
	}
	deck[K][0] = 1;

	auto check = [&]() -> ll {
		ll ret = 0;
		ll min_value = INF;
		for (ll i=0;i<N;i++) {
			ll total = accumulate(deck[i].begin(), deck[i].end(), 0ll);
			if (total != 4) continue;
			for (ll j=1;j<=13;j++) {
				if (deck[i][j] == 4 && j < min_value) {
					min_value = j;
					ret = i + 1;
				}
			}
		}
		return ret;
	};
	ll turn = 1;
	for (i=K;;i=(i+1)%N, turn++) {
		ans = check();
		if (ans) break;
		card_min = INF;
		for (j=1;j<=13;j++) {
			if (deck[i][j] == 0) continue;
			if (deck[i][j] < card_min) {
				card_min = deck[i][j];
				min_idx = j;
			}
		}
		if (deck[i][0] && deck[i][0] < turn) {
			deck[i][0] = 0;
			deck[(i+1)%N][0] = turn+1;
		} else {
			deck[i][min_idx]--;
			deck[(i+1)%N][min_idx]++;
		}
	}
	cout << ans << '\n';
	return 0;
}
