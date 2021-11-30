#include <iostream>
#include <math.h>
using namespace std;

long GENERATE_PRIME_CANDIDATE(long b) {  // 2^(b-1) rand()% 2^b -1;
    long mini = pow(2, b - 1); long maxi = pow(2, b) - 1; long n;
    n = rand() % maxi; // n es de 10 bits, 1xxxxxxxx1 y es impar
    if (!(n % 2)) { 
        n = n + 1;
    }
    long m = pow(2, b - 1) + 1; // mascara
    n = n | m;
    return n;
}

long long  modular(unsigned long long  base, unsigned long long  exp, unsigned long long  mod) {
    long long  x = 1;
    int i;
    long long  power = base % mod;
    for (i = 0; i < sizeof(int) * 64; i++) {
        int least_sig_bit = 0x00000001 & (exp >> i);
        if (least_sig_bit)
            x = (x * power) % mod;
        power = (power * power) % mod;
    }
    return x;
}

bool WITNESS(long long a, long long  n) {// n es impar, u es impar, a[1-n-1] , 
    long long int  t = 1, u = 1, aux = 2;;
    while (n - 1 > aux) {  // hallamos t y u , n-1 = 2^t *u
        while (n - 1 > aux) {
            u = u + 2;
            aux = pow(2, t) * u;
        }
        if ((n - 1) == pow(2, t) * u)break;
        u = 1;
        t = t + 1;
        aux = pow(2, t) * u;
    }
    long long x0 = modular(a, u, n); //caso base x0 = a^u mod n
    if (x0 == 1 || x0 + 1 == n)return  false; // si es igual a 1 o -1 es un posible primo
    for (long i = 1; i < t; i++) {
        x0 = modular(x0, 2, n);
        if (x0 == (n - 1))return false;// posible primo
    }
    return true;// compuesto
}

bool MILLER_RABIN(long long n, long long  s) {// n
    for (long j = 1; j < s; j++) {
        long long a = 2 + rand() % (n - 1);
        if (WITNESS(a, n))return true;// compuesto 
    }
    return false;// posible primo
}

long GENERATE_PRIME(long b) {
    int s = 128;  // s = 128 
    long n = GENERATE_PRIME_CANDIDATE(b);
    while (!MILLER_RABIN(n, s)) {
        n = n + 2;
    }
    return n;
}


int main() {
    long b =10;
    long array[100];
    long i = GENERATE_PRIME(b);
    
    array[0] = i;
    int cont = 1;
    while (true) {
        int j = 0;
        i  = GENERATE_PRIME(b);
        for (j = 0; j < cont;j++ ) {
            if (i == array[j])i = GENERATE_PRIME(b);// si es igual al primo que tenemos generamos otro
        }
        array[cont] = i;
        cont = cont + 1;
        if (cont == 100)break; // 100 primos diferentes
    }

    for (int filas = 0,colum = 0; filas < 100; filas = filas +1,colum = colum +1) {
        cout << array[filas] << "\t";
        if (colum == 10) { cout << endl; colum = 0; }
    }

    return 0;
}