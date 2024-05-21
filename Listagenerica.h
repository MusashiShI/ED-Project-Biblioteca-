#ifndef LISTAGENERICA_H_INCLUDED
#define LISTAGENERICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INSUCESSO -1
#define SUCESSO 1


typedef struct NOG
{
    void *Info;   //Informa��o de um n� da lista
    struct NOG *Prox;   //Ponteiro que aponta para o n� a seguir
}NOG;

typedef struct
{
    int NEL;    //N�mero de elementos da lista gen�rica
    NOG *Inicio;  //N� que aponta para o in�cio da lista
}ListaGenerica;

//Fun��es relativas � lista gen�rica
int Aleatorio(int min, int max);
ListaGenerica *CriarLG();
int RemoverLG(ListaGenerica *L, void *X, int (*fcomp)(void *, void *), void (*fdest)(void *));
void MostrarLG(ListaGenerica *lg, void (*f)(void *));
void DestruirLG(ListaGenerica *lg, void (*fdest)(void *));
void ShowLG(ListaGenerica *lg, void (*f)(void *));
void AddLG(ListaGenerica *lg, void *X);
int PertenceLG(ListaGenerica *lg, void *X, int (*fcomp)(void *, void *));
size_t MemoriaOcupada(ListaGenerica *lg, size_t (*fmem)(void *X));
void *GetElementoPosicao(ListaGenerica *lg, int pos);


#endif // LISTAGENERICA_H_INCLUDED
