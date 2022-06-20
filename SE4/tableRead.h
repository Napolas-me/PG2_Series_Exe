/**
 * @file tableRead.h
 * @brief 
 * @version 0.1
 * @date 31-05-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _TABLE_READ_H
#define _TABLE_READ_H

#include "manage.h"
#include <stdio.h>
/**
 *  Esta função destina-se preencher a estrutura de dados array para acesso às tags. Deve percorrer o
 *  ficheiro de texto com o nome indicado por tableName, ler os dados de cada tag e adicionar a sua
 *  referência à gestão de dados, através do descritor indicado por man, usando a função manAddTag.
 *  Tal como especificado na série anterior, no caso de haver carateres de espaço nas extremidades dos
 *  campos, estes espaços devem ser eliminados. Se houver tags em que um dos campos Title e Artist seja
 *  string vazia, a respetiva linha da tabela deve ser ignorada, não ficando registada para qualquer
 *  processamento.
 *  Esta função retorna 0, em caso de sucesso, ou -1, em caso de falha na leitura da tabela.
 * 
 * @param tableName input file name
 * @param man data structure of type Manage_t
 * @return 0 if sucesse, -1 if read file error
 */
int tableReadStore( char *tableName, Manage_t *man );

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

#endif