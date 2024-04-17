#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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
    printf("| 1- Administração          |\n");
    printf("| 2- Cliente                |\n");
    printf("| 3- Biblioteca             |\n");
    printf("| 4- Livros                 |\n");
    printf("| 0-Sair                    |\n");
    printf(" ---------------------------\n");
    int op;
    op = LerInteiro("Qual a o opcao? ");
    return op;
}


int MenuAdm ()
{
    printf(" ---------------------------\n");
    printf("|       ADMINISTRAÇÃO       |\n");
    printf(" ---------------------------\n");

    int opadm;
    opadm = LerInteiro("Qual a o opcao? ");
    return opadm;
}

int Menuclient ()
{
    printf(" ---------------------------\n");
    printf("|          CLIENTE          |\n"); // Na requesição do livro o utilizador tem de adicionar as suas informaçõs tipo nome e ssas cenas.
    printf(" ---------------------------\n");

    int opclient;
    opclient = LerInteiro("Qual a o opcao? ");
    return opclient;
}



int MenuBiblio()
{
    printf(" ---------------------------------------\n");
    printf("| 1- Adicionar livro                    |\n");
    printf("| 2- Remover livro                      |\n");
    printf("| 3- Listar livros                      |\n");
    printf("| 4- Determinar area com mais livros    |\n");
    printf("| 5- Verificar existencia de um livro   |\n");
    printf("| 6- Livro mais requesitado             |\n");
    printf("| 7- Livro mais recente                 |\n");
    printf("| 8- Area mais requesitada              |\n");
    printf("| 0-Sair                                |\n");
    printf(" ---------------------------------------\n");
    int opBiblio;
    opBiblio = LerInteiro("Qual a o opcao? ");
    return opBiblio;
}

int MenuLivro ()
{
    printf(" --------------------------- \n");
    printf("| 1- Requesitar Livro       |\n"); // Na requesição do livro o utilizador tem de adicionar as suas informaçõs tipo nome e ssas cenas.
    printf("| 2- Devolver Livro         |\n");
    printf("| 5- Verificar Existenc     |\n");
    printf("| 0-Sair                    |\n");
    printf(" ---------------------------\n");
    int opLivro;
    opLivro = LerInteiro("Qual a o opcao? ");
    return opLivro;
}










int main()
{
    setlocale(LC_ALL, "Portuguese");
    printf("Projecto-Biblioteca-Versao-Base!\n");
    //Exemplo_Hashing();
    BIBLIOTECA *Bib;
    Bib = CriarBiblioteca("Biblioteca-ESTGV", "log.txt");
    int OP, OPB, OPL, OPA, OPC;
    do
    {
        system("cls");
        OP = Menu();
        switch(OP)
        {
// -------------------- SEPARAÇÃO MENUS ----------------------
// --------------------- ADMINISTRAÇÃO -----------------------
            case 1:
                system("cls");
                MenuAdm;
                do
                {
                    OPA = MenuAdm();
                    switch(OPA)
                    {
                       case 1:
                       break;
                    }
                }while (OPA != 0);
            break;



// -------------------- SEPARAÇÃO MENUS ----------------------
// ------------------------ CLIENTE --------------------------


            case 2:  system("cls");
                     Menuclient;
                                     do
                {
                    OPC = Menuclient();
                    switch(OPC)
                    {
                       case 1:
                        break;


                    }
                }while (OPC != 0);
            break;


// -------------------- SEPARAÇÃO MENUS ----------------------
// ---------------------- BIBLIOTECA -------------------------



            case 3:  system("cls");
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
// ------------------------ LIVROS --------------------------



            case 4:  system("cls");
                    MenuLivro;
                    do
                 {
                    OPL = MenuLivro();
                    switch(OPL)
                    {
                       case 1:
                        break;


                    }
                }while (OPL != 0);
            break;


            default:
                printf("Opcao nao implementada\n"); break;
        }while (OPL != 0);


    }while (OP != 0);
    DestruirBiblioteca(Bib);
    return EXIT_SUCCESS; // ou EXIT_FAILURE
}
