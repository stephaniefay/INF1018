/* Luis Marcelo Fonseca - 0911762 - 3WB */
/* Marcello Lins - 0910675 - 3WB        */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "definitions.h"

//Definicoes de Constantes
#define PUSH_EBP 0x55
#define MOVL 0x89
#define RET 0xc3
#define CALL 0xe8

// Vetores Estaticos
static unsigned char inicioDeFuncao[] = {PUSH_EBP,0x89,0xe5};
static unsigned char fimDeFuncao[] = {0x89,0xec,0x5d,RET};
static unsigned char callNaoConfigurado[] = {CALL,0xfc,0xff,0xff,0xff};


/*********************************************************
*  Funcao Libera Malloc
*********************************************************/
void libera_func(void * func) {
	free(func);
}

/*********************************************************
*  Funcao Principal
*********************************************************/
void* cria_func (void* f, int n, Parametro params[]) {

	// Variáveis
	int indexaInstrucoes = 0; 
	int contador = 0; 
	int endFuncao;
	int endProximaInstrucao;
	int indiceProximaInstrucao;
	int indiceDepoisDoCall;
	int endCall;
	unsigned char offset = 8;
	unsigned char* pointer;
	unsigned char * codigo = (unsigned char*) malloc(sizeof(unsigned char) * 255); // Tamanho maximo do vetor = 255

/************************
*  Inicio do Código     *
*************************/

	// Adiciona instrucoes Iniciais no vetor de Instrucoes
	for(contador = 0 ; contador < 3 ; contador ++ , indexaInstrucoes++)
	{
		codigo[contador] = inicioDeFuncao[contador];
	} 

	// Para ler os parametros de tras para frente
	for (contador = 0; contador < n ; contador++)
	{
		if (params[contador].e_constante == 0) {
			if (params[contador].tipo == DOUBLE_PAR)
				offset += 8;
			else
				offset += 4;
		}
			
	}
		

	// Loop Principal, empilha os parametros de tras pra frente
	for (contador = n - 1; contador >= 0; contador--) 
	{	

		// Se o parametro for Fixo
		if (params[contador].e_constante) 
		{
			codigo[indexaInstrucoes] = 0xb9; // mov $const, %ecx

			if (params[contador].tipo == INT_PAR)
			{
			
				pointer = (unsigned char*) &params[contador].valor.v_int;
				codigo[indexaInstrucoes + 1] = *(pointer);
				codigo[indexaInstrucoes + 2] = *(pointer + 1); /* Armazenando o int */
				codigo[indexaInstrucoes + 3] = *(pointer + 2);
				codigo[indexaInstrucoes + 4] = *(pointer + 3);

				indexaInstrucoes += 5;

			} /* Primeiro If Interno */ 
			else 
				if (params[contador].tipo == CHAR_PAR) 
				{
				
					pointer = (unsigned char*)&params[contador].valor.v_char;
					codigo[indexaInstrucoes + 1] = *(pointer); // Armazenando o char 
					codigo[indexaInstrucoes + 2] = 0;
					codigo[indexaInstrucoes + 3] = 0; // Zeramos os paddings
					codigo[indexaInstrucoes + 4] = 0;
					indexaInstrucoes += 5;

				} /* Segundo If Interno*/
			else
				if (params[contador].tipo == PTR_PAR) 
				{
				
					pointer = (unsigned char*)&params[contador].valor.v_ptr;
					codigo[indexaInstrucoes + 1] = *(pointer);
					codigo[indexaInstrucoes + 2] = *(pointer + 1); /* Armazenando o ponteiro */
					codigo[indexaInstrucoes + 3] = *(pointer + 2);
					codigo[indexaInstrucoes + 4] = *(pointer + 3);

					indexaInstrucoes += 5;

				} /* Terceiro If Interno*/
			else
				if (params[contador].tipo == DOUBLE_PAR) 
				{

					pointer = (unsigned char*)&params[contador].valor.v_double;
					
					codigo[indexaInstrucoes + 1] = *(pointer + 4);
					codigo[indexaInstrucoes + 2] = *(pointer + 5); /* Armazenando o double */
					codigo[indexaInstrucoes + 3] = *(pointer + 6);
					codigo[indexaInstrucoes + 4] = *(pointer + 7); /* Salva em ordem de dois ints inversos */

					codigo[indexaInstrucoes + 5] = 0x51; // Push %ecx
					codigo[indexaInstrucoes + 6] = 0xb9; // Mov $const, %ecx

					codigo[indexaInstrucoes + 7] = *(pointer + 0); /* mov $constant, %ecx */
					codigo[indexaInstrucoes + 8] = *(pointer + 1);
					codigo[indexaInstrucoes + 9] = *(pointer + 2); /* Precisa dar dois push */
					codigo[indexaInstrucoes + 10] = *(pointer + 3);

					indexaInstrucoes += 11;

				} /* Quarto If Interno*/
			else 
				printf("Erro - Tipo indefinido\n");
				
			codigo [indexaInstrucoes] = 0x51; // Push %ecx
			indexaInstrucoes++;

		} /* If Externo */
		else // Se Parametro Não For Fixo
		{
			if(params[contador].tipo == INT_PAR)
			{
			
				offset -= 4;
				codigo[indexaInstrucoes + 0] = 0x8b; // mov offset(%ebp), %ecx 
				codigo[indexaInstrucoes + 1] = 0x4d;
				codigo[indexaInstrucoes + 2] = offset;
				
				
				indexaInstrucoes += 3;
			} /* Primeiro If Interno*/
			else
				if(params[contador].tipo == CHAR_PAR)
				{
				
					offset -= 4;
					codigo[indexaInstrucoes + 0] = 0x31; // xor %ecx, %ecx
					codigo[indexaInstrucoes + 1] = 0xc9; // Precisa zerar o parametro, mas está errado
					codigo[indexaInstrucoes + 2] = 0x8b; // mov offset(%ebp), %ecx 
					codigo[indexaInstrucoes + 3] = 0x4d;
					codigo[indexaInstrucoes + 4] = offset;
					
					
					
					indexaInstrucoes += 5;
				} /* Segundo If Interno*/
			else
				if(params[contador].tipo == PTR_PAR)
				{
				
					offset -= 4;
					codigo[indexaInstrucoes + 0] = 0x8b; // mov offset(%ebp), %ecx 
					codigo[indexaInstrucoes + 1] = 0x4d;
					codigo[indexaInstrucoes + 2] = offset;
					
					
					
					indexaInstrucoes += 3;
				} /* Terceiro If Interno*/
			else
				if(params[contador].tipo == DOUBLE_PAR)
				{
					
					// Primeira parte do double
					offset -= 4;
					codigo[indexaInstrucoes + 0] = 0x8b; // mov offset(%ebp), %ecx 
					codigo[indexaInstrucoes + 1] = 0x4d;
					codigo[indexaInstrucoes + 2] = offset; // Precisa ser ao contrario!
					codigo[indexaInstrucoes + 3] = 0x51; // Push %ecx
					

					offset -= 4; // 
					// Segunda parte do double
					codigo[indexaInstrucoes + 4] = 0x8b; // mov offset(%ebp), %ecx 
					codigo[indexaInstrucoes + 5] = 0x4d;
					codigo[indexaInstrucoes + 6] = offset; // Precisa ser ao contrario!				


					indexaInstrucoes += 7;
				} /* Quarto If Inferno*/

			codigo[indexaInstrucoes] = 0x51;
			indexaInstrucoes++;
		} /* Else Externo*/

	} /* Loop Principal */


	    // Configurando o Endereço do Call
		for(contador = 0 ; contador < 5 ; contador++,indexaInstrucoes++)
		{
			codigo[indexaInstrucoes] = callNaoConfigurado[contador];
		}

		// Desempilhando, Tirando o EBP da Pilha e RETORNO
		for(contador = 0 ; contador < 4 ; contador++,indexaInstrucoes++)
		{
			codigo[indexaInstrucoes] = fimDeFuncao[contador];
		}

		//Procurando indice da próxima instrucao depois do CALL
		contador=0;
		while(codigo[contador]!= CALL)
		{
			contador++;
		}
		indiceProximaInstrucao = contador+5;
		indiceDepoisDoCall = contador + 1;
		//printf("\n****************************************");
		//printf("\nIndice da Instrucao depois do Call : %d",indiceProximaInstrucao);

		// Arrumando o Call
		endFuncao = (int)f;
		endProximaInstrucao = (int)&codigo[indiceProximaInstrucao];
		endCall = endFuncao - endProximaInstrucao;
		//printf("\nEndereco da Funcao : %x",endFuncao);
		//printf("\nEndereco da Proxima Instrucao : %x",endProximaInstrucao);
		//printf("\nEndereco do Call (offset) : %x",endCall);
		//printf("\n****************************************\n");

		*((int*) &codigo[indiceDepoisDoCall]) = endCall; // Casting do Endereco da proxima instrucao,para int* recebendo o endereco certo
	
	// Testando o Vetor de Instrucoes
	//traduzAssembly(codigo,indexaInstrucoes);
	imprimeInstrucoes(codigo,indexaInstrucoes);
	// Comentei as funções acima para que ficasse menos sobrecarregado
	// e para facilitar a leitura da saida do programa

	return codigo;
}

/*************************************************
* Faz o parsing do Conteúdo do Vetor de Codigo
* Traduzindo Código de máquina para a Assembly 
* em Nossa Lingua Natal Tupiniquim :)
*************************************************/
void traduzAssembly(unsigned char* codigo,int tamanho)
{
	int contador = 0 ;

	for( ; contador < tamanho ; contador ++)
	{
		switch(codigo[contador])
		{
			case PUSH_EBP:
				printf("\nPUSH EBP");
			break;

			case MOVL:
				if(codigo[contador+1] == 0xe5)	
				{
					printf("\nMOVL ESP,EBP");
					contador++;
				}
				else
					if(codigo[contador+1] == 0xec)
					{
					printf("\nMOVL EBP,ESP");
					contador++;
					}
					else
						printf("\nMOVL ");
			break;

			case CALL:
				contador++;
				printf("\nCALL %x %x %x %x",codigo[contador],codigo[contador+1],codigo[contador+2],codigo[contador+3]);
				contador = contador + 3;
			break;

			case RET:
				printf("\nRET");
			break;

			case 0xb9:
				printf("\nMOVL UMA CONSTANTE");
			break;

			case 0x51:
				printf("\nPUSH ECX");
			break;

			default:
				printf("\n Instrucao Sem Tratamento : %x",codigo[contador]);
		    break;

		} /* switch*/

	} /* for */

	printf("\n\n==== Fim da Funcao de Traducao ====\n\n");
}


/*************************************************
* Imprime o código de máquina de cada instrucao
* com um índice antes(que é o indice no vetor de 
* codigo). Ajuda a conferir a implementacao
*************************************************/
void imprimeInstrucoes(unsigned char* codigo,int tam)
{
	int contador = 0 ;
	printf("\n**********************************************\n");
	while(contador<tam)
	{
		printf("\n%d - %x",contador,codigo[contador]);
		contador++;
	}
	return ;
}


