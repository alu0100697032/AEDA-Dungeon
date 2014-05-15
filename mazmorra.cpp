//fichero mazmorra.cpp
#include "mazmorra.h"

/**********************************/
/**Funciones de la clase mazmorra**/
/**********************************/

/**CONSTRUCTOR DE LA MAZMORRA**/

mazmorra::mazmorra(int f, int c){
	
	f_ = f;
	c_ = c;
	pared = '*';
	puerta = '+';
	pasillo = '#';
	p_a = 'X';
	monstruo = 'O';
	amuleto = '&';
	hero = '@';		
	
}

/*****Destructor******/

mazmorra::~mazmorra(){
	
	f_ = 0;
	c_ = 0;	
	
}

/**Colocar elementos dentro de la mazmorra**/


//i, j deben ser iguales en esta funcion y en el constructor de la clase hero

void mazmorra::ubicarhero(int i, int j, char** a){
	
	a[i][j] = hero;	
}

//i, j deben ser iguales en esta funcion y en el constructor de la clase moster

void mazmorra::ubicarmonstruo(int i, int j, char** a){
	
	a[i][j] = monstruo;	
}


/******************************************/

void mazmorra::mostrarmazmorra(char** a){
	
	for(int i = 0; i < f_; i++){
		for(int j = 0; j < c_; j++)
			cout<< a[i][j];	
		cout<< endl;
	}

}

/*******************************/
/**Funciones de la clase hero **/
/*******************************/

/**Constructor**/

//i, j deben ser iguales en este constructor y en la funcion ubicarhero(i,j) de la clase mazmorra

hero::hero(int i, int j){
	
	posf_ = i;
	posc_ = j;
	vidas_ = 5;
	amul_ = false;	
	pasillo_ = false;
	p_a_ = false;
	
}

/*****Destructor*****/

hero::~hero(){
	
	posf_ = 0;
	posc_ = 0;
	vidas_ = 0;
	amul_ = false;	
	pasillo_ = false;
	p_a_ = false;	
	
}

void hero::decrementarvidas(char** a){ 
	
	if(a[posf_+1][posc_] == 'O'||a[posf_][posc_+1] == 'O'||a[posf_+1][posc_+1] == 'O'
	||a[posf_-1][posc_] == 'O'||a[posf_][posc_-1] == 'O'||a[posf_-1][posc_-1] == 'O'||
	a[posf_+1][posc_-1] == 'O'||a[posf_-1][posc_+1] == 'O'){
		vidas_ = vidas_ -1;		
		cout<< "¡Has perdido 1 vida! \n";
	}
	if(vidas_ == 0){
		cout<< endl;
		cout<< "*****************************************************\n";
		cout<< "* El juego ha terminado. ¡Te has quedado sin vidas! *\n";	
		cout<< "*****************************************************\n";	
	}	
		
}

int hero::getvidas(){
	
	return vidas_;
	
}

int hero::posf(){
	
	return posf_;
	
}

int hero::posc(){
	
	return posc_;
	
}

/******Para indicar cuando el amuleto es encontrado y el punto de acceso cuando el protagonista porta el amuleto*****/

bool hero::achieved(){
	
	amul_ = true;
	return amul_;	
}

bool hero::p_a(){
	
	p_a_ = true;
	return p_a_;	
	
}

/***************************/

bool hero::getp_a(){
	
	return p_a_;	
	
}

/********Estado del amuleto*******/

bool hero::getamul(){
	
	return amul_;
		
}


/*****Permiten indicar donde se encuentra el persobaje: habitacion o pasillo****/

bool hero::pasillo(){
	
	pasillo_ = true;	
	return pasillo_;
}

bool hero::enhab(){
	
	pasillo_ = false;	
	return pasillo_;
}

/****Permite mover al personaje por la mazmorra*****/


void hero::cambiarposicion(char** tab){ 
	
		char orden;
		cout<< "*--------------------------------*\n";
		cout << "|Pulsa: I para ir hacia arriba.  |\n";
		cout << "|Pulsa: K para ir hacia abajo.   |\n";
		cout << "|Pulsa: J para ir a la izquierda.|\n";
		cout << "|Pulsa: L para ir a la derecha.  |\n";
		cout<< "*--------------------------------*\n";
		cout<< "Tu selección: ";
		cin >> orden;	
		cout<< endl;
		/*************Switch que permite mover al personaje*****************/
		
		switch(orden)
		{
			case 'i': case 'I': //mover arriba
			{
				if (tab[posf_-1][posc_] == '*') //si se encuentra una pared, no permitir el paso
					cout << "¡No se puede avanzar, hay una pared!" << endl;
				else if(tab[posf_-1][posc_] == '+' && tab[posf_-2][posc_] == '#'){ // si se encuentra una puerta, permitir entrar.
					tab[posf_][posc_] = ' ';
					posf_ = posf_-2;
					tab[posf_][posc_] = '@';	
					pasillo();	
				}else if(tab[posf_-1][posc_] == '+' && tab[posf_-2][posc_] == ' '){ //si se encuentra en un pasillo y encuentra una puerta permitir entrar a la habitacion
					tab[posf_][posc_] = '#';
					posf_ = posf_-2;
					tab[posf_][posc_] = '@';
					enhab();
				}else if(tab[posf_-1][posc_] == '#'){ //si se encuentra pasillo permitir continuar
					tab[posf_][posc_] = '#';
					posf_ = posf_-1;
					tab[posf_][posc_] = '@';
				}else if(tab[posf_-1][posc_] == '&'){ //si se encuentra el amuleto, tomarlo 
					tab[posf_][posc_] = ' ';
					posf_ = posf_-1;
					tab[posf_][posc_] = '@';
					achieved();						  //invocar a la funcion achieved() para indicar que el amuleto es encontrado
					cout<< "¡Amuleto encontrado! Ahora llévalo al punto de acceso. \n";
				//}else if(tab[hero.posf-1][hero.posc] == "X"){	
				}else if(tab[posf_-1][posc_] == 'O') //si se encuentra mounstruo denegar el paso
					cout<< "¡Retrocede, ahí hay un mounstro! \n";
				else if(tab[posf_-1][posc_] == ' ' && pasillo_ == true){
					cout<< "¡No se puede avanzar, hay una pared! \n";
				}else if(tab[posf_-1][posc_] == 'X' && amul_ == true){	
					p_a();
					cout<< "¡Has ganado, felicidades! \n";
				}else if (tab[posf_-1][posc_] == 'X' && amul_ == false){
					tab[posf_][posc_] = ' ';
					posf_ = posf_-1;
					tab[posf_][posc_] = '@';												
				}else if(tab[posf_-1][posc_] == ' '){ //si se encuentra habitacion...
					tab[posf_][posc_] = ' ';
					posf_ = posf_-1;
					tab[posf_][posc_] = '@';
				}
			}						
				break;
			case 'k': case 'K': //mover abajo
				{
				if (tab[posf_+1][posc_] == '*') //si se encuentra una pared, no permitir el paso
					cout << "¡No se puede avanzar, hay una pared!" << endl;
				else if(tab[posf_+1][posc_] == '+' && tab[posf_+2][posc_] == '#'){ // si se encuentra una puerta, permitir entrar.
					tab[posf_][posc_] = ' ';
					posf_ = posf_+2;
					tab[posf_][posc_] = '@';
					pasillo();		
				}else if(tab[posf_+1][posc_] == '+' && tab[posf_+2][posc_] == ' '){ //si se encuentra en un pasillo y encuentra una puerta permitir entrar a la habitacion
					tab[posf_][posc_] = '#';
					posf_ = posf_+2;
					tab[posf_][posc_] = '@';
					enhab();
				}else if(tab[posf_+1][posc_] == '#'){ //si se encuentra pasillo permitir continuar
					tab[posf_][posc_] = '#';
					posf_ = posf_+1;
					tab[posf_][posc_] = '@';
				}else if(tab[posf_+1][posc_] == '&'){ //si se encuentra el amuleto, tomarlo 
					tab[posf_][posc_] = ' ';
					posf_ = posf_+1;
					tab[posf_][posc_] = '@';
					achieved();						  //invocar a la funcion achieved() para indicar que el amuleto es encontrado
					cout<< "¡Amuleto encontrado! Ahora llévalo al punto de acceso. \n";
				//}else if(tab[hero.posf-1][hero.posc] == "X"){	
				}else if(tab[posf_+1][posc_] == 'O') //si se encuentra mounstruo denegar el paso
					cout<< "¡Retrocede, ahí hay un mounstro! \n";
				else if(tab[posf_+1][posc_] == ' ' && pasillo_ == true)
					cout<< "¡No se puede avanzar, hay una pared! \n";		
				else if(tab[posf_+1][posc_] == 'X' && amul_ == true){	
					p_a();
					cout<< "¡Has ganado, felicidades! \n";
				}else if (tab[posf_+1][posc_] == 'X' && amul_ == false){
					tab[posf_][posc_] = ' ';
					posf_ = posf_+1;
					tab[posf_][posc_] = '@';										
				}else if(tab[posf_+1][posc_] == ' '){	 		  //si se encuentra habitacion poder moverse	
					tab[posf_][posc_] = ' ';
					posf_ = posf_+1;
					tab[posf_][posc_] = '@';
				}
			}						
				break;
			case 'j': case 'J': //mover izquierda
			{
				if (tab[posf_][posc_] == '*') //si se encuentra una pared, no permitir el paso
					cout << "¡No se puede avanzar, hay una pared!" << endl;
				else if(tab[posf_][posc_-1] == '+' && tab[posf_][posc_-2] == '#'){ // si se encuentra una puerta, permitir entrar.
					tab[posf_][posc_] = ' ';
					posc_ = posc_-2;
					tab[posf_][posc_] = '@';
					pasillo();		
				}else if(tab[posf_][posc_-1] == '+' && tab[posf_][posc_-2] == ' '){ //si se encuentra en un pasillo y encuentra una puerta permitir entrar a la habitacion
					tab[posf_][posc_] = '#';
					posc_ = posc_-2;
					tab[posf_][posc_] = '@';
					enhab();
				}else if(tab[posf_][posc_-1] == '#'){ //si se encuentra pasillo permitir continuar
					tab[posf_][posc_] = '#';
					posc_ = posc_-1;
					tab[posf_][posc_] = '@';
				}else if(tab[posf_][posc_-1] == '&'){ //si se encuentra el amuleto, tomarlo 
					tab[posf_][posc_] = ' ';
					posc_ = posc_-1;
					tab[posf_][posc_] = '@';
					achieved();						  //invocar a la funcion achieved() para indicar que el amuleto es encontrado
					cout<< "¡Amuleto encontrado! Ahora llévalo al punto de acceso. \n";
				//}else if(tab[hero.posf-1][hero.posc] == "X"){	
				}else if(tab[posf_][posc_-1] == 'O') //si se encuentra mounstruo denegar el paso
					cout<< "¡Retrocede, ahí hay un mounstro! \n";	
				else if(tab[posf_][posc_-1] == ' ' && pasillo_ == true)
					cout<< "¡No se puede avanzar, hay una pared! \n";	
				else if(tab[posf_][posc_-1] == 'X' && amul_ == true){	
					p_a();
					cout<< "¡Has ganado, felicidades! \n";
				}else if (tab[posf_][posc_-1] == 'X' && amul_ == false){
					tab[posf_][posc_] = ' ';
					posc_ = posc_-1;
					tab[posf_][posc_] = '@';									
				}else if(tab[posf_][posc_-1] == ' '){	 	 //si se encuentra habitacion poder moverse	
					tab[posf_][posc_] = ' ';
					posc_ = posc_-1;
					tab[posf_][posc_] = '@';
				}
			}						
				break;
			case 'l': case 'L':  //mover derecha
				{
				if (tab[posf_][posc_] == '*') //si se encuentra una pared, no permitir el paso
					cout << "¡No se puede avanzar, hay una pared!" << endl;
				else if(tab[posf_][posc_+1] == '+' && tab[posf_][posc_+2] == '#'){ // si se encuentra una puerta, permitir entrar.
					tab[posf_][posc_] = ' ';
					posc_ = posc_+2;
					tab[posf_][posc_] = '@';
					pasillo();		
				}else if(tab[posf_][posc_+1] == '+' && tab[posf_][posc_+2] == ' '){ //si se encuentra en un pasillo y encuentra una puerta permitir entrar a la habitacion
					tab[posf_][posc_] = '#';
					posc_ = posc_+2;
					tab[posf_][posc_] = '@';
					enhab();
				}else if(tab[posf_][posc_+1] == '#'){ //si se encuentra pasillo permitir continuar
					tab[posf_][posc_] = '#';
					posc_ = posc_+1;
					tab[posf_][posc_] = '@';
				}else if(tab[posf_][posc_+1] == '&'){ //si se encuentra el amuleto, tomarlo 
					tab[posf_][posc_] = ' ';
					posc_ = posc_+1;
					tab[posf_][posc_] = '@';
					achieved();						  //invocar a la funcion achieved() para indicar que el amuleto es encontrado
					cout<< "¡Amuleto encontrado! Ahora llévalo al punto de acceso. \n";
				//}else if(tab[hero.posf-1][hero.posc] == "X"){	
				}else if(tab[posf_][posc_+1] == 'O') //si se encuentra mounstruo denegar el paso
					cout<< "¡Retrocede, ahí hay un mounstro! \n";	
				else if(tab[posf_][posc_+1] == ' ' && pasillo_ == true)
					cout<< "¡No se puede avanzar, hay una pared! \n";	
				else if(tab[posf_][posc_+1] == 'X' && amul_ == true){	
					p_a();
					cout<< "¡Has ganado! \n";
				}else if (tab[posf_][posc_+1] == 'X' && amul_ == false){
					tab[posf_][posc_] = ' ';
					posc_ = posc_+1;
					tab[posf_][posc_] = '@';										
				}else if(tab[posf_][posc_+1] == ' '){	   //si se encuentra habitacion poder moverse	
					tab[posf_][posc_] = ' ';
					posc_ = posc_+1;
					tab[posf_][posc_] = '@';
				}
			}						
				break;
			default: cout<< "¡¡¡Comando incorrecto!!! Introduzca uno de los propuestos:" << endl;
				break;
		}//fin switch
		
		/*************Mostrar la mazmorra****************/
		
	
}

/**********************************/
/**Funciones de la clase monster**/
/**********************************/

/**constructor**/

//i, j deben ser iguales en este constructor y en la funcion ubicarmonstruo(i,j) de la clase mazmorra

monster::monster(int i, int j){
	
	posf_ = i;
	posc_ = j;	
	
}

/*****Destructor****/
monster::~monster(){
	
	posf_ = 0;
	posc_ = 0;	

}

int monster::posf(){
		
	return posf_;
	
}

int monster::posc(){
	
	return posc_;
	
}

/*********movimiento de los monstruos**************/
/**************************************************/
/**************************************************/
/**************************************************/

void monster::changepos(char** a){
	
	int n_rand = 0;		

	n_rand = rand() % 4 + 0; //gererar nuemro aleatorio del 0 al 3, 0 = arriba, 1 = abajo, 2 = izquierda, 3 = derecha
	
	switch(n_rand)
		{
			case 0: 
			{
				if(a[posf_-1][posc_] == ' '){ //si encuentra espacio: moverse
					a[posf_][posc_] = ' ';
					posf_ = posf_-1;
					a[posf_][posc_] = 'O';
				}else 						 //si no: quedarse en el mismo lugar	
					a[posf_][posc_] = 'O';
			}						
				break;
			case 1:
				{
				if(a[posf_+1][posc_] == ' '){ 
					a[posf_][posc_] = ' ';
					posf_ = posf_+1;
					a[posf_][posc_] = 'O';
				}else
					a[posf_][posc_] = 'O';
			}						
				break;
			case 2: 
			{
				if (a[posf_][posc_-1] == ' '){ 
					a[posf_][posc_] = ' ';
					posc_ = posc_-1;
					a[posf_][posc_] = 'O';
				}else
					a[posf_][posc_] = 'O';
			}						
				break;
			case 3:
			{
				if (a[posf_][posc_+1] == ' '){
					a[posf_][posc_] = ' ';
					posc_ = posc_+1;
					a[posf_][posc_] = 'O';
				}else
					a[posf_][posc_] = 'O';
			}						
				break;
		}//fin switch
	n_rand = 0;	
	
}


