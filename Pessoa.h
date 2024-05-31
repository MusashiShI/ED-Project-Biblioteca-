#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int ID;
    char *nome;
    char *datan;
    int idfreg;
}PESSOA;

PESSOA *CriarPessoa(int _id, char *_nome, char *_datan, int _idfreg);
void MostrarPessoa(PESSOA *P);
void DestruirPessoa(PESSOA *P);

#endif // PESSOA_H_INCLUDED
