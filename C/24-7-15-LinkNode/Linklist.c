#include <stdio.h>

#define VBIAS_MAX 2.4   // Maximum output voltage for VBIAS
#define VZERO_MAX 2.4   // Maximum output voltage for VZERO
#define VBIAS_MIN 0.2   // Minimum output voltage for VBIAS
#define VZERO_MIN 0.2   // Minimum output voltage for VZERO

// Function to convert voltage to 12-bit code (VBIAS)
int convertToVbiasCode(float voltage) {
    if (voltage < VBIAS_MIN || voltage > VBIAS_MAX) {
        printf("Error: Voltage out of range for VBIAS.\n");
        return -1; // Error value
    }
    return (int)((voltage - VBIAS_MIN) / (VBIAS_MAX - VBIAS_MIN) * 4095); // 12-bit code
}

// Function to convert voltage to 6-bit code (VZERO)
int convertToVzeroCode(float voltage) {
    if (voltage < VZERO_MIN || voltage > VZERO_MAX) {
        printf("Error: Voltage out of range for VZERO.\n");
        return -1; // Error value
    }
    return (int)((voltage - VZERO_MIN) / (VZERO_MAX - VZERO_MIN) * 63); // 6-bit code
}

int main() {
    float vbias, vzero;
    printf("Enter VBIAS voltage (0.2V to 2.4V): ");
    scanf("%f", &vbias);
    printf("Enter VZERO voltage (0.2V to 2.4V): ");
    scanf("%f", &vzero);

    int vbias_code = convertToVbiasCode(vbias);
    int vzero_code = convertToVzeroCode(vzero);

    if (vbias_code != -1 && vzero_code != -1) {
        printf("VBIAS Code (12-bit): %d\n", vbias_code);
        printf("VZERO Code (6-bit): %d\n", vzero_code);
    }

    return 0;
}
