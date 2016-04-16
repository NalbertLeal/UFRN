/**
 * Exercício
 * ---------
 *
 * 1) Implementar message.cpp de acordo com a especificação de message.h.
 * 2) Imprimir as mensagens por ordem de
 *    a) Remetente
 *    b) Assunto
 *    c) Data de envio
 *    utilizando functors.
 *
 * 3) Fazer o programa trabalhar com objetos mensagem criado com alocação
 * dinâmica e ponteiros.
 *
 * 4) Converter o programa do passo 2 para trabalhar com std::unique_ptr<>.
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <memory>

#include "message.h"

using namespace std;

int main( )
{
    unique_ptr <Message> pM1( new Message( "selan@dimap.ufrn.br", "LP1", "201509011355", "jack@gmail.com", "jack.boy@hotmail.com", "false", "Aqui começa o corpo da mensagem\n Queremos voce por aqui.\n \n Ate breve!" ) );
    unique_ptr <Message> pM2( new Message( "andre@gmail.com", "Qualquer coisa", "201509101255" ) );
    unique_ptr <Message> pM3( new Message( "silvia.mota@hotmail.com", "Pesquisa em conjunto", "201509101055" ) );


    // std::vector< Message* > ms;

    vector<unique_ptr<Message> > ms;

    ms.push_back( move(pM1) );
    ms.push_back( move(pM2) );
    ms.push_back( move(pM3) );

    std::cout << ">>> Original messages: \n";
    for ( auto const & e : ms )
        std::cout << *e << "\n";

    // TODO:
    // Aqui eh onde você deve ordenar as mensagens armazenadas em ms.
    //
    //

    SortM mySorterSubject(Message::HeaderField::SUBJECT);
    SortM mySorterDate(Message::HeaderField::DATE);
    SortM mySorterSender(Message::HeaderField::SENDER);

    std::sort( ms.begin(), ms.end(), mySorterSubject );

    std::cout << ">>> Sorted messages by Subject: \n";
    for ( auto const & e : ms )
        std::cout << *e << "\n";
#ifdef _XXXx
    std::sort( ms.begin(), ms.end(), mySorterDate );

    std::cout << ">>> Sorted messages by Date: \n";
    for ( auto const & e : ms )
        std::cout << *e << "\n";

    std::sort( ms.begin(), ms.end(), mySorterSender );

    std::cout << ">>> Sorted messages by Sender: \n";
    for ( auto const & e : ms )
        std::cout << *e << "\n";

#endif

    std::cout << ">>> Normal exiting....\n";
    return EXIT_SUCCESS;
}
