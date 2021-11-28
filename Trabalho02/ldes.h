//Arquivo ListaDinEncad.h
typedef struct{
    float x;
    float y;
    float z;
    short int r;
    short int g;
    short int b;
    int id;
} tipo_dado;

//Definição do tipo lista
struct elemento{
    tipo_dado dado;
    struct elemento *prox;
};

typedef struct elemento Elem;
typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
void insere_lista_final(Lista* li, tipo_dado dt, int *custo);
void insere_lista_inicio(Lista* li, tipo_dado dt, int *custo);
void insere_lista_ordx(Lista* li, tipo_dado dt, int *custo);
void insere_lista_ordy(Lista* li, tipo_dado dt);
void insere_lista_ordz(Lista* li, tipo_dado dt);
Elem* busca_lista_menorz(Lista* li, Lista* liz, int* cont);
void imprime_lista(Lista* li);
void imprime_pz(Lista *li_ordz);
void imprime_pi(Lista *li_ini, Lista *li_ordz);
void imprime_id(Lista *li, float id);
void imprime_cut(Lista *li, float num[]);
void salva_em_disco(Lista *li);