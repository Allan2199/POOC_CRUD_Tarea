#include<iostream>
#include<conio.h>
#include "Estudiante.cpp"

Estudiante s;

using namespace std;

int main(){
	
	int op;
	
	do{
		system("cls");
		cout<<"1.Escriba el estudiante"<<endl;
		cout<<"2.Leer  los estudiantes existentes"<<endl;
		cout<<"3.Actualizar el estudiante"<<endl;
		cout<<"4.Eliminar al estudiante"<<endl;
		cout<<"0.Salir"<<endl;
		cout<<"Ingrese la opción para poder salir: ";
		cin>>op;
	
		switch(op){
			case 1: s.getdata(); break;
			case 2: s.showdata(); break;
			case 3:	s.editdata(); break;
			case 4:	//eliminar(); break;
			case 0: break;
			default: break;
		}	
	}while(op!=0);
	
	return 0;
	getch();	
}


