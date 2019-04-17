/*
** EPITECH PROJECT, 2018
** Tetris
** File description:
** Tetris game, main function
*/
#include "my.h"

int my_str_compare_snd(char *str, char *str_two)
{
    for (int i = 0; i != my_strlen(str); i++)
        if (str[i] != str_two[i])
            return (1);
    return (2);
}

int my_str_compare(char *str, char *str_two)
{
    int j;

    if (my_strlen(str) == my_strlen(str_two)) {
        j = my_str_compare_snd(str, str_two);
        if (j == 1)
            return (1);
    } else if (my_strlen(str) != my_strlen(str_two))
        return (1);
    return (0);
}

int my_str_compare_borne(char *str, char *str_two)
{
    if (my_strlen(str) < my_strlen(str_two))
        return (1);
    for (int i = 0; str[i] != '='; i++) {
        if (str[i] != str_two[i]) {
            return (1);
        }
    }
    return (0);
}

void disp_usage(void)
{
    my_putstr("Usage: ./tetris [options]\nOptions:\n--help\t\t\t");
    my_putstr("Display this help\n-L --level={num}\t");
    my_putstr("Start Tetris at level num (def: 1)\n");
    my_putstr("-l --key-left={K}\tMove the tetrimino LEFT");
    my_putstr("using the K key (def: left arrow)\n");
    my_putstr("-r --key-right={K}\tMove the tetrimino RIGHT using");
    my_putstr(" (def: right arrow)\n-t --key-turn={K}\tTURN the");
    my_putstr("tetrimino clockwise 90d using the K key (def: top arrow)");
    my_putstr("\n-d --key-drop={K}\tDROP the tretimino using the K key");
    my_putstr(" (def: down arrow)\n-d --key-drop={K}\tQUIT the K key");
    my_putstr(" (def: 'q' key\n-p --key-pause={K}\tPAUSE/RESTART the");
    my_putstr(" game using the K key (def: space bar)\n");
    my_putstr("--map-size={row,col}\tSet the numbers of rows and");
    my_putstr(" of the map (def: 20,10)\n");
    my_putstr("-w --without-next\tHide next tetrimino (def: false)\n");
    my_putstr("-D --debug\t\tDebug mode (def: false)\n");
    exit(0);
}

char *level_update_recup_nbr(char *str)
{
    int i = 0;
    int z = 0;
    char *nbr;

    for (i; str[i] != '='; i++);
    for (z = i; str[z] != '\0'; z++);
    nbr = malloc(sizeof(char) * (z-i));
    z = 0;
    for (i; str[i+1] != '\0'; i++) {
        nbr[z] = str[i+1];
        z++;
    }
    nbr[z] = '\0';
    return (nbr);
}

char *map_resize_update_recup_nbr_two(char *str)
{
    int i = 0;
    int z = 0;
    char *nbr;

    for (i; str[i] != ','; i++);
    for (z = i; str[z] != '\0'; z++);
    nbr = malloc(sizeof(char) * (z-i));
    z = 0;
    for (i; str[i+1] != '\0'; i++) {
        nbr[z] = str[i+1];
        z++;
    }
    nbr[z] = '\0';
    return (nbr);
}

char *map_resize_update_recup_nbr_one(char *str)
{
    int i = 0;
    int z = 0;
    char *nbr;

    for (i; str[i] != '='; i++);
    for (z = i; str[z] != ','; z++);    
    nbr = malloc(sizeof(char) * (z-i));
    z = 0;
    for (i; str[i+1] != ','; i++) {
        nbr[z] = str[i+1];
        z++;
    }
    nbr[z] = '\0';
    return (nbr);
}

void map_resize_update(int i, char **av, option *op)
{
    op->row = my_getnbr(map_resize_update_recup_nbr_one(av[i]));
    op->col = my_getnbr(map_resize_update_recup_nbr_two(av[i]));
}

void level_update(int i, char **av, option *op)
{
    if (my_str_compare_borne(av[i], "--level=") == 0)
        op->lvl = my_getnbr(level_update_recup_nbr(av[i]));
    else if (my_str_compare(av[i], "-L") == 0)
        op->lvl = my_getnbr(av[i+1]);
}

void moove_left_update(int i, char **av, option *op)
{
    if (my_str_compare_borne(av[i], "--key-left=") == 0)
        op->mv_left = av[i][11];
    else if (my_str_compare(av[i], "-l") == 0)
        op->mv_left = av[i+1][0];
}

void moove_right_update(int i, char **av, option *op)
{
    if (my_str_compare_borne(av[i], "--key-right=") == 0)
        op->mv_right = av[i][12];
    else if (my_str_compare(av[i], "-r") == 0)
        op->mv_right = av[i+1][0];
}

void moove_turn_update(int i, char **av, option *op)
{
    if (my_str_compare_borne(av[i], "--key-turn=") == 0)
        op->mv_turn = av[i][11];
    else if (my_str_compare(av[i], "-t") == 0)
        op->mv_turn = av[i+1][0];
}

void moove_drop_update(int i, char **av, option *op)
{
    if (my_str_compare_borne(av[i], "--key-drop=") == 0)
        op->mv_drop = av[i][11];
    else if (my_str_compare(av[i], "-d") == 0)
        op->mv_drop = av[i+1][0];
}

void moove_quit_update(int i, char **av, option *op)
{
    if (my_str_compare_borne(av[i], "--key-quit=") == 0)
        op->quit = av[i][11];
    else if (my_str_compare(av[i], "-q") == 0)
        op->quit = av[i+1][0];
}

void moove_pause_update(int i, char **av, option *op)
{
    if (my_str_compare_borne(av[i], "--key-pause=") == 0)
        op->pause = av[i][12];
    else if (my_str_compare(av[i], "-p") == 0)
        op->pause = av[i+1][0];
}

int test_flag(int i, char **av, option *op)
{
    if (my_str_compare(av[i], "--help") == 0)
        disp_usage();
    
    if (my_str_compare_borne(av[i], "--level=") == 0 || my_str_compare(av[i], "-L") == 0)
        level_update(i, av, op);

    if (my_str_compare_borne(av[i], "--key-left=") == 0 || my_str_compare(av[i], "-l") == 0)
        moove_left_update(i, av, op);

    if (my_str_compare_borne(av[i], "--key-right=") == 0 || my_str_compare(av[i], "-r") == 0)
        moove_right_update(i, av, op);

    if (my_str_compare_borne(av[i], "--key-turn=") == 0 || my_str_compare(av[i], "-t") == 0)
        moove_turn_update(i, av, op);

    if (my_str_compare_borne(av[i], "--key-drop=") == 0 || my_str_compare(av[i], "-d") == 0)
        moove_drop_update(i, av, op);

    if (my_str_compare_borne(av[i], "--key-quit=") == 0 || my_str_compare(av[i], "-q") == 0)
        moove_quit_update(i, av, op);

    if (my_str_compare_borne(av[i], "--key-pause=") == 0 || my_str_compare(av[i], "-p") == 0)
        moove_pause_update(i, av, op);

    if (my_str_compare_borne(av[i], "--map-size=") == 0)
        map_resize_update(i, av, op);

    if (my_str_compare(av[i], "--without-next") == 0 || my_str_compare(av[i], "-w") == 0)
            op->hidden = 1;

    if (my_str_compare(av[i], "---debug") == 0 || my_str_compare(av[i], "-D") == 0)
            op->debug = 1;

}

void init_struct(option *op)
{
    op->lvl = 1;
    op->mv_left = 'D';
    op->mv_right = 'C';
    op->mv_turn = 'A';
    op->mv_drop = 'B';
    op->quit = 'q';
    op->pause = ' ';
    op->row = 20;
    op->col = 10;
    op->hidden = 0;
    op->debug = 0;
}

void disp_struct(option *op)
{
    printf("lvl = %i\n", op->lvl);
    printf("mv_left = %c\n", op->mv_left);
    printf("mv_right = %c\n", op->mv_right);
    printf("mv_turn = %c\n", op->mv_turn);
    printf("mv_drop = %c\n", op->mv_drop);
    printf("quit = %c\n", op->quit);
    printf("pause = %c\n", op->pause);
    printf("row = %i\n", op->row);
    printf("col = %i\n", op->col);
    printf("hidden = %i\n", op->hidden);
    printf("debug = %i\n", op->debug);
}

int check_file_piece(char *str)
{
    if (my_strlen(str) < 5)
        return (-1);
    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
        if (str[0] >= 49 && str[0] <= 57 && str[2] >= 49 && str[2] <= 57
            && str[4] >= 49 && str[4] <= 57)
            return (0);
    }
    return (-1);
}

void run_debug(option *op, tetrimino *tm)
{
    my_putstr("*** DEBUG MODE ***\nKey Left : ");
    if (op->mv_left == 32)
        my_putstr("(space)");
    else
        my_putchar(op->mv_left);
    my_putstr("\nKey Right : ");
    if (op->mv_right == 32)
        my_putstr("(space)");
    else
        my_putchar(op->mv_right);
    my_putstr("\nKey Turn : ");
    if (op->mv_turn == 32)
        my_putstr("(space)");
    else
        my_putchar(op->mv_turn);
    my_putstr("\nKey Drop : ");
    if (op->mv_drop == 32)
        my_putstr("(space)");
    else
        my_putchar(op->mv_drop);
    my_putstr("\nKey Quit : ");
    if (op->quit == 32)
        my_putstr("(space)");
    else
        my_putchar(op->quit);
    my_putstr("\nKey Pause : ");
    if (op->pause == 32)
        my_putstr("(space)");
    else
        my_putchar(op->pause);
    my_putstr("\nKey Next : ");
    if (op->hidden == 0)
        my_putstr("Yes");
    else if (op->hidden == 1)
        my_putstr("No");
    my_putstr("\nLevel : ");
    my_put_nbr(op->lvl);
    my_putstr("\nSize : ");
    my_put_nbr(op->row);
    my_putchar('*');
    my_put_nbr(op->col);
    my_putstr("\nTetriminos : ");
    my_put_nbr(tm->nb_mino);

    for (int i = 0; i != tm->nb_mino; i++) {
        my_putstr("\nTetriminos : Name ");
        for (int z = 0; tm->name_piece[i][z] != '.'; z++)
            my_putchar(tm->name_piece[i][z]);
        my_putstr(" : ");
        if (check_file_piece(tm->disp_piece[i]) == 0) {
            my_putstr("Size ");
            my_putchar(tm->disp_piece[i][0]);
            my_putchar('*');
            my_putchar(tm->disp_piece[i][2]);
            my_putstr(" : Color ");
            my_putchar(tm->disp_piece[i][4]);
            my_putstr(" :\n");
            for (int j = 6; tm->disp_piece[i][j] != '\0'; j++)
                my_putchar(tm->disp_piece[i][j]);
        } else
            my_putstr("Error");
    }
    my_putstr("\nPress any key to start Tetris\n");
}

int main(int ac, char **av)
{
    option op;
    tetrimino tm;
    
    init_struct(&op);
    if (ac > 1)
        for (int i = 1; i != ac; i++)
            if (av[i][0] == '-')
                test_flag(i, av, &op);
    tetrimino_distrib(&tm);
    if (op.debug == 1)
        run_debug(&op, &tm);

    return (0);
}