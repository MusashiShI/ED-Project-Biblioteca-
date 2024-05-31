

#include "Requesicao.h"

REQUISITANTE *CriarRequesitante(int _id, PESSOA *P, LIVRO *L)
{
    REQUISITANTE *Req = (REQUISITANTE *)malloc(sizeof(REQUISITANTE));

    Req->ID = _id;
    Req->Ptr_Req = P;
    Req->Ptr_Livro = L;
    return Req;
}
void MostrarRequisitante(REQUISITANTE *R)
{
    printf("REQ ID = %d\n", R->ID);
    MostrarPessoa(R->Ptr_Req);
    MostrarLivro(R->Ptr_Livro);
}
void DestruirRequisitante(REQUISITANTE *R)
{
    //free (R->Ptr_Livro); //OH Pá se tirares o comentario vais ter problemas!!!!
    //free (R->Ptr_Req); //OH Pá se tirares o comentario vais ter problemas!!!!
    free (R);
}
