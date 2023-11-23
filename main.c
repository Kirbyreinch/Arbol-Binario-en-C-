#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Nodo {
    int dato;
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

struct Nodo *nuevoNodo(int dato) {
    size_t Tnodo = sizeof(struct Nodo);
    struct Nodo *nodo = (struct Nodo *)malloc(Tnodo);
    nodo->dato = dato;
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}

void insertar(struct Nodo *nodo, int dato) {
    while (1) {
        int direccion;
        printf("A que direccion ira el nodo %d (1 para izquierda, 2 para derecha): ", dato);
        scanf("%d", &direccion);

        if (direccion == 1) {
            if (nodo->izquierda == NULL) {
                nodo->izquierda = nuevoNodo(dato);
                break;
            } else {
                nodo = nodo->izquierda;
            }
        } else if (direccion == 2) {
            if (nodo->derecha == NULL) {
                nodo->derecha = nuevoNodo(dato);
                break;
            } else {
                nodo = nodo->derecha;
            }
        } else {
            printf("Dirección no válida. Ingrese 1 para izquierda o 2 para derecha.\n");

            while (getchar() != '\n');
        }
    }
}

void inorden(struct Nodo *nodo) {
    if (nodo != NULL) {
        inorden(nodo->izquierda);
        printf("%d, ", nodo->dato);
        inorden(nodo->derecha);
    }
}

bool esBinario(struct Nodo *nodo, int *previo) {
    if (nodo != NULL) {
        if (!esBinario(nodo->izquierda, previo)) {
            return false;
        }


        if (nodo->dato <= *previo) {
            return false;
        }

        *previo = nodo->dato;

        return esBinario(nodo->derecha, previo);
    }

    return true;
}

int main(void) {
    struct Nodo *raiz = nuevoNodo(10);

    int dato;
    printf("Ingrese valores para el arbol binario (-1 para terminar):\n");

    while (1) {
        printf("Ingrese un valor: ");
        scanf("%d", &dato);

        if (dato == -1) {
            break;
        }

        insertar(raiz, dato);
    }

    printf("\nImprimiendo inorden\n");
    inorden(raiz);


    char respuesta;
    printf("\n Evaluar si el arbol es binario? (S para Si, cualquier otra tecla para No): ");
    scanf(" %c", &respuesta);

    if (respuesta == 'S' || respuesta == 's') {

        int previo = -1;
        if (esBinario(raiz, &previo)) {
            printf("\n Es un arbol binario.\n");
        } else {
            printf("\n NO es un arbol binario.\n");
        }
    }

    return 0;
}
