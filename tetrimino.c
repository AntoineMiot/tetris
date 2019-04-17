/*
** EPITECH PROJECT, 2018
** Tetris
** File description:
** Tetrimino error handling
*/

#include "my.h"
#include <sys/types.h>
#include <dirent.h>

void recup_name_tetriminos(tetrimino *tm)
{
    struct dirent *lecture;
    DIR *rep;
    int z = 0;
    int j = 0;

    rep = opendir("./tetriminos");
    if (rep == 0)
        exit(84);
    for (z; lecture = readdir(rep);)
        if (lecture->d_name[0] != '.')
            z++;
    closedir(rep);
    tm->nb_mino = z;
    rep = opendir("./tetriminos");
    tm->name_piece = malloc(sizeof(char*) * (z+1));
    for (; (lecture = readdir(rep));) {
        if (lecture->d_name[0] != '.') {
            tm->name_piece[j] = malloc(sizeof(char)*(my_strlen(lecture->d_name)+1));
            tm->name_piece[j] = my_strcpy(tm->name_piece[j], lecture->d_name);
            j++;
        }
    }
    tm->name_piece[j+1] = malloc(sizeof(char *));
    tm->name_piece[j+1] = NULL;
    // for (int i = 0; tm->name_piece[i] != NULL; i++)
    //     printf("%s\n", tm->name_piece[i]);
    closedir(rep);
}

void recup_disp_tetriminos_buff(tetrimino *tm, char *file, int i)
{

    struct stat s;
    char *buff;
    unsigned long fd;

    stat(file, &s);
    buff = malloc(sizeof(char) * s.st_size-1);
    fd = open(file, O_RDONLY);
    if (fd == -1)
        exit(84);
    read(fd, buff, s.st_size);
    close(fd);
    buff[s.st_size-1] = '\0';
    tm->disp_piece[i] = my_strcpy(tm->disp_piece[i], buff);
}

void recup_disp_tetriminos(tetrimino *tm)
{
    tm->disp_piece = malloc(sizeof(char *) * tm->nb_mino+1);
    for (int i = 0; i != tm->nb_mino; i++) {
        recup_disp_tetriminos_buff(tm, my_strcat("./tetriminos/",
        tm->name_piece[i]), i);
    }
    tm->disp_piece[tm->nb_mino] = NULL;

    // for (int i = 0; tm->disp_piece[i] != NULL; i++) {
    //     printf("%s\n", tm->name_piece[i]);
    //     printf("%s\n", tm->disp_piece[i]);
    // }
}

int test_len_sort(tetrimino *tm)
{
    for (int i = 0; i != tm->nb_mino-1; i++) {
        if (my_strlen(tm->name_piece[i]) > my_strlen(tm->name_piece[i+1]) && tm->name_piece[i+1] != NULL)
            return (-1);
    }
    return (0);
}

int test_sort(tetrimino *tm)
{
    for (int i = 0; i != tm->nb_mino-1; i++)
        for (int z = 0; tm->name_piece[i][z] != '.' && tm->name_piece[i+1][z] != '.' && tm->name_piece[i+1] != NULL; z++)
            if (tm->name_piece[i][z] > tm->name_piece[i+1][z])
                return (-1);
    
    return (0);
}

void sort_name_n_disp_tetriminos(tetrimino *tm)
{
    char *tmp;
    char *tmp2;

    // do {
    //     for (int i = 0; i != tm->nb_mino-1; i++) {
    //         if (my_strlen(tm->name_piece[i]) > my_strlen(tm->name_piece[i+1]) && tm->name_piece[i+1] != NULL) {
    //             tmp = my_strcpy(tmp, tm->name_piece[i]);
    //             tm->name_piece[i] = my_strcpy(tm->name_piece[i], tm->name_piece[i+1]);
    //             tm->name_piece[i+1] = my_strcpy(tm->name_piece[i+1], tmp);
    //             tmp2 = my_strcpy(tmp2, tm->disp_piece[i]);
    //             tm->disp_piece[i] = my_strcpy(tm->disp_piece[i], tm->disp_piece[i+1]);
    //             tm->disp_piece[i+1] = my_strcpy(tm->disp_piece[i+1], tmp2);
    //         }
    //     }
    // } while (test_len_sort(tm) != 0);
    // do {
    //     for (int i = 0; i != tm->nb_mino-1; i++) {
    //         if (my_strlen(tm->name_piece[i]) == my_strlen(tm->name_piece[i+1]) && tm->name_piece[i+1] != NULL) {
    //             for (int z = 0; z != my_strlen(tm->name_piece[i]); z++) {
    //                 if (tm->name_piece[i][z] > tm->name_piece[i+1][z]) {
    //                     tmp = my_strcpy(tmp, tm->name_piece[i]);
    //                     tm->name_piece[i] = my_strcpy(tm->name_piece[i], tm->name_piece[i+1]);
    //                     tm->name_piece[i+1] = my_strcpy(tm->name_piece[i+1], tmp);
    //                     tmp2 = my_strcpy(tmp2, tm->disp_piece[i]);
    //                     tm->disp_piece[i] = my_strcpy(tm->disp_piece[i], tm->disp_piece[i+1]);
    //                     tm->disp_piece[i+1] = my_strcpy(tm->disp_piece[i+1], tmp2);
    //                 }
    //             }
    //         }
    //     }
    // } while (test_sort(tm) != 0);

    

    

}

void tetrimino_distrib(tetrimino *tm)
{
    recup_name_tetriminos(tm);
    recup_disp_tetriminos(tm);
    sort_name_n_disp_tetriminos(tm);
}
