
unt shift_bits(unt x, unt a) {
    return (x << a) | (x >> (L - a));
}

unt permute_bits(unt x, unt* p) {
    unt y = 0;
    for (int i = 0; i < L; i++) y |= ((x & (1 << i)) >> i) << p[i];
    return y;
}
unt bit_count(unt x) {
    unt y = 0;
    for (int i = 0; i < L; i++) y += ((x & (1 << i)) >> i);
    return y;
}
