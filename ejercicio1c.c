/*
 * double_linked_queue.h
 * Definición de las operaciones básicas para colas doblemente ligadas (deque).
 *
 * Una cola doblemente ligada (double-ended queue) permite insertar y extraer
 * elementos tanto por el frente (head) como por el final (tail), usando nodos
 * con punteros tanto al siguiente como al anterior elemento.
 */


#ifndef DOUBLE_LINKED_QUEUE_H
#define DOUBLE_LINKED_QUEUE_H


#include <stdlib.h>


/* ── Tipos base ───────────────────────────────────────────────────────────── */


typedef unsigned int data;      /* Tipo del dato almacenado (e.g. PID)       */
typedef int          boolean;   /* Tipo booleano                             */


#define TRUE  1
#define FALSE 0
#define EMPTY 0


/* ── Nodo de la cola doblemente ligada ───────────────────────────────────── */


typedef struct elem {
    data         d;     /* Dato almacenado en el nodo                        */
    struct elem *next;  /* Puntero al siguiente nodo (hacia tail)            */
    struct elem *prev;  /* Puntero al nodo anterior (hacia head)             */
} elem;


/* ── Estructura de la cola doblemente ligada ─────────────────────────────── */


typedef struct {
    elem *head;         /* Puntero al primer elemento (frente)               */
    elem *tail;         /* Puntero al último elemento (final)                */
    int   cnt;          /* Número de elementos en la cola                    */
} double_linked_queue;


/* ── Prototipos de las operaciones básicas ───────────────────────────────── */


/*
 * initialize: Establece el estado inicial de la cola doblemente ligada.
 *   - cnt = 0, head = NULL, tail = NULL.
 */
void initialize(double_linked_queue *q);


/*
 * empty: Devuelve TRUE si la cola no contiene elementos, FALSE en caso contrario.
 */
boolean empty(const double_linked_queue *q);


/*
 * full: Para una cola dinámica (basada en malloc) siempre devuelve FALSE,
 *       ya que no tiene un límite de capacidad fijo.
 */
boolean full(const double_linked_queue *q);


/*
 * enqueue_tail: Inserta el dato d al final (tail) de la cola.
 *   - Equivale al enqueue de una cola simple: política FIFO estándar.
 *   - El nuevo nodo queda como nuevo tail; su prev apunta al tail anterior.
 */
void enqueue_tail(data d, double_linked_queue *q);


/*
 * enqueue_head: Inserta el dato d al frente (head) de la cola.
 *   - Operación adicional habilitada por el doble enlace.
 *   - El nuevo nodo queda como nuevo head; su next apunta al head anterior.
 */
void enqueue_head(data d, double_linked_queue *q);


/*
 * dequeue_head: Extrae y devuelve el dato del frente (head) de la cola.
 *   - Precondición: la cola no debe estar vacía (!empty(q)).
 *   - El nuevo head pasa a ser head->next; su prev se pone a NULL.
 *   - Se libera el nodo extraído con free().
 */
data dequeue_head(double_linked_queue *q);


/*
 * dequeue_tail: Extrae y devuelve el dato del final (tail) de la cola.
 *   - Operación adicional habilitada por el doble enlace.
 *   - Precondición: la cola no debe estar vacía (!empty(q)).
 *   - El nuevo tail pasa a ser tail->prev; su next se pone a NULL.
 *   - Se libera el nodo extraído con free().
 */
data dequeue_tail(double_linked_queue *q);


/*
 * peek_head: Devuelve el dato del frente sin extraerlo.
 *   - Precondición: la cola no debe estar vacía (!empty(q)).
 */
data peek_head(const double_linked_queue *q);


/*
 * peek_tail: Devuelve el dato del final sin extraerlo.
 *   - Precondición: la cola no debe estar vacía (!empty(q)).
 */
data peek_tail(const double_linked_queue *q);


#endif /* DOUBLE_LINKED_QUEUE_H */


