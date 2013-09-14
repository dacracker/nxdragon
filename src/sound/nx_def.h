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

#ifndef __NXDRAGON_SOUND_DEF_H__
#define __NXDRAGON_SOUND_DEF_H__

#include "../kernel/nx_platform.h"

#ifdef NXDRAGON_BUILD_SOUND
#	define NX_SOUND_API NX_EXPORT
#else
#	define NX_SOUND_API NX_IMPORT
#endif

#endif

