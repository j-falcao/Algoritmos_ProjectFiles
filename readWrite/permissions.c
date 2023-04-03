#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/global.h"

extern permissionFileStruct *perms_file;
extern regimeStruct *regimes;
extern int n_regimes;

void saveAndSetPermissionsBinByTxt(){
    FILE *file = fopen("data/bin/permission.bin", "ab");
    perms_file = malloc(sizeof(permissionFileStruct)*3);
    if (file == NULL){
        printc("\n\n\tImpossivel abrir Ficheiro [red]permission.bin[/red]\n\n");
        exit(1);
    }

    //ADMIN PERMISSIONS
    perms_file[0].id_regime = regimes[0].id;
     /* EXAMES */
    perms_file[0].perm.CriarExames = 1;
    perms_file[0].perm.InscritosExames = 1;
    perms_file[0].perm.ListarExames = 1;
    perms_file[0].perm.ListarExamesInscritos = 1;
    perms_file[0].perm.EditarExames = 1;
    perms_file[0].perm.ExportarExames = 1;
    perms_file[0].perm.InscreverExames = 0;
     /* SALAS */
    perms_file[0].perm.CriarSalas = 1;
    perms_file[0].perm.ListarSalas = 1;
    perms_file[0].perm.EditarSalas = 1;
    perms_file[0].perm.RemoverSalas = 1;
     /* PROFESSOR */
    perms_file[0].perm.CriarProfessor = 1;
    perms_file[0].perm.ListarProfessor = 1;
    perms_file[0].perm.EditarProfessor = 1;
    perms_file[0].perm.RemoverProfessor = 1;
     /* CURSOS */
    perms_file[0].perm.CriarCursos = 1;
    perms_file[0].perm.ListarCursos = 1;
    perms_file[0].perm.EditarCursos = 1;
    perms_file[0].perm.RemoverCursos = 1;
     /* DISCIPLINAS */
    perms_file[0].perm.ListarCursosDisciplinas = 1;
    perms_file[0].perm.CriarDisciplinas = 1;
    perms_file[0].perm.ListarDisciplinas = 1;
    perms_file[0].perm.EditarDisciplinas = 1;
    perms_file[0].perm.RemoverDisciplinas = 1;
    perms_file[0].perm.VerDisciplinas = 0;
     /* ALUNOS */
    perms_file[0].perm.CriarAluno = 1;
    perms_file[0].perm.ListarAluno = 1;
    perms_file[0].perm.ListarTodosAlunos = 1;
    perms_file[0].perm.EditarAluno = 1;
    perms_file[0].perm.RemoverAluno = 1;
     /* Regimes */
    perms_file[0].perm.CriarRegimes = 1;
    perms_file[0].perm.ListarRegimes = 1;
    perms_file[0].perm.ListarRegimesPermissoes = 1;
    perms_file[0].perm.EditarNomeRegimes = 1;
    perms_file[0].perm.EditarPermissoesRegimes = 1;
    perms_file[0].perm.MoverRegimes = 1;
    perms_file[0].perm.RemoverRegimes = 1;
    fwrite(&perms_file[0], sizeof(permissionFileStruct),1,file);

    //PROFESSOR PERMISSIONS
    perms_file[1].id_regime = regimes[1].id;
     /* EXAMES */
    perms_file[1].perm.CriarExames = 1;
    perms_file[1].perm.InscritosExames = 1;
    perms_file[1].perm.ListarExames = 1;
    perms_file[1].perm.ListarExamesInscritos = 1;
    perms_file[1].perm.EditarExames = 1;
    perms_file[1].perm.ExportarExames = 1;
    perms_file[1].perm.InscreverExames = 0;
     /* SALAS */
    perms_file[1].perm.CriarSalas = 0;
    perms_file[1].perm.ListarSalas = 1;
    perms_file[1].perm.EditarSalas = 0;
    perms_file[1].perm.RemoverSalas = 0;
     /* PROFESSOR */
    perms_file[1].perm.CriarProfessor = 0;
    perms_file[1].perm.ListarProfessor = 1;
    perms_file[1].perm.EditarProfessor = 0;
    perms_file[1].perm.RemoverProfessor = 0;
     /* CURSOS */
    perms_file[1].perm.CriarCursos = 0;
    perms_file[1].perm.ListarCursos = 1;
    perms_file[1].perm.EditarCursos = 0;
    perms_file[1].perm.RemoverCursos = 0;
     /* DISCIPLINAS */
    perms_file[1].perm.ListarCursosDisciplinas = 1;
    perms_file[1].perm.CriarDisciplinas = 0;
    perms_file[1].perm.ListarDisciplinas = 1;
    perms_file[1].perm.EditarDisciplinas = 0;
    perms_file[1].perm.RemoverDisciplinas = 0;
    perms_file[1].perm.VerDisciplinas = 0;
     /* ALUNOS */
    perms_file[1].perm.CriarAluno = 0;
    perms_file[1].perm.ListarAluno = 1;
    perms_file[1].perm.ListarTodosAlunos = 1;
    perms_file[1].perm.EditarAluno = 0;
    perms_file[1].perm.RemoverAluno = 0;
     /* Regimes*/
    perms_file[1].perm.CriarRegimes = 0;
    perms_file[1].perm.ListarRegimes = 1;
    perms_file[1].perm.ListarRegimesPermissoes = 0;
    perms_file[1].perm.EditarNomeRegimes = 0;
    perms_file[1].perm.EditarPermissoesRegimes = 0;
    perms_file[1].perm.MoverRegimes = 0;
    perms_file[1].perm.RemoverRegimes = 0;
    fwrite(&perms_file[1], sizeof(permissionFileStruct),1,file);

    printf("\n1º Regime - %s\n", regimes[0].name);
    printc("Permissoes predefinidas.\n");

    printf("\n2º Regime - %s\n", regimes[1].name);
    printf("Permissoes predefinidas.\n");

    for (int i = 2; i < n_regimes; i++){
        perms_file = realloc(perms_file, sizeof(permissionFileStruct) * (i + 1));
        perms_file[i].id_regime = regimes[i].id;
        printc("[green]\n%dº Regime - %s\n[/green]", regimes[i].id, regimes[i].name);

        printc("[blue]Permissoes Exames:[/blue]\n");
        printc("Tem permissao para Criar Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.CriarExames = ValidarZeroUm();
        printc("Tem permissao para Ver Inscritos Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.InscritosExames = ValidarZeroUm();
        printc("Tem permissao para Listar Todos Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.ListarExames = ValidarZeroUm();
        printc("Tem permissao para Listar Exames de um aluno? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.ListarExamesInscritos = ValidarZeroUm();
        printc("Tem permissao para Editar Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.EditarExames = ValidarZeroUm();
        printc("Tem permissao para Exportar Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.ExportarExames = ValidarZeroUm();
        printc("Tem permissao para Inscrever Exames? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.InscreverExames = ValidarZeroUm();

        printc("\n[blue]Permissoes Salas:[/blue]\n");
        printc("Tem permissao para Criar Salas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.CriarSalas = ValidarZeroUm();
        printc("Tem permissao para Listar Salas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.ListarSalas = ValidarZeroUm();
        printc("Tem permissao para Editar Salas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.EditarSalas = ValidarZeroUm();
        printc("Tem permissao para Remover Salas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.RemoverSalas = ValidarZeroUm();

        printc("\n[blue]Permissoes Professor:[/blue]\n");
        printc("Tem permissao para Criar Professor? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.CriarProfessor = ValidarZeroUm();
        printc("Tem permissao para Listar Professor? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.ListarProfessor = ValidarZeroUm();
        printc("Tem permissao para Editar Professor? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.EditarProfessor = ValidarZeroUm();
        printc("Tem permissao para Remover Professor? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.RemoverProfessor = ValidarZeroUm();

        printc("\n[blue]Permissoes Cursos:[/blue]\n");
        printc("Tem permissao para Criar Cursos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.CriarCursos = ValidarZeroUm();
        printc("Tem permissao para Listar Cursos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.ListarCursos = ValidarZeroUm();
        printc("Tem permissao para Editar Cursos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.EditarCursos = ValidarZeroUm();
        printc("Tem permissao para Remover Cursos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.RemoverCursos = ValidarZeroUm();
        printc("Tem permissao para Listar Cursos e Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.ListarCursosDisciplinas = ValidarZeroUm();

        printc("\n[blue]Permissoes Disciplinas:[/blue]\n");
        printc("Tem permissao para Criar Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.CriarDisciplinas = ValidarZeroUm();
        printc("Tem permissao para Listar Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.ListarDisciplinas = ValidarZeroUm();
        printc("Tem permissao para Editar Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.EditarDisciplinas = ValidarZeroUm();
        printc("Tem permissao para Remover Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.RemoverDisciplinas = ValidarZeroUm();
        printc("Tem permissao para Listar Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.ListarDisciplinas = ValidarZeroUm();
        printc("Tem permissao para Ver Proprias Disciplinas Disciplinas? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.VerDisciplinas = ValidarZeroUm();

        printc("\n[blue]Permissoes Alunos:[/blue]\n");
        printc("Tem permissao para Criar Alunos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.CriarAluno = ValidarZeroUm();
        printc("Tem permissao para Listar Aluno? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.ListarAluno = ValidarZeroUm();
        printc("Tem permissao para Listar Todos os Alunos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.ListarTodosAlunos = ValidarZeroUm();
        printc("Tem permissao para Editar Alunos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.EditarAluno = ValidarZeroUm();
        printc("Tem permissao para Remover Alunos? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.RemoverAluno = ValidarZeroUm();

        printc("\n[blue]Permissoes Regimes:[/blue]\n");
        printc("Tem permissao para Criar Regimes? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.CriarRegimes = ValidarZeroUm();
        printc("Tem permissao para Listar Regimes? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.ListarRegimes = ValidarZeroUm();
        printc("Tem permissao para Listar Regimes e Permissões? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.ListarRegimesPermissoes = ValidarZeroUm();
        printc("Tem permissao para Editar Nome dos Regimes ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.EditarNomeRegimes = ValidarZeroUm();
        printc("Tem permissao para Editar permissões dos Regimes ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.EditarPermissoesRegimes = ValidarZeroUm();
        printc("Tem permissao para Mover Regimes Regimes ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.MoverRegimes = ValidarZeroUm();
        printc("Tem permissao para Remover Regimes? ([green]1 - Sim[/green], [red]0 - Não[/red]): ");
        perms_file[i].perm.RemoverRegimes = ValidarZeroUm();
        fwrite(&perms_file[i], sizeof(permissionFileStruct),1,file);
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    }
    fclose(file);
}

void saveBinPermissions(){
    FILE *file = fopen("data/bin/permission.bin", "wb");
    if (file == NULL){
        printc("\n\n\tImpossivel abrir Ficheiro [red]permission.bin[/red]\n\n");
    }
    else{
        for (int i = 0; i < n_regimes; i++){
            fwrite(&perms_file[i], sizeof(permissionFileStruct), 1, file);
        }
    }
    fclose(file);
}

void readBinPermissions(){
    FILE *file = fopen("data/bin/permission.bin", "rb");
    perms_file = malloc(sizeof(permissionFileStruct));
    if (file == NULL){
        printc("\n\n\tImpossivel abrir Ficheiro [red]permission.bin[/red]\n\n");
    }
    else{
        int i = 0;
        while (fread(&perms_file[i], sizeof(permissionFileStruct), 1, file)){
            i++;
            perms_file = realloc(perms_file, sizeof(permissionFileStruct)*((i)+1));
        }
        fclose(file);
    }
}

PermissionsType getPermissionsByID(int id){
    int i = 0;
    while (perms_file[i].id_regime != id){
        i++;
    }
    return perms_file[i].perm;
}