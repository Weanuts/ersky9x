/*
 * Author - Mike Blandford
 *
 * Based on er9x by Erez Raviv <erezraviv@gmail.com>
 *
 * Based on th9x -> http://code.google.com/p/th9x/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

// This version for ARM based ERSKY9X board

// Items set to make things compile, will need to be sorted eventually
#define assert(x)
#define wdt_reset()


#define VERSION	"V0.23"

#define CPU_INT		int32_t
#define CPU_UINT	uint32_t

#define BITMASK(bit) (1<<(bit))

#define PSTR(a)  (char *)a
#define PROGMEM	 const unsigned char
#define strcpy_P(a,b)	strcpy(a,b)
#define strncpy_P(a,b,c)	strncpy(a,b,c)



#define DIM(arr) (sizeof((arr))/sizeof((arr)[0]))

enum EnumKeys {
    KEY_MENU ,
    KEY_EXIT ,
    KEY_DOWN ,
    KEY_UP  ,
    KEY_RIGHT ,
    KEY_LEFT ,
    TRM_LH_DWN  ,
    TRM_LH_UP   ,
    TRM_LV_DWN  ,
    TRM_LV_UP   ,
    TRM_RV_DWN  ,
    TRM_RV_UP   ,
    TRM_RH_DWN  ,
    TRM_RH_UP   ,
    //SW_NC     ,
    //SW_ON     ,
    SW_ThrCt  ,
    SW_RuddDR ,
    SW_ElevDR ,
    SW_ID0    ,
    SW_ID1    ,
    SW_ID2    ,
    SW_AileDR ,
    SW_Gear   ,
    SW_Trainer
};

#define CURV_STR "---x>0x<0|x|f>0f<0|f|c1 c2 c3 c4 c5 c6 c7 c8 c9 c10c11c12c13c14c15c16"
#define CURVE_BASE 7


#define CS_OFF       0
#define CS_VPOS      1  //v>offset
#define CS_VNEG      2  //v<offset
#define CS_APOS      3  //|v|>offset
#define CS_ANEG      4  //|v|<offset
#define CS_AND       5
#define CS_OR        6
#define CS_XOR       7
#define CS_EQUAL     8
#define CS_NEQUAL    9
#define CS_GREATER   10
#define CS_LESS      11
#define CS_EGREATER  12
#define CS_ELESS     13
#define CS_MAXF      13  //max function

#define CS_VOFS       0
#define CS_VBOOL      1
#define CS_VCOMP      2
#define CS_STATE(x)   ((x)<CS_AND ? CS_VOFS : ((x)<CS_EQUAL ? CS_VBOOL : CS_VCOMP))

#define SW_BASE      SW_ThrCt
#define SW_BASE_DIAG SW_ThrCt
#define MAX_DRSWITCH (1+SW_Trainer-SW_ThrCt+1+NUM_CSW)

#define SWITCHES_STR "THR""RUD""ELE""ID0""ID1""ID2""AIL""GEA""TRN""SW1""SW2""SW3""SW4""SW5""SW6""SW7""SW8""SW9""SWA""SWB""SWC"
#define NUM_CSW  12 //number of custom switches



#define NUM_KEYS TRM_RH_UP+1
#define TRM_BASE TRM_LH_DWN

#define _MSK_KEY_REPT    0x40
#define _MSK_KEY_DBL     0x10
#define IS_KEY_BREAK(key)  (((key)&0xf0)        ==  0x20)
#define EVT_KEY_BREAK(key) ((key)|                  0x20)
#define EVT_KEY_FIRST(key) ((key)|    _MSK_KEY_REPT|0x20)
#define EVT_KEY_REPT(key)  ((key)|    _MSK_KEY_REPT     )
#define EVT_KEY_LONG(key)  ((key)|0x80)
#define EVT_KEY_DBL(key)   ((key)|_MSK_KEY_DBL)
//#define EVT_KEY_DBL(key)   ((key)|0x10)
#define EVT_ENTRY               (0xff - _MSK_KEY_REPT)
#define EVT_ENTRY_UP            (0xfe - _MSK_KEY_REPT)
#define EVT_KEY_MASK             0x0f


#define INP_D_TRM_LH_UP   7
#define INP_D_TRM_LH_DWN  6
#define INP_D_TRM_RV_DWN  5
#define INP_D_TRM_RV_UP   4
#define INP_D_TRM_LV_DWN  3
#define INP_D_TRM_LV_UP   2
#define INP_D_TRM_RH_DWN  1
#define INP_D_TRM_RH_UP   0

#define RESX    (1<<10) // 1024
#define RESXu   1024u
#define RESXul  1024ul
#define RESXl   1024l
#define RESKul  100ul
#define RESX_PLUS_TRIM (RESX+128)

#define NUM_PPM     8
//number of real outputchannels CH1-CH16
#define NUM_CHNOUT  16
///number of real input channels (1-9) plus virtual input channels X1-X4
#define PPM_BASE    MIX_CYC3
#define CHOUT_BASE  (PPM_BASE+NUM_PPM)

#define SWASH_TYPE_STR   "---   ""120   ""120X  ""140   ""90    "

#define SWASH_TYPE_120   1
#define SWASH_TYPE_120X  2
#define SWASH_TYPE_140   3
#define SWASH_TYPE_90    4
#define SWASH_TYPE_NUM   4


#define MIX_P1    5
#define MIX_P2    6
#define MIX_P3    7
#define MIX_MAX   8
#define MIX_FULL  9
#define MIX_CYC1  10
#define MIX_CYC2  11
#define MIX_CYC3  12

#define DR_HIGH   0
#define DR_MID    1
#define DR_LOW    2
#define DR_EXPO   0
#define DR_WEIGHT 1
#define DR_RIGHT  0
#define DR_LEFT   1
#define DR_DRSW1  99
#define DR_DRSW2  98

#define DSW_THR  1
#define DSW_RUD  2
#define DSW_ELE  3
#define DSW_ID0  4
#define DSW_ID1  5
#define DSW_ID2  6
#define DSW_AIL  7
#define DSW_GEA  8
#define DSW_TRN  9
#define DSW_SW1  10
#define DSW_SW2  11
#define DSW_SW3  12
#define DSW_SW4  13
#define DSW_SW5  14
#define DSW_SW6  15
#define DSW_SW7   16
#define DSW_SW8   17
#define DSW_SW9   18
#define DSW_SWA   19
#define DSW_SWB   20
#define DSW_SWC   21


extern uint8_t Ee_lock ;

// Bit masks in Ee_lock
#define EE_LOCK      1
#define EE_TRIM_LOCK 2

#define EE_GENERAL 1
#define EE_MODEL   2
#define EE_TRIM    4           // Store model because of trim

template<class t> inline t min(t a, t b){ return a<b?a:b; }
template<class t> inline t max(t a, t b){ return a>b?a:b; }

// This doesn't need protection on this processor
#define get_tmr10ms() g_tmr10ms

#define sysFLAG_OLD_EEPROM (0x01)
extern uint8_t sysFlags;

const char s_charTab[]=" ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_-.";
#define NUMCHARS (sizeof(s_charTab)-1)

const char modn12x3[]= {
    1, 2, 3, 4,
    1, 3, 2, 4,
    4, 2, 3, 1,
    4, 3, 2, 1 };

extern const uint8_t chout_ar[] ;

#define CONVERT_MODE(x)  (((x)<=4) ? convert_mode_helper(x) : (x))
#define CHANNEL_ORDER(x) (chout_ar[g_eeGeneral.templateSetup*4 + (x)-1])
#define THR_STICK       (2-(g_eeGeneral.stickMode&1))
#define ELE_STICK       (1+(g_eeGeneral.stickMode&1))
#define AIL_STICK       ((g_eeGeneral.stickMode&2) ? 0 : 3)
#define RUD_STICK       ((g_eeGeneral.stickMode&2) ? 3 : 0)

#define STORE_MODELVARS_TRIM   eeDirty(EE_MODEL|EE_TRIM)
#define STORE_MODELVARS   eeDirty(EE_MODEL)
#define STORE_GENERALVARS eeDirty(EE_GENERAL)

typedef void (*MenuFuncP)(uint8_t event);




extern uint8_t heartbeat ;
extern int16_t            g_chans512[NUM_CHNOUT];
extern uint8_t eeprom[4096] ;

uint8_t char2idx(char c);
char idx2char(uint8_t idx);

extern volatile uint32_t Timer2_count ;		// Modified in interrupt routine
extern volatile uint16_t g_tmr10ms ;
extern volatile uint8_t  g_blinkTmr10ms;
extern volatile uint8_t tick10ms ;
extern uint32_t Master_frequency ;

extern void alert(const char * s, bool defaults=false);
extern void message(const char * s);
extern void resetTimer2( void ) ;

extern void putsTime(uint8_t x,uint8_t y,int16_t tme,uint8_t att,uint8_t att2) ;
extern void putsVolts(uint8_t x,uint8_t y, uint8_t volts, uint8_t att) ;
extern void putsVBat(uint8_t x,uint8_t y,uint8_t att) ;
extern void putsVBat(uint8_t x,uint8_t y,uint8_t att) ;
extern void putsChnRaw(uint8_t x,uint8_t y,uint8_t idx,uint8_t att) ;
extern void putsChn(uint8_t x,uint8_t y,uint8_t idx1,uint8_t att) ;
extern void putsDrSwitches(uint8_t x,uint8_t y,int8_t idx1,uint8_t att) ; //, bool nc) ;
extern const char *get_switches_string( void ) ;

void eeWaitComplete( void ) ;
void eeDirty(uint8_t msk);
void eeCheck(bool immediately=false ) ;
void eeReadAll( void ) ;

extern char idx2char(uint8_t idx) ;
extern uint8_t char2idx(char c) ;


/// goto given Menu, but substitute current menu in menuStack
extern void    chainMenu(MenuFuncP newMenu);
/// goto given Menu, store current menu in menuStack
extern void    pushMenu(MenuFuncP newMenu);
///deliver address of last menu which was popped from
extern MenuFuncP lastPopMenu();
/// return to last menu in menustack
/// if uppermost is set true, thenmenu return to uppermost menu in menustack
void    popMenu(bool uppermost=false);







