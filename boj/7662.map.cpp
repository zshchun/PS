#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<int,int> &lhs, const pair<int,int> &rhs) {
	return lhs.first < rhs.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<int,int> m;
	int T, i, j, N, v, cnt;
	char c;
	cin >> T;
	map<int,int>::iterator it;
	for (i=0;i<T;i++) {
		cin >> N;
		m.clear();
		cnt = 0;
		for (j=0;j<N;j++) {
			cin >> c >> v;
			if (c == 'I') {
				if (m.count(v)) {
					m[v]++;
					cnt++;
				} else {
					m.insert(make_pair(v, 1));
					cnt++;
				}
			} else if (c == 'D') {
				if (abs(v) >= m.size()) {
					m.clear();
					cnt = 0;
				} else if (v < 0) {
					it = m.begin();
					while (v) {
						it->second
					}

				} else if (v > 0) {
					for (it=m.end();it != m.begin() && v;--it,--v) { ; }
					m.erase(it, m.end());
				}
			}
		}
		if (!m.empty())
			cout << m.back() << " " << m.front() << '\n';
		else
			cout << "EMPTY\n";
	}
	return 0;
}
