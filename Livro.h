#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Listagenerica.h"


typedef struct {
    int ano;
    int mes;
    int dia;
} datpub;

typedef struct LIVRO {
    char *isbn; 
    char *Autor;
    char *titulo;
    char *AREA;
    int ID;
    datpub data;
    ListaGenerica *llivro;
} LIVRO;

int ler_livros(ListaGenerica *lp);
LIVRO *CriarLivro(char *_isbn, char *_autor, char *_titulo, char *_area, int _id, int _ano, int _mes, int _dia);
void MostrarLivro(LIVRO *P);
void DestruirLivro(LIVRO *P);


#endif // LIVRO_H_INCLUDED
