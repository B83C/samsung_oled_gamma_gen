#ifndef _SAMSUNG_DSI_SMART_DIMMING_S6E8AA5X01_AMS520KT01_H_
#define _SAMSUNG_DSI_SMART_DIMMING_S6E8AA5X01_AMS520KT01_H_

//#include "../ss_dsi_panel_common.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>

#ifdef DEBUG 
#define pr_info(fmt,arg...)  printf(fmt,##arg);
#define pr_err(fmt,arg...)  printf(fmt,##arg);
#define pr_debug(fmt,arg...)  printf(fmt,##arg);
#else
#define pr_info(fmt,arg...)  __asm__("nop");
#define pr_err(fmt,arg...)  __asm__("nop");
#define pr_debug(fmt,arg...)  __asm__("nop");
#endif

#define KERN_ERR "Error : "
#define __packed __attribute__((packed))

static inline uint32_t __div64_32(uint64_t *n, uint32_t base)
{
	uint32_t remainder = *n % base;
	*n = *n / base;
	return remainder;
}

#define do_div(n, base) __div64_32(&(n), base)

struct smartdim_conf{
	void (*generate_gamma)(struct smartdim_conf *conf, int cd, char *str);
	void (*init)(struct smartdim_conf *conf);
	void (*print_aid_log)(struct smartdim_conf *conf);
	struct SMART_DIM *psmart;

	void (*get_min_lux_table)(char *str, int size);
	char *mtp_buffer;
	int *lux_tab;
	int lux_tabsize;
	unsigned int man_id;

	/* HMT */
	void (*set_para_for_150cd)(char *para, int size);
};

/* Define the gamma */
#define GAMMA_INDEX_MAX 256

/*
 *		index : 0 ~ 255
 *		((index/255)^2.25)*4194304
 */
extern int candela_coeff_2p25[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		((index/255)^2.2)*4194304
 */
extern int candela_coeff_2p2[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		((index/255)^2.15)*4194304
 */
extern int candela_coeff_2p15[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		((index/255)^2.12)*4194304
 */
extern int candela_coeff_2p12[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		((index/255)^2.1)*4194304
 */
extern int candela_coeff_2p1[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		((index/255)^2.05)*4194304
 */
extern int candela_coeff_2p05[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		((index/255)^2.0)*4194304
 */
extern int candela_coeff_2p0[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		((index/255)^1.95)*4194304
 */
extern int candela_coeff_1p95[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		((index/255)^1.9)*4194304
 */
extern int candela_coeff_1p9[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		((index/255)^1.85)*4194304
 */
extern int candela_coeff_1p85[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		((index/255)^1.8)*4194304
 */
extern int candela_coeff_1p8[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		((index/255)^1.75)*4194304
 */
extern int candela_coeff_1p75[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		((index/255)^1.7)*4194304
 */
extern int candela_coeff_1p7[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		((index/255)^1.65)*4194304
 */
extern int candela_coeff_1p65[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		((index/255)^1.6)*4194304
 */
extern int candela_coeff_1p6[GAMMA_INDEX_MAX];





/*
 *		index : 0 ~ 255
 *		300 is max CANDELA
 *		(300*((index/255)^2.2))*4194304
 */
extern int curve_2p2_300[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		300 is max CANDELA
 *		(300*((index/255)^1.9))*4194304
 */
extern int curve_1p9_300[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		300 is max CANDELA
 *		(300*((index/255)^1.95))*4194304
 */
extern int curve_1p95_300[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		300 is max CANDELA
 *		(300*((index/255)^2.0))*4194304
 */
extern int curve_2p0_300[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		300 is max CANDELA
 *		(300*((index/255)^2.05))*4194304
 */
extern int curve_2p05_300[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		300 is max CANDELA
 *		(300*((index/255)^2.1))*4194304
 */
extern int curve_2p1_300[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		300 is max CANDELA
 *		(300*((index/255)^2.12))*4194304
 */
extern int curve_2p12_300[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		350 is max CANDELA
 *		(350*((index/255)^1.9))*4194304
 */
extern int curve_1p9_350[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		350 is max CANDELA
 *		(350*((index/255)^2.0))*4194304
 */
extern int curve_2p0_350[GAMMA_INDEX_MAX];


/*
 *		index : 0 ~ 255
 *		350 is max CANDELA
 *		(350*((index/255)^2.15))*4194304
 */
extern int curve_2p15_350[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		350 is max CANDELA
 *		(350*((index/255)^2.2))*4194304
 */
extern int curve_2p2_350[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		360 is max CANDELA
 *		(360*((index/255)^1.9))*4194304
 */
extern int curve_1p9_360[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		360 is max CANDELA
 *		(360*((index/255)^2.15))*4194304
 */
extern int curve_2p15_360[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		360 is max CANDELA
 *		(360*((index/255)^2.2))*4194304
 */
extern int curve_2p2_360[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		360 is max CANDELA
 *		(360*((index/255)^2.0))*4194304
 */
extern int curve_2p0_360[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		420 is max CANDELA
 *		(420*((index/255)^2.15))*4194304
 */
extern int curve_2p15_420[GAMMA_INDEX_MAX];

/*
 *		index : 0 ~ 255
 *		420 is max CANDELA
 *		(420*((index/255)^2.2))*4194304
 */
extern int curve_2p2_420[GAMMA_INDEX_MAX];

/*
 *	From 4.8 inch model use AID function
 *	CASE#1 is used for now.
 */
#define AID_OPERATION

enum {
	GAMMA_CURVE_2P15= 0,
	GAMMA_CURVE_2P2,
};

#define REV_A	0x01

#define LUMINANCE_MAX 62
#define GAMMA_SET_MAX 33
#define BIT_SHIFT 22
/*
   it means BIT_SHIFT is 22.  pow(2,BIT_SHIFT) is 4194304.
   BIT_SHIFT is used for right bit shfit
   */
#define BIT_SHFIT_MUL 4194304

#define GRAY_SCALE_MAX 256

/* 5.8 * 4194304 */
#define VREG0_REF_5P8 24326963

/*V0,V3,V11,V23,V35,V51,V87,V151,V203,V255*/
#define ARRAY_MAX 11

/* PANEL DEPENDENT THINGS */
#define MIN_CANDELA	5

/*
 *	ID 0x20
 */
#define V255_300CD_R_MSB_20 0x01
#define V255_300CD_R_LSB_20 0x00

#define V255_300CD_G_MSB_20 0x01
#define V255_300CD_G_LSB_20 0x00

#define V255_300CD_B_MSB_20 0x01
#define V255_300CD_B_LSB_20 0x00

#define V203_300CD_R_20 0x80
#define V203_300CD_G_20 0x80
#define V203_300CD_B_20 0x80

#define V151_300CD_R_20 0x80
#define V151_300CD_G_20 0x80
#define V151_300CD_B_20 0x80

#define V87_300CD_R_20 0x80
#define V87_300CD_G_20 0x80
#define V87_300CD_B_20 0x80

#define V51_300CD_R_20 0x80
#define V51_300CD_G_20 0x80
#define V51_300CD_B_20 0x80

#define V35_300CD_R_20 0x80
#define V35_300CD_G_20 0x80
#define V35_300CD_B_20 0x80

#define V23_300CD_R_20 0x80
#define V23_300CD_G_20 0x80
#define V23_300CD_B_20 0x80

#define V11_300CD_R_20 0x80
#define V11_300CD_G_20 0x80
#define V11_300CD_B_20 0x80

#define V3_300CD_R_20 0x80
#define V3_300CD_G_20 0x80
#define V3_300CD_B_20 0x80

#define VT_300CD_R_20 0x00
#define VT_300CD_G_20 0x00
#define VT_300CD_B_20 0x00

/* PANEL DEPENDENT THINGS END*/

enum {
	V1_INDEX = 0,
	V3_INDEX = 1,
	V11_INDEX = 2,
	V23_INDEX = 3,
	V35_INDEX = 4,
	V51_INDEX = 5,
	V87_INDEX = 6,
	V151_INDEX = 7,
	V203_INDEX = 8,
	V255_INDEX = 9,
};

struct GAMMA_LEVEL {
	int level_0;
	int level_1;
	int level_3;
	int level_11;
	int level_23;
	int level_35;
	int level_51;
	int level_87;
	int level_151;
	int level_203;
	int level_255;
} __packed;

struct RGB_OUTPUT_VOLTARE {
	struct GAMMA_LEVEL R_VOLTAGE;
	struct GAMMA_LEVEL G_VOLTAGE;
	struct GAMMA_LEVEL B_VOLTAGE;
} __packed;

struct GRAY_VOLTAGE {
	/*
	   This voltage value use 14bit right shit
	   it means voltage is divied by 16384.
	   */
	int R_Gray;
	int G_Gray;
	int B_Gray;
} __packed;

struct GRAY_SCALE {
	struct GRAY_VOLTAGE TABLE[GRAY_SCALE_MAX];
	struct GRAY_VOLTAGE VT_TABLE;
} __packed;

/*V0,V1,V3,V11,V23,V35,V51,V87,V151,V203,V255*/

struct MTP_SET {
	char OFFSET_255_MSB;
	char OFFSET_255_LSB;
	char OFFSET_203;
	char OFFSET_151;
	char OFFSET_87;
	char OFFSET_51;
	char OFFSET_35;
	char OFFSET_23;
	char OFFSET_11;
	char OFFSET_3;
	char OFFSET_1;
} __packed;

struct MTP_OFFSET {
	struct MTP_SET R_OFFSET;
	struct MTP_SET G_OFFSET;
	struct MTP_SET B_OFFSET;
} __packed;

struct illuminance_table {
	int lux;
	char gamma_setting[GAMMA_SET_MAX];
} __packed;

struct SMART_DIM {
	struct MTP_OFFSET MTP_ORIGN;

	struct MTP_OFFSET MTP;
	struct RGB_OUTPUT_VOLTARE RGB_OUTPUT;
	struct GRAY_SCALE GRAY;

	/* Because of AID funtion, below members are added*/
	int lux_table_max;
	int *plux_table;
	struct illuminance_table gen_table[LUMINANCE_MAX];

	int brightness_level;
	int ldi_revision;
	int vregout_voltage;
} __packed;

#define AOR_DIM_BASE_CD	111

#define CANDELA_MAX_TABLE 61
#define RGB_COMPENSATION 24

static int candela_table[][2] = {
	{5, 0,},
	{6, 1,},
	{7, 2,},
	{8, 3,},
	{9, 4,},
	{10, 5,},
	{11, 6,},
	{12, 7,},
	{13, 8,},
	{14, 9,},
	{15, 10,},
	{16, 11,},
	{17, 12,},
	{19, 13,},
	{20, 14,},
	{21, 15,},
	{22, 16,},
	{24, 17,},
	{25, 18,},
	{27, 19,},
	{29, 20,},
	{30, 21,},
	{32, 22,},
	{34, 23,},
	{37, 24,},
	{39, 25,},
	{41, 26,},
	{44, 27,},
	{47, 28,},
	{50, 29,},
	{53, 30,},
	{56, 31,},
	{60, 32,},
	{64, 33,},
	{68, 34,},
	{72, 35,},
	{77, 36,},
	{82, 37,},
	{87, 38,},
	{93, 39,},
	{98, 40,},
	{105, 41,},
	{111, 42,},
	{119, 43,},
	{126, 44,},
	{134, 45,},
	{143, 46,},
	{152, 47,},
	{162, 48,},
	{172, 49,},
	{183, 50,},
	{195, 51,},
	{207, 52,},
	{220, 53,},
	{234, 54,},
	{249, 55,},
	{265, 56,},
	{282, 57,},
	{300, 58,},
	{316, 59,},
	{333, 60,},
	{360, 61,},
};
static int base_luminance_revA[][2] = {
	{5, 111,},
	{6, 111,},
	{7, 111,},
	{8, 111,},
	{9, 111,},
	{10, 111,},
	{11, 111,},
	{12, 111,},
	{13, 111,},
	{14, 111,},
	{15, 111,},
	{16, 111,},
	{17, 111,},
	{19, 111,},
	{20, 111,},
	{21, 111,},
	{22, 111,},
	{24, 111,},
	{25, 111,},
	{27, 111,},
	{29, 111,},
	{30, 111,},
	{32, 111,},
	{34, 111,},
	{37, 111,},
	{39, 111,},
	{41, 111,},
	{44, 111,},
	{47, 111,},
	{50, 111,},
	{53, 111,},
	{56, 111,},
	{60, 111,},
	{64, 111,},
	{68, 114,},
	{72, 122,},
	{77, 129,},
	{82, 138,},
	{87, 146,},
	{93, 156,},
	{98, 162,},
	{105, 172,},
	{111, 180,},
	{119, 193,},
	{126, 193,},
	{134, 193,},
	{143, 193,},
	{152, 193,},
	{162, 193,},
	{172, 193,},
	{183, 196,},
	{195, 206,},
	{207, 219,},
	{220, 231,},
	{234, 243,},
	{249, 257,},
	{265, 272,},
	{282, 289,},
	{300, 305,},
	{316, 320,},
	{333, 337,},
	{360, 360,},
};

static int gradation_offset_revA[][9] = {
	/*	V255 V203 V151 V87 V51 V35 V23 V11 V3 */
	{0, 2, 1, 3, 5, 7, 10, 14, 16},
	{0, 2, 1, 2, 4, 7, 9, 13, 15},
	{0, 2, 1, 1, 3, 6, 8, 12, 14},
	{0, 2, 1, 1, 3, 5, 8, 12, 14},
	{0, 2, 1, 1, 2, 4, 7, 11, 13},
	{0, 2, 1, 1, 2, 4, 6, 10, 12},
	{0, 2, 1, 1, 2, 4, 6, 10, 12},
	{0, 2, 1, 1, 2, 4, 6, 9, 11},
	{0, 2, 1, 1, 1, 3, 5, 8, 11},
	{0, 2, 1, 1, 1, 3, 5, 8, 10},
	{0, 2, 1, 1, 1 , 3, 5, 7, 9},
	{0, 2, 1, 1, 1, 2, 4, 7, 9},
	{0, 1, 1, 1, 1, 2, 4, 7, 9},
	{0, 1, 0, 1, 1, 2, 4, 6, 8},
	{0, 0, 0, 1, 1, 2, 4, 6, 8},
	{0, 1, 0, 1, 1, 2, 4, 6, 8},
	{0, 1, 0, 1, 1, 2, 4, 7, 8},
	{0, 1, 1, 1, 2, 3, 5, 7, 8},
	{0, 2, 1, 2, 3, 3, 5, 8, 8},
	{0, 2, 1, 2, 3, 3, 5, 8, 8},
	{0, 2, 1, 2, 3, 3, 5, 8, 8},
	{0, 2, 1, 2, 3, 3, 5, 8, 8},
	{0, 2, 1, 2, 3, 3, 5, 8, 8},
	{0, 2, 1, 2, 3, 3, 5, 7, 8},
	{0, 2, 1, 2, 2, 3, 5, 7, 8},
	{0, 2, 1, 2, 2, 3, 4, 6, 8},
	{0, 2, 1, 2, 2, 3, 4, 6, 8},
	{0, 2, 1, 2, 2, 3, 4, 5, 8},
	{0, 2, 1, 2, 2, 2, 3, 5, 8},
	{0, 2, 1, 2, 2, 2, 3, 5, 8},
	{0, 2, 1, 2, 2, 2, 3, 4, 8},
	{0, 2, 1, 1, 2, 2, 3, 4, 7},
	{0, 2, 1, 1, 2, 2, 3, 4, 6},
	{0, 2, 1, 1, 2, 2, 3, 4, 5},
	{0, 2, 1, 1, 2, 2, 3, 4, 5},
	{0, 2, 1, 1, 2, 2, 2, 4, 5},
	{0, 2, 1, 1, 2, 2, 2, 4, 5},
	{0, 2, 1, 1, 1, 2, 2, 3, 4},
	{0, 2, 1, 1, 1, 2, 2, 3, 4},
	{0, 1, 1, 1, 1, 2, 2, 3, 4},
	{0, 1, 1, 1, 1, 2, 2, 3, 4},
	{0, 1, 1, 1, 1, 1, 2, 3, 4},
	{0, 1, 1, 1, 1, 1, 2, 2, 4},
	{0, 1, 1, 1, 1, 1, 2, 2, 4},
	{0, 1, 1, 1, 1, 1, 2, 2, 3},
	{0, 0, 1, 1, 1, 1, 1, 2, 3},
	{0, 0, 1, 1, 1, 1, 1, 2, 3},
	{0, 0, 1, 1, 1, 1, 1, 2, 3},
	{0, 0, 1, 1, 1, 1, 1, 2, 3},
	{0, 0, 1, 1, 1, 1, 1, 2, 3},
	{0, 0, 1, 1, 1, 1, 1, 1, 3},
	{0, 0, 1, 1, 1, 1, 1, 1, 2},
	{0, 0, 1, 1, 1, 1, 1, 1, 2},
	{0, 0, 1, 1, 1, 0, 1, 1, 2},
	{0, 0, 1, 1, 1, 0, 0, 1, 2},
	{0, 0, 1, 1, 1, 0, 0, 1, 2},
	{0, 0, 0, 1, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},

};

static int rgb_offset_revA[][RGB_COMPENSATION] = {
	/*	R255 G255 B255 R203 G203 B203 R151 G151 B151 R87 G87 B87 R51 G51 B51 R35 G35 B35  R23 G23 B23 R11 G11 B11*/
	{1, 0, 0, -1, 0, 0, 0, 0, 1, -2, 0, 0, -3, 0, 3, -7, 0, 1, -6, 0, 0, -5, 0, -2},
	{1, 0, 0, -1, 0, 0, 0, 0, 1, -2, 0, 0, -4, 0, 3, -5, 0, 0, -6, 0, 0, -6, 0, -2},
	{1, 0, 0, -1, 0, 0, 0, 0, 1, -1, 0, 0, -4, 0, 3, -5, 0, 0, -6, 0, 0, -6, 0, -3},
	{1, 0, 0, -1, 0, 0, 0, 0, 1, -1, 0, 0, -4, 0, 3, -4, 0, 0, -6, 0, 0, -8, 0, -2},
	{1, 0, 0, -1, 0, 0, 0, 0, 1, -1, 0, 0, -3, 0, 3, -4, 0, 0, -6, 0, 0, -9, 0, -2},
	{1, 0, 0, -1, 0, 0, 0, 0, 1, -1, 0, 0, -3, 0, 3, -4, 0, 0, -7, 0, -1, -9, 0, -2},
	{1, 0, 0, -1, 0, 0, 0, 0, 1, -1, 0, 0, -3, 0, 3, -3, 0, 0, -7, 0, -1, -9, 0, -2},
	{1, 0, 0, -1, 0, 0, 0, 0, 1, -1, 0, 0, -2, 0, 3, -3, 0, -1, -7, 0, -1, -11, 0, -2},
	{1, 0, 0, -1, 0, -1, 0, 0, 2, -1, 0, 0, -2, 0, 3, -2, 0, -2, -7, 0, -1, -11, 0, -3},
	{1, 0, 0, -1, 0, -1, 0, 0, 2, -1, 0, 0, -2, 0, 2, -2, 0, -2, -7, 0, 0, -10, 0, -3},
	{1, 0, 0, -1, 0, -1, 0, 0, 2, -1, 0, 0, -2, 0, 2, -1, 0, -2, -6, 0, 0, -11, 0, -4},
	{1, 0, 0, -1, 0, -1, 0, 0, 2, -1, 0, 0, -2, 0, 2, -1, 0, -2, -6, 0, 0, -11, 0, -3},
	{1, 0, 0, -1, 0, -1, 0, 0, 2, -1, 0, 0, -2, 0, 2, -1, 0, -2, -6, 0, 0, -10, 0, -2},
	{1, 0, 0, -1, 0, -1, 0, 0, 1, -1, 0, 0, -2, 0, 2, -1, 0, -2, -5, 0, 0, -10, 0, -2},
	{1, 0, 0, -1, 0, -1, 0, 0, 1, 0, 0, 0, -2, 0, 2, -3, 0, -2, -5, 0, 0, -10, 0, -1},
	{1, 0, 0, -1, 0, -1, 0, 0, 1, 0, 0, 0, -1, 0, 2, -1, 0, -3, -5, 0, 0, -10, 0, -3},
	{1, 0, 0, -1, 0, -1, 0, 0, 1, 0, 0, 0, -1, 0, 2, -1, 0, -3, -5, 0, 0, -7, 0, -2},
	{1, 0, 2, -1, 0, -1, 0, 0, 1, -1, 0, 0, -1, 0, 2, -1, 0, -3, -5, 0, 0, -8, 0, -4},
	{1, 0, 2, -1, 0, 0, 0, 0, 1, -1, 0, -1, -2, 0, 3, -1, 0, -3, -6, 0, -1, -8, 0, -2},
	{1, 0, 3, -1, 0, 0, 0, 0, 1, -1, 0, -1, -2, 0, 2, 0, 0, -4, -4, 0, -3, -8, 0, -2},
	{1, 0, 3, -1, 0, 0, 0, 0, 1, -1, 0, -1, -2, 0, 2, 0, 0, -4, -4, 0, -3, -8, 0, -3},
	{1, 0, 3, -1, 0, 1, 0, 0, 1, -1, 0, -1, -2, 0, 1, 0, 0, -4, -4, 0, -3, -8, 0, -4},
	{1, 0, 3, -1, 0, 1, 0, 0, 1, -1, 0, -1, -2, 0, 1, 0, 0, -4, -4, 0, -3, -7, 0, -2},
	{1, 0, 3, -1, 0, 1, 0, 0, 1, 0, 0, 0, -2, 0, 1, 0, 0, -4, -4, 0, -3, -9, 0, -6},
	{1, 0, 3, -1, 0, 1, 0, 0, 1, 0, 0, 0, -2, 0, 1, 0, 0, -4, -4, 0, -3, -9, 0, -5},
	{1, 0, 3, -1, 0, 1, 0, 0, 1, 0, 0, 0, -2, 0, 1, 0, 0, -4, -2, 0, -3, -8, 0, -5},
	{1, 0, 3, -1, 0, 1, 0, 0, 1, 0, 0, 0, -2, 0, 1, 0, 0, -4, -2, 0, -3, -7, 0, -4},
	{1, 0, 3, -1, 0, 1, 0, 0, 1, 0, 0, 0, -2, 0, 1, 0, 0, -4, -2, 0, -3, -8, 0, -5},
	{1, 0, 3, -1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, -4, -3, 0, -4, -8, 0, -5},
	{1, 0, 3, -1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, -4, -1, 0, -3, -9, 0, -5},
	{1, 0, 3, -1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, -4, -1, 0, -3, -8, 0, -5},
	{1, 0, 3, -1, 0, 1, 0, 0, 1, -1, 0, 0, 0, 0, 2, 1, 0, -4, -1, 0, -3, -8, 0, -4},
	{1, 0, 3, -1, 0, 1, 0, 0, 1, -1, 0, 0, 0, 0, 2, 1, 0, -4, -1, 0, -3, -6, 0, -2},
	{1, 0, 3, -1, 0, 1, 0, 0, 1, -1, 0, 0, 0, 0, 2, 1, 0, -4, -1, 0, -3, -5, 0, -1},
	{0, 0, 3, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 2, 1, 0, -4, -1, 0, -3, -8, 0, -2},
	{0, 0, 3, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 2, 1, 0, -4, -1, 0, -2, -8, 0, -2},
	{0, 0, 3, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 2, 1, 0, -4, -1, 0, -2, -8, 0, -2},
	{0, 0, 3, 0, 0, 0, 0, 0, 1, 1, 0, 1, -2, 0, 2, 1, 0, -4, -1, 0, -2, -7, 0, -2},
	{0, 0, 3, 0, 0, 0, 0, 0, 1, 1, 0, 1, -2, 0, 2, 1, 0, -4, -2, 0, -1, -4, 0, -1},
	{0, 0, 2, 0, 0, 1, 0, 0, 1, 1, 0, 1, -2, 0, 2, 1, 0, -4, -2, 0, -1, -7, 0, -2},
	{0, 0, 2, 0, 0, 1, 0, 0, 1, 1, 0, 1, -2, 0, 2, 1, 0, -2, -2, 0, -1, -7, 0, -2},
	{0, 0, 2, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 2, 1, 0, -2, 0, 0, -2, -7, 0, -2},
	{0, 0, 2, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 2, 1, 0, -2, 0, 0, -2, -5, 0, -2},
	{0, 0, 2, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 2, 1, 0, -3, 0, 0, -2, -5, 0, -1},
	{0, 0, 2, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 2, 1, 0, -3, 0, 0, -2, -5, 0, -1},
	{0, 0, 2, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 2, 1, 0, -2, 1, 0, -3, -5, 0, -1},
	{0, 0, 2, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 2, 1, 0, -2, 1, 0, -3, -5, 0, 0},
	{0, 0, 2, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 2, 1, 0, -2, 0, 0, -3, -3, 0, 0},
	{0, 0, 2, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 2, 1, 0, -2, 0, 0, -3, -3, 0, 0},
	{0, 0, 2, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 2, 1, 0, -2, 0, 0, -3, -3, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};
#endif
