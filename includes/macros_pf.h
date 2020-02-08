/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_pf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:34:23 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/28 21:30:34 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_PF_H
# define MACROS_PF_H
# define INFO __FILE__, (char *)__FUNCTION__, __LINE__
# define BUFFER_SIZE	1000
# define TYPE_S			(1 << 31)
# define TYPE_C			(1 << 30)
# define TYPE_D			(1 << 29)
# define TYPE_P			(1 << 28)
# define TYPE_X			(1 << 27)
# define TYPE_U			(1 << 26)
# define TYPE_O			(1 << 25)
# define TYPE_B			(1 << 24)
# define TYPE_PERCENT 	(1 << 23)
# define PREC_PARSE		(1 << 14)
# define PRECISION		(1 << 13)
# define MODIFIER_F		(1 << 12)
# define MODIFIER_X		(1 << 11)
# define MODIFIER_H		(1 << 10)
# define MODIFIER_HH	(1 << 9)
# define MODIFIER_L		(1 << 8)
# define MODIFIER_LL	(1 << 7)
# define MODIFIER_J		(1 << 6)
# define MODIFIER_Z		(1 << 5)
# define MINUS			(1 << 4)
# define PLUS			(1 << 3)
# define SHARP			(1 << 2)
# define ZERO			(1 << 1)
# define SPACE			(1 << 0)
# define LONGEST_COLOR	6
/*
 **init
*/
# define COLOR			"\033["
# define EOC			"0m"
# define BLACK			"30m"
# define RED			"31m"
# define GREEN			"32m"
# define YELLOW			"33m"
# define BLUE			"34m"
# define VIOLET			"35m"
# define CYAN			"36m"
# define WHITE			"37m"
# define LOG_CLEAR		\033[2K
# define LOG_UP			\033[A
# define LOG_NOCOLOR	\033[0m
# define LOG_BOLD		\033[1m
# define LOG_UNDERLINE	\033[4m
# define LOG_BLINKING	\033[5m
# define LOG_BLACK		\033[1;30m
# define LOG_RED		\033[1;31m
# define LOG_GREEN		\033[1;32m
# define LOG_YELLOW		\033[1;33m
# define LOG_BLUE		\033[1;34m
# define LOG_VIOLET		\033[1;35m
# define LOG_CYAN		\033[1;36m
# define LOG_WHITE		\033[1;37m
#endif
