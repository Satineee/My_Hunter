/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-2-myhunter-satine.fouque
** File description:
** my.h
*/

#ifndef _MY_
    #define _MY_
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include<SFML/Graphics.h>
    #include<SFML/Window/Export.h>
    #include<SFML/Window.h>
    #include<SFML/System/Time.h>
    #include<SFML/System.h>
    #include<SFML/System/Clock.h>
    #include<time.h>
    #include<SFML/Graphics/Rect.h>
    #include<SFML/System/Vector2.h>
    #include<SFML/Audio.h>
    #include <stdio.h>

typedef struct image {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
} image_t;

typedef struct arg {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfVector2i mouse;
    sfEvent event;
    sfClock *clock_bird;
    sfTime t_bird;
    sfClock *clock_wing;
    sfTime t_wing;
    sfMusic *home;
    sfMusic *game;
    sfMusic *kill;
    sfMusic *game_over;
    int score;
    int vie;
    int replay;
    float speed_bird;
    int best_score;
    int pause;
} arg_t;

typedef struct text {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    char *str;
} text_t;

image_t *init_img(sfVector2f vector, sfIntRect rect, char const *file);
image_t **array_img(void);
void array_img_2(image_t **img);
text_t *init_text(sfVector2f vector);
text_t **array_text(void);

void init_arg(arg_t *arg);
void reset_arg(arg_t *arg, text_t **text);
int restart(arg_t *arg, image_t **img, text_t **text);

void bird_fly(arg_t *arg, image_t **img, text_t **text);
int start_game(arg_t *arg, image_t **img, text_t **text);
int display_pause(arg_t *arg, image_t **img, text_t **text);
int display_game(arg_t *arg, image_t **img, text_t **text);

int do_event(arg_t *arg, image_t **img, text_t **text);
int event_menu_pause(arg_t *arg, image_t **img, text_t **text);
void set_pause(arg_t *arg);
void kill_bird(arg_t *arg, image_t **img, text_t **text);
void set_score(arg_t *arg, text_t **text);

void display_window(arg_t *arg, image_t **img, text_t **text);
void display_img(arg_t *arg, image_t *img);
void display_text(arg_t *arg, text_t *text);
void display_vie(arg_t *arg, image_t *img);
void display_h(void);

void display_home(image_t **img, arg_t *arg, text_t **text);
void button_effect(image_t *img1, image_t *img2, arg_t *arg);
int close_window(arg_t *arg, image_t **img, text_t **text);
void display_end(image_t **img, arg_t *arg, text_t **text);
int game(arg_t *arg, image_t **img, text_t **text);

int page(image_t **img, arg_t *arg, text_t **text);
int click_play(arg_t *arg, image_t **img, text_t **text);
int play(arg_t *arg, image_t **img, text_t **text);
int event_play(arg_t *arg, image_t **img, text_t **text);

int my_strlen(char const *str);
int my_nbrlen(int nb);
char *my_revstr(char *str);
void my_itoa(arg_t *arg, text_t **text);
int my_getnbr(char const *str);

int read_file(text_t **text);
void write_into_file(arg_t *arg, text_t **text);

void sleep_sec(image_t **img, arg_t *arg, text_t **text);
void sleep_5_sec(arg_t *arg, image_t **img, text_t **text);

void destroy_elt(arg_t *arg, image_t **img, text_t **text);
void destroy_arg(arg_t *arg);
void destroy_img(image_t **img);
void destroy_text(text_t **text);

#endif
