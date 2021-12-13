#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h> 

void ExibirAnimais(int animal);
int UltimosDoisDigitos(int n); 
int ValidarGanhadorAnimal(int numerosSorteados[4], char apostaAnimal[10], int opcaoSorteio);
int ValidarGanhadorDezena(int numerosSorteados[4], int apostaDezena, int opcaoSorteio);
void PopularDezenasPorAnimal (char apostaAnimal[10], int dezenaAnimal[10]);

int main()
{
	setlocale(LC_ALL, "portuguese");
	srand(time(0));
	
	int opcaoAposta, apostaDezena, opcaoSorteio, opcaoResultado, i, numerosSorteados[4], opcErrada = 1;;
	char iniciar, apostaAnimal[10];
	float valorAposta, resultadoGanho;
	
	printf("---------------------------------Bem-Vindo ao Jogo do Bicho---------------------------------\n");
	
	printf("\nComo jogar o Jogo do Bicho?\n");
	printf("\nPara jogar o jogo do bicho, basta escolher um dos dois tipos de apostas a disposição.\n"
			"Na primeira aposta, você escolherá um animal, o qual tem 10 dezenas relacionadas a ele.\n"
			"\nNomes dos animais disponíveis para aposta: avestruz, borboleta, cachorro, elefante, gato, macaco, porco, tigre, urso e vaca.\n");
	
	printf("\nNa segunda aposta, você escolhe uma dezena entre 00 e 99 para apostar.\n"
			"Após definida a aposta, você precisará digitar o valor da aposta e escolher se deseja participar do 1° sorteio ou do 2° ao 4° sorteio.\n"
			"Feito isso, é só aguardar o sorteio para conferir os resultados.\n\n");
	
	printf("-----------------------------------------------------------------------------------------------");
	printf("\n\nPronto para apostar?\n");
	printf("\nSe estiver preparado pressione ENTER");
	
	do 
	{
		iniciar = getch();
	} while (iniciar != 13);
	
	system("cls");

	do 
	{
		printf("\nSelecione 1 para apostar no ANIMAL ou selecione 2 para apostar na DEZENA: ");
		scanf("%i", &opcaoAposta);
		
		switch(opcaoAposta) 
		{ 
			case 1:
				printf("\n\nDigite o nome do ANIMAL a qual você deseja apostar: ");
				scanf("%s", &apostaAnimal);
				
				printf("Digite o valor que você deseja apostar: ");
				scanf("%f", &valorAposta);
				
				opcErrada = 0;
				break;
			
			case 2:
				printf("\n\nDigite a DEZENA (00 a 99) na qual você deseja apostar: ");
				scanf("%i", &apostaDezena); 
				
				printf("Digite o valor que você deseja apostar: ");
				scanf("%f", &valorAposta);
				
				opcErrada = 0;
				break;
			
			default :
				printf("\nOpção incorreta!! Digite novamente.\n");
				opcErrada = 1;
		}
	} while (opcErrada == 1);
	
	do 
	{
		printf("\nQual sorteio você deseja concorrer?");
		printf("\nDigite 1 para concorrer ao 1° SORTEIO ou digite 2 para concorrer do 2° ao 4° SORTEIO   ");
		scanf("%i", &opcaoSorteio);
		
		switch(opcaoSorteio) {
			case 1:
				printf("\nVocê está concorrendo ao 1° Sorteio!");
				opcErrada = 0;
				break;
				
			case 2:
				printf("\nVocê está concorrendo do 2° Sorteio ao 4° Sorteio!");
				opcErrada = 0;
				break;	
				
			default :
				printf("\nOpção incorreta!! Digite novamente.\n");
				opcErrada = 1;			
		}
	} while (opcErrada == 1);
	
	printf("\n\n---------------------------------Aposta feita com sucesso!!!---------------------------------\n");
	
	printf("\nPressione ENTER para conferir os resultados!");
	
	do {
		iniciar = getch();
	} while (iniciar != 13);
	
	system("cls");	
	 
	printf("-------------------------Gerando números para o sorteio-------------------------\n");
	 	
	for(i = 0; i < 4; i++)
	{
		numerosSorteados[i] = 1000 + rand() % 9999;
		
		//if(i == 3)
		//{
		//	numerosSorteados[i] = 1569;
		//}
		
		printf("\n%i° Sorteio %i - " , i + 1, numerosSorteados[i]);
		ExibirAnimais(numerosSorteados[i]);
	}
	
	printf("\n\n----------------------------------Resultados----------------------------------\n");
	
	if(opcaoAposta == 1) //animal
	{
		if(opcaoSorteio == 1)//cabeça
		{
			int ganhador = ValidarGanhadorAnimal(numerosSorteados, apostaAnimal, opcaoSorteio);
			if(ganhador == 1)
			{
				resultadoGanho = valorAposta * 18;
				printf("\nParabéns!! Você ganhou %.2f reais no Jogo do Bicho!\n", resultadoGanho);
			}
			else
			{
				printf("\nNão foi dessa vez que você ganhou no Jogo do Bicho! Boa sorte na próxima!\n");
			}
		}
		else // corpo
		{
			int ganhador = ValidarGanhadorAnimal(numerosSorteados, apostaAnimal, opcaoSorteio);
			if(ganhador == 1)
			{
				resultadoGanho = valorAposta * 3.6;
				printf("\nParabéns!! Você ganhou %.2f reais no Jogo do Bicho!\n", resultadoGanho);
			}
			else
			{
				printf("\nNão foi dessa vez que você ganhou no Jogo do Bicho! Boa sorte na próxima!\n");
			}
		}
	} 
	else //dezena
	{
		if(opcaoSorteio == 1) //cabeça
		{
			int ganhador = ValidarGanhadorDezena(numerosSorteados, apostaDezena, opcaoSorteio);
			if(ganhador == 1)
			{
			 	resultadoGanho = valorAposta * 60;
				printf("\nParabéns!! Você ganhou %.2f reais no Jogo do Bicho!\n", resultadoGanho);
			}
			else 
			{
				printf("\nNão foi dessa vez que você ganhou no Jogo do Bicho! Boa sorte na próxima!\n");
			}
		} 
		else //corpo
		{
			int ganhador = ValidarGanhadorDezena(numerosSorteados, apostaDezena, opcaoSorteio);
			if(ganhador == 1)
			{
				resultadoGanho = valorAposta * 12;
				printf("\nParabéns!! Você ganhou %.2f reais no Jogo do Bicho!\n", resultadoGanho);	
			}
			else 
			{
				printf("\nNão foi dessa vez que você ganhou no Jogo do Bicho! Boa sorte na próxima!\n");
			}
		} 
	}	
	return 0;
}  

void ExibirAnimais (int animal)
{
	animal = UltimosDoisDigitos(animal);
	if (animal >= 0 && animal <= 9)
	{
		printf("avestruz");
	}
	
	else if  (animal >= 10 && animal <= 19)
	{
		printf("borboleta");
	}
	
	else if (animal >= 20 && animal <= 29)
	{
		printf("cachorro");
	}
	
	else if (animal >= 30 && animal <=39)
	{
		printf("elefante");
	}
	
	else if (animal >= 40 && animal <=49)
	{
		printf("gato");
	}
	
	else if (animal >= 50 && animal <=59)
	{
		printf("macaco");
	}
	
	else if (animal >= 60 && animal <=69)
	{
		printf("porco");
	}
	
	else if (animal >= 70 && animal <=79)
	{
		printf("tigre");
	}
	
	else if (animal >= 80 && animal <=89)
	{
		printf("urso");
	}
	
	else if (animal >= 90 && animal <=99)
	{
		printf("vaca");
	}
}

int UltimosDoisDigitos(int n) 
{
	int temp = n % 100;
	return temp;
}

void PopularDezenasPorAnimal(char apostaAnimal[10], int dezenaAnimal[10])
{
	int i, animal = 0;
	
	if (strcmp(apostaAnimal, "avestruz") == 0)
	{
		for(i = 0; i < 10; i++)
		{
			dezenaAnimal[i] = i;
		}
	}
	else if (strcmp(apostaAnimal, "borboleta") == 0)
	{
		for(i = 0; i < 10; i++)
		{
			dezenaAnimal[i] = i + 10;
		}
	}
	else if (strcmp(apostaAnimal, "cachorro") == 0)
	{
		for(i = 0; i < 10; i++)
		{
			dezenaAnimal[i] = i + 20;
		}
	}
	else if (strcmp(apostaAnimal, "elefante") == 0)
	{
		for(i = 0; i < 10; i++)
		{
			dezenaAnimal[i] = i + 30;
		}
	}
	else if (strcmp(apostaAnimal, "gato") == 0)
	{
		for(i = 0; i < 10; i++)
		{
			dezenaAnimal[i] = i + 40;
		}
	}
	else if (strcmp(apostaAnimal, "macaco") == 0)
	{
		for(i = 0; i < 10; i++)
		{
			dezenaAnimal[i] = i + 50;
		}
	}
	else if (strcmp(apostaAnimal, "porco") == 0)
	{
		for(i = 0; i < 10; i++)
		{
			dezenaAnimal[i] = i + 60;
		}
	}
	else if (strcmp(apostaAnimal, "tigre") == 0)
	{
		for(i = 0; i < 10; i++)
		{
			dezenaAnimal[i] = i + 70;
		}
	}
	else if (strcmp(apostaAnimal, "urso") == 0)
	{
		for(i = 0; i < 10; i++)
		{
			dezenaAnimal[i] = i + 80;
		}
	}
	else if (strcmp(apostaAnimal, "vaca") == 0)
	{
		for(i = 0; i < 10; i++)
		{
			dezenaAnimal[i] = i + 90;
		}
	}
}

int ValidarGanhadorAnimal(int numerosSorteados[4], char apostaAnimal[10], int opcaoSorteio)
{
	int dezenaAnimal[10], i,j;
	int ganhador = 0;
	PopularDezenasPorAnimal(apostaAnimal, dezenaAnimal);
	
	for(i = 0; i < 4; i++)
	{
		numerosSorteados[i] = UltimosDoisDigitos(numerosSorteados[i]);
	}
	
	if(opcaoSorteio == 1)
	{
		for(j = 0; j < 10; j++)
		{
			if(numerosSorteados[0] == dezenaAnimal[j])
			{
				ganhador = 1;
			}
		}
	}
	else
	{
		for(i = 1; i < 4; i++)
		{
			for(j = 0; j < 10; j++)
			{
				if(numerosSorteados[i] == dezenaAnimal[j])
				{
					ganhador = 1;
				}
			}
		}
	}
	return ganhador;
}


int ValidarGanhadorDezena(int numerosSorteados[4], int apostaDezena, int opcaoSorteio)
{
	int i;
	int ganhador = 0;
	
	for(i = 0; i < 4; i++)
	{
		numerosSorteados[i] = UltimosDoisDigitos(numerosSorteados[i]);
	}
	
	if(opcaoSorteio == 1)
	{
		if(numerosSorteados[0] == apostaDezena)
		{
			ganhador = 1;
		}
	}
	else 
	{	
		for(i = 1; i < 4; i++)
		{
			if(numerosSorteados[i] == apostaDezena)
			{
				ganhador = 1;
			}
		}
	}
	return ganhador;
}
