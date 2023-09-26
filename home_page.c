/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-2-myhunter-satine.fouque
** File description:
** home_page.c
*/

#include "./include/my.h"

int page(image_t **img, arg_t *arg, text_t **text)
{
    int check;
    sfRenderWindow_setMouseCursorVisible(arg->window, sfTrue);
    sfMusic_play(arg->home);
    sfMusic_setLoop(arg->home, sfTrue);
    while (sfRenderWindow_isOpen(arg->window)) {
        sfRenderWindow_clear(arg->window, sfBlack);
        arg->mouse = sfMouse_getPosition((sfWindow*) arg->window);
        (arg->replay == 0) ? display_home(img, arg, text) :
        display_end(img, arg, text);
        check = event_play(arg, img, text);
        if (check == 1)
            return 1;
        sfRenderWindow_display(arg->window);
    }
}

int event_play(arg_t *arg, image_t **img, text_t **text)
{
    int check;
    while (sfRenderWindow_pollEvent(arg->window, &arg->event)){
        check = play(arg, img, text);
        if (check == 1)
            return 1;
    }
    return 0;
}

int click_play(arg_t *arg, image_t **img, text_t **text)
{
    int check;
    if (arg->mouse.x >= img[5]->pos.x
    && arg->mouse.x <= img[5]->pos.x + 400
    && arg->mouse.y >= img[5]->pos.y
    && arg->mouse.y <= img[5]->pos.y + 212 ){
        if (arg->event.type == sfEvtMouseButtonPressed){
            sfMusic_pause(arg->home);
            check = start_game(arg, img, text);
        }
        if (check == 1)
            return 1;
    }
    return 0;
}

int play(arg_t *arg, image_t **img, text_t **text)
{
    int check;
    check = close_window(arg, img, text);
    if (check == 1)
        return 1;
    if (arg->mouse.x >= img[12]->pos.x
    && arg->mouse.x <= img[12]->pos.x + 400
    && arg->mouse.y >= img[12]->pos.y
    && arg->mouse.y <= img[12]->pos.y + 212 ){
        if (arg->event.type == sfEvtMouseButtonPressed){
            sfRenderWindow_close(arg->window);
            destroy_elt(arg, img, text);
            return 1;
        }
    }
    check = click_play(arg, img, text);
    if (check == 1)
        return 1;
    return 0;
}
