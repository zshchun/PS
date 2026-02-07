#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, F, i, j;
	cin >> N >> F;
	j = N % 100;
	N -= j;
	for (i=0;i<100;i++) {
		if ((N + i) % F == 0) {
			cout << setfill('0') << setw(2) << i << endl;
			break;
		}
	}

	return 0;
}
