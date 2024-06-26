
#include "HashingL.h"


LISTA_CHAVES *CriarListaCHAVES()
{
    LISTA_CHAVES *L = (LISTA_CHAVES *)malloc(sizeof(LISTA_CHAVES));
    L->NEL = 0;
    L->Inicio = NULL;
    return L;
}

//--------------------------------------------------
NO_CHAVE *AddCHAVE(LISTA_CHAVES *L, char *key)
{
    if (!L) return NULL;
    NO_CHAVE *aux = (NO_CHAVE *)malloc(sizeof(NO_CHAVE));
    aux->KEY = (char *)malloc((strlen(key) + 1) * sizeof(char));
    strcpy(aux->KEY, key);
    aux->DADOS = CriarListaL();
    aux->Prox = L->Inicio;
    L->Inicio = aux;
    L->NEL++;
    return aux;
}
HASHING *CriarHashing()
{
    HASHING *Has = (HASHING *)malloc(sizeof(HASHING));
    Has->LChaves = CriarListaCHAVES();
    return Has;
}
void DestruirHashing(HASHING *H)
{
    if (!H) return;
    NO_CHAVE *Seguinte;
    NO_CHAVE *P = H->LChaves->Inicio;
    while (P)
    {
        Seguinte = P->Prox;
        DestruirListaL(P->DADOS);
        free (P->KEY);
        free (P);
        P = Seguinte;
    }
    free(H);
}
void AddHashing(HASHING *H, LIVRO *L)
{
    if (!H) return;
    if (!H->LChaves) return;
    NO_CHAVE *Key_colocar = FuncaoHashing(H, L);
    if (!Key_colocar)
    {
        Key_colocar = AddCHAVE(H->LChaves, L->AREA);
    }
    AddInicioL(Key_colocar->DADOS, L);
}

void ShowHashing(HASHING *H)
{
    if (!H) return;
    if (!H->LChaves) return;
    NO_CHAVE *P = H->LChaves->Inicio;
    while (P)
    {
        printf("Key: [%s]\n", P->KEY);
        ShowListaL(P->DADOS);
        P = P->Prox;
    }
}
NO_CHAVE *FuncaoHashing(HASHING *H, LIVRO *X)
{
    if (!H) return NULL;
    if (!H->LChaves) return NULL;

    NO_CHAVE *P = H->LChaves->Inicio;
    while (P)
    {
        if (stricmp(P->KEY, X->AREA) == 0)
            return P;
        P = P->Prox;
    }
    return NULL;
}
