#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n, i, j, t;
	cin>>n;
	int *a = new int[n];
	for(i=0;i<n;i++)
		cin>>a[i];

	for(i=1;i<n;i++) {
		j = i - 1;
		t = a[i];
		while(j >= 0 && t < a[j]) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = t;
	}
	for (i=0;i<n;i++)
		cout << a[i] <<"\n";
	return 0;
}

