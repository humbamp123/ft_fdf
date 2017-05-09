/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:22:02 by apineda           #+#    #+#             */
/*   Updated: 2017/05/08 16:35:18 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>

# define G "\033[32;1m"
# define Y "\033[33;1m"
# define R "\033[31;1m"
# define B "\033[34;1m"
# define W "\033[0m"

# ifndef ERRS
#  define ERR(a, b) while(1){if(a){return(b);}break;}
#  define ERR1(a, b, c) while(1){if(a){b;return(c);}break;}
#  define ERW(a, b, c, d) while(1){if(a){b;printf(c);return(d);}break;}
# endif



#endif