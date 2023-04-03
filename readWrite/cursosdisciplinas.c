#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

//GLOBAL VARIABLES
extern disciplinasStruct *disciplinas;
extern courseStruct *courses;
extern AlunoStruct *alunos;
extern AlunoFileStruct *alunosFile; 
extern int n_disciplinas, n_courses, n_alunos, n_professores;

void getAllCourses(AlunoFileStruct *alunosFile){
    courses = malloc(sizeof(courseStruct));
    for (int i = 0; i < n_alunos; i++){
        int found = 0;
        for (int j = 0; j < n_courses; j++){
            if (strcmp(alunosFile[i].course, courses[j].name) == 0){
                found = 1;
                break;
            }
        }
        if (!found){
            courses = realloc(courses, ((n_courses)+1)*sizeof(courseStruct));
            courses[n_courses].id = n_courses+1;
            courses[n_courses].name = malloc((strlen(alunosFile[i].course)+1));
            strcpy(courses[n_courses].name, alunosFile[i].course);
            n_courses++;
        }
    }
    SaveBinCursosDisciplina();
}

int InitCursos() { //Apenas usado pela primeira vez
    readBinProfessores();
    FILE *professoresbin = fopen("data/bin/professores.bin", "rb");
    if(n_professores == 0){
        printc("\n\n\t[red]Não existem professores registados[/red]\n\n");
        criarProfessor();
    }
    for (int i=0;i<n_courses;i++)
        courses[i].AnoDisciplina = malloc(3);
    char TmpNameDisciplina[15];
    int  TmpIdDiretor;
    for(int i=0; i<n_courses; i++){   
        fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
        ListarDisciplinas();
        printc("\n[green]Curso: [/green]%s\n",  courses[i].name);
            listarProfessor();
            printc("\n\n[green]Insira o ID do diretor deste curso:[/green] ");
            scanf("%d", &TmpIdDiretor);
            if(CheckIFProfessor(TmpIdDiretor) == -1){
                printc("\n\n\t[red]Esta pessoa não é professor[/red]\n\n");
                do{
                    printf("\n\nInsira o ID do um professor para ser o diretor deste curso: ");
                    scanf("%d", &TmpIdDiretor);
                } while (CheckIFProfessor(TmpIdDiretor) == -1); 
            }
            courses[i].IdDiretor = TmpIdDiretor;
        for(int j=0; j<3; j++){ 
            printf("Insira o numero de disciplinas do %d ano: ", j+1);
            scanf("%d", &courses[i].num_disciplinas[j]);
            if(courses[i].num_disciplinas[j] >= n_disciplinas){
                printc("\n\n\t[red]Numero de disciplinas invalido  -->  [/red]tem de ser menor do que o número total de disciplinas\n");
                printf("\\t[red]Numero de disciplinas total: %d[/red]\n\n", n_disciplinas);
                do{
                    printf("\n\nInsira o numero de disciplinas do %d ano: ", j+1);
                    scanf("%d", &courses[i].num_disciplinas[j]);
                }while(courses[i].num_disciplinas[j] >= n_disciplinas);
            }
            courses[i].AnoDisciplina[j] = malloc(courses[i].num_disciplinas[j]);
            printc("[green]Insira o nome das %d disciplinas do %d ano [/green]", courses[i].num_disciplinas[j], j+1);
            for(int k=0; k<courses[i].num_disciplinas[j]; k++)
            {   
                do{
                    printf("\n\nInsira a nome da disciplina %d: ", k+1);
                    scanf("%s", TmpNameDisciplina);
                    uppercase(TmpNameDisciplina);
                    if(CheckIFDisciplinaExisteNome(TmpNameDisciplina) == -1){
                        printc("\n\n\t[red]Disciplina nao existe[/red]\n\n");
                    }
                }while(CheckIFDisciplinaExisteNome(TmpNameDisciplina) == -1); 
                courses[i].AnoDisciplina[j][k] = malloc(strlen(TmpNameDisciplina)+1);
                strcpy(courses[i].AnoDisciplina[j][k], TmpNameDisciplina);
            }
        }
    }
    SaveBinCursosDisciplina();
}
void SaveBinCursosDisciplina(){

    FILE *CursoDisciplinaBin = fopen("data/bin/cursosdisciplina.bin","wb");
    if (!CursoDisciplinaBin) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]cursos.bin[/red]\n\n");
        return;
    }
    fwrite(&n_courses, sizeof(int), 1, CursoDisciplinaBin);
    for (int i = 0; i < n_courses; i++){
        fwrite(&courses[i].id, sizeof(int), 1, CursoDisciplinaBin);
        size_t CursoLen = strlen(courses[i].name) + 1;
        fwrite(&CursoLen, sizeof(size_t), 1, CursoDisciplinaBin);
        fwrite(courses[i].name, CursoLen, 1, CursoDisciplinaBin);
        for(int j=0; j<3; j++){   
            fwrite(&courses[i].num_disciplinas[j], sizeof(int), 1, CursoDisciplinaBin);
            for(int k=0;k < courses[i].num_disciplinas[j]; k++){
                size_t DisciplinaLen = strlen(courses[i].AnoDisciplina[j][k]) + 1;
                fwrite(&DisciplinaLen, sizeof(size_t), 1, CursoDisciplinaBin);
                fwrite(courses[i].AnoDisciplina[j][k], DisciplinaLen, 1, CursoDisciplinaBin);
            }
        }
        fwrite(&courses[i].IdDiretor, sizeof(int), 1, CursoDisciplinaBin);
    }
    fclose(CursoDisciplinaBin);
}


void ReadBinCursosDisciplina(){
    FILE *CursoDisciplinaBin = fopen("data/bin/cursosdisciplina.bin","rb");
    if (CursoDisciplinaBin == NULL) {
        printc("\n\n\tImpossivel abrir Ficheiro [red]cursosdisciplina.bin[/red]\n\n");
        return;
    }
    fread(&n_courses, sizeof(int), 1, CursoDisciplinaBin);    
    courses = malloc(sizeof(courseStruct)*n_courses);
        
    for (int i = 0; i < n_courses; i++){

        courses[i].AnoDisciplina = malloc(3);
        fread(&courses[i].id, sizeof(int), 1, CursoDisciplinaBin);

        size_t CursoLen;
        fread(&CursoLen, sizeof(size_t), 1, CursoDisciplinaBin);
        courses[i].name = malloc(CursoLen);
        fread(courses[i].name, CursoLen, 1, CursoDisciplinaBin);

        for(int j=0; j<3; j++)
        {   fread(&courses[i].num_disciplinas[j], sizeof(int), 1, CursoDisciplinaBin); 
            courses[i].AnoDisciplina[j] = malloc(courses[i].num_disciplinas[j]);
            for(int k=0; k<courses[i].num_disciplinas[j]; k++)
            {
                size_t DisciplinaName;
                fread(&DisciplinaName, sizeof(size_t), 1, CursoDisciplinaBin);
                courses[i].AnoDisciplina[j][k] = malloc(DisciplinaName);
                fread(courses[i].AnoDisciplina[j][k], DisciplinaName, 1, CursoDisciplinaBin);
            }
        }
        fread(&courses[i].IdDiretor, sizeof(int), 1, CursoDisciplinaBin);
    }
    fclose(CursoDisciplinaBin);
}


courseStruct getCourseByID(int id){
    for (int i = 0; i < n_courses; i++){
        if (courses[i].id == id){
            return courses[i];
        }
    }
    courseStruct course;
    course.id = -1;
    course.name = malloc(12);
    strcpy(course.name, "Não existe!");
    return course;
}