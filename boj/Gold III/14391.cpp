#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, k, i, j, x, sum, temp, ans = 0;
	cin >> N >> M;
	vector<string> s(N);
	for (i=0;i<N;i++) {
		cin >> s[i];
	}
	// bitmask, 1 == horizontal
	for (k=0;k<1<<(N*M);k++) {
		sum = 0;
		for (i=0;i<N;i++) {
			temp = 0;
			for (j=0;j<M;j++) {
				if (k & (1<<(i*M+j))) {
					temp = temp * 10 + (s[i][j] - '0');
				} else {
					sum += temp;
					temp = 0;
				}
			}
			sum += temp;
		}
		for (j=0;j<M;j++) {
			temp = 0;
			for (i=0;i<N;i++) {
				if (k & (1<<(i*M+j))) {
					sum += temp;
					temp = 0;
				} else {
					temp = temp * 10 + (s[i][j] - '0');
				}
			}
			sum += temp;
		}
		if (sum > ans)
			ans = sum;
	}
	cout << ans << endl;

	return 0;
}
