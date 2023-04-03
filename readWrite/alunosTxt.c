#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
#include "../All_functions/global.h" 

extern AlunoStruct *alunos;
extern regimeStruct *regimes;
extern courseStruct *courses;
extern AlunoFileStruct *alunosFile; 
extern int n_alunos, n_regimes, n_courses;

AlunoFileStruct* getTxt(){
    AlunoFileStruct *alunosFile = malloc(sizeof(AlunoFileStruct));
    FILE *file = fopen("data/alunos.txt","r");
    char **filedata = malloc(5*sizeof(char *)), *linhaString = malloc(250);

    if (!file) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]alunos.txt[/red]\n\n");
        exit(1);
    }

    int linha = 0;
    while (!feof(file)){
        fgets(linhaString,250,file);
        char *pch = strtok (linhaString, "\t\r\n");
        
        int count = 0;

        while (pch != NULL){
            filedata[count] = malloc((strlen(pch)+1));
            strcpy(filedata[count], pch);
            pch = strtok (NULL, "\t\r\n");
            count++;
        }
        alunosFile = realloc(alunosFile, ((n_alunos)+1)*sizeof(AlunoFileStruct));

        if(strcmp(filedata[0] , "NOME") != 0 && strcmp(filedata[1] , "REGIME") != 0 && strcmp(filedata[2] , "ANO") != 0 && strcmp(filedata[3] , "NÚMERO") != 0 && strcmp(filedata[4] , "CURSO") != 0){
            //nome
            alunosFile[n_alunos].name = malloc((strlen(filedata[0])+1));
            strcpy(alunosFile[n_alunos].name, filedata[0]);
            if(isspace(alunosFile[n_alunos].name[0])){
                alunosFile[n_alunos].name = &alunosFile[n_alunos].name[1];
            }
            //REGIME
            alunosFile[n_alunos].regime = malloc((strlen(filedata[1])+1));
            strcpy(alunosFile[n_alunos].regime, capitalize(filedata[1]));
            //Year
            alunosFile[n_alunos].year = atoi(filedata[2]);
            //ID / Número
            alunosFile[n_alunos].id = atoi(filedata[3]);
            //Course 
            alunosFile[n_alunos].course = malloc((strlen(filedata[4])+1));
            strcpy(alunosFile[n_alunos].course, uppercase(filedata[4]));

            n_alunos++;
        }
    }

    int flag = 0, gerar = 0;
    for(int i = 0; i < n_alunos; i++){
        for(int j = i+1; j < n_alunos; j++){
            if(alunosFile[i].id == alunosFile[j].id){
                if(flag == 0){
                    printc("\n[red]ERRO[/red] - Os seguintes alunos têm o mesmo número:");
                    flag = 1;
                }
                printc("\n[red]ERRO[/red] - ID:%d O aluno [yellow]%s[/yellow] tem o mesmo número que o aluno [yellow]%s[/yellow]", alunosFile[i].id, alunosFile[i].name, alunosFile[j].name);
            }
        }
    }
    
    fclose(file);
    if(flag == 1){
        printc("\n\nQuer gerar novos números para os alunos? ([green]1[/green]/[red]0[/red]) ");
        scanf("%d", &gerar);
        if(gerar == 1){
            int *numbers = malloc(n_alunos * sizeof(int));
            for (size_t i = 0; i < n_alunos; i++){
                numbers[i] = alunosFile[i].id;
            }
            generate_unique_numbers(numbers, n_alunos);
            for (size_t i = 0; i < n_alunos; i++){
                alunosFile[i].id = numbers[i];
            }
        }
        else{
            printc("[red]Não foi Introduzido qualquer dado![/red]\n\n");
            n_alunos = 0;
            return NULL;
        }
    }
    return alunosFile;
}

void ConvertAluno(AlunoFileStruct *alunosFile){
    alunos = malloc(sizeof(AlunoStruct)*(n_alunos+1));

    alunos[0].id = generateUserID();
    alunos[0].name = malloc(50 * sizeof(char));
    printc("\n[red]Introduza o nome do adminstrador: [/red]");
    scanf("%s", alunos[0].name);
    alunos[0].year = 0;
    alunos[0].id_regime = 1;
    alunos[0].id_course = 0;
    alunos[0].email = malloc(120);
    alunos[0].password = malloc(100);
    printc("\n[red]Introduza o email do adminstrador: [/red]");
    scanf("%s", alunos[0].email);
    printc("\n[red]Introduza a password do adminstrador: [/red]");
    scanf("%s", alunos[0].password);
    
    alunos[0].email = realloc(alunos[0].email, (strlen(alunos[0].email)+1));
    alunos[0].password = realloc(alunos[0].password, (strlen(alunos[0].password)+1));

    for (int i = 1; i < n_alunos; i++){
        alunos[i].name = malloc((strlen(alunosFile[i].name)+1));
        strcpy(alunos[i].name, alunosFile[i].name);
        alunos[i].year = alunosFile[i].year;
        alunos[i].id = alunosFile[i].id;
        for (int j = 0; j < n_regimes; j++){
            if (strcmp(alunosFile[i].regime, regimes[j].name) == 0){
                alunos[i].id_regime = regimes[j].id;
                break;
            }
        }
        for (int j = 0; j < n_courses; j++){
            if (strcmp(alunosFile[i].course, courses[j].name) == 0){
                alunos[i].id_course = courses[j].id;
                break;
            }
        }

        char *email = malloc(120), *password = malloc(100);
        //email example: pv25207@estgv.ipv.pt
        email[0] = '\0';
        strcat(email, "pv");
        char* id = malloc(10);
        itoa(alunosFile[i].id, id, 10);
        strcat(email, id);
        strcat(email, "@estgv.ipv.pt");
        alunos[i].email = malloc((strlen(email)+1));
        strcpy(alunos[i].email, email);

        //password example: pv25207EE
        password[0] = '\0';
        strcat(password, "pv");
        strcat(password, id);
        strcat(password, alunosFile[i].course);
        alunos[i].password = malloc((strlen(password)+1));
        strcpy(alunos[i].password, password);
    }
}