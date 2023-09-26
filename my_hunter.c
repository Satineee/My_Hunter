/*
** EPITECH PROJECT, 2022
** task1
** File description:
** open a window with csfml
*/

#include "./include/my.h"

void bird_fly(arg_t *arg, image_t **img, text_t **text)
{
    float seconds_bird = arg->t_bird.microseconds / 10000.0f;
    float seconds_wing = arg->t_wing.microseconds / 100000.0f;
    if (seconds_wing > 2.5){
        img[1]->rect.left += 127.0f;
        if (img[1]->rect.left == 381.0f) {
            img[1]->rect.left = 0.0f;
        }
        sfClock_restart(arg->clock_wing);
    }
    if (seconds_bird > 0.8f){
        img[1]->pos.x += 1 * arg->speed_bird;
        if (img[1]->pos.x >= 1500.0f) {
            arg->vie -= 1;
            img[1]->pos.x = 0;
        }
        sfClock_restart(arg->clock_bird);
    }
    display_window(arg, img, text);
}

int start_game(arg_t *arg, image_t **img, text_t **text)
{
    int check;
    reset_arg(arg, text);
    sfMusic_play(arg->game);
    sfMusic_setLoop(arg->game, sfTrue);
    while (sfRenderWindow_isOpen(arg->window)) {
        check = game(arg, img, text);
        if (check == 1)
            return 1;
    }
    return 0;
}

int display_pause(arg_t *arg, image_t **img, text_t **text)
{
    display_img(arg, img[0]);
    display_vie(arg, img[2]);
    display_img(arg, img[3]);
    display_img(arg, img[10]);
    display_img(arg, img[1]);
    display_text(arg, text[0]);
    display_text(arg, text[1]);
    display_img(arg, img[11]);
    button_effect(img[12], img[13], arg);
    display_img(arg, img[8]);
    sfRenderWindow_display(arg->window);
}

int display_game(arg_t *arg, image_t **img, text_t **text)
{
    int check;
    arg->t_bird = sfClock_getElapsedTime(arg->clock_bird);
    arg->t_wing = sfClock_getElapsedTime(arg->clock_wing);
    sfMusic_stop(arg->kill);
    sfMusic_stop(arg->game_over);
    if (arg->vie == 0){
        arg->replay = 1;
        sfMusic_pause(arg->game);
        sfMusic_play(arg->game_over);
        check = restart(arg, img, text);
        if (check == 1)
            return 1;
    } else
        bird_fly(arg, img, text);
    return 0;
}

int main(int ac, char **av, char **env)
{
    if (ac > 2)
        return 84;
    if (ac == 2){
        if (av[1][0] == '-' && av[1][1] == 'h'){
            display_h();
            return 0;
        } else
            return 84;
    }
    if (env[0] == 0)
        return 84;
    image_t **img = array_img();
    arg_t *arg = malloc(sizeof(arg_t));
    init_arg(arg);
    text_t **text = array_text();
    arg->best_score = read_file(text);
    reset_arg(arg, text);
    page(img, arg, text);
    return 0;
}
