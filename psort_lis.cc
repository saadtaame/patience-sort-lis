
#include <bits/stdc++.h>

using namespace std;

void add(vector<int> &piles, int a) {
    auto it = lower_bound(piles.begin(), piles.end(), a);
    if(it == piles.end()) piles.push_back(a);
    else piles[ distance(piles.begin(), it) ] = a;
}

int LIS(vector<int> A) {
    int n = (int)A.size();
    vector<int> piles; // Top elements of piles
    
    for(int i = 0; i < n; i++)
        add(piles, A[i]);
        
    return (int)piles.size();
}

int main(void) {

	int n;
	cin >> n;
	vector<int> A(n);
	for(int i = 0; i < n; i++)
		cin >> A[i];
	cout << LIS(A) << endl;

	return 0;
}
