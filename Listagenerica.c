#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Listagenerica.h"
#include "Biblioteca.h"

int Aleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

ListaGenerica *CriarLG()
{
    ListaGenerica *L = (ListaGenerica *)malloc(sizeof(ListaGenerica));
    L->Inicio = NULL;
    L->NEL = 0;
    return L;
}

void DestruirLG(ListaGenerica *lg, void (*fdest)(void *))
{
    if (!lg) return;
    NOG *P = lg->Inicio;
    NOG *AUX;
    while(P)
    {
        AUX = P->Prox;
        fdest(P->Info);
        free(P);
        P = AUX;
    }
    free(lg);
}

void MostrarLG(ListaGenerica *lg, void (*f)(void *))
{
    if (!lg) return;
    printf("Numero elementos da Lista: [%d]\n", lg->NEL);
    NOG *P = lg->Inicio;
    while(P)
    {
        f(P->Info);
        P = P->Prox;
    }
}

void AddLG(ListaGenerica *lg, void *X)
{
    if (!lg || !X) return;
    NOG *P = (NOG *)malloc(sizeof(NOG));
    P->Prox = lg->Inicio;
    P->Info = X;
    lg->Inicio = P;
    lg->NEL++;
}

int PertenceLG(ListaGenerica *lg, void *X, int (*fcomp)(void *, void *))
{
    if (!lg || !X) return INSUCESSO;
    NOG *P = lg->Inicio;
    while(P)
    {
        if (fcomp(P->Info, X) == 1) return SUCESSO;
        P = P->Prox;
    }
    return INSUCESSO;
}

int RemoverLG(ListaGenerica *L, void *X, int (*fcomp)(void *, void *), void (*fdest)(void *))
{
    if(!L || !X) return INSUCESSO;
    NOG *ANT = NULL;
    NOG *P = L->Inicio;
    int STOP = 0;
    while(P && !STOP)
    {
        if(fcomp(P->Info, X) == 1)
        {
            STOP = 1;
        }
        else
        {
            ANT = P;
            P = P->Prox;
        }
    }
    if(STOP == 1)
    {
        if(ANT)
            ANT->Prox = P->Prox;
        else
            L->Inicio = P->Prox;
        fdest(P->Info);
        free(P);
        L->NEL--;
        return SUCESSO;
    }
    return INSUCESSO;
}

size_t MemoriaOcupada(ListaGenerica *lg, size_t (*fmem)(void *X))
{
    if (!lg) return 0;
    size_t soma_mem = sizeof(*lg);
    NOG *P = lg->Inicio;
    while(P)
    {
        soma_mem += sizeof(*P) + fmem(P->Info);
        P = P->Prox;
    }
    return soma_mem;
}

void *GetElementoPosicao(ListaGenerica *lg, int pos)
{
    if (!lg) return NULL;
    if ((pos < 0) || (pos >= lg->NEL)) return NULL;
    NOG *P = lg->Inicio;
    for (int i = 0; i < pos; i++)
       {
            P = P->Prox;
       }
    return P->Info;
}
