#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, i, s1, e1, s2, e2, ans = 0;
	cin >> N;
	list<pa> v;

	for (i=0;i<N;i++) {
		cin >> s1 >> e1;
		v.push_back({s1, e1});
	}

	auto cur = v.begin();

	while (cur != v.end()) {
		auto next = cur;
		next++;
		if (next == v.end()) break;
		s1 = (*cur).first;
		e1 = (*cur).second;
		s2 = (*next).first;
		e2 = (*next).second;
		if (s2 <= e1) {
			(*cur).second = max(e1, e2);
			v.erase(next);
		} else {
			++cur;
		}
	}

	for (pa &p : v)
		ans += p.second - p.first;

	cout << ans << endl;

	return 0;
}
