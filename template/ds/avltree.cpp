#include <bits/stdc++.h>

using namespace std;

//does not work and im too lazy to make it work

struct node {
    int val;
    int h = 1;
    node *p = nullptr, *l = nullptr, *r = nullptr;

    bool is_lc() { return p != nullptr && p-> l == this; }
    bool is_rc() { return p != nullptr && p-> r == this; }
    int lh() { return l == nullptr ? 0 : l->h; }
    int rh() { return r == nullptr ? 0 : r->h; }
    int bal_fac() { return lh() - rh(); }
    void upd_h() { h = 1 + max(lh(), rh()); }

    void sl(node *n) {
        l = n;
        if (n != nullptr) { l -> p = this; }
        upd_h();
    }
    void sr(node *n) {
        r = n;
        if (n != nullptr) { r -> p = this; }
        upd_h();
    }
};

struct AVLTree {
    node *root = nullptr;
    int size = 0;

    node *rotl(node* root) {
        //make the right child the root
        if (root->r == nullptr) { return nullptr; }
        node *new_root = root -> r;
        root->sr(new_root -> l);
        new_root->sl(root);
        return new_root;
    }
    node *rotr(node* root) {
        //left child -> root
        if (root -> l == nullptr) { return nullptr; }
        node *new_root = root -> l;
        root -> sl(new_root -> r);
        new_root -> sr(root);
        return new_root;
    }

    node *balance(node* root) {
        if (root == nullptr) { return nullptr; }
        int fac = root->bal_fac();
        if (abs(fac) <= 1) { return root; }
        if (fac == 2) {
            if (root->l->bal_fac() == -1) { root->sl(rotl(root->l)); }
            return rotr(root);
        }
        if (root->r->bal_fac() == 1) { root->sr(rotr(root->r)); }
        return rotl(root);
    }

    void add(int val) {
        size += 1;
        if (root == nullptr) { root->val = val; return; }
        _add(val, root);
    }

    void _add(int val, node* n) {
        if (val < n->val) {
            if (n->l == nullptr) {
                node *child; child->val = val;
                child->p = n;
                n->sl(child);
            }   else {
                _add(val, n->l);
            }
        }   else {
            if (n->r == nullptr) {
                node *child; child -> val = val;
                child->p = n;
                n->sr(child);
            }
        }
        balance(n);
    }
    
    node *find(int val) {
        return _find(val, root);
    }

    node* _find(int val, node* n) {
        if (n->val == val) { return n; }
        if (val < n->val) {
            if (n->l == nullptr) { return nullptr; }
            return _find(val, n->l);
        }   else {
            if (n->r == nullptr) { return nullptr; }
            return _find(val, n->r);
        }
    }

    //must have nonempty to use
    node* min(node *n) {
        if (n->l == nullptr) { return n; }
        return min(n->l);
    }
    node* max(node *n) {
        if (n->r == nullptr) { return n; }
        return max(n->r);
    }

    void del_leaf(node *n) {
        if (n->p == nullptr) { n = nullptr; }
        else if (n->is_lc()) { n->p->l = nullptr; }
        else { n->p->r = nullptr; }
    }

    void del(int val) {
        node *rem = _find(val, root);
        if (rem == nullptr) { return; }
        node *replace = nullptr;
        node *par = rem->p;
        if (rem->l != nullptr) {
            replace = max(rem->l);
        }   else if (rem->r != nullptr) {
            replace = min(rem->r);
        }
        if (replace != nullptr) {
            rem->val = val;
            if (rem->is_lc()) { rem->p->sl(rem->l); }
            else { rem->p->sr(rem->r); }
        }   else {
            del_leaf(rem);
        }
        if (par != nullptr) {
            balance(par);
        }
    }
    
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    AVLTree bruh;
    cout <<"hey"<<endl;
    bruh.add(2);
    cout << "goodbye"<<endl;
    cout << (bruh.min(bruh.root)->val) << "\n";
}