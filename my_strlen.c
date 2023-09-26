/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** count number of caracter
*/

#include "./include/my.h"

int my_strlen(char const *str)
{
    int compteur = 0;
    for (int i = 0; str[i] != '\0'; i++){
        compteur += 1;
    }
    return compteur;
}

int my_nbrlen(int nb)
{
    int comp = 1;
    int ten_exp = 10;
    while (nb >= ten_exp){
        ten_exp = ten_exp * 10;
        comp += 1;
    }
    return comp;
}

char *my_revstr(char *str)
{
    int len = my_strlen(str) - 1;
    for (int j = 0; j < len; j++){
        char temp = str[len];
        str[len] = str[j];
        str[j] = temp;
        len--;
    }
    return str;
}

void my_itoa(arg_t *arg, text_t **text)
{
    int copy = arg->score;
    int i = 0;
    if (arg->score != 0){
        do {
            text[0]->str[i++] = copy % 10 + '0';
        } while ((copy /= 10) > 0);
        text[0]->str[i] = '\0';
    }
    text[0]->str = my_revstr(text[0]->str);
    if (arg->score > arg->best_score){
        text[1]->str = malloc(sizeof(char) * (my_nbrlen(arg->score) + 1));
        text[1]->str = text[0]->str;
    }
}

int my_getnbr(char const *str)
{
    int nombre = 0;
    int i = 0;
    while (str[i] != '\0' && '0' <= str[i] && str[i] <= '9'){
        nombre = nombre * 10 + (str[i] - 48);
        i++;
    }
    return nombre;
}
