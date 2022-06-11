#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define NTH(x) get<2>(p[x])

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<tuple<int,int,int>> p;
	ll T, i, N, m;
	cin >> T;
	while(T--) {
		cin >> N;
		p.resize(N);
		for (i=0;i<N;i++) {
			cin >> get<0>(p[i]);
		}
		for (i=0;i<N;i++) {
			cin >> get<1>(p[i]);
			get<2>(p[i]) = i;
		}
		sort(p.begin(), p.end());
		bool possible = true;
		for (i=1;i<N;i++) {
			if (get<1>(p[i-1]) > get<1>(p[i])) {
				possible = false;
				break;
			}
		}
		if (!possible) {
			cout << "-1\n";
			continue;
		}
		m =0;
		vector<pair<int,int>> a;
		for (i=0;i<N;i++) {
			if (NTH(i) == i) continue;
			for (int j=i;j<N;j++) {
				if (NTH(j) == i) {
					a.push_back(make_pair(NTH(i)+1, NTH(j)+1));
					swap(NTH(i), NTH(j));
					m++;
					break;
				}
			}
		}
		cout << m << '\n';
		for (i=0;i<a.size();i++) {
			cout << a[i].first << " " << a[i].second << '\n';
		}
	}
	return 0;
}
