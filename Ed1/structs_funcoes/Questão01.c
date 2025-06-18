#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int segundos, minutos, horas;
	int ano, mês, dia; 
} Horario;

int main(){
	Horario A;
	A.segundos = A.minutos = A.horas = time(NULL);
	A.ano = A.mês = A.dia = time(NULL);
	
	printf ("Hora atual: %02d:%02d:%02d\n\n", ((A.horas/3600)%24)-3,
			(A.minutos/60)%60, A.segundos%60);
	printf ("Data: %02d/%02d/%0d", ((A.dia/86400)%31), (((A.mês/86400)/31)%12)+1,
			((A.ano/86400)/365)+1970);
	return 0;
}



