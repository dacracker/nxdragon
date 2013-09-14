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

#ifndef __NXDRAGON_SOUND_SOUND_H__
#define __NXDRAGON_SOUND_SOUND_H__

#include "nx_def.h"

#include "../kernel/nx_bool.h"

/** Macro that identifier a raw sound data buffer. */
#define nx_sound_buffer unsigned char

/** Enum that defines all the sound errors. */
typedef enum nx_sound_error_t {
	NX_SOUND_NO_ERROR = 0,
	NX_SOUND_UNKNOWN_ERROR,
	NX_SOUND_FILE_ACCESS_DENIED,
	NX_SOUND_UNKNOWN_FORMAT,
	NX_SOUND_DIFFERENT_FORMAT
} nx_sound_error;

/** Enum that defines all the supported sound-versions. */
typedef enum nx_sound_type_t {
	NX_WAV = 0
} nx_sound_type;

/** Attempts to open a file. Returns true if successful. */
NX_SOUND_API nxbool nx_sound_open_file(const char *name,
									   const nx_sound_type type,
									   nx_sound_buffer **buffer /* out */,
									   nx_sound_error *error /* out */);

#endif