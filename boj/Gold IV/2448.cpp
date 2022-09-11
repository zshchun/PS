#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

char c[3072][6144];
int N;
void star(int n, int y, int x) {
	if (n == 3) {
		c[y][x] = '*';
		c[y+1][x-1] = '*';
		c[y+1][x+1] = '*';
		c[y+2][x-2] = '*';
		c[y+2][x-1] = '*';
		c[y+2][x+0] = '*';
		c[y+2][x+1] = '*';
		c[y+2][x+2] = '*';
		return;
	}
	star(n/2, y, x);
	star(n/2, y+n/2, x-n/2);
	star(n/2, y+n/2, x+n/2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	memset(c, ' ', sizeof(c));
	cin >> N;
	star(N, 0, N-1);
	for (i=0;i<N;i++) {
		for (j=0;j<N*2-1;j++)
			cout << c[i][j];
		cout << '\n';
	}
	return 0;
}
