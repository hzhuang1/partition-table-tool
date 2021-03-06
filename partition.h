/*
 * Partition Table Tool
 *
 * Copyright (c) 2017 Hisilicon Limited.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef _PARTITION_H_
#define _PARTITION_H_

#include "hisi_partition.h"

typedef struct partition {
	char name[PART_NAMELEN];
	unsigned long long start;
	unsigned long long length;
	unsigned int flags;
}PARTITION;

static const struct partition partition_table_ufs[] =
{
  /* Caution:
   *   Entries from PART_XLOADER_A to PART_NVME (inclusive) shall not be
   *   modified. They are correlated with xloader [1]. Changing of them
   *   must be done together with xloader.
   *
   * [1]: https://github.com/96boards-hikey/tools-images-hikey960/blob/master/sec_xloader.img)
   */
  {PART_XLOADER_A,        0,         2*1024,          UFS_PART_0},
  {PART_XLOADER_B,        0,         2*1024,          UFS_PART_1},
  {PART_PTABLE,           0,         1024,            UFS_PART_2},/* ptable          512K */
  {PART_FRP,              1024,      7*1024,          UFS_PART_2},/* frp             512K   p1*/
  {PART_PTABLE_LU3,       0,         1024,            UFS_PART_3},/* ptable_lu3    1M    sdd  */
  {PART_XLOADER_RESERVED1,1024,      1024,            UFS_PART_3},/* vrl           1M    sdd1 */
  {PART_FASTBOOT,         2*1024,    12*1024,         UFS_PART_3},/* fastboot      12M   sdd2 */
  {PART_NVME,             14*1024,   6*1024,          UFS_PART_3},/* nvme          6M    sdd3 */
  /* Items above shall not be changed, unless you can update xloader simualtaneously. */
  {PART_FIP,              20*1024,   12*1024,         UFS_PART_3},/* fip           12M   sdd4 */
  {PART_CACHE,            32*1024,   256*1024,        UFS_PART_3},/* cache         256M  sdd5 */
  {PART_FW_LPM3,          288*1024,  1024,            UFS_PART_3},/* mcuimage      1M    sdd6 */
  {PART_BOOT,             289*1024,  64*1024,         UFS_PART_3},/* boot          64M   sdd7 */
  {PART_DTS,              353*1024,  16*1024,         UFS_PART_3},/* dtimage       16M   sdd8 */
  {PART_TRUSTFIRMWARE,    369*1024,  2*1024,          UFS_PART_3},/* trustfirmware 2M    sdd9 */
  {PART_SYSTEM,           371*1024,  4688*1024,       UFS_PART_3},/* system        4688M sdd10 */
  {PART_VENDOR,           5059*1024, 784*1024,        UFS_PART_3},/* vendor        784M  sdd11 */
  {PART_RESERVED,         5843*1024, 1024,            UFS_PART_3},/* reserved      1M    sdd12 */
  {PART_USERDATA,         5844*1024, (4UL)*1024*1024, UFS_PART_3},/* userdata      4G    sdd13 */
  {"0", 0, 0, 0},
};

#endif


