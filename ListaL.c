
#include "ListaL.h"


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
        MostrarLivro(P->Info);
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
        DestruirLivro(Helder->Info);
        free (Helder);
        Helder = Martim;
    }
    free(L);
}

//--------------------------------------------------

//--------------------------------------------------
int SizeListaL(LISTAL *L)
{
    if (!L) return -1;
    return L->NEL;
}



//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
