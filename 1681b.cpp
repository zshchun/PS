#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n[200001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, N, M, v, sum;
	cin >> T;
	while(T--) {
		sum=0;
		cin >> N;
		for (i=0;i<N;i++) {
			cin >> n[i];
		}
		cin >> M;
		for (i=0;i<M;i++) {
			cin >> v;
			sum = (sum + v) % N;
		}
		cout << n[sum] << '\n';
	}
	return 0;
}
