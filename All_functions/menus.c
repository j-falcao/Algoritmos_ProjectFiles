#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  "global.h"

extern AlunoDataStruct aluno;

//Menu Folder Novos: Ficheiros.c
void MenuFilesNovos(){
    int opcao;
    do{
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
        printc("[red]**********************************[/red]\n");
        printc("[red]*********** Menu Files ***********[/red]\n");
        printc("[red]**********************************[/red]\n");
        printc("[red]**     0 -> Sair                **[/red]\n");
        printc("[red]**     1 -> Continuar           **[/red]\n");
        printc("[red]**     2 -> Importar dados      **[/red]\n");
        printc("[red]**********************************[/red]\n");
        printc("[yellow]ERRO FICHEIROS EM FALTA![/yellow]");
        printf("\nOpcao: ");
        scanf("%d", &opcao);
    switch (opcao){
      case 0:
        exit(0);
        break;
      case 1:
        printc("Deseja continuar com os dados [red]Corrompidos[/red]? ([red]0 - Não[/red]/[green]1 - Sim[/green]) ");
        scanf("%d", &opcao);
        if (opcao == 1){
            opcao = 0;
        }
        else{
            exit(0);
        }
        break;
      case 2:
        importDataTxtBin();
        opcao = 0;
        break;
      default:
        printf("Opcao invalida!\n");
        break;
    }
    }while (opcao != 0);
}

//MENU PRINCIPAL: main.c
int mainMenu(){
    int opcao;
    printf("**************************************************\n");
    printc("****************** [green]Menu Principal[/green] ****************\n");
    printf("**************************************************\n");
    printf("**        0 -> Sair                             **\n");
    printf("**        1 -> Login                            **\n");
    printf("**        2 -> Exportar / Importar Dados        **\n");
    printf("**************************************************\n");
    printf("Qual a opção que pretende?");
    scanf("%d", &opcao);
    return opcao;
}

//MENU IMPORTAR / EXPORTAR FILE: importExport.c
int importExportMenu(){
    int opcao;
    printf("**************************************************\n");
    printc("************ [red]Menu Importar / Exportar[/red] ************\n");
    printf("**************************************************\n");
    printf("**        0 -> Voltar                           **\n");
    printf("**        1 -> Importar (TXT -> BIN)            **\n");
    printf("**        2 -> Exportar (BIN -> TXT)            **\n");
    printf("**        3 -> Exportar (BIN -> CSV)            **\n");
    printf("**************************************************\n");
    printf("Qual a opção que pretende?");
    scanf("%d", &opcao);
    return opcao;
}

 
//MENU PRINCIPAL: login.c
void MenuPrincipal(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int opcao, i = 1;
    do{
        i = 0;
        printf("Bem vindo %s!\n", aluno.name);
        printc("**************************************************\n");
        printc("****************** [blue]Menu Principal[/blue] ****************\n");
        printc("**************************************************\n");
        printf("**        %d -> Sair                             **\n", i++);
        if (aluno.regime.perm.VerDisciplinas){
            printf("**        %d -> Ver Disciplinas                  **\n", i++);
        }
        if(aluno.regime.perm.CriarExames
            || aluno.regime.perm.InscritosExames
            || aluno.regime.perm.ListarExames
            || aluno.regime.perm.ListarExamesInscritos
            || aluno.regime.perm.EditarExames
            || aluno.regime.perm.ExportarExames
            || aluno.regime.perm.InscreverExames){
            printf("**        %d -> Menu Exames                      **\n", i++);
        }
        printf("**        %d -> Editar Conta de Utilizador       **\n", i++);
        if(aluno.regime.perm.CriarAluno
        || aluno.regime.perm.ListarAluno
        || aluno.regime.perm.ListarTodosAlunos
        || aluno.regime.perm.EditarAluno
        || aluno.regime.perm.RemoverAluno
        || aluno.regime.perm.CriarProfessor
        || aluno.regime.perm.ListarProfessor
        || aluno.regime.perm.EditarProfessor
        || aluno.regime.perm.RemoverProfessor
        || aluno.regime.perm.CriarCursos
        || aluno.regime.perm.ListarCursos
        || aluno.regime.perm.EditarCursos
        || aluno.regime.perm.RemoverCursos
        || aluno.regime.perm.ListarCursosDisciplinas
        || aluno.regime.perm.CriarRegimes
        || aluno.regime.perm.ListarRegimes
        || aluno.regime.perm.ListarRegimesPermissoes
        || aluno.regime.perm.EditarNomeRegimes
        || aluno.regime.perm.EditarPermissoesRegimes
        || aluno.regime.perm.MoverRegimes
        || aluno.regime.perm.RemoverRegimes
        || aluno.regime.perm.CriarSalas
        || aluno.regime.perm.ListarSalas
        || aluno.regime.perm.EditarSalas
        || aluno.regime.perm.RemoverSalas){
            printf("**        %d -> Menu admin                       **\n", i++);
        }
        printc("**************************************************\n");
        printc("Qual a opção que pretende?");
        scanf("%d", &opcao);
        i = 1;

        if (aluno.regime.perm.VerDisciplinas){
            if (opcao == i++){
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                printf("Minhas disciplinas: \n");
                ListarPropriasDisciplinas();
                getchar();
                getchar();
            }
        }

        if (aluno.regime.perm.CriarExames
            || aluno.regime.perm.InscritosExames
            || aluno.regime.perm.ListarExames
            || aluno.regime.perm.ListarExamesInscritos
            || aluno.regime.perm.EditarExames
            || aluno.regime.perm.ExportarExames
            || aluno.regime.perm.InscreverExames){
            if (opcao == i++){
                printf("Menu Exames");
                MenuExames(); 
            }
        }

        if (opcao == i++){
            editAccount();
        }

        if (aluno.regime.perm.CriarAluno
        || aluno.regime.perm.ListarAluno
        || aluno.regime.perm.ListarTodosAlunos
        || aluno.regime.perm.EditarAluno
        || aluno.regime.perm.RemoverAluno
        || aluno.regime.perm.CriarProfessor
        || aluno.regime.perm.ListarProfessor
        || aluno.regime.perm.EditarProfessor
        || aluno.regime.perm.RemoverProfessor
        || aluno.regime.perm.CriarCursos
        || aluno.regime.perm.ListarCursos
        || aluno.regime.perm.EditarCursos
        || aluno.regime.perm.RemoverCursos
        || aluno.regime.perm.ListarCursosDisciplinas
        || aluno.regime.perm.CriarRegimes
        || aluno.regime.perm.ListarRegimes
        || aluno.regime.perm.ListarRegimesPermissoes
        || aluno.regime.perm.EditarNomeRegimes
        || aluno.regime.perm.EditarPermissoesRegimes
        || aluno.regime.perm.MoverRegimes
        || aluno.regime.perm.RemoverRegimes
        || aluno.regime.perm.CriarSalas
        || aluno.regime.perm.ListarSalas
        || aluno.regime.perm.EditarSalas
        || aluno.regime.perm.RemoverSalas
        ){
            if (opcao == i++){
                MenuAdmin();
            }
        }
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    } while (opcao != 0);
}

//MENU EXAMES: exames.c
void MenuExames(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int opcao;
    do{
        int i = 0;
        printc("**************************************************\n");
        printc("****************** [blue]Menu Exames[/blue] *******************\n");
        printc("**************************************************\n");
        printf("**        %d -> Sair                             **\n", i++);
        if (aluno.regime.perm.CriarExames){
            printf("**        %d -> Criar Exames                     **\n", i++); // Não esquecer de verificar se o aluno já está inscrito no exame e se Não se deve permitir marcar exames de um mesmo ano curricular com uma diferença de dias inferior a 3 dias e a data não pode ser num fim de semana ou feriado. FAZER A SELEÇÃO DE SALAS E DATA/HORA QUE OCORRERÁ.
        }
        if (aluno.regime.perm.InscreverExames){
            printf("**        %d -> Inscrever em Exames              **\n", i++); // Não esquecer de verificar se o aluno já está inscrito no exame e se Não se deve permitir marcar exames de um mesmo ano curricular com uma diferença de dias inferior a 3 dias e a data não pode ser num fim de semana ou feriado.
        }
        if (aluno.regime.perm.InscritosExames){
            printf("**        %d -> Inscritos em Exames              **\n", i++);
        }
        if (aluno.regime.perm.ListarExames){
            printf("**        %d -> Listar Exames                    **\n", i++);
        }
        if (aluno.regime.perm.ListarExamesInscritos){
            printf("**        %d -> Listar Exames Inscritos          **\n", i++);
        }
        if (aluno.regime.perm.EditarExames){
            printf("**        %d -> Editar Exames                    **\n", i++);
        }
        if (aluno.regime.perm.ExportarExames){
            printf("**        %d -> Exportar Exames                  **\n", i++);
        }
        printc("**************************************************\n");
        printc("Qual a opção que pretende?");
        scanf("%d", &opcao);
        i = 1;
        if (opcao == 0){
            printf("[lw]A fechar o programa...[/lw]");
        }
        if (aluno.regime.perm.CriarExames){
            if (opcao == i++){
                criarExame();
            }
        }
        if (aluno.regime.perm.InscreverExames){
            if (opcao == i++){
                inscreverExame();
            }
        }
        if (aluno.regime.perm.InscritosExames){
            if (opcao == i++){
                listarInscritos(1);
            }
        }
        if (aluno.regime.perm.ListarExames){
            if (opcao == i++){
                listarExames();
            }
        }
        if (aluno.regime.perm.ListarExamesInscritos){
            if (opcao == i++){
                listarExamesdeumAluno();
            }
        }
        if (aluno.regime.perm.EditarExames){
            if (opcao == i++){
                //editarExame();
            }
        }
        if (aluno.regime.perm.ExportarExames){
            if (opcao == i++){
                //exportarExames();
            }
        }
    }while(opcao != 0);
}

//MENU EDITAR CONTA: currentUser.c
int MenuEditarConta(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int opcao;
    printc("**************************************************\n");
    printc("**************** [blue]Menu Editar Conta[/blue] ***************\n");
    printc("**************************************************\n");
    printf("**            0 -> Sair                         **\n");
    printf("**            1 -> Editar Nome                  **\n");
    printf("**            2 -> Editar Password              **\n");
    printc("**************************************************\n");
    printc("Qual a opção que pretende?");
    scanf("%d", &opcao);
    return opcao;
}

//MENU ADMIN: admin.c
void MenuAdmin(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int opcao, i = 1;
    do{
        i = 0;
        printc("**************************************************\n");
        printc("**************** [blue]Menu Administração[/blue] **************\n");
        printc("**************************************************\n");
        printf("**        %d -> Sair                             **\n", i++);
        if(aluno.regime.perm.CriarAluno
        || aluno.regime.perm.ListarAluno
        || aluno.regime.perm.ListarTodosAlunos
        || aluno.regime.perm.EditarAluno
        || aluno.regime.perm.RemoverAluno){
            printf("**        %d -> Menu Alunos                      **\n", i++);
        }
        if(aluno.regime.perm.CriarProfessor
        || aluno.regime.perm.ListarProfessor
        || aluno.regime.perm.EditarProfessor
        || aluno.regime.perm.RemoverProfessor){
            printf("**        %d -> Menu Professor                   **\n", i++);
        }
        if (aluno.regime.perm.CriarCursos
        || aluno.regime.perm.ListarCursos
        || aluno.regime.perm.EditarCursos
        || aluno.regime.perm.RemoverCursos
        || aluno.regime.perm.ListarCursosDisciplinas){
            printf("**        %d -> Menu Cursos                      **\n", i++);
        }
        if (aluno.regime.perm.CriarRegimes
        || aluno.regime.perm.ListarRegimes
        || aluno.regime.perm.ListarRegimesPermissoes
        || aluno.regime.perm.EditarNomeRegimes
        || aluno.regime.perm.EditarPermissoesRegimes
        || aluno.regime.perm.MoverRegimes
        || aluno.regime.perm.RemoverRegimes){
            printf("**        %d -> Menu Regimes                     **\n", i++);
        }
        if (aluno.regime.perm.CriarSalas
        || aluno.regime.perm.ListarSalas
        || aluno.regime.perm.EditarSalas
        || aluno.regime.perm.RemoverSalas){
            printf("**        %d -> Menu Salas                       **\n", i++);
        }
        printc("**************************************************\n");
        printc("Qual a opção que pretende?");
        scanf("%d", &opcao);
        int i = 1;

        if (aluno.regime.perm.CriarAluno
        || aluno.regime.perm.ListarAluno
        || aluno.regime.perm.ListarTodosAlunos
        || aluno.regime.perm.EditarAluno
        || aluno.regime.perm.RemoverAluno){
            if (opcao == i++){
                MenuAlunos();
            }
        }

        if (aluno.regime.perm.CriarProfessor
        || aluno.regime.perm.ListarProfessor
        || aluno.regime.perm.EditarProfessor
        || aluno.regime.perm.RemoverProfessor){
            if (opcao == i++){
                MenuProfessor();
            }
        }

        if (aluno.regime.perm.CriarCursos
        || aluno.regime.perm.ListarCursos
        || aluno.regime.perm.EditarCursos
        || aluno.regime.perm.RemoverCursos
        || aluno.regime.perm.ListarCursosDisciplinas){
            if (opcao == i++){
                MenuCursos();
            }
        }
        if (aluno.regime.perm.CriarRegimes
        || aluno.regime.perm.ListarRegimes
        || aluno.regime.perm.ListarRegimesPermissoes
        || aluno.regime.perm.EditarNomeRegimes
        || aluno.regime.perm.EditarPermissoesRegimes
        || aluno.regime.perm.MoverRegimes
        || aluno.regime.perm.RemoverRegimes){
            if (opcao == i++){
                MenuRegimes();
            }
        }
        if (aluno.regime.perm.CriarSalas
        || aluno.regime.perm.ListarSalas
        || aluno.regime.perm.EditarSalas
        || aluno.regime.perm.RemoverSalas){
            if (opcao == i++){
                MenuSalas();
            }
        }
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    } while (opcao != 0);
}

void MenuAlunos(){
    int opcao, i = 0;
    do{
        i = 1;
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
        printc("**************************************************\n");
        printc("******************* [blue]Menu Alunos[/blue] ******************\n");
        printc("**************************************************\n");
        printf("**        0 -> Sair                             **\n");
        if (aluno.regime.perm.ListarTodosAlunos){
            printf("**        %d -> Listar Todos os Aluno            **\n", i++);
        }
        if (aluno.regime.perm.ListarAluno){
            printf("**        %d -> Listar Aluno (ID)                **\n", i++);
        }
        if (aluno.regime.perm.CriarAluno){
            printf("**        %d -> Criar Aluno                      **\n", i++);
        }
        if (aluno.regime.perm.EditarAluno){
            printf("**        %d -> Editar Aluno                     **\n", i++);
        }
        if (aluno.regime.perm.RemoverAluno){
            printf("**        %d -> Remover Aluno                    **\n", i++);
        }
        printc("**************************************************\n");
        printc("Qual a opção que pretende?");
        scanf("%d", &opcao);

        i = 1;

        if (aluno.regime.perm.ListarTodosAlunos){
            if (opcao == i++){
                listarTodosAlunos();
            }
        }

        if (aluno.regime.perm.ListarAluno){
            if (opcao == i++){
                listarAluno();
            }
        }

        if (aluno.regime.perm.CriarAluno){
            if (opcao == i++){
                criarAluno();
            }
        }

        if (aluno.regime.perm.EditarAluno){
            if (opcao == i++){
                alterarAluno();
            }
        }

        if (aluno.regime.perm.RemoverAluno){
            if (opcao == i++){
                apagarAluno();
            }
        }
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    } while (opcao != 0);
}

int menuEditAluno(){
    int opcao, i = 0;
    printc("**************************************************\n");
    printc("***************** [blue]Menu Editar Aluno[/blue] **************\n");
    printc("**************************************************\n");
    printf("**        %d -> Sair                             **\n", i++);
    printf("**        %d -> Editar Nome                      **\n", i++);
    printf("**        %d -> Editar Password                  **\n", i++);
    printf("**        %d -> Editar Regime                    **\n", i++);
    printf("**        %d -> Editar Curso                     **\n", i++);
    printf("**        %d -> Editar Ano                       **\n", i++);
    printc("**************************************************\n");
    printc("Qual a opção que pretende?");
    scanf("%d", &opcao);
    return opcao;
}


//MENU PROFESSOR: professor.c
void MenuProfessor(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int opcao, i = 0;
    do{
        i = 0;
        printc("**************************************************\n");
        printc("****************** [blue]Menu Professor[/blue] ****************\n");
        printc("**************************************************\n");
        printf("**        %d -> Sair                             **\n", i++);
        if (aluno.regime.perm.CriarProfessor){
            printf("**        %d -> Criar Professor                  **\n", i++);
        }
        if (aluno.regime.perm.ListarProfessor){
            printf("**        %d -> Listar Professor                 **\n", i++);
        }
        if (aluno.regime.perm.EditarProfessor){
            printf("**        %d -> Editar Professor                 **\n", i++);
        }
        if (aluno.regime.perm.RemoverProfessor){
            printf("**        %d -> Remover Professor                **\n", i++);
        }
        printc("**************************************************\n");
        printc("Qual a opção que pretende?");
        scanf("%d", &opcao);
        int i = 1;

        if (aluno.regime.perm.CriarProfessor){
            if (opcao == i++){
                criarProfessor(); 
            }
        }
        if (aluno.regime.perm.ListarProfessor){
            if (opcao == i++){
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                listarProfessor(); 
                printc("Pressione [red]ENTER[/red] para continuar...");
                getchar();
                getchar();
            }
        }
        if (aluno.regime.perm.EditarProfessor){
            if (opcao == i++){
                listarProfessor();
                editarProfessor();
            }
        }
        if (aluno.regime.perm.RemoverProfessor){
            if (opcao == i++){
                listarProfessor();
                removerProfessor();
            }
        }

        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    } while (opcao != 0);
}

//MENU CURSOS: disciplinas.c && cursosdisciplinas.c && UnidadesCurriculares.c
void MenuCursos(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int opcao, i = 1;
    do{
        i = 0;
        printc("**************************************************\n");
        printc("******************* [blue]Menu Cursos[/blue] ******************\n");
        printc("**************************************************\n");
        printf("**        %d -> Sair                             **\n", i++);
        if (aluno.regime.perm.EditarCursos){
            printf("**        %d -> Editar Cursos                    **\n", i++);;
        }
        if (aluno.regime.perm.ListarCursos){ 
            printf("**        %d -> Listar Cursos                    **\n", i++);
        }
            if (aluno.regime.perm.ListarCursosDisciplinas){                                        
            printf("**        %d -> Listar Cursos/Disciplinas        **\n", i++);
        }
        if (aluno.regime.perm.ListarCursosDisciplinas
        || aluno.regime.perm.CriarDisciplinas
        || aluno.regime.perm.ListarDisciplinas
        || aluno.regime.perm.EditarDisciplinas
        || aluno.regime.perm.RemoverDisciplinas
        || aluno.regime.perm.VerDisciplinas){
            printf("**        %d -> Menu Disciplinas                 **\n", i++);
        }
        printc("**************************************************\n");
        printc("Qual a opção que pretende?");
        scanf("%d", &opcao);
        int i = 1;

        if (aluno.regime.perm.EditarCursos){
            if (opcao == i++){
                EditarCursos();
            }
        }

        if (aluno.regime.perm.ListarCursos){
            if (opcao == i++){
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                ListarCursos();
                printc("Pressione [red]ENTER[/red] para continuar...");
                getchar();
                getchar();
            }
        }

        if (aluno.regime.perm.ListarCursosDisciplinas){
            if (opcao == i++){
                ListarCursosDisciplinas();
                getchar();
                getchar();
            }
        }
        if (aluno.regime.perm.ListarCursosDisciplinas
        || aluno.regime.perm.CriarDisciplinas
        || aluno.regime.perm.ListarDisciplinas
        || aluno.regime.perm.EditarDisciplinas
        || aluno.regime.perm.RemoverDisciplinas
        || aluno.regime.perm.VerDisciplinas){
            if (opcao == i++){
               MenuDisciplinas();
            }
        }
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    } while (opcao != 0);
}

void MenuDisciplinas(){
    int opcao, i = 0;
    do{
        i = 0;
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
        printc("**************************************************\n");
        printc("***************** [blue]Menu Disciplinas[/blue] ***************\n");
        printc("**************************************************\n");
        printf("**        0 -> Sair                             **\n");
        if (aluno.regime.perm.ListarDisciplinas){
            printf("**        1 -> Listar Disciplinas               **\n");
        }
        if (aluno.regime.perm.CriarDisciplinas){
            printf("**        2 -> Criar Disciplinas                **\n");
        }
        if (aluno.regime.perm.EditarDisciplinas){
            printf("**        3 -> Editar Disciplinas               **\n");
        }
        if (aluno.regime.perm.RemoverDisciplinas){
            printf("**        4 -> Remover Disciplinas              **\n");
        }
        printc("**************************************************\n");
        printc("Qual a opção que pretende?");
        scanf("%d", &opcao);

        i = 1;

        if (aluno.regime.perm.ListarDisciplinas){
            if (opcao == i++){
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                ListarDisciplinas();
                printc("Pressione [red]ENTER[/red] para continuar...");
                getchar();
                getchar();
            }
        }

        if (aluno.regime.perm.CriarDisciplinas){
            if (opcao == i++){
                CriarDisciplina();
            }
        }

        if (aluno.regime.perm.EditarDisciplinas){
            if (opcao == i++){
                EditarDisciplina();
            }
        }

        if (aluno.regime.perm.RemoverDisciplinas){
            if (opcao == i++){
                RemoverDisciplina();
            }
        }
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    } while (opcao != 0);
}

//MENU SALAS: salas.c
void MenuSalas(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int opcao, i = 0;
    do{
        i = 0;
        printc("**************************************************\n");
        printc("******************** [blue]Menu Salas[/blue] *****************\n");
        printc("**************************************************\n");
        printf("**        %d -> Sair                            **\n", i++);
        if (aluno.regime.perm.CriarSalas){
            printf("**        %d -> Criar Salas                     **\n", i++);
        }
        if (aluno.regime.perm.ListarSalas){
            printf("**        %d -> Listar Salas                    **\n", i++);
        }
        if (aluno.regime.perm.EditarSalas){
            printf("**        %d -> Editar Salas                    **\n", i++);
        }
        if (aluno.regime.perm.RemoverSalas){
            printf("**        %d -> Remover Salas                   **\n", i++);
        }
        printc("**************************************************\n");
        printc("Qual a opção que pretende?");
        scanf("%d", &opcao);

        int i = 1;

        if (aluno.regime.perm.CriarSalas){
            if (opcao == i++){
                criarSala();
            }
        }
        if (aluno.regime.perm.ListarSalas){
            if (opcao == i++){
                listarSalas();
            }
        }
        if (aluno.regime.perm.EditarSalas){
            if (opcao == i++){
                listarSalas();
                editarSala(); 
            }
        }
        if (aluno.regime.perm.RemoverSalas){
            if (opcao == i++){
                removerSala();
            }
        }

        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    } while (opcao != 0);
}


//MENU REGIMES: regimes.c
void MenuRegimes(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int opcao, i = 1;
    do{
        i = 0;
        printc("**************************************************\n");
        printc("******************* [blue]Menu Regimes[/blue] *****************\n");
        printc("**************************************************\n");
        printf("**        %d -> Sair                             **\n", i++);
        if(aluno.regime.perm.ListarRegimes){
            printf("**        %d -> Listar Regimes                   **\n", i++);
        }
        if(aluno.regime.perm.ListarRegimesPermissoes){
            printf("**        %d -> Listar Regimes Permissões        **\n", i++);
        }
        if(aluno.regime.perm.CriarRegimes){
            printf("**        %d -> Criar Regime                     **\n", i++);
        }
        if (aluno.regime.perm.EditarNomeRegimes
        || aluno.regime.perm.EditarPermissoesRegimes){
            printf("**        %d -> Editar Regime                    **\n", i++);
        }
        if (aluno.regime.perm.MoverRegimes){
            printf("**        %d -> Mover Regime para outro Regime   **\n", i++);
        }
        if (aluno.regime.perm.RemoverRegimes){
            printf("**        %d -> Remover Regime                   **\n", i++);
        }
        printc("**************************************************\n");
        printc("Qual a opção que pretende?");
        scanf("%d", &opcao);
        int i = 1;

        if (aluno.regime.perm.ListarRegimes){
            if (opcao == i++){
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                listarRegimes();
                printc("Pressione [red]ENTER[/red] para continuar...");
                getchar();
                getchar();
            }
        }

        if (aluno.regime.perm.ListarRegimesPermissoes){
            if (opcao == i++){
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                listarRegimesPermissoes();
                printc("Pressione [red]ENTER[/red] para continuar...");
                getchar();
                getchar();
            }
        }

        if (aluno.regime.perm.CriarRegimes){
            if (opcao == i++){
                criarRegime();
            }
        }

        if (aluno.regime.perm.EditarNomeRegimes
        || aluno.regime.perm.EditarPermissoesRegimes){
            if (opcao == i++){
                editarRegimeMenu();
            }
        }
        
        if (aluno.regime.perm.MoverRegimes){
            if (opcao == i++){
                moverRegimes();
            }
        }

        if (aluno.regime.perm.RemoverRegimes){
            if (opcao == i++){
               removerRegime();
            }
        }
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    } while (opcao != 0);
}

void editarRegimeMenu(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int opcao, i = 1;
    do{
        i = 0;
        printc("**************************************************\n");
        printc("**************** [blue]Menu Editar Regimes[/blue] *************\n");
        printc("**************************************************\n");
        printf("**        %d -> Sair                             **\n", i++);
        if(aluno.regime.perm.EditarNomeRegimes){
            printf("**        %d -> Editar Nome Do Regime            **\n", i++);
        }
        if(aluno.regime.perm.EditarPermissoesRegimes){
            printf("**        %d -> Editar Permissoes                **\n", i++);
        }
        printc("**************************************************\n");
        printc("Qual a opção que pretende?");
        scanf("%d", &opcao);
        int i = 1;

        if (aluno.regime.perm.EditarNomeRegimes){
            if (opcao == i++){
                editarNomeRegime();
            }
        }

        if (aluno.regime.perm.EditarPermissoesRegimes){
            if (opcao == i++){
                editarPermissoesRegime();
            }
        }
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    } while (opcao != 0);
}