#include <iostream>
template<class T>
class No 
{
	No<T>* Prox;
	No<T>* Ant;
	T Dados;
};

template<class T>
class Lista 
{
private: No<T>* First;
private: No<T>* Last;
private: int tamanho;

public: Lista() 
{
	First = NULL;
	Last = NULL;
}

public: void Add(T _dados) 
{
	No<T>* novo = static_cast<No<T>*>(malloc(sizeof(No<T>)));
	novo->Dados = _dados;
	novo->Prox = NULL;

	if (First == NULL)
	{
		No<T>* novo = static_cast<No<T>*>(malloc(sizeof(No<T>)));
		novo->Ant = NULL;
		First = novo;
		Last = novo;
	}
	else
	{
		novo->Ant = Last;
		Last->Prox = novo;
		Last = novo;
	}
};

public: T FirstOrDefault()
{
	return First->Dados;
}

public: T LastOrDefault()
{
	return Last->Dados;
}

public: float Size()
{
	No<T>* _no = First;
	tamanho = 0;
	do 
	{
		tamanho += sizeof(_no);
	} while (_no->Prox != NULL);

	return tamanho;
}




};
