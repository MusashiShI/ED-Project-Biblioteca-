

#include "Pessoa.h"

/** \brief Permite Alocar e inicializar uma estrutura Pessoa
 *
 * \param _id int
 * \param _nome char*
 * \param _categoria char*
 * \return PESSOA*
 *
 */
PESSOA *CriarPessoa(int _id, char *_nome, char *_datan, int _idfreg)
{
    PESSOA *P = (PESSOA *)malloc(sizeof(PESSOA));
    P->nome = (char *)malloc((strlen(_nome) + 1)*sizeof(char));
    strcpy(P->nome, _nome);
    P->datan = (char *)malloc((strlen(_datan) + 1)*sizeof(char));
    strcpy(P->datan, _datan);
    P->ID = _id;
    P->idfreg = _idfreg;
    return P;
}
void MostrarPessoa(PESSOA *P)
{
    printf("\tID: %d | PESSOA: [%s] | DATA DE NASCIMENTO: [%s] | ID Freguesia: [%s]\n", P->ID, P->nome, P->datan, P->idfreg);
}
void DestruirPessoa(PESSOA *P)
{
    free (P->nome);
    free (P->datan);
    free (P);
}
