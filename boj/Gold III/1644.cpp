#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, ans;
bool a[4000001];
vector<int> psum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, sum, l, r;

	cin >> N;

	for (i=2;i<=N;i++) {
		for (j=i*2;j<=N;j+=i) {
			a[j] = 1;
		}
	}

	psum.push_back(0);
	sum = 0;
	for (i=2;i<=N;i++) {
		if (!a[i]) {
			sum += i;
			psum.push_back(sum);
		}
	}

	// two pointer
	l = 0;
	r = 0;
	sum = 0;
	while (l < psum.size()) {
		while (r < psum.size()) {
			sum = psum[r] - psum[l];
			if (sum == N) {
				ans++;
				r++;
				break;
			} else if (sum > N) {
				break;
			}
			r++;
		}
		l++;
	}

	cout << ans << endl;
	return 0;
}
