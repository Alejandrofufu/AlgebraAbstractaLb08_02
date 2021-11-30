# AlgebraAbstractaLb08_02
El código genera 100 números primos diferentes de tamaño 10 bits, se hace uso de la función WITNESS(), MILLER_RABIN(),GENERATE_PRIME_CANDIDATE() y  GENERATE_PRIME().

El código llama a la función GENERATE_PRIME(b), donde b = 10, n será igual al resultado de GENERATE_PRIME_CANDIDATE(b), que nos generara un pseudo número primo aleatorio de 10 bits.

Para confirmar que es un número primo llamamos a la función MILLER_RABIN(n,s), s = 128,esta función retornara true si es un número compuesto, false si es primo, aumentaremos n= n+2 hasta que de falso.

El n resultante debe ser un número primo.
