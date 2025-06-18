#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * char *data, *horario;
 * data = __DATE__;
 * horario = __TIME__;
 */

typedef struct {
	int segundos, minutos, horas;
}Horario;

int main(){
	
	Horario tempo;
	char *tempo2;
	
	tempo2 = __TIME__;
	printf ("Horas pelo sistema: %s\n", tempo2);
	
	tempo.horas = ((__TIME__[0]-'0')*10) + (__TIME__[1]-'0');
	tempo.minutos = ((__TIME__[3]-'0')*10) + (__TIME__[4]-'0');
	tempo.segundos = ((__TIME__[6]-'0')*10) + (__TIME__[7]-'0');

	
	printf ("Horas calculadas pelos segundos: %02d:%02d:%02d", tempo.horas, tempo.minutos, tempo.segundos);
	
	return 0;
}



