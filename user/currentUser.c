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

void editAccount(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int op = -1;
    do{
        op = MenuEditarConta();
        switch (op){
            case 0:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                break;
            case 1:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                changeName();
                break;
            case 2:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                changePassword();
                break;
            default: 
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                printc("\n[red]Opção inválida![/red]\n\n");
        }
    } while (op != 0);
}

void changeName(){
    char nome[50];
    printc("****************** [blue]Editar nome![/blue] ******************\n");
    printf("             Nome: %s\n", aluno.name);
    printf("             Novo nome: ");
    scanf(" %[^\n]", nome);
    printc("\n             [green]Nome alterado com sucesso![/green]\n");
    printf("**************************************************\n");
    printf("\nPressione [enter] para continuar...");
    strcpy(aluno.name, nome);
    updateUser();
    saveBinAlunos();
    getchar();
    getchar();
}

void changePassword(){
    char password[50];
    printc("**************** [blue]Editar password![/blue] ****************\n");
    printf("             Password: *********\n");
    printf("             Nova password: ");
    scanf("%s", password);
    strcpy(aluno.password, password);
    printc("\n          [green]Password alterada com sucesso![/green]\n");
    printf("**************************************************\n");
    printf("\nPressione [enter] para continuar...");
    updateUser();
    saveBinAlunos();
    getchar();
    getchar();
}

void updateUser(){
    int position = 0;
    for (int i = 0; i < n_alunos; i++){
        if (aluno.id == alunos[i].id){
            position = i;
            break;
        }
    }
    alunos[position].name = malloc(strlen(aluno.name)+1);
    alunos[position].password = malloc(strlen(aluno.password)+1);
    strcpy(alunos[position].name, aluno.name);
    strcpy(alunos[position].password, aluno.password);
    aluno.year = alunos[position].year;
    aluno.regime = getRegimeByID(alunos[position].id_regime);
    aluno.regime.perm = getPermissionsByID(alunos[position].id_regime);
    aluno.course = getCourseByID(alunos[position].id_course);
}