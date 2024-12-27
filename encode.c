
unt _enc(unt S, unt c) {
    unt y;
    for (size_t w = 0 ; w < 1000; w++) {
        y = rand_symbol();
        if ( ( (S & 1 << y) >> y) == c) return y;
    }
    return 0;
}
void enc(unt T[B], unt S[B], unt x, unt y[N] ) {
    unt s = chi_code(T,x);
    for (unt w = 0 ; w < N; w++) y[w] = _enc(S[w] , (s & 1 << w) >> w);
        //for (unt i = 0 ; i < N ; i++) y |= ((S[i] & 1 << x) >> x) << i;
    if ( s == multi_chi_code(S, y) ) return;
    printf("\nencoding failure\n");
    return;
}
// void enc(unt T[B], unt S[B], unt x, unt y[N] ) {
//     unt s = chi_code(T,x);
//     for (unt w = 0 ; w < N; w++) {
//         for (unt i = 0; i < 200; i++) {
//             for (unt j = 0; j < N; j++) y[w] = rand_symbol();
//         for (unt i = 0 ; i < N ; i++) y |= ((S[i] & 1 << x) >> x) << i;
//         if ( s == multi_chi_code(S, y) ) return;
//     }


//     }

//     printf("\nencoding failure\n");
//     return;
// }

unt dec(unt T[B], unt S[B], unt y[N] ) {
    unt code = multi_chi_code(S,y);
    for (unt i = 0 ; i < L ; i++) if (chi_code(T,i) == code) return i;
    //printf("decoding failure");
    return 0;
}