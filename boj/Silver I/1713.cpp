#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, K, i, v;
	cin >> N >> K;
	vector<pa> a;

	for (i=0;i<K;i++) {
		cin >> v;

		bool found = false;
		for (pa &p: a) {
			if (p.first == v) {
				p.second++;
				found = true;
			}
		}

		if (!found) {
			if (a.size() >= N) {
				ll low = INF;
				vector<pa>::iterator lowest;
				for (vector<pa>::iterator it=a.begin();it!=a.end();it++) {
					if (low > it->second) {
						lowest = it;
						low = it->second;
					}
				}
				a.erase(lowest);
			}
			a.push_back(make_pair(v, 1));
		}

	}

	sort(a.begin(), a.end(), [&](const pa &lhs, const pa &rhs) {
		return lhs.first < rhs.first;
	});

	for (pa x : a)
		cout << x.first << ' ';
	cout << endl;

	return 0;
}
