#include <bits/stdc++.h>
using namespace std;
int m[101][101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i, j, k;
	cin >> N;
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
			cin >> m[i][j];
	for (k=1;k<=N;k++)
		for (i=1;i<=N;i++)
			for (j=1;j<=N;j++)
				if (!m[i][j] && m[i][k] && m[k][j])
					m[i][j] = 1;
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++)
			cout << m[i][j] << (j == N ? "" : " ");
		cout << '\n';
	}
	return 0;
}
