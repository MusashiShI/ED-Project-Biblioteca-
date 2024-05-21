
#include "Livro.h"










LIVRO *CriarLivro(int _id, char *_titulo, char *_area)
{
    LIVRO *P = (LIVRO *)malloc(sizeof(LIVRO));
    P->titulo = (char *)malloc((strlen(_titulo) + 1)*sizeof(char));
    strcpy(P->titulo, _titulo);
    P->AREA = (char *)malloc((strlen(_area) + 1)*sizeof(char));
    strcpy(P->AREA, _area);
    P->ID = _id;
    return P;
}
void MostrarLivro(LIVRO *P)
{
    printf("\tPESSOA: ID: %d [%s] [%s]\n", P->ID, P->titulo, P->AREA);
}
void DestruirLivro(LIVRO *P)
{
    free (P->titulo);
    free (P->AREA);
    free (P);
}
