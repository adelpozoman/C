#include<stdio.h>
#include<math.h>
# include<stdlib.h>
# include<time.h>

void VecAlea(FILE *, int, double *);

int main(void)
{
	int N;
	int cont, chk;
	
	
	FILE *fi;
	
	fi = fopen("Salida.dat", "w");
	
	do{
		printf("Introduce la dimensión del vector (N > 1) -> ");
		chk = scanf("%i", &N);
		while(getchar() != '\n');
	}while(chk != 1 || N < 2);
	
// ***** Dimensionamiento variable	

    double Vec[N];	
    
// ****** Inicialización ****
	for(cont = 0; cont < N; cont++){
		Vec[cont] = 0.;
	}
	
// **** Generación de Números aleatorios *****	
	VecAlea(fi, N, Vec); 
	
// **** Salida del vector ****	
	fprintf(fi, "El vector introducido es: \n\n");
	for(cont = 0; cont < N; cont++){
		fprintf(fi, "V[%i] = %lf; ", cont+1, Vec[cont]);
	}
	fprintf(fi, "\n\n");
	
	
	
	fclose(fi);
	return 0;		
}

void VecAlea(FILE *fo, int DIM, double *V){
	
	float a, b;
	int chk;
	double Aux, numero;
	int Semilla;
	int cont;
	
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
    fprintf(fo, "El intervalo es [%.2f, %.2f]\n", a, b);

        
	do{
	    printf("Introduce la semilla -> ");
	    chk = scanf("%i", &Semilla);
	    while(getchar() != '\n');
    } while(chk != 1);  
        
    fprintf(fo, "La semilla es %i \n", Semilla);
    //srand ( time(NULL) );
    srand ( Semilla );    
    
    for (cont = 0; cont < DIM; cont++){
    	numero = (double)rand()/RAND_MAX;
    	numero  = numero * (b-a) +  a;
    	
        V[cont] = numero; // rand() % (b - a + 1) + a
    }
	
	return;	
	
	
	
}


