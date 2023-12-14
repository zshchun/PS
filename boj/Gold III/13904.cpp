#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int i, j, d, w, ans = 0;
	vector<pa> a;
	for (i=0;i<N;i++) {
		cin >> d >> w;
		a.push_back(pa(d, w));
	}
	sort(a.begin(), a.end(), [&](const pa &lhs, const pa &rhs) {
		if (lhs.second == rhs.second)
			return lhs.first < rhs.first;
		return lhs.second > rhs.second;
	});
	for (i=N;i>0;i--) {
		if (a.empty()) break;
		for (auto it=a.begin();it != a.end(); it++) {
			if (it->first >= i) {
				ans += it->second;
				a.erase(it);
				break;
			}
		}
	}
	cout << ans << endl;

	return 0;
}
