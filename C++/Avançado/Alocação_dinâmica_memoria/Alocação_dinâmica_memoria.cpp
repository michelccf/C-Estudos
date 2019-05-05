
#include "stdafx.h"
using namespace std;
#include <iostream>

#include <locale.h>

#include <string>

#include "Classe_Listas.h"

#include "ListaGenerica.h"

#include "ListaTelefonica.h"

//void MenuLista_cl(bool ex);
//
//void AddLista_cl(Lista_s_cl* l);
//
//Lista_s_cl* ApagarLista(Lista_s_cl *l);
//
//void ImprimirLista(Lista_s_cl* l);
//
//void OutrasOperacoes();

void MenuLista_Generica();

Lista_s_cl * l = NULL;




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
	Lista<ListaTelefonica>* List = static_cast<Lista<ListaTelefonica>*>(malloc(sizeof(Lista<ListaTelefonica>)));
	new (List) Lista<ListaTelefonica>();
	Lista<ListaTelefonica> List_v = *List;

	ListaTelefonica* lt = static_cast<ListaTelefonica*>(malloc(sizeof(ListaTelefonica)));
	ListaTelefonica lt_v = *lt;
	lt->Nome = "Lucas";
	lt->Celular = "97382-8192";
	lt->Telefone = "5092-2837";

	for (int i = 0; i < 5; i++)
	{
		lt->Nome += static_cast<char>(i);
		List_v.Add(lt_v);
		std::cout << List_v[i].Nome << endl << List_v[i].Telefone << endl << List_v[i].Celular << endl << endl;
	}
	std::cout << endl << endl;

	system("PAUSE");
}

//void MenuLista_cl(bool ex)
//{
//	int arg = 0;
//
//	system("CLS");
//
//	printf("Digite Qual Função para a lista de classes deseja usar?\n");
//	printf("1- Adicionar\n");
//	printf("2- Apagar\n");
//	printf("3- Contar Elementos\n");
//	printf("4- Imprimir\n");
//	printf("5- Concatenar\n");
//
//	std::cout << std::endl;
//
//	printf("Sua opção: ");
//
//	std::cin >> arg;
//
//	if (ex == false || l == NULL)
//	{
//		l = static_cast<Lista_s_cl*>(malloc(sizeof(Lista_s_cl)));
//		new (l) Lista_s_cl();
//		l->~Lista_s_cl();
//	}
//
//	switch (arg)
//	{
//
//		case static_cast<int>(FuncoesLista::Add) :
//			AddLista_cl(l);
//			OutrasOperacoes();
//			break;
//
//		case static_cast<int>(FuncoesLista::Imprimir) :
//			ImprimirLista(l);
//			OutrasOperacoes();
//			break;
//
//		case static_cast<int>(FuncoesLista::Apagar) :
//			l = ApagarLista(l);
//			OutrasOperacoes();
//			break;
//
//			default:
//				std::cout << "Função não Existe! Digite novamente após pressionar a tecla enter.\n\n";
//				system("PAUSE");
//				system("CLS");
//
//				MenuLista_cl(true);
//				break;
//	}
//
//}

//void OutrasOperacoes()
//{
//	int voltar = 2;
//
//	while (voltar != 0 && voltar != 1) {
//		std::cout << "Deseja Fazer outra operação? 1 - SIM, 2 - NÃO \nSua Resposta: ";
//
//		std::cin >> voltar;
//	}
//
//	if (voltar == 1)
//		MenuLista_cl(true);
//}
//
//void AddLista_cl(Lista_s_cl *l)
//{
//	int valor = 0;
//	bool continuar = true;
//	char opcao = ' ';
//
//	while (continuar)
//	{
//		while (opcao != 'n' && continuar == true)
//		{
//			printf("Digite o valor que deseja adicionar na lista: ");
//			std::cin >> valor;
//
//			l->Add(valor);
//
//
//			printf("Deseja adicionar mais algum valor?\ny - SIM, n - NÃO: ");
//
//			std::cin >> opcao;
//
//			if (opcao == 'y')
//				continuar = true;
//			else
//				continuar = false;
//
//		}
//	}
//
//}
//
//void ImprimirLista(Lista_s_cl* l)
//{
//	if (l->FirstOrDefaut == NULL) {
//		printf("A Lista está vazia!");
//		std::cout << std::endl << std::endl;
//		return;
//	}
//
//	printf("Impressão da lista encadeada.");
//	std::cout << std::endl << std::endl;
//
//	Lista_s_cl::No* no = l->FirstOrDefaut;
//	do
//	{
//		std::cout << no << ": " << no->retornarValor() << std::endl;
//		no = no->proxNo;
//	} while (no != NULL);
//
//	system("PAUSE");
//
//}
//
//Lista_s_cl* ApagarLista(Lista_s_cl *l) 
//{
//	l->ApagarLista();
//	free(l);
//	l = NULL;
//	return l;
//}

