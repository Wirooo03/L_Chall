#include <stdio.h>
#include <string.h>


void crackMe(char *message) {
    int length = strlen(message);
    

    for (int i = 0; i < length; i++) {
        if (message[i] >= '0' && message[i] <= '9') {
            int shift = message[i] - '0';  
            if (i + 1 < length) {
                message[i + 1] = message[i + 1] + shift;
            }
        }
    }

    for (int i = 0; i < length; i++) {
        if ((message[i] >= 'A' && message[i] <= 'Z') || (message[i] >= 'a' && message[i] <= 'z')) {
            message[i] = message[i] + 2;  
        }
    }

    for (int i = 0; i < length / 2; i++) {
        char temp = message[i];
        message[i] = message[length - 1 - i];
        message[length - 1 - i] = temp;
    }
}

int main() {
    char message[] = "Kaliber{1n1_fL@g_nY@!_b3n3r@N_g@k_b0h0n9!}";
    
    printf("Pesan asli: %s\n", message);

    crackMe(message);

    printf("Pesan terenkripsi: %s\n", message);

    return 0;
}
