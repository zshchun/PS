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
	double sum;
	cin >> T;
	while(T--) {
		cin >> N;
		vector<int> v(N);
		sum = 0;
		for (i=0;i<N;i++) {
			cin >> v[i];
			sum += v[i];
		}
		for (i=0;i<N;i++) {
			if ((sum - v[i]) / (N-1) == v[i]) {
				cout << "YES" << endl;
				break;
			}
		}
		if (i == N) cout << "NO" << endl;
	}
	return 0;
}
