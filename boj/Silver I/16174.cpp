#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N;
int a[65][65];
int visited[65][65];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N;
	visited[0][0] = 1;
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			cin >> a[i][j];
			if (visited[i][j]) {
				if (a[i][j] == -1)
					continue;
				if (i + a[i][j] < N)
					visited[i+a[i][j]][j] = 1;
				if (j + a[i][j] < N)
					visited[i][j+a[i][j]] = 1;
			}
		}
	}

	if (visited[N-1][N-1])
		cout << "HaruHaru\n";
	else
		cout << "Hing\n";
	return 0;
}
