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

#ifndef __NXDRAGON_SOUND_WAV_H__
#define __NXDRAGON_SOUND_WAV_H__

#include "nx_sound.h"

#include "../kernel/nx_types.h"

/** \ingroup NxSound
  * \defgroup nx_wav nx_wav
  * \brief A wav-type resource.
  *
  * TODO 
  * @{
  */

typedef struct nx_wav_t {
	nxint32 chunk_size,
			sample_rate,
			avg_bytes_sec,
			data_size;

	nxint16 format_type,
		    channels,
		    bytes_per_sample,
		    bits_per_sample;

	nx_sound_error error;
	
	nx_sound_buffer* data;
} nx_wav;

/** Initialises the object. */
NX_SOUND_API void nx_wav_init(nx_wav *self);

/** Deletes the objects data. */
NX_SOUND_API void nx_wav_delete(nx_wav *self);

/** Attemts to read the contents of 'name' to this object. */
NX_SOUND_API nxbool nx_wav_read(nx_wav *self, const char *name);

/** Returns the latest generated error. */
NX_SOUND_API nx_sound_error nx_wav_error(const nx_wav *self);

/** Returns the actual "sound-data" */
NX_SOUND_API nx_sound_buffer* nx_wav_data(const nx_wav *self);

#endif