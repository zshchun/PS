#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, i, j, N, v;
	char c;
	cin >> T;
	multiset<int> m;
	multiset<int>::iterator it;
	for (i=0;i<T;i++) {
		cin >> N;
		m.clear();
		for (j=0;j<N;j++) {
			cin >> c >> v;
			if (c == 'I') {
				m.insert(v);
			} else if (c == 'D') {
				if (abs(v) >= m.size()) {
					m.clear();
				} else if (v < 0) {
					while (!m.empty() && v++) m.erase(m.begin());
				} else if (v > 0) {
					it = m.end();
					--it;
					while (!m.empty() && v--) m.erase(it);
				}
			}
		}
		if (!m.empty()) {
			it = m.end();
			--it;
			cout << *it << " " << *m.begin() << '\n';
		} else
			cout << "EMPTY\n";
	}
	return 0;
}
