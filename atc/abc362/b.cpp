#include <bits/stdc++.h>

using namespace std;
int pythag(array<int, 2> p1, array<int, 2> p2) {
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    array<int, 2> p1, p2, p3;
    cin >> p1[0] >> p1[1] >> p2[0] >> p2[1] >> p3[0] >> p3[1];
    //theyre not collinear
    //so if any of x are equal then yay
    vector<int> sides = {pythag(p1, p2), pythag(p1, p3), pythag(p2, p3)};
    sort(sides.begin(), sides.end());
    if (sides[0] + sides[1] == sides[2]) {
        cout << "Yes" << "\n";
    }   else {
        cout << "No" << "\n";
    }
}