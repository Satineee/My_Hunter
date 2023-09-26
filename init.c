/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-2-myhunter-satine.fouque
** File description:
** init.c
*/

#include "./include/my.h"

image_t *init_img(sfVector2f vector, sfIntRect rect, char const *file)
{
    image_t *img = malloc(sizeof(*img));
    img->pos = vector;
    img->rect = rect;
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    sfSprite *sprite = sfSprite_create();
    img->texture = texture;
    img->sprite = sprite;
    sfSprite_setTexture(img->sprite, img->texture, sfFalse);
    sfSprite_setTextureRect(img->sprite, img->rect);
    sfSprite_setPosition(img->sprite, img->pos);
    return (img);
}

image_t **array_img(void)
{
    image_t **img = malloc(sizeof(*img) * 15);
    img[0] = init_img((sfVector2f) {0.0f, 0.0f}, (sfIntRect) {0, 0, 1500, 1000},
    "img/western.jpg");
    img[1] = init_img((sfVector2f) {0.0f, 110.0f}, (sfIntRect) {0, 0, 127, 110},
    "img/vautour.png");
    img[2] = init_img((sfVector2f) {1300.0f, 15.0f}, (sfIntRect) {0, 0, 50, 50},
    "img/etoile.png");
    img[3] = init_img((sfVector2f) {1120, 840}, (sfIntRect) {0, 0, 170, 170},
    "img/score.png");
    img[4] = init_img((sfVector2f) {0, 0}, (sfIntRect) {200, 0, 1700, 1000},
    "img/bg_menu.png");
    array_img_2(img);
    return img;
}

void array_img_2(image_t **img)
{
    img[5] = init_img((sfVector2f) {270, 380}, (sfIntRect) {0, 0, 440, 212},
    "img/play.png");
    img[6] = init_img((sfVector2f) {1150, 485}, (sfIntRect) {127, 0, 127, 110},
    "img/vautour.png");
    img[7] = init_img((sfVector2f) {450, 200}, (sfIntRect) {0, 0, 577, 433},
    "img/game_over2.png");
    img[8] = init_img((sfVector2f) {0, 0}, (sfIntRect) {0, 0, 30, 30},
    "img/cible.png");
    img[9] = init_img((sfVector2f) {200, 50}, (sfIntRect) {0, 0, 600, 600},
    "img/end.png");
    img[10] = init_img((sfVector2f) {1320, 840}, (sfIntRect) {0, 0, 170, 170},
    "img/best_score.png");
    img[11] = init_img((sfVector2f) {420, 200}, (sfIntRect) {0, 0, 900, 512},
    "img/pause.png");
    img[12] = init_img((sfVector2f) {280, 580}, (sfIntRect) {0, 0, 440, 212},
    "img/quit.png");
    img[13] = init_img((sfVector2f) {280, 580}, (sfIntRect) {0, 0, 440, 212},
    "img/on_quit.png");
    img[14] = init_img((sfVector2f) {270, 380}, (sfIntRect) {0, 0, 440, 212},
    "img/on_play.png");
}

text_t *init_text(sfVector2f vector)
{
    text_t *text = malloc(sizeof(*text));
    text->text = sfText_create();
    text->font = sfFont_createFromFile("font/University.ttf");
    text->pos = vector;
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 40);
    sfText_setPosition(text->text, text->pos);
    sfText_setColor(text->text, sfBlack);
    return text;
}

text_t **array_text(void)
{
    text_t **text = malloc(sizeof(*text) * 3);
    text[0] = init_text((sfVector2f) {1220.0f, 925.0f});
    text[1] = init_text((sfVector2f) {1370.0f, 925.0f});
    return text;
}
