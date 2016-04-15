
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

float   det(float a, float b, float c)
{
  return (pow(b, (float)2) - (4 * a * c));
}

t_vec   equ_para(t_ray ray, float t1)
{
  t_vec res;

  res.x = (ray.alpha).x + (ray.beta).x * t1;
  res.y = (ray.alpha).y + (ray.beta).y * t1;
  res.z = (ray.alpha).z + (ray.beta).z * t1;
  return (res);
}

float	vec_norm(t_vec Va, t_vec Vb)
{
  float	a;
  float	b;
  float	c;

  a = Vb.x - Va.x;
  b = Vb.y - Va.y;
  c = Vb.z - Va.z;
  return (sqrt(pow(a, 2.0) + pow(b, 2.0) + pow(c, 2.0)));
}

t_hit           sphere(t_ray ray,
		       float size)
{
  t_hit         res;
  t_cal         calc;
  t_vec		pos;

  pos.x = 0;
  pos.y = 0;
  pos.z = 0;

  calc.a = (pow((ray.beta).x, 2) + pow((ray.beta).y, 2) +
	    pow((ray.beta).z, 2));
  
  calc.b = 2 * (((ray.beta).x) * ((ray.alpha).x - pos.x) +
		((ray.beta).y) * ((ray.alpha).y - pos.y) +
		((ray.beta).z) * ((ray.alpha).z - pos.z));
  
  calc.c = pow((ray.alpha).x, 2.0) + pow((ray.alpha).y, 2.0) +
    pow((ray.alpha).z, 2.0) + pow(pos.x, 2.0) +
    pow(pos.y, 2.0) + pow(pos.z, 2.0) - 2 *
    (((ray.alpha).x * pos.x) + ((ray.alpha).y * pos.y) +
     ((ray.alpha).z * pos.z)) - pow(size, 2.0);
  calc.d = det(calc.a, calc.b, calc.c);
  res.hit = 0;
  if (calc.d < 0)
    return (res);
  calc.t1 = (-calc.b + sqrt(calc.d)) / (2 * calc.a);
  calc.t2 = (-calc.b - sqrt(calc.d)) / (2 * calc.a);
  if (calc.t1 < 0 || calc.t2 < 0)
    return (res);
  res.hitpos = equ_para(ray, (calc.t1 > calc.t2 ? calc.t2 : calc.t1));
  //set_hit_info(&res, &(ray.alpha), obj);
  res.hit = 1;
  res.norm = vec_norm(ray.alpha, res.hitpos);
  return (res);
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
  
  /*
  c.full = 17777215;
  c = set_color(c, x, y, *rt);
  */

  t_ray ray;
  t_hit hit;
  ray = get_ray(rt->cam, x, y, *rt);
  hit = sphere(ray, 1.0);
  if (hit.hit == 1)
    c.full = 17777215;
  else
    c.full = 13777215;
  pixels[id] = c.full;
}
