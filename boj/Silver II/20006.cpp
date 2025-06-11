#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
int p, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, x, lv;
	string n, nick;
	cin >> p >> m;
	using pa_is = vector<pair<string, int>>;
	list<pair<int, pa_is >> a;
	for (i=0;i<p;i++) {
		cin >> x >> n;
		bool found = false;
		for (auto it=a.begin();it != a.end();it++) {
			lv = (*it).first;
			if ((*it).second.size() >= m)
				continue;
			if (lv-10 <= x && x <= lv+10) {
				(*it).second.push_back({n, x});
				found = true;
				break;
			}
		}
		if (!found)
			a.push_back({x, {{n, x}} });
	}
	for (auto &t : a) {
		pa_is q = t.second;
		if (q.size() >= m)
			cout << "Started!\n";
		else
			cout << "Waiting!\n";
		sort(q.begin(), q.end());
		for (auto &w: q)
			cout << w.second << ' ' << w.first << endl;
	}

	return 0;
}
