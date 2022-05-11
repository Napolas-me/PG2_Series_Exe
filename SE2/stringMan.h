/**
 * @file stringMan.c
 * @author Group 14
 * @brief File holding the functions used in exe2
 * @version 0.1
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _STRINGMAN_H_
#define _STRINGMAN_H_

#include <string.h>
#include <stdio.h>

#define MAX_CHAR_VAL 2


enum stringTypes{
    SPACE = ' ',
    TAB = '\t',
    CHANGE_LINE = '\n',
	FIELD_SEP = ';'
};

/**
 * @brief Function to cut the ending spaces from a pointer to a string passed by argument
 * 
 * @param str string with spaces
 * @return pointer to the string with ending spaces removed 
 */
char *cutEndingSpaces( char *str );

/**
 * @brief Function to separate strings from a line.
 * The separator element is ';'
 * 
 * @param line line to evaluate
 * @param ptrs array of pointers with diferent starting points of line
 * @param max_fields max number of fields in ptrs
 * @return number of real fields in line 
 */
int fields(char *line, char *ptrs[], int max_fields );

#endif