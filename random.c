unt rand_unt() {
    return (unt) arc4random_uniform(1 << L);
}
unt rand_symbol() {
    return (unt) arc4random_uniform(1 << N);
}
void shuffle(unt* f, int l) {
    int j = 0;int t = 0;
    for (int i = l - 1; i > 0; i -= 1) {
        j = arc4random_uniform(i+1);
        t = f[i];f[i] = f[j];f[j] = t;
    }
}
void create_perm(unt* t, int L) {
    for (int i = 0; i < L ; i++) t[i] = i;
    shuffle(t, L);
}

int index(unt* f, unt k, unt l) {
    for (int i = 0; i < l; i++)
        if (f[i] == k ) return i;
    return -1;
}
void invert(unt* f, unt* g, unt l) {
    for (unt i = 0; i < l; i++) g[i] = index(f, i, l);
}

void shift_perm(unt* f, unt* g, unt a, unt l) {
    unt s[N];
    for (int i = 0; i < l; i++) s[i] = (f[i] + a)%l;
    for (int i = 0; i < l; i++) g[i] = s[i];
}
