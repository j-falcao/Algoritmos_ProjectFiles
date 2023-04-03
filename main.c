#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <sys/stat.h>
#include <windows.h>

#include "All_functions\global.h"


//GLOBAL VARIABLES
AlunoStruct *alunos;
regimeStruct *regimes;
courseStruct *courses;
permissionFileStruct *perms_file;
disciplinasStruct *disciplinas;
SalaStruct *salas;
professorStruct *professores;
AlunoDataStruct aluno;
Exames* exame;
TempoAnoAtualDiferenca tempo;

int n_alunos = 0, n_regimes = 0, n_courses = 0, n_disciplinas = 0, n_salas = 0, n_professores = 0, n_exames = 0;

void readData();


void main(){
    if (fileExistAll() == 0){
        printc("[red]Error[/red] Ficheiros não existem.\n\n");
        MenuFilesNovos();
    }
    readData();
    fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
    int op = -1;
    setlocale(LC_ALL, "Portuguese");
    do{
        op = mainMenu();
        switch (op){
            case 0:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                printc("[lw]A fechar o programa...[/lw]");
                break;
            case 1:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                char *username = malloc(120), *password = malloc(50);
                printc("[lw]Bem-vindo ao sistema de gestão de exames![/lw]\n");
                printc("[lw]Por favor, faça o login para continuar![/lw]\n");
                printc("[lw]Email:[/lw] ");
                scanf("%s", username);
                printc("[lw]Password:[/lw] ");
                scanf("%s", password);
                login(username, password);
                break;
            case 2:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                importExportData();
                break;
            default:
                fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
                printc("\n[red]Opção inválida![/red]\n\n");
        }
    } while (op != 0);

}

void readData(){
    mkdir("data/bin");
    readBinAlunos();
    readBinRegimes();
    readBinPermissions();
    ReadBinDisciplinas();
    ReadBinCursosDisciplina(); 
    readBinSalas();
    readBinProfessores();
    readBinExames();
}

