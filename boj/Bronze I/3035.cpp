#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int r, c, zr, zc;
char m[51][51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> r >> c >> zr >> zc;
	for (i=0;i<r;i++)
		for (j=0;j<c;j++)
			cin >> m[i][j];

	for (i=0;i<r*zr;i++) {
		for (j=0;j<c*zc;j++) {
			cout << m[i/zr][j/zc];
		}
		cout << endl;
	}

	return 0;
}
