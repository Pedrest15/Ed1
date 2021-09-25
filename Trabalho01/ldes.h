typedef float tipo_lista;

struct elemento{
    tipo_lista dado;
    struct elemento *prox;
};

typedef struct elemento Elem;
typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
void insere_lista_final(Lista* li, tipo_lista x);
int insere_lista_ordenada(Lista* li, tipo_lista x);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
void imprime_lista(Lista* li);

int insere_lista_ordenada_inversa(Lista* li, tipo_lista x);