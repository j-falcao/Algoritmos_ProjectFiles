#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions/global.h"

extern AlunoStruct *alunos;
extern regimeStruct *regimes;
extern courseStruct *courses;
extern permissionFileStruct *perms_file;
extern int n_alunos, n_regimes, n_courses;

void getAllRegimes(AlunoFileStruct *alunosFile){
    regimes = malloc(sizeof(regimeStruct)*3);
    n_regimes = 2;
    regimes[0].id = 1;
    regimes[0].name = malloc(6);
    strcpy(regimes[0].name, "Admin");
    regimes[1].id = 2;
    regimes[1].name = malloc(10);
    strcpy(regimes[1].name, "Professor");


    for (int i = 0; i < n_alunos; i++){
        int found = 0;
        for (int j = 0; j < n_regimes; j++){
            if (strcmp(alunosFile[i].regime, regimes[j].name) == 0){
                found = 1;
                break;
            }
        }
        if (!found){
            regimes = realloc(regimes, (n_regimes+1)*sizeof(regimeStruct));
            regimes[n_regimes].id = n_regimes+1;
            regimes[n_regimes].name = malloc((strlen(alunosFile[i].regime)+1));
            strcpy(regimes[n_regimes].name, alunosFile[i].regime);
            n_regimes++;
        }
    }
}

void saveBinRegimes(){
    FILE *file = fopen("data/bin/regimes.bin","wb");
    if (!file) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]regimes.bin[/red]\n\n");
        exit(1);
    }

    for (int i = 0; i < n_regimes; i++){
        fwrite(&regimes[i].id, sizeof(int), 1, file);
        size_t regimeLen = strlen(regimes[i].name) + 1;
        fwrite(&regimeLen, sizeof(size_t), 1, file);
        fwrite(regimes[i].name, regimeLen, 1, file);
    }
    fclose(file);
}

void readBinRegimes(){
    regimes = malloc(sizeof(regimeStruct));
    int i;
    FILE *file = fopen("data/bin/regimes.bin","rb");
    if (!file) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]regimes.bin[/red] \n\n");
    }
    else{
        for (i = 0;; i++){
            regimes = realloc(regimes, (i+1)*sizeof(regimeStruct));
            if(fread(&regimes[i].id, sizeof(int), 1, file) != 1) break;

            size_t regimeLen;
            fread(&regimeLen, sizeof(size_t), 1, file);
            regimes[i].name = malloc(regimeLen);
            fread(regimes[i].name, regimeLen, 1, file);
        }
        n_regimes = i;
    }
    fclose(file);
}

regimeStruct getRegimeByID(int id){
    for (int i = 0; i < n_regimes; i++){
        if (regimes[i].id == id){
            return regimes[i];
        }
    }
    regimeStruct none;
    none.id = -1;
    none.name = malloc(12);
    strcpy(none.name, "Não existe!");
    return none;
}

void listarRegimes(){
    printf("\nListagem de todos os Regimes:\n");
    for (int i = 0; i < n_regimes; i++){
        printc("\n[green]ID[/green]: %d [green]Regime[/green]: %s\n", regimes[i].id, regimes[i].name);
    }
}

void listarRegimesPermissoes(){
    printf("\nListagem de todos os Regimes:\n");
    for (int i = 0; i < n_regimes; i++){
        printc("\n[green]ID[/green]: %d [green]Regime[/green]: %s\n", regimes[i].id, regimes[i].name);
        printc("**************************************************\n");
        printc("******************** [blue]Permissões[/blue] ******************\n");
        printc("**************************************************\n");

        printc("[blue]Permissoes Exames:[/blue]\n");
        printc("\t[blue]Criar exames[/blue]: %d\n", perms_file[i].perm.CriarExames);
        printc("\t[blue]Inscritos exames[/blue]: %d\n", perms_file[i].perm.InscritosExames);
        printc("\t[blue]Listar exames[/blue]: %d\n", perms_file[i].perm.ListarExames);
        printc("\t[blue]Listar exames inscritos[/blue]: %d\n", perms_file[i].perm.ListarExamesInscritos);
        printc("\t[blue]Editar exames[/blue]: %d\n", perms_file[i].perm.EditarExames);
        printc("\t[blue]Exportar exames[/blue]: %d\n", perms_file[i].perm.ExportarExames);
        printc("\t[blue]Inscrever em exames[/blue]: %d\n", perms_file[i].perm.InscreverExames);
        
        printc("\n[blue]Permissoes Salas:[/blue]\n");
        printc("\t[blue]Criar salas[/blue]: %d\n", perms_file[i].perm.CriarSalas);
        printc("\t[blue]Listar salas[/blue]: %d\n", perms_file[i].perm.ListarSalas);
        printc("\t[blue]Editar salas[/blue]: %d\n", perms_file[i].perm.EditarSalas);
        printc("\t[blue]Remover salas[/blue]: %d\n", perms_file[i].perm.RemoverSalas);
        
        printc("\n[blue]Permissoes Professores:[/blue]\n");
        printc("\t[blue]Criar professores[/blue]: %d\n", perms_file[i].perm.CriarProfessor);
        printc("\t[blue]Listar professores[/blue]: %d\n", perms_file[i].perm.ListarProfessor);
        printc("\t[blue]Editar professores[/blue]: %d\n", perms_file[i].perm.EditarProfessor);
        printc("\t[blue]Remover professores[/blue]: %d\n", perms_file[i].perm.RemoverProfessor);
       
        printc("\n[blue]Permissoes Cursos:[/blue]\n");
        printc("\t[blue]Criar cursos[/blue]: %d\n", perms_file[i].perm.CriarCursos);
        printc("\t[blue]Listar cursos[/blue]: %d\n", perms_file[i].perm.ListarCursos);
        printc("\t[blue]Editar cursos[/blue]: %d\n", perms_file[i].perm.EditarCursos);
        printc("\t[blue]Remover cursos[/blue]: %d\n", perms_file[i].perm.RemoverCursos);
       
        printc("\n[blue]Permissoes Disciplinas:[/blue]\n");
        printc("\t[blue]Listar cursos e disciplinas[/blue]: %d\n", perms_file[i].perm.ListarCursosDisciplinas);
        printc("\t[blue]Criar disciplinas[/blue]: %d\n", perms_file[i].perm.CriarDisciplinas);
        printc("\t[blue]Listar disciplinas[/blue]: %d\n", perms_file[i].perm.ListarDisciplinas);
        printc("\t[blue]Editar disciplinas[/blue]: %d\n", perms_file[i].perm.EditarDisciplinas);
        printc("\t[blue]Remover disciplinas[/blue]: %d\n", perms_file[i].perm.RemoverDisciplinas);
        printc("\t[blue]Ver disciplinas[/blue]: %d\n", perms_file[i].perm.VerDisciplinas);
       
        printc("\n[blue]Permissoes Alunos:[/blue]\n");
        printc("\t[blue]Criar alunos[/blue]: %d\n", perms_file[i].perm.CriarAluno);
        printc("\t[blue]Listar alunos[/blue]: %d\n", perms_file[i].perm.ListarAluno);
        printc("\t[blue]Listar todos os alunos[/blue]: %d\n", perms_file[i].perm.ListarTodosAlunos);
        printc("\t[blue]Editar alunos[/blue]: %d\n", perms_file[i].perm.EditarAluno);
        printc("\t[blue]Remover alunos[/blue]: %d\n", perms_file[i].perm.RemoverAluno);

        printc("\n[blue]Permissoes Regimes:[/blue]\n");
        printc("\t[blue]Criar regimes[/blue]: %d\n", perms_file[i].perm.CriarRegimes);
        printc("\t[blue]Listar regimes[/blue]: %d\n", perms_file[i].perm.ListarRegimes);
        printc("\t[blue]Listar regimes e permissões[/blue]: %d\n", perms_file[i].perm.ListarRegimesPermissoes);
        printc("\t[blue]Editar nome dos regimes[/blue]: %d\n", perms_file[i].perm.EditarNomeRegimes);
        printc("\t[blue]Editar permissões dos regimes[/blue]: %d\n", perms_file[i].perm.EditarPermissoesRegimes);
        printc("\t[blue]Mover regimes[/blue]: %d\n", perms_file[i].perm.MoverRegimes);
        printc("\t[blue]Remover regimes[/blue]: %d\n", perms_file[i].perm.RemoverRegimes);
    }
}

int checkIfRegimeExists(int id){
    for (int i = 0; i < n_regimes; i++){
        if (regimes[i].id == id){
            return 1;
        }
    }
    return 0;
}

int checkIfRegimesBeingUsed(int id){
    for (int i = 0; i < n_alunos; i++){
        if (alunos[i].id_regime == id){
            return 1;
        }
    }
    return 0;
}

void masiveRegimeChange(int id, int new_id){
    for (int i = 0; i < n_alunos; i++){
        if (alunos[i].id_regime == id){
            alunos[i].id_regime = new_id;
        }
    }
    saveBinRegimes();
    saveBinAlunos();
    updateUser();
}