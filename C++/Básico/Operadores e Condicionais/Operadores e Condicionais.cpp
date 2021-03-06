// Operadores e Condicionais.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

using namespace std;
#include <iostream>

#include <locale.h>

void Media_simples();

void SomaVetorial_NaoDinamico();

void ConcatenacaoVetorial_NaoDinamico();

void MatrizQuadrada_NaoDinamica();

void MultiplicacaoMatrizes_NaoDinamicas();

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
	printf("1- Média Simples de três valores.\n");
	printf("2- Soma vetorial entre 2 vetores.\n");
	printf("3- Concatenação vetorial entre 2 vetores.\n");
	printf("4- Soma entre 2 matrizes 2x2.\n");
	printf("5- Multiplicacao entre 2 matrizes.\n");

	printf("\n");

	printf("Sua opção: ");

	cin >> arg;

	switch (arg)
	{
		case static_cast<int>(Funcoes::Media) :
			Media_simples();
			break;

		case static_cast<int>(Funcoes::SomaVetorialNaoDinamico) :
			SomaVetorial_NaoDinamico();
			break;

		case static_cast<int>(Funcoes::ConcatenacaoVetorialNaoDinamico) :
			ConcatenacaoVetorial_NaoDinamico();
			break;

		case static_cast<int>(Funcoes::MatrizQuadradaNaoDinamica) :
			MatrizQuadrada_NaoDinamica();
		break;

		case static_cast<int>(Funcoes::MultiplicacaoMatrizesNaoDinamicas) :
			MultiplicacaoMatrizes_NaoDinamicas();
		break;


		default:
			cout << "Função não Existe! Digite novamente após pressionar a tecla enter.\n\n";
			system("PAUSE");
			system("CLS");

			main();

			break;
	}
}

void Media_simples()
{
	int a, b, c;
	float media = 0;

	printf("Digite 3 valores e pressione enter consecultivamente para serem somados e então exibir sua média.\n\n");

	printf("Valor: ");
	cin >> a;
	printf("Valor: ");
	cin >> b;
	printf("Valor: ");
	cin >> c;

	media = (a + b + c) / 3;

	cout << "Resultado da média dos números digitados é: " << media << "\n";
	system("PAUSE");
}

void SomaVetorial_NaoDinamico()
{
	int vetor1[5];
	int vetor2[5];
	int vetor3[5] = { 0,0,0,0,0 };

	printf("Digite os valores dos vetores e pressione enter, ao final, será somado os 2 vetores.\n\n");

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++)
		{
			if (i == 0)
			{
				printf("Valor[%d] do vetor %d: ", i + 1, j + 1);
				cin >> vetor1[j];
			}
			if (i == 1)
			{
				printf("Valor[%d] do vetor %d: ", i + 1, j + 1);
				cin >> vetor2[j];
			}
		}
	}

	cout << "A soma vetorial entre o vetor 1 e 2 é: \n\n";

	for (int i = 0; i < 5; i++)
	{
		vetor3[i] = vetor1[i] + vetor2[i];
		cout << vetor3[i] << "\t";
	}

	cout << "\n\n";

	system("PAUSE");

}

void ConcatenacaoVetorial_NaoDinamico()
{
	int vetor1[5];
	int vetor2[5];
	int vetor3[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int contador = 0;

	printf("Digite os valores dos vetores e pressione enter, ao final, será concatenado os 2 vetores.\n\n");

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++)
		{
			if (i == 0)
			{
				printf("Valor[%d] do vetor %d: ", i + 1, j + 1);
				cin >> vetor1[j];
			}
			if (i == 1)
			{
				printf("Valor[%d] do vetor %d: ", i + 1, j + 1);
				cin >> vetor2[j];
			}
		}
	}

	cout << "A concatenação vetorial entre o vetor 1 e 2 é: \n\n";

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			vetor3[i] = vetor1[contador];
		else
		{
			vetor3[i] = vetor2[contador];
			contador++;
		}

		if (contador > 4)
			contador = 0;

		cout << vetor3[i] << "\t";
	}

	cout << "\n\n";

	system("PAUSE");
}

void MatrizQuadrada_NaoDinamica()
{
	int matriz1[2][2];
	int matriz2[2][2];
	int matriz3[2][2];

	printf("Digite os valores das matrizes e pressione enter, ao final, será somado as 2 matrizes.\n\n");

	for(int k = 0; k < 2 ; k ++)
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (k == 0)
				{
					printf("Valor[%d][%d] da matriz %d: ", i + 1, j + 1, k + 1);
					cin >> matriz1[i][j];
				}
				if (k == 1)
				{
					printf("Valor[%d][%d] da matriz %d: ", i + 1, j + 1, k + 1);
					cin >> matriz2[i][j];
				}
			}
		}

	cout << "A soma entre as matrizes 1 e 2 é: \n\n";

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
			cout << matriz3[i][j] << "\t";
		}
	}

	cout << "\n\n";

	system("PAUSE");
}

void MultiplicacaoMatrizes_NaoDinamicas()
{
	int matriz1[2][3];
	int matriz2[3][2];
	int matriz3[2][2] = {0,0,0,0};
	int multicplicador = 0;
	int linha = 0, coluna = 0;
	int colunaM2 = 0;

	printf("Digite os valores das matrizes e pressione enter, ao final, será somado as 2 matrizes.\n\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("Valor[%d][%d] da matriz 1: ", i + 1, j + 1);
			cin >> matriz1[i][j];
		}
	}
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("Valor[%d][%d] da matriz 2: ", i + 1, j + 1);
			cin >> matriz2[i][j];
		}
	}

	cout << "A Multiplicacao entre as matrizes 1 e 2 é: \n\n";

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
			}
		}
	}
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << matriz3[i][j] << "\t";
		}
	}
			
	system("PAUSE");

	cout << "\n\n";

}
