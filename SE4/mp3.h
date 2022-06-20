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
#endif