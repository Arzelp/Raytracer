/*
** jif.h for jif in /home/alies_a/rendu/gfx_raytracer2/gif
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 13 17:17:18 2016 alies_a
** Last update Fri Apr 15 16:00:49 2016 alies_a
*/

#ifndef JIF_H_
#define JIF_H_

#include <stdint.h>
#include <lapin.h>

/*
** Jif lib
** save your pixelarrays in a file
*/

typedef struct s_jif_header
{
  uint32_t width;
  uint32_t height;
  uint32_t delay;
} __attribute__((packed)) t_jif_header;

typedef enum e_jif_mode
  {
    J_WRITE	= 1,
    J_READ	= 2
  } t_jif_mode;

typedef struct s_jif
{
  int fd;
  t_jif_header head;
  t_jif_mode mode;
} t_jif;

/*
** Write functions
*/
t_jif *jif_new(const char *file, int width, int height, int delay);
int jif_add(const t_jif *jif, const t_bunny_pixelarray *pix);

/*
** Read functions
*/

t_jif *jif_open(const char *file);
t_bunny_pixelarray *jif_next_load(const t_jif *jif);
int jif_next_fill(const t_jif *jif, t_bunny_pixelarray *pix);

/*
** Other
*/

void jif_close(t_jif *jif);

/*
** Camera save
*/

typedef struct s_jif_path
{
  t_jif_mode mode;
  int fd;
} t_jif_path;

t_jif_path *jif_path_open(const char *file, t_jif_mode mode);

int jif_path_write(t_jif_path *path, const void *cam);
int jif_path_read(t_jif_path *path, void *cam);

void jif_path_close(t_jif_path *path);

#endif
