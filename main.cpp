//#include "mazmorra.cpp" 
#include "mazmorra.cpp"

/*********Funcion principal**********/

int main(){
	
	srand (time(NULL));
	int start;
	int nivel;
	cout<< "Bienvenido. Antes de empezar a jugar deberá elegir una de las dos mazmorras disponibles.\n";
	cout<< "-----------------------------------\n";
	while(nivel != 1 && nivel != 2){
		cout<<"Pulse 1 o 2 para elegir una u otra mazmorra.\n";
		cin >> nivel;
	}	
	switch(nivel){
		case 1:
		{
			//mazmorra desde fichero
			char** tablero_;
			int f = 26;
			int c = 32;
			//leer mazmorra
			ifstream entrada("Mazmorra_30_30.dat");
			cout<< "Se ha creado la mazmorra a partir del fichero Mazmorra_30_30.dat.\n";
			tablero_ = new char*[f];
			for(int i = 0; i < f ; i++)
				tablero_[i] = new char[c];
			
			char a[c];

			for (int i = 0; i < f; i++){
				entrada.getline(a , c+ 2);
				for (int j = 0; j < c; j++){
					tablero_[i][j] = a[j];
					cout << tablero_[i][j]; 
				}	
				cout << endl;	
				
			}	
			entrada.close();
			
			//mazmorra creada desde fichero
			
			/****Creación de objetos****/
			
			hero prota(3,4);
			mazmorra M(f,c);
			monster m11(3,7);
			monster m12(7,6);
			monster m13(9,5);
			monster m21(3,16);
			monster m22(1,20);
			monster m23(2,25);
			monster m31(18,8);
			monster m32(20,15);
			monster m33(22,22);
			
			M.ubicarhero(3,4,tablero_);
			//monstruos habitacion 1 columnas 4-8, filas 3-9 
			M.ubicarmonstruo(3,7,tablero_);
			M.ubicarmonstruo(7,6,tablero_);
			M.ubicarmonstruo(9,5,tablero_);
			//monstruos habitacion 2 columnas 16-26, filas 1-4
			M.ubicarmonstruo(3,16,tablero_);
			M.ubicarmonstruo(1,20,tablero_);
			M.ubicarmonstruo(2,25,tablero_);
			//monstruos habitacion 3 columnas 7-23, filas 16-23
			M.ubicarmonstruo(18,8,tablero_);
			M.ubicarmonstruo(20,15,tablero_);
			M.ubicarmonstruo(22,22,tablero_);
			
			cout<< "-----------------------------------\n";
			while(start != 1 && start != 2){
				cout<<"Pulsa 1 para comenzar la partida o pulsa 2 para salir del juego:\n";
				cin >> start;
			}	
			
			switch(start){
				case 1:{
					for(int i = 0; i < f; i++){
						for(int j = 0; j < c; j++)
							cout<< tablero_[i][j];	
						cout<< endl;
					}
					cout<< endl;
					cout<< "ESTADO DEL PERSONAJE:\n";
					cout<< "---------------------\n";
					cout<< "| Número de vidas: " << prota.getvidas() << "|" << endl;
					cout<< "| Amuletos: " << prota.getamul() << "       |"<< endl;
					cout<< "---------------------\n";
					cout<< endl;
						//borrar símbolos de monstruos iniciales
					tablero_[3][7] = ' ';
					tablero_[7][6] = ' ';
					tablero_[9][5] = ' ';
					tablero_[3][16] = ' ';
					tablero_[1][20] = ' ';
					tablero_[2][25] = ' ';
					tablero_[18][8] = ' ';
					tablero_[20][15] = ' ';
					tablero_[22][22] = ' ';
			
					while(prota.getp_a() == false && prota.getvidas() != 0){ 
							prota.cambiarposicion(tablero_);
							if (tablero_[3][4] == ' ')
								tablero_[3][4] = 'X';
							m11.changepos(tablero_);
							m12.changepos(tablero_);
							m13.changepos(tablero_);
							m21.changepos(tablero_);
							m22.changepos(tablero_);
							m23.changepos(tablero_);
							m31.changepos(tablero_);
							m32.changepos(tablero_);
							m33.changepos(tablero_);
							M.mostrarmazmorra(tablero_);
							prota.decrementarvidas(tablero_);
							cout<< endl;
							cout<< "ESTADO DEL PERSONAJE:\n";
							cout<< "---------------------\n";
							cout<< "| Número de vidas: " << prota.getvidas() << "|" << endl;
							cout<< "| Amuletos: " << prota.getamul() << "       |"<< endl;
							cout<< "---------------------\n";
							cout<< endl;
						}//fin while
				}	
					break;
				case 2:{
					cout<<"El juego ha terminado.\n";
				}
					break;
			}//fin switch de comenzar partida
		}//case 1: mazmorra desde fichero
			break;
		case 2:
		{
			int fil = 17;
			int col = 20;
			char** tab;
			tab = new char*[fil];
			for(int i = 0; i < fil ; i++)
				tab[i] = new char[col];
			//inicializar
			for(int i = 0; i < fil; i++){
				for(int j = 0; j < col; j++)
					tab[i][j] = '.';	
				
			}
			//primera habitacion	
			for(int i = 0; i < 7; i++){
				for(int j = 0; j < 7; j++){
					if(i==6||i==0||j==0||j==6){
						tab[i][j] = '*';	
					}else{
						tab[i][j] = ' ';	
					}		
				}	
			}
			//pasillo de hab1 a hab 2
			for(int i = 0; i < 7; i++){
				for(int j = 7; j < 13; j++){
					if(i==2){
						tab[i][j] = '#';	
					}else{
						tab[i][j] = ' ';	
					}		
				}	
			}
			//segunda habitacion
			for(int i = 0; i < 7; i++){
				for(int j = 13; j < 20; j++){
					if(i==6||i==0||j==13||j==19){
						tab[i][j] = '*';	
					}else{
						tab[i][j] = ' ';	
					}		
				}	
			}
			//pasillo hab 2 a hab 3
			for(int i = 7; i < 10; i++){
				for(int j = 13; j < 20; j++){
					if(j==16){
						tab[i][j] = '#';	
					}else{
						tab[i][j] = ' ';	
					}		
				}	
			}
			
			//tercera habitacion
			
			for(int i = 10; i < 17; i++){
				for(int j = 0; j < 20; j++){
					if(i==16||i==10||j==0||j==19){
						tab[i][j] = '*';	
					}else{
						tab[i][j] = ' ';	
					}		
				}	
			}
			//pasillo hab 3 a hab 1
			
			for(int i = 7; i < 10; i++){
				for(int j = 0; j < 13; j++){
					if(j==3){
						tab[i][j] = '#';	
					}else{
						tab[i][j] = ' ';	
					}		
				}	
			}
			//puertas 
			tab[6][3] = '+';
			tab[6][16] = '+';	
			tab[2][13] = '+';
			tab[2][6] = '+';
			tab[10][3] = '+';
			tab[10][16] = '+';
			//amuleto
			tab[15][10] = '&';
			//punto de acceso
			tab[1][1] = 'X';
			for(int i = 0; i < fil; i++){
				for(int j = 0; j < col; j++)
					cout<< tab[i][j];	
				cout<< endl;
			}
			
			/****Creación de objetos****/
			
			hero H(1,1);
			mazmorra Maz(fil,col);
			monster M11(3,3);
			monster M12(5,3);
			monster M13(1,5);
			monster M21(5,14);
			monster M22(1,16);
			monster M23(2,17);
			monster M31(15,15);
			monster M32(13,10);
			monster M33(11,5);
			
			Maz.ubicarhero(1,1,tab);
			//monstruos habitacion 1 columnas 1-5, filas 1-5 
			Maz.ubicarmonstruo(3,3,tab);
			Maz.ubicarmonstruo(5,3,tab);
			Maz.ubicarmonstruo(1,5,tab);
			//monstruos habitacion 2 columnas 14-19, filas 1-5
			Maz.ubicarmonstruo(5,14,tab);
			Maz.ubicarmonstruo(1,16,tab);
			Maz.ubicarmonstruo(2,17,tab);
			//monstruos habitacion 3 columnas 1-19, filas 11-15
			Maz.ubicarmonstruo(15,15,tab);
			Maz.ubicarmonstruo(13,10,tab);
			Maz.ubicarmonstruo(11,5,tab);
			
			cout<< "-----------------------------------\n";
			while(start != 1 && start != 2){
				cout<<"Pulsa 1 para comenzar la partida o pulsa 2 para salir del juego:\n";
				cin >> start;
			}	
			switch(start){
				case 1:{
					for(int i = 0; i < fil; i++){
						for(int j = 0; j < col; j++)
							cout<< tab[i][j];	
						cout<< endl;
					}
					cout<< endl;
					cout<< "ESTADO DEL PERSONAJE:\n";
					cout<< "---------------------\n";
					cout<< "| Número de vidas: " << H.getvidas() << "|" << endl;
					cout<< "| Amuletos: " << H.getamul() << "       |" << endl;
					cout<< "---------------------\n";
					cout<< endl;
						//borrar símbolos de monstruos iniciales
					tab[3][3] = ' ';
					tab[5][3] = ' ';
					tab[1][5] = ' ';
					tab[5][14] = ' ';
					tab[1][16] = ' ';
					tab[2][17] = ' ';
					//tab[15]15] = ' ';
					tab[13][10] = ' ';
					tab[11][5] = ' ';
			
					while(H.getp_a() == false && H.getvidas() != 0){ 
							H.cambiarposicion(tab);
							if (tab[1][1] == ' ')
								tab[1][1] = 'X';
							M11.changepos(tab);
							M12.changepos(tab);
							M13.changepos(tab);
							M21.changepos(tab);
							M22.changepos(tab);
							M23.changepos(tab);
							M31.changepos(tab);
							M32.changepos(tab);
							M33.changepos(tab);
							Maz.mostrarmazmorra(tab);
							H.decrementarvidas(tab);
							cout<< endl;
							cout<< "ESTADO DEL PERSONAJE:\n";
							cout<< "---------------------\n";
							cout<< "| Número de vidas: " << H.getvidas() << "|" << endl;
							cout<< "| Amuletos: " << H.getamul() << "       |" << endl;
							cout<< "---------------------\n";
							cout<< endl;
						}//fin while
				}	
					break;
				case 2:{
					cout<<"El juego ha terminado.\n";
				}
					break;
			}//fin switch de comenzar partida
			
		}//case 2: mazmorra predeterminada	
			break;
	}//fin switch de eleccion de mazmorra		
	return 0;		
}		
