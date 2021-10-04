#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = ft_lstnew((*f)(lst->content));
	list = tmp;
	lst = lst->next;
	while (lst)
	{
		if (!tmp)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		tmp->next = ft_lstnew((*f)(lst->content));
		tmp = tmp->next;
		lst = lst->next;
	}
	return (list);
}
