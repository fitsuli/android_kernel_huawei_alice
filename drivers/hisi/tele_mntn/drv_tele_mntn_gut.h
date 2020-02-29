/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : drv_tele_mntn_gut.h
  �� �� ��   : ����
  ��    ��   : ���� 00186593
  ��������   : 2014��4��1��
  ����޸�   :
  ��������   : drv_tele_mntn_gut.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2014��4��1��
    ��    ��   : ���� 00186593
    �޸�����   : �����ļ�

******************************************************************************/

#ifndef __DRV_TELE_MNTN_GUT_H__
#define __DRV_TELE_MNTN_GUT_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include  "drv_tele_mntn_common.h"
#include  "drv_tele_mntn_platform.h"

/*****************************************************************************
  2 �궨��
*****************************************************************************/

#undef TELE_MNTN_DEBUG_SW

#ifdef TELE_MNTN_DEBUG_SW
#define TELE_MNTN_DISCARD_SLICE_BUF_NUM (64)           /*����Ϊ2��n����*/
#define TELE_MNTN_WUACORE_SLICE_BUF_NUM (64)           /*����Ϊ2��n����*/
#endif

#define TELE_MNTN_PROTECT1              (0x55AA55AA)
#define TELE_MNTN_PROTECT2              (0x5A5A5A5A)
#define TELE_MNTN_PROTECT_LEN           (sizeof(u32_t)) /* ���䱣���ֳ��ȣ���λbyte������ͷ������ͷ��β�������������ı����� */
#define TELE_MNTN_PROTECT               (0x43415254)    /*TRAC*/

#define TELE_MNTN_INIT_MAGIC            (0x20140407)
#define TELE_MNTN_VALID_MAGIC           (0x20142137)

#define TELE_MNTN_HEAD_SIZE             (sizeof(struct tele_mntn_head))
#define TELE_MNTN_DATA_SIZE             (sizeof(struct tele_mntn_data))

#define TELE_MNTN_SECOND_TO_SLICE(s)    ((s)*32768)
/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/


/*****************************************************************************
  4 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  5 ��Ϣ����
*****************************************************************************/
typedef struct tele_mntn_head
{
    u32_t protect_word1;     /*������ 0x55AA55AA*/
    u32_t front;             /*���д�д��Ԫ�������(����������)ͷ�ĳ��ȣ���λ32bit */
    u32_t rear;              /*���д�����Ԫ�������(����������)ͷ�ĳ��ȣ���λ32bit */
    u32_t protect_word2;     /*������ 0x55AA55AA*/
} TELE_MNTN_HEAD_STRU;

typedef struct tele_mntn_data
{
    u32_t protect;
    u32_t type_id;
    u32_t idex:30;
    u32_t cpu_id:2;
    u32_t rtc;
    u32_t slice;
    u32_t len;
}TELE_MNTN_DATA_STRU;
/*****************************************************************************
  6 STRUCT����
*****************************************************************************/

typedef struct tele_mntn_cfg
{
    u32_t data_addr;   /*�ڴ��ַ*/
    u32_t data_size;   /*��С*/
    u32_t wake_threshold;
    u32_t wake_interval_threshold;/*���λ��ѵ�ʱ��������λ s*/
    u32_t user_data_threshold;
    u32_t ipc_int_num;
    u32_t ipc_sem_num;
    u8_t* data_virt_addr;
}TELE_MNTN_CFG_STRU;

#ifdef TELE_MNTN_DEBUG_SW
typedef struct tele_mntn_debug
{
    u32_t discard_num;
    u32_t discard_silce[TELE_MNTN_DISCARD_SLICE_BUF_NUM];
    u32_t wakeup_accore_num;
    u32_t wakeup_accore_silce[TELE_MNTN_WUACORE_SLICE_BUF_NUM];
    u32_t peak_left_size;
    u32_t peak_left_slice;
}TELE_MNTN_DEBUG_STRU;
#endif

typedef struct tele_mntn_handle
{
    u32_t init_flag;
    u32_t idex;
    u32_t prior_wakeup_acore_slice;
#ifdef TELE_MNTN_DEBUG_SW
    struct tele_mntn_debug debug;
#endif
    struct tele_mntn_queue queue;
#if defined (BSP_CORE_APP)
    spinlock_t lock;
    udy_t flag;
#else
    u32_t lock;
    u32_t flag;
#endif
}TELE_MNTN_HANDLE;


/*****************************************************************************
  7 UNION����
*****************************************************************************/


/*****************************************************************************
  8 OTHERS����
*****************************************************************************/


/*****************************************************************************
  9 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
  10 ��������
*****************************************************************************/
extern s32_t tele_mntn_init_cfg(void_t);
extern s32_t tele_mntn_write_buf(TELE_MNTN_DATA_STRU *head_data, void_t * data, u32_t len, TELE_MNTN_BUF_TYPE buf_type);
#ifdef TELE_MNTN_DEBUG_SW
extern void_t tele_mntn_debug_out(void_t);
#endif


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of drv_tele_mntn_gut.h */
