//
// Copyright (C) 2017 Alexey Khokholov (Nuke.YKT)
// 
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
//
//  Nuked OPN2(Yamaha YM3438) emulator.
//  Thanks:
//      Silicon Pr0n:
//          Yamaha YM3438 decap and die shot(digshadow).
//      OPLx decapsulated(Matthew Gambrell, Olli Niemitalo):
//          OPL2 ROMs.
//
// version: 1.0.7
//

#ifndef YM3438_H
#define YM3438_H

enum {
    ym3438_type_discrete = 0,   /* Discrete YM3438 (Teradrive)          */
    ym3438_type_asic = 1,       /* ASIC YM3438 (MD1 VA7, MD2, MD3, etc) */
    ym3438_type_ym2612 = 2      /* YM2612 (MD1, MD2 VA2)                */
};

#include <stdint.h>

typedef uintptr_t       Bitu;
typedef intptr_t        Bits;
typedef uint64_t        Bit64u;
typedef int64_t         Bit64s;
typedef uint32_t        Bit32u;
typedef int32_t         Bit32s;
typedef uint16_t        Bit16u;
typedef int16_t         Bit16s;
typedef uint8_t         Bit8u;
typedef int8_t          Bit8s;

typedef struct _ym3438_t ym3438_t;

void OPN2_Reset(ym3438_t *chip);
void OPN2_SetChipType(Bit32u type);
void OPN2_Clock(ym3438_t *chip, Bit32u *buffer);
void OPN2_Write(ym3438_t *chip, Bit32u port, Bit8u data);
void OPN2_SetTestPin(ym3438_t *chip, Bit32u value);
Bit32u OPN2_ReadTestPin(ym3438_t *chip);
Bit32u OPN2_ReadIRQPin(ym3438_t *chip);
Bit8u OPN2_Read(ym3438_t *chip, Bit32u port);
#endif
