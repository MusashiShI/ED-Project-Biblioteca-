#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int ano;
    int mes;
    int dia;
} datpub;

typedef struct LIVRO {
    char isbn[20]; 
    char *Autor;
    char *titulo;
    char *AREA;
    int ID;
    datpub data;
    struct LIVRO *next;
} LIVRO;

LIVRO *CriarLivro(int _id, char *_nome, char *_area);
void MostrarLivro(LIVRO *P);
void DestruirLivro(LIVRO *P);


#endif // LIVRO_H_INCLUDED
