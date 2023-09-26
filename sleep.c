/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-2-myhunter-satine.fouque
** File description:
** sleep.c
*/

#include "./include/my.h"

void sleep_sec(image_t **img, arg_t *arg, text_t **text)
{
    sfClock *clock = sfClock_create();
    sfTime t;
    t = sfClock_getElapsedTime(clock);
    float seconds = t.microseconds / 100000.0f;
    while (seconds < 3.0){
        t = sfClock_getElapsedTime(clock);
        seconds = t.microseconds / 100000.0f;
        img[1]->rect.left = 378.0f;
        display_window(arg, img, text);
    }
}

void sleep_5_sec(arg_t *arg, image_t **img, text_t **text)
{
    sfClock *clock = sfClock_create();
    sfTime t;
    t = sfClock_getElapsedTime(clock);
    float seconds = t.microseconds / 1000000.0f;
    while (seconds < 4.0){
        t = sfClock_getElapsedTime(clock);
        seconds = t.microseconds / 1000000.0f;
        img[1]->rect.left = 378.0f;
        display_window(arg, img, text);
    }
    img[1]->rect.left = 0.0f;
    sfClock_destroy(clock);
}
