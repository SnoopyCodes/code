#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> arr;
vector<int> truth; //false
bool test() {
    for (int i = 0; i < arr.size(); i++) {  //for these subarrays
        for (int j = 0; j < arr[i].size(); j++) {  //at this index
            int ax = 0, in = INT_MAX;
            for (int k = i; k <= j+i; k++) {
                ax = max(ax, truth[k]);
                in = min(in, truth[k]);
            }
            if (ax - in != arr[i][j]) { return false; }
        }
    }
    return true; 
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //how do being able to use negatives hlep?
    //can we figure out when there is a max and min?
    //start with absolute max
    //set that to 1e9
    //for the second one what can we do
    //then why cant we just iteratively move left and right from there and use the corresponding arrays to find the difference?
    //certainly for moving backwards we should be able to, right?
    //can we?
    //maybe
    //first find the earliest index for which it is always the largest within all arrays
    //freopen("in.txt", "r", stdin);
    int N; cin >> N;
    truth.resize(N);
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        vector<int> v(N-i);
        for (int j = 0; j < v.size(); j++) { cin >> v[j]; }
        arr[i] = v;
    }
    bool worked = false;
    int messiah;
    for (messiah = 0; messiah < N; messiah++) {
        truth.clear(); truth.resize(N);
        //truth[messiah] = 1e9;
        for (int i = messiah-1; i >= 0; i--) {  //the array is the ith array, and the index of hte array is 0
            int dist = arr[i][1];  //from in front to this, this is the distance
            if (i == messiah-1) { truth[i] = truth[messiah] - dist; continue; }
            //now find if it is less than or greater than it?
            if (arr[i][2] == arr[i+1][1]) { //it is in between
                if (truth[i+2] > truth[i+1]) { truth[i] = truth[i+1] + dist; }
                else { truth[i] = truth[i+1] - dist; }
            }   else {
                //it is outside
                if (truth[i+2] > truth[i+1]) { truth[i] = truth[i+1] - dist; }
                else { truth[i] = truth[i+1] + dist; }
            }
        }
        for (int i = messiah+1; i < N; i++) {
            int dist = arr[i-1][1];  //from the one behind to this
            if (i == messiah+1) { truth[i] = truth[messiah] - dist; continue; }
            if (arr[i-2][2] == arr[i-1][1]) {  //we are in between
                if (truth[i-2] > truth[i-1]) { truth[i] = truth[i-1] + dist; }
                else { truth[i] = truth[i-1] - dist; }
            }   else {
                if (truth[i-2] > truth[i-1]) { truth[i] = truth[i-1] - dist; }
                else { truth[i] = truth[i-1] + dist; }
            }
        }
        //1/10
        if (test()) { worked = true; break; }
    }
    for (int i = 0; i < N; i++) { cout << truth[i] << " "; }
}