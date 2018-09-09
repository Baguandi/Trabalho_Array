// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include "string"

using namespace std;

int bubblesort(int vetor[], int posicoes_vetor, int movimentos) {
	int aux, tempo_total;
	clock_t tempo;

	tempo = clock();
	for (int i = 0; i<posicoes_vetor; i++) {
		for (int j = 0; j<posicoes_vetor -1-i; j++) {
			if (vetor[j]>vetor[j + 1]) {
				aux = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = aux;
				movimentos++;
			}
		}
	}
	

	printf ("Tempo: %.2f \n", (clock() - tempo) *10 / (double)CLOCKS_PER_SEC);

	return movimentos;
}

int SelectionSort(int vetor[],int posicoes_vetor, int movimentos)
{
	int menor_posicao, aux, tempo_total;
	clock_t tempo;
	tempo = clock();
	for (int i = 0; i < posicoes_vetor-1; i++) 
	{
		menor_posicao = i;
		for (int j = i + 1; j < posicoes_vetor; j++) 
		{
			if (vetor[menor_posicao] > vetor[j])
				menor_posicao = j;
		}

		if (i != menor_posicao) 
		{
			aux = vetor[i];
			vetor[i] = vetor[menor_posicao];
			vetor[menor_posicao] = aux;
			movimentos++;
		}
	}
	printf("Tempo: %.2f \n", (clock() - tempo) * 10 / (double)CLOCKS_PER_SEC);

	return (movimentos);
}

int InsertionSort(int vetor[], int posicoes_vetor, int movimentos)
{	
	int aux, tempo_total;
	clock_t tempo;
	tempo = clock();
	for (int i = 0; i < posicoes_vetor - 1; i++)
	{
		for (int j = i + 1; j > 0; j--)
		{
			if (vetor[j] < vetor[j - 1])
			{
				aux = vetor[j];
				vetor[j] = vetor[j - 1];
				vetor[j - 1] = aux;
				movimentos++;
			}
		}
	}
	printf("Tempo: %.2f \n", (clock() - tempo) * 10 / (double)CLOCKS_PER_SEC);

	return(movimentos);
}

int ShellSort(int vetor[], int posicoes_vetor, int movimentos)
{
	int aux, i, j, tempo_total;
	clock_t tempo;
	int h = posicoes_vetor / 2;
	tempo = clock();
	while (h > 0) 
	{
		i = h;
		while (i < posicoes_vetor) 
		{
			aux = vetor[i];
			j = i;
			while (j >= h && aux < vetor[j - h]) 
			{
				vetor[j] = vetor[j - h];
				j = j - h;
			}

			vetor[j] = aux;
			i = i + 1;
			movimentos++;
		}
		h = h / 2;
	}
	printf("Tempo: %.2f \n", (clock() - tempo) * 10 / (double)CLOCKS_PER_SEC);

	return(movimentos);
}

int QuickSort(int vetor[], int menor_valor, int maior_valor, int movimentos)
{

	int i = menor_valor;
	int j = maior_valor;
	int aux_1 = vetor[(i + j) / 2];
	int aux, tempo_total;
	clock_t tempo;

	tempo = clock();

	while (i <= j)
	{
		while (vetor[i] < aux_1)
			i++;
		while (vetor[j] > aux_1)
			j--;
		if (i <= j)
		{
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
			movimentos++;
		}
	};

	if (j > menor_valor) {
		QuickSort(vetor, menor_valor, j, movimentos);
	}
	
	if (i < maior_valor) {
		QuickSort(vetor, i, maior_valor, movimentos);
	}
	
	return movimentos;
}

int gnomeSort(int vetor[], int posicoes_vetor, int movimentos) {
	int i = 0, aux, tempo_total;
	clock_t tempo;

	tempo = clock();
	while (i < posicoes_vetor) {
		if (i == 0)
			i++;
		if (vetor[i] >= vetor[i - 1])
			i++;
		else {
			aux = vetor[i];
			vetor[i] = vetor[i - 1];
			vetor[i - 1] = aux;
			i--;
			movimentos++;
		}
	}
	printf("Tempo: %.2f \n", (clock() - tempo) * 10 / (double)CLOCKS_PER_SEC);

	return movimentos;
}

int menu() {

	system("cls");

	const int posicoes_vetor = 30000;
	int vetor[posicoes_vetor];
	int operador, exibir, movimentos = 0, again;

	srand(time(NULL));

	for (int i = 0; i < posicoes_vetor; i++) 
	{
		vetor[i] = rand() % 500;
	}

	cout << endl << "Seu vetor esta pronto para ser ordenado \nDeseja exibir o vetor de 30000 posicoes? : " << endl << "1 - Sim \n2 - Nao : ";
	cin >> exibir;
	
	cout << endl;
	if (exibir == 1)
	{
		for (int i = 0; i < posicoes_vetor; i++)
		{
			cout << vetor[i] << "\t";
		}
	}

	cout << endl << "Escolha um Sort: \n1 - BoubbleSort \n2 - QuickSort \n3 - SelectioSort \n4 - InsertionSort \n5 - ShellSort \n6 - GnomeSort \n: " << endl;
	cin >> operador;

	if (operador == 1)
		cout << "Movimentos : " << bubblesort(vetor, posicoes_vetor, movimentos) << endl;
	else if (operador == 2)
		cout << "Movimentos : " << QuickSort(vetor, 0, posicoes_vetor, movimentos) << endl;
	else if (operador == 3)
		cout << "Movimentos : " << SelectionSort(vetor, posicoes_vetor, movimentos) << endl;
	else if (operador == 4)
		cout << "Movimentos : " << InsertionSort(vetor, posicoes_vetor, movimentos) << endl;
	else if (operador == 5)
		cout << "Movimentos : " << ShellSort(vetor, posicoes_vetor, movimentos) << endl;
	else if (operador == 6)
		cout << "Movimentos : " << gnomeSort(vetor, posicoes_vetor, movimentos) << endl;

	system("pause");
	system("cls");

	cout << "O programa terminou, deseja executar novamente?\n1 - Sim \n2 - Nao \n: ";
	cin >> again;

	if (again == 1)
		menu();
	else
		return 0;
}

int main()
{
	menu();

	system("pause");
	return 0;
}