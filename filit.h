/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:54:29 by qhetting          #+#    #+#             */
/*   Updated: 2019/01/23 18:43:59 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FILIT_FILIT_H
# define FILIT_FILIT_H
#include "libft/libft.h"
#include "libft/get_next_line.h"
#define LOWER 4
#define HIGHER -4
#define LEFT_UP 0
#define RIGHT_UP 1
#define LEFT_DOWN 2
#define RIGHT_DOWN 3
char **generate_arrays(char **tet_inpt);
char *read_file(int fd);
int is_req_symbols(char **ch);
int ft_count_symbol(char *str, char ch);
int pre_parse(int fd, char **tetraminos);
void remove_symbols(char **s, char c);
int validate(char **tet_inpt,int flag);
int get_flag(char **tetramino) ;

#endif //FILIT_FILIT_H
