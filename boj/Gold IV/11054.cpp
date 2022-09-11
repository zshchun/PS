#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a[1001], lis[1001], lds[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i, j, ans=0;
	cin >> N;
	for (i=1;i<=N;i++) {
		cin >> a[i];
		for (j=1;j<i;j++) {
			if (a[j] < a[i] && lis[j]+1 > lis[i]) {
				lis[i] = lis[j] + 1;
			}
		}
	}
	for (i=N;i>0;i--) {
		for (j=N;j>i;j--) {
			if (a[j] < a[i] && lds[j]+1 > lds[i]) {
				lds[i] = lds[j] + 1;
			}
		}
	}
	for (i=1;i<=N;i++) {
		if (ans < lis[i]+lds[i]+1)
			ans = lis[i]+lds[i]+1;
	}
	cout << ans << '\n';
	return 0;
}

