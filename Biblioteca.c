


#include "Biblioteca.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
/** \brief Aloca Memoria para uma Biblioteca
 *
 * \param _nome char* : Nome da Biblioteca
 * \param _logs char* : Ficheiro dos Logs
 * \return BIBLIOTECA* : Retorna o ponteiro para a biblioteca
 * \author Docentes & Alunos
 * \date   11/04/2024
 *
 */
BIBLIOTECA *CriarBiblioteca(char *_nome, char *_logs)
{
    BIBLIOTECA *Bib = (BIBLIOTECA *)malloc(sizeof(BIBLIOTECA));
    Bib->NOME = (char *)malloc((strlen(_nome) + 1) * sizeof(char));
    strcpy(Bib->NOME, _nome);
    strcpy(Bib->FICHEIRO_LOGS, _logs);
    Bib->HLivros = CriarHashing();
    Bib->HPessoas = CriarHashingp();
    //Bib->LRequisicoes = CriarListaRequisicoes();
    //Bib->LRequisitantes = CriarListaPessoas();
    return Bib;
}
//------------------------------------------------------------------------------
/** \brief Funcao para Mostrar toda a Biblioteca
 *
 * \param B BIBLIOTECA* : Pnteiro para a Biblioteca
 * \return void
 * \author : Docentes e Alunos
 * \date   : 11/04/2024
 */
void ShowLBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));
    printf("NOME BIBLIOTECA = [%s]\n", B->NOME);

    ShowHashing(B->HLivros);

    fclose(F_Logs);
}
void ShowPBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));
    printf("NOME BIBLIOTECA = [%s]\n", B->NOME);

    ShowHashingp(B->HPessoas);

    fclose(F_Logs);
}
void ShowBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));
    printf("NOME BIBLIOTECA = [%s]\n", B->NOME);
    printf("Quantidade de Categorias na Biblioteca = %d\n", B->HLivros->LChaves->NEL);
   // printf("Quantidade de Pessoas = %d\n",);

    // FUNÇÃO ADD: Mostrar Pessoas, Requesitantes, Livros requesitados (só o numero )
    printf("\n");
    ShowHashing(B->HLivros);

    fclose(F_Logs);
}
//------------------------------------------------------------------------------
void DestruirBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Vosso Codigo.....
    free (B->NOME);
    //------
    free(B);

    fclose(F_Logs);
}
//------------------------------------------------------------------------------
int LoadFicheiroBiblioteca(BIBLIOTECA *B)
{

   printf("Entrei na Função %s", __func__);
    FILE *F = fopen("livros.txt","r"); // FILE *F = fopen(ficheiro,"r");
    if(!F) return 0;

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
        AddHashing(B->HLivros, L);

    }
    fclose(F);
    printf("Sai da Função %s", __func__);
    return 1;
}
//----------------------------------------------------------------------------------------------
int LoadFicheiroBibliotecaPessoas(BIBLIOTECA *B)
{


   printf("Entrei na Função %s", __func__);
    FILE *F = fopen("requesitantes.txt","r"); // FILE *F = fopen(ficheiro,"r");
    if(!F) return 0;

    char BUFFER[1001];

    while(!feof(F))
    {

        fgets(BUFFER, 1000, F);
       // printf("Linha [%s] \n",BUFFER);
        int i = 0;
        char *CAMPOS[4];
        char *tokenp = strtok (BUFFER, "\t\n"); //Separa a string pelo '\t'
        while (tokenp != NULL)
        {

            CAMPOS[i] = tokenp;
            tokenp = strtok (NULL, "\t\n");
            i++;

        }

        PESSOA *P = CriarPessoa(CAMPOS[0], CAMPOS[1], CAMPOS[2], CAMPOS[3]);

        AddHashingp(B->HPessoas, P);


    }
    fclose(F);
    printf("Sai da Função %s", __func__);
    return 1;
}
//------------------------------------------------------------------------------

int AddLivroBiblioteca(BIBLIOTECA *B)
{
    LIVRO *L;
    int ano, mes, dia, ID;
    char isbn[20];
    char Autor[100];
    char titulo[100];
    char AREA[100];
    char buffer[100];

    FILE *F_Logs = fopen("logfile.txt", "a");// Exemplo de arquivo de log
    if (F_Logs == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo de log.\n");
        return 1;
    }
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    printf("\nColoque as Informações do Novo Livro:\n");
    limparBuffer();
    printf("ISBN ( Ex:978-0-7432-7356-5 ) : ");
    fgets(isbn, sizeof(isbn), stdin);
    isbn[strcspn(isbn, "\n")] = '\0';  // Remove o newline no final


    printf("\nAutor: ");
    fgets(Autor, sizeof(Autor), stdin);
    Autor[strcspn(Autor, "\n")] = '\0';  // Remove o newline no final

    printf("\nTitulo do Livro: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0';  // Remove o newline no final

    printf("\nArea: ");
    fgets(AREA, sizeof(AREA), stdin);
    AREA[strcspn(AREA, "\n")] = '\0';  // Remove o newline no final

    do {
        printf("\nID: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &ID);
        if (IDExiste(B->HLivros, ID)) {
            printf("ID ja existe! Por favor, insira um ID unico.\n");
        }
    } while (IDExiste(B->HLivros, ID));

    // Verificação da data
    do {
        printf("\nData Da Criacao\nAno: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &ano);

        printf("\nMes: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &mes);

        printf("\nDia: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &dia);

        if (!DataValida(ano, mes, dia)) {
            printf("Data invalida! Por favor, insira uma data valida.\n");
        }
    } while (!DataValida(ano, mes, dia));


    L = CriarLivro(isbn,Autor, titulo, AREA, ID, ano, mes, dia);
    AddHashing(B->HLivros, L);
    FILE *FR = fopen("livros.txt", "a"); // Abrir o arquivo em modo de escrita, adicionando ao final
    if (FR == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    fprintf(FR,"\n%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d",isbn, Autor, titulo, AREA, ID, dia, mes, ano);

    fclose(F_Logs);
    fclose(FR);
    return 1;
}
//------------------------------------------------------------------------------
/*
int RemoverLivroBiblioteca(BIBLIOTECA *B, int isbn)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------
*/
//------------------------------------------------------------------------------
LIVRO *LivroMaisRequisitadoBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return NULL;
}
//------------------------------------------------------------------------------
char *ApelidoMaisComum(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return NULL;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/*
int AddRequisitante(BIBLIOTECA *B, PESSOA *X)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------
int RequeitarLivro(BIBLIOTECA *B, PESSOA *X)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------
int DevolverLivro(BIBLIOTECA *B, PESSOA *X)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------
PESSOA *PesquisarRequisitante(BIBLIOTECA *B, int cod)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return NULL;
}
//------------------------------------------------------------------------------
*/
int ListarLivrosRequesitados(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));

    // Aqui o teu codigo

    fclose(F_Logs);
    return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------
int ListarClientes(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
   fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));
    printf("Entrei em %s na data %s\n", __func__, ctime(&now));






   fprintf(F_Logs, "Sai de %s na data %s\n", __func__, ctime(&now));
    printf("Sai de %s na data %s\n", __func__, ctime(&now));
    fclose(F_Logs);
    return 0;

}
//------------------------------------------------------------------------------
int ListarRequesitantes(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
   fprintf(F_Logs, "Entrei em %s na data %s\n", __func__, ctime(&now));
    printf("Entrei em %s na data %s\n", __func__, ctime(&now));






   fprintf(F_Logs, "Sai de %s na data %s\n", __func__, ctime(&now));
    printf("Sai de %s na data %s\n", __func__, ctime(&now));
    fclose(F_Logs);

    return 0;

}
//------------------------------------------------------------------------------
int ContarLivros(LISTAL *L) {
    int count = 0;
    NO *p = L->Inicio;
    while (p != NULL) {
        count++;
        p = p->Prox;
    }
    return count;
}

// Função para encontrar a categoria com mais livros
void CategoriaMaisLivros(HASHING *H) {

    if (!H || !H->LChaves) return;

    NO_CHAVE *P = H->LChaves->Inicio;
    NO_CHAVE *categoriaMaisLivros = NULL;
    int maxLivros = 0;

    while (P) {
        int numLivros = ContarLivros(P->DADOS);
        if (numLivros > maxLivros) {
            maxLivros = numLivros;
            categoriaMaisLivros = P;
        }
        P = P->Prox;
    }

    if (categoriaMaisLivros) {
        printf("A categoria com mais livros: [%s] com [%d] livros.\n", categoriaMaisLivros->KEY, maxLivros);
    } else {
        printf("Nenhuma categoria encontrada.\n");
    }
}


void LivrosMaisRecentes(HASHING *H) {
    if (!H || !H->LChaves) return;

    NO_CHAVE *P = H->LChaves->Inicio;
    int anoMaisRecente = 0;
    LISTAL *livrosRecentes = CriarListaL();  // Lista para armazenar os livros mais recentes

    // Encontrar o ano mais recente
    while (P) {
        NO *L = P->DADOS->Inicio;
        while (L) {
            if (L->Info->data.ano > anoMaisRecente) {
                anoMaisRecente = L->Info->data.ano;
            }
            L = L->Prox;
        }
        P = P->Prox;
    }

    // Encontrar os livros com o ano mais recente
    P = H->LChaves->Inicio;
    while (P) {
        NO *L = P->DADOS->Inicio;
        while (L) {
            if (L->Info->data.ano == anoMaisRecente) {
                AddInicioL(livrosRecentes, L->Info);
            }
            L = L->Prox;
        }
        P = P->Prox;
    }

    // Mostrar os livros mais recentes
    printf("Livros mais recentes (Ano: %d):\n", anoMaisRecente);
    ShowListaL(livrosRecentes);

    // Liberar a memória alocada para a lista temporária de livros recentes
    DestruirListaL(livrosRecentes);
}

//---------------------------------------------------------------------------------------

LIVRO* EncontrarLivroPorISBN(BIBLIOTECA *Bib, char *_isbn) {
    if (Bib == NULL || Bib->HLivros == NULL || Bib->HLivros->LChaves == NULL || Bib->HLivros->LChaves->Inicio == NULL)
        return NULL;

    NO_CHAVE *chaveAtual = Bib->HLivros->LChaves->Inicio;
    while (chaveAtual) {
        NO *P = chaveAtual->DADOS->Inicio;
        while (P) {
            if (strcmp(P->Info->isbn, _isbn) == 0) {
                MostrarLivro(P->Info);
                return P->Info; // Saímos da função porque encontramos o ISBN
            }
            P = P->Prox;
        }
        chaveAtual = chaveAtual->Prox;
    }

    printf("Livro com ISBN '%s' não encontrado.\n", _isbn);
    return NULL;
}
//---------------------------------------------------------------------------------------
LIVRO* PesquisarArea(BIBLIOTECA *Bib, char *_area) {
    if (Bib == NULL || Bib->HLivros == NULL || Bib->HLivros->LChaves == NULL || Bib->HLivros->LChaves->Inicio == NULL)
        return NULL;

    NO_CHAVE *chaveAtual = Bib->HLivros->LChaves->Inicio;
    while (chaveAtual) {
        NO *P = chaveAtual->DADOS->Inicio;
        while (P) {
            if (strcmp(P->Info->AREA, _area) == 0) {
                        printf("Area '%s' encontrado.\n", _area);
            P = P->Prox;
        }
        chaveAtual = chaveAtual->Prox;
    }
    }
    printf("Area '%s' não encontrado.\n", _area);
    return NULL;
}
//---------------------------------------------------------------------------------------
LIVRO* ExistenciaDoLivroPorISBN(BIBLIOTECA *Bib, char *_isbn) {
    if (Bib == NULL || Bib->HLivros == NULL || Bib->HLivros->LChaves == NULL || Bib->HLivros->LChaves->Inicio == NULL)
        return NULL;

    NO_CHAVE *chaveAtual = Bib->HLivros->LChaves->Inicio;
    while (chaveAtual) {
        NO *P = chaveAtual->DADOS->Inicio;
        while (P) {
            if (strcmp(P->Info->isbn, _isbn) == 0) {
                printf("\n Livro Existe: ");
                MostrarLivro(P->Info);
                return P->Info;
            }
            P = P->Prox;
        }
        chaveAtual = chaveAtual->Prox;
    }

    printf("Livro com ISBN '%s' não encontrado.\n", _isbn);
    return NULL;
}

//---------------------------------------------------------------------------------------
PESSOA* EncontrarPessoaPorID(BIBLIOTECA *Bib, char *_id) {
    if (Bib == NULL || Bib->HPessoas == NULL || Bib->HPessoas->PChaves == NULL || Bib->HPessoas->PChaves->Inicio == NULL)
        return NULL;

    NO_CHAVEp *chaveAtual = Bib->HPessoas->PChaves->Inicio;
    while (chaveAtual) {
        NOp *P = chaveAtual->DADOS->Inicio;
        while (P) {
            if (strcmp(P->Info->ID, _id) == 0) {
                MostrarPessoa(P->Info);
                return P->Info; // Saímos da função porque encontramos o ISBN
            }
            P = P->Prox;
        }
        chaveAtual = chaveAtual->Prox;
    }

    printf("ID '%s' não encontrado.\n", _id);
    return NULL;
}
//-----------------------------------------------------------------------------------------
int IDExiste(HASHING *H, int ID) {
    NO_CHAVE *P = H->LChaves->Inicio;
    while (P) {
        NO *L = P->DADOS->Inicio;
        while (L) {
            if (L->Info->ID == ID) {
                return 1; // ID já existe
            }
            L = L->Prox;
        }
        P = P->Prox;
    }
    return 0; // ID não existe
}

int DataValida(int ano, int mes, int dia) {
    if (mes < 1 || mes > 12) {
        return 0;
    }

    int diasNoMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        diasNoMes[1] = 29;
    }
    if (dia < 1 || dia > diasNoMes[mes - 1]) {
        return 0;
    }

    return 1;
}
int removerLivroPorISBN(BIBLIOTECA *bib, char *_isbn) {
    if (bib == NULL || _isbn == NULL || bib->HLivros == NULL || bib->HLivros->LChaves == NULL) return 0;

    LISTA_CHAVES *listaChaves = bib->HLivros->LChaves;
    NO_CHAVE *chaveAtual = listaChaves->Inicio;

    while (chaveAtual != NULL) {
        LISTAL *lista = chaveAtual->DADOS;
        NO *atual = lista->Inicio;
        NO *anterior = NULL;

        while (atual != NULL) {
            if (strcmp(atual->Info->isbn, _isbn) == 0) {
                if (anterior == NULL) {
                    // Remover o primeiro nó
                    lista->Inicio = atual->Prox;
                } else {
                    // Remover nó do meio ou final
                    anterior->Prox = atual->Prox;
                }
                free(atual->Info->isbn);
                free(atual->Info->Autor);
                free(atual->Info->titulo);
                free(atual->Info->AREA);
                free(atual->Info);
                free(atual);
                lista->NEL--;
                return 1; // Sucesso
            }
            anterior = atual;
            atual = atual->Prox;
        }

        chaveAtual = chaveAtual->Prox;
    }

    return 0; // Livro não encontrado
}
