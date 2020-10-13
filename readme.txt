Everson Toledo - 76884

PLANTAE KOMBAT!!

Para rodar basta dar 2 cliques no aplicativo.

A ideia do jogo foi montar um estilo super trunfo utilizando árvores. Os parâmetros foram definidos para manter um jogo equilibrado e não obrigatoriamente respeitam parâmetros verídicos, mas há a tentativa de manter uma proporção. O parâmetro específico "idade" foi definido arbitrariamente.

Acompanha um arquivo executável (jogo em si) e o código fonte desenvolvido em C++.

O jogo deverá contar com 2 jogadores que jogarão um contra o outro, ou com apenas um jogador que jogará contra o computador (Neste readme o computador será tratado também como jogador 2). Um menu inicial permite a escolha. 
Existe um baralho com 24 cartas representando árvores, cada carta com seu nome, família (A, B, C ou D) e 5 parâmetros (altura, idade, diâmetro da copa, tamanho da folha e raio do tronco), o baralho é dividido igual e aleatoriamente com 12 cartas para cada jogador e é sorteado também o jogador que começa jogando.

 Regras e funcionamento:

1) Há um menu inicial com as seguintes opções:
	1 - Jogar contra outro jogador
	2 - Jogar contra o computador

2) O jogador que começar vai ver apenas a sua carta e deverá escolher um dos parâmetros digitando números através do seguinte menu:
	1 - Altura
	2 - Idade
	3 - Raio da copa
	4 - Tamanho da folha
	5 - Raio do tronco

3) O computador, tendo a escolha em seu poder, escolhe aleatoriamente um dos parâmetros, após a escolha do mesmo, o Jogador deverá digitar "1" para continuar no jogo.

4) Após a escolha, o jogo mostrará a carta do oponente e mostrará qual dos dois venceu o combate, ou seja, a carta com o maior valor no parâmetro escolhido.

5) O jogador vencedor verá somente a sua carta na próxima rodada e deverá escolher um parâmetro para dar continuidade ao jogo. No caso de empate cada jogador ficará com sua carta e o jogador que escolheu o parâmetro seguirá escolhendo.

6) PLANTAE: Há uma carta com um parâmetro especial denominado "PLANTAE!!", quando essa carta entra em jogo, o parâmetro escolhido é desconsiderado e ela vence seu embate caso não esteja jogando contra uma carta da família A.

7)Vence o jogo o jogador que acumular todas as cartas.

8) Após o término há a opção de uma nova partida ou de finalizar o programa com o seguinte menu:
	1 - Nova Partida
	2 - Finalizar

Detalhes técnicos:

Liguagem de desensolvimento: C++;
Paradigma de programação: Orientação a objetos;

O jogo utiliza orientação a objetos definindo o objeto genérico "Carta" inicializado com parâmetros neutros de Nome, Letra (Famĺia), Altura, Idade, Copa, Folha e Tronco, o qual serve de base para todas as cartas do jogo.

A próxima classe é denominada "Baralho" e é um vetor de objetos do tipo Carta que recebe todas as cartas no início do jogo. A estrutura trabalha como uma fila por quantiguidade física.

A terceira classe se chama "Jogador" e é um segundo vetor para objetos do tipo Carta, essa estrutura irá armazenar as cartas dos jogadores da mesma forma da estrutura "Baralho", e contará com métodos de inserção (ganho de cartas) e remoção (perda de cartas), além de alguns auxiliares. As cartas são inseridas nas duas estruturas de forma aleatória, por sorteio, no início do jogo.

A função principal (Main) começa com algumas variáveis fundamentais para o funcionamento do jogo, são elas: 
	vitória -> boleana (verdadeiro ou falso), define qual jogador vai esolher o próximo parâmetro, quem ganhou a rodada anterior. É inicializada através de sorteio (random) definindo quem começa jogando.
	plantae -> Também boleana, tem por objetivo apenas definir se a carta atual é ou não a que possui o parâmetro especial "PLANTAE".
	escolha -> Tipo int, um número inteiro que varia de 1 a 5 e representa o parâmetro escolhido pelo jogador.
	pvp -> Tipo int, número inteiro, define se o jogo será entre dois jogadores (valor 1) ou de jogador contra computador (outro valor).
			 
Posteriormente há a criação das cartas com seus parâmentros.

Agora são criadas as estruturas "baralho", do tipo "Baralho" (a linguagem C++ diferencia letras maíusculas de minúsculas, logo "baralho", com "b" minúsculo é diferente de "Baralho", com "b" maiúsculo e essa chamada representa o uso de um objeto "baralho" da classe tipo "Baralho"), "jogador 1" e "jogador 2" que são objetos do tipo "Jogador".

O baralho é preenchido com as cartas criadas e em seguida é criado um vetor com 24 posições que é preenchido aleatoriamente (função random) com números inteiros de 1 a 24, esse vetor é utilizado para dar as cartas para os jogadores 1 e 2. Exemplo de funcionamento com um vetor de 6 posições:
	1) sorteia números de 1 a 6 para preencher o vetor, por exemplo: {6,2,4,1,5,3}
	2) Esse vetor representa as posições do vetor baralho, as 3 primeiras cartas desse vetor randômico são dadas ao jogador 1 e as últimas 3 ao jogador 2:
	Vetor baralho (que também é preenchido randomicamente):
		{1,3,4,5,6,2}
	Vetor randômico:
		{6,2,4,1,5,3}
	Jogador 1:
		{2,3,5}
	Jogador 2:
		{1,6,4}
	
	Nesse exemplo, o Jogador 1 recebe as cartas 2, 3 e 5, três primeiras posiçõs do vetor randômico (1, 2 e 4), sexta, segunda e quarta posição do vetor baralho respectivamente. Seguindo a mesma lógica, são dadas as cartas do Jogador 2, o objetivo é garantir a aleatoriedade, garantindo assim que cada nova partida seja completamente diferente da anterior.

Nesse ponto do código temos os dois jogadores com as suas cartas definidas aleatoriamente. Um novo sorteio é realizado de forma similar para ver quem começa, é sorteado, aleatoriamente, o número 0 ou 1, um setando a varíavel boleana "vitoria" como "true" dando inicio do jogo ao jogador 1, outro setando a mesma variável como "false" dando o inicio ao jogador 2.

Agora o jogo em si começa, o jogador que ganhou o sorteio vê sua carta e escolhe um dos parâmetros, a variável "escolha" é alterada com a seleção desse menu, será detalhado o funcionamento quando escolha é igual a 1, exatamente o mesmo ocorre com outros valores.

Primeiro de tudo é verificado o parâmetro "PLANTAE", caso o mesmo seja verdadeiro, é verificada a família da carta oponente, se for da família "A", o jogador que possui a carta da família "A" vence, caso contrário vence o que possui a carta "PLANTAE".

Caso "PLANTAE" seja falso, o jogo vai para o parâmetro escolhido, no caso de "escolha = 1" é chamado um método que busca a carta atual do Jogador 1 e imediatamente em cima é chamado um método que busca o parâmetro "Altura" dessa carta. O mesmo é feito para o jogador 2 e esses valores são comparados, caso o valor do parâmetro da carta do jogador 1 seja maior, a carta dele vai para o fim do seu baralho e a carta do jogador 2 também, "vitoria" é setada como "true" dando a ele a escolha na próxima rodada. Caso o parâmetro do Jogador 2 seja maior, o mesmo é válido pra ele, porém setando "vitoria" como "false" para dar a ele o direito de escolha. Caso haja um empate, cada jogador fica com sua carta e a variável "vitoria" não é alterada.

Com uma escolha diferente de 1, exatamente o mesmo processo ocorre, porém com o uso de um parâmetro diferente.

No fim de cada rodada são mostradas quantas cartas cada jogador possui e é feito um teste para saber se algum dos dois está sem cartas, caso um deles esteja, o outro é mostrado como vencedor.

A última etapa é a verificação de nova partida ou término do programa.

A opção pelo referido trabalho foi desenvolver um jogo única e exclusivamente com os conhecimentos adquiridos durante a graduação, sem qualquer plataforma ou referência externa e o envio do código juntamente com esse rápido relato tem por objetivo demonstrar o quão complexo é o processo.
