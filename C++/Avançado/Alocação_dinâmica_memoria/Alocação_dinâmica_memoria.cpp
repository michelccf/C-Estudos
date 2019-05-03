// Alocação_dinâmica_memoria.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
#include <iostream>

#include <locale.h>

#include "Classe_Listas.h"

void MenuLista_cl(bool ex);

void AddLista_cl(Lista_s_cl* l);

void ImprimirLista(Lista_s_cl* l);

Lista_s_cl * l = NULL;



enum Funcoes
{
	ListaSimples_struct = 1,
	ListaSimplesDupEnc_struct = 2,
	ListaCl = 3
};

enum FuncoesLista
{
	Add = 1,
	Apagar = 2,
	ContarElementos = 3,
	Imprimir = 4,
	Concatenar = 5

};

int main()
{

	setlocale(LC_ALL, "Portuguese");

	int arg = 0;

	printf("Digite Qual Função quer executar.\n");
	printf("1- Lista Simples encadeada.\n");
	printf("2- Lista simples duplamente encadeada.\n");
	printf("3- Lista cl.\n");

	std::cout << std::endl;

	printf("Sua opção: ");

	std::cin >> arg;

	switch (arg)
	{
		case static_cast<int>(Funcoes::ListaSimples_struct) :
			break;
			case static_cast<int>(Funcoes::ListaSimplesDupEnc_struct) :
				break;
				case static_cast<int>(Funcoes::ListaCl) :
					MenuLista_cl(false);
					break;

				default:
					std::cout << "Função não Existe! Digite novamente após pressionar a tecla enter.\n\n";
					system("PAUSE");
					system("CLS");

					main();

					break;
	}

}


void MenuLista_cl(bool ex)
{
	int arg = 0;
	int voltar = 2;

	system("CLS");

	printf("Digite Qual Função para a lista de classes deseja usar?\n");
	printf("1- Adicionar\n");
	printf("2- Apagar\n");
	printf("3- Contar Elementos\n");
	printf("4- Imprimir\n");
	printf("5- Concatenar\n");

	std::cout << std::endl;

	printf("Sua opção: ");

	std::cin >> arg;

	if (ex == false)
	{
		l = static_cast<Lista_s_cl*>(malloc(sizeof(Lista_s_cl)));
		new (l) Lista_s_cl();
		l->~Lista_s_cl();
	}

	switch (arg)
	{

		case static_cast<int>(FuncoesLista::Add) :
			AddLista_cl(l);

			while (voltar != 0 && voltar != 1) {
				std::cout << "Deseja Fazer outra operação? 1 - SIM, 2 - NÃO \nSua Resposta: ";

				std::cin >> voltar;
			}

			if (voltar == 1)
				MenuLista_cl(true);

			break;

			case static_cast<int>(FuncoesLista::Imprimir) :
				ImprimirLista(l);
				break;

			default:
				std::cout << "Função não Existe! Digite novamente após pressionar a tecla enter.\n\n";
				system("PAUSE");
				system("CLS");

				MenuLista_cl(true);
				break;
	}

}

void AddLista_cl(Lista_s_cl *l)
{
	int valor = 0;
	bool continuar = true;
	char opcao = ' ';

	while (continuar)
	{
		while (opcao != 'n' && continuar == true )
		{
			printf("Digite o valor que deseja adicionar na lista: ");
			std::cin >> valor;

			l->Add(valor);


			printf("Deseja adicionar mais algum valor?\ny - SIM, n - NÃO: ");

			std::cin >> opcao;

			if (opcao == 'y')
				continuar = true;
			else
				continuar = false;

		}
	}
	
}

void ImprimirLista(Lista_s_cl* l)
{
	printf("Impressão da lista encadeada.");
	std::cout << std::endl << std::endl;

	No* no = l->FirstOrDefaut;
	do
	{
		std::cout << no << ": " << no->retornarValor() << std::endl;
		no = no->proxNo;
	} while (no != NULL);

	system("PAUSE");

}

