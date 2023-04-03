#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/global.h"

/* typedef struct { //struct para guardar os dados de um professor
    char *nomeProfessor;
    int id;
    char *emailProfessor;
    char *passwordProfessor;
}professorStruct;*/

extern professorStruct *professores; //extern para poder usar a variavel global.
extern int n_professores; 

void criarProfessor(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    professores = realloc(professores, (n_professores+1)*sizeof(professorStruct));
    professores[n_professores].nomeProfessor = malloc(100);
    int id = professores[n_professores - 1].id + 1;
    if (n_professores == 0){
        id = 1;
    }
    professores[n_professores].id = id;

    printf("**************************************************\n");
    printc("************        [blue]Professores[/blue]       ************\n");
    printf("**************************************************\n");
    do{
        printf("Qual o nome do professor? ");
        scanf(" %[^\n]", professores[n_professores].nomeProfessor);
        if (isdigit_cheker(professores[n_professores].nomeProfessor) == 1){
            printc("[red]Somente letras e espaços são permitidos[/red]\n");
        }
    } while (isdigit_cheker(professores[n_professores].nomeProfessor) == 1);
    professores[n_professores].nomeProfessor = realloc(professores[n_professores].nomeProfessor, (strlen(professores[n_professores].nomeProfessor)+1));
    
    capitalize(professores[n_professores].nomeProfessor);

    char *email = malloc(strlen("pv") + strlen(professores[n_professores].nomeProfessor) + 10 /* 10 é para o numero id */+ strlen("@estgv.ipv.pt") + 1 /* para o \0 */), *password = malloc(100);
    //email example: pvjorge25207@estgv.ipv.prof.pt
    email[0] = '\0';
    strcat(email, "pv");

    char *nomeProf = malloc(strlen(professores[n_professores].nomeProfessor)+1);
    strcpy(nomeProf, professores[n_professores].nomeProfessor);
    printf("\n\t %s", professores[n_professores].nomeProfessor);
    strcat(email, nomeProf);

    char* id_char = malloc(10);
    itoa(id, id_char, 10);
    strcat(email, id_char);
    strcat(email, "@estgv.ipv.prof.pt");
    professores[n_professores].emailProfessor = malloc((strlen(email)+1));
    strcpy(professores[n_professores].emailProfessor, email);
    
    password[0] = '\0';
    strcat(password, "pv");
    strcat(password, id_char);
    //password example: pv25207
    professores[n_professores].passwordProfessor = malloc((strlen(password)+1));
    strcpy(professores[n_professores].passwordProfessor, password);
    
    free(email);
    printc("\n\t[green]Professor criado com sucesso![/green]\n");
    free(password);
    free(id_char);
    free(nomeProf);
    n_professores++;
    saveBinProfessor();
}

void readBinProfessores(){
    professores = malloc(sizeof(professorStruct));
    int i;
    FILE *file = fopen("data/bin/professores.bin","rb");
    if (!file) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]professores.bin[/red] \n\n");
        return;
    }
    else{
        for (i = 0;; i++){
            professores = realloc(professores, (i+1)*sizeof(professorStruct));
            if(fread(&professores[i].id, sizeof(int), 1, file) != 1) break;

            size_t nomeProfessorsize;
            fread(&nomeProfessorsize, sizeof(size_t), 1, file);
            professores[i].nomeProfessor = malloc(nomeProfessorsize);
            fread(professores[i].nomeProfessor, nomeProfessorsize, 1, file);

            size_t emailProfessorsize;
            fread(&emailProfessorsize, sizeof(size_t), 1, file);
            professores[i].emailProfessor = malloc(emailProfessorsize);
            fread(professores[i].emailProfessor, emailProfessorsize, 1, file);

            size_t passwordProfessorsize;
            fread(&passwordProfessorsize, sizeof(size_t), 1, file);
            professores[i].passwordProfessor = malloc(passwordProfessorsize);
            fread(professores[i].passwordProfessor, passwordProfessorsize, 1, file);
        }
        n_professores = i;
        fclose(file);
    }
}

void saveBinProfessor(){
    FILE *file;
    file = fopen("data/bin/professores.bin", "wb");
    if(!file){
        printc("\n\n\tErro ao abrir o arquivo [red]professores.bin[/red]");
        return;
    }
    printf("A guardar ficheiro [red]professores.bin[/red]... \n");
    for (int i = 0; i < n_professores; i++){
        fwrite(&professores[i].id, sizeof(int), 1, file);

        size_t nomeProfessorsize = strlen(professores[i].nomeProfessor) + 1; // +1 para guardar o \0
        fwrite(&nomeProfessorsize, sizeof(size_t), 1, file);
        fwrite(professores[i].nomeProfessor, nomeProfessorsize, 1, file);

        size_t emailProfessorsize = strlen(professores[i].emailProfessor) + 1; // +1 para guardar o \0
        fwrite(&emailProfessorsize, sizeof(size_t), 1, file);
        fwrite(professores[i].emailProfessor, emailProfessorsize, 1, file);

        size_t passwordProfessorsize = strlen(professores[i].passwordProfessor) + 1; // +1 para guardar o \0
        fwrite(&passwordProfessorsize, sizeof(size_t), 1, file);
        fwrite(professores[i].passwordProfessor, passwordProfessorsize, 1, file);
    }
    fclose(file);
}

void listarProfessor(){
    printf("**************************************************\n");
    printc("************        [blue]Professores[/blue]       ************\n");
    printf("**************************************************\n");

    printc("\tNumero de professores: [red]%d[/red]\n", n_professores);
    for (int i = 0; i < n_professores; i++){
        printc("\t[green]ID:[/green] %d [green]Nome:[/green] %s\n", professores[i].id, professores[i].nomeProfessor);
    }
}

void editarProfessor(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    printf("**************************************************\n");
    printc("************        [blue]Professores[/blue]       ************\n");
    printf("**************************************************\n");

    int id;
    printf("Qual o ID do professor que deseja editar? ");
    scanf("%d", &id);
    for (int i = 0; i < n_professores; i++){
        if (id == professores[i].id){
            do{ // IMPLEMENTADO RECENTEMENTE
                printf("Qual o novo nome do professor? ");
                scanf(" %[^\n]", professores[i].nomeProfessor);
                if (isdigit_cheker(professores[i].nomeProfessor) == 1){
                    printc("[red]Somente letras e espaços são permitidos[/red]\n");
                }
            } while (isdigit_cheker(professores[i].nomeProfessor) == 1);
            saveBinProfessor();
            readBinProfessores();
        }
    }
}



void removerProfessor(){
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    printf("**************************************************\n");
    printc("************        [blue]Professores[/blue]       ************\n");
    printf("**************************************************\n");

    int id;
    printf("Qual o ID do professor que deseja remover? ");
    scanf("%d", &id);
    for (int i = 0; i < n_professores; i++){
        if (id == professores[i].id){
            for (int j = i; j < n_professores; j++){
                professores[j] = professores[j+1];
            }
            n_professores--;
            professores = realloc(professores, n_professores*sizeof(professorStruct));
            saveBinProfessor();
            readBinProfessores();
        }
    }
}

