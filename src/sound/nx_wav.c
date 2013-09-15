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

#include "nx_wav.h"

#include "../kernel/nx_memory.h"

#include <stdio.h>

/*************************************************************/
static nxbool nx_wav_set_error(nx_wav *self, nx_sound_error error)
{
	self->error = error;
	return (self->error == NX_SOUND_NO_ERROR);
}

/*************************************************************/
void nx_wav_init(nx_wav *self)
{
	/* 32-bit members */
	self->chunk_size = 0;
	self->sample_rate = 0;
	self->avg_bytes_sec = 0;
	self->data_size = 0;

	/* 16-bit members */
	self->format_type = 0;
	self->channels = 0;
	self->bytes_per_sample = 0;
	self->bits_per_sample = 0;

	/* the error variable */
	self->error = NX_SOUND_NO_ERROR;

	/* the data */
	self->data = 0;
}

/*************************************************************/
void nx_wav_delete(nx_wav *self)
{
	nx_free(self->data);
}

/*************************************************************/
nxbool nx_wav_read(nx_wav *self, const char *name)
{
	char type[4];			/* type for a wav file are the letters "RIFF" */
	char format[4];			/* the format are the letters "WAVE" */
	char subchunk_1_id[4];	/* contains the letters "fmt ", note the space */
	char data_block[4];		/* contains the letters "data" */
	nxint32 size;
	FILE *file = 0;
	
	/* try to open file */
	file = fopen(name, "rb");
	if(!file)
		return nx_wav_set_error(self, NX_SOUND_RESOURCE_UNACCESSIBLE);

	/* read the 4 first bytes */
	fread(type, sizeof(char), 4, file);
	if(type[0] != 'R' || type[1] != 'I' || type[2] != 'F' || type[3] != 'F')
		return nx_wav_set_error(self, NX_SOUND_UNKNOWN_FORMAT);

	fread(&size, sizeof(nxint32), 1, file);

	/* read the formats 4 bytes */
	fread(format, sizeof(char), 4, file);
	if(format[0] != 'W' || format[1] != 'A' || format[2] != 'V' || format[3] != 'E')
		return nx_wav_set_error(self, NX_SOUND_INCOMPLETE_HEADER);

	fread(subchunk_1_id, sizeof(char), 4, file);
	if(subchunk_1_id[0] != 'f' || subchunk_1_id[1] != 'm' || subchunk_1_id[2] != 't' || subchunk_1_id[3] != ' ')
		return nx_wav_set_error(self, NX_SOUND_INCOMPLETE_HEADER);

	fread(&self->chunk_size, sizeof(nxint32), 1, file);
	fread(&self->format_type, sizeof(nxint16), 1, file);
	fread(&self->channels, sizeof(nxint16), 1, file);
	fread(&self->sample_rate, sizeof(nxint32), 1, file);
	fread(&self->avg_bytes_sec, sizeof(nxint32), 1, file);
	fread(&self->bytes_per_sample, sizeof(nxint16), 1, file);
	fread(&self->bits_per_sample, sizeof(nxint16), 1, file);

	fread(data_block, sizeof(char), 4, file);
	if(data_block[0] != 'd' || data_block[1] != 'a' || data_block[2] != 't' || data_block[3] != 'a')
		return nx_wav_set_error(self, NX_SOUND_INCOMPLETE_HEADER);

	/* Read the data-size, the actual length of the sound data. */
	fread(&self->data_size, sizeof(nxint32), 1, file);

	if(self->data_size <= 0)
		return nx_wav_set_error(self, NX_SOUND_EMPTY);

	/* Allocate a buffer large enough to hold the data */
	self->data = nx_malloc(sizeof(nx_sound_buffer) * self->data_size);

	/* Read the actual data */
	fread(self->data, sizeof(nx_sound_buffer), self->data_size, file);

	return nxtrue;
}

/*************************************************************/
nx_sound_error nx_wav_error(const nx_wav *self)
{
	return self->error;
}

/*************************************************************/
nx_sound_buffer* nx_wav_data(const nx_wav *self)
{
	return self->data;
}
