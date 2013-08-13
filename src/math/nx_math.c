/***************************************************************************\
  This file is part of the NxDragon Game Engine.

  Copyright 2013 Patrik Jeppsson
  
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

#include "nx_math.h"

#include <math.h>

/*************************************************************/
nxint32 nx_sqrt(nxint32 value)
{
    return (nxint32)sqrt(value);
}

/*************************************************************/
nxreal nx_sqrtf(nxreal value)
{
    return (nxreal)sqrt(value);
}

/*************************************************************/
nxint32 nx_pow(nxint32 base, nxint32 power)
{
    return (nxint32)pow(base, power);
}

/*************************************************************/
nxreal nx_powf(nxreal base, nxreal power)
{
    return (nxreal)pow(base, power);
}
