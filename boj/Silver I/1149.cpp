#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, i, j;
	vector<int> c(3, 0);
	vector<vector<int>> o;
	cin >> n;
	for (i=0;i<n;i++) {
		for (j=0;j<3;j++)
			cin >> c[j];
		o.push_back(c);
	}

	for (i=1;i<n;i++) {
		for (j=0;j<3;j++) {
			o[i][j] += min(o[i-1][(j+1)%3], o[i-1][(j+2)%3]);
		}
	}
	int m = min(min(o[n-1][0], o[n-1][1]), o[n-1][2]);
	cout << m << '\n';

	return 0;
}




