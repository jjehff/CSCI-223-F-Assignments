#include <stdio.h>

int main() {
    auto int hex;
    while (EOF != scanf("%x", &hex)) {
        printf("%c", hex);
    }
}
