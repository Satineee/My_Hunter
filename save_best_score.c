/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-2-myhunter-satine.fouque
** File description:
** save_best_score.c
*/

#include "./include/my.h"
#include <stdio.h>

int read_file(text_t **text)
{
    char *str = NULL;
    size_t size;
    FILE *open_file = fopen("best_score", "r");
    getline(&str, &size, open_file);
    char *buff = malloc(sizeof(char) * size);
    text[1]->str = malloc(sizeof(char) * size);
    for (int i = 0; str[i] != '\0'; i++) {
        buff[i] = str[i];
        text[1]->str[i] = buff[i];
    }
    text[1]->str[my_strlen(str)] = '\0';
    int number = my_getnbr(buff);
    fclose(open_file);
    free(str);
    free(buff);
    return (number);
}

void write_into_file(arg_t *arg, text_t **text)
{
    arg->best_score = read_file(text);
    if (arg->score > arg->best_score){
        int fd = open("best_score",  O_RDWR | O_TRUNC);
        my_itoa(arg, text);
        write(fd, text[0]->str, my_strlen(text[0]->str));
        close(fd);
    }
}
