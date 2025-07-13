#include <bits/stdc++.h>

using std::vector, std::min, std::max;

/*
only consider prime factors.
*each prime can only be present in one card*
more strictly speaking, a prime can only divide one of the numbers set face up
therefore we can make the following logical 2-sat:
    if prime p divides a sequence i_1, i_2, ...
    draw edges from each i to the negation of each other i
    this represents only one p can exist.
this is too many edges
create condition j_1, j_2, ...
j_1 implies !i_1, etc.
j_2 implies j_1. i_2 implies j_1, i_3 implies j_2, ...
repeat with new k conditions 
k_1 implies k_2, k_2 implies k_3...; i_1 implies k_2, i_2 implies k_3...
therefore, any i_x implies all j_[0, x-1] (and thus !i_[0,x-1])
k does the same for y > x
apparently this is a "standard" construction, as it appears in KACTL
*/

vector<vector<int>> con;
std::stack<int> path;

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int N; std::cin >> N;
    vector<int> face(2 * N);
    con.resize(2 * N);
    std::map<int, vector<int>> at;
    for (int i = 0; i < 2 * N; i += 2) {
        std::cin >> face[i] >> face[i + 1];
        at[face[i]].push_back(i), at[face[i+1]].push_back(i + 1);
    }
    int MAX = *max_element(face.begin(), face.end());
    vector<int> sieve(MAX + 1);
    int total = 2 * N; //number of conditions
    for (int i = 2; i <= MAX; i++) {
        if (sieve[i]) { continue; }
        vector<int> mult;
        for (int j = i; j <= MAX; j += i) {
            sieve[j] = i;
            for (int x : at[j]) {
                mult.push_back(x);
            }
        }
        for (int j = 0; j < mult.size() - 1; j++) { //"k"
            int i_1 = mult[j], i_2 = mult[j + 1];
            con.push_back({});
            con.push_back({});
            
        }
    }

    
}