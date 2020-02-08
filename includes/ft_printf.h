/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <achambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 22:10:28 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 23:11:11 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/srcs/libft.h"
# include <stdarg.h>
# include <errno.h>
# include <unistd.h>
# include <wchar.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "macros_pf.h"

typedef struct	s_conv
{
	int			min_width;
	int			width_temp;
	int			precision;
	int			precision_set;
	int			ox;
	int			before;
	char		modif;
	char		sign;
	int			flag;
}				t_conv;

typedef struct	s_printf
{
	char		*format;
	va_list		ap;
	int			i;
	char		*str;
	int			len;
	int			n;
	char		*buffer;
	int			i_buf;
	int			subtract_buffer;
	int			add_buffer;
}				t_printf;

void			ft_error_pf(char *file, char *func, int line, char *s);
int				ft_printf(char *format, ...);
int				parse_type(char c);
int				parse_wildcard(t_printf *pf, t_conv *conv);
t_conv			*init_conv(void);
t_printf		*print_wint(t_printf *pf, wint_t wint);
t_printf		parsing_color(t_printf *pf);
t_printf		*buffer(t_printf *pf, char *saved, int len);
t_printf		*conversion_specifier(t_printf *pf, t_conv *conv);
t_printf		*parse_conversion(t_printf *pf);

int				count_wchars(t_conv *conv, wchar_t *wstr, int size);
int				ft_wstrlen(wchar_t *s);
void			conv_c(t_printf *pf, t_conv *conv);
t_conv			*option_char(t_printf *pf, int print_size, char c,
		t_conv *conv);
void			conv_s(t_printf *pf, t_conv *conv);
/*
**void			conv_s_file(t_printf *pf);
*/
void			conv_d(t_printf *pf, t_conv *conv);
int				conv_d_prec_only(t_printf *pf, t_conv *conv, int len,
		char *str);
int				conv_d_minus(t_printf *pf, t_conv *conv, int width_temp,
		char *str);
int				conv_d_width_only(t_printf *pf, t_conv *conv,
		int width_temp, char *str);
int				conv_d_prec_only(t_printf *pf, t_conv *conv, int len,
		char *str);
int				conv_d_hh_nominus(t_printf *pf, t_conv *conv, char *str,
		int len);
int				option_d(t_printf *pf, int n, char c, t_conv *conv);
char			*ft_itoa_printf(long long n);
void			conv_x(t_printf *pf, t_conv *conv);
int				conv_x_minus(t_printf *pf, t_conv *conv, char *str,
		int len);
int				conv_x_width_only(t_printf *pf, t_conv *conv, int len,
		char *str);
t_conv			option_x(t_printf *pf, int n, char c, t_conv *conv);
t_printf		*add_0x(t_printf *pf, t_conv *conv);
char			*ft_str_tolower(char *s);
t_conv			option_p(t_printf *pf, int n, char c, t_conv *conv);
intmax_t		ptr_number_base(t_printf *pf, int f);
uintmax_t		ptr_number(t_printf *pf, int f);
char			*ft_uitoa_pf(unsigned long n);
int				option(t_printf *pf, int c, size_t n);
int				conv_p(t_printf *pf, t_conv *conv);
int				print_p(t_printf *pf, t_conv *conv, int len, char *str);
int				conv_p_minus(t_printf *pf, t_conv *conv, int len,
		char *str);
int				add_char_and_string_2_buff(t_printf *pf, char c,
		char *str, int len);
int				minwidth_decr_add_char_2_buff(t_printf *pf, char c,
		t_conv *conv);
int				special_hhd_reverse_0_n_minus(t_printf *pf, char *str,
		char c);
void			conv_b(t_printf *pf, t_conv *conv);
void			conv_percent(t_printf *pf, t_conv *conv);
void			no_conv(t_printf *pf, t_conv *conv);

#endif
