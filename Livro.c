
#include "Livro.h"
/*
int ler_livros(LISTAL *lp)
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


        LIVRO *L = CriarLivro(CAMPOS[0], CAMPOS[1], CAMPOS[2], CAMPOS[3], atoi(CAMPOS[4]), atoi(CAMPOS[5]), atoi(CAMPOS[6]), atoi(CAMPOS[7])); //atof usa-se em float
        printf("%s\n",L->isbn);

        AddInicio(lp, L);
    }
    fclose(F);
    printf("Sai da Função %s", __func__);
    return SUCESSO;
}


*/



LIVRO *CriarLivro(char *_isbn, char *_autor, char *_titulo, char *_area, int _id, int _ano, int _mes, int _dia)
{
    LIVRO *L = (LIVRO *)malloc(sizeof(LIVRO));
    L->isbn = (char *)malloc((strlen(_isbn) + 1)*sizeof(char));
    strcpy(L->isbn, _isbn);

    L->Autor = (char *)malloc((strlen(_autor) + 1)*sizeof(char));
    strcpy(L->Autor, _autor);

    L->titulo = (char *)malloc((strlen(_titulo) + 1)*sizeof(char));
    strcpy(L->titulo, _titulo);

    L->AREA = (char *)malloc((strlen(_area) + 1)*sizeof(char));
    strcpy(L->AREA, _area);

    L->ID = _id;

    L->data.ano = _ano;
    L->data.mes = _mes;
    L->data.dia = _dia;

    return L;
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

