
#include "stdafx.h"
using namespace std;
#include <iostream>

#include <locale.h>

#include <string>

#include "ListaGenerica.h"

#include "ListaTelefonica.h"



void MenuLista_Generica();

//Lista_s_cl * l = NULL;




enum Funcoes
{
	ListaCl = 1,
	ListaGenerica = 2
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
	printf("1- Lista cl.\n");
	printf("2- Casos de uso da lista genérica.\n");

	std::cout << std::endl;

	printf("Sua opção: ");

	std::cin >> arg;

	switch (arg)
	{
		case static_cast<int>(Funcoes::ListaCl) :
			//MenuLista_cl(false);
			break;

			case static_cast<int>(Funcoes::ListaGenerica) :
				MenuLista_Generica();
				break;
				

				default:
					std::cout << "Função não Existe! Digite novamente após pressionar a tecla enter.\n\n";
					system("PAUSE");
					system("CLS");

					main();

					break;
	}

}

void MenuLista_Generica()
{
	std::cout << "A classe escolhida foi Lista telefonica." << endl << endl;
	Lista<ListaTelefonica> *List = static_cast<Lista<ListaTelefonica>*>(malloc(sizeof(Lista<ListaTelefonica>)));
	new (List) Lista<ListaTelefonica>();
	Lista<ListaTelefonica> List_v = *List;

	for (int i = 0; i < 5; i++)
	{
		ListaTelefonica* lt = new ListaTelefonica;
		lt->Nome = "Lucas";
		lt->Celular = "97382-8192";
		lt->Telefone = "5092-2837";
		

		lt->Nome += std::to_string(i);
		List_v.Add(lt);
		std::cout << List_v[i].Nome << endl << List_v[i].Telefone << endl << List_v[i].Celular << endl << endl;
		free(lt);
	}
	std::cout << endl << endl;

	std::cout << "First or Default:" << endl << List_v.FirstOrDefault().Nome << endl << List_v.FirstOrDefault().Telefone << endl << List_v.FirstOrDefault().Celular << endl << endl;

	std::cout << "Last or Default:" << endl << List_v.LastOrDefault().Nome << endl << List_v.LastOrDefault().Telefone << endl << List_v.LastOrDefault().Celular << endl << endl;

	std::cout << "Tamanho da lista é: " << List_v.Size() << " Bytes" << endl << endl;

	std::cout << "Remocão do indice 2" << endl;
	List_v = List_v.RemoveAt(2);

	for (int i = 0; i < List_v.Count(); i++)
	{
		std::cout << List_v[i].Nome << endl << List_v[i].Telefone << endl << List_v[i].Celular << endl << endl;
	}

	system("PAUSE");
}
