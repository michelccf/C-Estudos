
#include <iostream>

template<class T> class No
{
	No<T>* Prox;
	No<T>* Ant;
	T Dados;
	template<class T> friend class Lista;
};

#pragma once
template<class T> class Lista
{
private: No<T>* First;
private: No<T>* Last;
private: int tamanho;

		 


public: Lista<T>()
{
	First = NULL;
	Last = NULL;
}


public: void Add(T* _dados)
{
	No<T>* novo = static_cast<No<T>*>(malloc(sizeof(No<T>)));
	novo->Dados = *_dados;
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

public: void RemoveAll(int index)
{

	if (First == NULL)
		return;

	No<T>* _no = First;
	No<T>* _temp;
	do
	{
		_temp = _no;
		_no = _no->Prox;
		free(_temp);
	} while (_no->Prox != NULL);
}

public: void RemoveAt(int index)
{
	No<T>* _no = First;
	if (index > 0)
	{
		for (i = 0; i < index; i++)
		{
			_no = _no->Prox;
		}

		if (_no->Ant != NULL)
			_no->Prox->Ant = _no->Ant;
		else
			_no->Prox->Ant = NULL;

		if (_no->Prox != NULL)
			_no->Ant->Prox = _no->Prox;
		else
			_no->Ant->Prox = NUL;
	}
}

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

public: T GetElement(int index)
{

	No<T>* _no = First;
	if (index > 0)
	{
		for (int i = 0; i < index; i++)
		{
			_no = _no->Prox;
		}
	}
	else
		_no = First;

	return _no->Dados;
}

public: T operator[](int index)
{
	return GetElement(index);
}

};
