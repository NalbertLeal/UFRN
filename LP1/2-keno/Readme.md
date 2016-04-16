# Projeto Keno

## Readme

 O jogo inicialmente lê um arquivo que possui 3 linhas, a primeira com a aposta em dolares do jogador, a segunda possui o numero de rounds, e a terceira linha possui os numeros em que o jogador apostou. Esse é um exemplo de arquivo.
 
    1500.0
    3
    1 56 43

 A extensão do arquivo é .dat mas no momento de iniciar o programa essa extensão não deve ser mencionada. Exemplo:

    ./keno aposta
 
 ### Jogabilidade
 
 Para se jogar o keno deve ser inicialmente passado o arquivo como demonstrado acima. A seguir o programa vai rodar e dizer quanto dinheiro foi apostado em cada rodada (dividindo o montante de doleres pelo numero de rodadas). Após isso a primeira rodada será iniciada, nela 20 numeros serão sorteados, e se algum dos numeros apostados for sorteado ele recebera um valor baseado nessa quantidade de acertos, as rodadas subsequentes são iguais a primeira.
 
### Problemas

O desenvolvimento do jogo esta incompleto. Funções como void KenoBet::reset() não foi utilizada. Se um numero for sorteado mais de uma vez ele também ira ser comtabilizado mais de uma vez. Por isso o projeto será encaminhado para o meu github e lá irei manter o jogo para que possa terminalo e manter interessados atualizados das implementações.

### Sobre o autor

Nome: Nalbert Gabriel Melo Leal

email acadêmico: nalbertg@outlook.com

email pessoal: nalbertrn@yahoo.com.br

github: nalbertg
