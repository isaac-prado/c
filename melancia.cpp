// simulador de plantação de melancia
// isaac do prado almeida

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int semente=0;
int agua=5;
int adubo=5;
int jogadas=0;
int dia;
const char* area[25][50];

void inicializa(){
	int cont=0,i,j; // em branco
	for(int i=0; i<=25; i++){
		for(int j=0; j<=50;j++){
			area[i][j] = " ";
		}
	}
	do{ // 2x2
		i = (rand()%23)+1;
		j = (rand()%48)+1;
		if(area[i][j] != "^" && area[i+1][j] != "^" && area[i][j+1] != "^" && area[i+1][j+1] != "^"){
			area[i][j] = "^";
			area[i+1][j] = "^";
			area[i][j+1] = "^";
			area[i+1][j+1] = "^";
			cont++;
		}
	} while(cont<3);
	
	cont=0; // zerar o contador
	
	do{ // 3x3
		i = (rand()%22)+1;
		j = (rand()%47)+1;
		if(area[i][j] != "^" && area[i+1][j] != "^" && area[i][j+1] != "^" && area[i+1][j+1] != "^" && area[i+2][j] != "^" && area[i+2][j+1] != "^" && 	area[i][j+2] != "^" && area[i+1][j+2] != "^" && area[i+2][j+2] != "^"){
			area[i][j] = "^";
			area[i+1][j] = "^";
			area[i][j+1] = "^";
			area[i+1][j+1] = "^";
			area[i+2][j] = "^";
			area[i+2][j+1] = "^";
			area[i][j+2] = "^";
			area[i+1][j+2] = "^";
			area[i+2][j+2] = "^";
			cont++;
		}
	} while(cont<2);
	
	cont=0;
	
	do{
		i= (rand()%24)+1;
		j= (rand()%49)+1;
		if(area[i][j] != "^"){
			area[i][j] = "i";
			cont++;
		}
	} while(cont<10);
	
}

void imprime(){
	int i,j;
	printf("\nDIA %d:\n", dia+1);
	printf("    ");   // colunas superiores dezenas
	for(j=0;j<50;j++){
		if(j<10){
			printf(" ");
		} else
		if(j<20){
			printf("1");
		} else
		if(j<30){
			printf("2");
		} else
		if(j<40){
			printf("3");
		} else
		if(j<50){
			printf("4");
		}
	}
	printf("\n");

	printf("    ");   // colunas superiores numerais
	for(j=0;j<5;j++){
		for(i=0;i<10;i++){
			printf("%d",i);
		}
	}
	printf("\n");
	
	for(i=0;i<25;i++){   // linhas nas laterais
		if(i<10){
			printf("[0%d]",i);
		} else{
			printf("[%d]",i);
		}
		for(j=0;j<51;j++){
			if(j!=50){
				printf("%s",area[i][j]);
			} else{
				if(i<10){
					printf("[0%d]",i);
				} else{
					printf("[%d]",i);
				}
			}
		}
		printf("\n");
	}
	
	printf("    ");   // colunas inferiores dezenas
	for(j=0;j<50;j++){
		if(j<10){
			printf(" ");
		} else
		if(j<20){
			printf("1");
		} else
		if(j<30){
			printf("2");
		} else
		if(j<40){
			printf("3");
		} else
		if(j<50){
			printf("4");
		}
	}
	printf("\n");
	
	printf("    ");   // colunas inferiores numerais
	for(j=0;j<5;j++){
		for(i=0;i<10;i++){
			printf("%d",i);
		}
	}
	printf("\n");
	
	printf("\nsemente = %d / agua = %d / adubo = %d\n", semente, agua, adubo);
}

void irrigar(){
	int lin,col;
	
	if(agua>0){
		printf("IRRIGAR[linha]: ");
		scanf("%d", &lin);
		printf("IRRIGAR[coluna]: ");
		scanf("%d", &col);
		if(col<50 && lin<25 && area[lin][col] == " "){	
		area[lin][col] = "~";
		agua--;
	    } else{
	    	printf("\nATENCAO: posicao invalida na matriz ou ja usada!\n");
		}
		jogadas++;
	}
	else{
		printf("\nATENCAO: nao possui saldo de agua!\n");
	}
}

void semear(){
	int lin,col;
	
	if(semente>0){
		printf("SEMEAR[linha]: ");
		scanf("%d", &lin);
		printf("SEMEAR[coluna]: ");
		scanf("%d", &col);
		if(col<50 && lin<25 && area[lin][col] != "i" && area[lin][col] != "^"){
			if(area[lin][col] == "~"){
				area[lin][col] = "-";
				semente--;
			} else{
				printf("\nATENCAO: posicao escolhida nao possui agua para o plantio!\n");
			}
		} else{
			printf("\nATENCAO: posicao invalida ou ja usada na matriz!\n");
		}
		jogadas++;
	}else{
		printf("\nATENCAO: nao possui saldo de semente!\n");
	}
}


void adubar(){
	int lin, col;
	
	if(adubo>0){
	printf("ADUBAR[linha]: ");
	scanf("%d", &lin);
	printf("ADUBAR[coluna]: ");
	scanf("%d", &col);
    if(col<50 && lin<25 && area[lin][col] != "i" && area[lin][col] != "^"){
    	if(area[lin][col] == "-"){
    		area[lin][col] = "o";
    		adubo--;
		} else if(area[lin][col] == "o"){
			area[lin][col] = "O";
			adubo--;
		} else if(area[lin][col] != "o" && area[lin][col] != "-"){
			printf("\nATENCAO: posicao escolhida nao possui broto(-) ou melancia verde(o)!\n");
		}
	} else{
		printf("\nATENCAO: posicao invalida ou ja usada na matriz!\n");
	}
	jogadas++;
    }
	else {
    	printf("\nATENCAO: nao possui saldo de adubo!\n");
	}
	

}

void capinar(){
	int lin, col;
	
	printf("CAPINAR[linha]: ");
	scanf("%d", &lin);
	printf("CAPINAR[coluna]: ");
	scanf("%d", &col);
	if(col<50 && lin<25){
		if(area[lin][col] == "i"){
			area[lin][col] = " ";
			if(rand()%100<20){
				semente++;
			}
		} else if(area[lin][col] == "I"){
			area[lin][col] = " ";
			if(rand()%100<50){
				semente++;
			}
		} else if(area[lin][col] == "+"){
			area[lin][col] = " ";
			semente++;
		} else if(area[lin][col] != "i" && area[lin][col] != "I" && area[lin][col] != "+"){
			printf("\nATENCAO: posicao escolhida nao possui broto de erva daninha(i) ou erva daninha(I) ou cordao de melancia(+)!\n");
		}
		jogadas++;
	} else{
		printf("\nATENCAO: posicao invalida na matriz!\n");
	}
}

void recolher(){
	int lin, col;
	
	printf("RECOLHER[linha]: ");
	scanf("%d", &lin);
	printf("RECOLHER[coluna]: ");
	scanf("%d", &col);
	if(col<50 && lin<25){
		if(area[lin][col] == "o"){
			area[lin][col] = " ";
			semente++;
			adubo++;
		} else if(area[lin][col] == "O"){
			area[lin][col] = " ";
			semente++;
			adubo++;
			agua++;
		} else if(area[lin][col] != "o" && area[lin][col] != "O"){
			printf("\nATENCAO: posicao escolhida nao possui melancia verde(o) ou melancia madura(O)!\n");
		}
		
	} else{
		printf("\nATENCAO: posicao invalida na matriz!\n");
	}
	
}

void noite(){
	int i,j;
	for(i=0;i<25;i++){
		for(j=0;j<50;j++){
			if(area[i][j] == "+" && area[i-1][j] == " " ){   // cordao de melancia
				if(rand()%100<30){
					area[i-1][j] = "+";
				}
				if(rand()%100<15){
					area[i-1][j] = "-";
				}
				if(rand()%100<55){
					area[i-1][j] = " ";
				}
			}
			
			if(area[i][j] == "O" && area[i+1][j] == " "){   // melancia madura
				if(rand()%100<30){
					area[i+1][j] = "+";
				}
			}
				
			if(area[i][j] == "o"){   // melancia verde crescer
				if(rand()%100<50){
					area[i][j] = "O";
				}
			}
				
			if(area[i][j] == "-"){   // broto de melancia crescer
				if(rand()%100<50){
					area[i][j] = "o";
				}
			}
			
			if(area[i][j] == "i"){   // broto de erva daninha crescer
				if(rand()%100<50){
					area[i][j] = "I";
				}
			}
			
			if(area[i][j] == "I"){
				if(area[i-1][j-1] != "^"){
					area[i-1][j-1] = " ";
				}
				if(area[i-1][j] != "^"){
					area[i-1][j] = " ";
				}
				if(area[i-1][j+1] != "^"){
					area[i-1][j+1] = " ";
				}
				if(area[i][j-1] != "^"){
					area[i][j-1] = " ";
				}
				if(area[i][j+1] != "^"){
					area[i][j+1] = " ";
				}
				if(area[i+1][j-1] != "^"){
					area[i+1][j-1] = " ";
				}
				if(area[i+1][j] != "^"){
					area[i+1][j] = " ";
				}
				if(area[i+1][j+1] != "^"){
					area[i+1][j+1] = " ";
		     	}   
			}
			
			if(area[i][j] == " "){
				if(rand()%1250<1){
					area[i][j] = "i";
				}
			}
			
			}
		}
		dia++;
	}


int main(int argc, char * argv[])
{
	srand(time(NULL));
	inicializa();
	char op = ' ';
	while(op != 'f'){
		imprime();
		printf("(i)rrigar / (s)emear / (a)dubar / (c)apinar / (r)ecolher / (n)oite / (f)im // Opcao %d: ", jogadas+1);
		scanf("%c", &op);
		getchar();
		switch(op){
			case 'i': irrigar();
			getchar();
				break;
			case 's': semear();
			getchar();
				break;
			case 'a': adubar();
			getchar();
				break;
			case 'c': capinar();
			getchar();
				break;
			case 'r': recolher();
			getchar();
				break;
			case 'n': noite();
			getchar();
				break;
			case 'f': 
			getchar();
				break;
			default:
				printf("\nATENCAO: Opcao INVALIDA!\n");
			}
			if(jogadas >= 5){
				imprime();
				noite();
				jogadas = 0;
			}
		}
		return 0;
	}
