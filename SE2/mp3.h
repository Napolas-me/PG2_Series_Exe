/**
 * @file mp3.h
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
 * @brief 
 * 
 * @param data 
 * @param ref 
 * @param cmdLine 
 */
void command( TagArr_t *data, TagRef_t *ref, char *cmdLine );

/*******************************************
 *                                         *
 * Processamento da lista de ficheiros MP3 *
 *                                         *
 *******************************************/

/**
 * @brief 
 * 
 * @param tableName 
 * @param data 
 * @return int 
 */
int tableRead( char *tableName, TagArr_t *data );



#endif