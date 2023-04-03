#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../All_functions\global.h"

extern AlunoStruct *alunos;
extern regimeStruct *regimes;
extern courseStruct *courses;
extern int n_alunos, n_regimes, n_courses, n_professores;
extern AlunoDataStruct aluno;
extern permissionFileStruct *perms_file;
extern professorStruct *professores;


void saveBinAlunos(){
    FILE *file = fopen("data/bin/alunos.bin","wb");
    if (!file) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]alunos.bin[/red]\n\n");
        exit(1);
    }
    for (int i = 0; i < n_alunos; i++){
        fwrite(&alunos[i].id, sizeof(int), 1, file);
        fwrite(&alunos[i].year, sizeof(int), 1, file);
        fwrite(&alunos[i].id_regime, sizeof(int), 1, file);
        fwrite(&alunos[i].id_course, sizeof(int), 1, file);

        size_t nomeLen = strlen(alunos[i].name) + 1;
        fwrite(&nomeLen, sizeof(size_t), 1, file);
        fwrite(alunos[i].name, nomeLen, 1, file);

        size_t emailLen = strlen(alunos[i].email) + 1;
        fwrite(&emailLen, sizeof(size_t), 1, file);
        fwrite(alunos[i].email, emailLen, 1, file);

        size_t passLen = strlen(alunos[i].password) + 1;
        fwrite(&passLen, sizeof(size_t), 1, file);
        fwrite(alunos[i].password, passLen, 1, file);
    }
    fclose(file);
}

void readBinAlunos(){
    alunos = malloc(sizeof(AlunoStruct));
    int i;
    FILE *file = fopen("data/bin/alunos.bin","rb");
    if (!file) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]alunos.bin[/red]\n\n");
    }
    else{
        for (i = 0;; i++){
            if(fread(&alunos[i].id, sizeof(int), 1, file) != 1) break;
            fread(&alunos[i].year, sizeof(int), 1, file);
            fread(&alunos[i].id_regime, sizeof(int), 1, file);
            fread(&alunos[i].id_course, sizeof(int), 1, file);
            
            size_t nameLen;
            fread(&nameLen, sizeof(size_t), 1, file);
            alunos[i].name = malloc(nameLen);
            fread(alunos[i].name, nameLen, 1, file);

            size_t emailLen;
            fread(&emailLen, sizeof(size_t), 1, file);
            alunos[i].email = malloc(emailLen);
            fread(alunos[i].email, emailLen, 1, file);

            size_t passLen;
            fread(&passLen, sizeof(size_t), 1, file);
            alunos[i].password = malloc(passLen);
            fread(alunos[i].password, passLen, 1, file);

            alunos = realloc(alunos, sizeof(AlunoStruct) * (i+2));
        }
        n_alunos = i;
        fclose(file);
    }
}

void login(char *email, char *password){
    int i, flag = 0;
    for (i = 0; i < n_alunos; i++){
        if (strcmp(email, alunos[i].email) == 0 && strcmp(password, alunos[i].password) == 0){
            flag = 1;
            printc("\n\n\t[green]Login feito com sucesso[/green]\n\n");
            getchar();
            getchar();
            fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
            getUserDataByID(alunos[i].id);
            MenuPrincipal();
        }
    }
    for (int i = 0; i < n_professores; i++){
        if (strcmp(email, professores[i].emailProfessor) == 0 && strcmp(password, professores[i].passwordProfessor) == 0){
            flag = 1;
            printc("\n\n\t[green]Login feito com sucesso[/green]\n\n");
            getchar();
            getchar();
            getUserDataByIDProf(professores[i].id);
            MenuPrincipal();
        }
    }
    
    if(flag == 0){
        printc("\n\n\t[red]Dados Inválidos.[/red]\n\n");
        getchar();
        getchar();
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    }
}

void getUserDataByID(int id){
    int position = 0;
    for (int i = 0; i < n_alunos; i++){
        if (id == alunos[i].id){
            position = i;
            break;
        }
    }
    aluno.id = id;
    aluno.name = malloc(strlen(alunos[position].name)+1);
    aluno.email = malloc(strlen(alunos[position].email)+1);
    aluno.password = malloc(strlen(alunos[position].password)+1);
    strcpy(aluno.name, alunos[position].name);
    strcpy(aluno.email, alunos[position].email);
    strcpy(aluno.password, alunos[position].password);
    aluno.year = alunos[position].year;
    aluno.regime = getRegimeByID(alunos[position].id_regime);
    aluno.regime.perm = getPermissionsByID(alunos[position].id_regime);
    aluno.course = getCourseByID(alunos[position].id_course);
}

void getUserDataByIDProf(int id){
    int position = 0;
    for (int i = 0; i < n_professores; i++){
        if (id == professores[i].id){
            position = i;
            break;
        }
    }
    aluno.id = id;
    aluno.name = malloc(strlen(professores[position].nomeProfessor)+1);
    aluno.email = malloc(strlen(professores[position].emailProfessor)+1);
    aluno.password = malloc(strlen(professores[position].passwordProfessor)+1);
    strcpy(aluno.name, professores[position].nomeProfessor);
    strcpy(aluno.email, professores[position].emailProfessor);
    strcpy(aluno.password, professores[position].passwordProfessor);
    aluno.regime = getRegimeByID(alunos[position].id_regime);
}

int checkIfUserExists(int id){
    for (int i = 0; i < n_alunos; i++){
        if (id == alunos[i].id){
            return 1;            
        }
    }
    return 0;
}

int generateUserID(){
    int id = 0;
    srand(time(NULL));
    do{
        id = rand() % 100000;
    }while(checkIfUserExists(id) == 1);
    return id;
}

void printfUserData(){//testes
    printc("\n\t[green]ID:[/green] %d", aluno.id);
    printc("\n\t[green]Nome:[/green] %s", aluno.name);
    printc("\n\t[green]Email:[/green] %s", aluno.email);
    printc("\n\t[green]Password:[/green] %s", aluno.password);
    printc("\n\t[green]Ano:[/green] %d", aluno.year);
    printc("\n\t[green]Regime ID:[/green] %d", aluno.regime.id);
    printc("\n\t[green]Regime:[/green] %s", aluno.regime.name);
    printc("\n\t[green]Permissão CriarCursos:[/green] %d", aluno.regime.perm.CriarCursos);
    printc("\n\t[green]Permissão CriarExames:[/green] %d", aluno.regime.perm.CriarExames);
    printc("\n\t[green]Permissão CriarProfessor:[/green] %d", aluno.regime.perm.CriarProfessor);
    printc("\n\t[green]Curso ID:[/green] %d", aluno.course.id);
    printc("\n\t[green]Curso:[/green] %s", aluno.course.name);
    getchar();
    getchar();
}

/* AlunoStruct readBinAluno(int id_aluno){
    AlunoStruct aluno;

    FILE *file_alunos = fopen("data/bin/alunos.bin","rb");
    if (!file_alunos) {
        printf("\n\n\tImpossivel abrir Ficheiro alunos.bin\n\n");
        exit(1);
    }
    FILE *file_regimes = fopen("data/bin/regimes.bin","rb");
    if (!file_regimes) {
        printf("\n\n\tImpossivel abrir Ficheiro regimes.bin\n\n");
        exit(1);
    }
    FILE *file_course = fopen("data/bin/course.bin","rb");
    if (!file_course) {
        printf("\n\n\tImpossivel abrir Ficheiro course.bin\n\n");
        exit(1);
    }


    for (int i = 0;; i++){
        if(fread(&aluno.id, sizeof(int), 1, file_alunos) != 1) break;
        if (aluno.id == id_aluno){

            //GET ALUNO DATA FROM FILE
            fread(&aluno.year, sizeof(int), 1, file_alunos);
            fread(&aluno.id_regime, sizeof(int), 1, file_alunos);
            fread(&aluno.id_course, sizeof(int), 1, file_alunos);

            size_t nameLen;
            fread(&nameLen, sizeof(size_t), 1, file_alunos);
            aluno.name = malloc(nameLen);
            fread(aluno.name, nameLen, 1, file_alunos);


            for (int j = 0;; j++){
                if(fread(&aluno.id_regime, sizeof(int), 1, file_regimes) != 1) break;
                if (aluno.id_regime == aluno.id_regime){
                    size_t regimeLen;
                    fread(&regimeLen, sizeof(size_t), 1, file_regimes);
                    aluno.name = malloc(regimeLen);
                    fread(aluno.name, regimeLen, 1, file_regimes);
                    break;
                }
            }
            



            fclose(file_alunos);
            return aluno;
        }
    }
    fclose(file_alunos);
} */