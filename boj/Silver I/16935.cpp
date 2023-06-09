#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
int a[109][109];
int b[109][109];
int N, M;

void upside_down() {
	int i, j;
	for (i=0;i<N/2;i++)
		for (j=0;j<M;j++)
			swap(a[i][j], a[N-1-i][j]);
}

void right_to_left() {
	int i, j;
	for (i=0;i<N;i++)
		for (j=0;j<M/2;j++)
			swap(a[i][j], a[i][M-1-j]);
}

void rotate_right() {
	int i, j;
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
			b[j][N-1-i] = a[i][j];
	for (i=0;i<M;i++)
		for (j=0;j<N;j++)
			a[i][j] = b[i][j];
	swap(N, M);
}

void rotate_left() {
	int i, j;
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
			b[M-1-j][i] = a[i][j];
	for (i=0;i<M;i++)
		for (j=0;j<N;j++)
			a[i][j] = b[i][j];
	swap(N, M);
}

void quarter_right() {
	int i, j;
	for (i=0;i<N/2;i++)
		for (j=0;j<M/2;j++)
			b[i][M/2+j] = a[i][j];
	for (i=0;i<N/2;i++)
		for (j=M/2;j<M;j++)
			b[N/2+i][j] = a[i][j];
	for (i=N/2;i<N;i++)
		for (j=M/2;j<M;j++)
			b[i][j-M/2] = a[i][j];
	for (i=N/2;i<N;i++)
		for (j=0;j<M/2;j++)
			b[i-N/2][j] = a[i][j];
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
			a[i][j] = b[i][j];
}

void quarter_left() {
	int i, j;
	for (i=0;i<N/2;i++)
		for (j=0;j<M/2;j++)
			b[N/2+i][j] = a[i][j];
	for (i=0;i<N/2;i++)
		for (j=M/2;j<M;j++)
			b[i][j-M/2] = a[i][j];
	for (i=N/2;i<N;i++)
		for (j=M/2;j<M;j++)
			b[i-N/2][j] = a[i][j];
	for (i=N/2;i<N;i++)
		for (j=0;j<M/2;j++)
			b[i][j+M/2] = a[i][j];
	for (i=0;i<N;i++)
		for (j=0;j<M;j++)
			a[i][j] = b[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int R, n, r, i, j, q;
	cin >> N >> M >> R;
	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			cin >> a[i][j];
		}
	}

	while (R--) {
		cin >> q;
		if (q == 1) {
			upside_down();
		} else if (q == 2) {
			right_to_left();
		} else if (q == 3) {
			rotate_right();
		} else if (q == 4) {
			rotate_left();
		} else if (q == 5) {
			quarter_right();
		} else if (q == 6) {
			quarter_left();
		}
	}

	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
