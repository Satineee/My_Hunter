/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-2-myhunter-satine.fouque
** File description:
** init_arg.c
*/

#include "./include/my.h"

void init_arg(arg_t *arg)
{
    arg->video_mode = (sfVideoMode){1500, 1000, 32};
    arg->window = sfRenderWindow_create(arg->video_mode,
    "My hunter", sfClose, NULL);
    arg->replay = 0;
    arg->home = sfMusic_createFromFile("./sons/duel.ogg");
    arg->game = sfMusic_createFromFile("./sons/desert2.ogg");
    arg->kill = sfMusic_createFromFile("./sons/fusil.ogg");
    arg->game_over = sfMusic_createFromFile("./sons/game_over2.ogg");
    arg->pause = 0;
}

void reset_arg(arg_t *arg, text_t **text)
{
    arg->score = 0;
    arg->vie = 3;
    arg->clock_bird = sfClock_create();
    arg->clock_wing = sfClock_create();
    arg->speed_bird = 1;
    text[0]->pos.x = 1220.0f;
    text[0]->pos.y = 925.0f;
    int len = my_nbrlen(my_getnbr(text[1]->str));
    text[1]->pos.x = 1400.0f;
    (len > 3) ? text[1]->pos.x = 1350.0f :
    (len == 3) ? text[1]->pos.x = 1375.0f : 0;
    text[1]->pos.y = 925.0f;
    text[0]->str = "0";
}

int restart(arg_t *arg, image_t **img, text_t **text)
{
    sleep_5_sec(arg, img, text);
    my_itoa(arg, text);
    int check = page(img, arg, text);
    if (check == 1)
        return 1;
    return 0;
}
