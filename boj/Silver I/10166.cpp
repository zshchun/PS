#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"

int a[2001][2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int D1, D2, ans = 0;
	int i, j, den, num, g;
//	set<pa> s;
	cin >> D1 >> D2;
	for (i=D1;i<=D2;i++) {
		for (j=0;j<i;j++) {
			den = i;
			num = j;
			if (j == 0) {
				g = 0;
				den = 0;
			} else {
				g = gcd(den, num);
				if (g > 1) {
					den /= g;
					num /= g;
				}
			}
//			if (s.count(pa(num, den)) == 0) {
			if (!a[num][den]) {
				a[num][den] = 1;
				ans++;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
