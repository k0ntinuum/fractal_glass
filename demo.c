void detailed_demo(unt T[K][B], unt S[K][B]) {
    unt x,d,y[N];
    print_key(T,S);
    for (size_t i = 0 ; i < 5; i++) {
        x = rand_symbol();
        
        //print_sym_bits(x);
        for (size_t j = 0 ; j < N; j++)
        //print_sym_bits(y[j]);
        enc(T[0], S[0], x, y);
        d = dec(T[0], S[0], y);
        
        printf("chi T  %d          = ", x);print_chi(T[0], x);
        //printf("chi S  %d          = ", x);print_chi(S, x);
        printf("chi S  %d  %d  %d    = ", y[0],y[1],y[2]);print_multi_chi(S[0], y);
        //printf("chi T  %d  %d  %d    = ", y[0],y[1],y[2]);print_multi_chi(T, y);
        //printf("chi T  %d          = ", d);print_chi(T, d);
        printf("f      %d          = %d  %d  %d \n\n", x, y[0],y[1],y[2]);
        if (x != d) printf("\ndecoding error!\n");
    }
}

void detailed_frac_9_demo(unt T[K][B], unt S[K][B]) {
    unt x,d,y[N][N],z[N],u[N],dz, du,dy0,dy1,dy2;
    print_key(T,S);
    for (size_t i = 0 ; i < 5; i++) {
        x = rand_symbol();
        //enc(T[0], S[0], x, u);
        //enc(T, 0, S, 0, x, z);
        frac_9_enc(T, S, 0, x,  y);
        d = frac_9_dec(T, S, 0, y);
        //d = dec(T, 0, S, 0, y);
        
        //printf("chi T  %d          = ", x);print_chi(T, x);
        //printf("chi S  %d          = ", x);print_chi(S, x);
        //printf("chi S  %d  %d  %d    = ", y[0],y[1],y[2]);print_multi_chi(S, y);
        //printf("chi T  %d  %d  %d    = ", y[0],y[1],y[2]);print_multi_chi(T, y);
        //printf("chi T  %d          = ", d);print_chi(T, d);
        // printf("u                  =    %d  %d  %d \n\n",   u[0],u[1],u[2]);
        // printf("du                 =    %d \n\n\n\n", du);
        // printf("z                  =    %d  %d  %d \n\n",   z[0],z[1],z[2]);
        // printf("dz                 =    %d \n\n\n\n", dz);
        printf("f      %d           =    %d  %d  %d \n\n", x,  y[0][0],y[0][1],y[0][2]);
        printf("                        %d  %d  %d \n\n",      y[1][0],y[1][1],y[1][2]);
        printf("                        %d  %d  %d \n\n",      y[2][0],y[2][1],y[2][2]);
        // printf("dy0                =    %d \n", dy0);
        // printf("dy1                =    %d \n", dy1);
        // printf("dy2                =    %d \n", dy2);
        // printf("d                  =    %d \n\n\n\n", d);

        if (x != d) printf("\ndecoding error!\n\n");
    }
}

void detailed_frac_81_demo(unt T[K][B], unt S[K][B]) {
    unt x,d,y[N][N][N][N];
    rgb(0,255,0);
    hide_cursor();
    cls();
    //print_key(T,S);
    for (size_t i = 0 ; i < 50000; i++) {
        if (i % 100 == 0 ) x = rand_symbol();
        //enc(T[0], S[0], x, u);
        //enc(T, 0, S, 0, x, z);
        frac_81_enc(T, S, x ,  y);
        d = frac_81_dec(T, S, y);
        //printf("f  %d  = \n\n", x);
        print_81_calc_bits(x, y);
        //print_81_calc(x, y);
        usleep(30000);
        //printf("\n\nd                  =    %d \n", d);
        // d = frac_dec(T, S, z, y);
        // dz = dec(T[0], S[0], z);
        // du = dec(T[0], S[0], u);
        // dy0 = dec(T[0], S[0], y[0]);
        // dy1 = dec(T[0], S[0], y[1]);
        // dy2 = dec(T[0], S[0], y[2]);
        //d = dec(T, 0, S, 0, y);
        
        //printf("chi T  %d          = ", x);print_chi(T, x);
        //printf("chi S  %d          = ", x);print_chi(S, x);
        //printf("chi S  %d  %d  %d    = ", y[0],y[1],y[2]);print_multi_chi(S, y);
        //printf("chi T  %d  %d  %d    = ", y[0],y[1],y[2]);print_multi_chi(T, y);
        //printf("chi T  %d          = ", d);print_chi(T, d);
        // printf("u                  =    %d  %d  %d \n\n",   u[0],u[1],u[2]);
        // printf("du                 =    %d \n\n\n\n", du);
        // printf("z                  =    %d  %d  %d \n\n",   z[0],z[1],z[2]);
        // printf("dz                 =    %d \n\n\n\n", dz);
        // printf("f      %d           =    %d  %d  %d \n\n", x,  y[0][0],y[0][1],y[0][2]);
        // printf("                        %d  %d  %d \n\n",      y[1][0],y[1][1],y[1][2]);
        // printf("                        %d  %d  %d \n\n",      y[2][0],y[2][1],y[2][2]);
        // printf("dy0                =    %d \n", dy0);
        // printf("dy1                =    %d \n", dy1);
        // printf("dy2                =    %d \n", dy2);
        // printf("d                  =    %d \n\n\n\n", d);

        if (x != d) exit(0);
    }
}