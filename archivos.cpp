#include<iostream>
#include<conio.h>

const char *nombre_archivo = "archivo.txt";
const char *nombre_archivo_temp = "archivo_temp.dat"; 

using namespace std;

class Archivo{
	public:
		FILE* archivo;
		FILE* archivo_temp;
	public:
		void agregar_archivo(){
			archivo = fopen(nombre_archivo,"ab");
		}
		void modificar_archivo(){
			archivo = fopen(nombre_archivo,"r+b");
		}
		
		void leer_archivo(){
			archivo = fopen(nombre_archivo,"rb");
		}
		void eliminar_archivo(){
			archivo_temp=fopen(nombre_archivo_temp,"w+b"); 
			archivo=fopen(nombre_archivo,"rb");
		}
		void cerrar_archivo(){
			fclose(archivo);
		}
		void cerrar_archivoaux(){
			fclose(archivo_temp);
		}
};

