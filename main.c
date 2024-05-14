#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//#include "Lista.h"
//#include "Hashing.h"
//#include "Biblioteca.h"

//extern int LerInteiro(char *txt);

// Funções de exemplo para as operações
/*void Exemplo_Hashing()
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
}*/

int Menu()
{
    printf(" ---------------------------\n");
    printf("|        MENU GERAL         |\n");
    printf(" ---------------------------\n");
    printf("| 1- Administracao          |\n");
    printf("| 2- Cliente                |\n");
    printf("| 3- Biblioteca             |\n");
    printf("| 4- Livros                 |\n");
    printf("| 0- Sair                   |\n");
    printf(" ---------------------------\n");
    int op = 0;
    printf("Qual a opção? ");
    scanf("%d", &op);
    return op;
}

int MenuAdm()
{
    printf("   ---------------------------    \n");
    printf("  |       ADMINISTRACAO       |   \n");
    printf("   ---------------------------    \n");
    printf("| 1- Listar Livro                |\n");
    printf("| 2- Remover Livro               |\n");
    printf("| 3- Listar Clientes             |\n");
    printf("| 4- Listar Livros Requesitados  |\n");
    printf("| 5- Mostrar Biblioteca          |\n");
    printf("| 6- Destruir Biblioteca         |\n");
    printf("| 7- Verificar Memoria           |\n");
    printf("| 8- Listar Requesitantes        |\n");
    printf("| 9- Pesquisar Requesitante      |\n");
    printf("| 0- Sair                        |\n");
    printf(" --------------------------------\n");

    int opadm = 0;
    printf("Qual a opção? ");
    scanf("%d", &opadm);
    return opadm;
}

int Menuclient()
{
    printf(" ---------------------------\n");
    printf("|          CLIENTE          |\n");
    printf(" ---------------------------\n");
    printf("| 1- Requesitar Livro       |\n");
    printf("| 2- Devolver Livro         |\n");
    printf("| 3- Pesquisar Livro        |\n");
    printf("| 4- Pesquisar Area         |\n");
    printf("| 0- Sair                   |\n");
    printf(" ---------------------------\n");

    int opclient = 0;
    printf("Qual a opção? ");
    scanf("%d", &opclient);
    return opclient;
}

int MenuBiblio()
{
    printf("      ---------------------------       \n");
    printf("     |          BIBLIOTECA       |      \n");
    printf("      ---------------------------       \n");
    printf("| 1- Adicionar livro                    |\n");
    printf("| 2- Remover livro                      |\n");
    printf("| 3- Listar livros                      |\n");
    printf("| 4- Determinar area com mais livros    |\n");
    printf("| 5- Verificar existência de um livro   |\n");
    printf("| 6- Livro mais requesitado             |\n");
    printf("| 7- Livro mais recente                 |\n");
    printf("| 8- Area mais requesitada              |\n");
    printf("| 0- Sair                               |\n");
    printf(" ---------------------------------------\n");
    int opBiblio = 0;
    printf("Qual a opção? ");
    scanf("%d", &opBiblio);
    return opBiblio;
}

int MenuLivro()
{
    printf("     ---------------------------       \n");
    printf("    |           LIVRO           |      \n");
    printf("     ---------------------------       \n");
    printf("| 1- Pesquisar Livro                   |\n");
    printf("| 2- Registrar Livro                   |\n");
    printf("| 3- Verificar Existência de Livro     |\n");
    printf("| 0- Sair                              |\n");
    printf(" --------------------------------------\n");
    int opLivro = 0;
    printf("Qual a opção? ");
    scanf("%d", &opLivro);
    return opLivro;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    printf("Projeto-Biblioteca-Versão-Base!\n");

    // Exemplo_Hashing();
    // BIBLIOTECA *Bib;
    // Bib = CriarBiblioteca("Biblioteca-ESTGV", "log.txt");
    
    int OP, OPB, OPL, OPA, OPC;
    do
    {
        system("cls");
        OP = Menu();
        switch (OP)
        {
            case 1:
                system("cls");
                do
                {
                    OPA = MenuAdm();
                    switch (OPA)
                    {
                        case 1:
                            // ListarLivrosDaBiblioteca(Bib);
                            break;
                        case 2:
                            // RemoverLivroBiblioteca(BIBLIOTECA *B, int isbn);
                            break;
                        case 3:
                            // ListarClientes(BIBLIOTECA *B);
                            break;
                        case 4:
                            // ListarLivrosRequesitados(BIBLIOTECA *B);
                            break;
                        case 5:
                            // ShowBiblioteca(BIBLIOTECA *B);
                            break;
                        case 6:
                            // DestruirBiblioteca(BIBLIOTECA *B);
                            break;
                        case 7:
                          //  memoriaOcupada();
                            break;
                        case 8:
                            // PesquisarRequisitante(BIBLIOTECA *B, int cod);
                            break;
                    }
                } while (OPA != 0);
                break;

            case 2:
                system("cls");
                do
                {
                    OPC = Menuclient();
                    switch (OPC)
                    {
                        case 1:
                            // RequeitarLivro(BIBLIOTECA *B, PESSOA *X);
                            break;
                        case 2:
                            // DevolverLivro(BIBLIOTECA *B, PESSOA *X);
                            break;
                        case 3:
                            // Pesquisar Livro
                            break;
                    }
                } while (OPC != 0);
                break;

            case 3:
                system("cls");
                do
                {
                    OPB = MenuBiblio();
                    switch (OPB)
                    {
                        case 1:
                            // Adicionar livro
                            break;
                        case 2:
                            // Remover livro
                            break;
                    }
                } while (OPB != 0);
                break;

            case 4:
                system("cls");
                do
                {
                    OPL = MenuLivro();
                    switch (OPL)
                    {
                        case 1:
                            // Pesquisar Livro
                            break;
                    }
                } while (OPL != 0);
                break;

            default:
                if (OP != 0)
                    printf("Opção não implementada\n");
                break;
        }
    } while (OP != 0);

    // DestruirBiblioteca(Bib);
    return EXIT_SUCCESS; // ou EXIT_FAILURE
}
