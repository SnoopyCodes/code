#include <bits/stdc++.h>
 
using namespace std;
vector<int> numbers;
int chk(int a, int b) {
    int tot = 0;
    if (a > 0 && numbers[a-1] < numbers[a]) { tot++; }
    if (a < numbers.size()-1 && numbers[a+1] > numbers[a]) { tot++; }
    if (b != a + 1)
    if (b > 0 && numbers[b-1] < numbers[b]) { tot++; }
    if (b < numbers.size()-1 && numbers[b+1] > numbers[b]) { tot++; }
    return tot;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    numbers.resize(N);
    vector<int> old(N);
    vector<bool> links(N+1);  //link i, i-1
    for (int i = 0; i < N; i++) {
        int a; 
        cin >> a;
        a--;
        numbers[a] = i;
        old[i] = a;
    }
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i-1] < numbers[i]) { N--; links[i] = true; }
    }
    for (int q = 0; q < M; q++) {
        int a, b; cin >> a >> b;
        a--; b--;
        //the values of old are swapped
        swap(old[a], old[b]);
        a = old[a];
        b = old[b];
        
        if (b < a) { swap(a, b); }
        N += chk(a, b);
        swap(numbers[a], numbers[b]);
        N -= chk(a, b);
        cout << N << "\n";
    }
    //how to swap?
    //when we swap we should check the "links" of each one
}