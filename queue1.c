#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define MAX_TITLE 100
#define FALSE     0
#define TRUE      1


typedef int boolean;


/* ── Nodo ───────────────────────────────────────────────────────────────── */
typedef struct song {
    char         title[MAX_TITLE];
    struct song *next;
    struct song *prev;
} song;


/* ── Playlist ───────────────────────────────────────────────────────────── */
typedef struct {
    song *head;
    song *tail;
    int   cnt;
} playlist;


/* ── Operaciones básicas ─────────────────────────────────────────────────── */
void initialize(playlist *p)
{
    p->head = NULL;
    p->tail = NULL;
    p->cnt  = 0;
}


boolean empty(const playlist *p) { return (boolean)(p->cnt == 0); }
boolean full(const playlist *p)  { (void)p; return FALSE; }


void enqueue_tail(const char *title, playlist *p)
{
    song *s = malloc(sizeof(song));
    strncpy(s->title, title, MAX_TITLE - 1);
    s->next = NULL;
    s->prev = NULL;
    if (empty(p)) {
        p->head = p->tail = s;
    } else {
        s->prev       = p->tail;
        p->tail->next = s;
        p->tail       = s;
    }
    p->cnt++;
}


void enqueue_head(const char *title, playlist *p)
{
    song *s = malloc(sizeof(song));
    strncpy(s->title, title, MAX_TITLE - 1);
    s->next = NULL;
    s->prev = NULL;
    if (empty(p)) {
        p->head = p->tail = s;
    } else {
        s->next       = p->head;
        p->head->prev = s;
        p->head       = s;
    }
    p->cnt++;
}


void mostrar_playlist(const playlist *p)
{
    if (empty(p)) { printf("Playlist vacia.\n"); return; }
    song *curr = p->head;
    int i = 1;
    while (curr != NULL) {
        printf("  %d. %s\n", i++, curr->title);
        curr = curr->next;
    }
}


/* ── Main ───────────────────────────────────────────────────────────────── */
int main(void)
{
    playlist pl;
    initialize(&pl);


    int  opcion;
    char titulo[MAX_TITLE];


    printf("=== PLAYLIST (lista doblemente ligada) ===\n");


    do {
        printf("\n1. Agregar al final\n");
        printf("2. Agregar al inicio\n");
        printf("3. Ver playlist\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar();


        switch (opcion) {
            case 1:
                printf("Nombre de la cancion: ");
                fgets(titulo, MAX_TITLE, stdin);
                titulo[strcspn(titulo, "\n")] = '\0';
                enqueue_tail(titulo, &pl);
                printf("Agregada al final.\n");
                break;
            case 2:
                printf("Nombre de la cancion: ");
                fgets(titulo, MAX_TITLE, stdin);
                titulo[strcspn(titulo, "\n")] = '\0';
                enqueue_head(titulo, &pl);
                printf("Agregada al inicio.\n");
                break;
            case 3:
                printf("\n--- Playlist ---\n");
                mostrar_playlist(&pl);
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 0);


    return 0;
}
