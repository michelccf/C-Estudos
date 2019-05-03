#include <iostream>;

class No
{

public: int v;
public:  No *proxNo;
public:  No *antNo;

public: No()
{
	this->proxNo = NULL;
	this->antNo = NULL;
}

public: int retornarValor()
{
	return v;
}

public: void editarValor(int valor)
{
	this->v = valor;
}

public: No * proximoNo()
{
	return this->proxNo;
}

public: No * anteriorNo()
{
	return this->proxNo;
}


};

class Lista_s_cl
{
public: No* FirstOrDefaut;
public: No* LastOrDefault;

public: Lista_s_cl()
{
	FirstOrDefaut = NULL;
	LastOrDefault = NULL;
}

public: void Add(int valor)
{
	

	No* novo = static_cast<No*>(malloc(sizeof(No)));
	novo->v = valor;

	novo->antNo = LastOrDefault;
	novo->proxNo = NULL;

	if (LastOrDefault == NULL) {
		FirstOrDefaut = novo;
		LastOrDefault = novo;
	}
	else {
		LastOrDefault->proxNo = novo;
		LastOrDefault = LastOrDefault->proxNo;
	}
}

public: int Count()
{
	No* iterador = FirstOrDefaut;
	int count = 0;
	if (FirstOrDefaut == NULL)
		return 0;
	else
		do 
		{
			count++;
			iterador = iterador->proxNo;
		} while (iterador != LastOrDefault);
		return count;
}

public: void ApagarLista()
{
	No* iterador = FirstOrDefaut;
	No* tmp = FirstOrDefaut;
	if (FirstOrDefaut == NULL)
		return;
	else
		do
		{
			tmp = iterador;
			iterador = iterador->proxNo;
			free(tmp);
		} while (iterador != LastOrDefault);
}

};
