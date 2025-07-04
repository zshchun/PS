#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[11][11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, K, i, j, k, v;
	cin >> N >> K;
	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			cin >> a[i][j];

	for (i=0;i<N*K;i++) {
		for (j=0;j<N*K;j++) {
			cout << a[i/K][j/K] << ' ';
		}
		cout << endl;
	}
	return 0;
}
