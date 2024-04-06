#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<pair<int, int>> particles;
vector<pair<int, int>> compress;
bool comp(pair<int, int> p1, pair<int, int> p2) { 
    return p1.second < p2.second;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("moop.in", "r", stdin);
    // freopen("moop.out", "w", stdout);
    //so if htere is a particle so that its x and y are greater than all other then get rid of those
    //get rid of all particles with an x value similar to another but with a lower x-value, and vice versa
    //if there be a particle such that all other points with x-value <= this particle have y-value <= this particle
    //all the other points + 1 == our answer, given that this point is of the largest x-value with this property
    int N; cin >> N;
    particles.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> particles[i].first >> particles[i].second;
    }
    sort(particles.begin(), particles.end(), comp);  //is sorted by x-coordinate
    int ans = N;
    for (int i = 0; i < N - 1; i++) {
        if (particles[i].second == particles[i+1].second) { particles[i].second = INT_MAX; ans--; }
    }
    sort(particles.begin(), particles.end(), comp);  //move INTMAX to end

    sort(particles.begin(), particles.begin() + ans);  //sort by x
    int tmp = ans;
    for (int i = 0; i < N - 1; i++) {
        if (particles[i].first == particles[i+1].first) { particles[i].first = INT_MAX; ans--; }
    }
    sort(particles.begin(), particles.begin() + tmp);  //move INTMAX to end
    compress.resize(ans);
    for (int i = 0; i < ans; i++) {
        compress[i].first = i;
        compress[i].second = particles[i].second;
    }
    sort(compress.begin(), compress.end(), comp);
    for (int i = 0; i < compress.size(); i++) {
        compress[i].second = i;
    }
    sort(compress.begin(), compress.end());
    //okay. nice. now what do we do
    //we have a coordinate compressed thing that can tell us how much larger this is than that and this much than that
    //the important thing is to get rid of as many points that have 1 overlap as possible
    //so if we put stuff into a map
    //we should be able to very easily tell for every point how many overlaps it achieves
    //and afterwards for the ones that have ONE overlpa?
    int minreq = INT_MIN;  //starting requirement
    for (int i = particles.size()-1; i >= 0; i--) {
        if (i != N - 1 && particles[i].first == particles[i+1].first) { ans--; continue; }
        if (minreq >= particles[i].second) { ans--; }
        else { minreq = particles[i].second; }  //because if we go backwards, the points must have a y-value greater than minreq to survive
    }
    cout << ans << "\n";
    //okay but how do we kill them off?
    //use what we had before?
    //is it instead if there is a particle such that every other has coordinates larger than it then answer is like 1?
    //well sure but that doesnt help us does it
    //count on some points how many of the majors overlap it
    //right?
    //using a map to check how many it is larger than
    //oh coordinate compression
    //bruh moment
}