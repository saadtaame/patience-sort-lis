#include <cstdio>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool pCmp( const stack<int> &S, int val ) {
    return (S.top() < val);
}

void printSequence( vector<int> &prec, int pos ) {
    if(prec[pos] != -1) {
        printSequence(prec, prec[pos]);
        cout << " " << pos;
    }
    else {
        cout << pos;
    }
}

int main( void ) {

    int n;

    while(cin >> n) {

        vector<int> prec(n, -1);
        vector< stack<int> > piles, positions;
        int x, curPos;

        curPos = 0;

        while(n--) {

            cin >> x;

            auto it = lower_bound(piles.begin(), piles.end(), x, pCmp);
            int pos;

            if(it == piles.end()) {
                stack<int> newPile;
                newPile.push(x);
                piles.push_back(newPile);

                stack<int> dummy;
                dummy.push(curPos);
                positions.push_back(dummy);

                pos = (int)piles.size() - 1;
            }
            else {
                it->push(x);
                pos = distance(piles.begin(), it);
                positions[pos].push(curPos);
            }

            if(pos > 0) {
                prec[curPos] = positions[pos - 1].top();
            }
            curPos += 1;
        }

        cout << (int)piles.size() << endl;
        printSequence(prec, positions.back().top());
        cout << endl;
    }
    return 0;
}
