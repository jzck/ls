#ifndef FTLS_H
# define FTLS_H
# define ALL_OPTS "lRart"
# include "libft.h"
# include <errno.h>
# include <dirent.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>

typedef struct	s_lsdata
{
	struct stat		stat;
	char			*path;
	struct dirent	*dirent;
}				t_lsdata;

typedef struct	s_pads
{
	int		nlink;
	int		name;
	int		gr_name;
	int		size;
}				t_pads;

void	ft_parse_ls(int ac, char **av, t_list **dir, t_list **ent, char *opts);
int		ft_parse_ls_options(int ac, char **av, char *opts);

void	ft_lsdata_filename(t_lsdata *data);
int		ft_lsdata_cmp_name(t_lsdata *dat1, t_lsdata *dat2);
int		ft_lsdata_cmp_time(t_lsdata *dat1, t_lsdata *dat2);
int		ft_lsdata_cmp0(t_lsdata *dat1, char *dataref);

void	ft_ent_filter(t_list **ent, char *opts);
void	ft_ent_sort(t_list **ent, char *opts);
void	ft_ent_print(t_list *ent, char *opts, t_lsdata *topdir, t_list *nextdir);

t_list	*ft_ent_get_dirs(t_list *ent);
t_list	*ft_dir_get_ents(t_lsdata *dir);

void	ft_ls_short(t_list *ent);
int		ft_ls_long(t_list *ent, t_lsdata *topdir);

void	ft_ls_long_total(t_list *ent);
int		ft_ls_long_pads(t_list *ent, t_pads *pads);
void	ft_ls_long_type(mode_t m);
void	ft_ls_long_rights(int st_mode);
int		ft_ls_long_xattr(char *path);
int		ft_ls_long_middle(struct stat *stat, t_pads *pads);
void	ft_ls_long_date(struct stat *stat);
int		ft_ls_long_lnk(t_lsdata *data);


void	ft_error_option(char c);
void	ft_error_dir(char *s);

#endif
