#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../All_functions\global.h"

//GLOBAL VARIABLES
extern disciplinasStruct *disciplinas;
extern courseStruct *courses;
extern AlunoStruct *alunos;
extern AlunoDataStruct aluno;
extern professorStruct *professores;
extern int n_disciplinas, n_courses, n_alunos, n_professores;


void ListarDisciplinas()
{
    printf("**************************************************\n");
    printc("************        [green]Disciplinas[/green]       ************\n");
    printf("**************************************************\n");
    for(int i=0;i<n_disciplinas;i++)
    {
       printc("\t[green]Id:[/green] %d \t[green]Nome:[/green] %s\n", disciplinas[i].id, disciplinas[i].name);
    }
    printf("\n");
}

void ListarPropriasDisciplinas()
{
    for(int i = 0; i<3; i++)
    {
        printf("Ano %d: ", i+1);
        for(int j = 0; j<aluno.course.num_disciplinas[i]; j++)
        {
            printf("%s\n", aluno.course.AnoDisciplina[i][j]);
        }
        printf("\n");
    }
}

void CriarDisciplina()
{   
    char nameDisciplina[10], nomeCurso[10], op;
    printc("\n\n\t[green]Insira a sigla da nova disciplina:[/green] ");
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
    ListarDisciplinas();
    SaveBinDisciplinas();
    printc("\n\n\t[green]Disciplpina criada com sucesso![/green]");
}

void RemoverDisciplina()
{
    char NameDisciplina[15];
    ListarDisciplinas();
    printc("\n\n\t[green]Insira o nome da disciplina que quer remover: [/green]");
    scanf("%s", NameDisciplina);
    uppercase(NameDisciplina);
    if (CheckIFDisciplinaExisteNome(NameDisciplina) == -1){
        do{
            printc("\n\n\t[red]Disciplina nao existe[/red]\n\n");
            printf("\n\n\tInsira o nome da disciplina que quer remover: ");
            scanf("%s", NameDisciplina);
            uppercase(NameDisciplina);
        } while (CheckIFDisciplinaExisteNome(NameDisciplina) == -1);
    }    
    RemoverDisciplinaFromCursos(disciplinas[CheckIFDisciplinaExisteNome(NameDisciplina)].name);
    for (int i = CheckIFDisciplinaExisteNome(NameDisciplina); i < n_disciplinas; i++){
        if(i!=(n_disciplinas-1)){
        disciplinas[i].id = disciplinas[i+1].id;
        disciplinas[i].name = malloc(strlen(disciplinas[i+1].name+1));  
        strcpy(disciplinas[i].name , disciplinas[i+1].name);
        }   
    }
     
    disciplinas = realloc(disciplinas, sizeof(disciplinasStruct) * (n_disciplinas-1));
    n_disciplinas--; 
    SaveBinDisciplinas();
    
}

void EditarDisciplina()
{
    int id;
    char TmpDiscName[10];
    ListarDisciplinas();
    printc("\n\n\t[green]Insira o ID da disciplina que quer editar:[/green] ");
    scanf("%d", &id);
    for (int i = 0; i < n_disciplinas; i++)
    {
        if (disciplinas[i].id == id)
        {
            printf("\n\tNova sigla: ");
            scanf("%s", TmpDiscName);
            uppercase(TmpDiscName);
            if(CheckIFDisciplinaExisteNome(TmpDiscName) != -1){
                printc("\n\n\t[red]Disciplina ja existe[/red]\n\n");
                do{
                    printf("\n\tNova Sigla: ");
                    scanf("%s", TmpDiscName);
                    uppercase(TmpDiscName);
                } while(CheckIFDisciplinaExisteNome(TmpDiscName) != -1);
            }
            EditarDisciplinaFromCursos(disciplinas[i].name,TmpDiscName);
            disciplinas[i].name = realloc(disciplinas[i].name, (strlen(TmpDiscName) + 1));
            strcpy(disciplinas[i].name, TmpDiscName);
            break;
        }
    }
    SaveBinDisciplinas();
    printc("[green]Disciplina editada com sucesso![/green]");
}

//________CURSOS_____CURSOS______CURSOS______CURSOS______CURSOS_______CURSOS_______CURSOS_________

void ListarCursos()
{
    
    for(int i=0; i<n_courses; i++){
        int findID;
        for(int j=0; j<n_professores; j++){
            if(courses[i].IdDiretor == professores[j].id){
                findID = j;
                break;
            }
        }
        printf("\nCurso %d: %s\n", courses[i].id,  courses[i].name);
        printc("[green]ID[/green]: %d [blue]Diretor[/blue]: %s\n", courses[i].IdDiretor, professores[findID].nomeProfessor);
    }
}

void ListarCursosDisciplinas()
{
    for(int i=0; i<n_courses; i++)
    {
        printf("\nCurso %d: %s\n", courses[i].id,  courses[i].name);
        for(int j=0; j<3; j++)
        {
            printc("Disciplinas do [green]%d[/green] ano : ", j+1);
            if(courses[i].num_disciplinas[j] == 0)
            {
                printc("[red]Inexistente![/red]\t");
            }
            else
            {
                for(int k=0; k<courses[i].num_disciplinas[j]; k++)
                {
                    if(courses[i].AnoDisciplina[j][k] != NULL)
                    printf("%s\t", courses[i].AnoDisciplina[j][k]);
                    else
                    printc("[red]Inexistente![/red]\t");
                    if(k%5 == 0)
                        printf("\n");
                }
            }
            printf("\n");
        }
        int findID;
        for(int j=0; j<n_professores; j++){
            if(courses[i].IdDiretor == professores[j].id){
                findID = j;
                break;
            }
        }
        printc("[green]ID[/green]: %d [blue]Diretor[/blue]:  %s \n", courses[i].IdDiretor, professores[findID].nomeProfessor);
        printf("------------------------------------------------------------\n");
    }
}

void CriarCurso()
{   
    char TmpNameCurso[15], TmpNameDisciplina[15];
    int TmpIdDiretor;    
    courses = realloc(courses, (n_courses+1) * sizeof(courseStruct));
    courses[n_courses].AnoDisciplina = malloc(3);
    printf("**************************************************\n");
    printc("************        [blue]Criar Curso[/blue]       ************\n");
    printf("**************************************************\n");
    printc("\n[green]Nome do novo curso:[/green] ");
    scanf("%s", TmpNameCurso);
    uppercase(TmpNameCurso);
    if(CheckIFCursoExisteNome(TmpNameCurso) != -1){
        printc("\n\n\t[red]Este curso ja existe[/red]\n\n");
        do{
            printf("\n\nInsira a sigla do novo curso: ");
            scanf("%s", TmpNameCurso);
            uppercase(TmpNameCurso);
        } while (CheckIFCursoExisteNome(TmpNameCurso) != -1); 
    }

    courses[n_courses].id = n_courses;
    courses[n_courses].name = realloc(courses[n_courses-1].name, strlen(TmpNameCurso + 1));
    strcpy(courses[n_courses].name, TmpNameCurso);
    
    printc("\n\n[green]Insira o ID do diretor deste curso:[/green] ");
    scanf("%d", &TmpIdDiretor);
    if(CheckIFProfessor(TmpIdDiretor) == -1){
        printc("\n\n\t[red]Esta pessoa não é professor[/red]\n\n");
        do{
            printf("\n\nInsira o ID do um professor para ser o diretor deste curso: ");
            scanf("%d", &TmpIdDiretor);
        } while (CheckIFProfessor(TmpIdDiretor) == -1); 
    }
    courses[n_courses].IdDiretor = TmpIdDiretor;

    for(int i=0; i<3; i++)   
    { 
        printc("\nQuantas disciplinas tem %d ano o curso? ",i+1);
        scanf("%d", &courses[n_courses].num_disciplinas[i]);
        if(courses[n_courses].num_disciplinas[i] >= n_disciplinas){
                printc("\n\t[red]Numero de disciplinas invalido[/red]\n");
                do{
                    printf("\nInsira o numero de disciplinas do %d ano: ", i+1);
                    scanf("%d", &courses[n_courses].num_disciplinas[i]);
                }while(courses[n_courses].num_disciplinas[i] >= n_disciplinas);
            }
        courses[n_courses].AnoDisciplina[i] = malloc(courses[n_courses].num_disciplinas[i]);
        ListarDisciplinas();
        printc("\n[green]Disciplinas do %d ano:[/green] ", i+1);
        for(int j=0; j<courses[n_courses].num_disciplinas[i]; j++){   
            do{
                printf("\n\nInsira a nome da disciplina: ");
                scanf("%s", TmpNameDisciplina);
                uppercase(TmpNameDisciplina);
                
                if(CheckIFDisciplinaExisteNome(TmpNameDisciplina) == -1){
                    printc("\n\n\t[red]Esta disciplina nao existe[/red]\n\n");
                }
            } while (CheckIFDisciplinaExisteNome(TmpNameDisciplina) == -1); 
            courses[n_courses].AnoDisciplina[i][j] = malloc(strlen(TmpNameDisciplina) + 1);
            strcpy(courses[n_courses].AnoDisciplina[i][j], TmpNameDisciplina);
        }
    }
    n_courses++;
    SaveBinCursosDisciplina();
    printc("\n\n\t[green]Curso criado com sucesso![/green]");
}

void EditarCursos(){

    int id, TmpIdDiretor;
    char op, TmpNameCurso[15], TmpNameDisciplina[15];

    printc("[green]Cursos existentes:[/green]");
    ListarCursos();
    printc("\n\n\t[green]Insira o ID do curso que quer editar:[/green] ");
    scanf("%d", &id);
    if (CheckIFCursoExiste(id) == -1){
        do
        {
            printc("\n\n\t[red]Curso nao existe[/red]\n\n");
            printc("\n\n\tInsira o ID do curso que quer editar: ");
            scanf("%d", &id);
        } while (CheckIFCursoExiste(id) == -1);
    }
    printc("\n[green]Curso encontrado!\n[/green]");
    printf("Curso %d: %s\n", courses[CheckIFCursoExiste(id)].id,  courses[CheckIFCursoExiste(id)].name);
    printc("Alterar nome?([green]s[/green]/[red]n[/red]): ");
    scanf(" %c", &op);
    if(op == 'S' || op == 's')
    {
        printf("\n\nInsira o novo nome do curso: ");
        scanf("%s", TmpNameCurso);
        uppercase(TmpNameCurso);
        if(CheckIFCursoExisteNome(TmpNameCurso) != -1){
            printc("\n\n\t[red]Curso ja existe[/red]\n\n");
            do{
                printf("\n\nInsira o novo nome do curso: ");
                scanf("%s", TmpNameCurso);
                uppercase(TmpNameCurso);
            } while (CheckIFCursoExisteNome(TmpNameCurso) != -1); 
        }
        courses[CheckIFCursoExiste(id)].name = malloc(strlen(TmpNameCurso) + 1);
        strcpy(courses[CheckIFCursoExiste(id)].name, TmpNameCurso);

    }
    printc("\n\nAlterar disciplinas? ([green]s[/green]/[red]n[/red]): ");
    scanf(" %c", &op);
    if(op == 'S' || op == 's')
        realocarMatriz(courses[CheckIFCursoExiste(id)].id);
    printc("\n\nAlterar diretor? ([green]s[/green]/[red]n[/red]): ");
    scanf(" %c", &op);
    if(op == 'S' || op == 's')
    {
        listarProfessor();
        printc("\n\n\t[green]Insira o ID do novo diretor deste curso: [/green] ");
        scanf("%d", &TmpIdDiretor);
        if(CheckIFProfessor(TmpIdDiretor) == -1){
            printc("\n\n\t[red]Esta pessoa não é profesor[/red]\n\n");
            do{
                printf("\n\nInsira o ID do um professor para ser o novo diretor deste curso: ");
                scanf("%d", &TmpIdDiretor);
            }while (CheckIFProfessor(TmpIdDiretor) == -1); 
        }
    courses[CheckIFCursoExiste(id)].IdDiretor = TmpIdDiretor;
    }
    printc("\n\n\t[green]Curso editado com sucesso![/green]\n\n");
    SaveBinCursosDisciplina();
    if(aluno.course.id == courses[CheckIFCursoExiste(id)].id)
        aluno.course = courses[CheckIFCursoExiste(id)];   
}

void realocarMatriz(int idCurso)
{
    int addOrwrite;
    char TmpNameDisciplina[50];
    char **vetorAux;                
    do
    {
        printc("[yellow]Pretende adicionar disciplinas ou reescreve-las 1-->adicionar 2--> reescrever [/yellow]");
        scanf(" %d", &addOrwrite);
    } while (addOrwrite != 1 && addOrwrite != 2);
    
    

    for (int i = 0; i < n_courses; i++)
    {
        if(courses[i].id == idCurso)
        {
            for(int j=0; j<3; j++)
            {   int k;
                vetorAux = malloc(courses[i].num_disciplinas[j]);
                for(k=0; k<courses[i].num_disciplinas[j]; k++)
                {
                    vetorAux[k] = malloc((strlen(courses[i].AnoDisciplina[j][k])+1));
                    strcpy(vetorAux[k], courses[i].AnoDisciplina[j][k]);
                }

                do
                {
                printf("Quantas disciplinas quer que tenha o %d ano do curso? ",j+1);
                scanf("%d", &courses[i].num_disciplinas[j]);
                } while (courses[i].num_disciplinas[j] >= n_disciplinas && courses[i].num_disciplinas[j] < 0);
                courses[i].AnoDisciplina[j] = malloc(courses[i].num_disciplinas[j]);

                if(addOrwrite == 1)
                {
                    if(k<courses[i].num_disciplinas[j])
                    {
                            for(int l = 0; l<k;l++)
                            {
                                courses[i].AnoDisciplina[j][l] = malloc((strlen(vetorAux[l])+1));
                                strcpy(courses[i].AnoDisciplina[j][l], vetorAux[l]);
                            }
                            for(int l = k; l<courses[i].num_disciplinas[j];l++)
                            {
                                ListarDisciplinas();
                                printf("Insira nome da disciplina %d: ", l+1);
                                scanf("%s", TmpNameDisciplina);
                                uppercase(TmpNameDisciplina);
                                if(CheckIFDisciplinaExisteNome(TmpNameDisciplina) == -1){
                                    printc("\n\n\t[red]Disciplina nao existe[/red]\n\n");
                                    do{
                                        printf("\n\nInsira o novo nome da disciplina: ");
                                        scanf("%s", TmpNameDisciplina);
                                        uppercase(TmpNameDisciplina);
                                    } while (CheckIFDisciplinaExisteNome(TmpNameDisciplina) == -1); 
                                }
                                courses[i].AnoDisciplina[j][l] = malloc(strlen((TmpNameDisciplina)+1));
                                strcpy(courses[i].AnoDisciplina[j][l], TmpNameDisciplina);
                            }                        
                    }
                    else
                    {
                        for(int l = 0; l<courses[i].num_disciplinas[j];l++)
                        {
                            courses[i].AnoDisciplina[j][l] = malloc((strlen(vetorAux[l])+1));
                            strcpy(courses[i].AnoDisciplina[j][l], vetorAux[l]);
                        }
                    }
                }
                else
                {
                    for(int l = 0; l<courses[i].num_disciplinas[j];l++)
                    {
                        ListarDisciplinas();
                        printf("Insira nome da disciplina %d: ", l+1);
                        scanf("%s", TmpNameDisciplina);
                        uppercase(TmpNameDisciplina);
                            if(CheckIFDisciplinaExisteNome(TmpNameDisciplina) == -1){
                                printc("\n\n\t[red]Disciplina nao existe[/red]\n\n");
                                do{
                                    printf("\n\nInsira o novo nome da disciplina: ");
                                    scanf("%s", TmpNameDisciplina);
                                    uppercase(TmpNameDisciplina);
                                } while (CheckIFDisciplinaExisteNome(TmpNameDisciplina) == -1); 
                            }
                        courses[i].AnoDisciplina[j][l] = malloc(strlen((TmpNameDisciplina)+1));
                        strcpy(courses[i].AnoDisciplina[j][l], TmpNameDisciplina);
                    }
                }
            }
        }
    }
    
}

void RemoverDisciplinaFromCursos(char* name)
{
    int aux, flag = 0;
    // Verifique se o nome da disciplina é válido
    if (name == NULL || strlen(name) == 0)
    {
        printf("Nome de disciplina inválido\n");
        return;
    }

    for (int i = 0; i < n_courses; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < courses[i].num_disciplinas[j]; k++)
            {
                if (strcmp(courses[i].AnoDisciplina[j][k], name) == 0)
                {
                    // Desloca as disciplinas subsequentes uma posição para a esquerda e decrementa num_disciplinas
                    for (int l = k; l < courses[i].num_disciplinas[j]; l++)
                    {
                        if(l != courses[i].num_disciplinas[j] - 1)
                        {
                            courses[i].AnoDisciplina[j][l] = malloc(strlen(courses[i].AnoDisciplina[j][l+1]+1));
                            strcpy(courses[i].AnoDisciplina[j][l], courses[i].AnoDisciplina[j][l+1]);
                            
                        }
                    }
                    courses[i].num_disciplinas[j]--;
                    if(aluno.course.id == courses[i].id)
                    aluno.course = courses[i];
                }
            }
        }
    }
    SaveBinCursosDisciplina();
    
}


void EditarDisciplinaFromCursos(char *NameOriginal,char *nameNovo)
{
    for (int i = 0; i < n_courses; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < courses[i].num_disciplinas[j]; k++){
                if (strcmp(courses[i].AnoDisciplina[j][k], NameOriginal) == 0){
                    courses[i].AnoDisciplina[j][k] = malloc((strlen(nameNovo)+1));
                    strcpy(courses[i].AnoDisciplina[j][k], nameNovo);
                    if(aluno.course.id == courses[i].id)
                    aluno.course = courses[i];   
                }
            }
        } 
    }
    SaveBinCursosDisciplina();

}

int CheckIFDisciplinaExiste(int id)
{
    for(int i=0; i<n_disciplinas; i++){
        if(disciplinas[i].id == id)
            return i;
    }
    return -1;
}

int CheckIFDisciplinaExisteNome(char *name)
{
    for(int i=0; i<n_disciplinas; i++){
        if(strcmp(disciplinas[i].name, name) == 0)
            return i;
    }
    return -1;
}

int CheckIFCursoExiste(int id)
{
    for(int i = 0; i<n_courses; i++){
        if(courses[i].id == id)
            return i;
    }
    return -1;
}

int CheckIFCursoExisteNome(char *name)
{
    for(int i = 0; i<n_courses-1; i++){
        if(strcmp(courses[i].name, name) == 0){
            return i;
        }   
    }
    return -1;
}

int CheckIFProfessor(int id)
{
    for(int i=0; i<n_professores; i++){
        if(professores[i].id == id)
            return i;
    }
    return -1;
}