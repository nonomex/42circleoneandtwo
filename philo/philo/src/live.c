/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:51:22 by aammirat          #+#    #+#             */
/*   Updated: 2023/11/13 17:57:28 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	eatingodd(t_philo *philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(philo->forkleft);
	pthread_mutex_lock(philo->forkright);
	writing ("has taken a fork\n", philo);
	writing ("has taken a fork\n", philo);
	goeat(philo);
	ret = 1;
	pthread_mutex_unlock(philo->forkright);
	pthread_mutex_unlock(philo->forkleft);
	return (ret);
}

void	next(t_philo *philo)
{
	usleep(10);
	writing("is sleeping\n", philo);
	usleep(philo->time_sleep * 1000);
	writing("is thinking\n", philo);
	usleep(1000);
}
