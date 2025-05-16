#ifndef PRACTICAJA_H
#define PRACTICAJA_H

#include <stdio.h>
#include <string.h>

struct cliente {
    int Ncliente;
    float saldo;
    char nombre[40];
    char apellido[40];
    int nip;
};

int validar(float x) {
    if (x > 0) {
        printf("La cantidad ingresada es valida.\n");
        return 1;
    } else {
        printf("La cantidad ingresada es negativa, ingrese un numero positivo\n");
        return 0;
    }
}

void consultarSaldo(struct cliente clientes[], int cuentaSeleccionada) {
    printf("========= CONSULTA DE SALDO ==========\n");
    printf("Cliente: %s\n", clientes[cuentaSeleccionada].nombre);
    printf("Su saldo actual es de: %.2f\n", clientes[cuentaSeleccionada].saldo);
}

void realizarDeposito(struct cliente clientes[], int cuentaSeleccionada) {
    float num;
    int v;
    printf("========= DEPOSITOS ==========\n");
    printf("Ingrese la cantidad que desea depositar: \n");
    scanf("%f", &num);
    v = validar(num);
    while (v != 1) {
        scanf("%f", &num);
        v = validar(num);
    }
    clientes[cuentaSeleccionada].saldo += num;
    printf("Su deposito se realiza con exito. El saldo actual es: %.2f\n", clientes[cuentaSeleccionada].saldo);
}

void realizarRetiro(struct cliente clientes[], int cuentaSeleccionada) {
    float num;
    int v;
    do {
        printf("========= RETIROS ==========\n");
        printf("Ingrese la cantidad que desea retirar: \n");
        scanf("%f", &num);
        v = validar(num);
        while (v != 1) {
            scanf("%f", &num);
            v = validar(num);
        }

        if (num > clientes[cuentaSeleccionada].saldo) {
            printf("No tienes suficiente saldo, por favor ingresa una cantidad valida:\n");
        } else {
            clientes[cuentaSeleccionada].saldo -= num;
            printf("Su retiro se realizó con exito. Saldo restante: %.2f\n", clientes[cuentaSeleccionada].saldo);
            break;
        }
    } while (1);
}

int autenticarNip(struct cliente clientes[], int cuentaSeleccionada) {
    int nipIngresado;
    int intentos = 0;
    int maxIntentos = 3;

    while (intentos < maxIntentos) {
        printf("\n***** INGRESE SU NIP *****\n");
        scanf("%d", &nipIngresado);

        if (nipIngresado == clientes[cuentaSeleccionada].nip) {
            printf("NIP ingresado correctamente.\n");
            return 1;
        } else {
            intentos++;
            printf("El NIP ingresado es incorrecto.\n");
        }

        if (intentos == maxIntentos) {
            printf("Has alcanzado el número máximo de intentos.\n");
            return 0;
        }
    }
    return 0;
}

void agregar_usuario(struct cliente *clientes, int *n)
{
    printf("Ingrese el numero de cliente");
    scanf("%d", &clientes[*n].Ncliente);
    printf("Ingrese el nombre del cliente");
    scanf("%s", clientes[*n].nombre);
    printf("Ingrese el apellido del cliente");
    scanf("%s", clientes[*n].apellido);
    printf("Ingrese el nip del cliente");
    scanf("%d", &clientes[*n].nip);
    (*n)++;
}

void imprimir_usuarios(struct cliente clientes[], int n_usuarios){
    for(int i = 0; i < n_usuarios; i++){
        printf("Numero de cliente %d\n", clientes[i].Ncliente);
        printf("Nombre del cliente %s\n", clientes[i].nombre);
        printf("Apellido del cliente %s\n", clientes[i].apellido);
        printf("Nip de cliente %d\n", clientes[i].nip);
        printf("Saldo del cliente %f\n\n", clientes[i].saldo);
    }
}

#endif
