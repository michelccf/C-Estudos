
#include <iostream>

template<class T> class No
{
	No<T>* Prox;
	No<T>* Ant;
	T Dados;
	template<class T> friend class Lista;

public: No<T>()
	{
		T* newDados = (static_cast<T*>(malloc(sizeof(T))));
		new (newDados) T();
		this->Dados = *newDados;
		
	}
};

#pragma once
template<class T> class Lista
{
private: No<T>* First;
private: No<T>* Last;
private: int tamanhoBytes;
private: int length;




public: Lista<T>()
{
	First = NULL;
	Last = NULL;
}


public: void Add(T* _dados)
{
	No<T>* novo = static_cast<No<T>*>(malloc(sizeof(No<T>)));
	new(novo) No<T>();
	novo->Dados = *_dados;
	novo->Prox = NULL;

	if (First == NULL)
	{
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
		free(_temp->Dados);
		free(_temp);
	} while (_no->Prox != NULL);
}

public: Lista<T> RemoveAt(int index)
{
	No<T>* _no = First;
	if (index > 0)
	{
		for (int i = 0; i < index; i++)
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
			_no->Ant->Prox = NULL;
	}
	return *this;
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
	tamanhoBytes = 0;
	do
	{
		tamanhoBytes += sizeof(_no);
		_no = _no->Prox;
	} while (_no->Prox != NULL);

	return tamanhoBytes;
}

public: int Count()
{
	No<T>* _no = First;
	length = 0;
	do
	{
		length++;
		_no = _no->Prox;
	} while (_no->Prox != NULL);
	return length;
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
