/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: co-neill <co-neill@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:47:02 by co-neill          #+#    #+#             */
/*   Updated: 2024/01/28 19:45:39 by co-neill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

// LINUX KEYCODES
# ifdef __linux__
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_PLUS 61
#  define KEY_MINUS 45
#  define KEY_M 109
#  define KEY_J 106
#  define KEY_B 98
#  define KEY_C 99
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5

// MACOS KEYCODES
# else
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_PLUS 24
#  define KEY_MINUS 27
#  define KEY_1 18
#  define KEY_2 19
#  define KEY_3 20
#  define KEY_4 21
#  define KEY_M 46
#  define KEY_J 38
#  define KEY_B 11
#  define KEY_C 8
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5
# endif

#endif
