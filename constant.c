typedef uint8_t unt;
const unt N = 3;
const unt L = 1 << N;
const unt P = 70; //This is 8 choose 4, the number of POSSIBLE chi vectors. 
const unt K = 40; //This is the number of actual chi vectors used for the key
const unt B = 3; // This is the number of chi blocks used (the number of subkeys)
const unt card_T = 1 << N;
const unt card_S = 1 << N;
const uint16_t SEARCH_LIMIT = 100;

