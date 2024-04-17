#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "Hashing.h"
#include "Biblioteca.h"

extern int LerInteiro(char *txt);
//-----------------------------------------
void Exemplo_Hashing()
{
    HASHING *Has = CriarHashing();
    PESSOA *X = CriarPessoa(1234, "Jose", "CAT-A");
    AddHashing(Has, X);
    X = CriarPessoa(567, "Pedro", "CAT-A");
    AddHashing(Has, X);
    X = CriarPessoa(456, "Luis", "CAT-A");
    AddHashing(Has, X);
    X = CriarPessoa(56, "Miguel", "CAT-B");
    AddHashing(Has, X);
    X = CriarPessoa(5690, "James Bond", "CAT-Z");
    AddHashing(Has, X);
    ShowHashing(Has);

    DestruirHashing(Has);
}
int Menu()
{
    printf(" --------------------------- \n");
    printf("| 1- Biblioteca             |\n");
    printf("| 2- Livros                 |\n");
    printf("| 0-Sair                    |\n");
    printf(" ---------------------------\n");
    int op;
    op = LerInteiro("Qual a o opcao? ");
    return op;
}


int MenuBiblio()
{
    printf(" ------------------------------- \n");
    printf("| 1- Adicionar Livro            |\n");
    printf("| 2- Remover Livro              |\n");
    printf("| 3- Listar Livros              |\n");
    printf("| 4- Determinar Area Superior   |\n");
    printf("| 0-Sair                        |\n");
    printf(" -------------------------------\n");
    int opBiblio;
    opBiblio = LerInteiro("Qual a o opcao? ");
    return opBiblio;
}

int MenuLivro ()
{
    printf(" --------------------------- \n");
    printf("| 1- Biblioteca             |\n");
    printf("| 2- Livros                 |\n");
    printf("| 0-Sair                    |\n");
    printf(" ---------------------------\n");
    int opLivro;
    opLivro = LerInteiro("Qual a o opcao? ");
    return opLivro;
}











int main()
{
    printf("Projecto-Biblioteca-Versao-Base!\n");
    //Exemplo_Hashing();
    BIBLIOTECA *Bib;
    Bib = CriarBiblioteca("Biblioteca-ESTGV", "log.txt");
    int OP, OPB, OPL;
    do
    {
        system("cls");
        OP = Menu();
        switch(OP)
        {
            case 1:
                system("cls");
                MenuBiblio;
                do
                {
                    OPB = MenuBiblio();
                    switch(OPB)
                    {
                       case 1:
                        break;


                    }
                }while (OPB != 0);
            break;








// -------------------- SEPARAÇÃO MENUS ----------------------










            case 2:  system("cls");
                    MenuLivro;
                break;


            default:
                printf("Opcao nao implementada\n"); break;
        }while (OPL != 0);

    }while (OP != 0);
    DestruirBiblioteca(Bib);
    return EXIT_SUCCESS; // ou EXIT_FAILURE
}
