#include <bits/stdc++.h>
using namespace std;
//how is this shorter than my total template
template<typename T, int MAXN> struct deck {
    vector<T> data(MAXN);
    int front = MAXN;
    int back = MAXN;
    inline void emf(T val) { data[front--] = val; }
    inline void emb(T val) { data[++back] = val; }
    inline T pof() { return data[front++]; }
    inline T pob() { return data[--back]; }
    inline T front() { return data[front]; }
    inline T back() { return data[back-1]; }
    inline int size() { return back - front; }
    inline bool empty() { return front == back; }
    inline void clear() { front = back = MAXN; }
};