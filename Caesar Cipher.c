#include <stdio.h>
#include <ctype.h>

void encrypt(char text[], int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = (text[i] - 'A' + key) % 26 + 'A';
            } else {
                text[i] = (text[i] - 'a' + key) % 26 + 'a';
            }
        }
    }
}

void decrypt(char text[], int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = (text[i] - 'A' - key + 26) % 26 + 'A';
            } else {
                text[i] = (text[i] - 'a' - key + 26) % 26 + 'a';
            }
        }
    }
}

int main() {
    char text[100];
    int key;

    printf("Enter a text to encrypt: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key (shift value): ");
    scanf("%d", &key);

    // Encrypt the text
    encrypt(text, key);
    printf("Encrypted text: %s", text);

    // Decrypt the text
    decrypt(text, key);
    printf("Decrypted text: %s", text);

    return 0;
}
