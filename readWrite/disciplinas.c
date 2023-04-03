#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

//GLOBAL VARIABLES
extern disciplinasStruct *disciplinas;
extern int n_disciplinas;


/* void Disciplinas(){
    char TmpNameDisciplina[15]; 
    disciplinas = malloc(sizeof(disciplinasStruct));
    int parar = 0;
    for(int i=0; ;i++){
        disciplinas = realloc(disciplinas, sizeof(disciplinasStruct) * (i + 1));            
        printf("\nEscreve o nome da disciplina: ");
        scanf("%s", TmpNameDisciplina);
        disciplinas[i].name = malloc(strlen(TmpNameDisciplina)+1);
        strcpy(disciplinas[i].name, TmpNameDisciplina); 
        disciplinas[i].id = i+1;
        printc("\nPara parar escreva [red]0[/red] para cntinuar escreva [green]1[/green]: ");
        scanf("%d", &parar);
        if(parar == 0){
            n_disciplinas = i+1;
            break;
        }
    }
    SaveBinDisciplinas();
} */

/* void ReadTxtDisciplinas()
{	
    FILE *disciplinasTxt = fopen("data/bin/disciplinas.txt","r");
    if(disciplinasTxt == NULL){
        printf("\n\n\tImpossivel abrir Ficheiro disciplis.txt\n\n");
        return;
    }
    else{
        disciplinas = malloc(sizeof(disciplinasStruct)*348);
        int i;
        for (i = 0; i < 348; i++){
        	disciplinas[i].name = malloc(15);
            fgets(disciplinas[i].name, 14, disciplinasTxt);
            disciplinas[i].name = realloc(disciplinas[i].name, strlen(disciplinas[i].name)+1);
            disciplinas[i].id = i+1;
        }
        n_disciplinas = i;
        fclose(disciplinasTxt);
    }
    SaveBinDisciplinas();
} */

void ReadBinDisciplinas(){
    disciplinas = malloc(sizeof(disciplinasStruct));
    int i;
    FILE *disciplinasBin = fopen("data/bin/disciplinas.bin","rb");
    if (disciplinasBin == NULL) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]disciplinas.bin[/red]\n\n");
    }
    else{
        for (i = 0;; i++){
            disciplinas = realloc(disciplinas, sizeof(disciplinasStruct) * (i + 1));
            if(fread(&disciplinas[i].id, sizeof(int), 1, disciplinasBin) != 1) 
                break;
            size_t disciplinasLen;
            fread(&disciplinasLen, sizeof(size_t), 1, disciplinasBin);
            disciplinas[i].name = malloc(disciplinasLen);
            fread(disciplinas[i].name, disciplinasLen, 1, disciplinasBin);
        }
        n_disciplinas = i;

        fclose(disciplinasBin);
    }
}

void criardisciplinas()
{   int n = 0;
    //printc("[green]Criação de Disciplinas[/green]");
    while(n<6){
        printf("\nQuantas disciplinas quer criar? (minimo 6 -> 1 por semestre):");
        scanf("%d", &n);
        if(n<6)
            printc("\n[red]Numero de disciplinas invalido[/red]");
    }
    for(int i=0; i<n; i++){   
        char nameDisciplina[10], op;
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
        ListarDisciplinas();
        printc("\n[green]Insira a sigla da nova disciplina:[/green] ");
        scanf("%s", nameDisciplina);
        uppercase(nameDisciplina);
        if(CheckIFDisciplinaExisteNome(nameDisciplina) != -1){
            printc("\n\n\t[red]Disciplina ja existe[/red]\n\n");
            do{
                printf("\n\tSigla: ");
                scanf("%s", nameDisciplina);
                uppercase(nameDisciplina);
            } while(CheckIFDisciplinaExisteNome(nameDisciplina) != -1);
        }
        disciplinas = realloc(disciplinas, sizeof(disciplinasStruct) * (n_disciplinas+1));
        disciplinas[n_disciplinas].id = n_disciplinas+1;
        disciplinas[n_disciplinas].name = malloc(strlen(nameDisciplina)+1);
        strcpy(disciplinas[n_disciplinas].name, nameDisciplina); 
        n_disciplinas++;
        SaveBinDisciplinas();
    }
}

void SaveBinDisciplinas(){
    FILE *disciplinasBin = fopen("data/bin/disciplinas.bin","wb");
    if (disciplinasBin == NULL) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]disciplinas.bin[/red]\n\n");
        return;
    }

    for (int i = 0; i < n_disciplinas; i++){
        fwrite(&disciplinas[i].id, sizeof(int), 1, disciplinasBin);
        size_t disciplinasLen = strlen(disciplinas[i].name) + 1;
        fwrite(&disciplinasLen, sizeof(size_t), 1, disciplinasBin);
        uppercase(disciplinas[i].name);
        fwrite(disciplinas[i].name, disciplinasLen, 1, disciplinasBin);
    }
    fclose(disciplinasBin);
}