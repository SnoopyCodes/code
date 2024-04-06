#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    v.resize(N);
    //we can get the prime factorization of all in like what log N?
    //square root? probably sqrt
    //if we get the prime factorization of everything
    //we should calculate prefix mins
    //but thats kinda tough
    //if we calculate prefix mins uhh
    //we can do log n
    //objective:
    //find the integer ai such that the removal of it results in the largest increase of the gcd of the entire blackboard
    //if we have prefix sums of stuff then we can get the maximum gcd in a range?
    //if we start with a number the gcd can only go down from there
    //as we iterate through the list, do we need to update anything?
    //if we keep 2 values: gcd removed and gcd not removed
    //a greedy algorithm is not necessarily optimal so we can't
    //waht if we take the gcd at that point
    //bruh im stupid
    //okay just gcd on each one its not even prefix sums its just gcd spam
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int gcdremove = v[0], gcdnotremoved = v[0];
    for (int i = 1; i < N; i++) {

    }
}