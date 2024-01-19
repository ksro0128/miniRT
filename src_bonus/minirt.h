/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:59:41 by surkim            #+#    #+#             */
/*   Updated: 2023/12/29 16:35:00 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include "./gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define SP 1
# define PL 2
# define CY 3
# define HB 4

typedef struct s_data			t_data;
typedef struct s_img			t_img;
typedef struct s_xyz			t_xyz;
typedef struct s_xyz			t_rgb;
typedef struct s_xyz			t_vec;
typedef struct s_abc			t_abc;
typedef struct s_matrix			t_matrix;
typedef struct s_amb			t_amb;
typedef struct s_light			t_light;
typedef struct s_cam			t_cam;
typedef struct s_sphere			t_sphere;
typedef struct s_plane			t_plane;
typedef struct s_cylinder		t_cylinder;
typedef struct s_ray			t_ray;
typedef struct s_hit			t_hit;
typedef struct s_veiwport		t_veiwport;
typedef struct s_hyperboloid	t_hyperboloid;
typedef struct s_opt			t_opt;

struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
};

struct s_xyz
{
	double	x;
	double	y;
	double	z;
};

struct s_abc
{
	double	a;
	double	b;
	double	c;
};

struct s_matrix
{
	t_xyz	x;
	t_xyz	y;
	t_xyz	z;
};

struct s_amb
{
	double	ratio;
	t_rgb	rgb;
};

struct s_cam
{
	t_xyz	o;
	t_vec	v;
	double	degrees;
};

struct s_light
{
	t_xyz	o;
	double	ratio;
	t_rgb	rgb;
	t_light	*next;
};

struct s_sphere
{
	t_xyz		o;
	double		d;
	t_rgb		rgb;
	t_matrix	nor;
	t_img		*img;
	t_img		*himg;
};

struct s_plane
{
	t_xyz		o;
	t_vec		v;
	t_rgb		rgb;
	t_matrix	nor;
	t_img		*img;
	t_img		*himg;
};

struct s_cylinder
{
	t_xyz		o;
	t_vec		v;
	double		d;
	double		h;
	t_rgb		rgb;
	t_matrix	nor;
	t_img		*img;
	t_img		*himg;
};

struct s_hyperboloid
{
	t_xyz		center;
	t_vec		v;
	t_matrix	abc;
	t_rgb		rgb;
	t_matrix	nor;
	t_img		*img;
	t_img		*himg;
};

struct s_ray
{
	t_xyz	o;
	t_vec	dir;
};

struct s_hit
{
	double	t_min;
	t_xyz	hit_point;
	t_vec	n_vec;
	t_rgb	rgb;
};

struct s_veiwport
{
	double	width;
	double	height;
	double	focal_length;
	t_vec	u;
	t_vec	v;
	t_vec	upper_left;
};

struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_img		image;
	t_img		texturemap;
	t_img		normalmap;
	int			win_width;
	int			win_height;
	int			status;
	int			checker;
	t_amb		amb;
	t_cam		cam;
	t_light		*light;
	t_veiwport	veiwport;
	t_list		*obj;
};

struct s_opt
{
	int			id;
	t_data		*data;
};

//libft
void		*ft_malloc(size_t size);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);

//control
void		checker_on(t_data *data);
int			press(int keycode, t_data *data);
int			xbutton(void);

//draw
void		draw(t_data *data);
void		my_mlx_pixel_put(t_img *img, int x, int y, t_rgb rgb);
int			isshadow(t_data *data, t_hit hit);
t_rgb		apply_phonglighting(t_data *data, t_hit hit);

//get_rgb
t_rgb		get_complementary_color(t_rgb color);

//hit
t_hit		check_hit(t_list *obj, t_ray ray, int flag);

// plane

t_hit		hit_plane(t_plane *pl, t_ray ray, int flag);
t_rgb		get_rgb_plane(t_plane *pl, t_hit hit, int flag);
t_vec		cal_pl_tbn_normal(t_plane *pl, t_hit hit);
t_rgb		get_pl_checker_rgb(double x, double y, t_rgb rgb);
t_rgb		get_pl_texture_rgb(double x, double y, t_img *img);
t_rgb		get_pl_normal_rgb(double x, double y, t_img *img);

// sphere
t_hit		hit_sphere(t_sphere *sp, t_ray ray, int flag);
t_rgb		get_rgb_sphere(t_sphere *sp, t_hit hit, int flag);
t_vec		cal_sp_tbn_normal(t_sphere *sp, t_hit hit);
t_rgb		get_sp_checker_rgb(double x, double y, t_rgb rgb);
t_rgb		get_sp_texture_rgb(double x, double y, t_img *img);
t_rgb		get_sp_normal_rgb(double x, double y, t_img *img);

// cylinder
t_hit		hit_cylinder(t_cylinder *cy, t_ray ray, int flag);
t_rgb		get_rgb_cylinder(t_cylinder *cy, t_hit hit, int flag);
t_rgb		cal_cy_tbn_normal(t_cylinder *cy, t_hit hit);
t_rgb		get_cy_checker_rgb(double x, double y, t_rgb rgb);
t_rgb		get_cy_texture_rgb(double x, double y, t_img *img);
t_rgb		get_cy_normal_rgb(double x, double y, t_img *img);

// hyperboloid
t_hit		hit_hyperboloid(t_hyperboloid *hb, t_ray ray, int flag);
t_vec		cal_normal_hb(t_hit hit, t_hyperboloid *hb);
t_rgb		get_rgb_hyperboloid(t_hyperboloid *hb, t_hit hit, int flag);
t_vec		cal_hb_tbn_normal(t_hyperboloid *hb, t_hit hit);
t_rgb		get_hb_checker_rgb(double x, double y, t_rgb rgb);
t_rgb		get_hb_texture_rgb(double x, double y, t_img *img);
t_rgb		get_hb_normal_rgb(double x, double y, t_img *img);

//parsing
//// ft_split_set.c
char		**ft_split_set(char *str, char *charset);

//// init.c
void		init(t_data *data);

//// parsing.c
void		parsing(t_data *data, char *filename);

//// ft_strtod.c
double		ft_strtod(char *str);

//// set_veiwport.c
t_veiwport	set_veiwport(t_data *data);

//// set.c
t_xyz		set_xyz(char *str);
t_rgb		set_rgb(char *str);
t_vec		set_vec(char *str);
void		check_comma(char *str);
void		check_three_elements(char **s);

// set_bumpmap
void		insert_normalmap(t_data *data);

//// paring_acl.c
void		parsing_amb(t_data *data, char **strstr);
void		parsing_cam(t_data *data, char **strstr);
void		parsing_light(t_data *data, char **strstr);

//// parsing_spplcy.c
void		parsing_sphere(t_data *data, char **strstr);
void		parsing_plane(t_data *data, char **strstr);
void		parsing_cylinder(t_data *data, char **strstr);

//// parsing_hyperboloid.c
void		parsing_hyperboloid(t_data *data, char **strstr);

// parsing_normalmap.c
void		parsing_normalmap(t_data *data, char **strstr);

//utils
//// utils.c
void		print_error(char *str);
void		ft_doublefree(char **obj);
double		max(double a, double b);
t_rgb		clamp_rgb(t_rgb rgb);
void		print_matrix(t_matrix a);

//// constructor.c
t_xyz		xyz(double x, double y, double z);
t_xyz		rgb(double x, double y, double z);
t_xyz		vec(double x, double y, double z);
t_ray		ray(t_xyz o, t_vec dir);
t_hit		hit_infinity(void);

//// vec_utils_*.c
t_vec		vplus(t_vec v1, t_vec v2);
t_vec		vminus(t_vec v1, t_vec v2);
t_vec		vmulv(t_vec v1, t_vec v2);
t_vec		vmuln(t_vec v, double d);
t_vec		vdivn(t_vec v, double d);
t_vec		vcross(t_vec v1, t_vec v2);
t_vec		vunit(t_vec v);
double		vdot(t_vec v1, t_vec v2);
double		vlength(t_vec v);
t_matrix	set_nor(t_vec v);
t_vec		cal_matrix_vec(t_matrix a, t_vec b);
t_matrix	transpose_matrix(t_matrix a);
t_matrix	cal_matrix_matrix(t_matrix a, t_matrix b);
//// cal_utils.c
double		cal_discriminant(t_abc abc);
double		cal_root(t_abc abc);

#endif
