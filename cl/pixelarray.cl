
#define MAP(x, sA, eA, sB, eB) ((((sA - x) / (sA - eA)) * (eB - sB)) + sB)
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

typedef struct s_cam
{
  t_vec pos;
  float alpha;
  float beta;
} t_cam;

typedef struct s_cal
{
  float	a;
  float	b;
  float	c;
  float	d;
  float	t1;
  float	t2;
} t_cal;

typedef struct s_hit
{
  t_vec	hitpos;
  float	norm;
  int	hit;
} t_hit;

typedef union u_color
{
  int full;
  char argb[4];
} t_color;

typedef struct s_rt
{
  int width;
  int height;
  t_cam cam;
} t_rt;

t_ray		get_ray(t_cam me,
			int x,
			int y,
			t_rt rt)
{
  t_ray		ray;
  t_vec         res;
  float		beta;

  beta = -me.beta;
  res.x = sqrt(pow((float)rt.height, (float)2) + pow((float)rt.width, (float)2));
  res.y = ((rt.width / 2) - x);
  res.z = ((rt.height / 2) - y);
  ray.beta.x = res.x * cos(beta) + res.z * sin(beta);
  ray.beta.z = res.z * cos(beta) - res.x * sin(beta);
  res.x = ray.beta.x;
  ray.beta.x = res.x * cos(me.alpha) - res.y * sin(me.alpha);
  ray.beta.y = res.x * sin(me.alpha) + res.y * cos(me.alpha);
  ray.alpha.x = me.pos.x;
  ray.alpha.y = me.pos.y;
  ray.alpha.z = me.pos.z;
  return (ray);
}

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
  int x = id / rt->width;
  int y = id % rt->width;
  
  t_color c;
  c.full = 17777215;
  c = set_color(c, x, y, *rt);
  pixels[id] = c.full;
}
