#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
int N;
int a[1024][1024];
int b[4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, step;
	cin >> N;
	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			cin >> a[i][j];

	for (step=1;step<N;step<<=1) {
		for (i=0;i<N;i+=step*2) {
			for (j=0;j<N;j+=step*2) {
				b[0] = a[i][j];
				b[1] = a[i][j+step];
				b[2] = a[i+step][j];
				b[3] = a[i+step][j+step];
				sort(b, b+4);
				a[i][j] = b[2];
			}
		}
	}
	cout << a[0][0] << endl;

	return 0;
}
