/**
 * @file mp3.h
 * @author Group 14
 * @brief 
 * @version 0.1
 * @date 08-05-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _MP3_H_
#define _MP3_H_

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "stringMan.h"

/*
 *
 * Values taken from http://mpgedit.org/mpgedit/mpeg_format/mpeghdr.htm
 * 
 */

#define MAX_TIT 30
#define MAX_ART 30
#define MAX_ALB 30
#define MAX_COM 30
#define MAX_TAGS 1000
#define MAX_PARAMS 7

/**
 * @brief O tipo MP3Tag_t representa a informação de uma tag
 * 
 */
typedef struct mp3Tag_t{
    char title[MAX_TIT + 1];
    char artist[MAX_ART + 1];
    char album[MAX_ALB + 1];
    short year;
    char comment[MAX_COM + 1]; // the last byte in coment can be used for defining the track
    char track;
    char genre;
}MP3Tag_t;

/**
 * @brief O tipo TagArr_t representa o descritor de um array de tags
 * 
 */
typedef struct tagArr_t{
    int count; // Quantidade de elementos preenchidos no campo tags.
    MP3Tag_t tags[MAX_TAGS]; // Array de tags.
}TagArr_t;

/**
 * @brief O tipo TagRef_t representa o descritor de um array de ponteiros para tag
 * 
 */
typedef struct tagRef_t{
    int count; // Quantidade de elementos preenchidos no campo refs.
    MP3Tag_t *refs[MAX_TAGS]; // Array de ponteiros para tag.
}TagRef_t;

/********************************
 *                              *
 * Funções para gestao de dados *
 *                              *
 ********************************/

/**
 * @brief Esta função inicia o descritor de um array de tags no estado inicial, vazio, pelo que regista o
 *        valor 0 na quantidade de elementos preenchidos.
 * 
 * @param data estrutura do tipo TagArr_r 
 */
void tagArrInit( TagArr_t *data );

/**
 * @brief Funçao para iniciar estrutura TagRef_r
 * 
 * @param data estrutura do tipo TagArr_r
 * @param ref estrutura do tipo TagRef_t
 */
void tagRefInit(TagArr_t *data, TagRef_t *ref);

/**
 * @brief Esta função adiciona ao descritor, indicado por data, uma tag, indicada por tag.
 * 
 * Retorna um código de resultado: 0, em caso de sucesso; -1, se falhar,
 * nomeadamente devido a espaço insuficiente no array.
 * 
 * @param data estrutura do tipo TagArr_r
 * @param tag estrutura do tipo MP3tag_t
 * @return int 
 */
int tagArrAdd( TagArr_t *data, MP3Tag_t *tag );

/**
 * @brief Function to compare based on artists in MP3_Tag_t struct
 * 
 * @param t1 estrutura do tipo MP3tag_t
 * @param t2 estrutura do tipo MP3tag_t
 * @return result of comparation using strcmp() 
 */
int artistCompare(const void *t1, const void *t2);

/**
 * @brief Function to compare based on titles in MP3_Tag_t struct
 * 
 * @param t1 estrutura do tipo MP3tag_t
 * @param t2 estrutura do tipo MP3tag_t
 * @return result of comparation using strcmp() 
 */
int titleCompare(const void *t1, const void *t2);

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

/**
 * @brief Get the Title of a command type string.
 * 
 * Exe:
 *  char* string = "c hello";
 *  char* title = getTitle(string);
 *          |
 *          ---> hello
 *  
 * 
 * @param str string with title
 * @return title
 */
char* getTitle(char* str);

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

/*******************************************
 *                                         *
 * Processamento da lista de ficheiros MP3 *
 *                                         *
 *******************************************/

/**
 * @brief Esta função destina-se preencher o array de tags indicado por data. Deve percorrer o ficheiro 
          de texto com nome indicado por tableName, ler os dados de cada tag, e adicioná-los ao 
          array de tags, usando a função tagArrAdd. 
          No caso de haver carateres de espaço nas extremidades dos campos, estes espaços devem ser 
          eliminados. Se houver tags em que um dos campos Title e Artist seja  string vazia, a respetiva 
          linha da tabela deve ser ignorada, não ficando registada para qualquer processamento. 
          Esta função retorna 0, em caso de sucesso, ou -1, em caso de falha na leitura da tabela.
 * 
 * @param tableName Nome do ficheiro
 * @param data estrutura do tipo TagArr_r
 * @return 0 if success, -1 otherwise
 */
int tableRead( char *tableName, TagArr_t *data );

int titleCompare2(const void *t1, const void *t2);

#endif