/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-2-myhunter-satine.fouque
** File description:
** display.c
*/

#include "./include/my.h"

void display_window(arg_t *arg, image_t **img, text_t **text)
{
    display_img(arg, img[0]);
    display_vie(arg, img[2]);
    display_img(arg, img[3]);
    display_img(arg, img[10]);
    display_img(arg, img[1]);
    display_text(arg, text[0]);
    display_img(arg, img[8]);
    display_text(arg, text[1]);
    if (arg->vie == 0)
        display_img(arg, img[7]);
    sfRenderWindow_display(arg->window);
}

void display_img(arg_t *arg, image_t *img)
{
    sfSprite_setTextureRect(img->sprite, img->rect);
    sfSprite_setPosition(img->sprite, img->pos);
    sfRenderWindow_drawSprite(arg->window, img->sprite, NULL);
}

void display_text(arg_t *arg, text_t *text)
{
    sfText_setString(text->text, text->str);
    sfText_setPosition(text->text, text->pos);
    sfRenderWindow_drawText(arg->window, text->text, NULL);
}

void display_vie(arg_t *arg, image_t *img)
{
    for (int i = 0; i < arg->vie; i++){
        display_img(arg, img);
        img->pos.x += 60;
    }
    img->pos.x = 1300;
}

void display_h(void)
{
    write(1, "USAGE:\n    ./my_hunter\n\n", 24);
    write(1, "DESCRIPTION\n", 12);
    write(1, "    short video game, goal is to make the best score", 52);
    write(1, " by shooting birds.\n", 20);
    write(1, "    you have 3 lifes.\n", 22);
}
