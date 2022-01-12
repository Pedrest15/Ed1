typedef struct{
    char nome[20];
    char posicao[3];
    char pai[20];
    int bit;
} tipo_dado;

struct NO{
    tipo_dado info;
    struct NO *esq;
    struct NO *dir;
};
typedef struct NO *ArvBin;

ArvBin* cria_ArvBin();
void libera_NO(struct NO* no);
void libera_ArvBin(ArvBin *raiz);
void insere_circuito(ArvBin* raiz, tipo_dado valor, int *flag);
void preOrdem_ArvBin(ArvBin *raiz);

struct NO** Procura_preOrdem_ArvBin(ArvBin *raiz, char pai[], int* achou);
void insere_bit(ArvBin* raiz, char entrada_nome[], int entrada_bit, int *flag2);
int calcula_bit(ArvBin *raiz);
int verifica_arvore(ArvBin *raiz, int x);