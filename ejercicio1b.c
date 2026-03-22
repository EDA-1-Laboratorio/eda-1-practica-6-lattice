/*
 * circular_queue.h
 * Definición de las operaciones básicas para colas circulares.
 *
 * Una cola circular utiliza un arreglo de tamaño fijo (MAX) donde
 * los índices head y tail "dan la vuelta" usando aritmética modular,
 * evitando así el desperdicio de espacio que ocurre en colas lineales.
 */

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H


#include <stdlib.h>


/* ── Tipos base ───────────────────────────────────────────────────────────── */


typedef unsigned int data;      /* Tipo del dato almacenado (e.g. PID)       */
typedef int          boolean;   /* Tipo booleano                             */


#define TRUE  1
#define FALSE 0
#define EMPTY 0
#define MAX   100               /* Capacidad máxima de la cola circular      */


/* ── Estructura de la cola circular ─────────────────────────────────────── */


typedef struct {
    data    items[MAX]; /* Arreglo de tamaño fijo que almacena los elementos */
    int     head;       /* Índice del frente de la cola                      */
    int     tail;       /* Índice de la siguiente posición libre             */
    int     cnt;        /* Número de elementos actualmente en la cola        */
} circular_queue;


/* ── Prototipos de las operaciones básicas ───────────────────────────────── */


/*
 * initialize: Establece el estado inicial de la cola circular.
 *   - head, tail y cnt se ponen a 0.
 */
void initialize(circular_queue *q);


/*
 * empty: Devuelve TRUE si la cola no contiene elementos, FALSE en caso contrario.
 */
boolean empty(const circular_queue *q);


/*
 * full: Devuelve TRUE si la cola ha alcanzado su capacidad máxima (MAX),
 *       FALSE en caso contrario.
 */
boolean full(const circular_queue *q);


/*
 * enqueue: Inserta el dato d al final (tail) de la cola.
 *   - Precondición: la cola no debe estar llena (!full(q)).
 *   - El índice tail avanza de forma circular: tail = (tail + 1) % MAX.
 */
void enqueue(data d, circular_queue *q);


/*
 * dequeue: Extrae y devuelve el dato del frente (head) de la cola.
 *   - Precondición: la cola no debe estar vacía (!empty(q)).
 *   - El índice head avanza de forma circular: head = (head + 1) % MAX.
 */
data dequeue(circular_queue *q);


/*
 * head: Devuelve el dato del frente de la cola sin extraerlo.
 *   - Precondición: la cola no debe estar vacía (!empty(q)).
 */
data head(const circular_queue *q);


#endif /* CIRCULAR_QUEUE_H */


