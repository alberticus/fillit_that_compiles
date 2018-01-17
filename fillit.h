/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:22:48 by rperrone          #+#    #+#             */
/*   Updated: 2018/01/16 15:35:51 by atsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define box "##...##"
# define Z 	 "##....##"
# define Zup "#...##...#"
# define S	 "###..#"
# define Sup "#....##....#"
# define lineHori "####"
# define lineVert "#....#....#....#"
// # define L	 "###..#"
# define Lup "##....#....#"
# define Ldown "#....#....##"
# define Lside "#..###"
# define J "###....#"
# define Jup "##...#....#"
# define Jdown "#....#...##"
# define Jside "#....###"
# define T "###...#"
# define Tup "#...###"
# define Tleft "#...##....#"
# define Tright "#....##...#"

# define boxVal 0
# define ZVal 1
# define ZupVal 2
# define SVal 3
# define SupVal 4
# define HoriVal 5
# define VertVal 6
# define LVal 7
# define LupVal 8
# define LdownVal 9
# define LsideVal 10
# define JVal 11
# define JupVal 12
# define JdownVal 13
# define JsideVal 14
# define TVal 15
# define TupVal 16
# define TleftVal 17
# define TrightVal 18

# define Alpha "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void OneD_TwoD(char *input, char output[4][4]);
int piececounter(char **array);
char *delimit_tetro(char *clone);
char **split_into_tetro(char *input);
char *fileRead(char *path);
int	linesizefinder(char *input);
void reset(int *ps, int *lines, int *c);
int	validates(char *f);
int	cf1(char *input, int index, int line, int linesize);
int	cf2(char *input, int index, int line, int linesize);
int	cf3(char *input, int index, int line, int linesize);
void spotify(char **grid, int dimension);
void move_to_corner(char piece[][4]);
char* place_piece(char piece[][4], char **grid, int x, int y, char letter);
int can_place(int grid_x, int grid_y, char **grid, char piece[][4]);
void    findstar(int *x, int *y, char **grid, int dimension);
void    undo(char **grid, char character, int dimension);


// remove all the functions prototyped below this line later
char	*ft_strcpy(char *dst, const char *src);
size_t		ft_strlen(const char *str);
char	*ft_strdup(char *src);
char		**ft_strsplit(char const *s, char c);


#endif
/*
typedef struct      tetrispiece
{
    int width;
    int height;
    char blocks[4][4];
}
#endif

typedef struct		s_grid
{
	int				size;
	char			*content;
}					t_grid;

t_grid				*createGrid(int i);
void				freeGrid(t_grid *freeG);
void				freeAll(t_grid *freeG, int *freeA, char *freeF);

int					solveRecursive(t_grid *grd, int *intA, int arrayIndex);

#endif
*/
