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
    char movimientos[10][100];
    int indice_movimiento;
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

void registrarMovimiento(struct cliente *c, const char *descripcion) {
    snprintf(c->movimientos[c->indice_movimiento], 100, "%s", descripcion);
    c->indice_movimiento = (c->indice_movimiento + 1) % 10;
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

    char desc[100];
    snprintf(desc, sizeof(desc), "Deposito: +%.2f", num);
    registrarMovimiento(&clientes[cuentaSeleccionada], desc);

    printf("Su deposito se realizo con exito. El saldo actual es: %.2f\n", clientes[cuentaSeleccionada].saldo);
}

void realizarRetiro(struct cliente clientes[], int cuentaSeleccionada) {
    float num;
    int v, continuar;
    do {
        printf("========= RETIROS ==========\n");
        printf("Ingrese la cantidad que desea retirar: \n");
        scanf("%f", &num);
        v = validar(num);
        while (v != 1) {
            scanf("%f", &num);
            v = validar(num);
        }
        printf("Esta seguro que desea realizar el retiro?\n");
        printf("1.-Si\n");
        printf("2.-No\n");
        scanf("%d",&continuar);

        if(continuar !=1)
        {
            printf("Operacion cancelada\n");
            break;
        }
        if (num > clientes[cuentaSeleccionada].saldo) {
            printf("No tienes suficiente saldo, por favor ingresa una cantidad valida:\n");
        } else {
            clientes[cuentaSeleccionada].saldo -= num;

            char desc[100];
            snprintf(desc, sizeof(desc), "Retiro: -%.2f", num);
            registrarMovimiento(&clientes[cuentaSeleccionada], desc);

            printf("Su retiro se realizo con exito. Saldo restante: %.2f\n", clientes[cuentaSeleccionada].saldo);
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
            printf("Has alcanzado el numero maximo de intentos.\n");
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
    clientes[*n].indice_movimiento = 0;
    for (int i = 0; i < 10; i++) {
        clientes[*n].movimientos[i][0] = '\0';
    }
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

int compararNombreCompleto(struct cliente c, const char *entrada) {
    char nombreCompleto[100];
    snprintf(nombreCompleto, sizeof(nombreCompleto), "%s %s", c.nombre, c.apellido);
    return strcmp(nombreCompleto, entrada) == 0;
}

void mostrarMovimientos(struct cliente c) {
    printf("\n=== ULTIMOS MOVIMIENTOS ===\n");
    int count = 0;
    for (int i = 0; i < 10; i++) {
        int pos = (c.indice_movimiento - 1 - i + 10) % 10;
        if (strlen(c.movimientos[pos]) > 0) {
            printf("%d. %s\n", count + 1, c.movimientos[pos]);
            count++;
        }
    }
    if (count == 0) {
        printf("No hay movimientos registrados.\n");
    }
}

#endif
