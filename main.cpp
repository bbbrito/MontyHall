#include <stdlib.h>
#include <iostream>
#include <ctime>
using std::cout;
using std::cin;

int main()
{
	int jogadas = 0;
	int permaneceEVence = 0;
	int trocaEVence = 0;
	int portaEscolhida;
	int portaRestante;
	int portaRevelada;
	int portaVencedora;
	int novaEscolha;

	srand (time(NULL));
	portaEscolhida = rand() % 3 + 1;
	portaVencedora = rand() % 3 + 1;

	do
	{
		do
		{
			portaRevelada = rand() % 3 + 1;
		} while (portaRevelada == portaEscolhida || portaRevelada == portaVencedora);

		do
		{
			portaRestante = rand() % 3 + 1;
		} while (portaRestante == portaEscolhida || portaRestante == portaRevelada);

		novaEscolha = rand() % 2 + 1;
		if (novaEscolha == 1)
		{
			if (portaEscolhida == portaVencedora)
			{
				permaneceEVence++;
			}
		}
		if (novaEscolha == 2)
		{
			portaEscolhida = portaRestante;
			if (portaEscolhida == portaVencedora)
			{
			     trocaEVence++;
			}
		}
		jogadas++;
	} while (jogadas < 10000);
	
	float taxaVitPerm = ((float)permaneceEVence / (float)jogadas) * 100.0;
	float taxaVitTroca = ((float)trocaEVence / (float)jogadas) * 100.0;

	cout << "Para 10.000 jogadas, o competidor ganhou " << permaneceEVence << " vezes ao permanecer com sua escolha original, com taxa de acerto de  " << taxaVitPerm << "%.\n";
	cout << "Para 10.000 jogadas, o competidor ganhou " << trocaEVence << " vezes ao trocar sua escolha original, com taxa de acerto de " << taxaVitTroca << "%.\n";
	
	return 0;
}