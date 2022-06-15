#ifndef _MANAGE_H_
#define _MANAGE_H_

#include "dinamicArray.h"
#include "binTree.h"
#include "annex.h"

#define INITSPACE 4

typedef struct{
	DinRef_t *refA; // Referências para o comando “a”.
	DinRef_t *refT; // Referências para os comandos “t” e “s”.
	TNode *bst; // Árvore binária para pesquisar títulos por palavras isoladas
}Manage_t;

/**
 *
 * Esta função aloja dinamicamente, e retorna, o descritor para gestão dos dados. Deve utilizar o módulo
de arrays de referências para criar os respetivos descritores.
 *
 * 
 * @return Manage_t* 
 */
Manage_t *manCreate( void );

/**
 * Esta função elimina o descritor de gestão de dados, indicado por man, libertando a toda a memória de
alojamento dinâmico que dele depende. Deve utilizar o módulo de arrays de referências para eliminar
os respetivos descritores.
 * 
 * @param man 
 */
void manDelete( Manage_t *man );

/**
 *Esta função adiciona à gestão de dados, através do descritor indicado de man, a referência para a
estrutura indicada por tag, previamente alojada e preenchida.
 * 
 * @param man 
 * @param tag
 */
void manAddTag( Manage_t *man, MP3Tag_t *tag );

/**
 * Esta função marca como concluída a fase de preparação dos dados, tendo sido criadas e referenciadas
todas as tags. Tem como objetivo preparar os dois arrays de referências para dar as respostas
pretendidas na fase de comandos. Para isso, aplica os respetivos critérios de ordenação, usando o
módulo de arrays de referências.
 * 
 * @param man 
 */
void manSort( Manage_t *man );

/**
 * Esta função apresenta, em standard output, os resultados do comando inserido pelo utilizador. A linha
de comando é passada através do parâmetro cmdLine. Deve utilizar as funções do módulo de arrays
de referências para realizar as listagens e as pesquisas. O comando “q” é processado diretamente pela
aplicação, não sendo chamada a função manCommand.
 * 
 * @param man 
 * @param cmdLine 
 */
void manCommand( Manage_t *man, char *cmdLine );

/**
 * @brief Esta função apresenta, em standard output, os resultados do comando inserido pelo utilizador. 
          A linha de comando é passada à função através do parâmetro cmdLine. 
          Para os comados a e t deve utilizar, respetivamente, o array principal e o array auxiliar de 
          referências. Para o comando s deve utilizar a função bsearch, da biblioteca normalizada, 
          sobre o array auxiliar de referências
 * 
 * @param data estrutura do tipo TagArr_r
 * @param ref estrutura do tipo TagRef_t
 * @param cmdLine comando a executar (a, t, s "title")
 */
void command( TagArr_t *data, TagRef_t *ref, char *cmdLine );

/**
 * @brief Prepara os descritores dos dois arrays (de tags e de referências), 
 *        para dar as respostas pretendidas na fase de comandos.
 *        As ordenações devem ser realizadas com a função qsort da biblioteca normalizada.
 *        Para uniformização das soluções, pretende-se que o array principal seja ordenado pelo critério
 *        do comando a e o array auxiliar pelo critério do comando t.
 * 
 * @param data estrutura do tipo TagArr_r
 * @param ref estrutura do tipo TagRef_t
 */
void setupEnd( TagArr_t *data, TagRef_t *ref );

#endif
