/*
** tetris.h for tetris in /home/kiwiv2/epitech/PSU/PSU_2016_SEM2/PSU_2016_tetris
** 
** Made by alexandre
** Login   <alexandre.caila@epitech.eu>
** 
** Started on  Tue Feb 21 18:38:10 2017 alexandre
** Last update Sun Mar 19 23:01:59 2017 alexandre
*/

#ifndef TETRIS_H_
# define TETRIS_H_

/*
** Help defines
*/

# define USAGE		"Usage:  ./tetris [options]\n"
# define OPTIONS	"Options:\n"

/*
** Flag defines for help
*/
# define HELP_FLAG	"  --help                  "
# define LEVEL_FLAG	"  -l --level={num}        "
# define LEFT_FLAG	"  -kl --key-left={K}      "
# define RIGHT_FLAG	"  -kr --key-right={K}     "
# define TURN_FLAG	"  -kt --key-turn={K}      "
# define DROP_FLAG	"  -kd --key-drop={K}      "
# define QUIT_FLAG	"  -kq --key-quit={K}      "
# define PAUSE_FLAG	"  -kp --key-pause={K}     "
# define MAPSIZE_FLAG	"  --map-size={row,col}    "
# define NEXT_FLAG	"  -w --without-next       "
# define DEBUG_FLAG	"  -d --debug              Debug mode (def: false)\n"

/*
** Flag descriptions defines for help
*/
# define HELP_DESC	"Display this help\n"
# define LEVEL_DESC	"Start Tetris at level num (def: 1)\n"
# define LEFT_DESC_1	"Move tetrimino on LEFT using the K key "
# define LEFT_DESC_2	"(def: left arrow)\n"
# define LEFT_DESC      LEFT_DESC_1 LEFT_DESC_2
# define RIGHT_DESC_1	"Move tetrimino on RIGHT using the K key"
# define RIGHT_DESC_2	" (def: right arrow)\n"
# define RIGHT_DESC     RIGHT_DESC_1 RIGHT_DESC_2
# define TURN_DESC_1	"TURN tetrimino clockwise 90d using the K key"
# define TURN_DESC_2	" (def: top arrow)\n"
# define TURN_DESC      TURN_DESC_1 TURN_DESC_2
# define DROP_DESC	"DROP the tetrimino using the K key (def: down arrow)\n"
# define QUIT_DESC	"QUIT the game using the K key (def: 'q' key)\n"
# define PAUSE_DESC	"PAUSE/RESTART the game using the K key (def: space)\n"
# define MAPSIZE_DESC_1	"Set the numbers of rows and columns of "
# define MAPSIZE_DESC_2	"the map (def: 20,10)\n"
# define MAPSIZE_DESC   MAPSIZE_DESC_1 MAPSIZE_DESC_2
# define NEXT_DESC	"Hide next tetrimino (def: false)\n"
# define DEBUG_DESC

/*
** Concatenation of help flags and their description
*/
# define HELP		HELP_FLAG HELP_DESC
# define LEVEL		LEVEL_FLAG LEVEL_DESC
# define LEFT		LEFT_FLAG LEFT_DESC
# define RIGHT		RIGHT_FLAG RIGHT_DESC
# define TURN		TURN_FLAG TURN_DESC
# define DROP		DROP_FLAG DROP_DESC
# define QUIT		QUIT_FLAG QUIT_DESC
# define PAUSE		PAUSE_FLAG PAUSE_DESC
# define MAPSIZE	MAPSIZE_FLAG MAPSIZE_DESC
# define NEXT		NEXT_FLAG NEXT_DESC
# define DEBUG		DEBUG_FLAG DEBUG_DESC

/*
** Game folder and file type
*/

# define PATH	"tetriminos/"
# define FILTER	".tetrimino"
# define TERM	"TERM="

/*
** Error types
*/
# define FATAL	-1
# define ERRO	84

/*
** Debug mode
*/

# define DEBUG_MODE	"*** DEBUG MODE ***\n"
# define KEY_LEFTS	"Key Left :"
# define KEY_RIGHTS	"Key Right :"
# define KEY_TURN	"Key Turn :"
# define KEY_DROP	"Key Drop :"
# define KEY_QUIT	"Key Quit :"
# define KEY_PAUSE	"Key Pause :"
# define NEXT_MODE	"Next :"
# define LEVEL_MODE	"Level :"
# define SIZE_MODE	"Size :"
# define TETRIMINOS	"Tetriminos :"
# define PRESS		"Press any key to start Tetris\n"

/*
** Board
*/
# define HIGHTSCORE	"| High score:  "
# define SCORE		"| Score:       "
# define LINES_BOARD	"| Lines:       "
# define LEVEL_BOARD	"| Level:       "
# define TIMER		"| Timer:       "

# define BASE		"0123456789"
# define EMPTY		-1
# define MAP_POS_X	1
# define MAP_POS_Y	1

typedef	struct	s_pos
{
  int		x;
  int		y;
  int		xpos;
  int		xmax;
  int		ymax;
}		t_pos;

typedef	struct		s_shape
{
  char			*name;
  int			height;
  int			width;
  int			color;
  char			**shape;
  struct s_shape	*next;
}			t_shape;

typedef	struct	s_shape_list
{
  int		len;
  t_shape	*first;
}		t_shape_list;

typedef	struct	s_state
{
  char		rotate;
  t_pos		pos;
  t_shape	*shape;
  t_shape	*next;
}		t_state;

typedef	struct	s_key
{
  char		*left;
  char	        *right;
  char		*turn;
  char		*drop;
  char		*quit;
  char		*pause;
}		t_key;

typedef	struct	s_game
{
  /* Destroyed lines */
  int		tlines;
  /* Display next piece ? */
  char		next;
  /* Your score */
  int		score;
  /* Your highscore */
  int		highscore;
  /* Level */
  int		level;
  /* Elapsed time */
  int		time;
  /* The map table */
  char		**map;
  /* List of keys */
  t_key		key;
  /* Actual piece */
  t_shape	*piece;
  /* Next piece */
  t_shape	*next_piece;
  /* Piece state */
  t_state	state;
  /* List of all shapes */
  t_shape_list	shapes;
}		t_game;

typedef	struct	s_tab
{
  char		*name;
  int		(*flags)(t_game *, char **);
}		t_tab;

int	can_go_left(char **map, int height, int width);
int	can_go_right(char **map, int height, int width);
void	move_right(char **map, int height, int width);
void	move_left(char **map, int height, int width);
int	commands(t_game *game);
int	print_next(t_shape *piece, int x, int y);
t_shape	*the_piece(t_game game);
int	touch_something(t_game *game);
int	my_maxlen(t_shape piece);
void	print_map(char **map, int height, int width);
int	tetri_down(t_game *game);
void	print_border(t_game *game);
int	launch_tetriminos(t_game *game, t_shape *piece);
int	my_highscore(t_game *game);
int	print_inform(t_game *game);
int	display_game(char **map, int xmax, int ymax);
int	map_generator(t_game *game);
int	my_tetris(t_game *game, char **av);
int	level_simpl(t_game *game, char **av);
int	left_simpl(t_game *game, char **av);
int	right_simpl(t_game *game, char **av);
int	turn_simpl(t_game *game, char **av);
int	drop_simpl(t_game *game, char **av);
int	quit_simpl(t_game *game, char **av);
int	pause_simpl(t_game *game, char **av);
int	get_nbr_atm(char *str, int nb);
int	level_next(t_game *game, char *str);
char	*puts_longkeys(char *str);
int	setting_term(char **env, char reset);
int	my_printf(char *str, ...);
int	debuger(char **av, t_game *game);
int	get_nbr(char *str);
int	level_longflag(t_game *game, char **av);
int	left_longflag(t_game *game, char **av);
int	right_longflag(t_game *game, char **av);
int	turn_longflag(t_game *game, char **av);
int	drop_longflag(t_game *game, char **av);
int	quit_longflag(t_game *game, char **av);
int	pause_longflag(t_game *game, char **av);
int	map_set(t_game *game, char **av);
int	next_set(t_game *game, char **av);
int	flags_handler(char **av, t_game *game);
char	*my_strcpy(char *str, char *dest);
int	get_nbr_stat(char *str);
int	header_read(t_shape *shape, int fd);
char	**my_str_to_wordtab(char *str);
char	*fill_name(char *name);
int	my_help();
int	my_strlen(char *str);
char	*my_cpy_atm(char *str, char *src, int nb);
int	my_strcmp(char *src, char *dest);
int	get_shapes(t_shape_list *list);
char	*my_strcat(char *str, char *dest);
int	my_endcmp(char *str, char *dest);
char	**my_tabcat(char **arr, char *str);
void	insert(t_shape_list *list, t_shape *elem);
char	tetriminos_is_valid(t_shape *shape, char need_content);
int	parse_nb(int *i, char **str);
int	my_error(char *str);
char	*my_itoa(int nb, char *str, int base);
int	clean_tetriminos(t_game *game);
int	realloc_full_table(t_game *game);
int	my_colors();
int	init_map(t_game *game);
void	move_down(char **map, int height, int width);
int	can_go_down(char **map, int height, int width);
float	my_pow(float nb, int rank);
int	final_map(t_game *game);
int	full_lines(t_game *game);
int	my_strcmp2(char *src, char *dest);

#endif /* !TETRIS_H_ */
