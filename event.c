/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-2-myhunter-satine.fouque
** File description:
** event.c
*/

#include "./include/my.h"

int do_event(arg_t *arg, image_t **img, text_t **text)
{
    int check;
    while (sfRenderWindow_pollEvent(arg->window, &arg->event)){
        check = close_window(arg, img, text);
        if (check == 1)
            return 1;
        if (sfEvtKeyReleased == arg->event.type
            && arg->event.key.code == sfKeySpace) {
            set_pause(arg);
        }
        img[8]->pos.x = arg->mouse.x - 8;
        img[8]->pos.y = arg->mouse.y - 5;
        if (arg->pause == 0)
            kill_bird(arg, img, text);
        else {
            check = event_menu_pause(arg, img, text);
        }
        if (check == 1)
            return 1;
    }
    return 0;
}

int event_menu_pause(arg_t *arg, image_t **img, text_t **text)
{
    img[12]->pos.y = 700;
    img[12]->pos.x = 550;
    img[13]->pos.y = 700;
    img[13]->pos.x = 550;
    if (arg->mouse.x >= img[12]->pos.x
    && arg->mouse.x <= img[12]->pos.x + 400
        && arg->mouse.y >= img[12]->pos.y
    && arg->mouse.y <= img[12]->pos.y + 212){
        if (arg->event.type == sfEvtMouseButtonPressed){
            sfRenderWindow_close(arg->window);
            destroy_elt(arg, img, text);
            return 1;
        }
    }
    return 0;
}

void set_pause(arg_t *arg)
{
    if (arg->pause == 0){
        arg->pause = 1;
    } else if (arg->pause == 1) {
        arg->pause = 0;
    }
}

void kill_bird(arg_t *arg, image_t **img, text_t **text)
{
    if (arg->mouse.x >= img[1]->pos.x
        && arg->mouse.x <= img[1]->pos.x + 120
        && arg->mouse.y >= img[1]->pos.y
        && arg->mouse.y <= img[1]->pos.y + 120 ){
        if (arg->event.type == sfEvtMouseButtonPressed){
            sfMusic_play(arg->kill);
            sleep_sec(img, arg, text);
            img[1]->rect.left = 0;
            img[1]->pos.x = 0;
            img[1]->pos.y = rand() % 850;
            text[0]->str = malloc(sizeof(char) * (my_nbrlen(arg->score) + 1));
            set_score(arg, text);
            my_itoa(arg, text);
            sfClock_restart(arg->clock_bird);
        }
    }
}

void set_score(arg_t *arg, text_t **text)
{
    arg->score += 5;
    write_into_file(arg, text);
    (arg->score == 10) ? text[0]->pos.x -= 10 : 0;
    (arg->score == 20) ? text[0]->pos.x -= 15 : 0;
    (arg->score == 100) ? text[0]->pos.x -= 20 : 0;
    ((arg->score % 25) == 0 && arg->score != 0) ?
    arg->speed_bird += 0.5 : 0;
    int len = my_nbrlen(my_getnbr(text[1]->str));
    text[1]->pos.x = 1400.0f;
    (len > 3) ? text[1]->pos.x = 1350.0f :
    (len == 3) ? text[1]->pos.x = 1375.0f : 0;
}
