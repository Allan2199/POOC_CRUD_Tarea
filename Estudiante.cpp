#include<iostream>
#include<conio.h>
#include <string.h> 
#include "archivos.cpp"

using namespace std;
Archivo ar;


class Estudiante{
			// atributo
	public : 
			char codigo[5];
			char nombres[40];
			char apellidos[40];
			char direccion[100];
			int telefono;
			
				
			// metodo
	public : 
		Estudiante(){
			
		}
		
	void getdata(){
		system("cls");
		Estudiante s;
		ar.agregar_archivo();
		string nombre2, apellido2,direccion2,codigo2;
		fflush(stdin);
		cout<<"Escriba el nombre del estudiante: ";
		getline(cin,nombre2);
		strcpy(s.nombres,nombre2.c_str());
		cout<<"Escriba los apellidos del estudiante: ";
		getline(cin,apellido2);
		strcpy(s.apellidos,apellido2.c_str());
		cout<<"Escriba el codigo del estudiante: ";
		getline(cin,codigo2);
		strcpy(s.codigo,codigo2.c_str());
		cout<<"Escriba la direccion del estudiante: ";
		getline(cin,direccion2);
		strcpy(s.direccion,direccion2.c_str());
		cout<<"Escriba el telefono del estudiante: ";
		cin>>s.telefono;
		fwrite(&s,sizeof(s),1,ar.archivo);
		ar.cerrar_archivo();
	}
	
	void showdata(){
		system("cls");
		Estudiante s;
		ar.leer_archivo();
		fread(&s,sizeof(s),1,ar.archivo);
		int id=0;
		do{
			cout<<"____________________________________"<<endl;
			cout<<"Id: "<<id<<endl;
			cout<<"Nombre: "<<s.nombres<<endl;
			cout<<"Apellidos: "<<s.apellidos<<endl;
			cout<<"Codigo: "<<s.codigo<<endl;
			cout<<"Direccion: "<<s.direccion<<endl;
			cout<<"Telefono: "<<s.telefono<<endl;
			id++;
			fread(&s,sizeof(s),1,ar.archivo);		
		}while(!feof(ar.archivo));
		ar.cerrar_archivo();
		getch();
	}
	
	void editdata(){
		system("cls");
		Estudiante s;
		int id;
		string name,lastname,adress,cod;
		int tel;
		//archivo = fopen(nombre_archivo,"r+b");
		cout<<"Escriba el id para modificar: ";
		cin>>id;
		fseek(ar.archivo, id*sizeof(s),SEEK_SET);
		cout<<"Nombres: "<<s.nombres<<endl;
		getch();
		/*
		fflush(stdin);
		cout<<"Ingrese el nuevo nombre: ";
		getline(cin,name);
		strcpy(s.nombres,name.c_str());
		cout<<"Ingrese el nuevo apellido: ";
		getline(cin,lastname);
		strcpy(s.nombres,lastname.c_str());
		cout<<"Ingrese el nuevo codigo: ";
		getline(cin,cod);
		strcpy(s.nombres,cod.c_str());
		cout<<"Ingrese el nuevo telefono: ";
		cin>>s.telefono;
		cout<<"Ingrese la nueva direccion: ";
		getline(cin,adress);
		strcpy(s.nombres,adress.c_str());
		fwrite(&s,sizeof(s),1,archivo);
		*/
		ar.cerrar_archivo();
	}
	
	//Metdo set
	void setname(string n){Estudiante s; strcpy(s.nombres,n.c_str());}
	void setlastname(string ap){Estudiante s; strcpy(s.apellidos,ap.c_str());}
	void setcod(string cod){Estudiante s; strcpy(s.codigo,cod.c_str());}
	void setadress(string ad){Estudiante s; strcpy(s.direccion,ad.c_str());}
	void settelefono(int tel){Estudiante s; telefono = tel;}
};
