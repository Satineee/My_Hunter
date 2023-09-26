/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-2-myhunter-satine.fouque
** File description:
** destroy.c
*/

#include "./include/my.h"
#include <stdio.h>

void destroy_elt(arg_t *arg, image_t **img, text_t **text)
{
    destroy_arg(arg);
    destroy_img(img);
    destroy_text(text);
}

void destroy_arg(arg_t *arg)
{
    sfClock_destroy (arg->clock_bird);
    sfClock_destroy (arg->clock_wing);
    sfMusic_destroy(arg->home);
    sfMusic_destroy(arg->game);
    sfMusic_destroy(arg->kill);
    sfMusic_destroy(arg->game_over);
    sfRenderWindow_destroy(arg->window);
    free(arg);
}

void destroy_img(image_t **img)
{
    for (int i = 0; i < 15; i++){
        sfTexture_destroy(img[i]->texture);
        sfSprite_destroy(img[i]->sprite);
        free(img[i]);
    }
    free(img);
}

void destroy_text(text_t **text)
{
    for (int i = 0; i < 2; i++) {
        sfFont_destroy(text[i]->font);
        sfText_destroy(text[i]->text);
        free(text[i]);
    }
    free(text);
}
