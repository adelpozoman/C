
		f++;
	}while(f<filas);
//ahora hay que hacer las cuentas
//voy a gaurdar los encontrados en el array doble silla, la primera columna es la fila en la que esta y las segunda columna la columna en la q esta nuestro punto (en la matriz inicial)
//si es maximo en la columna es maximo en su fila de la traspuesta, ahorra un monton de cuentas y funciones
	int m2[columnas][filas];
	llenam2(filas, columnas, m1, m2);//m2=&m2[0][0]
//encontrados es el numero de puntos silla encontrado
	int encontrados;
	int silla[f*c];
	encontrados=0;
	f=0;
	do{	c=0;
		do{
			if(1==puntosilla(filas, columnas,f,c,m1,m2)){
				silla[encontrados]=m1[f][c];
				encontrados++;}
			c++;
		}while(c<columnas);
		f++;
	}while(f<filas);
	printf("He encontrado %i puntos de silla, los cuales son (en fila y columna):\n",encontrados);
	int gazpacho=0;
	while(gazpacho<encontrados){
		printf("Pto.%i--x:%i\n",gazpacho+1,silla[gazpacho]);
		gazpacho++;}
	puts("");
	puts("");
}return EXIT_SUCCESS;}

void llenam2(int filas, int columnas, int (*m1)[columnas], int (*m2)[filas]){
	int cuenta1, cuenta2=0;
	do{	cuenta1=0;
		do{
			
			*(m2[cuenta2]+cuenta1)=*(m1[cuenta1]+cuenta2);
			cuenta1++;
		}while(cuenta1<filas);
		
		cuenta2++;
	}while(cuenta2<columnas);
}

int puntosilla(int filas, int columnas, int f, int c, int (*m1)[columnas], int (*m2[filas])){
	if(min(filas, columnas,f,c,m1)&&max(columnas,filas,c,f,m2)){
		printf("M1.seguro que he encontrado 1, en fila %i columna %i\n",f,c);
		return 1;}
//lo q se mete en max es lo q hay q arreglar
//en la segunda funcion hay q meter la traspuesta y ver si es maximo en su fila de la traspuesta
	else if(max(filas, columnas,f,c,m1)&&min(columnas,filas,c,f,m2)){
		printf("M2.seguro que he encontrado 1, en fila %i columna %i\n",f,c);
		return 1;}
//aqui en min se mete la traspuesta
	return 0;}
//punto de silla comprueba si nuestro numero es maximo o minimo en su fila y si es minimo o maximo en su fila de la traspuesta


int min(int filas, int columnas, int f, int c, int (*m1)[columnas]){
	int minimo=*(m1[0]+f);
	int contador=1;
	do{
		if((*(m1[contador]+f))<minimo){
			minimo=(*(m1[contador]+f));
			}
		contador++;
	}while(contador<columnas);
	if(minimo==(*(m1[c]+f)))return 1;
	//es minimo, vamos adecirselo, q compruebe si es maximo en la column
	return 0;}

int max(int filas, int columnas, int f, int c, int (*m1)[columnas]){
	int maximo=*(m1[0]+f);
	int contador=1;
	do{
		if((*(m1[contador]+f))>maximo){
			maximo=(*(m1[contador]+f));
			}
		contador++;
	}while(contador<columnas);
	if(maximo==*(m1[c]+f))return 1;
	//es maximo, se lo desimos, q compruebe si es minimo en la columna
	return 0;}
