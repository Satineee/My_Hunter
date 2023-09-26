/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-2-myhunter-satine.fouque
** File description:
** display_home.c
*/

#include "./include/my.h"

void display_home(image_t **img, arg_t *arg, text_t **text)
{
    display_img(arg, img[4]);
    button_effect(img[5], img[14], arg);
    display_img(arg, img[6]);
    display_img(arg, img[10]);
    button_effect(img[12], img[13], arg);
    read_file(text);
    display_text(arg, text[1]);
}

void button_effect(image_t *img1, image_t *img2, arg_t *arg)
{
    if (arg->mouse.x >= img1->pos.x
    && arg->mouse.x <= img1->pos.x + 400
    && arg->mouse.y >= img1->pos.y
    && arg->mouse.y <= img1->pos.y + 212 ){
        display_img(arg, img2);
    } else
        display_img(arg, img1);
}

int close_window(arg_t *arg, image_t **img, text_t **text)
{
    if (arg->event.type == sfEvtClosed
    || arg->event.key.code == sfKeyEscape){
        sfRenderWindow_close(arg->window);
        destroy_elt(arg, img, text);
        return 1;
    }
    return 0;
}

void display_end(image_t **img, arg_t *arg, text_t **text)
{
    display_img(arg, img[4]);
    img[5]->pos.x = 100;
    img[5]->pos.y = 700;
    img[14]->pos.x = 100;
    img[14]->pos.y = 700;
    img[12]->pos.x = 600;
    img[12]->pos.y = 700;
    img[13]->pos.x = 600;
    img[13]->pos.y = 700;
    button_effect(img[5], img[14], arg);
    button_effect(img[12], img[13], arg);
    display_img(arg, img[6]);
    display_img(arg, img[9]);
    text[0]->pos.x = 480;
    text[0]->pos.y = 415;
    display_text(arg, text[0]);
    text[1]->pos.x = 480;
    text[1]->pos.y = 510;
    display_text(arg, text[1]);
}

int game(arg_t *arg, image_t **img, text_t **text)
{
    int check;
    sfRenderWindow_clear(arg->window, sfBlack);
    arg->mouse = sfMouse_getPosition((sfWindow*) arg->window);
    check = do_event(arg, img, text);
    if (check == 1){
        return 1;
    }
    if (arg->pause == 1){
        sfRenderWindow_setMouseCursorVisible(arg->window, sfTrue);
        display_pause(arg, img, text);
    } else {
        sfRenderWindow_setMouseCursorVisible(arg->window, sfFalse);
        check = display_game(arg, img, text);
        if (check == 1)
            return 1;
    }
    return 0;
}
