void print_bit(unt b) { b == 0 ? printf("O") : printf("|"); }
void print_bit_space(unt b) { b == 0 ? printf("O ") : printf("| "); }
void print_bits(unt x) {
    for (int i = 0; i < L ; i++ ) print_bit( (x & ( 1 << i) ) >> i);
    //printf("\n");
}
void print_bits_l(unt x, unt l) {
    for (int i = 0; i < l ; i++ ) print_bit( (x & ( 1 << i) ) >> i);
}
void print_bits_nl(unt x) {
    for (int i = 0; i < L ; i++ ) print_bit( (x & ( 1 << i) ) >> i);
    printf("\n");
}
void print_sym_bits(unt x) {
    for (int i = 0; i < L ; i++ ) print_bit( (x & ( 1 << i) ) >> i);
    printf("\n");
}
void print_chi(unt T[B], unt x) {
    print_bits_l(chi_code(T, x), N);
    printf("\n");
}
void print_multi_chi(unt T[B], unt y[N]) {
    print_bits_l(multi_chi_code(T, y), N);
    printf("\n");
}

void print_key_block(unt T[B], unt S[B]) {
    for (size_t i = 0 ; i < B ; i++) {
        print_bits(T[i]);printf("     ");print_bits(S[i]);printf("\n"); 
    }
    printf("\n\n");

}
void print_key(unt T[K][B], unt S[K][B]) {
    for (size_t i = 0 ; i < K ; i++) {
        print_key_block(T[i],S[i]);
    }
}

// void print_81_dec(unt y[N][N][N][N]) {
//         for (size_t i = 0 ; i < N ; i++) {
//             for (size_t j = 0 ; j < N ; j++) {
//                 for (size_t k = 0 ; k < N ; k++) {
//                     for (size_t h = 0 ; h < N ; h++) {
//                         cursor_to(cent - half + 2*j + 9*(i%3) - 3 , 4 + 20 + 8*k + 2*h);
//                         printf("%d ", y[i][j][k][h]);
//                     }
//                     printf("       ");
//                 }
//                 printf("\n");
                
                
//             }
//             printf("\n");
//         }
//         printf("\n");
// }
void print_81_calc(unt x, unt y[N][N][N][N]) {
    unt cent = 20, half = 8;
    cursor_to(cent,2);
    printf("f ( %d )     = ",x);
        for (size_t i = 0 ; i < N ; i++) {
            for (size_t j = 0 ; j < N ; j++) {
                for (size_t k = 0 ; k < N ; k++) {
                    for (size_t h = 0 ; h < N ; h++) {
                        cursor_to(cent - half + 2*j + 9*(i%3) - 3 , 4 + 20 + 8*k + 2*h);
                        printf("%d ", y[i][j][k][h]);
                        
                    }
                    //printf("       ");
                }
                //printf("\n");
                
                
            }
            //printf("\n");
        }
    cursor_to(cent + 2*half + 3, 0 );
}
void print_81_calc_bits(unt x, unt y[N][N][N][N]) {
    unt cent = 20, half = 8;
    cursor_to(cent,2);
    printf("   f ");print_bits_l(x,3); 
        for (size_t i = 0 ; i < N ; i++) {
            for (size_t j = 0 ; j < N ; j++) {
                for (size_t k = 0 ; k < N ; k++) {
                    for (size_t h = 0 ; h < N ; h++) {
                        //cursor_to(cent - half + 2*j + 9*(i%3) - 3 , 4 + 20 + 4*8*k + 4*2*h);
                        cursor_to(cent - half + 2*j + 7*(i%3) -1 , 16 + 14*k + 2*2*h);
                        print_bits_l( y[i][j][k][h], 3);
                    }
                    //printf("       ");
                }
                //printf("\n");
                
                
            }
            //printf("\n");
        }
    cursor_to(cent + 2*half + 3, 0 );
}