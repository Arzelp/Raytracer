
#define MAP(x, sA, eA, sB, eB) ((((sA - x) / (sA - eA)) * (eB - sB)) + sB)
#define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct s_pos
{
  float x;
  float y;
  float z;
} t_pos;

typedef struct s_ray
{
  t_pos alpha;
  t_pos beta;
} t_ray;


typedef struct s_rt
{
  int width;
  int height;
  t_ray cam;
} t_rt;

typedef union u_color
{
  int full;
  char argb[4];
} t_color;


/*
static void     get_ray(const t_cam *me,
			const t_bunny_position *sr,
			t_ray *ray)
{
  t_vec         res;
  double        beta;

  beta = -me->beta;
  res.x = sqrt(pow(HEIGHT, 2) + pow(WIDTH, 2));
  res.y = ((WIDTH / 2) - (double)sr->x);
  res.z = ((HEIGHT / 2) - (double)sr->y);
  ray->beta.x = res.x * cos(beta) + res.z * sin(beta);
  ray->beta.z = res.z * cos(beta) - res.x * sin(beta);
  res.x = ray->beta.x;
  ray->beta.x = res.x * cos(me->alpha) - res.y * sin(me->alpha);
  ray->beta.y = res.x * sin(me->alpha) + res.y * cos(me->alpha);
  ray->alpha.x = me->pos.x;
  ray->alpha.y = me->pos.y;
  ray->alpha.z = me->pos.z;
}*/

t_color set_color(t_color c, int x, int y, t_rt rt)
{
  c.argb[1] = MAP((float)x, 0, rt.width, 0, 255);
  c.argb[0] = MAP((float)y, 0, rt.height, 0, 255);
  return (c);
}

__kernel void calcpixel(__global unsigned int *pixels,
			__constant t_rt *rt)
{
  int id = get_global_id(0);
  int x;
  int y;
  t_color c;
  c.full = 17777215;

  y = id / rt->width;
  x = id % rt->width;

  c = set_color(c, x, y, *rt);
  //c.argb[1] = MAP((float)x, 0, rt->width, 0, 255);
  //c.argb[0] = MAP((float)y, 0, rt->height, 0, 255);
  pixels[id] = c.full;
}
