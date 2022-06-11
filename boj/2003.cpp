#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int d[10000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, N, M;
	cin >> N >> M;
	for (i=0;i<N;i++) {
		cin >> d[i];
	}
	int ans = 0, acc = 0, s = 0, e = 0;
	while (1) {
		if (acc >= M)
			acc -= d[s++];
		else if (e >= N)
			break;
		else
			acc += d[e++];
		if (acc == M)
			ans++;
	}
	cout << ans << '\n';
	return 0;
}

