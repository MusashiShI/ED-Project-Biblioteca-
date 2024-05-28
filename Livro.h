#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED

#define INSUCESSO -1
#define SUCESSO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
    int ano;
    int mes;
    int dia;
}datpub;

typedef struct LIVRO {
    char *isbn;
    char *Autor;
    char *titulo;
    char *AREA;
    int ID;
    datpub data;

}LIVRO;


LIVRO *CriarLivro(char *_isbn, char *_autor, char *_titulo, char *_area, int _id, int _ano, int _mes, int _dia);
void MostrarLivro(LIVRO *P);
void DestruirLivro(LIVRO *P);


#endif // LIVRO_H_INCLUDED
