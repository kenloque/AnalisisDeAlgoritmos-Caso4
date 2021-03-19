list<int> crearImagen(int pAncho, int pAlto){
	int inicioX, inicioY;
	inicioX = 0;
	inicioY = 0;
	list<int> listaLineas; //Se puede crear una clase punto para agrupar 2 ints o una linea para agrupar 4
	for(int contImagen = 0 ; contImagen < N ; contImagen++){
		int distX = pAncho-inicioX;
		int distY = pAlto-inicioY;
		int reduccionX = (distX*4)/100;
		int reduccionY = (distY*4)/100;
		//Figura principal
		listaLineas.insert(inicioX); #Punto 1 Linea 1
		listaLineas.insert(inicioY); #Punto 1 Linea 1
		listaLineas.insert(inicioX); #Punto 2 Linea 1
		listaLineas.insert(pAlto); #Punto 2 Linea 1
		listaLineas.insert(inicioX); #Punto 1 Linea 2
		listaLineas.insert(pAlto); #Punto 1 Linea 2
		listaLineas.insert(pAncho); #Punto 2 Linea 2
		listaLineas.insert(pAlto); #Punto 2 Linea 2
		listaLineas.insert(inicioX); #Punto 1 Linea 3
		listaLineas.insert(inicioY); #Punto 1 Linea 3
		listaLineas.insert(pAncho); #Punto 2 Linea 3
		listaLineas.insert(inicioY); #Punto 2 Linea 3
		listaLineas.insert(pAncho); #Punto 1 Linea 4
		listaLineas.insert(inicioY); #Punto 1 Linea 4
		listaLineas.insert(pAncho); #Punto 2 Linea 4
		listaLineas.insert(pAlto); #Punto 2 Linea 4
		//Figura secundaria
		int auxInicioX = inicioX + reduccionX;
		int auxInicioY = inicioY + reduccionY;
		int auxAncho = pAncho - reduccionX;
		int auxAlto = pAlto - reduccionY;
		listaLineas.insert(inicioX); #Punto 1 Linea 1
		listaLineas.insert(auxInicioY); #Punto 1 Linea 1
		listaLineas.insert(auxInicioX); #Punto 2 Linea 1
		listaLineas.insert(pAlto); #Punto 2 Linea 1
		listaLineas.insert(auxInicioX); #Punto 1 Linea 2
		listaLineas.insert(pAlto); #Punto 1 Linea 2
		listaLineas.insert(pAncho); #Punto 2 Linea 2
		listaLineas.insert(auxAlto); #Punto 2 Linea 2
		listaLineas.insert(inicioX); #Punto 1 Linea 3
		listaLineas.insert(auxInicioY); #Punto 1 Linea 3
		listaLineas.insert(auxAncho); #Punto 2 Linea 3
		listaLineas.insert(inicioY); #Punto 2 Linea 3
		listaLineas.insert(auxAncho); #Punto 1 Linea 4
		listaLineas.insert(inicioY); #Punto 1 Linea 4
		listaLineas.insert(pAncho); #Punto 2 Linea 4
		listaLineas.insert(auxAlto); #Punto 2 Linea 4
		//Lineas de relleno
	
		//Ajuste de medidas finales
		inicioX = auxInicioX;
		inicioY = auxInicioY;
		pAncho = auxAncho;
		pAlto = auxAlto;
	}
	return listaLineas;
}

int main(){
	
	return 0;
}