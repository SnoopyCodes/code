template <class T> struct SegTree{
    vector<T> seg;
    int n;
    const T ID = 
    
    T cmb(T a, T b){
        
    }
    
    SegTree(int _n){
        n = 1;
        while (n < _n) n *= 2;
        seg.assign(2 * n + 1, ID);
    }
    
    void set(int pos, T val){
        seg[pos + n] = val;
    }
    
    void build(){
        for (int i = n - 1; i >= 1; i--) seg[i] = cmb(seg[2 * i], seg[2 * i + 1]);
    }
    
    void upd(int v, int tl, int tr, int pos, T val){
        if (tl == tr){
            seg[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) upd(2 * v, tl, tm, pos, val);
            else upd(2 * v + 1, tm + 1, tr, pos, val);
            seg[v] = cmb(seg[2 * v], seg[2 * v + 1]);
        }
    }
    
    void upd(int pos, T val){
        upd(1, 0, n - 1, pos, val);
    }
    
    T query(int v, int tl, int tr, int l, int r){
        if (l > r) return ID;
        if (l == tl && r == tr) return seg[v];
        int tm = (tl + tr) / 2;
        T res = query(2 * v, tl, tm, l, min(tm, r));
        res = cmb(res, query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
        return res;
    }
    
    T query(int l, int r){
        return query(1, 0, n - 1, l, r);
    }
};