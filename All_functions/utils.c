#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>
#include "global.h"
//#include "structs.h"

extern TempoAnoAtualDiferenca tempo;

char *lowercase(char *str){
    int i;
    for(i = 0; i < strlen(str); i++){
        str[i] = tolower(str[i]);
    }
    return str;
}

char *uppercase(char *str){
    int i;
    for(i = 0; i < strlen(str); i++){
        str[i] = toupper(str[i]);
    }
    return str;
}

char *capitalize(char *str){
    int i;
    lowercase(str);
    str[0] = toupper(str[0]);
    return str;
}


int isdigit_cheker(char *str){
    int i, flag = 0;
    for(i = 0; i < strlen(str); i++){
        if(isdigit(str[i])){
          flag = 1;
        }
    }
    if (flag == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int isletter_cheker(char *str){
    int i, flag = 0;
    for(i = 0; i < strlen(str); i++){
        if(isalpha(str[i])){
          flag = 1;
        }
    }
    if (flag == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int ValidarZeroUm(){
    int flag = 0, num = -1;
    while (1){
        if(flag == 1){
            printc("\n[red]Numero inválido, tente novamente: [/red]");
        }
        scanf("%d", &num);
        if(num == 0 || num == 1){
            break;
        }
        flag = 1;
    }
    return num;
}

/* void timeNow(){
    time_t now;
    time(&now);
    struct tm *tempoAgora;

    tempoAgora = localtime(&now);

    //printf("Current date and time: %04d-%02d-%02d %02d:%02d:%02d\n", tempoAgora->tm_year + 1900, tempoAgora->tm_mon + 1, tempoAgora->tm_mday, tempoAgora->tm_hour, tempoAgora->tm_min, tempoAgora->tm_sec);
}

void diferencaTempo(int mes, int dia, int hora, int minuto){
    struct tm *tempoAgora;
    timeNow();
    tempo.difMes = tempoAgora->tm_mon + 1 - mes;
    tempo.difDia = tempoAgora->tm_mday - dia;
    tempo.difHora = tempoAgora->tm_hour - hora;
    tempo.difMinuto = tempoAgora->tm_min;
}*/

/*     struct Date date;
    date.year = 2020;
    date.month = 1;
    date.day = 31;
    date.hour = 12;
    date.minute = 30; */

/*     date = add_time(date, 10, 90);

    printf("New date and time: %d-%02d-%02d %02d:%02d\n", date.year, date.month, date.day, date.hour, date.minute); */

//auxiliar
int days_in_month(int month, int year) {
    if (month == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

tempoExames dateSumHoursMinutes(tempoExames date, int hours, int minutes) {
    int days = 0;
    date.minuto += minutes;
    while (date.minuto >= 60) {
        date.minuto -= 60;
        date.hora++;
    }

    date.hora += hours;
    while (date.hora >= 24) {
        date.hora -= 24;
        days++;
    }

    date.dia += days;
    while (date.dia > days_in_month(date.mes, date.ano)) {
        date.dia -= days_in_month(date.mes, date.ano);
        date.mes++;
        if (date.mes > 12) {
            date.mes = 1;
            date.ano++;
        }
    }
    return date;
}

int is_between_dates(tempoExames start, tempoExames end, tempoExames check) {
    if (start.ano > end.ano) {
        tempoExames temp = start;
        start = end;
        end = temp;
    } else if (start.ano == end.ano && start.mes > end.mes) {
        tempoExames temp = start;
        start = end;
        end = temp;
    } else if (start.ano == end.ano && start.mes == end.mes && start.dia > end.dia) {
        tempoExames temp = start;
        start = end;
        end = temp;
    } else if (start.ano == end.ano && start.mes == end.mes && start.dia == end.dia && start.hora > end.hora) {
        tempoExames temp = start;
        start = end;
        end = temp;
    } else if (start.ano == end.ano && start.mes == end.mes && start.dia == end.dia && start.hora == end.hora && start.minuto > end.minuto) {
        tempoExames temp = start;
        start = end;
        end = temp;
    }
    if (check.ano < start.ano || check.ano > end.ano) {
        return 0;
    } else if (check.ano == start.ano && check.mes < start.mes) {
        return 0;
    } else if (check.ano == end.ano && check.mes > end.mes) {
        return 0;
    } else if (check.ano == start.ano && check.mes == start.mes && check.dia < start.dia) {
        return 0;
    } else if (check.ano == end.ano && check.mes == end.mes && check.dia > end.dia) {
        return 0;
    } else if (check.ano == start.ano && check.mes == start.mes && check.dia == start.dia && check.hora < start.hora) {
        return 0;
    } else if (check.ano == end.ano && check.mes == end.mes && check.dia == end.dia && check.hora > end.hora) {
        return 0;
    } else if (check.ano == start.ano && check.mes == start.mes && check.dia == start.dia && check.hora == start.hora && check.minuto < start.minuto) {
        return 0;
    } else if (check.ano == end.ano && check.mes == end.mes && check.dia == end.dia && check.hora == end.hora && check.minuto > end.minuto) {
        return 0;
    } else {
        return 1;
    }
}

int isValidDate(tempoExames date) {
    if (date.ano < 1) {
        return 0;
    }

    int mesLength[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Check for leap ano
    if (date.ano % 4 == 0 && (date.ano % 100 != 0 || date.ano % 400 == 0)) {
        mesLength[1] = 29;
    }

    if (date.mes < 1 || date.mes > 12) {
        return 0;
    }
    if (date.dia < 1 || date.dia > mesLength[date.mes - 1]) {
        return 0;
    }
    if (date.hora < 0 || date.hora > 23) {
        return 0;
    }
    if (date.minuto < 0 || date.minuto > 59) {
        return 0;
    }
    return 1;
}

void generate_unique_numbers(int *array, int length) {
  // Create a set to store the unique values
  int max = 150000, min = 1000;
  int unique_values[150000 - 1000 + 1] = {0}; //<-- MAX AND MIN NEED TO BE THE SAME AS ^^ 

  // Loop through the array and check for duplicates
  for (int i = 0; i < length; i++) {
    if (unique_values[array[i] - min] == 1) {
      // Generate a new unique number and replace the duplicate
      int new_number;
      do {
        new_number = rand() % (max - min + 1) + min;
      } while (unique_values[new_number - min] == 1);
      array[i] = new_number;

      // Mark the new number as seen
      unique_values[new_number - min] = 1;
    } else {
      // Mark the current number as seen
      unique_values[array[i] - min] = 1;
    }
  }
}


int fileExists(const char* path) {
  struct stat st;
  if (stat(path, &st) == 0) {
    return 1;
  }
  return 0;
}

int fileExistAll(){
  if(fileExists("data/bin/alunos.bin") && fileExists("data/bin/cursosdisciplina.bin") && fileExists("data/bin/disciplinas.bin") && fileExists("data/bin/permission.bin") && fileExists("data/bin/professores.bin") && fileExists("data/bin/regimes.bin") && fileExists("data/bin/salas.bin")){
    return 1;
  }
  else{
    return 0;
  }
}