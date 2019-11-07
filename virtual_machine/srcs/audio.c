/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   audio.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 21:01:37 by tide-jon       #+#    #+#                */
/*   Updated: 2019/11/06 22:31:20 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int	play_audio(void)
{
	DWORD	chan;

	BASS_Init(1, 44100, 0, 0, NULL);
	chan = BASS_StreamCreateFile(
	FALSE, "./virtual_machine/srcs/Chiptronical.ogg", 0, 0, BASS_SAMPLE_LOOP);
	BASS_ChannelPlay(chan, FALSE);
	// while (BASS_ChannelIsActive(chan))
	// {
	// 	usleep(50000);
	// }
	// BASS_Free();
	return (0);
}
