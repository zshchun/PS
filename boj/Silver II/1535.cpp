#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[21];
int b[21];
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i, j, happy, hp;
	cin >> N;
	for (i=0;i<N;i++)
		cin >> a[i];
	for (i=0;i<N;i++)
		cin >> b[i];

	for (i=0;i<(1<<N);i++) {
		happy = 0;
		hp = 100;
		for (j=0;j<N;j++) {
			if (i & (1 << j)) {
				hp -= a[j];
				happy += b[j];
			}
		}
		if (hp > 0)
			ans = max(ans, happy);
	}

	cout << ans << endl;

	return 0;
}
