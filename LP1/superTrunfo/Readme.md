# Prova de LP1
## Read me
### Alunos: Nalbert Gabriel e Rodrigo Lafayette

### Para compilar
 Como não foi desenvolvido um makefile é necessário usar o comando a seguir do g++ (é nescessário estar na raiz do projeto):
 
        g++ -std=c++11 -I include src/main.cpp -o compilado

### Jogabilidade
 Antes da inicialização do software é nescessario passar como argumento na linha de comando o nome de um arquivo .dat (ou similar) que possua os atributos das cartas que irão ser usadas, seguido pelo numero de jogadores e pelo numero de cartas que cada jogador possui no inicio do jogo.
 A partir dessas informações o jogo ira ser configurado para a partida desejada e o sorteio de cartas sera feito isso, as rodadas começaram com o soteio de um atributo aleatorio por parte de um jogatodor aleatorio e então serão sacadas da pilha de cada jogador uma carta e ela sera comparada as outras tendo en vista o atributo priviamente sorteado.
 
 se uma carta possui ID igual a ST e todas a outras não possuirem 1 em seu ID ela ganha a rodada automaticamente
 se não ouver carta com ID igual a ST ou se houver junto com uma carta qua possui um em seu ID a partida ocorre normalmente
 O jogador que coletar todas as cartas sera o vencedor
 
### Contatos

##### Nalbert
 email academico: nalbertg@outlook.com.br   
 email pessoal: nalbertrn@yahoo.com.br  
 github: nalbertg   
 
#### Rodrigo
email: rodrigolafayette@hotmail.com  
github: Rlafayette