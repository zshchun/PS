#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//int a[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, N, i, v, c;
	cin >> T;
	vector<int> a;
	vector<int> b;
	while (T--) {
		a.clear();
		b.clear();
		cin >> N;
		a.reserve(N+1);
		for (i=0;i<N;i++) {
			cin >> v;
			a.push_back(v);
		}
		sort(a.begin(), a.end());
//		unique(a.begin(), a.end());
		for (c=0,i=0;i<N;i++,c++) {
			if (i+1 < N && a[i] == a[i+1]) {
				b.push_back(a[i]);
				continue;
			}
			if (i) cout << ' ';
			cout << a[i];
		}
		for (i=0;i<b.size();i++,c++) {
			if (c) cout << ' ';
			cout << b[i];
		}
		cout << '\n';
	}
	return 0;
}
