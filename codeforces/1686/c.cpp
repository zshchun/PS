#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, N, M;
	cin >> T;
	while(T--) {
		cin >> N;
		vector<int> v(N), r;
		for (i=0;i<N;i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		for (i=0;i<N/2;i++) {
			r.emplace_back(v[i]);
			r.emplace_back(v[i+N/2]);
		}
		if (N%2)
			r.emplace_back(v[N-1]);
		bool yes = true;
		for (i=1;i<N-1;i++) {
			if ((r[i-1] < r[i] && r[i] > r[i+1]) || (r[i-1] > r[i] && r[i] < r[i+1])) continue;
			else {
				yes = false;
				break;
			}
		}
		if (yes) {
			cout << "YES" << endl;
			for (int &x: r) {
				cout << x << " ";
			}
			cout << endl;
		} else {
			cout << "NO" << endl;
		}

	}
	return 0;
}
