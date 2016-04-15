/*
** core.h for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Feb 20 15:23:59 2016 Arthur Josso
** Last update Thu Apr 14 14:35:25 2016 Arthur Josso
*/

#ifndef CORE_H_
# define CORE_H_

#include <lapin.h>

#define MAP(x, ba, ea, bb, eb) ((((ba - x) / (ba - ea)) * (eb - bb)) + bb)
#define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct s_vec
{
  float x;
  float y;
  float z;
} t_vec;

typedef struct s_ray
{
  t_vec alpha;
  t_vec beta;
} t_ray;

/*
** t_data
*/

typedef struct s_cam
{
  t_vec pos;
  t_vec rot;
} t_cam;

typedef struct s_refrac
{
  float ratio;
  float indice;
} t_refrac;

typedef struct s_perlin
{
  float ratio;
  float	persis;
  int	*tab;
  char	type;
} t_perlin;

typedef struct s_meta
{
  t_vec		pos;
  t_vec		rot;
  t_color       color;
  float         reflec;
  t_refrac      refrac;
  t_perlin      perlin;
  float         mirroring;
  t_bunny_pixelarray *tex;
} t_meta;

typedef struct s_sphere
{
  float         radius;
  t_meta	meta;
} t_sphere;

typedef struct s_cylinder
{
  float         radius;
  t_meta	meta;
} t_cylinder;

typedef struct s_cone
{
  float         angle;
  t_meta	meta;
} t_cone;

typedef struct s_torus
{
  float		radius;
  float		width;
  t_meta        meta;
} t_torus;

typedef struct s_light
{
  t_vec pos;
  float power;
} t_light;

typedef struct s_nb_item
{
  int   light;
  int   sphere;
  int   cylinder;
  int   cone;
  int	torus;
} t_nb_item;

typedef struct s_obj
{
  t_nb_item     nb;
  t_sphere      *sphere;
  t_cylinder    *cylinder;
  t_cone        *cone;
  t_torus	*torus;
  t_light       *light;
  t_cam         cam;
} t_obj;

typedef struct s_data
{
  t_bunny_window        *win;
  t_bunny_pixelarray    *pix;
  t_bunny_pixelarray    *big;
  t_bunny_pixelarray    *small;
  t_obj                 obj;
  unsigned char         gen_type;
} t_data;

typedef enum    e_exit
  {
    SUCCESS     = 0,
    ERROR       = 1
  }             t_exit;

#endif
