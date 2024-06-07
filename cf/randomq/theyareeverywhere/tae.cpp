#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> pokemon(N);
    vector<bool> types(52);
    vector<int> has(52);
    int numtypes = 0;
    string s; cin >> s;
    for (int i = 0; i < N; i++) {
        int c = s[i];
        if (c >= 97) { c -= 97; }
        else { c -= 65 - 26; }  //caps
        pokemon[i] = c;
        if (!types[c]) { types[c] = true; numtypes++; }
    }
    //we want to find the smallest group that encompasses all of the elements
    //therefore just move a sliding window over all of it
    //if our first element appears more than once then we can make our window smaller
    int j = 1;  //will be exclusive
    has[pokemon[0]]++;
    int numhas = 1;
    int minsize = INT_MAX;
    for (int i = 0; i < N; i++) {
        while (j < N && (j == i + 1 || pokemon[j-1] != pokemon[i]) && numhas < numtypes) {
            //j is a valid pokemon
            if (!has[pokemon[j]]) { numhas++; }
            has[pokemon[j]]++;
            j++;
        }
        if (numhas == numtypes) {
            minsize = min(minsize, j - i);
        }
        has[pokemon[i]]--;
        if (!has[pokemon[i]]) { numhas--; }
    }
    cout << minsize << "\n";
}