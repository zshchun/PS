#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, j, k;
	int a[100001];
	int s[100001];
	string ans;
	cin >> n;
	for (i=0;i<n;i++)
		cin >> a[i];

	for (j=0,k=0,i=1;i<=n && k < n ;i++) {
		if (i < a[k]) {
			ans += "+\n";
			s[j++] = i;
		} else if (i == a[k]) {
			s[j++] = i;
			ans += "+\n";
			while (j > 0 && k < n && s[j-1] == a[k]) {
				ans += "-\n";
				j--;
				k++;
			}
		}
	}

	if (k == n) {
		cout << ans;
	} else {
		cout << "NO\n";
		return 0;
	}
	return 0;
}
