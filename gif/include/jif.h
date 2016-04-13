/*
** jif.h for jif in /home/alies_a/rendu/gfx_raytracer2/gif
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 13 17:17:18 2016 alies_a
** Last update Wed Apr 13 18:04:32 2016 alies_a
*/

#ifndef JIF_H_
#define JIF_H_

#include <stdint.h>
#include <lapin.h>

#define JIF_MAGIC (0x21)

/*
** Jif lib
** save your pixelarrays in a file
*/

typedef struct s_jif_header
{
  char magic;
  uint32_t width;
  uint32_t height;
  uint32_t delay;
} __attribute__((packed)) t_jif_header;

typedef struct s_jif_pix
{
  char r;
  char g;
  char b;
} __attribute__((packed)) t_jif_pix;

typedef enum e_jif_mode
  {
    J_WRITE	= 1,
    J_READ	= 2
  } t_jif_mode;

typedef struct s_jif
{
  int fd;
  t_jif_mode mode;
} t_jif;

/*
** Write functions
*/
t_jif *jif_new(const char *file, int width, int height, int delay);
int jif_add(t_jif *jif, const t_bunny_pixelarray *pix);

/*
** Read functions
*/

t_jif *jif_open(const char *file);
t_bunny_pixelarray *jif_next(t_jif *jif);

/*
** Other
*/

void jif_close(t_jif *jif);

#endif
