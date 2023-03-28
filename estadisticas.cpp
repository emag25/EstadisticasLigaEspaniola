#include <conio.h>    // Permite utilizar getch();
#include <stdio.h>    // Para imprimir cadenas de textos: gets() y printf(). Tambien puts()
#include <iostream>   // Para imprimir y guardar datos [cout, cin]
#include <stdlib.h>   // Permite darle color al fondo y al texto del programa [system("color##")]. Tambien para limpiar pantalla [system("cls")]
#include <windows.h>  // Permite cambiarle el titulo a la ventana [setconsoletitle("nombredelprograma")]
#include <string.h>   // Se uso en todo lo que se necesitaba en cadena de texto [strcpy = para copiar ; strcmp = para comparar]
#include <locale.h>   // Imprime palabras con ñ y vocales acentuadas del idioma español [setlocale(LC_ALL,"spanish");]

using namespace std;

/*---Declaracion de variables globales--------------------------------------------------------------------*/
bool repita=false;
char club[30],tempo[30]; 
char tempc[30];
int tecla,tam;

/*---Prototipo de Funciones-----------------------------------------------------------------------------*/
void escudo_barcelona();
void escudo_rcdespanyol();
void escudo_alaves();
void escudo_realmadrid();
void escudo_atleticoM();
void escudo_sevilla();
void escudo_realsociedad();
void escudo_valencia();
void escudo_getafe();
void escudo_bilbao();
void escudo_villarreal();
void escudo_granada();
void escudo_levante();
void escudo_osasuna();
void escudo_realbetis();
void escudo_realvalladolid();
void escudo_eibar();
void escudo_celtadevigo();
void escudo_rcdmallorca();
void escudo_leganes();	
void escudos (int e);
void gotoxy(int x,int y);
void color_txt(int colorf, int colort);
void base_datos();
void salir();
void cuadro_menu();
void menu();
void cuadro_encabezado();
void encabezado();
void consultar();
void cuadro_mostrar();
void buscar_mostrar();
void conexion();

/*---Declaracion de estructuras o de registros------------------------------------------------------------*/
struct equipo
{
	char nombre[30];
	char p1[30];
	char p2[30];
	char p3[30];
	char opo1[30];
	char opo2[30];
	char opo3[30];
	char maxgol[30];
	char maxasis[30];
	int gf;
	int gc;
};

/*---Adicional-------------------------------------------------------------------------------------------*/
	struct equipo datos[20];       /*Declaracion de una arreglo de estructuras de manera global*/

/*---Inicio del programa----------------------------------------------------------------------------------*/
main()
{

/*Imprime palabras con ñ y vocales acentuadas del idioma español.*/
setlocale(LC_ALL,"spanish");

/* le da un titulo a la ventana de la consola */
SetConsoleTitle("ESTADISTICAS DE LA SELECCION DE FUTBOL ESPANOLA");

	menu();	
	base_datos();
	buscar_mostrar();
}
	
void gotoxy(int x,int y)
{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  

void color_txt(int colorf, int colort)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorf*16+colort); 
}

void salir()
{
	system("cls");
	system("color 0f");
	cout<<"Presione cualquier tecla para salir.";
	getch();
	exit(1);
}

void cuadro_menu()
{
	system("color 0F");
	color_txt(12,12);
	gotoxy(3,1);  cout<<"__________________________________________________________________________________________________________________"; // linea superior
	gotoxy(3,28); cout<<"__________________________________________________________________________________________________________________"; // linea inferior
	
	for (int i=2;i<28;i++)
	{	
		gotoxy(3,i); cout<<"||";   // linea izquierda 
		gotoxy(115,i); cout<<"||";  // linea derecha 
	}
	//***************************************************************************************************//
	color_txt(9,9);
	gotoxy(80,8);  cout<<"--------------------------------";   // linea superior
    gotoxy(80,20);  cout<<"--------------------------------";  // linea inferior

	for (int i=9;i<20;i++)
	{	
		gotoxy(80,i); cout<<"||";   // linea izquierda bienvenida
		gotoxy(110,i); cout<<"||";  // linea derecha bienvenida
	}
	color_txt(0,11);
	gotoxy(82,13);  cout<<"****************************";  // linea medio
}			

void menu()
{
	system("cls");
	cuadro_menu();
	
	color_txt(0,15);
	gotoxy(35,9);  cout<< "##        ##    ";
	gotoxy(35,10); cout<< "##       ####   ";
	gotoxy(35,11); cout<< "##      ##  ##  ";
	gotoxy(35,12); cout<< "##     ######## ";
	gotoxy(35,13); cout<< "###### ##    ## ";

	gotoxy(28,15); cout<< "##     ###### ######    ##    ";
	gotoxy(28,16); cout<< "##       ##   ##       ####   ";
	gotoxy(28,17); cout<< "##       ##   ## ###  ##  ##  ";
	gotoxy(28,18); cout<< "##       ##   ##  ## ######## ";
	gotoxy(28,19); cout<< "###### ###### ###### ##    ## ";	
	
	int i=8; int j=15; int k=15;    // VARIABLES PARA ASIGNARLE COLOR ITERADAS VECES
	for(int a=1;a<3;a++)
	{
		for(int c=1;c<7;c++)
		{
			i++;
			Sleep(11);
			color_txt(0,i);  // DERECHA ARRIBA
			gotoxy(55,5);  cout<< "    ____________ ";
			gotoxy(55,6);  cout<< "   /###########/  ";
			gotoxy(55,7);  cout<< "  /###########/  ";
			gotoxy(55,8);  cout<< " /###########/  ";
			gotoxy(55,9); cout<< "/###########/ ";
			gotoxy(55,10); cout<< ".-*******-./";
			
			Sleep(11);
			color_txt(0,i);  // IZQUIERDA ARRIBA
			gotoxy(14,5);  cout<< "    ____________ ";
			gotoxy(14,6);  cout<< "   /###########/  ";
			gotoxy(14,7);  cout<< "  /###########/  ";
			gotoxy(14,8);  cout<< " /###########/  ";
			gotoxy(14,9); cout<< "/###########/ ";
			gotoxy(14,10); cout<< ".-*******-./";	
			
			if (c==5) continue;
			j--;
			Sleep(11);
			color_txt(0,j);	 // CENTRO                                
			gotoxy(36,2); cout<< "    ____________ ";
			gotoxy(36,3); cout<< "   /###########/  ";                   
			gotoxy(36,4); cout<< "  /###########/  ";          
			gotoxy(36,5); cout<< " /###########/  ";
			gotoxy(36,6); cout<< "/###########/ ";
			gotoxy(36,7); cout<< ".-*******-./";

			Sleep(11);
			color_txt(0,j); // ABAJO IZQUIERDA
			gotoxy(22,21);  cout<< "    ____________ ";
			gotoxy(22,22);  cout<< "   /###########/  ";
			gotoxy(22,23);  cout<< "  /###########/  ";
			gotoxy(22,24);  cout<< " /###########/  ";
			gotoxy(22,25); cout<< "/###########/ ";
			gotoxy(22,26); cout<< ".-*******-./";
			
			Sleep(11);
			color_txt(0,j);  // ABAJO DERECHA
			gotoxy(48,21);  cout<< "    ____________ ";
			gotoxy(48,22);  cout<< "   /###########/  ";
			gotoxy(48,23);  cout<< "  /###########/  ";
			gotoxy(48,24);  cout<< " /###########/  ";
			gotoxy(48,25); cout<< "/###########/ ";
			gotoxy(48,26); cout<< ".-*******-./";
			
			if (c==4) continue;
			k--;
			Sleep(11);
			color_txt(0,k);  // DERECHA ABAJO
			gotoxy(61,13);  cout<< "    ____________ ";
			gotoxy(61,14);  cout<< "   /###########/  ";
			gotoxy(61,15);  cout<< "  /###########/  ";
			gotoxy(61,16);  cout<< " /###########/  ";
			gotoxy(61,17); cout<< "/###########/ ";
			gotoxy(61,18); cout<< ".-*******-./";
			
			Sleep(11);
			color_txt(0,k);  // IZQUIERDA ABAJO
			gotoxy(7,13);  cout<< "    ____________ ";
			gotoxy(7,14);  cout<< "   /###########/  ";
			gotoxy(7,15);  cout<< "  /###########/  ";
			gotoxy(7,16);  cout<< " /###########/  ";
			gotoxy(7,17); cout<< "/###########/ ";
			gotoxy(7,18); cout<< ".-*******-./";
		
		}
		i=8; j=15; k=15;
	} 
	do
	{
		color_txt(0,15);
		gotoxy(88,11);  cout << "¡¡ BIENVENIDO !!";
		color_txt(0,15);
		gotoxy(84,15);  cout << "* PARA CONSULAR PRESIONA ";
		gotoxy(84,16);  cout << "  LA TECLA TAB";
		gotoxy(84,17);  cout << "* PARA SALIR PRESIONA ";
		gotoxy(84,18);  cout << "  LA TECLA ESC";	
		tecla=getch();
	}while(tecla!=9&&tecla!=27);
	if(tecla==27)
	{
		salir();
	}				
}

void cuadro_encabezado()
{
	color_txt(12,12);
	gotoxy(3,1);  cout<<"__________________________________________________________________________________________________________________"; // linea superior
	gotoxy(3,28); cout<<"__________________________________________________________________________________________________________________";	

	color_txt(9,9);
	for (int i=2;i<28;i++)
	{	
		gotoxy(3,i); cout<<"||";   // linea izquierda 
		gotoxy(115,i); cout<<"||";  // linea derecha 
	}

	//***************************************************************************************************//
	color_txt(0,11);
	gotoxy(5,8);  cout<<"______________________________________________________________________________________________________________"; // linea consultar
	gotoxy(5,9); cout<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";	
	gotoxy(5,23);  cout<<"__________________________________________________________"; // linea consultar
	gotoxy(5,24); cout<<"<><><><><><><><><><><><><><><><><><><><><><><><><><><><><>";
	gotoxy(63,23);  cout<<"____________________________________________________"; // linea consultar
	gotoxy(65,24); cout<<"<><><><><><><><><><><><><><><><><><><><><><><><><>";
	gotoxy(63,24); cout<<"<>";
	for (int i=10;i<24;i++)
	{	
		gotoxy(61,i); cout<<"||";   // linea izquierda de indicaciones
	}	 
}

void encabezado()
{	system("cls");
	color_txt(0,10);
	gotoxy(29,3); cout<<"######   #######   ##    ##  ######  ######   ######   ###### ";
	gotoxy(29,4); cout<<"##      ##     ##  ##    ##    ##    ##  ##  ##    ##  ##     ";
	gotoxy(29,5); cout<<"####    ##     ##  ##    ##    ##    ######  ##    ##  ###### ";
	gotoxy(29,6); cout<<"##      ##   ####  ##    ##    ##    ##      ##    ##      ## ";
	gotoxy(29,7); cout<<"######   #######    ######   ######  ##       ######   ###### ";

	color_txt(0,15);
	gotoxy(8,12); cout<<"1.- BARCELONA";          gotoxy(37,12);  cout<<"11.- VILLARREAL";
	gotoxy(8,13); cout<<"2.- RCD ESPANYOL";       gotoxy(37,13);  cout<<"12.- GRANADA";
	gotoxy(8,14); cout<<"3.- ALAVES";             gotoxy(37,14);  cout<<"13.- LEVANTE";
	gotoxy(8,15); cout<<"4.- REAL MADRID CF";     gotoxy(37,15);  cout<<"14.- OSASUNA";
	gotoxy(8,16); cout<<"5.- ATLETICO DE MADRID"; gotoxy(37,16); cout<<"15.- REAL BETIS";
	gotoxy(8,17); cout<<"6.- SEVILLA";            gotoxy(37,17); cout<<"16.- REAL VALLADOLID";
	gotoxy(8,18); cout<<"7.- REAL SOCIEDAD";      gotoxy(37,18); cout<<"17.- EIBAR";
	gotoxy(8,19); cout<<"8.- VALENCIA CF";        gotoxy(37,19); cout<<"18.- CELTA DE VIGO";
	gotoxy(8,20); cout<<"9.- GETAFE";             gotoxy(37,20); cout<<"19.- RCD MALLORCA";
	gotoxy(8,21); cout<<"10.- ATHLETIC BILBAO";   gotoxy(37,21); cout<<"20.- LEGANES";	
	gotoxy(80,11); cout<<"** INDICACIONES **";   
	gotoxy(67,13); cout<<"a) Para mostrar las estadísticas, debe";
	gotoxy(67,14); cout<<"escribir correctamente el nombre del equipo.";	
	gotoxy(67,16); cout<<"b) Si ha ingresado de manera incorrecta el";
	gotoxy(67,17); cout<<"nombre del equipo, debe volver a ingresarlo.";	
	gotoxy(67,19); cout<<"c) Evite dejar espacios o digitar caracteres";
	gotoxy(67,20); cout<<"especiales antes y/o después de escribir el";
	gotoxy(67,21); cout<<"el nombre del equipo.";		
	cuadro_encabezado();
	do
	{
		color_txt(0,10);
		gotoxy(38,26);  cout<<"Ingrese el equipo a consultar: ";
		gotoxy(69,26);gets(club);tam=strlen(club);		
	}while(tam==0);
	strupr(club);
}

void base_datos()
{
/*-----------------------------------------Tabla de datos------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------*/
/*01.-*/strcpy(datos[0].nombre,"BARCELONA");          strcpy(datos[0].p1,"EMPATADO"); strcpy(datos[0].p2,"GANADO");   strcpy(datos[0].p3,"EMPATADO"); strcpy(datos[0].maxgol,"LIONEL MESSI");     strcpy(datos[0].maxasis,"LUIS SUAREZ");      datos[0].gf=49; datos[0].gc=23;    strcpy(datos[0].opo1,"RCD ESPANYOL");        strcpy(datos[0].opo2,"ALALVES");             strcpy(datos[0].opo3,"REAL MADRID"); 
/*02.-*/strcpy(datos[1].nombre,"RCD ESPANYOL");       strcpy(datos[1].p1,"EMPATADO"); strcpy(datos[1].p2,"PERDIDO");  strcpy(datos[1].p3,"EMPATADO"); strcpy(datos[1].maxgol,"JONATHAN CALLERI"); strcpy(datos[1].maxasis,"MATIAS VARGAS");    datos[1].gf=14; datos[1].gc=36;    strcpy(datos[1].opo1,"BARCELONA");           strcpy(datos[1].opo2,"LEGANES");             strcpy(datos[1].opo3,"REAL BETIS");
/*03.-*/strcpy(datos[2].nombre,"ALAVES");             strcpy(datos[2].p1,"EMPATADO"); strcpy(datos[2].p2,"PERDIDO");  strcpy(datos[2].p3,"EMPATADO"); strcpy(datos[2].maxgol,"LUCAS PEREZ");      strcpy(datos[2].maxasis,"ALEIX VIDAL");      datos[2].gf=20; datos[2].gc=19;	  strcpy(datos[2].opo1,"REAL BETIS");          strcpy(datos[2].opo2,"BARCELONA");           strcpy(datos[2].opo3,"LEGANES");
/*04.-*/strcpy(datos[3].nombre,"REAL MADRID CF");     strcpy(datos[3].p1,"GANADO");   strcpy(datos[3].p2,"EMPATADO"); strcpy(datos[3].p3,"EMPATADO"); strcpy(datos[3].maxgol,"KARIM BENZEMA");    strcpy(datos[3].maxasis,"KARIM BENZEMA");    datos[3].gf=36; datos[3].gc=12;    strcpy(datos[3].opo1,"GETAFE");              strcpy(datos[3].opo2,"ATHLETIC BILBAO");     strcpy(datos[3].opo3,"BARCELONA");
/*05.-*/strcpy(datos[4].nombre,"ATLETICO DE MADRID"); strcpy(datos[4].p1,"GANADO");   strcpy(datos[4].p2,"GANADO");   strcpy(datos[4].p3,"EMPATADO"); strcpy(datos[4].maxgol,"ALVARO MORATA");    strcpy(datos[4].maxasis,"ANGEL CORREA");     datos[4].gf=22; datos[4].gc=12;    strcpy(datos[4].opo1,"LEVANTE");             strcpy(datos[4].opo2,"REAL BETIS");          strcpy(datos[4].opo3,"VILLARREAL");
/*06.-*/strcpy(datos[5].nombre,"SEVILLA");            strcpy(datos[5].p1,"EMPATADO"); strcpy(datos[5].p2,"GANADO");   strcpy(datos[5].p3,"PERDIDO");  strcpy(datos[5].maxgol,"OCAMPO");           strcpy(datos[5].maxasis,"EVER BANEGA");      datos[5].gf=24; datos[5].gc=18;    strcpy(datos[5].opo1,"ATHLETIC BILBAO");     strcpy(datos[5].opo2,"RCD MALLORCA");        strcpy(datos[5].opo3,"VILLARREAL"); 
/*07.-*/strcpy(datos[6].nombre,"REAL SOCIEDAD");	  strcpy(datos[6].p1,"PERDIDO");  strcpy(datos[6].p2,"GANADO");   strcpy(datos[6].p3,"EMPATADO"); strcpy(datos[6].maxgol,"WILLIAM JOSE");     strcpy(datos[6].maxasis,"MARTIN ODEGAARD");  datos[6].gf=32; datos[6].gc=25;    strcpy(datos[6].opo1,"VILLARREAL");          strcpy(datos[6].opo2,"OSASUNA");             strcpy(datos[6].opo3,"BARCELONA"); 
/*08.-*/strcpy(datos[7].nombre,"VALENCIA CF");        strcpy(datos[7].p1,"GANADO");   strcpy(datos[7].p2,"EMPATADO"); strcpy(datos[7].p3,"EMPATADO"); strcpy(datos[7].maxgol,"MAXI GOMEZ");       strcpy(datos[7].maxasis,"RODRIGO");          datos[7].gf=29; datos[7].gc=25;    strcpy(datos[7].opo1,"EIBAR");               strcpy(datos[7].opo2,"VALLADOLID");          strcpy(datos[7].opo3,"VALENCIA C.F."); 
/*09.-*/strcpy(datos[8].nombre,"GETAFE");             strcpy(datos[8].p1,"PERDIDO");  strcpy(datos[8].p2,"PERDIDO");  strcpy(datos[8].p3,"GANADO");   strcpy(datos[8].maxgol,"ANGEL");            strcpy(datos[8].maxasis,"JASON");            datos[8].gf=26; datos[8].gc=20;    strcpy(datos[8].opo1,"REAL MADRID");         strcpy(datos[8].opo2,"VILLARREAL");          strcpy(datos[8].opo3,"REAL VALLADOLID"); 
/*10.-*/strcpy(datos[9].nombre,"ATHLETIC BILBAO");    strcpy(datos[9].p1,"EMPATADO"); strcpy(datos[9].p2,"EMPATADO"); strcpy(datos[9].p3,"EMPATADO"); strcpy(datos[9].maxgol,"RAUL GARCIA");      strcpy(datos[9].maxasis,"CAPA");             datos[9].gf=20; datos[9].gc=13;    strcpy(datos[9].opo1,"SEVILLA");             strcpy(datos[9].opo2,"REAL MADRID");         strcpy(datos[9].opo3,"EIBAR"); 
/*11.-*/strcpy(datos[10].nombre,"VILLARREAL");        strcpy(datos[10].p1,"GANADO");  strcpy(datos[10].p2,"GANADO");  strcpy(datos[10].p3,"GANADO");  strcpy(datos[10].maxgol,"GERARD");          strcpy(datos[10].maxasis,"SANTI CAZORLA");   datos[10].gf=33;datos[10].gc=26;   strcpy(datos[10].opo1,"REAL SOCIEDAD");       strcpy(datos[10].opo2,"GETAFE");              strcpy(datos[10].opo3,"SEVILLA"); 
/*12.-*/strcpy(datos[11].nombre,"GRANADA");           strcpy(datos[11].p1,"GANADO");  strcpy(datos[11].p2,"PERDIDO"); strcpy(datos[11].p3,"PERDIDO"); strcpy(datos[11].maxgol,"ANTONIO PUERTAS"); strcpy(datos[11].maxasis,"SOLDADO");         datos[11].gf=25;datos[11].gc=25;   strcpy(datos[11].opo1,"RCD MALLORCA");        strcpy(datos[11].opo2,"EIBAR");               strcpy(datos[11].opo3,"LEVANTE"); 
/*13.-*/strcpy(datos[12].nombre,"LEVANTE");           strcpy(datos[12].p1,"PERDIDO"); strcpy(datos[12].p2,"GANADO");  strcpy(datos[12].p3,"GANADO");  strcpy(datos[12].maxgol,"ROGER");           strcpy(datos[12].maxasis,"CAMPAÑA");         datos[12].gf=26;datos[12].gc=29;   strcpy(datos[12].opo1,"ATLETICO DE MADRID");  strcpy(datos[12].opo2,"CELTA DE VIGO");       strcpy(datos[12].opo3,"GRANADA"); 
/*14.-*/strcpy(datos[13].nombre,"OSASUNA");           strcpy(datos[13].p1,"EMPATADO");strcpy(datos[13].p2,"PERDIDO"); strcpy(datos[13].p3,"PERDIDO"); strcpy(datos[13].maxgol,"ROBERTO TORRES");  strcpy(datos[13].maxasis,"PERVIS ESTUPIÑAN");datos[13].gf=26;datos[13].gc=25;   strcpy(datos[13].opo1,"CELTA DE VIGO");       strcpy(datos[13].opo2,"REAL SOCIEDAD");       strcpy(datos[13].opo3,"ATLETICO DE MADRID"); 
/*15.-*/strcpy(datos[14].nombre,"REAL BETIS");	 	  strcpy(datos[14].p1,"EMPATADO");strcpy(datos[14].p2,"PERDIDO"); strcpy(datos[14].p3,"EMPATADO");strcpy(datos[14].maxgol,"LOREN MORON");     strcpy(datos[14].maxasis,"ALEX MORENO");     datos[14].gf=26;datos[14].gc=32;   strcpy(datos[14].opo1,"ALAVES");              strcpy(datos[14].opo2,"ATLETICO DE MADRID");  strcpy(datos[14].opo3,"RCD ESPANYOL"); 
/*16.-*/strcpy(datos[15].nombre,"REAL VALLADOLID");	  strcpy(datos[15].p1,"EMPATADO");strcpy(datos[15].p2,"EMPATADO");strcpy(datos[15].p3,"PERDIDO"); strcpy(datos[15].maxgol,"SERGI GUARDIOLA"); strcpy(datos[15].maxasis,"OSCAR PLANO");     datos[15].gf=17;datos[15].gc=23;   strcpy(datos[15].opo1,"LEGANES");             strcpy(datos[15].opo2,"VALENCIA CF");         strcpy(datos[15].opo3,"GETAFE"); 
/*17.-*/strcpy(datos[16].nombre,"EIBAR");             strcpy(datos[16].p1,"PERDIDO"); strcpy(datos[16].p2,"GANADO");  strcpy(datos[16].p3,"EMPATADO");strcpy(datos[16].maxgol,"ORELLANA");        strcpy(datos[16].maxasis,"DE BLASIS");       datos[16].gf=18;datos[16].gc=29;   strcpy(datos[16].opo1,"VALENCIA CF");         strcpy(datos[16].opo2,"GETAFE");               strcpy(datos[16].opo3,"ATHLETIC BILBAO"); 
/*18.-*/strcpy(datos[17].nombre,"CELTA DE VIGO");     strcpy(datos[17].p1,"EMPATADO");strcpy(datos[17].p2,"PERDIDO"); strcpy(datos[17].p3,"EMPATADO");strcpy(datos[17].maxgol,"IAGO ASPAS");      strcpy(datos[17].maxasis,"OLAZA");           datos[17].gf=16;datos[17].gc=29;   strcpy(datos[17].opo1,"OSASUNA");             strcpy(datos[17].opo2,"LEVANTE");             strcpy(datos[17].opo3,"RCD MALLORCA"); 
/*19.-*/strcpy(datos[18].nombre,"RCD MALLORCA");      strcpy(datos[18].p1,"PERDIDO"); strcpy(datos[18].p2,"PERDIDO"); strcpy(datos[18].p3,"PERDIDO"); strcpy(datos[18].maxgol,"BUDIMIR");         strcpy(datos[18].maxasis,"FEBAS");           datos[18].gf=18;datos[18].gc=33;   strcpy(datos[18].opo1,"GRANADA");             strcpy(datos[18].opo2,"SEVILLA");             strcpy(datos[18].opo3,"CELTA DE VIGO"); 
/*20.-*/strcpy(datos[19].nombre,"LEGANES");           strcpy(datos[19].p1,"EMPATADO");strcpy(datos[19].p2,"GANADO");  strcpy(datos[19].p3,"EMPATADO");strcpy(datos[19].maxgol,"BRAITHWAITE");     strcpy(datos[19].maxasis,"K. RODRIGUES");    datos[19].gf=16;datos[19].gc=30;   strcpy(datos[19].opo1,"REAL VALLADOLID");     strcpy(datos[19].opo2,"RCD ESPANYOL");        strcpy(datos[19].opo3,"ALAVES"); 
/*--------------------------------------------------------------------------------------------------------*/
}

void cuadro_mostrar()
{
	system("color 0F");
	color_txt(9,9);
	gotoxy(15,1);  cout<<"________________________________________________________________________________________";
	gotoxy(17,28);  cout<<"_____________________________________________________________________________________";	
	for (int i=2;i<29;i++)
	{	
		gotoxy(15,i); cout<<"||";   
	}
	for (int i=1;i<29;i++)
	{	
		gotoxy(102,i); cout<<"||";   
	}
	gotoxy(47,5);  cout<<"_________________________________________________________";
	gotoxy(17,23); cout <<"_______________________________________________________________________________________";
	
	for (int i=2;i<24;i++)
	{	
		gotoxy(46,i); cout<<"||";   
	}
	color_txt(0,10);
	gotoxy(48,16);  cout<<"******************************************************";
	color_txt(0,10);
	gotoxy(4,1); cout<<"######   ";	gotoxy(4,7);  cout<<"###### ";	gotoxy(4,13);  cout<<"###### ";	gotoxy(3,19);  cout<<"##    ## ";
	gotoxy(4,2); cout<<"##   ##  ";	gotoxy(4,8);  cout<<"##     ";	gotoxy(4,14);  cout<<"##     ";	gotoxy(3,20);  cout<<"##    ## ";
	gotoxy(4,3); cout<<"######   ";	gotoxy(4,9);  cout<<"####   ";	gotoxy(4,15);  cout<<"###### ";	gotoxy(3,21);  cout<<"##    ## ";
	gotoxy(4,4); cout<<"##   ##  ";	gotoxy(4,10); cout<<"##     ";	gotoxy(4,16);  cout<<"    ## ";	gotoxy(3,22);  cout<<"##    ## ";
	gotoxy(4,5); cout<<"##   ##  ";	gotoxy(4,11); cout<<"###### ";	gotoxy(4,17);  cout<<"###### ";	gotoxy(3,23);  cout<<" ######  "; 
	
	gotoxy(4,25); cout<<"##     ";	gotoxy(109,1);  cout<<"###### ";
	gotoxy(4,26); cout<<"##     ";	gotoxy(109,2);  cout<<"  ##   ";
	gotoxy(4,27); cout<<"##     ";	gotoxy(109,3);  cout<<"  ##   ";
	gotoxy(4,28); cout<<"###### ";	gotoxy(109,4);  cout<<"  ##   ";

	gotoxy(108,6);  cout<<" ###### ";	gotoxy(108,12); cout<<"######   ";	gotoxy(108,18); cout<<" ######  ";	gotoxy(109,24);  cout<<"###### ";
	gotoxy(108,7);  cout<<"##    ##";	gotoxy(108,13); cout<<"##    ## ";	gotoxy(108,19); cout<<"##    ## ";	gotoxy(109,25);  cout<<"##     ";
	gotoxy(108,8);  cout<<"########";	gotoxy(108,14); cout<<"##    ## ";	gotoxy(108,20); cout<<"##    ## ";	gotoxy(109,26);  cout<<"###### ";
	gotoxy(108,9);  cout<<"##    ##";	gotoxy(108,15); cout<<"##    ## ";	gotoxy(108,21); cout<<"##    ## ";	gotoxy(109,27);  cout<<"    ## ";
	gotoxy(108,10); cout<<"##    ##";	gotoxy(108,16); cout<<"######   ";	gotoxy(108,22); cout<<" ######  ";	gotoxy(109,28);  cout<<"###### ";
}

void buscar_mostrar()
{
	do{
		encabezado();

		for(int i=0;i<20;i++)
		{
			strcpy(tempc,datos[i].nombre);	
			if(strcmp(tempc,club)==0)	
			{	
				system("cls");
				cuadro_mostrar();
				escudos(i);
				color_txt(0,15);
				gotoxy(57,3); cout <<"*  ULTIMOS 3 PARTIDOS DE "<<datos[i].nombre<<"   *";
				gotoxy(51,7); cout <<"* ULTIMO PARTIDO:";
				color_txt(0,11);
				gotoxy(51,8); cout <<" "<<datos[i].nombre<<" Vs "<<datos[i].opo1<<":\t\t "; gotoxy(84,8); cout <<datos[i].p1;
				color_txt(0,15);
				gotoxy(51,10); cout <<"* PENULTIMO PARTIDO: ";
				color_txt(0,11);
				gotoxy(51,11); cout <<" "<<datos[i].nombre<<" Vs "<<datos[i].opo2<<":\t\t "; gotoxy(84,11); cout <<datos[i].p2;
				color_txt(0,15);
				gotoxy(51,13); cout <<"* ANTEPENULTIMO PARTIDO: ";
				color_txt(0,11);
				gotoxy(51,14); cout <<" "<<datos[i].nombre<<" Vs "<<datos[i].opo3<<":\t\t "; gotoxy(84,14); cout <<datos[i].p3;
				
				color_txt(0,15); 
				gotoxy(51,18); cout <<"*  MAXIMO GOLEADOR   ";
				gotoxy(51,19); cout <<"*  MAXIMA ASISTENCIA ";
				gotoxy(51,20); cout <<"*  GOLES A FAVOR     ";	
				gotoxy(51,21); cout <<"*  GOLES EN CONTRA   ";   
				
				color_txt(0,11);
				gotoxy(84,18); cout<<datos[i].maxgol;  
				gotoxy(84,19); cout<<datos[i].maxasis;
				gotoxy(84,20); cout<<datos[i].gf;
				gotoxy(84,21); cout<<datos[i].gc;
				color_txt(0,15);
				do
				{
					gotoxy(47,25); cout <<"PARA CONSUTAR PRESIONA TAB";
					gotoxy(49,26); cout <<"PARA SALIR PRESIONA ESC";	
					tecla=getch();				
				}while(tecla!=9 && tecla!=27);
				switch (tecla)
				{
					case 9:
						repita=false;
					break;
					case 27:
						salir();
					break;
				}	
			}	
		}			
	}while(repita!=true);

												
}


//1.- funcion escudo de barcelona
void escudo_barcelona(){
	color_txt(0,12);
	for (int i=7;i<11;i++){	
		gotoxy(26,i); cout<<"####";  
	}
	for (int i=7;i<11;i++){
		gotoxy(33,i); cout<<"#";
	}
	for(int i=7;i<11;i++){
		gotoxy(35,i); cout<<"#";
	}
	for(int i=7;i<11;i++){
		gotoxy(37,i); cout<<"#";
	}
	for(int i=7;i<11;i++){
		gotoxy(39,i); cout<<"#";
	}
	
	gotoxy(24,8); printf("########");
	gotoxy(24,9); printf("########");
	
	for(int i=14;i<18;i++){
		gotoxy(25,i); cout<<"####";}

	for(int i=14;i<18;i++){
		gotoxy(34,i); cout<<"####";}



	color_txt(0,14);
	for (int i=7;i<11;i++){
		gotoxy(32,i); cout<<"#";
	}
	for(int i=7;i<11;i++){
		gotoxy(34,i); cout<<"#";
	}
	for(int i=7;i<11;i++){
		gotoxy(36,i); cout<<"#";
	}
	for(int i=7;i<11;i++){
		gotoxy(38,i); cout<<"#";
	}
	
	gotoxy(23,11); printf("##################");
	gotoxy(23,12); printf("##################");
	gotoxy(23,13); printf("##################");
	
	for (int i=7;i<16;i++){
		gotoxy(22,i); cout<<"|";
	}
	for(int i=7;i<11;i++){
		gotoxy(23,i); cout<<"$";
	}
	gotoxy(22,16); printf("%c+",92);
	gotoxy(23,17); printf("%c+",92);
	gotoxy(24,18); printf("%c+-+-",92);
	gotoxy(25,19); printf("    %c-v-/",92);
	gotoxy(34,18); printf("-+-+/");
	gotoxy(39,17); printf("/");
	gotoxy(39,16); printf("+/");
	gotoxy(40,15); printf("#");
	gotoxy(40,14); printf("#");	
	for (int i=7;i<16;i++){
		gotoxy(41,i); cout<<"|";
	}
	for(int i=7;i<11;i++){
		gotoxy(40,i); cout<<"$";
	}
	
	gotoxy(28,5); printf(".__/%c__.",92);
	gotoxy(22,6); printf(".----/########%c---.",92);
	
	gotoxy(21,12); printf("<|");
	gotoxy(41,12); printf("|>");


	color_txt(0,9);
	gotoxy(23,14); printf("##");
	gotoxy(23,15); printf("##");
	gotoxy(24,16); printf("#");
	gotoxy(24,17); printf("#");
	
	for(int i=14;i<19;i++){
		gotoxy(29,i); cout<<"#####";}
	
	gotoxy(38,14); printf("##");
	gotoxy(38,15); printf("##");
	gotoxy(38,16); printf("#");
	gotoxy(38,17); printf("#");
	
	color_txt(0,15);
	gotoxy(24,7); printf("##");
	gotoxy(24,10); printf("##");
	gotoxy(30,7); printf("##");
	gotoxy(30,10); printf("##");


}

//2.-funcion RCD ESPANYOL
void escudo_rcdespanyol(){
	color_txt(0,14); 
	gotoxy(31,3); printf("||",92);
	gotoxy(29,4); printf("||||||",92);
	gotoxy(31,5); printf("||",92);
	gotoxy(31,6); printf("C3",92);
	gotoxy(28,7); printf("********");
	gotoxy(26,8); printf("************");
	gotoxy(27,9); printf("**");
	gotoxy(31,9); printf("**");
	gotoxy(35,9); printf("**");
	gotoxy(28,10); printf("********");
		
	color_txt(0,12);
	gotoxy(28,8); printf("**");
	gotoxy(29,9); printf("**");
	gotoxy(33,9); printf("**");
	gotoxy(34,8); printf("**");
	
	color_txt(0,12);
	gotoxy(26,11); printf("************");
	gotoxy(25,12); printf("**************");
	gotoxy(23,13); printf("**");
	gotoxy(22,14); printf("**");
	gotoxy(21,15); printf("**");
	gotoxy(21,16); printf("**");
	gotoxy(22,17); printf("**");
	gotoxy(23,18); printf("**");
	gotoxy(25,19); printf("**************");
	gotoxy(26,20); printf("************");	
	gotoxy(38,13); printf("**");
	gotoxy(39,14); printf("**");
	gotoxy(40,15); printf("**");
	gotoxy(40,16); printf("**");
	gotoxy(39,17); printf("**");
	gotoxy(38,18); printf("**");
	
	color_txt(0,15); //blancos
	gotoxy(25,13); printf("###");
	gotoxy(24,14); printf("###");
	gotoxy(23,15); printf("###");
	gotoxy(23,16); printf("##");
	
	gotoxy(31,13); printf("##");
	gotoxy(30,14); printf("##");
	gotoxy(29,15); printf("##");
	gotoxy(28,16); printf("##");
	gotoxy(27,17); printf("##");
	gotoxy(26,18); printf("##");
	
	gotoxy(36,13); printf("##");
	gotoxy(35,14); printf("##");
	gotoxy(34,15); printf("##");
	gotoxy(33,16); printf("##");
	gotoxy(32,17); printf("##");
	gotoxy(31,18); printf("##");
	
	gotoxy(39,15); printf("#");
	gotoxy(38,16); printf("##");
	gotoxy(37,17); printf("##");
	gotoxy(36,18); printf("##");
	
	color_txt(0,11); //CELESTES
	gotoxy(28,13); printf("###");
	gotoxy(27,14); printf("###");
	gotoxy(26,15); printf("###");
	gotoxy(25,16); printf("###");
	gotoxy(24,17); printf("###");
	gotoxy(25,18); printf("#");
	
	gotoxy(33,13); printf("###");
	gotoxy(32,14); printf("###");
	gotoxy(31,15); printf("###");
	gotoxy(30,16); printf("###");
	gotoxy(29,17); printf("###");
	gotoxy(28,18); printf("###");
	
	gotoxy(37,14); printf("##");
	gotoxy(36,15); printf("###");
	gotoxy(35,16); printf("###");
	gotoxy(34,17); printf("###");
	gotoxy(33,18); printf("###");
}

//3.- funcion escudo de alaves
void escudo_alaves(){
	color_txt(0,11);
	for (int i=5;i<15;i++)
	{	
		gotoxy(18,i); cout<<"|x|";  
	}
	color_txt(0,11);
	gotoxy(21,5); printf("$$$%c",92);
	gotoxy(25,6); printf("$$$$%c",92);
	gotoxy(29,7); printf("$$$$%c",92);
	gotoxy(35,8); printf("$$$$%c",92);
	gotoxy(40,9); printf("$$$$%c",92);
	
	gotoxy(21,8); printf("____");
	gotoxy(24,7); printf("|");
	gotoxy(24,8); printf("|");

	for (int i=21;i<44;i++){	
		gotoxy(i,9); cout<<"#";  
	}

	gotoxy(21,14); printf("$$$/");
	gotoxy(25,13); printf("$$$$/");
	gotoxy(29,12); printf("$$$$/");
	gotoxy(35,11); printf("$$$$/");
	gotoxy(40,10); printf("$$$$/");
	gotoxy(21,7); printf("D A");
	
	for (int i=21;i<44;i++){	
	gotoxy(i,10); cout<<"#";  
	}
	
	color_txt(0,15);
	gotoxy(21,6); printf("$$$$");
	gotoxy(25,7); printf("$$$$");
	gotoxy(25,8); printf("$$$$$$$$$$");
	gotoxy(21,11); printf("$$$$$$$$$$$$$$");
	gotoxy(21,12); printf("$$$$$$$$$$");
	gotoxy(21,13); printf("$$$$");
	
	gotoxy(26,16); printf("|ALAVES|");
	gotoxy(21,17); printf("|FUNDADO EN 1921|");

}

//4.-funcion escudo de real madrid
void escudo_realmadrid(){
	color_txt(0,14); 
	gotoxy(31,3); printf("||",92);
	gotoxy(29,4); printf("||||||",92);
	gotoxy(31,5); printf("||",92);
	gotoxy(28,6); printf("+######+");
	gotoxy(27,7); printf("#");
	gotoxy(36,7); printf("#");
	gotoxy(36,8); printf("#");
	gotoxy(27,8); printf("#");
	gotoxy(28,9); printf("+######+");
	
	gotoxy(30,7); printf("#");
	gotoxy(30,8); printf("#");
	gotoxy(33,7); printf("#");
	gotoxy(33,8); printf("#");
	
	gotoxy(26,10); printf("************");
	gotoxy(25,11); printf("**************");
	gotoxy(24,12); printf("**");
	gotoxy(23,13); printf("**");
	gotoxy(22,14); printf("**");
	gotoxy(22,15); printf("**");
	gotoxy(23,16); printf("**");
	gotoxy(24,17); printf("**");
	gotoxy(25,18); printf("**************");
	gotoxy(26,19); printf("************");	
	gotoxy(38,12); printf("**");
	gotoxy(39,13); printf("**");
	gotoxy(40,14); printf("**");
	gotoxy(40,15); printf("**");
	gotoxy(39,16); printf("**");
	gotoxy(38,17); printf("**");
	
	color_txt(0,12);
	gotoxy(28,7); printf("##");
	gotoxy(28,8); printf("##");
	gotoxy(31,7); printf("##");
	gotoxy(31,8); printf("##");
	gotoxy(34,7); printf("##");
	gotoxy(34,8); printf("##");
	
	color_txt(0,15);
	gotoxy(26,17); printf("+++++++");
	gotoxy(26,16); printf("+++++++++++++");
	gotoxy(23,15); printf("+++++++++++++++++");
	gotoxy(23,14); printf("+++++++++++++++++");
	gotoxy(24,13); printf("+++++++++++++++");
	gotoxy(30,12); printf("++++++++");	
	
	color_txt(0,9);
	gotoxy(26,12); printf("#######");
	gotoxy(27,13); printf("#######");
	gotoxy(28,14); printf("#######");
	gotoxy(29,15); printf("#######");
	gotoxy(30,16); printf("#######");
	gotoxy(31,17); printf("#######");


}

//5.- funcion ATLETICO
void escudo_atleticoM(){
	color_txt(0,9);
	gotoxy(19,3); printf("_________________________");
	gotoxy(19,4); printf("|+_____________________+|");
	gotoxy(19,5); printf("| |                   | |");
	gotoxy(19,6); printf("| |                   | |");
	gotoxy(19,7); printf("| |                   | |");
	gotoxy(19,8); printf("|+|                   |+|");
	gotoxy(19,9); printf("| |                   | |");
	gotoxy(19,10); printf("| |                   | |");
	gotoxy(19,11); printf("|+|                   | |");
	gotoxy(19,12); printf("%c %c                   / /",92,92);
	gotoxy(20,13); printf("%c %c                 / /",92,92);
	gotoxy(21,14); printf("%c %c               / /",92,92);
	gotoxy(22,15); printf("%c %c             / /",92,92);
	gotoxy(23,16); printf("%c %c           / /",92,92);
	gotoxy(24,17); printf("%c %c         / /",92,92);
	gotoxy(25,18); printf("%c %c       / /",92,92);
	gotoxy(26,19); printf("%c %c     / /",92,92);
	gotoxy(27,20); printf("%c %c   / /",92,92);
	gotoxy(28,21); printf("%c %c / /",92,92);

	gotoxy(39,5); printf("//");
	gotoxy(37,6); printf("//");
	gotoxy(35,7); printf("//");
	gotoxy(33,8); printf("//");
	gotoxy(31,9); printf("//");
	gotoxy(29,10); printf("//");
	gotoxy(27,11); printf("//");
	gotoxy(25,12); printf("//");
	gotoxy(23,13); printf("//");
	
	gotoxy(25,7); printf("<0>");
	gotoxy(25,8); printf("| |");
	gotoxy(22,9); printf("___| |__");
	
	color_txt(0,12);
	for (int i=6;i<13;i++)
	{	
		gotoxy(39,i); cout<<"##";  
	}
	for (int i=8;i<17;i++)
	{	
		gotoxy(35,i); cout<<"##";  
	}
	for (int i=10;i<21;i++)
	{	
		gotoxy(31,i); cout<<"##";  
	}
	for (int i=12;i<18;i++)
	{	
		gotoxy(27,i); cout<<"##";  
	}
	
	gotoxy(39,13); printf("#");
	gotoxy(37,15); printf("#");
	gotoxy(35,17); printf("#");
	gotoxy(33,19); printf("#");

	gotoxy(24,14); printf("#");
	gotoxy(26,16); printf("#");
	gotoxy(28,18); printf("#");

	color_txt(0,15);
	for (int i=7;i<15;i++)
	{	
		gotoxy(37,i); cout<<"##";  
	}
	for (int i=9;i<19;i++)
	{	
		gotoxy(33,i); cout<<"##";  
	}
	for (int i=11;i<21;i++)
	{	
		gotoxy(29,i); cout<<"##";  
	}
	for (int i=13;i<16;i++)
	{	
		gotoxy(25,i); cout<<"##";  
	}
	gotoxy(22,5); printf("##################");
	gotoxy(22,6); printf("###############");
	gotoxy(22,7); printf("###");	
	gotoxy(28,7); printf("#######");
	gotoxy(22,8); printf("###");
	gotoxy(28,8); printf("#####");
	gotoxy(22,10); printf("#######");
	gotoxy(22,11); printf("#####");
	gotoxy(22,12); printf("###");

}

//6.-SEVILLA
void escudo_sevilla(){
	color_txt(0,14);
	gotoxy(21,3); printf("+.___  ___/%c___  ___.+",92);
	gotoxy(26,4); printf("''");
	gotoxy(36,4); printf("''");
	
	for(int i=4;i<6;i++){
		gotoxy(20,i); printf("%c|",92);}
	
	gotoxy(25,4); printf(".__.     .__.");
	gotoxy(23,5); printf(".-    --.--    -.");
	
	for(int i=6;i<10;i++){
		gotoxy(31,i); printf("|");
	}
		
	for(int i=6;i<8;i++){
		gotoxy(21,i); printf("%c|",92);}
	for(int i=8;i<10;i++){
		gotoxy(22,i); printf("%c|",92);}
	for(int i=10;i<12;i++){
		gotoxy(23,i); printf("%c|",92);}
	for(int i=12;i<14;i++){
		gotoxy(24,i); printf("%c|",92);}
	for(int i=14;i<16;i++){
		gotoxy(25,i); printf("%c|",92);}
	for(int i=16;i<18;i++){
		gotoxy(26,i); printf("%c|",92);}
	for(int i=18;i<20;i++){
		gotoxy(27,i); printf("%c|",92);}
	for(int i=20;i<22;i++){
		gotoxy(28,i); printf("%c|",92);}

	for(int i=4;i<6;i++){
		gotoxy(41,i); printf("|/");}
	for(int i=6;i<8;i++){
		gotoxy(40,i); printf("|/");}
	for(int i=8;i<10;i++){
		gotoxy(39,i); printf("|/");}
	for(int i=10;i<12;i++){
		gotoxy(38,i); printf("|/");}
	for(int i=12;i<14;i++){
		gotoxy(37,i); printf("|/");}
	for(int i=14;i<16;i++){
		gotoxy(36,i); printf("|/");}
	for(int i=16;i<18;i++){
		gotoxy(35,i); printf("|/");}
	for(int i=18;i<20;i++){
		gotoxy(34,i); printf("|/");}
	for(int i=20;i<22;i++){
		gotoxy(33,i); printf("|/");}
		
	gotoxy(25,10); printf("------0------");
	
	color_txt(0,12);
	for(int i=11;i<22;i++){
		gotoxy(30,i); printf("###");
	}
	gotoxy(25,11); printf("###");
	gotoxy(26,12); printf("##");
	gotoxy(26,13); printf("##");
	gotoxy(27,14); printf("#");
	gotoxy(27,15); printf("#");
	
	gotoxy(25,6); printf("****");
	gotoxy(26,7); printf("**");
	gotoxy(26,8); printf("**");
	gotoxy(25,9); printf("****");

	color_txt(0,15);
	for(int i=11;i<18;i++){
		gotoxy(28,i); printf("##");
	}
	gotoxy(29,18); printf("#");
	gotoxy(29,19); printf("#");
	for(int i=11;i<18;i++){
		gotoxy(33,i); printf("##");
	}
	gotoxy(33,18); printf("#");
	gotoxy(33,19); printf("#");
	gotoxy(35,11); printf("###");
	gotoxy(35,12); printf("##");
	gotoxy(35,13); printf("##");
	gotoxy(35,14); printf("#");
	gotoxy(35,15); printf("#");
	
	gotoxy(33,7); printf("SEVILLA");
	gotoxy(34,8); printf("C.F");
}

//7.-Real Sociedad.
void escudo_realsociedad(){
	color_txt(0,14); 
	gotoxy(31,3); printf("||",92);
	gotoxy(29,4); printf("||||||",92);
	gotoxy(31,5); printf("||",92);
	gotoxy(28,6); printf("+######+");
	gotoxy(27,7); printf("#");
	gotoxy(36,7); printf("#");
	gotoxy(36,8); printf("#");
	gotoxy(27,8); printf("#");
	gotoxy(28,9); printf("+######+");
	
	gotoxy(30,7); printf("#");
	gotoxy(30,8); printf("#");
	gotoxy(33,7); printf("#");
	gotoxy(33,8); printf("#");
	
	gotoxy(26,10); printf("************");
	gotoxy(24,11); printf("%c**************",92);
	gotoxy(24,12); printf("**");
	gotoxy(23,13); printf("**");
	gotoxy(22,14); printf("**");
	gotoxy(22,15); printf("**");
	gotoxy(23,16); printf("**");
	gotoxy(24,17); printf("**");
	gotoxy(25,18); printf("**************");
	gotoxy(26,19); printf("************");	
	gotoxy(38,12); printf("**");
	gotoxy(39,13); printf("**");
	gotoxy(40,14); printf("**");
	gotoxy(40,15); printf("**");
	gotoxy(39,16); printf("**");
	gotoxy(38,17); printf("**");
	
	gotoxy(23,10); printf("%c%c",92,92);
	gotoxy(22,9); printf("%c%c",92,92);
	gotoxy(21,8); printf("%c%c",92,92);
	gotoxy(20,7); printf("%c%c",92,92);
	
	gotoxy(34,20); printf("%c%c",92,92);
	gotoxy(35,21); printf("%c%c",92,92);
		
	color_txt(0,12);
	gotoxy(28,7); printf("##");
	gotoxy(28,8); printf("##");
	gotoxy(31,7); printf("##");
	gotoxy(31,8); printf("##");
	gotoxy(34,7); printf("##");
	gotoxy(34,8); printf("##");
	
	color_txt(0,6);
	gotoxy(26,12); printf("$$$  $$$  $$");
	gotoxy(25,13); printf("$$$  $$$  $$$");
	gotoxy(24,14); printf("$$$  $$$  $$$  $");
	gotoxy(24,15); printf("$$  $$$  $$$  $$");
	gotoxy(25,16); printf("  $$$  $$$  $$");
	gotoxy(26,17); printf("$$$  $$$  $$");

}

//8.-Valencia cf
void escudo_valencia(){
	color_txt(0,15);
	gotoxy(27,3); printf("/%c  W  /%c",92,92);
	gotoxy(26,4); printf("/--%cu_u/--%c",92,92);
	gotoxy(25,5); printf("/-----------%c",92);
	gotoxy(24,6); printf("/-------------%c",92);
	gotoxy(23,7); printf("/---------------%c",92);
	
	for(int i=8;i<14;i++){
		gotoxy(23,i); printf("|");
	}
	for(int i=8;i<14;i++){
		gotoxy(40,i); printf("|");
	}
	gotoxy(24,14); printf("%c-",92);
	gotoxy(25,15); printf("%c-",92);
	gotoxy(26,16); printf("%c-",92);
	gotoxy(27,17); printf("%c-",92);
	gotoxy(28,18); printf("%c-",92);
	gotoxy(29,19); printf("%c-",92);
	gotoxy(30,20); printf("%c-",92);
	
	gotoxy(38,14); printf("ñ/");
	gotoxy(37,15); printf("ñ/");
	gotoxy(36,16); printf("ñ/");
	gotoxy(35,17); printf("ñ/");
	gotoxy(34,18); printf("ñ/");
	gotoxy(33,19); printf("ñ/");
	gotoxy(32,20); printf("ñ/");

	color_txt(0,11);
	gotoxy(24,6); printf("-------------");
	gotoxy(25,7); printf(":VALENCIA CF:");
	
	color_txt(0,14);
	for(int i=8;i<14;i++){
		gotoxy(24,i); cout<<"##";}
	gotoxy(25,14); printf("#");
	for(int i=8;i<19;i++){
		gotoxy(29,i); cout<<"##";}
	gotoxy(30,19); cout<<"#";
	for(int i=8;i<19;i++){
		gotoxy(33,i); cout<<"##";}
	gotoxy(33,19); cout<<"#";
	for(int i=8;i<14;i++){
		gotoxy(38,i); cout<<"##";}
	gotoxy(38,14); printf("#");
		
	color_txt(0,12);
	for(int i=8;i<16;i++){
		gotoxy(26,i); cout<<"###";}
	gotoxy(27,16); printf("##");
	gotoxy(28,17); printf("#");

	for(int i=8;i<21;i++){
		gotoxy(31,i); cout<<"##";}
	gotoxy(35,16); printf("##");
	for(int i=8;i<16;i++){
		gotoxy(35,i); cout<<"###";}
	gotoxy(35,17); printf("#");
}

//9.-Getafe
void escudo_getafe(){
	color_txt(0,9);
	gotoxy(26,8); printf("************");
	gotoxy(25,9); printf("**************");
	gotoxy(23,10); printf("**");
	gotoxy(22,11); printf("**");
	gotoxy(21,12); printf("**");
	gotoxy(21,13); printf("**");
	gotoxy(22,14); printf("**");
	gotoxy(23,15); printf("**");
	gotoxy(25,16); printf("**************");
	gotoxy(26,17); printf("************");	
	gotoxy(38,10); printf("**");
	gotoxy(39,11); printf("**");
	gotoxy(40,12); printf("**");
	gotoxy(40,13); printf("**");
	gotoxy(39,14); printf("**");
	gotoxy(38,15); printf("**");
	
	color_txt(0,15);
	for(int i=10;i<15;i++){
		gotoxy(26,i); cout<<"|";
	}	
	for(int i=10;i<16;i++){
		gotoxy(31,i); cout<<"|";
	}
	gotoxy(27,15); printf("%c",92);
	
	for(int i=10;i<15;i++){
		gotoxy(37,i); printf("|");
	}
	for(int i=10;i<16;i++){
		gotoxy(32,i); printf("|");
	}
	gotoxy(36,15); printf("/");
	
	gotoxy(27,18); printf("G");
	gotoxy(28,18); printf("E");
	gotoxy(29,18); printf("T");
	gotoxy(30,18); printf("A");
	gotoxy(31,18); printf("F");
	gotoxy(32,18); printf("E");
	gotoxy(34,18); printf("F.");
	gotoxy(35,18); printf("C.");
	
	color_txt(0,14);
	for (int i=10;i<16;i++){
		gotoxy(28,i); printf("##");	
	gotoxy(27,11); printf("#");
	gotoxy(30,11); printf("#");
	}
	
	color_txt(0,12);
	gotoxy(27,10); printf("#");
	gotoxy(30,10); printf("#");
	for(int i=12;i<15;i++){
		gotoxy(27,i); printf("#");
	}
	for(int i=12;i<16;i++){
		gotoxy(30,i); printf("#");
	}
	
	color_txt(0,11);
	for(int i=10;i<15;i++){
		gotoxy(33,i); printf("----");
	}
	gotoxy(33,15); printf("---");
	
}

//10.-Athletic bilbao
void escudo_bilbao(){
	color_txt(0,11);
	gotoxy(19,2); printf("_________________________");
	gotoxy(18,3); printf("|------ATHLETIC CLUB------|");
	gotoxy(18,4); printf("|##---------------------##|");
	gotoxy(18,5); printf("|##||                 ||##|");
	gotoxy(18,6); printf("|##||                 ||##|");
	gotoxy(19,7); printf("||##|               |##||");
	gotoxy(19,8); printf("||##|               |##||");
	gotoxy(20,9); printf("||##|             |##||");
	gotoxy(20,10); printf("||##|             |##||");
	gotoxy(21,11); printf("||##|           |##||");
	gotoxy(21,12); printf("||##|           |##||");
	gotoxy(22,13); printf("||##|         |##||");
	gotoxy(22,14); printf("||##|         |##||");
	gotoxy(23,15); printf("||##|       |##||");
	gotoxy(23,16); printf("||##|       |##||");
	gotoxy(24,17); printf("||##|     |##||");
	gotoxy(24,18); printf("||##|     |##||");
	gotoxy(25,19); printf("||##|   |##||");
	gotoxy(25,20); printf("||##|   |##||");
	gotoxy(30,21); printf("VVV");
	
	gotoxy(37,5); printf("/");
	gotoxy(36,6); printf("/");
	gotoxy(35,7); printf("/");
	gotoxy(34,8); printf("/");
	gotoxy(33,9); printf("/");
	gotoxy(32,10); printf("/");
	gotoxy(31,11); printf("/");
	gotoxy(30,12); printf("/");
	gotoxy(29,13); printf("/");
	gotoxy(28,14); printf("/");

	gotoxy(27,6); printf("{O}");
	gotoxy(24,7); printf("___|T|");
	gotoxy(24,8); printf("     |");
	gotoxy(25,9); printf("____|");
	gotoxy(25,10); printf("~~~~~~~");
	gotoxy(26,11); printf("~~~~~");
	gotoxy(26,12); printf("~~~~");
	gotoxy(27,13); printf("~~");
	gotoxy(27,14); printf("~");


	color_txt(0,12);
	gotoxy(38,5); printf("##");
	gotoxy(37,6); printf("###");
	gotoxy(36,7); printf("###");
	gotoxy(36,8); printf("###");
	gotoxy(36,9); printf("##");
	gotoxy(36,10); printf("##");
	gotoxy(36,11); printf("#");
	gotoxy(36,12); printf("#");
	
	gotoxy(33,10); printf("#");
	gotoxy(32,11); printf("##");
	gotoxy(31,12); printf("###");
	gotoxy(31,13); printf("###");
	gotoxy(31,14); printf("###");
	gotoxy(31,15); printf("###");
	gotoxy(31,16); printf("###");
	gotoxy(31,17); printf("###");
	gotoxy(31,18); printf("###");
	gotoxy(31,19); printf("##");
	gotoxy(31,20); printf("##");
	
	gotoxy(28,15); printf("#");
	gotoxy(28,16); printf("#");
	
	color_txt(0,15);
	gotoxy(35,8); printf("#");
	gotoxy(34,9); printf("##");
	gotoxy(34,10); printf("##");
	gotoxy(34,11); printf("##");
	gotoxy(34,12); printf("##");
	gotoxy(34,13); printf("##");
	gotoxy(34,14); printf("##");
	gotoxy(34,15); printf("#");
	gotoxy(34,16); printf("#");

	gotoxy(30,13); printf("#");
	gotoxy(29,14); printf("##");
	gotoxy(29,15); printf("##");
	gotoxy(29,16); printf("##");
	gotoxy(29,17); printf("##");
	gotoxy(29,18); printf("##");
	gotoxy(30,19); printf("#");
	gotoxy(30,20); printf("#");
}

//11.- FUNCION DEL ESCUDO DE VILLARREAL
void escudo_villarreal(){
	color_txt(0,14);
	gotoxy(19,4);  printf("     < >< > <> < >< > ");      
	gotoxy(19,5);  printf("      %c%c %c%c || // //    ",92,92,92,92);      
	gotoxy(19,6);  printf("        *==.__.==*   ");      
	gotoxy(19,7);  printf("        %c.==  ==./    ",92);      
	gotoxy(19,8);  printf("            /%c           ",92);		
	gotoxy(19,9);  printf("          / ## %c",92);   
	gotoxy(19,10); printf("         #  ##  #");     
	gotoxy(19,11); printf("            ##");     
	gotoxy(19,12); printf("    /#      ##      #%c",92);  
	gotoxy(19,13); printf("  / ##      ##      ## %c",92);   
	gotoxy(19,14); printf("/#  ##  #        #  ##  #%c",92);   
	gotoxy(19,15); printf("%c#  ##  ##      ##  ##  #/",92);     
	gotoxy(19,16); printf("  %c ##  ##      ##  ## /  ",92);      
	gotoxy(19,17); printf("    %c#  ##      ##  #/    ",92);	   
	gotoxy(19,18); printf("      %c ##  ##  ## /     ",92);        
	gotoxy(19,19); printf("        %c#  ##  #/       ",92);         
	gotoxy(19,20); printf("          %c ## /        ",92);
	gotoxy(19,21); printf("            %c/           ",92);	

	color_txt(0,15);
	gotoxy(22,10); printf("|####%c",92);  gotoxy(36,10); printf("/####| ");   
	gotoxy(22,11); printf("|#####%c",92); gotoxy(35,11); printf("/#####|");    
	gotoxy(26,12); printf("%c##%c",92,92); gotoxy(34,12); printf("/##/");  
	gotoxy(27,13); printf("%c##%c",92,92);   gotoxy(33,13); printf("/##/");
	gotoxy(28,14); printf("%c##%c/##/",92,92);   
	gotoxy(29,15); printf("%c####/",92);     
	gotoxy(30,16); printf("%c##/",92);      
	gotoxy(31,17); printf("%c/",92);	

	color_txt(0,12);
	gotoxy(25,4);  printf("@");  gotoxy(28,4);  printf("@");  gotoxy(35,4);  printf("@"); gotoxy(38,4);  printf("@");
	gotoxy(31,7);  printf("**");
	gotoxy(30,9);  printf("#");  gotoxy(33,9);  printf("#");   
	gotoxy(29,10); printf("##");   gotoxy(33,10); printf("##");  
	gotoxy(29,11); printf("##");   gotoxy(33,11); printf("##");     
	gotoxy(30,12);  printf("#");  gotoxy(33,12);  printf("#"); gotoxy(25,12);  printf("#");  gotoxy(38,12);  printf("#");
	gotoxy(22,13);  printf("#"); gotoxy(25,13);  printf("##"); gotoxy(37,13);  printf("##");  gotoxy(41,13);  printf("#");
	gotoxy(21,14);  printf("##"); gotoxy(25,14);  printf("##"); gotoxy(37,14);  printf("##");  gotoxy(41,14);  printf("##");  
	gotoxy(21,15);  printf("##"); gotoxy(25,15);  printf("C#"); gotoxy(37,15);  printf("#F");  gotoxy(41,15);  printf("##");    
	gotoxy(22,16);  printf("#"); gotoxy(25,16);  printf("##"); gotoxy(29,16);  printf("#"); gotoxy(34,16);  printf("#");gotoxy(37,16); printf("##");  gotoxy(41,16);  printf("#");  
	gotoxy(25,17);  printf("##"); gotoxy(29,17);  printf("##");	  gotoxy(33,17); printf("##");  gotoxy(37,17);  printf("##");
	gotoxy(26,18);  printf("#"); gotoxy(29,18);  printf("##"); gotoxy(33,18);  printf("##");  gotoxy(37,18);  printf("#");       
	gotoxy(29,19);  printf("##");  gotoxy(33,19);  printf("##");    
	gotoxy(30,20);  printf("#"); gotoxy(33,20);  printf("#"); 
}

// 12.- FUNCION DEL ESCUDO DE GRANADA
void escudo_granada(){
	color_txt(0,12);
	gotoxy(18,2); printf("           .===.          ");
	gotoxy(18,3); printf("          /  º  %c       ",92);
	gotoxy(18,4); printf("    #####º  - -  º#####    ");
	gotoxy(18,5); printf("    ######%c  º  /#### #  ",92);
	gotoxy(18,6); printf("    #######*-#-*####  #  ");
	gotoxy(18,7); printf("    #            ## # #");
	gotoxy(18,8); printf("    # ############ ## #");
	gotoxy(18,9); printf("    # ####      ### # # ");
	gotoxy(18,10); printf("    # ############  # # ");
	gotoxy(18,11); printf("    # ######### #     # ");
	gotoxy(18,12); printf("    # ########  #     # ");
	gotoxy(18,13); printf("    # ##### ##..=.    # ");
	gotoxy(18,14); printf("    # #### ##// #     #");
	gotoxy(18,15); printf("    # ### ## || #==   #");
	gotoxy(18,16); printf("    # ## ##  %c%c #     #",92,92);
	gotoxy(18,17); printf("    # # ##    %c%c=%c    #",96,96,96);
	gotoxy(18,18); printf("    #  ##       #     #");
	gotoxy(18,19); printf("    # #               #");
	gotoxy(18,20); printf("     #               #");
	gotoxy(18,21); printf("      ###############");
	
	color_txt(0,15);
	gotoxy(31,4); printf("#");
	gotoxy(29,3); printf("##");
	gotoxy(32,3); printf("##");
	gotoxy(28,4); printf("##");
	gotoxy(33,4); printf("##");
	gotoxy(29,5); printf("##");
	gotoxy(32,5); printf("##");
	gotoxy(39,5); printf("#");
	gotoxy(38,6); printf("##");
	gotoxy(23,7); printf("############");
	gotoxy(37,7); printf("#"); gotoxy(39,7); printf("#");
	gotoxy(23,8); printf("#"); gotoxy(36,8); printf("#"); gotoxy(39,8); printf("#");
	gotoxy(23,9); printf("#"); gotoxy(28,9); printf("######"); gotoxy(35,9); printf("#"); gotoxy(37,9); printf("#"); gotoxy(39,9); printf("#");
	gotoxy(23,10); printf("#"); gotoxy(32,10); printf("#"); gotoxy(34,10); printf("#"); gotoxy(36,10); printf("##"); gotoxy(39,10); printf("#");
	gotoxy(23,11); printf("#"); gotoxy(31,11); printf("#"); gotoxy(33,11); printf("#"); gotoxy(35,11); printf("####"); gotoxy(39,11); printf("#");
	gotoxy(23,12), printf("#"); gotoxy(30,12); printf("#"); gotoxy(32,12), printf("##"); gotoxy(35,12), printf("####"); gotoxy(39,12), printf("#");
	gotoxy(23,13), printf("#"); gotoxy(29,13); printf("#"); gotoxy(31,13), printf("#"); gotoxy(36,13), printf("####");
	gotoxy(23,14), printf("#"); gotoxy(28,14); printf("#"); gotoxy(30,14), printf("#");gotoxy(33,14); printf("#"); gotoxy(35,14), printf("#####");
	gotoxy(23,15), printf("#"); gotoxy(27,15); printf("#"); gotoxy(29,15), printf("##");gotoxy(33,15); printf("#"); gotoxy(37,15), printf("###");
	gotoxy(23,16), printf("#"); gotoxy(26,16); printf("#"); gotoxy(28,16), printf("###");gotoxy(33,16); printf("#"); gotoxy(35,16), printf("#####");
	gotoxy(23,17), printf("#"); gotoxy(25,17); printf("#"); gotoxy(27,17), printf("#####"); gotoxy(36,17), printf("####");
	gotoxy(23,18); printf("##"); gotoxy(26,18); printf ("########"); gotoxy(35,18); printf("#####");
	gotoxy(23,19); printf("#"); gotoxy(25,19); printf ("###############");
	gotoxy(24,20); printf("###############");
}

//13.- FUNCIÓN DEL ESCUDO DE LEVANTE
void escudo_levante(){
	color_txt(0,14);
	gotoxy(19,5); printf("   //#####_/%c/%c_#####%c%c",92,92,92,92);
	gotoxy(19,6); printf("  //                  %c%c ",92,92);
	gotoxy(19,7); printf(" //                    %c%c  ",92,92);
	gotoxy(19,8); printf(" ||                    || ");
	gotoxy(19,9); printf(" ||                    || ");
	gotoxy(19,10); printf(" %c%c                    //",92,92);
	gotoxy(19,11); printf("  %c%c                  //",92,92);
	gotoxy(19,12); printf("   %c%c                //",92,92);
	gotoxy(19,13); printf("    %c%c              //",92,92);
	gotoxy(19,14); printf("     %c%c            //",92,92); 
	gotoxy(19,15); printf("      %c%c          //",92,92); 
	gotoxy(19,16); printf("       %c%c        //",92,92);
	gotoxy(19,17); printf("        %c%c      //",92,92);
	gotoxy(19,18); printf("         %c%c    //",92,92);
	gotoxy(19,19); printf("          %c%c  //",92,92);
	gotoxy(19,20); printf("           ====");
	
	color_txt(0,9);
	gotoxy(23,6); printf("##");
	gotoxy(22,7); printf("###");
	gotoxy(22,8); printf("###");
	gotoxy(24,12); printf("#");
	gotoxy(30,6); printf("####");
	gotoxy(30,7); printf("####");
	gotoxy(30,8); printf("####");
	gotoxy(30,17); printf("####");
	gotoxy(30,18); printf("####");
	gotoxy(31,19); printf("##");
	gotoxy(39,6); printf("##");
	gotoxy(39,7); printf("###");
	gotoxy(39,8); printf("###");
	gotoxy(39,12); printf("#");
	
	color_txt(0,12);
	gotoxy(26,6); printf("###");
	gotoxy(26,7); printf("###");
	gotoxy(26,8); printf("###");
	gotoxy(26,12); printf("###");
	gotoxy(26,13); printf("###");
	gotoxy(26,14); printf("###");
	gotoxy(27,15); printf("##");
	gotoxy(28,16); printf("#");
	gotoxy(35,6); printf("###");
	gotoxy(35,7); printf("###");
	gotoxy(35,8); printf("###");
	gotoxy(35,12); printf("###");
	gotoxy(35,13); printf("###");
	gotoxy(35,14); printf("###");
	gotoxy(35,15); printf("##");
	gotoxy(35,16); printf("#");
	
	color_txt(0,15);
	gotoxy(25,6); printf("|");
	gotoxy(25,7); printf("|");
	gotoxy(25,8); printf("|");
	gotoxy(25,12); printf("|");
	gotoxy(25,13); printf("|");
	gotoxy(29,6); printf("|");
	gotoxy(29,7); printf("|");
	gotoxy(29,8); printf("|");
	gotoxy(29,12); printf("|");
	gotoxy(29,13); printf("|");
	gotoxy(29,17); printf("|");
	gotoxy(34,6); printf("|");
	gotoxy(34,7); printf("|");
	gotoxy(34,8); printf("|");
	gotoxy(34,17); printf("|");
	gotoxy(38,6); printf("|");
	gotoxy(38,7); printf("|");
	gotoxy(38,8); printf("|");
	gotoxy(38,12); printf("|");
	gotoxy(38,13); printf("|");
	gotoxy(22,9); printf("====================");	
	gotoxy(23,11); printf("==================");
	gotoxy(22,10); printf("####LEVANTE U.D.####");
	gotoxy(29,12); printf("|.==.|");
	gotoxy(28,13); printf("/@@@@@@%c",92);
	gotoxy(27,14); printf("|@@@@@@@@|");
	gotoxy(27,15); printf("%c@@@@@@@@/",92);
	gotoxy(28,16); printf("*-@@@@-*");
}

// 14.-FUNCION DEL ESCUDO DE OSASUNA
void escudo_osasuna(){	
	color_txt(0,14);
	gotoxy(23,4); cout<< "<@> <^> @ <^> <@>"<<endl; 
	gotoxy(24,5); printf("%c===^==^==^===/",92);
	gotoxy(25,6); printf("%c___________/",92);
	gotoxy(26,7); cout<< "-----------"<<endl;

	color_txt(0,12);
	gotoxy(24,8);  cout<< "**";
	gotoxy(20,9); cout<< "******"<<endl;
	gotoxy(19,10); cout<< "***C***"<<endl;
	gotoxy(19,11); cout<< "*******"<<endl;
	gotoxy(19,12); cout<< "*******"<<endl;
	gotoxy(20,13); cout<< "******"<<endl;
	gotoxy(21,14); cout<< "*******"<<endl;
	gotoxy(23,15); cout<< "*******"<<endl;
	gotoxy(24,16); cout<< "*******"<<endl;
	gotoxy(26,17); cout<< "*****"<<endl;
	gotoxy(27,18); cout<< "****"<<endl;
	gotoxy(29,19); cout<< "**"<<endl;
	gotoxy(30,20); cout<< "*"<<endl;
	
	color_txt(0,9);
	gotoxy(37,8);  cout<< "**";
	gotoxy(37,9); cout<< "******"<<endl;
	gotoxy(37,10); cout<< "***A***"<<endl;
	gotoxy(37,11); cout<< "*******"<<endl;
	gotoxy(37,12); cout<< "*******"<<endl;
	gotoxy(37,13); cout<< "******"<<endl;
	gotoxy(34,14); cout<< "*******"<<endl;
	gotoxy(33,15); cout<< "*******"<<endl;
	gotoxy(32,16); cout<< "*******"<<endl;
	gotoxy(32,17); cout<< "*****"<<endl;
	gotoxy(32,18); cout<< "****"<<endl;
	gotoxy(32,19); cout<< "**"<<endl;
	gotoxy(32,20); cout<< "*"<<endl;	
	
	color_txt(0,15);
	gotoxy(26,8); cout<< "O####O####O"<<endl;
	gotoxy(26,9); cout<< "###########"<<endl;
	gotoxy(26,10); cout<< "###########"<<endl;
	gotoxy(26,11); cout<< "###########"<<endl;
	gotoxy(26,12); cout<< "###########"<<endl;
	gotoxy(26,13); cout<< "O#########O"<<endl;
	gotoxy(28,14); cout<< "#######"<<endl;
	gotoxy(30,15); cout<< "###"<<endl;
	
	color_txt(0,6);
	gotoxy(31,16); cout<< "O"<<endl;
	gotoxy(31,17); cout<< "*"<<endl;
	gotoxy(31,18); cout<< "*"<<endl;
	gotoxy(31,19); cout<< "O"<<endl;
	gotoxy(31,20); cout<< "*"<<endl;	
}

//15.- FUNCION DEL ESCUDO DE REAL BETIS
void escudo_realbetis(){
	color_txt(0,14);	
	gotoxy(19,4);  printf("         ^-++-^   ");  
	gotoxy(19,5);  printf("       (        ) ");      
	gotoxy(19,6);  printf("       %c.=    =./  ",92);      
	gotoxy(19,7);  printf("        %c.=**=./   ",92);        
	gotoxy(19,8);  printf(" ________..@@..________",92);	
	gotoxy(19,9);  printf("%c       /      %c       /",92,92);   
	gotoxy(19,10); printf(" %c     |        |     /",92);     
	gotoxy(19,11); printf("  %c    %c        /    /",92,92);     
	gotoxy(19,12); printf("   %c    *-@@@@-*    /",92);  
	gotoxy(19,13); printf("    %c              /",92);   
	gotoxy(19,14); printf("     %c            /",92);   
	gotoxy(19,15); printf("      %c          /",92);     
	gotoxy(19,16); printf("       %c        /",92);      
	gotoxy(19,17); printf("        %c      /",92);	   
	gotoxy(19,18); printf("         %c    /",92);        
	gotoxy(19,19); printf("          %c  /",92);         
	gotoxy(19,20); printf("           %c/",92);
	
	color_txt(0,12);
	gotoxy(27,5);  printf(".=****=.");
	gotoxy(29,6);  printf("****");
	
	color_txt(0,15);	
	gotoxy(20,9);   printf("###   #");  gotoxy(28,9); printf("@@@@@@");   gotoxy(35,9);  printf("#   ###");
	gotoxy(21,10);  printf("##");       gotoxy(27,10); printf("@@ @@ @@"); gotoxy(39,10);  printf("##");   
	gotoxy(22,11);  printf("#");        gotoxy(27,11); printf("@@@@@@@@"); gotoxy(39,11);  printf("#");  
	gotoxy(26,12);  printf("#");    gotoxy(35,12);  printf("#");
	gotoxy(26,13);  printf("###");  gotoxy(33,13);  printf("###");
	gotoxy(26,14);  printf("###");  gotoxy(33,14);  printf("###");
	gotoxy(26,15);  printf("###");  gotoxy(33,15);  printf("###"); 
	gotoxy(27,16);  printf("##");   gotoxy(33,16);  printf("##");    
	gotoxy(28,17);  printf("#");   gotoxy(33,17);  printf("#");  
	
	color_txt(0,10);
	gotoxy(23,9);  printf("###");  gotoxy(36,9);  printf("###");
	gotoxy(23,10);  printf("###");  gotoxy(29,10); printf("R"); gotoxy(32,10); printf("B"); gotoxy(36,10);  printf("###");
	gotoxy(23,11);  printf("###");  gotoxy(36,11);  printf("###"); 
	gotoxy(23,12);  printf("###");  gotoxy(36,12);  printf("###"); 	
	gotoxy(24,13);  printf("##");   gotoxy(29,13);  printf("####");  gotoxy(36,13);  printf("##");    
	gotoxy(25,14);  printf("#");    gotoxy(29,14);  printf("####");  gotoxy(36,14);  printf("#");
	gotoxy(29,15);  printf("####");
	gotoxy(29,16);  printf("####");
	gotoxy(29,17);  printf("####");
	gotoxy(29,18);  printf("####");
	gotoxy(30,19);  printf("##");	
}

//16.- FUNCION DEL ESCUDO DE REAL VALLADOLID
void escudo_realvalladolid(){
	color_txt(0,10);
	gotoxy(19,10); printf("  @@                  @@  ");     
	gotoxy(19,11); printf(" @@                    @@ ");   
	gotoxy(19,13); printf("@%c@                    @/@",92);   
	gotoxy(19,14); printf("@%c@@                  @@/@",92);     
	gotoxy(19,15); printf("@@%c@@                @@/@@",92);      
	gotoxy(19,16); printf(" @@%c@@              @@/@@ ",92);	   
	gotoxy(19,17); printf("  @@%c@@            @@/@@  ",92);        
	gotoxy(19,18); printf("   @@%c@@          @@/@@   ",92);         
	gotoxy(19,19); printf("    @@%c@@        @@/@@    ",92);
	gotoxy(19,20); printf("       @@%c@@  @@/@@      ",92);
	gotoxy(19,21); printf("          //  %c%c         ",92,92); 
	
	color_txt(0,14);
	gotoxy(19,3);  printf("        __..<>..__      ");      
	gotoxy(19,4);  printf("       / // || %c%c %c     ",92,92,92);      
	gotoxy(19,5);  printf("      / //  ||  %c%c %c    ",92,92,92);      
	gotoxy(19,6);  printf("      %c.==******==./    ",92);      
	gotoxy(19,7);  printf("       %c.==****==./     ",92);
	
	color_txt(0,12);
	gotoxy(27,4);  printf("%c",37); gotoxy(30,4);  printf("%c",37);    gotoxy(33,4);  printf("%c",37);    gotoxy(36,4);  printf("%c",37);
	gotoxy(26,5);  printf("%c",37); gotoxy(29,5);  printf("%c%c",37,37);   gotoxy(33,5);  printf("%c%c",37,37);	  gotoxy(37,5);  printf("%c",37);	
	gotoxy(24,8);  printf("_______  _______");   
	gotoxy(23,9);  printf("|#############/");     
	gotoxy(23,10); printf("|##        ##/");     
	gotoxy(23,11); printf("|##      ##/");  
	gotoxy(23,12); printf("|##     ##/");   
	gotoxy(23,13); printf("%c##    ##/",92);   
	gotoxy(24,14); printf("%c##  #/",92);     
	gotoxy(25,15); printf("%c###/",92);      
	gotoxy(26,16); printf("%c#/",92);
	
	color_txt(0,14);
	gotoxy(26,10); printf("========");     
	gotoxy(26,11); printf("======");  
	gotoxy(26,12); printf("=====");   
	gotoxy(26,13); printf("====");   
	gotoxy(27,14); printf("==");
	
	color_txt(0,5);
	gotoxy(38,9);  printf("##|");     
	gotoxy(37,10); printf("###|");     
	gotoxy(37,11); printf("###|");  
	gotoxy(34,12); printf("#  ###|");   
	gotoxy(33,13); printf("##  ###/");   
	gotoxy(33,14); printf("##  ##/");     
	gotoxy(30,15); printf("#  ##  #/");      
	gotoxy(29,16); printf("##  ##  /");	   
	gotoxy(27,17); printf("%c###  ## /",92);        
	gotoxy(28,18); printf("%c##  ##/",92);         
	gotoxy(29,19); printf("%c#  #/",92);
	
	color_txt(0,15);
	gotoxy(31,8); printf("||");
	gotoxy(19,11); printf("_");  gotoxy(22,11); printf("_");  gotoxy(35,11); printf("##");  
	gotoxy(41,11); printf("_");  gotoxy(44,11); printf("_");
	gotoxy(19,12); printf("%c___",92);	gotoxy(35,12); printf("##");   gotoxy(41,12); printf("___/");
	gotoxy(35,13); printf("##");   
	gotoxy(31,14); printf("##");  gotoxy(35,14); printf("##"); 
	gotoxy(31,15); printf("##");  gotoxy(35,15); printf("##");
	gotoxy(31,16); printf("##");  gotoxy(35,16); printf("##");
	gotoxy(31,17); printf("RV");  gotoxy(35,17); printf("#");            
	gotoxy(31,18); printf("##");         
	gotoxy(31,19); printf("##");
	gotoxy(31,20); printf("||");
	gotoxy(31,21); printf("%c/",92);

}

// 17.-FUNCION DEL ESCUDO DE EIBAR
void escudo_eibar(){	
	color_txt(0,9);
	gotoxy(37,8); printf("_____");
	gotoxy(37,9); printf("#####%c",92);
	gotoxy(36,10); printf("######/");
	gotoxy(35,11); printf("### ##/");
	gotoxy(34,12); printf("### ##/");
	gotoxy(33,13); printf("### ##/");
	gotoxy(32,14); printf("### ##/");
	gotoxy(31,15); printf("### ##/");
	gotoxy(30,16); printf("######/");
	gotoxy(29,17); printf("### ##/");
	gotoxy(27,18); printf("%c### ##/",92);
	gotoxy(28,19); printf("%c####/",92);
	gotoxy(29,20); printf("%c##/",92);
	gotoxy(30,21); printf("%c/",92);
	
	color_txt(0,15);
	gotoxy(20,8); printf("_________________");
	gotoxy(19,9); printf("/#################");
	gotoxy(19,10); printf("%c####  ##  ######",92);
	gotoxy(20,11); printf("%c#####  #######",92);
	gotoxy(21,12); printf("%c##  ##  ####",92);
	gotoxy(22,13); printf("%c##########",92);
	gotoxy(23,14); printf("%c########",92);
	gotoxy(24,15); printf("%c######",92);
	gotoxy(25,16); printf("%c####",92);
	gotoxy(26,17); printf("%c##",92);
	color_txt(0,7);
	gotoxy(31,18); printf("S");
	gotoxy(32,17); printf("D");
	gotoxy(34,15); printf("E");
	gotoxy(35,14); printf("I");
	gotoxy(36,13); printf("B");
	gotoxy(37,12); printf("A");
	gotoxy(38,11); printf("R");
	
	color_txt(0,12);
	gotoxy(24,10); printf("##"); gotoxy(28,10); printf("##");
	gotoxy(26,11); printf("##");
	gotoxy(24,12); printf("##"); gotoxy(28,12); printf("##");
	gotoxy(28,3); printf("..==..");
	gotoxy(27,4); printf("/######%c",92);
	gotoxy(26,5); printf("|########|");
	gotoxy(26,6); printf("%c########/",92);
	gotoxy(27,7); printf("*-####-*");	
}

//18.- FUNCION DEL ESCUDO DE CELTA DE VIGO
void escudo_celtadevigo(){
	color_txt(0,12);	
	gotoxy(19,3);  printf("            /%c         ",92); 
	gotoxy(19,4);  printf("          (=**=)       ");           
	gotoxy(19,7);  printf("   <>>              <<>    ");	
	gotoxy(19,8);  printf("  ((                  ))   ");   
	gotoxy(19,9);  printf("<>=====            =====<> ");     
	gotoxy(19,10); printf("  ((                  ))   ");     
	gotoxy(19,11); printf("   <>>              <<>   ");    
	gotoxy(19,14); printf("            ||         ");     
	gotoxy(19,15); printf("          /####%c      ",92);      
	gotoxy(19,16); printf("        /########%c  ",92);	   
	gotoxy(19,17); printf("        %c########/  ",92);        
	gotoxy(19,18); printf("         %c######/  ",92);         
	gotoxy(19,19); printf("          %c####/  ",92);
	gotoxy(19,20); printf("           %c##/  ",92);
	gotoxy(19,21); printf("            %c/  ",92);
	
	color_txt(0,11);
	gotoxy(27,7);  printf("____||____  ");	
	gotoxy(26,8);  printf("|#        #|");   
	gotoxy(26,9);  printf("%c#  #     #/",92);     
	gotoxy(27,10); printf("%c#  # ###/",92);     
	gotoxy(28,11); printf("%c#  # #/",92);  
	gotoxy(29,12); printf("%c#  #/",92);   
	gotoxy(31,13); printf("%c/",92);
	
	color_txt(0,15);
	gotoxy(19,5);  printf("           %c##/          ",92);
	gotoxy(19,6);  printf("            **           ",92);
	gotoxy(28,8);  printf("########");   
	gotoxy(28,9);  printf("##");   gotoxy(31,9);  printf("#####");  
	gotoxy(29,10); printf("##");   gotoxy(32,10);  printf("#"); 
	gotoxy(30,11); printf("##");   gotoxy(33,11);  printf("#");
	gotoxy(31,12); printf("##");
}

//19.- FUNCION DEL ESCUCDO DE RCD MALLORCA
void escudo_rcdmallorca(){
	color_txt(0,10);
	gotoxy(19,14); printf(" @                      @");     
	gotoxy(19,15); printf("@/@                    @%c@",92);      
	gotoxy(19,16); printf("@/@                    @%c@",92);	   
	gotoxy(19,17); printf(" @%c@                  @/@",92);        
	gotoxy(19,18); printf("  @%c@                @/@",92);         
	gotoxy(19,19); printf("    @@              @@");
	gotoxy(19,20); printf("      @            @");

	color_txt(0,14);
	gotoxy(19,3);  printf("        __..<>..__      ");      
	gotoxy(19,4);  printf("       / // || %c%c %c     ",92,92,92);      
	gotoxy(19,5);  printf("      / //  ||  %c%c %c    ",92,92,92);      
	gotoxy(19,6);  printf("      %c.==******==./    ",92);      
	gotoxy(19,7);  printf("       %c.==****==./     ",92);
	gotoxy(19,9);  printf("     __%c###====###/__  ",92);
	gotoxy(19,10); printf("   /###            ###%c ",92);     
	gotoxy(19,11); printf("  /###              ###%c ",92);  
	gotoxy(19,12); printf(" /###   ####  ####   ###%c ",92);   
	gotoxy(19,13); printf(" %c##   #          #   ##/ ",92);        
	gotoxy(26,20); printf("%c##########/",92);
	gotoxy(28,21); printf("%c######/",92);
	
	color_txt(0,12);
	gotoxy(19,8);  printf("        *=.####.=*     ");
	gotoxy(27,4);  printf("%c",37); gotoxy(30,4);  printf("%c",37);    gotoxy(33,4);  printf("%c",37);    gotoxy(36,4);  printf("%c",37);
	gotoxy(26,5);  printf("%c",37); gotoxy(29,5);  printf("%c%c",37,37);   gotoxy(33,5);  printf("%c%c",37,37);	  gotoxy(37,5);  printf("%c",37);
	gotoxy(26,10); printf(".==******==.");     
	gotoxy(25,11); printf("/############%c",92);  
	gotoxy(24,12); printf("/##");  gotoxy(31,12); printf("##");  gotoxy(37,12); printf("##%c",92); 
	gotoxy(23,13); printf("/##"); gotoxy(27,13); printf("##########"); gotoxy(38,13); printf("##%c",92);   
	gotoxy(22,14); printf("|## ###      ### ##|");     
	gotoxy(22,15); printf("|## ### #### ### ##|");      
	gotoxy(23,16); printf("%c## ##      ## ##/",92);	   
	gotoxy(24,17); printf("%c## ######## ##/",92);        
	gotoxy(25,18); printf("%c##   ##   ##/",92);         
	gotoxy(26,19); printf("*=.######.=*");

	color_txt(0,14);
	gotoxy(25,14); printf("#"); gotoxy(29,14); printf("######"); gotoxy(38,14); printf("#");
	gotoxy(25,15); printf("#"); gotoxy(29,15); printf("#"); gotoxy(34,15); printf("#");gotoxy(38,15); printf("#");
	gotoxy(26,16); printf("#"); gotoxy(29,16); printf("######"); gotoxy(37,16); printf("#");
	gotoxy(27,17); printf("#"); gotoxy(36,17); printf("#");
	gotoxy(28,18); printf("###"); gotoxy(33,18); printf("###");
}

//20.- FUNCION DEL ESCUDO DE LEGANES
void escudo_leganes(){	
	color_txt(0,14);
	gotoxy(19,4); printf("==========================");	      
	gotoxy(19,5); printf("%C    CLUB   DEPORTIVO    /",92);
	gotoxy(19,6); printf(" %C======================/",92);            
	gotoxy(19,7); printf("  %C                    /",92);     
	gotoxy(19,8); printf("   %C  C   %C<><>/   D  /",92,92);    
	gotoxy(19,9); printf("    %C     ..==..     /",92);    
	gotoxy(19,10); printf("     %C   /      %C   /",92,92);     
	gotoxy(19,11); printf("   /  %C |        | /  %C",92,92);      
	gotoxy(19,12); printf("   /   %C%C        //   %C",92,92,92);      
	gotoxy(19,13); printf("   %C    %C*-####-*/    /",92,92);	    
	gotoxy(19,14); printf("    %C    %C      /    /",92,92);      
	gotoxy(19,15); printf("     %C    %C    /    /",92,92);      
	gotoxy(19,16); printf("      %C    %C  /    /",92,92);            
	gotoxy(19,17); printf("        %C   %C/   /",92,92); 
	gotoxy(19,18); printf("     ----%C  ..  /-----",92); 
	gotoxy(19,19); printf("    |     LEGANES     |");
	gotoxy(19,20); printf("     -----------------"); 	

	color_txt(0,15);    
	gotoxy(20,5); printf("####"); gotoxy(28,5); printf("###");  gotoxy(40,5); printf("####");           
	gotoxy(22,7); printf("####################"); 
	gotoxy(23,8); printf("##"); gotoxy(26,8); printf("###");  gotoxy(35,8); printf("###");  gotoxy(39,8); printf("##");
	gotoxy(24,9); printf("#####"); gotoxy(35,9); printf("#####");   
	gotoxy(25,10); printf("###"); gotoxy(29,10); printf("#");  gotoxy(31,10); printf("##"); gotoxy(34,10); printf("#"); gotoxy(36,10); printf("###"); 
	gotoxy(26,11); printf("#"); gotoxy(28,11); printf("##");  gotoxy(31,11); printf("##"); gotoxy(34,11); printf("##"); gotoxy(37,11); printf("#");
	gotoxy(28,12); printf("##");  gotoxy(31,12); printf("##"); gotoxy(34,12); printf("##");       	    
	gotoxy(29,14); printf("######");     
	gotoxy(30,15); printf("####");      
	gotoxy(31,16); printf("##");           
	gotoxy(24,19); printf("#####"); gotoxy(36,19); printf("#####");

	color_txt(0,9);	
	gotoxy(30,10); printf("@");     gotoxy(33,10); printf("@");
	gotoxy(30,11); printf("@");     gotoxy(33,11); printf("@");
	gotoxy(30,12); printf("@");     gotoxy(33,12); printf("@");
	
	color_txt(0,10);
	gotoxy(21,10); printf("@@"); gotoxy(41,10); printf("@@");     
	gotoxy(20,11); printf("@@"); gotoxy(23,11); printf("@@");  gotoxy(39,11); printf("@@");  gotoxy(42,11); printf("@@");
	gotoxy(20,12); printf("@@"); gotoxy(23,12); printf("@@");  gotoxy(39,12); printf("@@");  gotoxy(42,12); printf("@@");
	gotoxy(20,13); printf("@@"); gotoxy(23,13); printf("@@");  gotoxy(39,13); printf("@@");  gotoxy(42,13); printf("@@");
	gotoxy(21,14); printf("@@"); gotoxy(24,14); printf("@@");  gotoxy(38,14); printf("@@");  gotoxy(41,14); printf("@@");
	gotoxy(22,15); printf("@@"); gotoxy(25,15); printf("@@");  gotoxy(37,15); printf("@@");  gotoxy(40,15); printf("@@");
	gotoxy(23,16); printf("@@"); gotoxy(26,16); printf("@@");  gotoxy(36,16); printf("@@");  gotoxy(39,16); printf("@@");
	gotoxy(25,17); printf("@@"); gotoxy(28,17); printf("@@");  gotoxy(34,17); printf("@@");  gotoxy(37,17); printf("@@");
	gotoxy(29,18); printf("@@"); gotoxy(33,18); printf("@@");
}

//funcion para los escudos.
void escudos (int e){
	switch(e)
	{
		case 0:
			escudo_barcelona();				
		break;		
		case 1:
			escudo_rcdespanyol();
		break;
		case 2:
			escudo_alaves();
		break;		
		case 3:
			escudo_realmadrid();
		break;		
		case 4:
			escudo_atleticoM();
		break;		
		case 5:
			escudo_sevilla();
		break;		
		case 6:
			escudo_realsociedad();
		break;		
		case 7:
			escudo_valencia();
		break;		
		case 8:
			escudo_getafe();
		break;
		case 9:
			escudo_bilbao();
		break;
		case 10:
			escudo_villarreal();
		break;
		case 11:
			escudo_granada();
		break;
		case 12:
			escudo_levante();
		break;
		case 13:
			escudo_osasuna();
		break;		
		case 14:
			escudo_realbetis();
		break;
		case 15:
			escudo_realvalladolid();
		break;
		case 16:
			escudo_eibar();
		break;
		case 17:
			escudo_celtadevigo();
		break;
		case 18:
			escudo_rcdmallorca();
		break;
		case 19:
			escudo_leganes();
		break;
	}	
}
