#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, N, M, cnt;
	cin >> T;
	while(T--) {
		cin >> N;
		vector<int> v(N);
		cnt=0;
		bool split=false;
		for (i=0;i<N;i++) {
			cin >> v[i];
			if (split && v[i-1] > v[i]) {
				cnt++;
				split = false;
			} else {
				split = true;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
