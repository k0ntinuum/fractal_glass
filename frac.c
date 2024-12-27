void frac_9_enc(unt T[K][B], unt S[K][B], unt s, unt x, unt y[N][N] ) {
    unt z[N];
    enc(T[s],S[s],x,z);
    for (unt i = 0; i < N; i++) {
        //enc(T, 3*i, S, 3*i, x, y[i]);
        enc(T[s + i] , S[s + i],  z[i], y[i]);
        //enc(T[0] , S[0],  z[i], y[i]);
    }
}
unt frac_9_dec(unt T[K][B], unt S[K][B], unt s, unt y[N][N]) {
    //for (unt i = 3; i < N; i++) z[i] = dec(T, 3*i, S, 3*i, y[i]);
    unt z[N];
    for (unt i = 0; i < N; i++) z[i] = dec(T[s + i] , S[s + i],  y[i]);
    //for (unt i = 0; i < N; i++) z[i] = dec(T[0] , S[0],  y[i]);
    return dec(T[s],S[s], z);
}
void frac_81_enc(unt T[K][B], unt S[K][B], unt x, unt y[N][N][N][N] ) {
    unt z[N], w[N][N];
    frac_9_enc(T, S, 0, x, w);
    //for (unt i = 0; i < N; i++) frac_9_enc(T, S, 4 + 4*i , x, w);
    for (unt i = 0; i < N; i++) for (unt j = 0; j < N; j++) frac_9_enc(T, S, 10 + 3*i + j, w[i][j], y[i][j] );
}
unt frac_81_dec(unt T[K][B], unt S[K][B], unt y[N][N][N][N]) {
    unt w[N][N];
    for (unt i = 0; i < N; i++) for (unt j = 0; j < N; j++) w[i][j] = frac_9_dec(T, S, 10 + 3*i + j, y[i][j] );
    return frac_9_dec(T,S, 0, w);
}