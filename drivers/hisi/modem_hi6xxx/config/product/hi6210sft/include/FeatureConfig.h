/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : FeatureConfig.h
  �� �� ��   :
  ��    ��   : ��� 62584
  ��������   : 2008��03��11��
  ����޸�   :
  ��������   : �����˲�Ʒ����ģ�����Ժ궨��
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2008��03��11��
    ��    ��   : ��� 62584
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __FEATURECONFIG_H__
#define __FEATURECONFIG_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/* �������Ա��� */
#define FEATURE_ON                                  1
#define FEATURE_OFF                                 0

#define MEMORY_SIZE_32M                             1
#define MEMORY_SIZE_64M                             2
#define MEMORY_SIZE_128M                            3
#define MEMORY_SIZE_256M                            4
#define MEMORY_SIZE_512M                            5
/* Э��ջ�汾 */
#define PS_PTL_VER_DANAMIC                          20

#define PS_PTL_VER_PRE_R99                          (-2)
#define PS_PTL_VER_R99                              (-1)
#define PS_PTL_VER_R3                               0
#define PS_PTL_VER_R4                               1
#define PS_PTL_VER_R5                               2
#define PS_PTL_VER_R6                               3
#define PS_PTL_VER_R7                               4
#define PS_PTL_VER_R8                               5
#define PS_PTL_VER_R9                               6
#define PS_UE_REL_VER                               PS_PTL_VER_R9

/* GSM ͨ�Ž��뼼��ģʽ */
#define FEATURE_UE_MODE_G                           FEATURE_ON

/* WCDMA ͨ�Ž��뼼��ģʽ */
#define FEATURE_UE_MODE_W                           FEATURE_ON

/* ֧��CS����ҵ�� */
#define FEATURE_CS                                  FEATURE_ON

/* Gģ����֧�� */
#define FEATURE_GFAX                                FEATURE_OFF

/* Wģ����֧�� */
#define FEATURE_WFAX                                FEATURE_OFF

/* GС���㲥 */
#define FEATURE_GCBS                                FEATURE_ON

/* WС���㲥 */
#define FEATURE_WCBS                                FEATURE_ON

/* ֧��AP */
#define FEATURE_AP                                  FEATURE_OFF

/* ֧��BALONG_UDP_V1R1 */
#define BALONG_UDP_V1R1                             FEATURE_OFF

/* ֧��BALONG_UDP_V1R2 */
#define BALONG_UDP_V1R2                             FEATURE_OFF

/* ֧�� PTABLE UDP */
#define FEATURE_PTABLE_UDP                          FEATURE_ON

/* ֧��STICK */
#define FEATURE_STICK                               FEATURE_OFF

/* ֧��E5 */
#define FEATURE_E5                                  FEATURE_OFF

/* ֧��E5_UDP */
#define FEATURE_E5_UDP                              FEATURE_OFF

/* PC Voice */
#define FEATURE_PC_VOICE                            FEATURE_OFF

/* Lighting Card */
#define FEATURE_HILINK                              FEATURE_OFF

/* Security Boot */
#define FEATURE_SEC_BOOT                            FEATURE_OFF

/* �Ƿ�֧�ֶ�ģ */
#ifdef VERSION_V7R1_C010
#define FEATURE_LTE                                 FEATURE_ON
#else
#define FEATURE_LTE                                 FEATURE_OFF
#endif

#define FEATURE_CSD                                 FEATURE_OFF

#define FEATURE_NDIS                                FEATURE_ON

#define FEATURE_IPV6                                FEATURE_OFF
#define FEATURE_PPP                                 FEATURE_ON

#define FEATURE_PPPOE                               FEATURE_OFF


/* Update OnLine*/
#define FEATURE_UPDATEONLINE                        FEATURE_OFF

/* wifi*/
#define FEATURE_WIFI                                FEATURE_OFF

/*hifi*/  
#define FEATURE_HIFI                                FEATURE_OFF

/* sdio*/
#define FEATURE_SDIO                                FEATURE_OFF

/* keyboard*/
#define FEATURE_KEYBOARD                            FEATURE_OFF

/*charge*/
#define FEATURE_CHARGE                              FEATURE_OFF

#define FEATURE_ICC_DEBUG                           FEATURE_OFF/*ICC��ά�ɲ���Դ�׮*/

/*power_on_off*/
#define FEATURE_POWER_ON_OFF                        FEATURE_OFF

/*OLED*/
#define FEATURE_OLED                                FEATURE_OFF

/*TFT*/
#define FEATURE_TFT                                 FEATURE_OFF

/*MMI_TEST*/
#define FEATURE_MMI_TEST                            FEATURE_OFF
/* DL E CELL FACH */
#define FEATURE_DL_E_CELL_FACH                      FEATURE_ON

#define FEATURE_DC_MIMO                             FEATURE_OFF

/*harq ����*/
#define FEATURE_HARQ_OUT                            FEATURE_OFF

/*interpeak*/
#define FEATURE_INTERPEAK                           FEATURE_OFF

/*interpeak_mini �ú궨��������FEATURE_INTERPEAK������FEATURE_INTERPEAKΪONʱ��Ч��*/
#define FEATURE_INTERPEAK_MINI                      FEATURE_OFF

/*ipwebs_feature_e5*/
#define IPWEBS_FEATURE_E5                           FEATURE_OFF

/*ipwebs_feature_wireless_dongle*/
#define IPWEBS_FEATURE_WIRELESS_DONGLE              FEATURE_OFF

/*ipwebs_feature_lightning_card*/
#define IPWEBS_FEATURE_LIGHTNING_CARD               FEATURE_OFF

/*feature_webnas*/
#define FEATURE_WEBNAS                              FEATURE_OFF

/* Disable Autorun */
/*#define FEATURE_AUTORUN_HL_1_1                      FEATURE_OFF*/

/* E355 */
#define FEATURE_WIRELESS_DONGLE                     FEATURE_OFF

/* PMU current overflow and high-temperature protection */
#define FEATURE_PMU_PROTECT                         FEATURE_OFF

/* VxWorks TCPIP protocol stack */
#define FEATURE_VXWORKS_TCPIP                       FEATURE_OFF

#define FEATURE_M2                                  FEATURE_OFF

/*memory size */
#define FEATURE_MEMORY_SIZE                         MEMORY_SIZE_64M

#define FEATURE_ECM_RNDIS                           FEATURE_OFF

#define FEATURE_RNIC                                FEATURE_OFF

#define FEATURE_NFEXT                               FEATURE_OFF

#define FEATURE_UL_E_CELL_FACH                      FEATURE_OFF

#define FEATURE_DC_UPA                              FEATURE_OFF
/*E5 ������*/
#define FEATURE_BREATH_LIGHT                        FEATURE_OFF
/* ��ɫ��ʹ�ܿ��� */
#define FEATURE_LEDSTATUS                           FEATURE_OFF
/*E5 LED*/
#define FEATURE_E5_LED                              FEATURE_OFF
/*RTC���Կ���*/
#define FEATURE_RTC                                 FEATURE_OFF
/* BBPС����: �����Կ�����, WTTF�ὫBBP�����е����ݿ�����TTF MEM, �Ӷ���С
BBP������, �ﵽ�ü��ڴ��Ŀ�� */
#define FEATURE_SMALL_MAILBOX                       FEATURE_OFF
/* �͹��ķ������µ���ʱ���� */
#define FEATURE_TEMP_DSP_CORE_POWER_DOWN            FEATURE_OFF
#define FEATURE_RECONFIG                            FEATURE_ON

/* Ӳ���ܰ汾�������Ժ꣬E5 �ϴ򿪣�stick �Ȱ汾�رա��μ� matao00151948 ���ʼ� */
#define FEATURE_HWENCRY_REWORK                      FEATURE_OFF

/* �ڴ�ع�����Ԫ */
#define FEATURE_MMU_BIG                             FEATURE_OFF

#define FEATURE_MMU_MEDIUM                          FEATURE_ON

#define FEATURE_MMU_SMALL                           FEATURE_OFF

#define FEATURE_TTFMEM_CACHE                        FEATURE_OFF

#define FEATURE_SDUPDATE                            FEATURE_OFF

/* x00195127 add for SHELL LOCK���� */
#define FEATURE_SECURITY_SHELL                      FEATURE_ON

#define FEATURE_EPAD                                FEATURE_OFF

#define FEATURE_HSIC_SLAVE                          FEATURE_OFF

/* ��Ƭ�汾��LOG */
#ifdef PRODUCT_CFG_BURN_OPEN
#define FEATURE_MANUFACTURE_LOG                     FEATURE_ON
#else
#define FEATURE_MANUFACTURE_LOG                     FEATURE_OFF
#endif

#define FEATURE_MEM_MONITOR                         FEATURE_ON


#define FEATURE_TEMP_MULTI_MODE_LP                  FEATURE_OFF

#define FEATURE_DRV_REPLAY_DUMP                     FEATURE_OFF

/*V3R2 CS f00164371*/
#define FEATURE_POWER_DRV                           FEATURE_ON/*monan for v9r1bbit FEATURE_ON
 */

#define FEATURE_SIM_NOTIFY                          FEATURE_OFF

#define FEATURE_HW_CODEC                            FEATURE_ON

/* SKB�Ƿ�Ϊ��չ�ṹ���� */
#define FEATURE_SKB_EXP                             FEATURE_OFF

/* ���ļ�ϵͳ���� */
#define FEATURE_MULTI_FS_PARTITION                  FEATURE_ON 

#define FEATURE_MULTI_MODEM                         FEATURE_OFF

/* socpͨ���ü� */
#define FEATURE_SOCP_CHANNEL_REDUCE                 FEATURE_OFF

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* __FEATURECONFIG_H__ */
