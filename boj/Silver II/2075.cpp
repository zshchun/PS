#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, N;
	cin >> N;

	vector<int> a(N*N);
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			cin >> a[N*i+j];
		}
	}

	sort(a.begin(), a.end());
	cout << a[(N*N)-N] << endl;

	return 0;
}
