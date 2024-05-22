#include "Listagenerica.h"
#include "Livro.h"
//#include "Listagenerica.h"






int ler_livros(ListaGenerica *lp) //int ler_livros(ListaGenerica *lp, char *ficheiro)
{
    printf("Entrei na Função %s", __func__);
    FILE *F = fopen("livros.txt","r"); // FILE *F = fopen(ficheiro,"r");
    if(!F) return INSUCESSO;

    char BUFFER[1001];

    while(!feof(F))
    {

        fgets(BUFFER, 1000, F);
       // printf("Linha [%s] \n",BUFFER);
        int i = 0;
        char *CAMPOS[8];
        char *token = strtok (BUFFER, "\t\n"); //Separa a string pelo '\t'
        while (token != NULL)
        {
            CAMPOS[i] = token;
            token = strtok (NULL, "\t\n");
            i++;
        }

        //printf("CODIGO : [%s]     NOME: [%s]", CAMPOS[0], CAMPOS[1]);
        LIVRO *L = CriarLivro(CAMPOS[0], CAMPOS[1], CAMPOS[2], CAMPOS[3], atoi(CAMPOS[4]), atoi(CAMPOS[5]), atoi(CAMPOS[6]), atoi(CAMPOS[7])); //atof usa-se em float
        printf("%s\n",CAMPOS[0]);
        //MostrarProduto(P);
        AddLG (lp, L);
    }
    fclose(F);
    printf("Sai da Função %s", __func__);
    return SUCESSO;
}



LIVRO *CriarLivro(char *_isbn, char *_autor, char *_titulo, char *_area, int _id, int _ano, int _mes, int _dia)
{
    LIVRO *P = (LIVRO *)malloc(sizeof(LIVRO));
    P->isbn = (char *)malloc((strlen(_isbn) + 1)*sizeof(char));
    strcpy(P->isbn, _isbn);

    P->Autor = (char *)malloc((strlen(_autor) + 1)*sizeof(char));
    strcpy(P->Autor, _autor);

    P->titulo = (char *)malloc((strlen(_titulo) + 1)*sizeof(char));
    strcpy(P->titulo, _titulo);

    P->AREA = (char *)malloc((strlen(_area) + 1)*sizeof(char));
    strcpy(P->AREA, _area);

    P->ID = _id;

    P->data.ano = _ano;
    P->data.mes = _mes;
    P->data.dia = _dia;

    return P;
}


void MostrarLivro(LIVRO *P)
{
    printf("\tPESSOA: ID: %d [%s] [%s]\n", P->ID, P->titulo, P->AREA);
}
void DestruirLivro(LIVRO *P)
{
    free (P->isbn);
    free (P->Autor);
    free (P->titulo);
    free (P->AREA);
    free (P);
}
