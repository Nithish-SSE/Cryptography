#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a message using a monoalphabetic cipher
void encrypt(char *message, char *key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (islower(message[i])) {
                message[i] = tolower(key[message[i] - 'a']);
            } else {
                message[i] = toupper(key[message[i] - 'A']);
            }
        }
    }
}

int main() {
    char message[100];
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM"; // Replace with your desired key

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline character if present

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    return 0;
}
