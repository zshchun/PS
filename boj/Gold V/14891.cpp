#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
int a[4], b[4], N, D, K;

void rotate(int n, int d) {
	if (d == 1) {
		a[n] = ((a[n] << 1) & 0xff) | ((a[n] >> 7) & 1);
	} else if (d == -1) {
		a[n] = (a[n] >> 1) | ((a[n] & 1) << 7);
	}
}

bool right_cog(int n) {
	return (b[n] >> 2) & 1;
}

bool left_cog(int n) {
	return (b[n] >> 6) & 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, d, score, ans = 0;
	string s;
	for (i=0;i<4;i++) {
		cin >> s;
		for (j=0;j<8;j++) {
			a[i] |= (s[j] - '0') << j;
		}
	}

	cin >> K;
	for (i=0;i<K;i++) {
		cin >> N >> D;
		N--;

		memcpy(b, a, sizeof(b));

		rotate(N, D);
		d = D;
		for (j=N-1;j>=0;j--) {
			d = d * -1;
			if (right_cog(j) != left_cog(j+1))
				rotate(j, d);
			else
				break;
		}

		d = D;
		for (j=N+1;j<4;j++) {
			d = d * -1;
			if (right_cog(j-1) != left_cog(j))
				rotate(j, d);
			else
				break;
		}
	}
	score = 1;
	for (i=0;i<4;i++) {
		if (a[i] & 1)
			ans += score;
		score <<= 1;
	}
	cout << ans << endl;
	return 0;
}
