#include<stdio.h>
#include<math.h>
# include<stdlib.h>
# include<time.h>


int main(void)
{
	int N;
	int cont, chk;
	double Aux, numero;
	float a, b;
	int Semilla;
	
	FILE *fi;
	
	fi = fopen("Salida.dat", "w");
	
	do{
		printf("Introduce la dimensión del vector (N > 1) -> ");
		chk = scanf("%i", &N);
		while(getchar() != '\n');
	}while(chk != 1 || N < 2);
	
    double Vec[N];	
	
// ****** Introducción de las componentes de manera aleatoria en el intervalo dado:
	
	do{
	    printf("Introduce los extremos del intervalo, en cuaquier orden -> ");
	    chk = scanf("%f %f", &a, &b);
	    while(getchar() != '\n');
    } while(chk != 2 || a == b);
    
    if (b < a) {
        Aux = a;
        a = b;
        b = Aux;
    }
    fprintf(fi, "El intervalo es [%.2f, %.2f]\n", a, b);

        
	do{
	    printf("Introduce la semilla -> ");
	    chk = scanf("%i", &Semilla);
	    while(getchar() != '\n');
    } while(chk != 1);  
        
    fprintf(fi, "La semilla es %i \n", Semilla);
    //srand ( time(NULL) );
    srand ( Semilla );    
    
    for (cont = 0; cont < N; cont++){
    	numero = (double)rand()/RAND_MAX;
    	numero  = numero * (b-a) +  a;
    	
        Vec[cont] = numero; // rand() % (b - a + 1) + a
    }
    
    
	fprintf(fi, "El vector introducido es: \n\n");
	for(cont = 0; cont < N; cont++){
		fprintf(fi, "V[%i] = %lf; ", cont+1, Vec[cont]);
	}
	fprintf(fi, "\n\n");
	
	
	fclose(fi);
	return 0;
	
}
