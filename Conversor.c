#include <stdio.h>

float convertir_a_gtq(float cantidad, char moneda_origen);
float convertir_desde_gtq(float cantidad, char moneda_destino);
void mostrar_menu();

int main() {
    char opcion;
    float cantidad;
    char moneda_destino;

    do {
        mostrar_menu();
        scanf(" %c", &opcion);

        switch (opcion) {
            case '1':
                printf("Ingrese la cantidad en GTQ: ");
                scanf("%f", &cantidad);
                printf("Ingrese la moneda a convertir (D para USD, E para EUR): ");
                scanf(" %c", &moneda_destino);
                printf("%.2f GTQ = %.2f %c\n", cantidad, convertir_desde_gtq(cantidad, moneda_destino), moneda_destino);
                break;
            case '2':
                printf("Ingrese la cantidad en USD: ");
                scanf("%f", &cantidad);
                printf("%.2f USD = %.2f GTQ\n", cantidad, convertir_a_gtq(cantidad, 'D'));
                break;
            case '3':
                printf("Ingrese la cantidad en EUR: ");
                scanf("%f", &cantidad);
                printf("%.2f EUR = %.2f GTQ\n", cantidad, convertir_a_gtq(cantidad, 'E'));
                break;
            case '0':
                printf("Saliendo del conversor...\n");
                break;
            default:
                printf("Opción no válida. Por favor, elija una opción del menú.\n");
                break;
        }
    } while (opcion != '0');

    return 0;
}

float convertir_a_gtq(float cantidad, char moneda_origen) {
    float tasa_conversion;
    if (moneda_origen == 'D') { // Convertir desde USD
        tasa_conversion = 7.70; // Tasa de cambio aproximada
    } else if (moneda_origen == 'E') { // Convertir desde EUR
        tasa_conversion = 9.07; // Tasa de cambio aproximada
    } else if (moneda_origen == 'Q') { // Moneda de origen es GTQ
        return cantidad; // No se necesita conversión
    } else {
        printf("Moneda de origen no válida.\n");
        return -1;
    }
    return cantidad * tasa_conversion;
}

float convertir_desde_gtq(float cantidad, char moneda_destino) {
    float tasa_conversion;
    if (moneda_destino == 'D') { // Convertir a USD
        tasa_conversion = 0.13; // Tasa de cambio aproximada
    } else if (moneda_destino == 'E') { // Convertir a EUR
        tasa_conversion = 0.11; // Tasa de cambio aproximada
    } else if (moneda_destino == 'Q') { // Moneda de destino es GTQ
        return cantidad; // No se necesita conversión
    } else {
        printf("Moneda de destino no válida.\n");
        return -1;
    }
    return cantidad * tasa_conversion;
}

void mostrar_menu() {
    printf("\n===== Conversor de Monedas =====\n");
    printf("1. Convertir desde GTQ\n");
    printf("2. Convertir a GTQ desde USD\n");
    printf("3. Convertir a GTQ desde EUR\n");
    printf("0. Salir\n");
    printf("================================\n");
    printf("Seleccione una opción: ");
}
