
#include "ListaL.h"
//#include "Livro.h"

//--------------------------------------------------
/** \brief Permite alocar mem�ria para uma LISTAL
 *
 * \return LISTAL* : Retorna a LISTAL alocada
 * \date 10/04/2024
 * \author Docentes de ED
 */
LISTAL *CriarListaL()
{
    LISTAL *L = (LISTAL *)malloc(sizeof(LISTAL));
    L->NEL = 0;
    L->Inicio = NULL;
    return L;
}

//--------------------------------------------------
void AddInicioL(LISTAL *L, LIVRO *X)
{
    if (!L) return;
    NO *aux = (NO *)malloc(sizeof(NO));
    aux->Info = X;
    aux->Prox = L->Inicio;
    L->Inicio = aux;
    L->NEL++;
}

//--------------------------------------------------
void ShowListaL(LISTAL *L)
{
    if (!L) return;
    //printf("NEL = %d\n", L->NEL);
    NO *P = L->Inicio;
    while (P != NULL)
    {
        MostrarPessoa(P->Info);
        P = P->Prox;
    }
}

//--------------------------------------------------
void DestruirListaL(LISTAL *L)
{
    //printf("Implementar <%s>\n", __func__);
    if (!L) return;
    NO *Martim;
    NO *Helder = L->Inicio;
    while (Helder)
    {
        Martim = Helder->Prox;
        DestruirPessoa(Helder->Info);
        free (Helder);
        Helder = Martim;
    }
    free(L);
}

//--------------------------------------------------
LIVRO *PesquisarListaL(LISTAL *L, char *_isbn)
{
    printf("Implementar <%s>\n", __func__);
    if (L == NULL) return NULL;
    NO *P = L->Inicio;
    while (P)
    {
        if (stricmp(P->Info->isbn, _isbn) == 0)
            return P->Info;
        P = P->Prox;
    }
    return NULL;
}

//--------------------------------------------------
int SizeListaL(LISTAL *L)
{
    if (!L) return -1;
    return L->NEL;
}
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
