
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "constant.c"
#include "bits.c"
#include "random.c"
#include "text.c"
#include "chi.c"
// #include "mix.c"
#include "print.c"
#include "encode.c"
#include "frac.c"
#include "demo.c"
// #include "dec.c"
// #include "test.c"

int main() {
    cls();
    srand(time(NULL));
    unt X[N][N][N][N], T[K][B], S[K][B], x ,y[N][N],d;
    //frac_enc(T, S, x, y);
    create_system_key(T,S);
    //print_key(T,S);
    //frac_enc(T, S, x, y);
    detailed_frac_81_demo(S,T);








}
      