#include "structs.h"
#include <stdbool.h>

//colorprint.c
#ifndef CJAG_COLORPRINT
#define CJAG_COLORPRINT
#define ERROR_TAG "[r][ERROR][/r] "
void printc(const char *fmt, ...);
void spinner_start(unsigned int type, const char* fmt, ...);
void spinner_update(const char* fmt, ...);
void spinner_done(const char* fmt, ...);
void progress_start(int max, char* fmt);
void progress_update();
#endif

//utils.c
int ValidarZeroUm();
char *lowercase(char *str);
char *uppercase(char *str);
int isdigit_cheker(char *str);
void generate_unique_numbers(int *array, int length);
char *capitalize(char *str);
int isletter_cheker(char *str);
tempoExames dateSumHoursMinutes(tempoExames date, int hours, int minutes);
int isValidDate(tempoExames date);
int is_between_dates(tempoExames start, tempoExames end, tempoExames check);
/* void timeNow();
void diferencaTempo(int ano, int mes, int dia, int hora, int minuto);
struct tm add_time(struct tm original_time,int minutes_to_add, int hours_to_add);
struct tm TempoDeTeste(int mes, int dia, int hora, int minuto, int n_TesteTempoHora, int n_TesteTempoMinuto);
int ChackTempoDeTeste(int mes, int dia, int hora, int minuto, int n_TesteTempoHora, int n_TesteTempoMinuto); */
int days_in_month(int month, int year);
struct Date add_time(struct Date date, int hours, int minutes);
int fileExistAll();

//alunosTxt.c
AlunoFileStruct* getTxt();
void ConvertAluno(AlunoFileStruct *alunosFile);

//alunos.c
void saveBinAlunos();
void printAlunos();
void readBinAlunos();
void login(char *email, char *password);
void getUserDataByID(int id);
void printfUserData();
int checkIfUserExists(int id);
int generateUserID();
void getUserDataByIDProf(int id);

//courses.c
void getAllCourses(AlunoFileStruct *alunosFile);
courseStruct getCourseByID(int id);

//regimes.c
void getAllRegimes(AlunoFileStruct *alunosFile);
void saveBinRegimes();
void readBinRegimes();
regimeStruct getRegimeByID(int id);
void listarRegimes();
void listarRegimesPermissoes();
int checkIfRegimeExists(int id);
int checkIfRegimesBeingUsed(int id);
void masiveRegimeChange(int id, int new_id);
void moverRegimes();

//permissions.c
void saveAndSetPermissionsBinByTxt();
void readBinPermissions();
void saveBinPermissions();
PermissionsType getPermissionsByID(int id);

//menus.c
void MenuCursos();
int mainMenu();
void MenuAlunos();
void MenuAdmin();
int MenuEditarConta();
void MenuPrincipal();
int importExportMenu();
void MenuDisciplinas();
void MenuEditarAdicionarRemoverDisciplinas();
void MenuFilesNovos();
int menuEditAluno();
void MenuSalas();
void MenuProfessor();
void MenuExames();
void MenuRegimes();
void editarRegimeMenu();

//importExport.c
void importExportData();
void importDataTxtBin();
void exportDataBinTxt();
void exportDataBinCsv();

//salas.c
void InitSalas();//Apenas necessario primeira vez(apos isso ja temos o ficheiro que podemos binario)
void criarSalainit();//Apenas necessario primeira vez
void criarSala();
void listarSalas();
void readBinSalas();
void editarSala();
void removerSala();
int CheckIFsalaExist(char *nomeSala, int nSala);
void saveBinSalas();

//disciplinas.c
/* void InitDisciplinas(); *///Apenas necessario primeira vez(apos isso ja temos o ficheiro que podemos binario)
void ReadBinDisciplinas();//Apenas necessario primeira vez(ja vamos ter o ficheiro que podemos binario)
void SaveBinDisciplinas();
void ReadTxtDisciplinas();

//cursosdisciplinas.c
void getAllCourses(AlunoFileStruct *alunosFile);//Apenas necessario primeira vez(apos isso ja temos o ficheiro que podemos binario)
int InitCursos();//Apenas necessario primeira vez(apos isso ja temos o ficheiro que podemos binario)
void ReadBinCursosDisciplina();
void SaveBinCursosDisciplina();

//UnidadesCurriculares.c
void criardisciplinas();
void ListarDisciplinas();
void ListarPropriasDisciplinas();
void CriarDisciplina();
void RemoverDisciplina();
void EditarDisciplina();
//--------------------------------------------
void ListarCursosDisciplinas();
void RemoverDisciplinaFromCursos(char* name);
void EditarDisciplinaFromCursos(char *NameOriginal,char *nameNovo);
//--------------------------------------------
void ListarCursos();
void CriarCurso();
void EditarCursos();
void RemoverCursos();
void realocarMatriz(int idCurso);
//--------------------------------------------
int CheckIFDisciplinaExiste(int id);
int CheckIFDisciplinaExisteNome(char *name);
int CheckIFCursoExiste(int id);
int CheckIFCursoExisteNome(char *name);
int CheckIFProfessor(int id);

//professores.c
void criarProfessor();
void readBinProfessores();
void listarProfessor();
void editarProfessor();
void removerProfessor();
void saveBinProfessor();

//currentUser.c
void changeName();
void changePassword();
void editAccount();
void updateUser();

//main.c
void readData();

//admin.c
void listarTodosAlunos();
void listarAluno();
void criarAluno();
void alterarAluno();
void apagarAluno();

//exames.c
void criarExame();
void zerarExame();
void listarExames();
int CheckDiscInCurso(int id, int n_Exame);
void ReservarSala(int N_exames, tempoExames dateFinal);
void RemoverReservaSala(int N_exames);
int CheckIfDataExisteExame(tempoExames dataInicio, tempoExames dataFinal, int *x, int *y);
void listarSalasReservas();
void listarSalasLivre();
void removerExame();
void listarReservasIndividuais(char *SalaNome, int SalaNum);
void inscreverExame();
void contarInscrito(int id);
void listarInscritos(int id);
void listarExamesdeumAluno();
void removerIncricao();
void vagaMais(int salaId, char *SalaNome, int id);
void vagaMenos(int salaId, char *SalaNome, int id);
void saveBinExames();
void readBinExames();
int checkdiscaluno(char *disc, AlunoDataStruct aluno, int idCurso);

//regime.c on MenuOpcao
void criarRegime();
void editarNomeRegime();
void editarPermissoesRegime();
void removerRegime();