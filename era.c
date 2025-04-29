#include <stdio.h>
#include <stdbool.h>

void sieveOfEratosthenes(int limit) {
    // Create a boolean array "prime[0..limit]" and initialize all entries as true.
    bool prime[limit + 1];
    for (int i = 0; i <= limit; i++) {
        prime[i] = true;
    }

    prime[0] = false; // 0 is not a prime
    prime[1] = false; // 1 is not a prime

    // Sieve algorithm
    for (int p = 2; p * p <= limit; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                prime[i] = false;
            }
        }
    }

    // Print all prime numbers
    printf("Prime numbers up to %d are:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the upper limit to find prime numbers: ");
    scanf("%d", &n);

    sieveOfEratosthenes(n);

    return 0;
}
