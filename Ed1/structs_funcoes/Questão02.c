#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int horas, minutos, segundos;
}Horario;

int main(){
	
	Horario horaAtual, horaDigita, horaFinal;
		
	printf ("informe a hora: ");
	scanf (" %2d", &horaDigita.horas);
	printf ("Informe os minutos: ");
	scanf (" %2d", &horaDigita.minutos);
	printf ("Informe os segundos: ");
	scanf (" %2d", &horaDigita.segundos);
	
	horaAtual.horas = ((time(NULL)/3600)%24)-3; 
	horaAtual.minutos = (time(NULL)/60)%60;
	horaAtual.segundos = time(NULL)%60;	
	
	printf ("Hora atual: %02d:%02d:%02d\n", horaAtual.horas,
			horaAtual.minutos, horaAtual.segundos);
	printf ("Hora digitada: %02d:%02d:%02d\n", horaDigita.horas,
			horaDigita.minutos, horaDigita.segundos);

	if (horaDigita.horas>horaAtual.horas){
		if (horaDigita.segundos<horaAtual.segundos){
			horaDigita.minutos -=1;
			horaDigita.segundos +=60;
		}
		if (horaDigita.minutos<horaAtual.minutos){
			horaDigita.horas -= 1;
			horaDigita.minutos += 60;
		}
		
		horaFinal.segundos = horaDigita.segundos - horaAtual.segundos;
		horaFinal.minutos = abs(horaDigita.minutos - horaAtual.minutos);
		horaFinal.horas = abs(horaDigita.horas - horaAtual.horas);
	}
	else {
		if (horaAtual.segundos<horaDigita.segundos){
			horaAtual.minutos -= 1;
			horaAtual.segundos += 60;
		}
		if (horaAtual.minutos<horaDigita.minutos){
			horaAtual.horas -= 1;
			horaAtual.minutos += 60;
		}
		horaFinal.segundos = horaAtual.segundos - horaDigita.segundos;
		horaFinal.minutos = horaAtual.minutos - horaDigita.minutos;
		horaFinal.horas = horaAtual.horas - horaDigita.horas;
	}	
	
	printf ("Diferença de horas: %02d:%02d:%02d\n",
			horaFinal.horas, horaFinal.minutos, horaFinal.segundos);
			
	return 0;
}



