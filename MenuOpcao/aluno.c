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

void listarTodosAlunos(){
    printf("Listagem de todos os alunos:\n");
    for (int i = 0; i < n_alunos; i++){
        courseStruct courseAluno = getCourseByID(alunos[i].id_course);
        regimeStruct regimeAluno = getRegimeByID(alunos[i].id_regime);        
        printf("ID: %d", alunos[i].id);
        printf(" Nome: %s", alunos[i].name);
        printf(" Ano: %d", alunos[i].year);
        printf(" ID Regime: %d", alunos[i].id_regime);
        printf(" Nome Regime: %s", regimeAluno.name);
        printf(" ID Course: %d", alunos[i].id_course);
        printf(" Nome Curso: %s", courseAluno.name);
        printf(" Email: %s\n", alunos[i].email);
    }
    printc("\n\n[lw]Pressione enter para continuar[/lw]\n");  
    getchar();
    getchar();
}

void listarAluno(){
    int flag = 0, id;
    do{
        if(flag == 1)
            printc("\n[red]Por favor insira um ID válido![/red]\n");

        printc("Por favor Introduza o ID do aluno que pretende ver:  [red](sair = -1)[/red]\n");
        scanf("%d", &id);
        if(id == -1)
            return;
        flag = 1;
    }while (checkIfUserExists(id) == 0);


    for (int i = 0; i < n_alunos; i++){
        if (alunos[i].id == id){
            printf("\nAluno encontrado:\n");
            courseStruct courseAluno = getCourseByID(alunos[i].id_course);
            regimeStruct regimeAluno = getRegimeByID(alunos[i].id_regime);           
            printf("\nID: %d", alunos[i].id);
            printf("\nNome: %s", alunos[i].name);
            printf("\nEmail: %s", alunos[i].email);
            printf("\nAno: %d", alunos[i].year);
            printf("\nID Regime: %d", alunos[i].id_regime);
            printf("\nNome Regime: %s", regimeAluno.name);
            printf("\nID Curso: %d", alunos[i].id_course);
            printf("\nNome Curso: %s", courseAluno.name);
            break;
        }
    }
    printc("\n\n[lw]Pressione enter para continuar[/lw]\n");  
    getchar();
    getchar();
}

void alterarAluno(){
    listarTodosAlunos();
    int flag = 0, id;
    do{
        if(flag == 1)
            printc("\n[red]Por favor insira um ID válido![/red]\n");

        printf("Por favor Introduza o ID do aluno que pretende editar: ");
        scanf("%d", &id);
        flag = 1;
    }while (checkIfUserExists(id) == 0);

    int position = 0;
    for (int i = 0; i < n_alunos; i++){
        if (id == alunos[i].id){
            position = i;
            break;
        }
    }

    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int opcao;
    flag = 0;
    do{
        opcao = menuEditAluno();
        switch (opcao){
            case 0:
                break;
            case 1:
                printf("Introduza o nome do aluno: ");
                scanf(" %[^\n]", alunos[position].name);
                saveBinAlunos();
                updateUser();
                break;
            case 2:
                printf("Introduza a password do aluno: ");
                scanf("%s", alunos[position].password);
                saveBinAlunos();
                updateUser();
                break;
            case 3:
                listarRegimes();
                flag = 0;
                do{
                    if(flag == 1)
                        printc("\n[red]Por favor insira um ID válido![/red]\n");

                    printf("\n\nPor favor Introduza o ID do regime que pretende editar: ");
                    scanf("%d", &id);
                    flag = 1;
                }while (checkIfRegimeExists(id) == 0);

                alunos[position].id_regime = id;
                saveBinAlunos();
                updateUser();
                break;
            case 4:
                ListarCursos();
                flag = 0;
                do{
                    if(flag == 1)
                        printc("\n[red]Por favor insira um ID válido![/red]\n");

                    printf("Por favor Introduza o ID do curso que pretende editar: ");
                    scanf("%d", &id);
                    flag = 1;
                }while (CheckIFCursoExiste(id) == -1);
                alunos[position].id_course = id;
                saveBinAlunos();
                updateUser();
                break;
            case 5:
                int year;
                flag = 0;
                do{
                    if(flag == 1)
                        printc("\n[red]Por favor insira um ano válido![/red]\n");

                    printf("Introduza o ano do aluno: ");
                    scanf("%d", &year);
                    flag = 1;

                } while (year < 1 || year > 4);
                alunos[position].year = year;
                saveBinAlunos();
                updateUser();
                break;
        default:
            printf("\nOpção inválida!\n");
            break;
        }
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    } while (opcao != 0);
}


void apagarAluno(){
    listarTodosAlunos();
    int flag = 0, id;
    do{
        if(flag == 1)
            printc("\n[red]Por favor insira um ID válido![/red]\n");

        printf("Por favor Introduza o ID do aluno que pretende remover: ");
        scanf("%d", &id);
        flag = 1;
    }while (checkIfUserExists(id) == 0);

    int position = 0;
    for (int i = 0; i <= n_alunos; i++){
        if (id == alunos[i].id){
            position = i;
            break;
        }
    }

    for (int i = position; i < n_alunos; i++){
        alunos[i] = alunos[i+1];
    }

    n_alunos--;
    saveBinAlunos();
}

void criarAluno(){
    int flag=0, year, id;
    alunos = realloc(alunos, (n_alunos+1) * sizeof(AlunoStruct));

    alunos[n_alunos].id = generateUserID();
    alunos[n_alunos].name = malloc(50 * sizeof(char));
    printf("Introduza o nome do aluno: ");
    scanf(" %[^\n]", alunos[n_alunos].name);

    do{
        if(flag == 1)
            printc("\n[red]Por favor insira um ano válido![/red]\n");

        printf("Introduza o ano do aluno: ");
        scanf("%d", &year);
        flag = 1;

    } while (year < 1 || year > 4);
    flag = 0;
    alunos[n_alunos].year = year;

    listarRegimes();

    do{
        if(flag == 1)
            printc("\n[red]Por favor insira um ID válido![/red]\n");

        printf("Por favor Introduza o ID do regime que pretende editar: ");
        scanf("%d", &id);
        flag = 1;
    }while (checkIfRegimeExists(id) == 0);
    alunos[n_alunos].id_regime = id;

    ListarCursos();
    flag = 0;
    do{
        if(flag == 1)
            printc("\n[red]Por favor insira um ID válido![/red]\n");

        printf("Por favor Introduza o ID do curso que pretende editar: ");
        scanf("%d", &id);
        flag = 1;
    }while (CheckIFCursoExiste(id) == -1);
    alunos[n_alunos].id_course = id;

    

    char *email = malloc(120), *password = malloc(100);
    //email example: pv25207@estgv.ipv.pt
    email[0] = '\0';
    strcat(email, "pv");
    char* id_char = malloc(10);
    itoa(alunos[n_alunos].id, id_char, 10);
    strcat(email, id_char);
    strcat(email, "@estgv.ipv.pt");
    alunos[n_alunos].email = malloc((strlen(email)+1));
    strcpy(alunos[n_alunos].email, email);

    //password example: pv25207EE
    password[0] = '\0';
    strcat(password, "pv");
    strcat(password, id_char);
    strcat(password, courses[CheckIFCursoExiste(alunos[n_alunos].id_course)].name);
    alunos[n_alunos].password = malloc((strlen(password)+1));
    strcpy(alunos[n_alunos].password, password);
    n_alunos++;

    saveBinAlunos();
}