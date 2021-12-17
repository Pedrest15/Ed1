typedef struct{
    int cep_ini;
    int cep_fin;
    char cidade[35];
    char estado[5];
} tipo_dado;

struct NO{
    tipo_dado info;
    int altura;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvAVL;

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
int insere_ArvAVL(ArvAVL *raiz, tipo_dado valor, int *flag);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
void consulta_cep_ArvAVL(ArvAVL *raiz, int cep);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);