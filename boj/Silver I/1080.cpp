#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N, M;
int a[51][51];
int b[51][51];

void bit_flip(int y, int x) {
	for (int i=y-1;i<=y+1;i++)
		for (int j=x-1;j<=x+1;j++)
			a[i][j] = !a[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, cnt = 0;
	char c;
	cin >> N >> M;
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			cin >> c;
			a[i][j] = c - '0';
		}
	}

	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			cin >> c;
			b[i][j] = c - '0';
		}
	}

	for (i=1;i<N-1;i++) {
		for (j=1;j<M-1;j++) {
			if (a[i-1][j-1] != b[i-1][j-1]) {
				bit_flip(i, j);
				cnt++;
			}
		}
	}
	bool same = true;
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			if (a[i][j] != b[i][j]) {
				same = false;
				break;
			}
		}
	}

	if (same)
		cout << cnt << endl;
	else
		cout << "-1\n";

	return 0;
}
