//Everson Toledo - 76884

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

/*Sorteio das cartas - ok
  Numero de cartas (24) - ok
  Plantae e letras - ok
  Empate - ok

  Problema atual: Vitória booleana está sendo sobreescrita pela característica normal após a vitória plantae. --> Resolvido

  Próximos passos:
		   Editar os prints quando vitória por plantae - ok
		   Parâmetros equilibrados - ok
		   Jogo vs computador ok
		   Adicionar parâmetros - ok*/

class Carta {
private:
	char nome, letra;
	int altura, idade, copa, folha, tronco;
public:
	Carta() {
		nome = 'x';
		letra = 'x';
		altura = 0;
		idade = 0;
		copa = 0;
		folha = 0;
		tronco = 0;
	}
	Carta(int alt, int id, int cop, char nome_inserido, char tipo, int fol, int tronc) {
		nome = nome_inserido;
		letra = tipo;
		altura = alt;
		idade = id;
		copa = cop;
		folha = fol;
		tronco = tronc;
	}
	char getNomePlantae(){
		return nome;
	}
	void getNome(char nome_inserido){
		nome = nome_inserido;
		if (nome == 'a')
			printf("Sequoia - 1B");
		if (nome == 'b')
			printf("Figueira - 2B");
		if (nome == 'c')
			printf("Eucalipto - 3B");
		if (nome == 'd')
			printf("Angelim - 4B");
		if (nome == 'e')
			printf("Ipe - 1A");
		if (nome == 'f')
			printf("Pau-Brasil - 2A");
		if (nome == 'g')
			printf("Macieira - 3A");
		if (nome == 'h')
			printf("Mamoneiro - 4D");
		if (nome == 'i')
			printf("Araucaria - 5A");
		if (nome == 'j')
			printf("Pinheiro - 5B");
		if (nome == 'k')
			printf("Acacia - 6B");
		if (nome == 'l')
			printf("Amarica - 6A");
		if (nome == 'm')
			printf("Carvalho - 1C");
		if (nome == 'n')
			printf("Cedro - 2C");
		if (nome == 'o')
			printf("Baoba - 3C");
		if (nome == 'p')
			printf("Laranjeira - 4C ->> PLANTAE");
		if (nome == 'q')
			printf("Palmeira - 5C");
		if (nome == 'r')
			printf("Coqueiro - 6C");
		if (nome == 's')
			printf("Olieveira - 1D");
		if (nome == 't')
			printf("Umbu - 2D");
		if (nome == 'u')
			printf("Abacateiro - 3D");
		if (nome == 'v')
			printf("Cajueiro - 4A");
		if (nome == 'x')
			printf("Goiabeira - 5D");
		if (nome == 'y')
			printf("Paineira - 6D");
	}
	char getLetra(){
		return letra;
	}
	int getAltura() {
		return altura;
	}
	int getIdade() {
		return idade;
	}
	int getCopa(){
		return copa;
	}
	int getFolha(){
		return folha;
	}
	int getTronco(){
		return tronco;
	}
	void mostra() {
		getNome(nome);
		printf("\n1 - Altura: %d\n2 - Idade: %d\n3 - Diametro da copa: %d \n4 - Tamanho da folha: %d\n5 - Raio do Tronco: %d\n",altura, idade, copa, folha, tronco);
	}
};

class Baralho {
private:
	int ini,fim;
	Carta *array;
	int tam=50;
public:
	Baralho() {
		array = new Carta[30];
		ini=-1;
		fim=-1;
	}
	int getTam(){
		if (ini==-1 && fim==-1)
			return 0;
		return (fim-ini+1);
	}
	int insere(Carta novo_valor) {
		if (ini < 0)
			ini=0;
		fim = fim+1;
		array[fim]=novo_valor;
		return 1;
	}
	int remove() {
		ini = ini+1;
		return 1;
	}
	Carta getCarta(int posicao) {
			return array[posicao+ini];
	}

	void mostra() {
	//	if (ini==-1 && fim==-1){
	//		printf("Lista vazia.\n");
	//	} else {
			int cont;
			cont=ini;
			for (cont;cont<=fim;cont++){
				array[cont].mostra();
			}
	//	}
	}

};

class Jogador {
private:
	int ini,fim;
	Carta *array;
	int tam=300;
public:
	Jogador() {
		array = new Carta[300];
		ini=-1;
		fim=-1;
	}
	int getTam(){
		if (ini==-1 && fim==-1)
			return 0;
		return (fim-ini+1);
	}
	int insere(Carta novo_valor) {
		if (ini < 0)
			ini=0;
		fim = fim+1;
		array[fim]=novo_valor;
		return 1;
	}
	int remove() {
		ini = ini+1;
		return 1;
	}
	Carta getCarta() {
			return array[ini];
	}

	void mostra() {
	//	if (ini==-1 && fim==-1){
	//		printf("Lista vazia.\n");
	//	} else {
			int cont;
			cont=ini;
			for (cont;cont<=fim;cont++){
				array[cont].mostra();
			}
	//	}
	}

};


int main(){

	bool vitoria; //Para saber quem escolhe, true para 1
	bool plantae; //para evitar q vitoria seja sobrescrita caso Plantae ganhe
	int pvp;
	int escolha;
	int pause;

	Carta sequoia(100, 50, 15, 'a', 'b', 8, 30); //0
	Carta figueira(20, 90, 60, 'b', 'b', 10, 20); //1
	Carta eucalipto(90, 52, 10, 'c', 'b', 12, 10); //2
	Carta angelim(80, 45, 26, 'd', 'b', 14, 22); //3
	Carta ipe(30, 53, 15, 'e', 'a', 16, 18); //4
	Carta pau_brasil(15, 80, 17, 'f', 'a', 18, 7); //5
	Carta macieira(15, 66, 8, 'g', 'a', 17, 9); //6
	Carta mamoneiro(22, 35, 14, 'h', 'd', 30, 10); //7
	Carta araucaria(40, 18, 12, 'i', 'a', 19, 12); //8
	Carta pinheiro(60, 40, 6, 'j', 'b', 19, 14); //9
	Carta acacia(29, 23, 11, 'k', 'b', 12, 12); //10
	Carta amarica(9, 84, 7, 'l', 'a', 16, 9); //11
	Carta carvalho(45, 57, 42, 'm', 'c', 14, 17); //12
	Carta cedro(73, 36, 6, 'n', 'c', 10, 13); //13
	Carta baoba(74, 86, 2, 'o', 'c', 2, 45); //14
	Carta laranjeira(12, 32, 8, 'p', 'c', 16, 9); //15 --> Ideia de Plantae
	Carta palmeira(21, 19, 19, 'q', 'c', 35, 15); //16
	Carta coqueiro(19, 63, 30, 'r', 'c', 40, 15); //17
	Carta oliveira(33, 65, 22, 's', 'd', 19, 13); //18
	Carta umbu(6, 35, 30, 't', 'd', 22, 17); //19
	Carta abacateiro(20, 30, 23, 'u', 'd', 21, 3); //20
	Carta goiabeira(8, 35, 10, 'v', 'd', 19, 5); //21
	Carta cajueiro(18, 19, 28, 'x', 'a', 17, 14); //22
	Carta paineira(36, 35, 19, 'y', 'd', 13, 16); //23

while(1){
	Baralho baralho;
	Jogador jogador1;
	Jogador jogador2;

	baralho.insere(sequoia);
	baralho.insere(angelim);
	baralho.insere(pau_brasil);
	baralho.insere(amarica);
	baralho.insere(mamoneiro);
	baralho.insere(carvalho);
	baralho.insere(pinheiro);
	baralho.insere(cedro);
	baralho.insere(baoba);
	baralho.insere(laranjeira);
	baralho.insere(figueira);
	baralho.insere(ipe);
	baralho.insere(macieira);
	baralho.insere(acacia);
	baralho.insere(palmeira);
	baralho.insere(araucaria);
	baralho.insere(coqueiro);
	baralho.insere(eucalipto);
	baralho.insere(oliveira);
	baralho.insere(umbu);
	baralho.insere(paineira);
	baralho.insere(cajueiro);
	baralho.insere(abacateiro);
	baralho.insere(goiabeira);

	//baralho.mostra();

	printf("------------------------------------\n");

	//aplica função randômica para o sorteio das cartas
	//srand inicializa rand com a semente
	//time pega o número de segundos de primeiro de janeiro de 1970 até o segundo do momento de execução, adquirido através do horário do próprio computador
	//rand inicia em zero fechado e vai até o intervalo aberto digitado
	srand (time(NULL));
	int cont;
	int vet[24] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int random;



	random = rand()%24;
	vet[0] = random;

	random = rand()%24;
	while (vet[1] == -1){
		if (random != vet[0])
			vet[1] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[2] == -1){
		if (random != vet[0] && random != vet[1])
			vet[2] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[3] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2])
			vet[3] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[4] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3])
			vet[4] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[5] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4])
			vet[5] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[6] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5])
			vet[6] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[7] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5] && random != vet[6])
			vet[7] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[8] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5] && random != vet[6] && random != vet[7])
			vet[8] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[9] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5] && random != vet[6] && random != vet[7] && random != vet[8])
			vet[9] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[10] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5] && random != vet[6] && random != vet[7] && random != vet[8] && random != vet[9])
			vet[10] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[11] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5] && random != vet[6] && random != vet[7] && random != vet[8] && random != vet[9] && random != vet[10])
			vet[11] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[12] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5] && random != vet[6] && random != vet[7] && random != vet[8] && random != vet[9] && random != vet[10] && random != vet[11])
			vet[12] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[13] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5] && random != vet[6] && random != vet[7] && random != vet[8] && random != vet[9] && random != vet[10] && random != vet[11] && random != vet[12])
			vet[13] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[14] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5] && random != vet[6] && random != vet[7] && random != vet[8] && random != vet[9] && random != vet[10] && random != vet[11] && random != vet[12] && random != vet[13])
			vet[14] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[15] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5] && random != vet[6] && random != vet[7] && random != vet[8] && random != vet[9] && random != vet[10] && random != vet[11] && random != vet[12] && random != vet[13] && random != vet[14])
			vet[15] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[16] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5] && random != vet[6] && random != vet[7] && random != vet[8] && random != vet[9] && random != vet[10] && random != vet[11] && random != vet[12] && random != vet[13] && random != vet[14] && random != vet[15])
			vet[16] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[17] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5] && random != vet[6] && random != vet[7] && random != vet[8] && random != vet[9] && random != vet[10] && random != vet[11] && random != vet[12] && random != vet[13] && random != vet[14] && random != vet[15] && random != vet[16])
			vet[17] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[18] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5] && random != vet[6] && random != vet[7] && random != vet[8] && random != vet[9] && random != vet[10] && random != vet[11] && random != vet[12] && random != vet[13] && random != vet[14] && random != vet[15] && random != vet[16] && random != vet[17])
			vet[18] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[19] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5] && random != vet[6] && random != vet[7] && random != vet[8] && random != vet[9] && random != vet[10] && random != vet[11] && random != vet[12] && random != vet[13] && random != vet[14] && random != vet[15] && random != vet[16] && random != vet[17] && random != vet[18])
			vet[19] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[20] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5] && random != vet[6] && random != vet[7] && random != vet[8] && random != vet[9] && random != vet[10] && random != vet[11] && random != vet[12] && random != vet[13] && random != vet[14] && random != vet[15] && random != vet[16] && random != vet[17] && random != vet[18] && random != vet[19])
			vet[20] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[21] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5] && random != vet[6] && random != vet[7] && random != vet[8] && random != vet[9] && random != vet[10] && random != vet[11] && random != vet[12] && random != vet[13] && random != vet[14] && random != vet[15] && random != vet[16] && random != vet[17] && random != vet[18] && random != vet[19] && random != vet[20])
			vet[21] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[22] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5] && random != vet[6] && random != vet[7] && random != vet[8] && random != vet[9] && random != vet[10] && random != vet[11] && random != vet[12] && random != vet[13] && random != vet[14] && random != vet[15] && random != vet[16] && random != vet[17] && random != vet[18] && random != vet[19] && random != vet[20] && random != vet[21])
			vet[22] = random;
		else
			random = rand()%24;
	}
	random = rand()%24;
	while (vet[23] == -1){
		if (random != vet[0] && random != vet[1] && random != vet[2] && random != vet[3] && random != vet[4] && random != vet[5] && random != vet[6] && random != vet[7] && random != vet[8] && random != vet[9] && random != vet[10] && random != vet[11] && random != vet[12] && random != vet[13] && random != vet[14] && random != vet[15] && random != vet[16] && random != vet[17] && random != vet[18] && random != vet[19] && random != vet[20] && random != vet[21] && random != vet[22])
			vet[23] = random;
		else
			random = rand()%24;
	}
	//utiliza o vetor randomico para inserir as cartas nos baralhos
	for (cont=0;cont<12;cont++){
		jogador1.insere(baralho.getCarta(vet[cont]));
	}
	for (cont=12;cont<24;cont++){
		jogador2.insere(baralho.getCarta(vet[cont]));
	}
	//limpa o baralho
	for (cont=0;cont<24;cont++){
		baralho.remove();
	}
	//sorteia quem vai começar
	printf("1 - Jogar contra outro jogador\n2 - Jogar contra o computador\n");
	scanf("%d", &pvp);
	random = rand()%2;
	if (random == 0){
		vitoria = true;
		printf("Jogador 1 comeca escolhendo\n");
		printf("------------------------------------\n");
	}
	else{
		vitoria = false;
		if (pvp == 1)
			printf("Jogador 2 comeca escolhendo\n");
		else
			printf("Computador comeca escolhendo\n");
		printf("------------------------------------\n");
	}
	printf("cartas do Jogador 1 no inicio do jogo: %d\n", jogador1.getTam());
	if (pvp == 1)
		printf("cartas do Jogador 2 no inicio do jogo: %d\n", jogador2.getTam());
	else
		printf("cartas do Computador no inicio do jogo: %d\n", jogador2.getTam());
	printf("\n");
	printf("escolha 1 para altura, 2 para idade, 3 para o diametro da copa, 4 para o raio do tronco ou 5 para o comprimento da folha:\n");

while(1){

	if (vitoria == true){
		printf("Jogador 1 escolhe\n");

		printf("Carta do jogador numero 1:\n");

		(jogador1.getCarta()).mostra();
		scanf("%d", &escolha);
		printf("\nParametro escolhido: %d\n", escolha);
		printf("-----------------------------------\n");
		if (pvp == 1)
			printf("Carta do jogador numero 2:\n");
		else
			printf("Carta do Computador:\n");
		(jogador2.getCarta()).mostra();
	}
	printf("-----------------------------------\n");
	if (vitoria == false){
		if (pvp == 1){
			printf("Jogador 2 escolhe\n");

			printf("Carta do jogador numero 2: \n");
		}
		else{
			printf("Computador escolhe\n");

			printf("Carta do Computador: \n");
		}

		(jogador2.getCarta()).mostra();
		if (pvp == 1){
			scanf("%d", &escolha);
			printf("\nParametro escolhido: %d\n", escolha);
		}
		else{
			srand (time(NULL));
			random = rand()%6;
			while (random == 0){
				srand (time(NULL));
				random = rand()%5;
			}
			if (random == 1)
				escolha = 1;
			if (random == 2)
				escolha = 2;
			if (random == 3)
				escolha = 3;
			if (random == 4)
				escolha = 4;
			if (random == 5)
				escolha = 5;
			printf("\nParametro escolhido: %d\nDigite 1 para continuar\n", escolha);
			scanf("%d", &pause);
		}
		printf("-----------------------------------\n");
		printf("Carta do jogador numero 1:\n");
		(jogador1.getCarta()).mostra();

	}
	printf("-----------------------------------\n");

	if ((jogador1.getCarta()).getNomePlantae()=='p'){
		if ((jogador2.getCarta()).getLetra() != 'a'){
			printf("PLANTAE!! Jogador 1 ganhou a carta\n");
			jogador1.insere(jogador1.getCarta());
			jogador1.insere(jogador2.getCarta());
			jogador1.remove();
			jogador2.remove();
			vitoria = true;
			plantae = true;
		}
		else{
			if (pvp == 1)
				printf("FAMILIA A!! Jogador 2 ganhou a carta\n");
			else
				printf("FAMILIA A!! Computador ganhou a carta\n");
			jogador2.insere(jogador2.getCarta());
			jogador2.insere(jogador1.getCarta());
			jogador1.remove();
			jogador2.remove();
			vitoria = false;
			plantae = true;
		}
	}
	if ((jogador2.getCarta()).getNomePlantae()=='p'){
		if ((jogador1.getCarta()).getLetra() != 'a'){
			if (pvp == 1)
				printf("PLANTAE!! Jogador 2 ganhou a carta\n");
			else
				printf("PLANTAE!! Computador ganhou a carta\n");

			jogador2.insere(jogador2.getCarta());
			jogador2.insere(jogador1.getCarta());
			jogador1.remove();
			jogador2.remove();
			vitoria = false;
			plantae = true;
		}
		else{
			printf("FAMILIA A!! Jogador 1 ganhou a carta\n");
			jogador1.insere(jogador1.getCarta());
			jogador1.insere(jogador2.getCarta());
			jogador1.remove();
			jogador2.remove();
			vitoria = true;
			plantae = true;
		}
	}
	if (plantae != true){
		if (escolha == 1){

			if ((jogador1.getCarta()).getAltura() > (jogador2.getCarta()).getAltura()){
				printf("Jogador 1 ganhou a carta\n");
				jogador1.insere(jogador1.getCarta());
				jogador1.insere(jogador2.getCarta());
				jogador1.remove();
				jogador2.remove();
				vitoria = true;
			}
			else {
				if ((jogador1.getCarta()).getAltura() < (jogador2.getCarta()).getAltura()){
					if (pvp == 1)
						printf("Jogador 2 ganhou a carta\n");
					else
						printf("Computador ganhou a carta\n");
					jogador2.insere(jogador2.getCarta());
					jogador2.insere(jogador1.getCarta());
					jogador1.remove();
					jogador2.remove();
					vitoria = false;
				}
				else{
					printf("Empate, cada um fica com sua carta\n");
					jogador1.insere(jogador1.getCarta());
					jogador2.insere(jogador2.getCarta());
					jogador1.remove();
					jogador2.remove();
				}
			}
		}
		if (escolha == 2){
				if ((jogador1.getCarta()).getIdade() > (jogador2.getCarta()).getIdade()){
					printf("Jogador 1 ganhou a carta\n");
					jogador1.insere(jogador1.getCarta());
					jogador1.insere(jogador2.getCarta());
					jogador1.remove();
					jogador2.remove();
					vitoria = true;
				}
				else {
					if ((jogador1.getCarta()).getIdade() < (jogador2.getCarta()).getIdade()){
						if (pvp == 1)
							printf("Jogador 2 ganhou a carta\n");
						else
							printf("Computador ganhou a carta\n");
						jogador2.insere(jogador2.getCarta());
						jogador2.insere(jogador1.getCarta());
						jogador1.remove();
						jogador2.remove();
						vitoria = false;
					}
					else{
						printf("Empate, cada um fica com sua carta\n");
					jogador1.insere(jogador1.getCarta());
					jogador2.insere(jogador2.getCarta());
					jogador1.remove();
					jogador2.remove();
					}
				}

		}
		else{
			if (escolha == 3){

				if ((jogador1.getCarta()).getCopa() > (jogador2.getCarta()).getCopa()){
					printf("Jogador 1 ganhou a carta\n");
					jogador1.insere(jogador1.getCarta());
					jogador1.insere(jogador2.getCarta());
					jogador1.remove();
					jogador2.remove();
					vitoria = true;
				}
				else {
					if ((jogador1.getCarta()).getCopa() < (jogador2.getCarta()).getCopa()){
						if (pvp == 1)
							printf("Jogador 2 ganhou a carta\n");
						else
							printf("Computador ganhou a carta\n");
						jogador2.insere(jogador2.getCarta());
						jogador2.insere(jogador1.getCarta());
						jogador1.remove();
						jogador2.remove();
						vitoria = false;
					}
					else{
						printf("Empate, cada um fica com sua carta\n");
					jogador1.insere(jogador1.getCarta());
					jogador2.insere(jogador2.getCarta());
					jogador1.remove();
					jogador2.remove();
					}
				}
			}
			else{
				if (escolha == 4){

					if ((jogador1.getCarta()).getFolha() > (jogador2.getCarta()).getFolha()){
						printf("Jogador 1 ganhou a carta\n");
						jogador1.insere(jogador1.getCarta());
						jogador1.insere(jogador2.getCarta());
						jogador1.remove();
						jogador2.remove();
						vitoria = true;
					}
					else {
						if ((jogador1.getCarta()).getFolha() < (jogador2.getCarta()).getFolha()){
							if (pvp == 1)
								printf("Jogador 2 ganhou a carta\n");
							else
								printf("Computador ganhou a carta\n");

							jogador2.insere(jogador2.getCarta());
							jogador2.insere(jogador1.getCarta());
							jogador1.remove();
							jogador2.remove();
							vitoria = false;
						}
						else{
							printf("Empate, cada um fica com sua carta\n");
						jogador1.insere(jogador1.getCarta());
						jogador2.insere(jogador2.getCarta());
						jogador1.remove();
						jogador2.remove();
						}
					}
				}
				else{
					if (escolha == 5){

						if ((jogador1.getCarta()).getTronco() > (jogador2.getCarta()).getTronco()){
							printf("Jogador 1 ganhou a carta\n");
							jogador1.insere(jogador1.getCarta());
							jogador1.insere(jogador2.getCarta());
							jogador1.remove();
							jogador2.remove();
							vitoria = true;
						}
						else {
							if ((jogador1.getCarta()).getTronco() < (jogador2.getCarta()).getTronco()){
								if (pvp == 1)
									printf("Jogador 2 ganhou a carta\n");
								else
									printf("Computador ganhou a carta\n");

								jogador2.insere(jogador2.getCarta());
								jogador2.insere(jogador1.getCarta());
								jogador1.remove();
								jogador2.remove();
								vitoria = false;
							}
							else{
								printf("Empate, cada um fica com sua carta\n");
							jogador1.insere(jogador1.getCarta());
							jogador2.insere(jogador2.getCarta());
							jogador1.remove();
							jogador2.remove();
							}
						}
					}
				}
			}
		}
	}
	else{
		plantae = false;
	}
	if (pvp == 1)
		printf("cartas do Jogador 2 ao final do embate: %d\n", jogador2.getTam());
	else
		printf("cartas do Computador ao final do embate: %d\n", jogador2.getTam());

	printf("cartas do jogador 1 ao final do embate: %d\n", jogador1.getTam());

	if (jogador1.getTam() == 0 or jogador2.getTam() == 0){
		if (jogador1.getTam()>0)
			printf("Jogador 1 venceu\n");
		else
			if (pvp == 1)
				printf("Jogador 2 venceu!!\n");
			else
				printf("Computador venceu!!\n");
		break;
	}
}
	printf("------------------------------------\n");
	int novo_jogo;

	printf("\nDeseja iniciar uma nova partida?\n1-Sim\n2-Nao\n");
	scanf("%d", &novo_jogo);

	if (novo_jogo != 1){
		printf("\nFim de jogo\n");
		break;
	}
	else{
	    scanf("%d", &pause);
		printf("\nInicio de um novo jogo\n");
		printf("------------------------------------");
	}
}
return 0;

}
