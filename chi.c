
void create_chi_block(unt T[B]) {
    unt p[P];create_perm(p, L);
    for (size_t j = 0; j  <  B ; j++) T[j] = 0;
    for (unt i = 0; i  <  L ; i++) 
        for (size_t j = 0; j  <  B ; j++)
            T[j] |= (( p[i] & 1 << j ) >> j) << i;
}
void create_system_key(unt T[K][B], unt S[K][B]) {
    for (size_t i = 0; i  <  K ; i++ ) {
        create_chi_block(T[i]);
        create_chi_block(S[i]);
    }
}

unt chi_code(unt S[B], unt x) {
    unt y = 0;
    for (unt i = 0 ; i < N ; i++) y |= ((S[i] & 1 << x) >> x) << i;
    return y;
}
unt multi_chi_code(unt S[B], unt y[N]) {
    unt z = 0;
    for (unt i = 0 ; i < N ; i++) z |= ((S[i] & 1 << y[i]) >> y[i]) << i;
    return z;
}