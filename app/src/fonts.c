﻿/**
******************************************************************************
* @file    fonts.c
* @author  Storozhenko Roman - D_EL
* @version V1.0.0
* @date
* @brief   массивы символов
******************************************************************************
*/

#include "fonts.h"

const uint8_t palette_tab[] = {
    //37 градаций
    0x00,0xE0,0xE4,0xE8,0xEC,0xF0,0xF4,0xF8,
    0xFC,0xDC,0xBC,0x9C,0x7C,0x5C,0x3C,0x1C,
    0x1D,0x1E,0x1F,0x1B,0x17,0x13,0x0F,0x0B,
    0x07,0x03,0x02,0x23,0x43,0x63,0x83,0xA3,
    0xC3,0xE3,0xE2,0xE1,0xFF,
};

//FONT_6X8
const char fonts6x8[] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x20
    0x04,0x0E,0x0E,0x04,0x04,0x00,0x04,0x00, // 0x21
    0x1B,0x1B,0x12,0x00,0x00,0x00,0x00,0x00, // 0x22
    0x00,0x0A,0x1F,0x0A,0x0A,0x1F,0x0A,0x00, // 0x23
    0x08,0x0E,0x10,0x0C,0x02,0x1C,0x04,0x00, // 0x24
    0x19,0x19,0x02,0x04,0x08,0x13,0x13,0x00, // 0x25
    0x08,0x14,0x14,0x08,0x15,0x12,0x0D,0x00, // 0x26
    0x0C,0x0C,0x08,0x00,0x00,0x00,0x00,0x00, // 0x27
    0x04,0x08,0x08,0x08,0x08,0x08,0x04,0x00, // 0x28
    0x08,0x04,0x04,0x04,0x04,0x04,0x08,0x00, // 0x29
    0x00,0x0A,0x0E,0x1F,0x0E,0x0A,0x00,0x00, // 0x2A
    0x00,0x04,0x04,0x1F,0x04,0x04,0x00,0x00, // 0x2B
    0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x08, // 0x2C
    0x00,0x00,0x00,0x1F,0x00,0x00,0x00,0x00, // 0x2D
    0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x00, // 0x2E
    0x00,0x01,0x02,0x04,0x08,0x10,0x00,0x00, // 0x2F
    0x0E,0x11,0x13,0x15,0x19,0x11,0x0E,0x00, // 0x30
    0x04,0x0C,0x04,0x04,0x04,0x04,0x0E,0x00, // 0x31
    0x0E,0x11,0x01,0x06,0x08,0x10,0x1F,0x00, // 0x32
    0x0E,0x11,0x01,0x0E,0x01,0x11,0x0E,0x00, // 0x33
    0x02,0x06,0x0A,0x12,0x1F,0x02,0x02,0x00, // 0x34
    0x1F,0x10,0x10,0x1E,0x01,0x11,0x0E,0x00, // 0x35
    0x06,0x08,0x10,0x1E,0x11,0x11,0x0E,0x00, // 0x36
    0x1F,0x01,0x02,0x04,0x08,0x08,0x08,0x00, // 0x37
    0x0E,0x11,0x11,0x0E,0x11,0x11,0x0E,0x00, // 0x38
    0x0E,0x11,0x11,0x0F,0x01,0x02,0x0C,0x00, // 0x39
    0x00,0x00,0x0C,0x0C,0x00,0x0C,0x0C,0x00, // 0x3A
    0x00,0x00,0x0C,0x0C,0x00,0x0C,0x0C,0x08, // 0x3B
    0x02,0x04,0x08,0x10,0x08,0x04,0x02,0x00, // 0x3C
    0x00,0x00,0x1F,0x00,0x00,0x1F,0x00,0x00, // 0x3D
    0x08,0x04,0x02,0x01,0x02,0x04,0x08,0x00, // 0x3E
    0x0E,0x11,0x01,0x06,0x04,0x00,0x04,0x00, // 0x3F
    0x0E,0x11,0x17,0x15,0x17,0x10,0x0E,0x00, // 0x40
    0x0E,0x11,0x11,0x11,0x1F,0x11,0x11,0x00, // 0x41
    0x1E,0x11,0x11,0x1E,0x11,0x11,0x1E,0x00, // 0x42
    0x0E,0x11,0x10,0x10,0x10,0x11,0x0E,0x00, // 0x43
    0x1E,0x11,0x11,0x11,0x11,0x11,0x1E,0x00, // 0x44
    0x1F,0x10,0x10,0x1E,0x10,0x10,0x1F,0x00, // 0x45
    0x1F,0x10,0x10,0x1E,0x10,0x10,0x10,0x00, // 0x46
    0x0E,0x11,0x10,0x17,0x11,0x11,0x0F,0x00, // 0x47
    0x11,0x11,0x11,0x1F,0x11,0x11,0x11,0x00, // 0x48
    0x0E,0x04,0x04,0x04,0x04,0x04,0x0E,0x00, // 0x49
    0x01,0x01,0x01,0x01,0x11,0x11,0x0E,0x00, // 0x4A
    0x11,0x12,0x14,0x18,0x14,0x12,0x11,0x00, // 0x4B
    0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0x00, // 0x4C
    0x11,0x1B,0x15,0x11,0x11,0x11,0x11,0x00, // 0x4D
    0x11,0x19,0x15,0x13,0x11,0x11,0x11,0x00, // 0x4E
    0x0E,0x11,0x11,0x11,0x11,0x11,0x0E,0x00, // 0x4F
    0x1E,0x11,0x11,0x1E,0x10,0x10,0x10,0x00, // 0x50
    0x0E,0x11,0x11,0x11,0x15,0x12,0x0D,0x00, // 0x51
    0x1E,0x11,0x11,0x1E,0x12,0x11,0x11,0x00, // 0x52
    0x0E,0x11,0x10,0x0E,0x01,0x11,0x0E,0x00, // 0x53
    0x1F,0x04,0x04,0x04,0x04,0x04,0x04,0x00, // 0x54
    0x11,0x11,0x11,0x11,0x11,0x11,0x0E,0x00, // 0x55
    0x11,0x11,0x11,0x11,0x11,0x0A,0x04,0x00, // 0x56
    0x11,0x11,0x15,0x15,0x15,0x15,0x0A,0x00, // 0x57
    0x11,0x11,0x0A,0x04,0x0A,0x11,0x11,0x00, // 0x58
    0x11,0x11,0x11,0x0A,0x04,0x04,0x04,0x00, // 0x59
    0x1E,0x02,0x04,0x08,0x10,0x10,0x1E,0x00, // 0x5A
    0x0E,0x08,0x08,0x08,0x08,0x08,0x0E,0x00, // 0x5B
    0x00,0x10,0x08,0x04,0x02,0x01,0x00,0x00, // 0x5C
    0x0E,0x02,0x02,0x02,0x02,0x02,0x0E,0x00, // 0x5D
    0x04,0x0A,0x11,0x00,0x00,0x00,0x00,0x00, // 0x5E
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F, // 0x5F
    0x0C,0x0C,0x04,0x00,0x00,0x00,0x00,0x00, // 0x60
    0x00,0x00,0x0E,0x01,0x0F,0x11,0x0F,0x00, // 0x61
    0x10,0x10,0x1E,0x11,0x11,0x11,0x1E,0x00, // 0x62
    0x00,0x00,0x0E,0x11,0x10,0x11,0x0E,0x00, // 0x63
    0x01,0x01,0x0F,0x11,0x11,0x11,0x0F,0x00, // 0x64
    0x00,0x00,0x0E,0x11,0x1E,0x10,0x0E,0x00, // 0x65
    0x06,0x08,0x08,0x1E,0x08,0x08,0x08,0x00, // 0x66
    0x00,0x00,0x0F,0x11,0x11,0x0F,0x01,0x0E, // 0x67
    0x10,0x10,0x1C,0x12,0x12,0x12,0x12,0x00, // 0x68
    0x04,0x00,0x04,0x04,0x04,0x04,0x06,0x00, // 0x69
    0x02,0x00,0x06,0x02,0x02,0x02,0x12,0x0C, // 0x6A
    0x10,0x10,0x12,0x14,0x18,0x14,0x12,0x00, // 0x6B
    0x04,0x04,0x04,0x04,0x04,0x04,0x06,0x00, // 0x6C
    0x00,0x00,0x1A,0x15,0x15,0x11,0x11,0x00, // 0x6D
    0x00,0x00,0x1C,0x12,0x12,0x12,0x12,0x00, // 0x6E
    0x00,0x00,0x0E,0x11,0x11,0x11,0x0E,0x00, // 0x6F
    0x00,0x00,0x1E,0x11,0x11,0x11,0x1E,0x10, // 0x70
    0x00,0x00,0x0F,0x11,0x11,0x11,0x0F,0x01, // 0x71
    0x00,0x00,0x16,0x09,0x08,0x08,0x1C,0x00, // 0x72
    0x00,0x00,0x0E,0x10,0x0E,0x01,0x0E,0x00, // 0x73
    0x00,0x08,0x1E,0x08,0x08,0x0A,0x04,0x00, // 0x74
    0x00,0x00,0x12,0x12,0x12,0x16,0x0A,0x00, // 0x75
    0x00,0x00,0x11,0x11,0x11,0x0A,0x04,0x00, // 0x76
    0x00,0x00,0x11,0x11,0x15,0x1F,0x0A,0x00, // 0x77
    0x00,0x00,0x12,0x12,0x0C,0x12,0x12,0x00, // 0x78
    0x00,0x00,0x12,0x12,0x12,0x0E,0x04,0x18, // 0x79
    0x00,0x00,0x1E,0x02,0x0C,0x10,0x1E,0x00, // 0x7A
    0x06,0x08,0x08,0x18,0x08,0x08,0x06,0x00, // 0x7B
    0x04,0x04,0x04,0x00,0x04,0x04,0x04,0x00, // 0x7C
    0x0C,0x02,0x02,0x03,0x02,0x02,0x0C,0x00, // 0x7D
    0x0A,0x14,0x00,0x00,0x00,0x00,0x00,0x00, // 0x7E
    0x04,0x0E,0x1B,0x11,0x11,0x1F,0x00,0x00, // 0x7F

    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x80
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x81
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x82
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x83
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x84
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x85
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x86
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x87
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x88
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x89
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x8A
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x8B
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x8C
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x8D
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x8E
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x8F

    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x90
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x91
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x92
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x93
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x94
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x95
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x96
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x97
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x98
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x99
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x9A
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x9B
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x9C
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x9D
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x9E
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0x9F

    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0xA0
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0xA1
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0xA2
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0xA3
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0xA4
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0xA5
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0xA6
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0xA7
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0xA8
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0xA9
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0xAA
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0xAB
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0xAC
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0xAD
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0xAE
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // 0xAF

    0x0C,0x12,0x12,0x0C,0x00,0x00,0x00,0x00, // 0xB0   °
    0x1F,0x11,0x11,0x11,0x1b,0x0A,0x1b,0x00, // 0xB1   Omega
};

// Author             : MCD Application Team
const unsigned char fonts8x12[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x20
    0x00, 0x18, 0x3c, 0x3c, 0x3c, 0x18, 0x18, 0x00, 0x18, 0x18, 0x00, 0x00, // 0x21
    0x00, 0x66, 0x66, 0x66, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x22
    0x00, 0x6c, 0x6c, 0xfe, 0x6c, 0x6c, 0x6c, 0xfe, 0x6c, 0x6c, 0x00, 0x00, // 0x23
    0x18, 0x7c, 0xc6, 0xc2, 0xc0, 0x7c, 0x06, 0x86, 0xc6, 0x7c, 0x18, 0x00, // 0x24
    0x00, 0x00, 0x00, 0xc2, 0xc6, 0x0c, 0x18, 0x30, 0x66, 0xc6, 0x00, 0x00, // 0x25
    0x00, 0x38, 0x6c, 0x6c, 0x38, 0x76, 0xdc, 0xcc, 0xcc, 0x76, 0x00, 0x00, // 0x26
    0x00, 0x18, 0x18, 0x18, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x27
    0x00, 0x0c, 0x18, 0x30, 0x30, 0x30, 0x30, 0x30, 0x18, 0x0c, 0x00, 0x00, // 0x28
    0x00, 0x30, 0x18, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x18, 0x30, 0x00, 0x00, // 0x29
    0x00, 0x00, 0x00, 0x66, 0x3c, 0xff, 0x3c, 0x66, 0x00, 0x00, 0x00, 0x00, // 0x2A
    0x00, 0x00, 0x00, 0x18, 0x18, 0x7e, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, // 0x2B
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x30, 0x00, // 0x2C
    0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x2D
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, // 0x2E
    0x00, 0x02, 0x06, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, // 0x2F
    0x00, 0x38, 0x6c, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x6c, 0x38, 0x00, 0x00, // 0x30
    0x00, 0x18, 0x38, 0x78, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7e, 0x00, 0x00, // 0x31
    0x00, 0x7c, 0xc6, 0x06, 0x0c, 0x18, 0x30, 0x60, 0xc6, 0xfe, 0x00, 0x00, // 0x32
    0x00, 0x7c, 0xc6, 0x06, 0x06, 0x3c, 0x06, 0x06, 0xc6, 0x7c, 0x00, 0x00, // 0x33
    0x00, 0x0c, 0x1c, 0x3c, 0x6c, 0xcc, 0xfe, 0x0c, 0x0c, 0x1e, 0x00, 0x00, // 0x34
    0x00, 0xfe, 0xc0, 0xc0, 0xc0, 0xfc, 0x06, 0x06, 0xc6, 0x7c, 0x00, 0x00, // 0x35
    0x00, 0x38, 0x60, 0xc0, 0xc0, 0xfc, 0xc6, 0xc6, 0xc6, 0x7c, 0x00, 0x00, // 0x36
    0x00, 0xfe, 0xc6, 0x06, 0x0c, 0x18, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, // 0x37
    0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0x7c, 0xc6, 0xc6, 0xc6, 0x7c, 0x00, 0x00, // 0x38
    0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0x7e, 0x06, 0x06, 0x0c, 0x78, 0x00, 0x00, // 0x39
    0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, // 0x3A
    0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x18, 0x18, 0x30, 0x00, 0x00, // 0x3B
    0x00, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x00, 0x00, // 0x3C
    0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, // 0x3D
    0x00, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x0c, 0x18, 0x30, 0x60, 0x00, 0x00, // 0x3E
    0x00, 0x7c, 0xc6, 0xc6, 0x0c, 0x18, 0x18, 0x00, 0x18, 0x18, 0x00, 0x00, // 0x3F
    0x00, 0x7c, 0xc6, 0xc6, 0xde, 0xde, 0xde, 0xdc, 0xc0, 0x7c, 0x00, 0x00, // 0x40
    0x00, 0x10, 0x38, 0x6c, 0xc6, 0xc6, 0xfe, 0xc6, 0xc6, 0xc6, 0x00, 0x00, // 0x41  A
    0x00, 0xfc, 0x66, 0x66, 0x66, 0x7c, 0x66, 0x66, 0x66, 0xfc, 0x00, 0x00, // 0x42  B
    0x00, 0x3c, 0x66, 0xc2, 0xc0, 0xc0, 0xc0, 0xc2, 0x66, 0x3c, 0x00, 0x00, // 0x43  C
    0x00, 0xf8, 0x6c, 0x66, 0x66, 0x66, 0x66, 0x66, 0x6c, 0xf8, 0x00, 0x00, // 0x44  D
    0x00, 0xfe, 0x66, 0x62, 0x68, 0x78, 0x68, 0x62, 0x66, 0xfe, 0x00, 0x00, // 0x45  E
    0x00, 0xfe, 0x66, 0x62, 0x68, 0x78, 0x68, 0x60, 0x60, 0xf0, 0x00, 0x00, // 0x46  F
    0x00, 0x3c, 0x66, 0xc2, 0xc0, 0xc0, 0xde, 0xc6, 0x66, 0x3a, 0x00, 0x00, // 0x47  G
    0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xfe, 0xc6, 0xc6, 0xc6, 0xc6, 0x00, 0x00, // 0x48  H
    0x00, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, // 0x49  I
    0x00, 0x1e, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0xcc, 0xcc, 0x78, 0x00, 0x00, // 0x4A  J
    0x00, 0xe6, 0x66, 0x6c, 0x6c, 0x78, 0x6c, 0x6c, 0x66, 0xe6, 0x00, 0x00, // 0x4B  K
    0x00, 0xf0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x62, 0x66, 0xfe, 0x00, 0x00, // 0x4C  L
    0x00, 0xc6, 0xee, 0xfe, 0xd6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x00, 0x00, // 0x4D  M
    0x00, 0xc6, 0xe6, 0xf6, 0xfe, 0xde, 0xce, 0xc6, 0xc6, 0xc6, 0x00, 0x00, // 0x4E  N
    0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x7c, 0x00, 0x00, // 0x4F  O
    0x00, 0xfc, 0x66, 0x66, 0x66, 0x7c, 0x60, 0x60, 0x60, 0xf0, 0x00, 0x00, // 0x50  P
    0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xd6, 0xde, 0x7c, 0x0e, 0x00, // 0x51  Q
    0x00, 0xfc, 0x66, 0x66, 0x66, 0x7c, 0x6c, 0x66, 0x66, 0xe6, 0x00, 0x00, // 0x52  R
    0x00, 0x7c, 0xc6, 0xc6, 0x60, 0x38, 0x0c, 0xc6, 0xc6, 0x7c, 0x00, 0x00, // 0x53  S
    0x00, 0x7e, 0x7e, 0x5a, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, // 0x54  T
    0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x7c, 0x00, 0x00, // 0x55  U
    0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x6c, 0x38, 0x10, 0x00, 0x00, // 0x56  V
    0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xd6, 0xd6, 0xfe, 0x6c, 0x6c, 0x00, 0x00, // 0x57  W
    0x00, 0xc6, 0xc6, 0xc6, 0x7c, 0x38, 0x7c, 0xc6, 0xc6, 0xc6, 0x00, 0x00, // 0x58  X
    0x00, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, // 0x59  Y
    0x00, 0xfe, 0xc6, 0x8c, 0x18, 0x30, 0x60, 0xc2, 0xc6, 0xfe, 0x00, 0x00, // 0x5A  Z
    0x00, 0x3c, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3c, 0x00, 0x00, // 0x5B  [
    0x00, 0x80, 0xc0, 0xe0, 0x70, 0x38, 0x1c, 0x0e, 0x06, 0x02, 0x00, 0x00, // 0x5C  '\'
    0x00, 0x3c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x3c, 0x00, 0x00, // 0x5D  ]
    0x10, 0x38, 0x6c, 0xc6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x5E  ^
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, // 0x5F  _
    0x00, 0x30, 0x18, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x60  `
    0x00, 0x00, 0x00, 0x00, 0x78, 0x0c, 0x7c, 0xcc, 0xcc, 0x76, 0x00, 0x00, // 0x61  a
    0x00, 0xe0, 0x60, 0x60, 0x78, 0x6c, 0x66, 0x66, 0x66, 0x7c, 0x00, 0x00, // 0x62  b
    0x00, 0x00, 0x00, 0x00, 0x7c, 0xc6, 0xc0, 0xc0, 0xc6, 0x7c, 0x00, 0x00, // 0x63  c
    0x00, 0x1c, 0x0c, 0x0c, 0x3c, 0x6c, 0xcc, 0xcc, 0xcc, 0x76, 0x00, 0x00, // 0x64  d
    0x00, 0x00, 0x00, 0x00, 0x7c, 0xc6, 0xfe, 0xc0, 0xc6, 0x7c, 0x00, 0x00, // 0x65  e
    0x00, 0x1c, 0x36, 0x32, 0x30, 0x7c, 0x30, 0x30, 0x30, 0x78, 0x00, 0x00, // 0x66  f
    0x00, 0x00, 0x00, 0x76, 0xcc, 0xcc, 0xcc, 0x7c, 0x0c, 0xcc, 0x78, 0x00, // 0x67  g
    0x00, 0xe0, 0x60, 0x60, 0x6c, 0x76, 0x66, 0x66, 0x66, 0xe6, 0x00, 0x00, // 0x68  h
    0x00, 0x18, 0x18, 0x00, 0x38, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, // 0x69  i
    0x00, 0x06, 0x06, 0x00, 0x0e, 0x06, 0x06, 0x06, 0x66, 0x66, 0x3c, 0x00, // 0x6A  j
    0x00, 0xe0, 0x60, 0x60, 0x66, 0x6c, 0x78, 0x6c, 0x66, 0xe6, 0x00, 0x00, // 0x6B  k
    0x00, 0x38, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, // 0x6C  l
    0x00, 0x00, 0x00, 0x00, 0xec, 0xfe, 0xd6, 0xd6, 0xd6, 0xd6, 0x00, 0x00, // 0x6D  m
    0x00, 0x00, 0x00, 0x00, 0xdc, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x00, // 0x6E  n
    0x00, 0x00, 0x00, 0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0x7c, 0x00, 0x00, // 0x6F  o
    0x00, 0x00, 0x00, 0xdc, 0x66, 0x66, 0x66, 0x7c, 0x60, 0x60, 0xf0, 0x00, // 0x70  p
    0x00, 0x00, 0x00, 0x00, 0x76, 0xcc, 0xcc, 0xcc, 0x7c, 0x0c, 0x0c, 0x1e, // 0x71  q
    0x00, 0x00, 0x00, 0x00, 0xdc, 0x76, 0x66, 0x60, 0x60, 0xf0, 0x00, 0x00, // 0x72  r
    0x00, 0x00, 0x00, 0x00, 0x7c, 0xc6, 0x70, 0x1c, 0xc6, 0x7c, 0x00, 0x00, // 0x73  s
    0x00, 0x10, 0x30, 0x30, 0xfc, 0x30, 0x30, 0x30, 0x36, 0x1c, 0x00, 0x00, // 0x74  t
    0x00, 0x00, 0x00, 0x00, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0x76, 0x00, 0x00, // 0x75  u
    0x00, 0x00, 0x00, 0x00, 0xc6, 0xc6, 0xc6, 0x6c, 0x38, 0x10, 0x00, 0x00, // 0x76  v
    0x00, 0x00, 0x00, 0x00, 0xc6, 0xc6, 0xd6, 0xd6, 0xfe, 0x6c, 0x00, 0x00, // 0x77  w
    0x00, 0x00, 0x00, 0x00, 0xc6, 0x6c, 0x38, 0x38, 0x6c, 0xc6, 0x00, 0x00, // 0x78  x
    0x00, 0x00, 0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0x7e, 0x06, 0x0c, 0x78, 0x00, // 0x79  y
    0x00, 0x00, 0x00, 0x00, 0xfe, 0xcc, 0x18, 0x30, 0x66, 0xfe, 0x00, 0x00, // 0x7A  z
    0x00, 0x0e, 0x18, 0x18, 0x18, 0x70, 0x18, 0x18, 0x18, 0x0e, 0x00, 0x00, // 0x7B  {
    0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, // 0x7C  |
    0x00, 0x70, 0x18, 0x18, 0x18, 0x0e, 0x18, 0x18, 0x18, 0x70, 0x00, 0x00, // 0x7D  }
    0x00, 0x76, 0xdc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x7E  ~
    0x00, 0x00, 0x00, 0x10, 0x38, 0x6c, 0xc6, 0xc6, 0xfe, 0x00, 0x00, 0x00, // 0x7F  del
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x80

    0x00, 0x00, 0x10, 0x10, 0x10, 0x92, 0x54, 0x38, 0x10, 0xfe, 0x00, 0x00, // 0x81 символ ограничения тока
    0x20, 0x30, 0x38, 0xFC, 0xFE, 0xFF, 0xFE, 0xFC, 0x38, 0x30, 0x20, 0x00, // 0x82 курсор
    0xff, 0xff, 0xff, 0x7e, 0x3c, 0x18, 0x18, 0x24, 0x42, 0x81, 0x81, 0xff, // 0x83 песочные часы 0
    0xff, 0x81, 0xff, 0x7e, 0x3c, 0x18, 0x18, 0x24, 0x42, 0x81, 0xff, 0xff, // 0x84 песочные часы 1
    0xff, 0x81, 0x81, 0x7e, 0x3c, 0x18, 0x18, 0x24, 0x42, 0xff, 0xff, 0xff, // 0x85 песочные часы 2
    0xff, 0x81, 0x81, 0x42, 0x3c, 0x18, 0x18, 0x24, 0x7e, 0xff, 0xff, 0xff, // 0x86 песочные часы 3
    0xff, 0x81, 0x81, 0x42, 0x24, 0x18, 0x18, 0x3c, 0x7e, 0xff, 0xff, 0xff, // 0x87 песочные часы 4
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x88
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x89
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x8A
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x8B
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x8C
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x8D
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x8E
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x8F

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x90
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x91
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x92
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x93
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x94
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x95
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x96
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x97
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x98
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x99
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x9A
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x9B
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x9C
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x9D
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x9E
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x9F

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xA0
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xA1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xA2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xA3
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xA4
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xA5
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xA6
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xA7
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xA8
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xA9
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xAA
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xAB
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xAC
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xAD
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xAE
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xAF

  0x00, 0x1c, 0x22, 0x22, 0x22, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xB0   °
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xB1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xB2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xB3
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xB4
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xB5
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xB6
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xB7
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xB8
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xB9
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xBA
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xBB
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xBC
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xBD
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xBE
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0xBF

    0x00, 0x10, 0x38, 0x6c, 0xc6, 0xc6, 0xfe, 0xc6, 0xc6, 0xc6, 0x00, 0x00, // 0xC0  А
    0x00, 0x7C, 0x40, 0x40, 0x40, 0x7C, 0x42, 0x42, 0x42, 0x7C, 0x00, 0x00, // 0xC1  Б
    0x00, 0xfc, 0x66, 0x66, 0x66, 0x7c, 0x66, 0x66, 0x66, 0xfc, 0x00, 0x00, // 0xC2  В
    0x00, 0x7C, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, // 0xC3  Г
    0x00, 0x1C, 0x24, 0x24, 0x24, 0x24, 0x24, 0x7E, 0x42, 0x42, 0x00, 0x00, // 0xC4  Д
    0x00, 0xfe, 0x66, 0x62, 0x68, 0x78, 0x68, 0x62, 0x66, 0xfe, 0x00, 0x00, // 0xC5  Е
    0x00, 0x54, 0x54, 0x54, 0x38, 0x38, 0x54, 0x54, 0x54, 0x54, 0x00, 0x00, // 0xC6  Ж
    0x00, 0x38, 0x44, 0x04, 0x04, 0x18, 0x04, 0x04, 0x44, 0x38, 0x00, 0x00, // 0xC7  З
    0x00, 0x42, 0x42, 0x42, 0x46, 0x4A, 0x52, 0x62, 0x42, 0x42, 0x00, 0x00, // 0xC8  И
    0x08, 0x52, 0x42, 0x42, 0x46, 0x4A, 0x52, 0x62, 0x42, 0x42, 0x00, 0x00, // 0xC9  Й
    0x00, 0xe6, 0x66, 0x6c, 0x6c, 0x78, 0x6c, 0x6c, 0x66, 0xe6, 0x00, 0x00, // 0xCA  К
    0x00, 0x1C, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x44, 0x00, 0x00, // 0xCB  Л
    0x00, 0xc6, 0xee, 0xfe, 0xd6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x00, 0x00, // 0xCC  М
    0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xfe, 0xc6, 0xc6, 0xc6, 0xc6, 0x00, 0x00, // 0xCD  Н
    0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x7c, 0x00, 0x00, // 0xCE  О
    0x00, 0x7E, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00, // 0xCF  П

    0x00, 0xfc, 0x66, 0x66, 0x66, 0x7c, 0x60, 0x60, 0x60, 0xf0, 0x00, 0x00, // 0xD0  Р
    0x00, 0x3c, 0x66, 0xc2, 0xc0, 0xc0, 0xc0, 0xc2, 0x66, 0x3c, 0x00, 0x00, // 0xD1  С
    0x00, 0x7e, 0x7e, 0x5a, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, // 0xD2  Т
    0x00, 0x44, 0x44, 0x44, 0x44, 0x44, 0x3C, 0x04, 0x44, 0x38, 0x00, 0x00, // 0xD3  У
    0x00, 0x7C, 0x92, 0x92, 0x92, 0x92, 0x7C, 0x10, 0x10, 0x10, 0x00, 0x00, // 0xD4  Ф
    0x00, 0x44, 0x44, 0x44, 0x28, 0x10, 0x28, 0x44, 0x44, 0x44, 0x00, 0x00, // 0xD5  Х
    0x00, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x7E, 0x02, 0x00, 0x00, // 0xD6  Ц
    0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3E, 0x02, 0x02, 0x02, 0x00, 0x00, // 0xD7  Ч
    0x00, 0x82, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0xFE, 0x00, 0x00, // 0xD8  Ш
    0x00, 0x82, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0xFE, 0x01, 0x00, // 0xD9  Щ
    0x00, 0xE0, 0x20, 0x20, 0x20, 0x3C, 0x22, 0x22, 0x22, 0x3C, 0x00, 0x00, // 0xDA  Ъ
    0x00, 0x42, 0x42, 0x42, 0x42, 0x72, 0x4A, 0x4A, 0x4A, 0x72, 0x00, 0x00, // 0xDB  Ы
    0x00, 0x20, 0x20, 0x20, 0x20, 0x3C, 0x22, 0x22, 0x22, 0x3C, 0x00, 0x00, // 0xDC  Ь
    0x00, 0x1C, 0x22, 0x02, 0x02, 0x1E, 0x02, 0x02, 0x22, 0x1C, 0x00, 0x00, // 0xDD  Э
    0x00, 0x4C, 0x52, 0x52, 0x52, 0x72, 0x52, 0x52, 0x52, 0x4C, 0x00, 0x00, // 0xDE  Ю
    0x00, 0x3C, 0x44, 0x44, 0x44, 0x3C, 0x24, 0x44, 0x44, 0x44, 0x00, 0x00, // 0xDF  Я

    0x00, 0x00, 0x00, 0x00, 0x78, 0x0c, 0x7c, 0xcc, 0xcc, 0x76, 0x00, 0x00, // 0xC0  а
    0x00, 0x7C, 0x40, 0x40, 0x40, 0x7C, 0x42, 0x42, 0x42, 0x7C, 0x00, 0x00, // 0xC1  Б
    0x00, 0x7C, 0x42, 0x42, 0x42, 0x7C, 0x42, 0x42, 0x42, 0x7C, 0x00, 0x00, // 0xC2  В
    0x00, 0x7C, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, // 0xC3  Г
    0x00, 0x1C, 0x24, 0x24, 0x24, 0x24, 0x24, 0x7E, 0x42, 0x42, 0x00, 0x00, // 0xC4  Д
    0x00, 0x00, 0x00, 0x00, 0x7c, 0xc6, 0xfe, 0xc0, 0xc6, 0x7c, 0x00, 0x00, // 0xC5  е
    0x00, 0x54, 0x54, 0x54, 0x38, 0x38, 0x54, 0x54, 0x54, 0x54, 0x00, 0x00, // 0xC6  Ж
    0x00, 0x38, 0x44, 0x04, 0x04, 0x18, 0x04, 0x04, 0x44, 0x38, 0x00, 0x00, // 0xC7  З
    0x00, 0x42, 0x42, 0x42, 0x46, 0x4A, 0x52, 0x62, 0x42, 0x42, 0x00, 0x00, // 0xC8  И
    0x08, 0x52, 0x42, 0x42, 0x46, 0x4A, 0x52, 0x62, 0x42, 0x42, 0x00, 0x00, // 0xC9  Й
    0x00, 0xe0, 0x60, 0x60, 0x66, 0x6c, 0x78, 0x6c, 0x66, 0xe6, 0x00, 0x00, // 0xCA  к
    0x00, 0x1C, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x44, 0x00, 0x00, // 0xCB  Л
    0x00, 0x82, 0xC6, 0xAA, 0x92, 0x82, 0x82, 0x82, 0x82, 0x82, 0x00, 0x00, // 0xCC  М
    0x00, 0x42, 0x42, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00, // 0xCD  Н
    0x00, 0x00, 0x00, 0x00, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0x7c, 0x00, 0x00, // 0xCE  о
    0x00, 0x7E, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x00, 0x00, // 0xCF  П

    0x00, 0x00, 0x00, 0xdc, 0x66, 0x66, 0x66, 0x7c, 0x60, 0x60, 0xf0, 0x00, // 0xD0 р
    0x00, 0x00, 0x00, 0x00, 0x7c, 0xc6, 0xc0, 0xc0, 0xc6, 0x7c, 0x00, 0x00, // 0xD1 с
    0x00, 0x00, 0x00, 0x00, 0xec, 0xfe, 0xd6, 0xd6, 0xd6, 0xd6, 0x00, 0x00, // 0xD2  m
    0x00, 0x44, 0x44, 0x44, 0x44, 0x44, 0x3C, 0x04, 0x44, 0x38, 0x00, 0x00, // 0xD3  У
    0x00, 0x7C, 0x92, 0x92, 0x92, 0x92, 0x7C, 0x10, 0x10, 0x10, 0x00, 0x00, // 0xD4  Ф
    0x00, 0x44, 0x44, 0x44, 0x28, 0x10, 0x28, 0x44, 0x44, 0x44, 0x00, 0x00, // 0xD5  Х
    0x00, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x7E, 0x02, 0x00, 0x00, // 0xD6  Ц
    0x00, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3E, 0x02, 0x02, 0x02, 0x00, 0x00, // 0xD7  Ч
    0x00, 0x82, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0xFE, 0x00, 0x00, // 0xD8  Ш
    0x00, 0x82, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0xFE, 0x01, 0x00, // 0xD9  Щ
    0x00, 0xE0, 0x20, 0x20, 0x20, 0x3C, 0x22, 0x22, 0x22, 0x3C, 0x00, 0x00, // 0xDA  Ъ
    0x00, 0x42, 0x42, 0x42, 0x42, 0x72, 0x4A, 0x4A, 0x4A, 0x72, 0x00, 0x00, // 0xDB  Ы
    0x00, 0x20, 0x20, 0x20, 0x20, 0x3C, 0x22, 0x22, 0x22, 0x3C, 0x00, 0x00, // 0xDC  Ь
    0x00, 0x1C, 0x22, 0x02, 0x02, 0x1E, 0x02, 0x02, 0x22, 0x1C, 0x00, 0x00, // 0xDD  Э
    0x00, 0x4C, 0x52, 0x52, 0x52, 0x72, 0x52, 0x52, 0x52, 0x4C, 0x00, 0x00, // 0xDE  Ю
    0x00, 0x3C, 0x44, 0x44, 0x44, 0x3C, 0x24, 0x44, 0x44, 0x44, 0x00, 0x00, // 0xDF  Я
};

/******************* (C) COPYRIGHT ***************** END OF FILE ********* D_EL *****/
