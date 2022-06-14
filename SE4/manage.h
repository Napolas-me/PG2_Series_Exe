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

#endif
