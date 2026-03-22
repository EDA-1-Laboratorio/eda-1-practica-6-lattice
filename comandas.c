#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id_mesa;
    char platillo[50];
    int prioridad; 
} Pedido;

struct nodo {
    Pedido info;
    struct nodo *siguiente;
};

typedef struct nodo nodo;

typedef struct {
    nodo *frente;
    nodo *final;
} Cola;

void initialize(Cola *c) {
    c->frente = NULL;
    c->final = NULL;
}

int empty(Cola *c) {
    return (c->frente == NULL);
}

void enqueue(Cola *c, Pedido p) {
    nodo *nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->info = p;
    nuevo->siguiente = NULL;

    if (empty(c)) {
        c->frente = nuevo;
        c->final = nuevo;
    } else {
        c->final->siguiente = nuevo;
        c->final = nuevo;
    }
}

Pedido dequeue(Cola *c) {
    nodo *temp = c->frente;
    Pedido p = temp->info;

    c->frente = c->frente->siguiente;

    if (c->frente == NULL)
        c->final = NULL;

    free(temp);
    return p;
}

Pedido front(Cola *c) {
    return c->frente->info;
}

Pedido back(Cola *c) {
    return c->final->info;
}

int main() {
    Cola cola;
    initialize(&cola);

    int opcion;

    do {
        printf("\n--- SISTEMA DE COMANDAS ---\n");
        printf("1. Recibir comanda\n");
        printf("2. Servir platillo\n");
        printf("3. Ver siguiente platillo\n");
        printf("4. Ver ultimo platillo\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);   
        while(getchar() != '\n');  
        switch (opcion) {
        case 1:
            Pedido p;   
            printf("ID de mesa: ");
            scanf("%d", &p.id_mesa);

            printf("Platillo: ");
            scanf(" %[^\n]", p.platillo);

            printf("Prioridad: ");
            scanf("%d", &p.prioridad);

            enqueue(&cola, p);
            printf("Comanda recibida\n");

            break;
        case 2: 
            if (empty(&cola)) {
                printf("No hay pedidos\n");
            } else {
                Pedido p = dequeue(&cola);
                printf("Sirviendo mesa %d: %s\n", p.id_mesa, p.platillo);
            }

            break;
        case 3:
            if (!empty(&cola)) {
                Pedido p = front(&cola);
                printf("Siguiente: Mesa %d - %s\n", p.id_mesa, p.platillo);
            } else {
                printf("No hay pedidos\n");
            }
            break;
        case 4:
            if (!empty(&cola)) {
                Pedido p = back(&cola);
                printf("Ultimo: Mesa %d - %s\n", p.id_mesa, p.platillo);
            } else {
                printf("No hay pedidos\n");
            }
            break;
        case 5:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion no valida\n");
        }   
    } while (opcion != 5);

    return 0;
} 
