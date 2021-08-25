// t = 12345
// Este programa desordena los carácteres de una forma definida
/*
	12345
	51423
	35214
	43152
	24531
	12345
*/
#pragma once

#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string>

using namespace std;

struct CambioOrden {
	static string Encriptar(string t, int veces);
	static string Desencriptar(string t, int veces);
};
inline string CambioOrden::Encriptar(string t, int veces){
	if (t.length() < 2 || !veces) return t;
	
	string n = "";
	while (t.length()){
		if (t.length() > 1){
			n+=t.at(t.length() - 1);
			n+= t.at(0);
		}
		if (t.length() > 2) 
		{
			t=t.substr(1, t.length() - 2);
		} else break;
	} return Encriptar(n, veces - 1);
}

inline string CambioOrden::Desencriptar(string t, int veces){
	if (t.length() < 2 || !veces) return t;
	
	string n = "";
	
	for (int i=1; i < t.length(); i+=2){
		n += t.at(i);
	}
	int ultimo = t.length() - (t.length() % 2 ? 1 : 2); //Dejar con 1 si es impar la cantidad de caracteres, si es par habrá que restarle dos con ': 2'
	for (int i=ultimo; i >= 0; i-=2){
		n += t.at(i);
	}
	return Desencriptar (n, veces - 1);
}

