 #include <stdio.h>
#include "practicaja.h"

int main() {
    int cuentaSeleccionada;
    int operaciones;
    int bucle = 1;
    int numOname;
    char nameCliente[40];
    int a, b, c, data=0;

    struct cliente banco[100] = {
        {1, 15000, "Carlos", "Ramirez", 1234},
        {2, 10000, "Karla","Gutierrez", 1701},
        {3, 20200, "Pepe","Pollo", 7766}
    };

    int n_usuarios = sizeof(banco)/sizeof(banco[0]);
    while(1)
    {
    printf("\n========== BIENVENIDO A LA PRACTICAJA CUCEI ==========\n");

    printf("ingrese con que opcion desea ingresar a su cuenta:\n");
        printf("1.- ingresar con numero de cliente\n");
        printf("2.-ingresar con su nombre\n");
        printf("3.-Salir de la practicaja\n");
        scanf("%d",&numOname);

        switch(numOname)
        {
            case 1:
            printf("por favor ingrese su numero de cliente para acceder a su cuenta: \n");
            scanf("%d", &cuentaSeleccionada);
            if (cuentaSeleccionada < 1 || cuentaSeleccionada > 3)
            {
                    printf("La opcion ingresada no es valida.\n");
                    return 0;
            }

            cuentaSeleccionada -= 1;

            if (!autenticarNip(banco, cuentaSeleccionada))
            {
                return 0;
            }
            break;

            case 2:
            printf("Ingrese su nombre (un nombre y un apellido): \n");
            getchar();
            fgets(nameCliente, sizeof(nameCliente), stdin);
            nameCliente[strcspn(nameCliente, "\n")] = 0;
            data = 0;
            for (a = 0; a < 3; a++)
            {
                if (compararNombreCompleto(banco[a], nameCliente))
                {
                    printf("Su cuenta fue encontrada.\n");
                    cuentaSeleccionada = a;
                    data = 1;

                    if (!autenticarNip(banco, cuentaSeleccionada))
                    {
                        return 0;
                    }
                    break;
                }
            }

            if (data == 0)
            {
                printf("Su cuenta no fue encontrada.\n");
                return 0;
            }
            break;
            case 3:
                 printf("\nGracias por usar la Practicaja CUCEI. Que tenga un buen dia\n");
                    return 0;
        }
    do {
        printf("\nPor favor ingrese la opcion deseada:\n\n");
        printf("1.- Consulta de saldo\n");
        printf("2.- Depositos\n");
        printf("3.- Retiros\n");
        printf("4.- Ver historial de movimientos\n");
        printf("5.- Salir de la practicaja\n");
        scanf("%d", &operaciones);

        switch (operaciones) {
            case 1:
                consultarSaldo(banco, cuentaSeleccionada);
                break;
            case 2:
                realizarDeposito(banco, cuentaSeleccionada);
                break;
            case 3:
                realizarRetiro(banco, cuentaSeleccionada);
                break;
            case 4:
                mostrarMovimientos(banco[cuentaSeleccionada]);
                break;
            case 5:
                printf("\nGracias por usar la Practicaja CUCEI. Que tenga un buen dia\n");
                return 0;
            default:
                printf("La opcion ingresada no es correcta.\n");
        }

        printf("\nDesea realizar alguna otra operacion?\n");
            printf("1.- Si\n");
            printf("2.- No, regresar al menu principal\n");
            scanf("%d", &bucle);
            if (bucle == 2)
            {
                break;
            }
        } while (bucle == 1);
    }

    printf("\nGracias por usar la Practicaja CUCEI. Que tenga un buen dia\n");
    return 0;
}

