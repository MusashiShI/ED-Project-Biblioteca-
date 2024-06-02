#ifndef LISTAL_H_INCLUDED
#define LISTAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Livro.h"

typedef struct no
{
    LIVRO *Info;
    struct no *Prox;
}NO;

typedef struct
{
    int NEL;
    NO *Inicio;
}LISTAL;

LISTAL *CriarListaL();
//--------------------------------------------------
void AddInicioL(LISTAL *L, LIVRO *X);
//--------------------------------------------------
void ShowListaL(LISTAL *L);
//--------------------------------------------------
void DestruirListaL(LISTAL *L);
//--------------------------------------------------
//--------------------------------------------------
int SizeListaL(LISTAL *L);
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------

#endif // LISTAL_H_INCLUDED
