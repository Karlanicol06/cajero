#include <stdio.h>
#include <string.h>
#include "practicaja.h"

int main()
{
    int n_cuenta, nip, estado_login, opcion;
    char nombre[50];
    int operaciones;
    int bucle = 1;
    int pass_admin = 1234;
    char nombre_admin[40] = "admin";
    struct cliente clientes[100] = {
        {1, "Carlos", "Ramirez", 1234, 15000.0, 0, 0, {1000, -500, 200, 0, 0, 0, 0, 0, 0, 0}},
        {2, "Karla", "Gutierrez", 1701, 10000.0, 0, 0, {500, 300, -200, 0, 0, 0, 0, 0, 0, 0}},
        {3, "Pepe", "Pollo", 7766, 20200.0, 0, 0, {1200, -100, 0, 0, 0, 0, 0, 0, 0, 0}}};

    int n_usuarios = 3;

    while (opcion != 5)
    {

        printf("\n1.Iniciar sesion\n2.Busqueda\n3.Deposito\n4.Crear cuenta\n5.Salir\n6.Guardar\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Ingrese su numero de cuenta\n");
            scanf("%d", &n_cuenta);
            do
            {
                printf("\nIngrese su nip\n");
                scanf("%d", &nip);
                estado_login = login(n_cuenta, nip, clientes);
            } while (estado_login == -1);
            if (estado_login == 1)
            {
                int i = buscar_indice_cuenta(clientes, n_cuenta);
                menu_cliente(clientes, i);
            }
            else if (estado_login == -2)
            {
                printf("Su cuenta ha sido bloqueada por demasiados intentos fallidos.\n");
            }
            else
            {
                printf("La cuenta no existe.\n");
            }
            break;
        case 2:
            printf("Ingrese el nombre del cliente a buscar\n");
            scanf("%s", nombre);
            buscar_nombre(clientes, nombre);
            break;
        case 3:
            printf("Ingrese el numero de cuenta\n");
            scanf("%d", &n_cuenta);
            realizar_deposito_sc(clientes, n_cuenta);
            break;
        case 4:
            agregar_usuario(clientes, &n_usuarios);
            printf("Usuario agregado con exito\n");
            break;
        case 5:
            printf("Gracias por usar la Practicaja CUCEI. Que tenga un buen dia\n");
            return 0;
        case 6:
            guardar_clientes(clientes, n_usuarios);
            printf("Los datos han sido guardados exitosamente.\n");
            break;
        default:
            printf("La opcion ingresada no es correcta.\n");
            break;
        }
    }

    return 0;
}
