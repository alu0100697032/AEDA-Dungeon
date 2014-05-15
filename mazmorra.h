//Fichero mazmorra.h
#include <fstream>
#include <stdlib.h>     
#include <time.h>  
#include <iostream>
using namespace std;

//clase mazmorra

class mazmorra{
	
	private:
 		int f_; //filas
		int c_; //columnas
		char pared, puerta, pasillo, p_a, monstruo, amuleto, hero; //elementos de la mazmorra
	public:
		mazmorra(int f, int c); 
		~mazmorra();
		void mostrarmazmorra(char** a); //muestra mazmorra
		void ubicarhero(int i, int j, char** a); //ubica prota
		void ubicarmonstruo(int i, int j, char** a); //ubica monstruos
		
};

//clase hero (protagonista)

class hero{
	
	private:
		int posf_;
		int posc_;
		int vidas_;
		bool amul_;
		bool pasillo_;
		bool p_a_;
	public:
		hero(int i, int j);
		~hero();
		void cambiarposicion(char** tab);
		int posc(); //Devuelve la posicion de la columna
		int posf(); //Devuelve la posicion de la fila
		int getvidas();
		void decrementarvidas(char** a);
		bool achieved(); //Amuleto encontrado
		bool pasillo(); //Estas en pasillo
		bool enhab(); //Estas en habitación
		bool getamul(); //Estado del amuleto: encontrado o no
		bool p_a(); //Indica que el prota se encuentra en el punto de acceso con el amuleto
		bool getp_a(); //Devuelve el estado del punto de acceso
};

//clase mounstro

class monster{
	
	private:
		int posf_;
		int posc_;	
	public:
		monster(int i, int j);
		~monster();
		int posf();
		int posc();
		void changepos(char** a); //cambia la posición del monstruo
					
};
