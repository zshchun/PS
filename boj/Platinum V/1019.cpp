#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n;
ll ans[11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i=0, j, k, x = 0;
	cin >> n;
	for (i=1;n;i*=10) {
		k = n % 10;
		n /= 10;
		ans[0] -= i;

		for (j=0;j<=9;j++) {
			if (j < k)
				ans[j] += (n+1) * i;
			else if (j > k)
				ans[j] += n * i;
			else
				ans[j] += n * i + x + 1;

			
		}
		x += k * i;
	}

	for (i=0;i<10;i++)
		cout << ans[i] << ' ';
	return 0;
}
