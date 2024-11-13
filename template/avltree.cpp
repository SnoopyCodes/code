#include <bits/stdc++.h>

using namespace std;

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
    node* min(node* n) {
        if (n->l == nullptr) { return n; }
        return min(n->l);
    }
    node* max(node* n) {
        if (n->r == nullptr) { return n; }
        return max(n->r);
    }

    
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}