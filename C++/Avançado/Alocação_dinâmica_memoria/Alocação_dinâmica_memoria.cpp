// Alocação_dinâmica_memoria.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
#include <iostream>

#include <locale.h>


enum Funcoes
{
	Media = 1,
	SomaVetorialNaoDinamico = 2,
	ConcatenacaoVetorialNaoDinamico = 3,
	MatrizQuadradaNaoDinamica = 4,
	MultiplicacaoMatrizesNaoDinamicas = 5
};

int main()
{

	setlocale(LC_ALL, "Portuguese");

	int arg = 0;

	printf("Digite Qual Função quer executar.\n");
	printf("1- Lista Simples encadeada.\n");
	printf("2- Lista simples duplamente encadeada.\n");
	printf("3- Lista circular encadeada.\n");
	printf("4- Lista ciscular duplamente encadeada.\n");


	printf("\n");

	printf("Sua opção: ");

	cin >> arg;

	switch (arg)
	{
		case static_cast<int>(Funcoes::Media) :
			
			break;


		default:
			cout << "Função não Existe! Digite novamente após pressionar a tecla enter.\n\n";
			system("PAUSE");
			system("CLS");

			main();

			break;
	}
}

