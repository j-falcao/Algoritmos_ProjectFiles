#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

extern AlunoStruct *alunos;
extern regimeStruct *regimes;
extern courseStruct *courses;
extern int n_alunos, n_regimes, n_courses;
extern AlunoDataStruct aluno;
extern permissionFileStruct *perms_file;


void criarRegime(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    listarRegimes();
    regimes = realloc(regimes, (n_regimes + 1) * sizeof(regimeStruct));
    perms_file = realloc(perms_file, (n_regimes + 1) * sizeof(permissionFileStruct));
    regimes[n_regimes].id = regimes[n_regimes-1].id+1;
    regimes[n_regimes].name = malloc(100 * sizeof(char));
    printf("Introduza o nome do regime: ");
    scanf("%s", regimes[n_regimes].name);
    printf("Nome do regime: %s", regimes[n_regimes].name);
    regimes[n_regimes].name = realloc(regimes[n_regimes].name, (strlen(regimes[n_regimes].name) + 1));

    perms_file[n_regimes].id_regime = regimes[n_regimes-1].id+1;
    printc("\n[blue]Permissoes Exames:[/blue]\n");
    printc("Tem permissao para Criar Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.CriarExames = ValidarZeroUm();
    printc("Tem permissao para Ver Inscritos Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.InscritosExames = ValidarZeroUm();
    printc("Tem permissao para Listar Todos Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.ListarExames = ValidarZeroUm();
    printc("Tem permissao para Listar Exames de um aluno? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.ListarExamesInscritos = ValidarZeroUm();
    printc("Tem permissao para Editar Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.EditarExames = ValidarZeroUm();
    printc("Tem permissao para Exportar Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.ExportarExames = ValidarZeroUm();
    printc("Tem permissao para Inscrever Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.InscreverExames = ValidarZeroUm();

    printc("\n[blue]Permissoes Salas:[/blue]\n");
    printc("Tem permissao para Criar Salas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.CriarSalas = ValidarZeroUm();
    printc("Tem permissao para Listar Salas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.ListarSalas = ValidarZeroUm();
    printc("Tem permissao para Editar Salas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.EditarSalas = ValidarZeroUm();
    printc("Tem permissao para Remover Salas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.RemoverSalas = ValidarZeroUm();

    printc("\n[blue]Permissoes Professor:[/blue]\n");
    printc("Tem permissao para Criar Professor? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.CriarProfessor = ValidarZeroUm();
    printc("Tem permissao para Listar Professor? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.ListarProfessor = ValidarZeroUm();
    printc("Tem permissao para Editar Professor? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.EditarProfessor = ValidarZeroUm();
    printc("Tem permissao para Remover Professor? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.RemoverProfessor = ValidarZeroUm();

    printc("\n[blue]Permissoes Cursos:[/blue]\n");
    printc("Tem permissao para Criar Cursos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.CriarCursos = ValidarZeroUm();
    printc("Tem permissao para Listar Cursos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.ListarCursos = ValidarZeroUm();
    printc("Tem permissao para Editar Cursos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.EditarCursos = ValidarZeroUm();
    printc("Tem permissao para Remover Cursos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.RemoverCursos = ValidarZeroUm();
    printc("Tem permissao para Listar Cursos e Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.ListarCursosDisciplinas = ValidarZeroUm();

    printc("\n[blue]Permissoes Disciplinas:[/blue]\n");
    printc("Tem permissao para Criar Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.CriarDisciplinas = ValidarZeroUm();
    printc("Tem permissao para Listar Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.ListarDisciplinas = ValidarZeroUm();
    printc("Tem permissao para Editar Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.EditarDisciplinas = ValidarZeroUm();
    printc("Tem permissao para Remover Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.RemoverDisciplinas = ValidarZeroUm();
    printc("Tem permissao para Listar Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.ListarDisciplinas = ValidarZeroUm();
    printc("Tem permissao para Ver Proprias Disciplinas Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.VerDisciplinas = ValidarZeroUm();

    printc("\n[blue]Permissoes Alunos:[/blue]\n");
    printc("Tem permissao para Criar Alunos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.CriarAluno = ValidarZeroUm();
    printc("Tem permissao para Listar Aluno? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.ListarAluno = ValidarZeroUm();
    printc("Tem permissao para Listar Todos os Alunos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.ListarTodosAlunos = ValidarZeroUm();
    printc("Tem permissao para Editar Alunos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.EditarAluno = ValidarZeroUm();
    printc("Tem permissao para Remover Alunos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.RemoverAluno = ValidarZeroUm();

    printc("\n[blue]Permissoes Regimes:[/blue]\n");
    printc("Tem permissao para Criar Regimes? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.CriarRegimes = ValidarZeroUm();
    printc("Tem permissao para Listar Regimes? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.ListarRegimes = ValidarZeroUm();
    printc("Tem permissao para Listar Regimes e Permissões? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.ListarRegimesPermissoes = ValidarZeroUm();
    printc("Tem permissao para Editar Nome dos Regimes ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.EditarNomeRegimes = ValidarZeroUm();
    printc("Tem permissao para Editar permissões dos Regimes ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.EditarPermissoesRegimes = ValidarZeroUm();
    printc("Tem permissao para Mover Regimes Regimes ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.MoverRegimes = ValidarZeroUm();
    printc("Tem permissao para Remover Regimes? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
    perms_file[n_regimes].perm.RemoverRegimes = ValidarZeroUm();

    n_regimes++;
    saveBinRegimes();
    saveBinPermissions();
}

void editarNomeRegime(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    listarRegimes();
    int flag = 0, id;
    do{
        if(flag == 1)
            printc("\n[red]Por favor insira um ID válido![/red]\n");
        
        printf("\n\nPor favor Introduza o ID do regime que pretende editar: ");
        scanf("%d", &id);
        flag = 1;
        if (id == 1 || id == 2){
            printc("\n[red]Não pode editar nome do regime Administrador ou Professor![/red]\n");
            flag = 0;
        }
    }while (checkIfRegimeExists(id) == 0 || id == 1 || id == 2);

    int position = 0;
    for (int i = 0; i <= n_regimes; i++){
        if (id == regimes[i].id){
            position = i;
            break;
        }
    }
    
    printf("\n\nPor favor introduza o novo nome do regime: ");
    scanf("%s", regimes[position].name);
    saveBinRegimes();
    updateUser();
}

void editarPermissoesRegime(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    listarRegimesPermissoes();
    int flag = 0, id;
    do{
        if(flag == 1)
            printc("\n[red]Por favor insira um ID válido![/red]\n");

        printf("\n\nPor favor Introduza o ID do regime que pretende editar: ");
        scanf("%d", &id);
        flag = 1;
        if (id == 1){
            printc("\n[red]Não pode editar as permissões do regime Administrador![/red]\n");
            flag = 0;
        }
    }while (checkIfRegimeExists(id) == 0 || id == 1);

    int position = 0;
    for (int i = 0; i <= n_regimes; i++){
        if (id == regimes[i].id){
            position = i;
            break;
        }
    }

    if(id == 2){
        printc("[blue]Permissoes Exames:[/blue]\n");
        printc("Tem permissao para Criar Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.CriarExames = ValidarZeroUm();
        printc("Tem permissao para Ver Inscritos Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.InscritosExames = ValidarZeroUm();
        printc("Tem permissao para Listar Todos Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarExames = ValidarZeroUm();
        printc("Tem permissao para Listar Exames de um aluno? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarExamesInscritos = ValidarZeroUm();
        printc("Tem permissao para Editar Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.EditarExames = ValidarZeroUm();
        printc("Tem permissao para Exportar Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ExportarExames = ValidarZeroUm();

        printc("\n[blue]Permissoes Salas:[/blue]\n");
        printc("Tem permissao para Criar Salas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.CriarSalas = ValidarZeroUm();
        printc("Tem permissao para Listar Salas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarSalas = ValidarZeroUm();
        printc("Tem permissao para Editar Salas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.EditarSalas = ValidarZeroUm();
        printc("Tem permissao para Remover Salas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.RemoverSalas = ValidarZeroUm();

        printc("\n[blue]Permissoes Professor:[/blue]\n");
        printc("Tem permissao para Criar Professor? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.CriarProfessor = ValidarZeroUm();
        printc("Tem permissao para Listar Professor? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarProfessor = ValidarZeroUm();
        printc("Tem permissao para Editar Professor? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.EditarProfessor = ValidarZeroUm();
        printc("Tem permissao para Remover Professor? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.RemoverProfessor = ValidarZeroUm();

        printc("\n[blue]Permissoes Cursos:[/blue]\n");
        printc("Tem permissao para Criar Cursos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.CriarCursos = ValidarZeroUm();
        printc("Tem permissao para Listar Cursos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarCursos = ValidarZeroUm();
        printc("Tem permissao para Editar Cursos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.EditarCursos = ValidarZeroUm();
        printc("Tem permissao para Remover Cursos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.RemoverCursos = ValidarZeroUm();
        printc("Tem permissao para Listar Cursos e Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarCursosDisciplinas = ValidarZeroUm();

        printc("\n[blue]Permissoes Disciplinas:[/blue]\n");
        printc("Tem permissao para Criar Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.CriarDisciplinas = ValidarZeroUm();
        printc("Tem permissao para Listar Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarDisciplinas = ValidarZeroUm();
        printc("Tem permissao para Editar Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.EditarDisciplinas = ValidarZeroUm();
        printc("Tem permissao para Remover Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.RemoverDisciplinas = ValidarZeroUm();
        printc("Tem permissao para Listar Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarDisciplinas = ValidarZeroUm();

        printc("\n[blue]Permissoes Alunos:[/blue]\n");
        printc("Tem permissao para Criar Alunos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.CriarAluno = ValidarZeroUm();
        printc("Tem permissao para Listar Aluno? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarAluno = ValidarZeroUm();
        printc("Tem permissao para Listar Todos os Alunos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarTodosAlunos = ValidarZeroUm();
        printc("Tem permissao para Editar Alunos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.EditarAluno = ValidarZeroUm();
        printc("Tem permissao para Remover Alunos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.RemoverAluno = ValidarZeroUm();

        printc("\n[blue]Permissoes Regimes:[/blue]\n");
        printc("Tem permissao para Criar Regimes? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.CriarRegimes = ValidarZeroUm();
        printc("Tem permissao para Listar Regimes? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarRegimes = ValidarZeroUm();
        printc("Tem permissao para Listar Regimes e Permissões? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarRegimesPermissoes = ValidarZeroUm();
        printc("Tem permissao para Editar Nome dos Regimes ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.EditarNomeRegimes = ValidarZeroUm();
        printc("Tem permissao para Editar permissões dos Regimes ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.EditarPermissoesRegimes = ValidarZeroUm();
        printc("Tem permissao para Mover Regimes Regimes ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.MoverRegimes = ValidarZeroUm();
        printc("Tem permissao para Remover Regimes? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.RemoverRegimes = ValidarZeroUm();
    }
    else{
        printc("[blue]Permissoes Exames:[/blue]\n");
        printc("Tem permissao para Criar Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.CriarExames = ValidarZeroUm();
        printc("Tem permissao para Ver Inscritos Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.InscritosExames = ValidarZeroUm();
        printc("Tem permissao para Listar Todos Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarExames = ValidarZeroUm();
        printc("Tem permissao para Listar Exames de um aluno? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarExamesInscritos = ValidarZeroUm();
        printc("Tem permissao para Editar Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.EditarExames = ValidarZeroUm();
        printc("Tem permissao para Exportar Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ExportarExames = ValidarZeroUm();
        printc("Tem permissao para Inscrever Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.InscreverExames = ValidarZeroUm();

        printc("\n[blue]Permissoes Salas:[/blue]\n");
        printc("Tem permissao para Criar Salas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.CriarSalas = ValidarZeroUm();
        printc("Tem permissao para Listar Salas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarSalas = ValidarZeroUm();
        printc("Tem permissao para Editar Salas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.EditarSalas = ValidarZeroUm();
        printc("Tem permissao para Remover Salas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.RemoverSalas = ValidarZeroUm();

        printc("\n[blue]Permissoes Professor:[/blue]\n");
        printc("Tem permissao para Criar Professor? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.CriarProfessor = ValidarZeroUm();
        printc("Tem permissao para Listar Professor? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarProfessor = ValidarZeroUm();
        printc("Tem permissao para Editar Professor? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.EditarProfessor = ValidarZeroUm();
        printc("Tem permissao para Remover Professor? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.RemoverProfessor = ValidarZeroUm();

        printc("\n[blue]Permissoes Cursos:[/blue]\n");
        printc("Tem permissao para Criar Cursos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.CriarCursos = ValidarZeroUm();
        printc("Tem permissao para Listar Cursos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarCursos = ValidarZeroUm();
        printc("Tem permissao para Editar Cursos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.EditarCursos = ValidarZeroUm();
        printc("Tem permissao para Remover Cursos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.RemoverCursos = ValidarZeroUm();
        printc("Tem permissao para Listar Cursos e Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarCursosDisciplinas = ValidarZeroUm();

        printc("\n[blue]Permissoes Disciplinas:[/blue]\n");
        printc("Tem permissao para Criar Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.CriarDisciplinas = ValidarZeroUm();
        printc("Tem permissao para Listar Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarDisciplinas = ValidarZeroUm();
        printc("Tem permissao para Editar Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.EditarDisciplinas = ValidarZeroUm();
        printc("Tem permissao para Remover Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.RemoverDisciplinas = ValidarZeroUm();
        printc("Tem permissao para Listar Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarDisciplinas = ValidarZeroUm();
        printc("Tem permissao para Ver Proprias Disciplinas Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.VerDisciplinas = ValidarZeroUm();

        printc("\n[blue]Permissoes Alunos:[/blue]\n");
        printc("Tem permissao para Criar Alunos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.CriarAluno = ValidarZeroUm();
        printc("Tem permissao para Listar Aluno? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarAluno = ValidarZeroUm();
        printc("Tem permissao para Listar Todos os Alunos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarTodosAlunos = ValidarZeroUm();
        printc("Tem permissao para Editar Alunos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.EditarAluno = ValidarZeroUm();
        printc("Tem permissao para Remover Alunos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.RemoverAluno = ValidarZeroUm();

        printc("\n[blue]Permissoes Regimes:[/blue]\n");
        printc("Tem permissao para Criar Regimes? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.CriarRegimes = ValidarZeroUm();
        printc("Tem permissao para Listar Regimes? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarRegimes = ValidarZeroUm();
        printc("Tem permissao para Listar Regimes e Permissões? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.ListarRegimesPermissoes = ValidarZeroUm();
        printc("Tem permissao para Editar Nome dos Regimes ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.EditarNomeRegimes = ValidarZeroUm();
        printc("Tem permissao para Editar permissões dos Regimes ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.EditarPermissoesRegimes = ValidarZeroUm();
        printc("Tem permissao para Mover Regimes Regimes ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.MoverRegimes = ValidarZeroUm();
        printc("Tem permissao para Remover Regimes? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[position].perm.RemoverRegimes = ValidarZeroUm();
    }

    saveBinPermissions();
    updateUser();
}

void moverRegimes(){
    int flag = 0, id, new_id;
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    listarRegimes();

    do{
        if(flag == 1)
            printc("\n[red]Por favor insira um ID válido![/red]\n");

        printf("\n\nPor favor Introduza o ID do regime que pretende mover: ");
        scanf("%d", &id);
        flag = 1;
        if (id == 1 || id == 2){
            printc("\n[red]Não pode mover regime Administrador ou Professor![/red]\n");
            flag = 0;
        }
    }while (checkIfRegimeExists(id) == 0 || id == 1 || id == 2);

    flag = 0;
    do{
        if(flag == 1)
            printc("\n[red]Por favor insira um ID válido![/red]\n");

        printf("\n\nPara onde pretende mover (ID): ");
        scanf("%d", &new_id);
        flag = 1;
        if (new_id == 1 || new_id == 2){
            printc("\n[red]Não pode editar as permissões do regime Administrador ou Professor![/red]\n");
            flag = 0;
        }
    }while (checkIfRegimeExists(new_id) == 0 || new_id == 1 || new_id == 2);
    masiveRegimeChange(id, new_id);
}

void removerRegime(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    listarRegimes();
    int flag = 0, id, new_id;
    do{
        if(flag == 1)
            printc("\n[red]Por favor insira um ID válido![/red]\n");

        printf("\n\nPor favor Introduza o ID do regime que pretende remover: ");
        scanf("%d", &id);
        flag = 1;
        if (id == 1 || id == 2){
            printc("\n[red]Não pode apagar o regime Administrador ou Professor![/red]\n");
            flag = 0;
        }
    }while (checkIfRegimeExists(id) == 0 || id == 1 || id == 2);

    if(checkIfRegimesBeingUsed(id) == 1){
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
        printc("\n[red]Não é possível remover este regime, pois existem utilizadores que o estão a usar![/red]\n");
        printf("\nDeseja mover os utilizadores para outro regime? (1 - Sim, 0 - Nao): ");
        int op;
        scanf("%d", &op);
        if (op == 1){
            flag = 0;
            fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
            listarRegimes();
            do{
                if(flag == 1)
                    printc("\n[red]Por favor insira um ID válido![/red]\n");

                printf("\n\nPor favor Introduza o ID do regime que pretende mover: ");
                scanf("%d", &new_id);
                flag = 1;
                if (new_id == 1 || new_id == 2){
                    printc("\n[red]Não pode mover para o regime Administrador ou Professor![/red]\n");
                    flag = 0;
                }
            }while (checkIfRegimeExists(new_id) == 0 || new_id == id || new_id == 1 || new_id == 2);
            masiveRegimeChange(id, new_id);
        }
        else{
            return;
        }
    }

    int position = 0;
    for (int i = 0; i <= n_regimes; i++){
        if (id == regimes[i].id){
            position = i;
            break;
        }
    }

    for(int i = position; i < n_regimes; i++){
        regimes[i] = regimes[i+1];
    }
    n_regimes--;
    regimes = realloc(regimes, n_regimes * sizeof(regimeStruct));
    saveBinRegimes();
}