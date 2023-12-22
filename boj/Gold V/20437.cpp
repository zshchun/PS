#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, N, i, l, r, k;
	string s;
	cin >> T;
	while (T--) {
		cin >> s >> N;
		int ans1 = INF, ans2 = 0;
		vector<int> a[26];
		for (int i=0;i<(int)s.size();i++) {
			int j = s[i] - 'a';
			a[j].push_back(i);
			if ((int)a[j].size() >= N) {
				int x = a[j].back();
				int y = a[j][a[j].size()-N];
				int sum = x - y+1;

				ans1 = min(ans1, sum);
				ans2 = max(ans2, sum);
			}
		}
		if (ans1 == INF || ans2 == 0)
			cout << "-1\n";
		else
			cout << ans1 << ' ' << ans2 << endl;

	}
	return 0;
}
