#include <bits/stdc++.h>

using namespace std;
struct course {
    int i; // priority
    vector<int> prereqs;
    int advanced = -1; //how many total prereqs
};
bool comp(course c1, course c2) {
    if (c1.advanced == c2.advanced) { return c1.i < c2.i; }
    return c1.advanced < c2.advanced;
}
vector<course> courses;
int dfs(int v) {
    if (courses[v].advanced != -1) { return courses[v].advanced + 1; }
    int need = 0;
    for (int pre : courses[v].prereqs) {
        need += dfs(pre);
    }
    courses[v].advanced = need;
    return need+1;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    courses.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        courses[b].prereqs.push_back(a);
    }
    //wait we need to put 0's tree first
    //if we come across a new tree
    //we can ignore stuff we've already covered
    //erm
    //
    for (int i = 0; i < N; i++) {
        courses[i].i = i;
        if (courses[i].advanced == -1) {
            dfs(i);
        }
    }
    sort(courses.begin(), courses.end(), comp);
    for (int i = 0; i < N; i++) {
        cout << courses[i].advanced << "\n";
    }
    for (int i = 0; i < N; i++) {
        cout << courses[i].i+1 << " \n"[i == N - 1];
    }
    //the idea is that we will make a reverse adjacency list
    //for every single i, we compute the prerequisite number
    //
}