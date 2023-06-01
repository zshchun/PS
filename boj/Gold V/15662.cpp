#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int N;
int a[1001];
#define ALL   0
#define LEFT  1
#define RIGHT 2

void rotate(int x, int y, int d) {
	if (x > 1 && (d == ALL || d == LEFT)) {
		if ((a[x] & 0x2) != ((a[x-1] & 0x20) >> 4))
			rotate(x-1, -y, LEFT);
	}
	if (x < N && (d == ALL || d == RIGHT)) {
		if (((a[x] & 0x20) >> 4) != (a[x+1] & 0x2))
			rotate(x+1, -y, RIGHT);
	}
	if (y == 1)
		a[x] = ((a[x] & 1) << 7) | (a[x] >> 1);
	else if (y == -1)
		a[x] = ((a[x] << 1) & 0xff) | (a[x] >> 7);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int K, i, j, q, w;
	char c;
	cin >> N;
	for (i=1;i<=N;i++) {
		for (j=0;j<8;j++) {
			cin >> c;
			a[i] = (a[i] << 1) | (c - '0');
		}
	}

	cin >> K;
	for (i=0;i<K;i++) {
		cin >> q >> w;
		rotate(q, w, ALL);
	}

//	for (i=1;i<=N;i++) {
//		for (j=7;j>=0;j--)
//			cout << (a[i] & (1<<j) ? '1' : '0');
//		cout << endl;
//	}

	int ans = 0;
	for (i=1;i<=N;i++) {
		if (a[i] & 128)
			ans++;
	}
	cout << ans << endl;

	return 0;
}
