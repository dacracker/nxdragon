/***************************************************************************\
This file is part of the NxDragon Game Engine.

Copyright 2013 Patrik Jeppsson, Ulf Johnsson

NxDragon is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

NxDragon is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with NxDragon. If not, see <http://www.gnu.org/licenses/>.
\***************************************************************************/

#include "nx_sound.h"

#include "../kernel/nx_def.h"

#include <stdio.h>

/*************************************************************/
static nxbool nx_sound_set_error(const nx_sound_error error_value, nx_sound_error *error_target)
{
	*error_target = error_value;
	return nxfalse;
}

/*************************************************************/
static nx_sound_error nx_sound_verify_wav(FILE *file)
{
	/* TODO: implement */
	NX_UNUSED(file);
	return NX_SOUND_UNKNOWN_ERROR;
}

/*************************************************************/
static nx_sound_error nx_sound_read_wav(FILE *file, nx_sound_buffer **buffer)
{
	/* TODO: implement */
	NX_UNUSED(file);
	NX_UNUSED(buffer);
	return NX_SOUND_UNKNOWN_ERROR;
}

/*************************************************************/
static nx_sound_error nx_sound_verify_type(const nx_sound_type type, FILE *file)
{
	switch(type)
	{
	case NX_WAV:
		return nx_sound_verify_wav(file);
	default:
		return NX_SOUND_UNKNOWN_FORMAT;
	}
}

/*************************************************************/
static nx_sound_error nx_sound_read_data(const nx_sound_type type, FILE *file, nx_sound_buffer **buffer)
{
	switch(type)
	{
	case NX_WAV:
		return nx_sound_read_wav(file, buffer);
	default:
		return NX_SOUND_UNKNOWN_FORMAT;
	}
}

/*************************************************************/
nxbool nx_sound_open_file(const char *name,
						  const nx_sound_type type,
						  nx_sound_buffer **buffer /* out */,
						  nx_sound_error *error /* out */)
{
	FILE *file = 0;
	
	/* try to open file */
	file = fopen(name, "rb");
	if(!file)
		return nx_sound_set_error(NX_SOUND_FILE_ACCESS_DENIED, error);

	/* verify that the file is off expected type */
	*error = nx_sound_verify_type(type, file);
	if(*error != NX_SOUND_NO_ERROR)
		return nxfalse;

	/* read the actual data */
	*error = nx_sound_read_data(type, file, buffer);
	if(*error != NX_SOUND_NO_ERROR)
		return nxfalse;

	return nxtrue;
}
