// Goodix Tls driver for libfprint

// Copyright (C) 2021 Alexander Meiler <alex.meiler@protonmail.com>
// Copyright (C) 2021 Matthieu CHARETTE <matthieu.charette@gmail.com>
// Copyright (C) 2021 Alireza S.N. <alireza6677@gmail.com>

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

#pragma once

#define GOODIX_55X4_INTERFACE (0)
#define GOODIX_55X4_EP_IN (0x82 | FPI_USB_ENDPOINT_IN)
#define GOODIX_55X4_EP_OUT (0x1 | FPI_USB_ENDPOINT_OUT)

#define GOODIX_55X4_FIRMWARE_VERSION ("GF3268_RTSEC_APP_10041")

#define GOODIX_55X4_PSK_FLAGS (0xbb020007)

#define GOODIX_55X4_RESET_NUMBER (1024)

const guint8 goodix_55x4_psk_0[] = {
    0x81, 0xb8, 0xff, 0x49, 0x06, 0x12, 0x02, 0x2a, 0x12, 0x1a, 0x94,
    0x49, 0xee, 0x3a, 0xad, 0x27, 0x92, 0xf3, 0x2b, 0x9f, 0x31, 0x41,
    0x18, 0x2c, 0xd0, 0x10, 0x19, 0x94, 0x5e, 0xe5, 0x03, 0x61
};

guint8 goodix_55x4_config[] = {
    0x60, 0x11, 0x60, 0x71, 0x24, 0x95, 0x2c, 0xc1, 0x14, 0xd5, 0x10,
    0xe5, 0x00, 0xe5, 0x14, 0xf9, 0x03, 0x04, 0x02, 0x00, 0x00, 0x08,
    0x00, 0x11, 0x11, 0xba, 0x00, 0x01, 0x80, 0xca, 0x00, 0x07, 0x00,
    0x84, 0x00, 0xc0, 0xb3, 0x86, 0x00, 0xbb, 0xc4, 0x88, 0x00, 0xba,
    0xba, 0x8a, 0x00, 0xb2, 0xb2, 0x8c, 0x00, 0xaa, 0xaa, 0x8e, 0x00,
    0xc1, 0xc1, 0x90, 0x00, 0xbb, 0xbb, 0x92, 0x00, 0xb1, 0xb1, 0x94,
    0x00, 0x00, 0xa8, 0x96, 0x00, 0x00, 0xb6, 0x98, 0x00, 0x00, 0xbf,
    0x9a, 0x00, 0x00, 0xba, 0x50, 0x00, 0x01, 0x05, 0xd0, 0x00, 0x00,
    0x00, 0x70, 0x00, 0x00, 0x00, 0x72, 0x00, 0x78, 0x56, 0x74, 0x00,
    0x34, 0x12, 0x26, 0x00, 0x00, 0x12, 0x20, 0x00, 0x10, 0x40, 0x12,
    0x00, 0x03, 0x04, 0x2a, 0x01, 0x02, 0x00, 0x22, 0x00, 0x01, 0x20,
    0x24, 0x00, 0x32, 0x00, 0x80, 0x00, 0x01, 0x00, 0x5c, 0x00, 0x80,
    0x00, 0x56, 0x00, 0x08, 0x20, 0x58, 0x00, 0x01, 0x00, 0x32, 0x00,
    0x2c, 0x02, 0x82, 0x00, 0x80, 0x0c, 0xba, 0x00, 0x01, 0x80, 0xca,
    0x00, 0x07, 0x00, 0x2a, 0x01, 0x82, 0x03, 0x20, 0x00, 0x10, 0x40,
    0x22, 0x00, 0x01, 0x20, 0x24, 0x00, 0x14, 0x00, 0x80, 0x00, 0x05,
    0x00, 0x5c, 0x00, 0x00, 0x01, 0x56, 0x00, 0x08, 0x20, 0x58, 0x00,
    0x03, 0x00, 0x82, 0x00, 0x80, 0x14, 0x2a, 0x01, 0x08, 0x00, 0x5c,
    0x00, 0x80, 0x00, 0x62, 0x00, 0x09, 0x03, 0x64, 0x00, 0x18, 0x00,
    0x22, 0x00, 0x00, 0x20, 0x2a, 0x01, 0x08, 0x00, 0x5c, 0x00, 0x00,
    0x01, 0x52, 0x00, 0x08, 0x00, 0x54, 0x00, 0x00, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x9a, 0x69
};

static const FpIdEntry id_table[] = {
    {.vid = 0x27c6, .pid = 0x55b4},
    {.vid = 0x27c6, .pid = 0x55a4},
    {.vid = 0, .pid = 0, .driver_data = 0},
};

gboolean save_image_to_pgm (FpImage *img, const char *path);
gboolean save_image_to_pgm2 (guchar *data, const char *path);