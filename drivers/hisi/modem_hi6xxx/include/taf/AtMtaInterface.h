/******************************************************************************

                  ��Ȩ���� (C), 2001-2012, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : AtMtaInterface.h
  �� �� ��   : ����
  ��    ��   : ��־��
  ��������   : 2012��6��27��
  ����޸�   :
  ��������   : MTAģ����ATģ����ͨ����ϢID����Ϣ�ṹ����
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2012��6��27��
    ��    ��   : Y00213812
    �޸�����   : A-GPS��Ŀ����

******************************************************************************/

#ifndef __ATMTAINTERFACE_H__
#define __ATMTAINTERFACE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "PsTypeDef.h"
#include "AtMnInterface.h"
#include "MtaPhyInterface.h"
/* Modified by s00217060 for VoLTE_PhaseI  ��Ŀ, 2013-07-27, begin */
#include "NasNvInterface.h"
/* Modified by s00217060 for VoLTE_PhaseI  ��Ŀ, 2013-07-27, end */

/*****************************************************************************
  2 �궨��
*****************************************************************************/
#define MTA_CPOS_XML_MAX_LEN            (1024)              /* MTA����AT�·���XML������󳤶� */
#define MTA_CPOSR_XML_MAX_LEN           (1024)              /* MTA��AT�ϱ���XML������󳤶�Ϊ1024 */
/* Added by l00198894 for V7R1C50 ISDB Project, 2012/08/28, begin */
#define MTA_SEC_PACKET_MAX_LEN          (272)               /* AP��ȫ�������󳤶� */
/* Added by l00198894 for V7R1C50 ISDB Project, 2012/08/28, end */
/* Added by l00198894 for STK&DCM Project, 2012/09/18, begin */
#define MTA_SIMLOCK_PASSWORD_LEN        (16)                /* ����������������ĳ��� */
/* Added by l00198894 for STK&DCM Project, 2012/09/18, end */

#define MTA_CLIENTID_BROADCAST          (0xFFFF)
#define MTA_INVALID_TAB_INDEX           (0x00)


/* Added by m00217266 for DSDA GUNAS C CORE, 2013-01-06, begin */
#define AT_MTA_WRR_AUTOTEST_MAX_PARA_NUM          (10) /* autotest�����·����������� */
#define MTA_AT_WRR_AUTOTEST_MAX_RSULT_NUM         (20) /* autotest�����ϱ���������� */
#define MTA_AT_WRR_ONE_MEANRPT_MAX_CELL_NUM       (8)  /* һ�β���������С�������� */
#define MTA_AT_WRR_MAX_MEANRPT_NUM                (10) /* �ϱ������������������� */

#define MTA_AT_WRR_MAX_NCELL_NUM                  (8)
/* Added by m00217266 for DSDA GUNAS C CORE, 2013-01-06, end */

/* Added by s00217060 for �����ϱ�AT�������������C��, 2013-3-25, begin */
#define AT_MTA_RPT_CFG_MAX_SIZE                   (8)
/* Added by s00217060 for �����ϱ�AT�������������C��, 2013-3-25, end */

/* Added by m00217266 for AP Sensor, 2013-08-07, begin */
#define AT_MTA_HANDLEDECT_MIN_TYPE                (0)
#define AT_MTA_HANDLEDECT_MAX_TYPE                (4)
/* Added by m00217266 for AP Sensor, 2013-08-07, End */

/* Added by l00198894 for NVWR Security Control, 2015-04-04, begin */
#define AT_RSA_CIPHERTEXT_LEN           (128)
/* Added by l00198894 for NVWR Security Control, 2015-04-04, end */

/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/
/*****************************************************************************
 ö����    : AT_MTA_MSG_TYPE_ENUM
 �ṹ˵��  : AT��MTA��Ϣ�ӿ�ö��
1.��    ��  : 2012��06��28��
  ��    ��  : y00213812
  �޸�����  : V7R1C50 A_GPS��Ŀ�����ṹ
2.��    ��   : 2012��11��21��
  ��    ��   : z00161729
  �޸�����  : ֧��cerssi��nmr
3.��    ��   : 2012��12��26��
  ��    ��   : m00217266
  �޸�����   :  ����WAS�ӿڵ���ϢID
4.��    ��  : 2013��03��13��
  ��    ��  : z00214637
  �޸�����  : BodySAR��Ŀ
5.��    ��   : 2013��3��25��
  ��    ��   : s00217060
  �޸�����   : ���������ϱ�������C�˵���ϢID
*****************************************************************************/
enum AT_MTA_MSG_TYPE_ENUM
{
    /* ��Ϣ���� */                      /* ��ϢID */        /* ��ע, ����ASN */
    /* AT����MTA����Ϣ */
    ID_AT_MTA_CPOS_SET_REQ              = 0x0000,           /* _H2ASN_MsgChoice AT_MTA_CPOS_REQ_STRU        */
    ID_AT_MTA_CGPSCLOCK_SET_REQ         = 0x0001,           /* _H2ASN_MsgChoice AT_MTA_CGPSCLOCK_REQ_STRU   */
    /* Added by l00198894 for V7R1C50 ISDB Project, 2012/08/28, begin */
    ID_AT_MTA_APSEC_SET_REQ             = 0x0002,           /* _H2ASN_MsgChoice AT_MTA_APSEC_REQ_STRU       */
    /* Added by l00198894 for V7R1C50 ISDB Project, 2012/08/28, end */
    /* Added by l00198894 for STK&DCM Project, 2012/09/18, begin */
    ID_AT_MTA_SIMLOCKUNLOCK_SET_REQ     = 0x0003,           /* _H2ASN_MsgChoice AT_MTA_SIMLOCKUNLOCK_REQ_STRU */
    /* Added by l00198894 for STK&DCM Project, 2012/09/18, end */

    /* Modified by z00161729 for cerssi, 2012-11-21, begin */
    ID_AT_MTA_QRY_NMR_REQ               = 0x0004,           /* _H2ASN_MsgChoice AT_MTA_QRY_NMR_REQ_STRU */
    /* Modified by z00161729 for cerssi, 2012-11-21, end */

    /* Added by t00212959 for WLTHRESHOLDCFG, 2012-12-10, begin */
    ID_AT_MTA_RESEL_OFFSET_CFG_SET_NTF  = 0x0005,           /* _H2ASN_MsgChoice AT_MTA_RESEL_OFFSET_CFG_SET_NTF_STRU */
    /* Added by t00212959 for WLTHRESHOLDCFG, 2012-12-10, end */
    /* Added by m00217266 for DSDA GUNAS C CORE, 2012-12-26, begin */
    ID_AT_MTA_WRR_AUTOTEST_QRY_REQ      = 0x0006,           /* _H2ASN_MsgChoice AT_MTA_WRR_AUTOTEST_QRY_PARA_STRU */
    ID_AT_MTA_WRR_CELLINFO_QRY_REQ      = 0x0007,           /* _H2ASN_MsgChoice AT_MTA_RESERVE_STRU */
    ID_AT_MTA_WRR_MEANRPT_QRY_REQ       = 0x0008,           /* _H2ASN_MsgChoice AT_MTA_RESERVE_STRU */
    ID_AT_MTA_WRR_FREQLOCK_SET_REQ      = 0x0009,           /* _H2ASN_MsgChoice MTA_AT_WRR_FREQLOCK_CTRL_STRU     */
    ID_AT_MTA_WRR_RRC_VERSION_SET_REQ   = 0x000A,           /* _H2ASN_MsgChoice AT_MTA_RESERVE_STRU*/
    ID_AT_MTA_WRR_CELLSRH_SET_REQ       = 0x000B,           /* _H2ASN_MsgChoice AT_MTA_RESERVE_STRU*/
    ID_AT_MTA_WRR_FREQLOCK_QRY_REQ      = 0x000C,           /* _H2ASN_MsgChoice AT_MTA_RESERVE_STRU */
    ID_AT_MTA_WRR_RRC_VERSION_QRY_REQ   = 0x000D,           /* _H2ASN_MsgChoice AT_MTA_RESERVE_STRU */
    ID_AT_MTA_WRR_CELLSRH_QRY_REQ       = 0x000E,           /* _H2ASN_MsgChoice AT_MTA_RESERVE_STRU */
    /* Added by m00217266 for DSDA GUNAS C CORE, 2012-12-26, end */

    /* Added by z00214637 for Body Sar Project, 2013-03-11, begin */
    ID_AT_MTA_BODY_SAR_SET_REQ          = 0x000F,           /* _H2ASN_MsgChoice AT_MTA_BODY_SAR_SET_REQ_STRU */
    /* Added by z00214637 for Body Sar Project, 2013-03-11, end */
    /* Added by s00217060 for �����ϱ�AT�������������C��, 2013-3-25, begin */
    ID_AT_MTA_CURC_SET_NOTIFY           = 0x0010,           /* _H2ASN_MsgChoice AT_MTA_CURC_SET_NOTIFY_STRU */
    ID_AT_MTA_CURC_QRY_REQ              = 0x0011,           /* _H2ASN_MsgChoice AT_MTA_CURC_QRY_REQ_STRU */
    ID_AT_MTA_UNSOLICITED_RPT_SET_REQ   = 0x0012,           /* _H2ASN_MsgChoice AT_MTA_UNSOLICITED_RPT_SET_REQ_STRU */
    ID_AT_MTA_UNSOLICITED_RPT_QRY_REQ   = 0x0013,           /* _H2ASN_MsgChoice AT_MTA_UNSOLICITED_RPT_QRY_REQ_STRU */
    /* Added by s00217060 for �����ϱ�AT�������������C��, 2013-3-25, end */

    /* Added by Y00213812 for IMEI_VERIFY Project, 2013-05-23, begin */
    ID_AT_MTA_IMEI_VERIFY_QRY_REQ       = 0x0014,           /* _H2ASN_MsgChoice AT_MTA_RESERVE_STRU */
    ID_AT_MTA_CGSN_QRY_REQ              = 0x0015,           /* _H2ASN_MsgChoice AT_MTA_RESERVE_STRU */
    /* Added by Y00213812 for IMEI_VERIFY Project, 2013-05-23, end */
    /* Added by s00217060 for V9R1_SVLTE, 2013-6-4, begin */
    ID_AT_MTA_NCELL_MONITOR_SET_REQ     = 0x0016,           /* _H2ASN_MsgChoice AT_MTA_NCELL_MONITOR_SET_REQ_STRU */
    ID_AT_MTA_NCELL_MONITOR_QRY_REQ     = 0x0017,           /* _H2ASN_MsgChoice AT_MTA_RESERVE_STRU */
    /* Added by s00217060 for V9R1_SVLTE, 2013-6-4, end */

    /* Added by l00198894 for V9R1 AGPS, 2013/07/22, begin */
    ID_AT_MTA_REFCLKFREQ_SET_REQ        = 0x0018,           /* _H2ASN_MsgChoice AT_MTA_REFCLKFREQ_SET_REQ_STRU */
    ID_AT_MTA_REFCLKFREQ_QRY_REQ        = 0x0019,           /* _H2ASN_MsgChoice AT_MTA_RESERVE_STRU */
    /* Added by l00198894 for V9R1 AGPS, 2013/07/22, end */

    /* Added by m00217266 for AP Sensor, 2013-08-07, begin */
    ID_AT_MTA_HANDLEDECT_SET_REQ        = 0x001A,           /* _H2ASN_MsgChoice AT_MTA_RESERVE_STRU */
    ID_AT_MTA_HANDLEDECT_QRY_REQ        = 0x001B,           /* _H2ASN_MsgChoice AT_MTA_RESERVE_STRU */
    /* Added by m00217266 for AP Sensor, 2013-08-07, End */

    /* Added by l00198894 for ����+ECID����, 2013-12-09, begin */
    ID_AT_MTA_ECID_SET_REQ              = 0x001C,           /* _H2ASN_MsgChoice AT_MTA_ECID_SET_REQ_STRU */
    /* Added by l00198894 for ����+ECID����, 2013-12-09, end */

    /* Add by j00174725 for RF&LCD INTRUSION, 2014-03-04, Begin */
    ID_AT_MTA_MIPICLK_QRY_REQ           = 0x001D,           /* _H2ASN_MsgChoice AT_MTA_RESERVE_STRU */
    /* Add by j00174725 for RF&LCD INTRUSION, 2014-03-04, End */

    /* Added by g00261581 for Jazz DPDT, 2014-04-04, begin */
    ID_AT_MTA_SET_DPDTTEST_FLAG_REQ     = 0x001E,           /* _H2ASN_MsgChoice AT_MTA_SET_DPDTTEST_FLAG_REQ_STRU */
    ID_AT_MTA_SET_DPDT_VALUE_REQ        = 0x001F,           /* _H2ASN_MsgChoice AT_MTA_SET_DPDT_VALUE_REQ_STRU */
    ID_AT_MTA_QRY_DPDT_VALUE_REQ        = 0x0020,           /* _H2ASN_MsgChoice AT_MTA_QRY_DPDT_VALUE_REQ_STRU */
    /* Added by g00261581 for Jazz DPDT, 2014-04-04, End */

    /*added by y00176023 for DSDS II,2014-03-24,begin*/
    ID_AT_MTA_RRC_PROTECT_PS_REQ        = 0x0021,
    ID_AT_MTA_PHY_INIT_REQ              = 0x0022,
    /*added by y00176023 for DSDS II,2014-03-24,end*/

    /* Added by g00261581 for V3R3 JAM DETECT Project, 2014-05-04, begin */
    ID_AT_MTA_SET_JAM_DETECT_REQ        = 0x0023,           /* _H2ASN_MsgChoice AT_MTA_SET_JAM_DETECT_REQ_STRU */
    /* Added by g00261581 for V3R3 JAM DETECT Project, 2014-05-04, end */

    /* Added by g00261581 for V7R11 FREQ LOCK Project, 2014-06-11, begin */
    ID_AT_MTA_SET_FREQ_LOCK_REQ         = 0x0024,           /* _H2ASN_MsgChoice AT_MTA_SET_FREQ_LOCK_REQ_STRU */
    /* Added by g00261581 for V7R11 FREQ LOCK Project, 2014-06-11, end */

    /* Added by j00174725 for GU ROAD TEST, 2014-08-05, Begin */
    ID_AT_MTA_SET_GSM_FREQLOCK_REQ      = 0x0025,          /* _H2ASN_MsgChoice AT_MTA_SET_GSM_FREQLOCK_REQ_STRU */
    /* Added by j00174725 for GU ROAD TEST, 2014-08-05, End */

    /* Added by l00198894 for NVWR Security Control, 2015-04-04, begin */
    ID_AT_MTA_NVWRSECCTRL_SET_REQ       = 0x0027,
    /* Added by l00198894 for NVWR Security Control, 2015-04-04, end */


    /* MTA����AT����Ϣ */
    ID_MTA_AT_CPOS_SET_CNF              = 0x1000,           /* _H2ASN_MsgChoice MTA_AT_CPOS_CNF_STRU        */
    ID_MTA_AT_CGPSCLOCK_SET_CNF         = 0x1001,           /* _H2ASN_MsgChoice MTA_AT_CGPSCLOCK_CNF_STRU   */
    ID_MTA_AT_CPOSR_IND                 = 0x1002,           /* _H2ASN_MsgChoice MTA_AT_CPOSR_IND_STRU       */
    ID_MTA_AT_XCPOSRRPT_IND             = 0x1003,           /* _H2ASN_MsgChoice MTA_AT_XCPOSRRPT_IND_STRU   */
    /* Added by l00198894 for V7R1C50 ISDB Project, 2012/08/28, begin */
    ID_MTA_AT_APSEC_SET_CNF             = 0x1004,           /* _H2ASN_MsgChoice MTA_AT_APSEC_CNF_STRU       */
    /* Added by l00198894 for V7R1C50 ISDB Project, 2012/08/28, end */
    /* Added by l00198894 for STK&DCM Project, 2012/09/18, begin */
    ID_MTA_AT_SIMLOCKUNLOCK_SET_CNF     = 0x1005,           /* _H2ASN_MsgChoice MTA_AT_SIMLOCKUNLOCK_CNF_STRU */
    /* Added by l00198894 for STK&DCM Project, 2012/09/18, end */

    /* Modified by z00161729 for cerssi, 2012-11-21, begin */
    ID_MTA_AT_QRY_NMR_CNF               = 0x1006,           /* _H2ASN_MsgChoice MTA_AT_QRY_NMR_CNF_STRU */
    /* Modified by z00161729 for cerssi, 2012-11-21, end */

    /* Added by m00217266 for DSDA GUNAS C CORE, 2012-12-26, begin */
    ID_MTA_AT_WRR_AUTOTEST_QRY_CNF      = 0x1007,           /* _H2ASN_MsgChoice MTA_AT_WRR_AUTOTEST_QRY_CNF_STRU       */
    ID_MTA_AT_WRR_CELLINFO_QRY_CNF      = 0x1008,           /* _H2ASN_MsgChoice MTA_AT_WRR_CELLINFO_QRY_CNF_STRU       */
    ID_MTA_AT_WRR_MEANRPT_QRY_CNF       = 0x1009,           /* _H2ASN_MsgChoice MTA_AT_WRR_MEANRPT_QRY_CNF_STRU        */
    ID_MTA_AT_WRR_FREQLOCK_SET_CNF      = 0x100A,           /* _H2ASN_MsgChoice MTA_AT_WRR_FREQLOCK_SET_CNF_STRU       */
    ID_MTA_AT_WRR_RRC_VERSION_SET_CNF   = 0x100B,           /* _H2ASN_MsgChoice MTA_AT_WRR_RRC_VERSION_SET_CNF_STRU    */
    ID_MTA_AT_WRR_CELLSRH_SET_CNF       = 0x100C,           /* _H2ASN_MsgChoice MTA_AT_WRR_CELLSRH_SET_CNF_STRU        */
    ID_MTA_AT_WRR_FREQLOCK_QRY_CNF      = 0x100D,           /* _H2ASN_MsgChoice MTA_AT_WRR_FREQLOCK_QRY_CNF_STRU       */
    ID_MTA_AT_WRR_RRC_VERSION_QRY_CNF   = 0x100E,           /* _H2ASN_MsgChoice MTA_AT_WRR_RRC_VERSION_QRY_CNF_STRU    */
    ID_MTA_AT_WRR_CELLSRH_QRY_CNF       = 0x100F,           /* _H2ASN_MsgChoice MTA_AT_WRR_CELLSRH_QRY_CNF_STRU        */
    /* Added by m00217266 for DSDA GUNAS C CORE, 2012-12-26, end */

    /* Added by z00214637 for Body Sar Project, 2013-03-11, begin */
    ID_MTA_AT_BODY_SAR_SET_CNF          = 0x1010,           /* _H2ASN_MsgChoice MTA_AT_RESULT_CNF_STRU */
    /* Added by z00214637 for Body Sar Project, 2013-03-11, end */

    /* Added by s00217060 for �����ϱ�AT�������������C��, 2013-3-25, begin */
    ID_MTA_AT_CURC_QRY_CNF              = 0x1011,           /* _H2ASN_MsgChoice MTA_AT_CURC_QRY_CNF_STRU */
    ID_MTA_AT_UNSOLICITED_RPT_SET_CNF   = 0x1012,           /* _H2ASN_MsgChoice MTA_AT_UNSOLICITED_RPT_SET_CNF_STRU */
    ID_MTA_AT_UNSOLICITED_RPT_QRY_CNF   = 0x1013,           /* _H2ASN_MsgChoice MTA_AT_UNSOLICITED_RPT_QRY_CNF_STRU */
    /* Added by s00217060 for �����ϱ�AT�������������C��, 2013-3-25, end */

    /* Added by Y00213812 for IMEI_VERIFY Project, 2013-05-23, begin */
    ID_MTA_AT_IMEI_VERIFY_QRY_CNF       = 0x1014,            /* _H2ASN_MsgChoice AT_MTA_RESERVE_STRU */
    ID_MTA_AT_CGSN_QRY_CNF              = 0x1015,            /* _H2ASN_MsgChoice MTA_AT_CGSN_QRY_CNF_STRU */
    /* Added by Y00213812 for IMEI_VERIFY Project, 2013-05-23, end */
    /* Added by s00217060 for V9R1_SVLTE, 2013-6-3, begin */
    ID_MTA_AT_NCELL_MONITOR_SET_CNF     = 0x1016,           /* _H2ASN_MsgChoice MTA_AT_RESULT_CNF_STRU        */
    ID_MTA_AT_NCELL_MONITOR_QRY_CNF     = 0x1017,           /* _H2ASN_MsgChoice MTA_AT_NCELL_MONITOR_QRY_CNF_STRU        */
    ID_MTA_AT_NCELL_MONITOR_IND         = 0x1018,           /* _H2ASN_MsgChoice MTA_AT_NCELL_MONITOR_IND_STRU        */
    /* Added by s00217060 for V9R1_SVLTE, 2013-6-3, end */

    /* Added by l00198894 for V9R1 AGPS, 2013/07/22, begin */
    ID_MTA_AT_REFCLKFREQ_SET_CNF        = 0x1019,           /* _H2ASN_MsgChoice MTA_AT_RESULT_CNF_STRU */
    ID_MTA_AT_REFCLKFREQ_QRY_CNF        = 0x101A,           /* _H2ASN_MsgChoice MTA_AT_REFCLKFREQ_QRY_CNF_STRU */
    ID_MTA_AT_REFCLKFREQ_IND            = 0x101B,           /* _H2ASN_MsgChoice MTA_AT_REFCLKFREQ_IND_STRU */
    /* Added by l00198894 for V9R1 AGPS, 2013/07/22, end */

    /* Added by m00217266 for AP Sensor, 2013-08-07, begin */
    ID_MTA_AT_HANDLEDECT_SET_CNF        = 0x101C,           /* _H2ASN_MsgChoice MTA_AT_HANDLEDECT_SET_CNF_STRU */
    ID_MTA_AT_HANDLEDECT_QRY_CNF        = 0x101D,           /* _H2ASN_MsgChoice MTA_AT_HANDLEDECT_QRY_CNF_STRU */
    /* Added by m00217266 for AP Sensor, 2013-08-07, End */

    /* Added by l00198894 for SVLTE Offline Reselect Project, 2013/10/21, begin */
    ID_MTA_AT_PS_TRANSFER_IND           = 0x101E,           /* _H2ASN_MsgChoice MTA_AT_PS_TRANSFER_IND_STRU */
    /* Added by l00198894 for SVLTE Offline Reselect Project, 2013/10/21, end */

    /* Added by l00198894 for ����+ECID����, 2013-12-09, begin */
    ID_MTA_AT_ECID_SET_CNF              = 0x101F,           /* _H2ASN_MsgChoice MTA_AT_ECID_SET_CNF_STRU */
    /* Added by l00198894 for ����+ECID����, 2013-12-09, end */

    /* Add by j00174725 for RF&LCD INTRUSION, 2014-03-04, Begin */
    ID_MTA_AT_MIPICLK_QRY_CNF           = 0x1020,           /* _H2ASN_MsgChoice MTA_AT_RF_LCD_MIPICLK_CNF_STRU */
    ID_MTA_AT_MIPICLK_INFO_IND          = 0x1021,           /* _H2ASN_MsgChoice MTA_AT_RF_LCD_MIPICLK_IND_STRU */
    /* Add by j00174725 for RF&LCD INTRUSION, 2014-03-04, End */

    /* Added by g00261581 for Jazz DPDT, 2014-04-04, begin */
    ID_MTA_AT_SET_DPDTTEST_FLAG_CNF     = 0x1022,           /* _H2ASN_MsgChoice MTA_AT_SET_DPDTTEST_FLAG_CNF_STRU */
    ID_MTA_AT_SET_DPDT_VALUE_CNF        = 0x1023,           /* _H2ASN_MsgChoice MTA_AT_SET_DPDT_VALUE_CNF_STRU */
    ID_MTA_AT_QRY_DPDT_VALUE_CNF        = 0x1024,           /* _H2ASN_MsgChoice MTA_AT_QRY_DPDT_VALUE_CNF_STRU */
    /* Added by g00261581 for Jazz DPDT, 2014-04-04, End */

    /*added by y00176023 for DSDS II,2014-03-19,begin*/
    ID_MTA_AT_RRC_PROTECT_PS_CNF        = 0x1025,
    ID_MTA_AT_PHY_INIT_CNF              = 0x1026,
    /*added by y00176023 for DSDS II,2014-03-19,end*/

    /* Added by g00261581 for V3R3 JAM DETECT Project, 2014-05-04, begin */
    ID_MTA_AT_SET_JAM_DETECT_CNF        = 0x1027,           /* _H2ASN_MsgChoice MTA_AT_SET_JAM_DETECT_CNF_STRU */
    ID_MTA_AT_JAM_DETECT_IND            = 0x1028,           /* _H2ASN_MsgChoice MTA_AT_JAM_DETECT_IND_STRU */
    /* Added by g00261581 for V3R3 JAM DETECT Project, 2014-05-04, end */

    /* Added by g00261581 for V7R11 FREQ LOCK Project, 2014-06-11, begin */
    ID_MTA_AT_SET_FREQ_LOCK_CNF         = 0x1029,           /* _H2ASN_MsgChoice MTA_AT_SET_FREQ_LOCK_CNF_STRU */
    /* Added by g00261581 for V7R11 FREQ LOCK Project, 2014-06-11, end */

    /* Added by j00174725 for GU ROAD TEST, 2014-08-05, Begin */
    ID_MTA_AT_SET_GSM_FREQLOCK_CNF      = 0x102A,           /* _H2ASN_MsgChoice MTA_AT_SET_GSM_FREQLOCK_CNF_STRU */
    /* Added by j00174725 for GU ROAD TEST, 2014-08-05, End */
    /* Added by m00217266 for Xpass reselect, 2014-12-25, begin */
    ID_MTA_AT_XPASS_INFO_IND            = 0x102C,
    /* Added by m00217266 for Xpass reselect, 2014-12-25, end */

    /* Added by l00198894 for NVWR Security Control, 2015-04-04, begin */
    ID_MTA_AT_NVWRSECCTRL_SET_CNF       = 0x102D,
    /* Added by l00198894 for NVWR Security Control, 2015-04-04, end */

    /* ���һ����Ϣ */
    ID_AT_MTA_MSG_TYPE_BUTT

};
typedef VOS_UINT32 AT_MTA_MSG_TYPE_ENUM_UINT32;

/*****************************************************************************
 ö����    : MTA_AT_RESULT_ENUM
 �ṹ˵��  : MTA��AT�ظ��Ľ����ö��
1.��    ��  : 2012��06��28��
  ��    ��  : y00213812
  �޸�����  : V7R1C50 A_GPS��Ŀ�����ṹ
*****************************************************************************/
enum MTA_AT_RESULT_ENUM
{
    /* ��ATģ���Ӧ�ı�׼������ */
    MTA_AT_RESULT_NO_ERROR                      = 0x000000,                     /* ��Ϣ�������� */
    MTA_AT_RESULT_ERROR,                                                        /* ��Ϣ�������� */
    MTA_AT_RESULT_INCORRECT_PARAMETERS,
    MTA_AT_RESULT_OPTION_TIMEOUT,

    /* Ԥ����ӦAT��׼��������� */

    /* װ���������д����� */
    MTA_AT_RESULT_DEVICE_ERROR_BASE             = 0x100000,
    MTA_AT_RESULT_DEVICE_SEC_IDENTIFY_FAIL,                                     /* ���߼�Ȩʧ�� */
    MTA_AT_RESULT_DEVICE_SEC_SIGNATURE_FAIL,                                    /* ǩ��У��ʧ�� */
    MTA_AT_RESULT_DEVICE_SEC_DK_INCORRECT,                                      /* �˿�������� */
    MTA_AT_RESULT_DEVICE_SEC_UNLOCK_KEY_INCORRECT,                              /* ����������� */
    MTA_AT_RESULT_DEVICE_SEC_PH_PHYNUM_LEN_ERROR,                               /* �����ų��ȴ��� */
    MTA_AT_RESULT_DEVICE_SEC_PH_PHYNUM_VALUE_ERROR,                             /* ����������� */
    MTA_AT_RESULT_DEVICE_SEC_PH_PHYNUM_TYPE_ERROR,                              /* ���������ʹ��� */
    MTA_AT_RESULT_DEVICE_SEC_RSA_ENCRYPT_FAIL,                                  /* RSA����ʧ�� */
    MTA_AT_RESULT_DEVICE_SEC_RSA_DECRYPT_FAIL,                                  /* RSA����ʧ�� */
    MTA_AT_RESULT_DEVICE_SEC_GET_RAND_NUMBER_FAIL,                              /* ��ȡ�����ʧ��(crypto_rand) */
    MTA_AT_RESULT_DEVICE_SEC_WRITE_HUK_FAIL,                                    /* HUKд����� */
    MTA_AT_RESULT_DEVICE_SEC_FLASH_ERROR,                                       /* Flash���� */
    MTA_AT_RESULT_DEVICE_SEC_NV_ERROR,                                          /* NV��д���� */
    MTA_AT_RESULT_DEVICE_SEC_OTHER_ERROR,                                       /* �������� */


    /* ˽���������д����� */
    MTA_AT_RESULT_PRICMD_ERROR_BASE             = 0x200000,

    MTA_AT_RESULT_BUTT
};
typedef VOS_UINT32 MTA_AT_RESULT_ENUM_UINT32;

/*****************************************************************************
 ö����    : MTA_AT_CGPSCLOCK_ENUM
 �ṹ˵��  : RFоƬGPSʱ��״̬ö��
 1.��    ��   : 2012��06��25��
   ��    ��   : h44270
   �޸�����   : Added for AGPS
*****************************************************************************/
enum MTA_AT_CGPSCLOCK_ENUM
{
    MTA_AT_CGPSCLOCK_STOP           = 0,
    MTA_AT_CGPSCLOCK_START,
    MTA_AT_CGPSCLOCK_BUTT
};
typedef VOS_UINT32 MTA_AT_CGPSCLOCK_ENUM_UINT32;


/*****************************************************************************
 ö����    : MTA_AT_CPOS_OPERATE_TYPE_ENUM
 �ṹ˵��  : +CPOS XML���������������ö��
 1.��    ��   : 2012��06��25��
   ��    ��   : h44270
   �޸�����   : Added for AGPS
*****************************************************************************/
enum MTA_AT_CPOS_OPERATE_TYPE_ENUM
{
    MTA_AT_CPOS_SEND                = 0,
    MTA_AT_CPOS_CANCEL,
    MTA_AT_CPOS_BUTT
};
typedef VOS_UINT32 MTA_AT_CPOS_OPERATE_TYPE_ENUM_UINT32;

/* Added by l00198894 for STK&DCM Project, 2012/09/18, begin */
/*****************************************************************************
ö����    : AT_MTA_PERS_CATEGORY_ENUM
ö��˵��  : ����������Category����

  1.��    ��   : 2012��9��18��
    ��    ��   : l00198894
    �޸�����   : STK�������Լ�DCM���󿪷���Ŀ����ö��
*****************************************************************************/
enum AT_MTA_PERS_CATEGORY_ENUM
{
    AT_MTA_PERS_CATEGORY_NETWORK                    = 0x00,                     /* Category: ���� */
    AT_MTA_PERS_CATEGORY_NETWORK_SUBSET             = 0x01,                     /* Category: ������ */
    AT_MTA_PERS_CATEGORY_SERVICE_PROVIDER           = 0x02,                     /* Category: ��SP */
    AT_MTA_PERS_CATEGORY_CORPORATE                  = 0x03,                     /* Category: ������ */
    AT_MTA_PERS_CATEGORY_SIM_USIM                   = 0x04,                     /* Category: ��(U)SIM�� */

    AT_MTA_PERS_CATEGORY_BUTT
};
typedef VOS_UINT8 AT_MTA_PERS_CATEGORY_ENUM_UINT8;
/* Added by l00198894 for STK&DCM Project, 2012/09/18, end */

/* Added by s00217060 for �����ϱ�AT�������������C��, 2013-3-25, begin */
/*****************************************************************************
ö����    : AT_MTA_RPT_GENERAL_CTRL_TYPE_ENUM
ö��˵��  : �����ϱ���������

  1.��    ��   : 2013��3��25��
    ��    ��   : s00217060
    �޸�����   : ����ö��
*****************************************************************************/
enum AT_MTA_RPT_GENERAL_CTRL_TYPE_ENUM
{
    AT_MTA_RPT_GENERAL_CONTROL_NO_REPORT      = 0x00,                           /* ��ֹ���е������ϱ� */
    AT_MTA_RPT_GENERAL_CONTROL_REPORT         = 0x01,                           /* �����е������ϱ� */
    AT_MTA_RPT_GENERAL_CONTROL_CUSTOM         = 0x02,                           /* ��BITλ���ƶ�Ӧ����������ϱ� */

    AT_MTA_RPT_GENERAL_CONTROL_BUTT
};
typedef VOS_UINT8 AT_MTA_RPT_GENERAL_CTRL_TYPE_ENUM_UINT8;

/*****************************************************************************
ö����    : AT_MTA_RPT_SET_TYPE_ENUM
ö��˵��  : �����ϱ���������

  1.��    ��   : 2013��3��25��
    ��    ��   : s00217060
    �޸�����   : ����ö��
*****************************************************************************/
enum AT_MTA_RPT_SET_TYPE_ENUM
{
    AT_MTA_SET_MODE_RPT_TYPE            = 0,                                 /* Category: ����ģʽ�仯�Ƿ������ϱ� */
    AT_MTA_SET_SRVST_RPT_TYPE,
    AT_MTA_SET_RSSI_RPT_TYPE,
    AT_MTA_SET_TIME_RPT_TYPE,
    AT_MTA_SET_CTZR_RPT_TYPE,
    AT_MTA_SET_DSFLOWRPT_RPT_TYPE,
    AT_MTA_SET_SIMST_RPT_TYPE,
    AT_MTA_SET_CREG_RPT_TYPE,
    AT_MTA_SET_CGREG_RPT_TYPE,
    AT_MTA_SET_CEREG_RPT_TYPE,
    AT_MTA_SET_RPT_TYPE_BUTT
};
typedef VOS_UINT32 AT_MTA_RPT_SET_TYPE_ENUM_UINT32;

/*****************************************************************************
ö����    : AT_MTA_RPT_QRY_TYPE_ENUM
ö��˵��  : �����ϱ���������

  1.��    ��   : 2013��4��10��
    ��    ��   : l00167671
    �޸�����   : ����ö��
*****************************************************************************/
enum AT_MTA_RPT_QRY_TYPE_ENUM
{
    AT_MTA_QRY_TIME_RPT_TYPE = 0,
    AT_MTA_QRY_CTZR_RPT_TYPE,
    AT_MTA_QRY_CSSN_RPT_TYPE,
    AT_MTA_QRY_CUSD_RPT_TYPE,
    AT_MTA_QRY_RPT_TYPE_BUTT
};
typedef VOS_UINT32 AT_MTA_RPT_QRY_TYPE_ENUM_UINT32;

/* Added by s00217060 for �����ϱ�AT�������������C��, 2013-3-25, end */

/* Added by l00198894 for V9R1 AGPS, 2013/07/22, begin */
/*****************************************************************************
 ö����    : AT_MTA_CMD_RPT_FLG_ENUM
 �ṹ˵��  : AT�����ϱ����ر�־ö��

  1.��    ��   : 2013��07��22��
    ��    ��   : l00198894
    �޸�����   : V9R1 AGPS
*****************************************************************************/
enum AT_MTA_CMD_RPT_FLG_ENUM
{
    AT_MTA_CMD_RPT_FLG_OFF              = 0,                        /* AT��������ϱ� */
    AT_MTA_CMD_RPT_FLG_ON,                                          /* AT���������ϱ� */
    AT_MTA_CMD_RPT_FLG_BUTT
};
typedef VOS_UINT8 AT_MTA_CMD_RPT_FLG_ENUM_UINT8;
/* Added by l00198894 for V9R1 AGPS, 2013/07/22, end */

/*****************************************************************************
 ö����    : AT_MTA_CMD_RATMODE_ENUM
 �ṹ˵��  : AT���������ģʽRatModeö��

  1.��    ��   : 2014��04��8��
    ��    ��   : g00261581
    �޸�����   : �½�
*****************************************************************************/
enum AT_MTA_CMD_RATMODE_ENUM
{
    AT_MTA_CMD_RATMODE_GSM              = 0,
    AT_MTA_CMD_RATMODE_WCDMA,
    AT_MTA_CMD_RATMODE_LTE,
    AT_MTA_CMD_RATMODE_TD,
    /* Add by j00174725 for TAS2.5, 2014-12-03, Begin */
    AT_MTA_CMD_RATMODE_CDMA,
    /* Add by j00174725 for TAS2.5, 2014-12-03, Begin */
    AT_MTA_CMD_RATMODE_BUTT
};
typedef VOS_UINT8 AT_MTA_CMD_RATMODE_ENUM_UINT8;

/*****************************************************************************
 ö����    : MTA_AT_JAM_RESULT_ENUM
 �ṹ˵��  : JAM DETECT REPORT�ϱ����ö��

  1.��    ��   : 2014��05��5��
    ��    ��   : g00261581
    �޸�����   : �½�
*****************************************************************************/
enum MTA_AT_JAM_RESULT_ENUM
{
    MTA_AT_JAM_RESULT_JAM_DISAPPEARED        = 0x00,                            /* ״̬�����޸��� */
    MTA_AT_JAM_RESULT_JAM_DISCOVERED,                                           /* ���Ŵ��� */

    MTA_AT_JAM_RESULT_BUTT
};
typedef VOS_UINT32 MTA_AT_JAM_RESULT_ENUM_UINT32;

/* Added by g00261581 for V7R11 FREQ LOCK Project, 2014-06-11, begin */
/*****************************************************************************
 ö����    : AT_MTA_FREQLOCK_RATMODE_ENUM
 �ṹ˵��  : ATģ����MTA֮��Ľ���ģʽö��

  1.��    ��   : 2014��06��11��
    ��    ��   : g00261581
    �޸�����   : ����
*****************************************************************************/
enum AT_MTA_FREQLOCK_RATMODE_ENUM
{
    AT_MTA_FREQLOCK_RATMODE_GSM         = 0x01,
    AT_MTA_FREQLOCK_RATMODE_WCDMA,
    AT_MTA_FREQLOCK_RATMODE_LTE,
    AT_MTA_FREQLOCK_RATMODE_CDMA1X,
    AT_MTA_FREQLOCK_RATMODE_TD,
    AT_MTA_FREQLOCK_RATMODE_WIMAX,
    AT_MTA_FREQLOCK_RATMODE_EVDO,

    AT_MTA_FREQLOCK_RATMODE_BUTT
};
typedef VOS_UINT8 AT_MTA_FREQLOCK_RATMODE_ENUM_UINT8;

/*****************************************************************************
 ö����    : AT_MTA_GSM_BAND_ENUM
 �ṹ˵��  : ATģ����MTA֮���BANDֵö��

  1.��    ��   : 2014��06��11��
    ��    ��   : g00261581
    �޸�����   : ����
*****************************************************************************/
enum AT_MTA_GSM_BAND_ENUM
{
    AT_MTA_GSM_BAND_850                 = 0x00,
    AT_MTA_GSM_BAND_900,
    AT_MTA_GSM_BAND_1800,
    AT_MTA_GSM_BAND_1900,

    AT_MTA_GSM_BAND_BUTT
};
typedef VOS_UINT16 AT_MTA_GSM_BAND_ENUM_UINT16;
/* Added by g00261581 for V7R11 FREQ LOCK Project, 2014-06-11, end */


/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/
/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/
/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/
/*****************************************************************************
  7 STRUCT����
*****************************************************************************/

/*****************************************************************************
�ṹ��    : AT_MTA_MSG_STRU
�ṹ˵��  : ATģ����MTAģ������Ϣ�ṹ
1.��    ��  : 2012��06��28��
  ��    ��  : y00213812
  �޸�����  : V7R1C50 A_GPS��Ŀ�����ṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgId;                                /* ��Ϣ�� */
    AT_APPCTRL_STRU                     stAppCtrl;
    VOS_UINT8                           aucContent[4];                          /* ��Ϣ���� */
} AT_MTA_MSG_STRU;

/*****************************************************************************
�ṹ��    : MTA_AT_CPOS_REQ_MSG_STRU
�ṹ˵��  : ����AT��+CPOS������Ϣ�ӽṹ
1.��    ��  : 2012��06��28��
  ��    ��  : y00213812
  �޸�����  : V7R1C50 A_GPS��Ŀ�����ṹ
*****************************************************************************/
typedef struct
{
    MTA_AT_CPOS_OPERATE_TYPE_ENUM_UINT32    enCposOpType;
    VOS_UINT32                              ulXmlLength;
    VOS_CHAR                                acXmlText[MTA_CPOS_XML_MAX_LEN];
} AT_MTA_CPOS_REQ_STRU;

/*****************************************************************************
�ṹ��    : MTA_AT_CPOS_CNF_STRU
�ṹ˵��  : ����AT��+CPOS�ظ���Ϣ�ӽṹ
1.��    ��  : 2012��06��28��
  ��    ��  : y00213812
  �޸�����  : V7R1C50 A_GPS��Ŀ�����ṹ
*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;                               /* ����ִ�н�� */
} MTA_AT_CPOS_CNF_STRU;

/*****************************************************************************
�ṹ��    : MTA_AT_CPOSR_IND_STRU
�ṹ˵��  : +CPOSR�����ϱ�����Ϣ�ṹ
1.��    ��  : 2012��06��28��
  ��    ��  : y00213812
  �޸�����  : V7R1C50 A_GPS��Ŀ�����ṹ
*****************************************************************************/
typedef struct
{
    /* AT��MTA�ϱ���XML������󳤶�Ϊ1024��ͬʱ����Ԥ��һ���ֽڴ���ַ�����β�Ŀ��ַ� */
    VOS_CHAR                            acXmlText[MTA_CPOSR_XML_MAX_LEN + 1];
    VOS_UINT8                           aucRsv[3];
} MTA_AT_CPOSR_IND_STRU;

/*****************************************************************************
�ṹ��    : MTA_AT_XCPOSRRPT_IND_STRU
�ṹ˵��  : ^XCPOSRRPT�����ϱ�����Ϣ�ṹ
1.��    ��  : 2012��06��28��
  ��    ��  : y00213812
  �޸�����  : V7R1C50 A_GPS��Ŀ�����ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulClearFlg;
} MTA_AT_XCPOSRRPT_IND_STRU;

/*****************************************************************************
�ṹ��    : AT_MTA_CGPSCLOCK_REQ_STRU
�ṹ˵��  : AT^CGPSCLOCK�Ļظ���Ϣ�ṹ
1.��    ��  : 2012��06��28��
  ��    ��  : y00213812
  �޸�����  : V7R1C50 A_GPS��Ŀ�����ṹ
*****************************************************************************/
typedef struct
{
    MTA_AT_CGPSCLOCK_ENUM_UINT32        enGpsClockState;                        /* RFоƬGPSʱ��״̬ */
} AT_MTA_CGPSCLOCK_REQ_STRU;

/*****************************************************************************
�ṹ��    : MTA_AT_CGPSCLOCK_CNF_STRU
�ṹ˵��  : AT^CGPSCLOCK�Ļظ���Ϣ�ṹ
1.��    ��  : 2012��06��28��
  ��    ��  : y00213812
  �޸�����  : V7R1C50 A_GPS��Ŀ�����ṹ
*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;                               /* ����ִ�н�� */
} MTA_AT_CGPSCLOCK_CNF_STRU;

/* Added by l00198894 for V7R1C50 ISDB Project, 2012/08/28, begin */
/*****************************************************************************
�ṹ��    : AT_MTA_APSEC_REQ_STRU
�ṹ˵��  : AT^APSEC��������Ϣ�ṹ
1.��    ��  : 2012��08��28��
  ��    ��  : l00198894
  �޸�����  : ISDB ��ȫ�洢��Ŀ�����ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulSPLen;
    VOS_UINT8                           aucSecPacket[MTA_SEC_PACKET_MAX_LEN];
} AT_MTA_APSEC_REQ_STRU;

/*****************************************************************************
�ṹ��    : MTA_AT_APSEC_CNF_STRU
�ṹ˵��  : AT^APSEC�Ļظ���Ϣ�ṹ
1.��    ��  : 2012��08��28��
  ��    ��  : l00198894
  �޸�����  : ISDB ��ȫ�洢��Ŀ�����ṹ
*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;                               /* ����ִ�н�� */
    VOS_UINT32                          ulSPLen;
    VOS_UINT8                           aucSecPacket[MTA_SEC_PACKET_MAX_LEN];
} MTA_AT_APSEC_CNF_STRU;
/* Added by l00198894 for V7R1C50 ISDB Project, 2012/08/28, end */

/* Added by l00198894 for STK&DCM Project, 2012/09/18, begin */
/*****************************************************************************
�ṹ��    : AT_MTA_SIMLOCKUNLOCK_REQ_STRU
�ṹ˵��  : AT^SIMLOCKUNLOCK��������Ϣ�ṹ
1.��    ��  : 2012��09��18��
  ��    ��  : l00198894
  �޸�����  : STK�������Լ�DCM���󿪷���Ŀ�����ṹ
*****************************************************************************/
typedef struct
{
    AT_MTA_PERS_CATEGORY_ENUM_UINT8     enCategory;
    VOS_UINT8                           aucReserved[3];
    VOS_UINT8                           aucPassword[MTA_SIMLOCK_PASSWORD_LEN];
} AT_MTA_SIMLOCKUNLOCK_REQ_STRU;

/*****************************************************************************
�ṹ��    : MTA_AT_SIMLOCKUNLOCK_CNF_STRU
�ṹ˵��  : AT^SIMLOCKUNLOCK�Ļظ���Ϣ�ṹ
1.��    ��  : 2012��09��18��
  ��    ��  : l00198894
  �޸�����  : STK�������Լ�DCM���󿪷���Ŀ�����ṹ
*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;                               /* ����ִ�н�� */
} MTA_AT_SIMLOCKUNLOCK_CNF_STRU;
/* Added by l00198894 for STK&DCM Project, 2012/09/18, end */


/* Modified by z00161729 for cerssi, 2012-11-21, begin */
/*****************************************************************************
 �ṹ��    : AT_MTA_QRY_NMR_REQ_STRU
 �ṹ˵��  : AT��ȡNMR����Ϣ����ṹ

  1.��    ��   : 2012��11��23��
    ��    ��   : z00161729
    �޸�����   : NMR�����ṹ

*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucRatType;
    VOS_UINT8                           aucReserve[3];                          /* Ԥ������ʹ�� */
}AT_MTA_QRY_NMR_REQ_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_QRY_NMR_CNF_STRU
 �ṹ˵��  : mta�ظ�atģ��nmr��ѯ����ӿڽṹ

  1.��    ��   : 2012��11��23��
    ��    ��   : z00161729
    �޸�����   : NMR�����ṹ

*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32         enResult;
    VOS_UINT8                         ucTotalIndex;
    VOS_UINT8                         ucCurrIndex;
    VOS_UINT16                        usNMRLen;                                 /* NMR���ݳ��� */
    VOS_UINT8                         aucNMRData[4];                            /* NMR�����׵�ַ */
}MTA_AT_QRY_NMR_CNF_STRU;


/* Modified by z00161729 for cerssi, 2012-11-21, end */

/* Added by t00212959 for WLTHRESHOLDCFG, 2012-12-10, begin */
/*****************************************************************************
 �ṹ��    : AT_MTA_RESEL_OFFSET_CFG_SET_REQ_STRU
 �ṹ˵��  : AT��MTA����WLTHRESHOLDCFG����ѡ����
  1.��    ��   : 2012��12��10��
    ��    ��   : t00212959
    �޸�����   : WLTHRESHOLDCFG�����ṹ

*****************************************************************************/
typedef struct
{
    VOS_UINT8                                   ucOffsetFlg;                    /* 0:������1:����*/
    VOS_UINT8                                   aucReserve[3];                  /* Ԥ������ʹ�� */
}AT_MTA_RESEL_OFFSET_CFG_SET_NTF_STRU;
/* Added by t00212959 for WLTHRESHOLDCFG, 2012-12-10, end */

/* Added by m00217266 for DSDA GUNAS C CORE, 2012-12-26, begin */
/*****************************************************************************
 �ṹ��    : AT_MTA_WRR_AUTOTEST_QRY_PARA_STRU
 �ṹ˵��  : AS�����������

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucCmd;
    VOS_UINT8                           ucParaNum;
    VOS_UINT16                          usReserve;
    VOS_UINT32                          aulPara[AT_MTA_WRR_AUTOTEST_MAX_PARA_NUM];
}AT_MTA_WRR_AUTOTEST_QRY_PARA_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_WRR_AUTOTEST_QRY_RSLT_STRU
 �ṹ˵��  : WAS��������ؽ��

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulRsltNum;
    VOS_UINT32                          aulRslt[MTA_AT_WRR_AUTOTEST_MAX_RSULT_NUM];
}MTA_AT_WRR_AUTOTEST_QRY_RSLT_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_WRR_AUTOTEST_QRY_CNF_STRU
 �ṹ˵��  : WAS��������ؽ����Ϣ�ṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulResult;
    MTA_AT_WRR_AUTOTEST_QRY_RSLT_STRU   stWrrAutoTestRslt;
} MTA_AT_WRR_AUTOTEST_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_WRR_CELLINFO_STRU
 �ṹ˵��  : С����Ϣ�ṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT16                      usCellFreq;
    VOS_UINT16                      usPrimaryScramCode;
    VOS_INT16                       sCpichRscp;
    VOS_INT16                       sCpichEcN0;

}MTA_AT_WRR_CELLINFO_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_WRR_CELLINFO_RSLT_STRU
 �ṹ˵��  : WRR�ظ�MTAС����Ϣ��ѯ�ṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
     VOS_UINT32                     ulCellNum;
     MTA_AT_WRR_CELLINFO_STRU       astWCellInfo[MTA_AT_WRR_MAX_NCELL_NUM];         /*���֧��W 8�������Ĳ�ѯ*/

} MTA_AT_WRR_CELLINFO_RSLT_STRU;
/*****************************************************************************
 �ṹ��    : MTA_AT_WRR_CELLINFO_QRY_CNF_STRU
 �ṹ˵��  : WRR�ظ�MTAС����Ϣ��ѯ�ṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulResult;
    MTA_AT_WRR_CELLINFO_RSLT_STRU       stWrrCellInfo;
} MTA_AT_WRR_CELLINFO_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_WRR_MEANRPT_STRU
 �ṹ˵��  : ���������е��¼�+С��

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT16                      usEventId;                                  /*��Ӧ���¼�����*/
    VOS_UINT16                      usCellNum;
    VOS_UINT16                      ausPrimaryScramCode[MTA_AT_WRR_ONE_MEANRPT_MAX_CELL_NUM];
}MTA_AT_WRR_MEANRPT_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_WRR_MEANRPT_RSLT_STRU
 �ṹ˵��  : �Զ�������AT^MEANRPT,
             ��ѯ������10�β��������е��¼�+С��

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                      ulRptNum;
    MTA_AT_WRR_MEANRPT_STRU         astMeanRptInfo[MTA_AT_WRR_MAX_MEANRPT_NUM];
}MTA_AT_WRR_MEANRPT_RSLT_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_WRR_MEANRPT_QRY_CNF_STRU
 �ṹ˵��  : WRR��MTA�ظ�^MEANRPT�������Ϣ�ṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulResult;
    MTA_AT_WRR_MEANRPT_RSLT_STRU        stMeanRptRslt;
} MTA_AT_WRR_MEANRPT_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_WRR_FREQLOCK_CTRL_STRU
 �ṹ˵��  : WAS��Ƶ���ƽṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucFreqLockEnable;
    VOS_UINT8                           aucReserved[1];
    VOS_UINT16                          usLockedFreq;
} MTA_AT_WRR_FREQLOCK_CTRL_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_WRR_FREQLOCK_SET_CNF_STRU
 �ṹ˵��  : MTA��AT�ص���Ƶ���ƽṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulResult;
} MTA_AT_WRR_FREQLOCK_SET_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_WRR_FREQLOCK_QRY_CNF_STRU
 �ṹ˵��  : MTA��AT�ص���Ƶ���ƽṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulResult;
    MTA_AT_WRR_FREQLOCK_CTRL_STRU       stFreqLockInfo;
} MTA_AT_WRR_FREQLOCK_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_WRR_RRC_VERSION_SET_CNF_STRU
 �ṹ˵��  : WRR��MTA�ϱ�version���ý��

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulResult;
} MTA_AT_WRR_RRC_VERSION_SET_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_WRR_RRC_VERSION_QRY_CNF_STRU
 �ṹ˵��  : WRR��MTA�ϱ�version��ѯ���

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulResult;
    VOS_UINT8                           ucRrcVersion;
    VOS_UINT8                           aucReserved[3];
} MTA_AT_WRR_RRC_VERSION_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_WRR_CELLSRH_SET_CNF_STRU
 �ṹ˵��  : WRR��MTA�ϱ�cellsrh���ý��

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulResult;
} MTA_AT_WRR_CELLSRH_SET_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_WRR_CELLSRH_QRY_CNF_STRU
 �ṹ˵��  : WRR��MTA�ϱ�cellsrh��ѯ���

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulResult;
    VOS_UINT8                           ucCellSearchType;
    VOS_UINT8                           aucReserve[3];
} MTA_AT_WRR_CELLSRH_QRY_CNF_STRU;
/* Added by m00217266 for DSDA GUNAS C CORE, 2012-12-26, end */

/* Added by z00214637 for Body Sar Project, 2013-03-11, begin */
/*****************************************************************************
 �ṹ��    : AT_MTA_BODY_SAR_SET_REQ_STRU
 �ṹ˵��  : AT��MTA����BODYSAR�������ò���
  1.��    ��   : 2013��03��11��
    ��    ��   : z00214637
    �޸�����   : ^BODYSARON�����ṹ
*****************************************************************************/
typedef struct
{
    MTA_BODY_SAR_STATE_ENUM_UINT16      enState;       /* Body SAR״̬ */
    VOS_UINT16                          usRsv;         /* ����λ */
    MTA_BODY_SAR_PARA_STRU              stBodySARPara; /* Body SAR�������޲��� */
}AT_MTA_BODY_SAR_SET_REQ_STRU;

/*******************************************************************************
 �ṹ��    : MTA_AT_RESULT_CNF_STRU
 �ṹ˵��  : AT������Ϣ��������Ļظ���Ϣ�ṹ��
 1.��    ��   : 2013��03��11��
   ��    ��   : z00214637
   �޸�����   : �����ṹ��
*******************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;      /* ������� */
}MTA_AT_RESULT_CNF_STRU;
/* Added by z00214637 for Body Sar Project, 2013-03-11, end */

/*******************************************************************************
 �ṹ��    : AT_MTA_RESERVE_STRU
 �ṹ˵��  : AT��MTA��Ϣ�����ṹ��
 1.��    ��   : 2013��03��11��
   ��    ��   : z00214637
   �޸�����   : �����ṹ��
*******************************************************************************/
typedef struct
{
    VOS_UINT8                           aucReserved[4]; /* ����λ */
}AT_MTA_RESERVE_STRU;

/* Added by s00217060 for �����ϱ�AT�������������C��, 2013-3-25, begin */
/*****************************************************************************
 �ṹ��    : AT_MTA_CSSN_RPT_FLG_STRU
 �ṹ˵��  : CSSN�Ƿ������ϱ���ʶ�ṹ�壬����CSSI�Ƿ������ϱ���CSSU�Ƿ������ϱ�

  1.��    ��   : 2013��3��25��
    ��    ��   : s00217060
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucCssiRptFlg;                           /* ��ֹ��ʹ��+CSSI�Ĳ���ҵ��֪ͨ 0:���ϱ�;1:�ϱ� */
    VOS_UINT8                           ucCssuRptFlg;                           /* ��ֹ��ʹ��+CSSU�Ĳ���ҵ��֪ͨ 0:���ϱ�;1:�ϱ� */
} AT_MTA_CSSN_RPT_FLG_STRU;

/*****************************************************************************
 �ṹ��    : AT_MTA_CURC_SET_NOTIFY_STRU
 �ṹ˵��  : AT��MTA��������CURC����

  1.��    ��   : 2013��3��25��
    ��    ��   : s00217060
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    AT_MTA_RPT_GENERAL_CTRL_TYPE_ENUM_UINT8     enCurcRptType;                  /* �����ϱ�ģʽ��0:�ر����е������ϱ���1:�����е������ϱ���2:����RptCfg����������Ӧ��bitλ�Ƿ������ϱ� */
    VOS_UINT8                                   aucReserve[3];                  /* �����ֶ� */
    VOS_UINT8                                   aucRptCfg[AT_MTA_RPT_CFG_MAX_SIZE];                   /* 64bit�����ϱ���ʶ */
} AT_MTA_CURC_SET_NOTIFY_STRU;

/*****************************************************************************
 �ṹ��    : AT_MTA_CURC_QRY_REQ_STRU
 �ṹ˵��  : AT��MTA���Ͳ�ѯCURC����

  1.��    ��   : 2013��3��25��
    ��    ��   : s00217060
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           aucReserve[4];
} AT_MTA_CURC_QRY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : AT_MTA_UNSOLICITED_RPT_SET_REQ_STRU
 �ṹ˵��  : AT��MTA���͵����������������ϱ�����

  1.��    ��   : 2013��3��25��
    ��    ��   : s00217060
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    AT_MTA_RPT_SET_TYPE_ENUM_UINT32     enReqType;                              /* �������� */

    union
    {
        VOS_UINT8                       ucModeRptFlg;                           /* mode�Ƿ������ϱ���ʶ 0:���ϱ���1:�ϱ� */
        VOS_UINT8                       ucSrvstRptFlg;                          /* service status�Ƿ������ϱ���ʶ */
        VOS_UINT8                       ucRssiRptFlg;                           /* rssi�Ƿ������ϱ���ʶ */
        VOS_UINT8                       ucTimeRptFlg;                           /* time�Ƿ������ϱ���ʶ */
        VOS_UINT8                       ucCtzrRptFlg;                           /* ctzr�Ƿ������ϱ���ʶ */
        VOS_UINT8                       ucDsFlowRptFlg;                         /* �����Ƿ������ϱ���ʶ */
        VOS_UINT8                       ucSimstRptFlg;                          /* sim��״̬�Ƿ������ϱ���ʶ */
        VOS_UINT8                       ucCregRptFlg;                           /* cs��ע��״̬�Ƿ������ϱ���ʶ */
        VOS_UINT8                       ucCgregRptFlg;                          /* ps��ע��״̬�Ƿ������ϱ���ʶ */
        VOS_UINT8                       ucCeregRptFlg;                          /* Lע��״̬�Ƿ������ϱ���ʶ */
    }u;

    VOS_UINT8                           aucReserve[3];

 } AT_MTA_UNSOLICITED_RPT_SET_REQ_STRU;

/*****************************************************************************
 �ṹ��    : AT_MTA_UNSOLICITED_RPT_QRY_REQ_STRU
 �ṹ˵��  : AT��MTA���Ͳ�ѯ�������������ϱ�����

  1.��    ��   : 2013��3��25��
    ��    ��   : s00217060
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    AT_MTA_RPT_QRY_TYPE_ENUM_UINT32     enReqType;
} AT_MTA_UNSOLICITED_RPT_QRY_REQ_STRU;

/* Added by s00217060 for V9R1_SVLTE, 2013-6-5, begin */
/*****************************************************************************
 �ṹ��    : AT_MTA_NCELL_MONITOR_SET_REQ_STRU
 �ṹ˵��  : AT��MTA����NCELLMONITOR��������

  1.��    ��   : 2013��3��25��
    ��    ��   : s00217060
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucSwitch;
    VOS_UINT8                           aucReserve[3];
} AT_MTA_NCELL_MONITOR_SET_REQ_STRU;

/* Added by s00217060 for V9R1_SVLTE, 2013-6-5, end */

/*****************************************************************************
 �ṹ��    : MTA_AT_CURC_QRY_CNF_STRU
 �ṹ˵��  : MTA��AT���Ͳ�ѯCURC�ظ�

  1.��    ��   : 2013��3��25��
    ��    ��   : s00217060
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32                   enResult;
    AT_MTA_RPT_GENERAL_CTRL_TYPE_ENUM_UINT8     enCurcRptType;                          /* �����ϱ�ģʽ��0:�ر����е������ϱ���1:�����е������ϱ���2:����ReportCfg����������Ӧ��bitλ�Ƿ������ϱ� */
    VOS_UINT8                                   aucReserve[3];
    VOS_UINT8                                   aucRptCfg[AT_MTA_RPT_CFG_MAX_SIZE];  /* �����ϱ���ʶ */
} MTA_AT_CURC_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_UNSOLICITED_RPT_SET_CNF_STRU
 �ṹ˵��  : MTA��AT���͵����������������ϱ��ظ�

  1.��    ��   : 2013��3��25��
    ��    ��   : s00217060
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;
} MTA_AT_UNSOLICITED_RPT_SET_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_UNSOLICITED_RPT_QRY_CNF_STRU
 �ṹ˵��  : MTA��AT���Ͳ�ѯ�������������ϱ��ظ�

  1.��    ��   : 2013��3��25��
    ��    ��   : s00217060
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;
    AT_MTA_RPT_QRY_TYPE_ENUM_UINT32     enReqType;

    union
    {
        VOS_UINT8                       ucTimeRptFlg;                           /* time�Ƿ������ϱ���ʶ */
        VOS_UINT8                       ucCtzvRptFlg;                           /* ctzr�Ƿ������ϱ���ʶ */
        AT_MTA_CSSN_RPT_FLG_STRU        stCssnRptFlg;                           /* cssn�Ƿ������ϱ���ʶ�ṹ�� */
        VOS_UINT8                       ucCusdRptFlg;                           /* cusd�Ƿ������ϱ���ʶ�ṹ�� */
    }u;

    VOS_UINT8                           aucReserve[2];
} MTA_AT_UNSOLICITED_RPT_QRY_CNF_STRU;

/* Added by s00217060 for �����ϱ�AT�������������C��, 2013-3-25, end */


/* Added by Y00213812 for IMEI_VERIFY Project, 2013-05-23, begin */
/*******************************************************************************
 �ṹ��    : MTA_AT_CGSN_QRY_CNF_STRU
 �ṹ˵��  : ID_MTA_AT_CGSN_QRY_CNF��Ϣ
 1.��    ��   : 2013��05��25��
   ��    ��   : Y00213812
   �޸�����   : �����ṹ��
*******************************************************************************/
typedef struct
{
    VOS_UINT8                           aucImei[NV_ITEM_IMEI_SIZE]; /* IMEI���� */
}MTA_AT_CGSN_QRY_CNF_STRU;
/* Added by Y00213812 for IMEI_VERIFY Project, 2013-05-23, end */
/* Added by s00217060 for V9R1_SVLTE, 2013-6-4, begin */
/*****************************************************************************
 �ṹ��    : MTA_AT_NCELL_MONITOR_QRY_CNF_STRU
 �ṹ˵��  : MTA����AT�Ĳ�ѯ��ϵͳС���仯��Ϣ����������Ϣ�Ļظ�

  1.��    ��   : 2013��5��31��
    ��    ��   : s00217060
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;
    VOS_UINT8                           ucSwitch;
    VOS_UINT8                           ucNcellState;
    VOS_UINT8                           aucReserved[2];
} MTA_AT_NCELL_MONITOR_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_NCELL_MONITOR_IND_STRU
 �ṹ˵��  : MTA����AT����ϵͳС���仯�����ϱ���Ϣ

  1.��    ��   : 2013��5��31��
    ��    ��   : s00217060
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucNcellState;
    VOS_UINT8                           aucReserved[3];
} MTA_AT_NCELL_MONITOR_IND_STRU;

/* Added by s00217060 for V9R1_SVLTE, 2013-6-4, end */

/* Added by l00198894 for V9R1 AGPS, 2013/07/22, begin */
/*****************************************************************************
�ṹ��    : AT_MTA_REFCLKFREQ_SET_REQ_STRU
�ṹ˵��  : AT^REFCLKFREQ���������������Ϣ�ṹ

1.��    ��   : 2013��07��22��
  ��    ��   : l00198894
  �޸�����   : V9R1 AGPS
*****************************************************************************/
typedef struct
{
    AT_MTA_CMD_RPT_FLG_ENUM_UINT8       enRptFlg;                               /* �����ϱ����ر�־ */
    VOS_UINT8                           aucReserved1[3];                        /* ����λ */
} AT_MTA_REFCLKFREQ_SET_REQ_STRU;

/*****************************************************************************
�ṹ��    : MTA_AT_REFCLKFREQ_QRY_CNF_STRU
�ṹ˵��  : AT^REFCLKFREQ��ѯ����Ļظ���Ϣ�ṹ

1.��    ��   : 2013��07��22��
  ��    ��   : l00198894
  �޸�����   : V9R1 AGPS
*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;
    VOS_UINT32                          ulFreq;                                 /* GPS�ο�ʱ�ӵ�Ƶ��ֵ����λHz */
    VOS_UINT32                          ulPrecision;                            /* ��ǰGPS�ο�ʱ�ӵľ��ȣ���λppb */
    PHY_MTA_REFCLOCK_STATUS_ENUM_UINT16 enStatus;                               /* ʱ��Ƶ������״̬ */
    VOS_UINT8                           aucReserved1[2];                        /* ����λ */
} MTA_AT_REFCLKFREQ_QRY_CNF_STRU;

/*****************************************************************************
�ṹ��    : MTA_AT_REFCLKFREQ_IND_STRU
�ṹ˵��  : GPS�ο�ʱ��״̬��Ϣ�����ϱ���Ϣ�ṹ

1.��    ��   : 2013��07��22��
  ��    ��   : l00198894
  �޸�����   : V9R1 AGPS
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulFreq;                                 /* GPS�ο�ʱ�ӵ�Ƶ��ֵ����λHz */
    VOS_UINT32                          ulPrecision;                            /* ��ǰGPS�ο�ʱ�ӵľ��ȣ���λppb */
    PHY_MTA_REFCLOCK_STATUS_ENUM_UINT16 enStatus;                               /* ʱ��Ƶ������״̬ */
    VOS_UINT8                           aucReserved1[2];                        /* ����λ */
} MTA_AT_REFCLKFREQ_IND_STRU;

/* Added by l00198894 for V9R1 AGPS, 2013/07/22, end */

/* Added by m00217266 for AP Sensor, 2013-08-07, begin */
/*****************************************************************************
�ṹ��    : MTA_AT_HANDLEDECT_SET_CNF_STRU
�ṹ˵��  : �����������������ֳ�״̬��Ϣcnf��Ϣ

1.��    ��   : 2013��08��08��
  ��    ��   : m00217266
  �޸�����   : AP Sensor
*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;                               /* ������� */
} MTA_AT_HANDLEDECT_SET_CNF_STRU;

/*****************************************************************************
�ṹ��    : MTA_AT_HANDLEDECT_QRY_CNF_STRU
�ṹ˵��  : ��ѯ�������������ֳ�״̬��Ϣcnf��Ϣ

1.��    ��   : 2013��08��08��
  ��    ��   : m00217266
  �޸�����   : AP Sensor
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usHandle;                               /* ���������� */
    VOS_UINT16                          aucReserved1[1];
    MTA_AT_RESULT_ENUM_UINT32           enResult;                               /* ������� */
} MTA_AT_HANDLEDECT_QRY_CNF_STRU;
/* Added by m00217266 for AP Sensor, 2013-08-07, End */

/* Added by l00198894 for SVLTE Offline Reselect Project, 2013/10/21, begin */
/*****************************************************************************
 �ṹ��    : MTA_AT_PS_TRANSFER_IND_STRU
 �ṹ˵��  : �ϱ�PS��Ǩ��ָʾ�ṹ��

  1.��    ��   : 2013��10��21��
    ��    ��   : l00198894
    �޸�����   : V9R1C50 SVLTE������ѡ��Ŀ����
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucCause;                                /* PS��Ǩ��ԭ��ֵ */
    VOS_UINT8                           aucReserved1[3];                        /* ����λ */
} MTA_AT_PS_TRANSFER_IND_STRU;
/* Added by l00198894 for SVLTE Offline Reselect Project, 2013/10/21, end */

/* Add by j00174725 for RF&LCD INTRUSION, 2014-03-04, Begin */
/*****************************************************************************
 �ṹ��    : MTA_AT_RF_LCD_MIPICLK_IND_STRU
 �ṹ˵��  : �ϱ�MIPICLK�ṹ��

  1.��    ��   : 2014��03��04��
    ��    ��   : j00174725
    �޸�����   : RF&LCD INTRUSION��Ŀ����
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usMipiClk;                              /* �����ϱ�MIPICLKֵ */
    VOS_UINT8                           aucReserved1[2];                        /* ����λ */
} MTA_AT_RF_LCD_MIPICLK_IND_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_RF_LCD_MIPICLK_CNF_STRU
 �ṹ˵��  : �ϱ�MIPICLK�ṹ��

  1.��    ��   : 2014��03��04��
    ��    ��   : j00174725
    �޸�����   : RF&LCD INTRUSION��Ŀ����
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usMipiClk;                              /* �����ϱ�MIPICLKֵ */
    VOS_UINT16                          usResult;
} MTA_AT_RF_LCD_MIPICLK_CNF_STRU;
/* Add by j00174725 for RF&LCD INTRUSION, 2014-03-04, End */

/* Added by l00198894 for ����+ECID����, 2013-12-09, begin */
/*******************************************************************************
 �ṹ��    : AT_MTA_ECID_SET_REQ_STRU
 �ṹ˵��  : AT��MTA����+ECID����������Ϣ�ṹ��

  1.��    ��   : 2013��12��10��
    ��    ��   : l00198894
    �޸�����   : �����ṹ��
*******************************************************************************/
typedef struct
{
    VOS_UINT32                          ulVersion;                              /* ����汾�� */
}AT_MTA_ECID_SET_REQ_STRU;

/*******************************************************************************
 �ṹ��    : MTA_AT_ECID_SET_CNF_STRU
 �ṹ˵��  : AT��MTA����+ECID���ûظ���Ϣ�ṹ��

  1.��    ��   : 2013��12��10��
    ��    ��   : l00198894
    �޸�����   : �����ṹ��
*******************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;
    VOS_UINT8                           aucCellInfoStr[4];                      /* ��ǿ��С����Ϣ�ַ��� */
}MTA_AT_ECID_SET_CNF_STRU;
/* Added by l00198894 for ����+ECID����, 2013-12-09, end */

/*added by y00176023 for DSDS II,2014-03-25,begin*/
/*****************************************************************************
 �ṹ��    : AT_MTA_RRC_PROTECT_PS_REQ_STRU
 �ṹ˵��  : AT��ȡPSPROTECTMODE����Ϣ����ṹ

  1.��    ��   : 2014��3��25��
    ��    ��   : y00176023
    �޸�����   : PSPROTECTMODE�����ṹ

*****************************************************************************/
typedef struct
{
    PS_BOOL_ENUM_UINT8                  enPsProtectFlg;
    VOS_UINT8                           aucReserve[3];                          /* Ԥ������ʹ�� */
}AT_MTA_RRC_PROTECT_PS_REQ_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_RRC_PROTECT_PS_CNF_STRU
 �ṹ˵��  : AT��ȡPSPROTECTMODE����Ϣ����ṹ

  1.��    ��   : 2014��3��25��
    ��    ��   : y00176023
    �޸�����   : PSPROTECTMODE�����ṹ

*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;                          /* ���ظ�AT�Ľ�� */
}MTA_AT_RRC_PROTECT_PS_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_PHY_INIT_CNF_STRU
 �ṹ˵��  : AT��ȡPHYINIT����Ϣ����ṹ

  1.��    ��   : 2014��3��25��
    ��    ��   : y00176023
    �޸�����   : PHYINIT�����ṹ

*****************************************************************************/
typedef struct
{
    VOS_UINT8                           aucReserve[4];                          /* Ԥ������ʹ�� */
}AT_MTA_PHY_INIT_REQ_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_PHY_INIT_CNF_STRU
 �ṹ˵��  : AT�����������ʼ��������ظ�����Ϣ�ṹ

  1.��    ��   : 2014��3��26��
    ��    ��   : y00176023
    �޸�����   : PHYINIT�����ṹ
*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;                          /* ���ظ�AT�Ľ�� */
}MTA_AT_PHY_INIT_CNF_STRU;
/*added by y00176023 for DSDS II,2014-03-25,end*/


/*****************************************************************************
 �ṹ��    : AT_MTA_SET_DPDTTEST_FLAG_REQ_STRU
 �ṹ˵��  : AT����MTA������DPDT TEST FLAG����Ϣ�ṹ

  1.��    ��   : 2014��4��04��
    ��    ��   : g00261581
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    AT_MTA_CMD_RATMODE_ENUM_UINT8       enRatMode;
    VOS_UINT8                           ucFlag;
    VOS_UINT8                           aucReserved[2];
} AT_MTA_SET_DPDTTEST_FLAG_REQ_STRU;

/*****************************************************************************
 �ṹ��    : AT_MTA_SET_DPDT_VALUE_REQ_STRU
 �ṹ˵��  : AT����MTA������DPDT��ǰ����ʹ��״̬����Ϣ�ṹ

  1.��    ��   : 2014��4��04��
    ��    ��   : g00261581
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    AT_MTA_CMD_RATMODE_ENUM_UINT8       enRatMode;
    VOS_UINT8                           aucReserved[3];
    VOS_UINT32                          ulDpdtValue;
} AT_MTA_SET_DPDT_VALUE_REQ_STRU;

/*****************************************************************************
 �ṹ��    : AT_MTA_QRY_DPDT_VALUE_PARA_STRU
 �ṹ˵��  : AT����MTA�Ĳ�ѯDPDT VAlUE����Ϣ�ṹ

  1.��    ��   : 2014��4��04��
    ��    ��   : g00261581
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    AT_MTA_CMD_RATMODE_ENUM_UINT8       enRatMode;
    VOS_UINT8                           aucReserved[3];
} AT_MTA_QRY_DPDT_VALUE_REQ_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_SET_DPDTTEST_FLAG_CNF_STRU
 �ṹ˵��  : MTA����AT������DPDTTEST Flag���ػظ���Ϣ�ṹ

  1.��    ��   : 2014��4��04��
    ��    ��   : g00261581
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;
} MTA_AT_SET_DPDTTEST_FLAG_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_SET_DPDT_VALUE_CNF_STRU
 �ṹ˵��  : MTA����AT������DPDT Value�ظ���Ϣ�ṹ

  1.��    ��   : 2014��4��04��
    ��    ��   : g00261581
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;
} MTA_AT_SET_DPDT_VALUE_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_QRY_DPDT_VALUE_CNF_STRU
 �ṹ˵��  : MTA����AT�Ļظ���ѯDPDT VAlUE����Ϣ�ṹ

  1.��    ��   : 2014��4��04��
    ��    ��   : g00261581
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulDpdtValue;
    MTA_AT_RESULT_ENUM_UINT32           enResult;
} MTA_AT_QRY_DPDT_VALUE_CNF_STRU;

/* Added by g00261581 for V3R3 JAM DETECT Project, 2014-05-04, begin */
/*****************************************************************************
 �ṹ��    : AT_MTA_SET_JAM_DETECT_REQ_STRU
 �ṹ˵��  : AT����MTA������Jamming Dectection Report����Ϣ�ṹ

  1.��    ��   : 2014��5��04��
    ��    ��   : g00261581
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucFlag;
    VOS_UINT8                           ucMethod;
    VOS_UINT8                           ucThreshold;
    VOS_UINT8                           ucFreqNum;
} AT_MTA_SET_JAM_DETECT_REQ_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_SET_JAM_DETECT_CNF_STRU
 �ṹ˵��  : MTA����AT������Jamming Dectection Report��Cnf��Ϣ�ṹ

  1.��    ��   : 2014��5��04��
    ��    ��   : g00261581
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;
} MTA_AT_SET_JAM_DETECT_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_JAM_DETECT_IND_STRU
 �ṹ˵��  : MTA����AT��Jamming Dectection Report��Ind�ϱ���Ϣ�ṹ

  1.��    ��   : 2014��5��04��
    ��    ��   : g00261581
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MTA_AT_JAM_RESULT_ENUM_UINT32       enJamResult;
} MTA_AT_JAM_DETECT_IND_STRU;
/* Added by g00261581 for V3R3 JAM DETECT Project, 2014-05-04, end */

/* Added by g00261581 for V7R11 FREQ LOCK Project, 2014-06-11, begin */
/*****************************************************************************
 �ṹ��    : AT_MTA_SET_FREQ_LOCK_REQ_STRU
 �ṹ˵��  : AT����MTA��������Ƶ�������Ϣ�ṹ

  1.��    ��   : 2014��6��11��
    ��    ��   : g00261581
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucEnableFlg;                            /* 1:��Ƶ���ܴ򿪣�0:���ܹر� */
    AT_MTA_FREQLOCK_RATMODE_ENUM_UINT8  enRatMode;
    VOS_UINT16                          usLockedFreq;
    AT_MTA_GSM_BAND_ENUM_UINT16         enBand;
    VOS_UINT8                           aucReserved[2];
} AT_MTA_SET_FREQ_LOCK_REQ_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_SET_FREQ_LOCK_CNF_STRU
 �ṹ˵��  : MTA�ظ���AT������Ƶ�ظ��������Ϣ�ṹ

  1.��    ��   : 2014��6��11��
    ��    ��   : g00261581
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;
} MTA_AT_SET_FREQ_LOCK_CNF_STRU;
/* Added by g00261581 for V7R11 FREQ LOCK Project, 2014-06-11, end */

/* Added by j00174725 for GU ROAD TEST, 2014-08-05, Begin */
/*****************************************************************************
 �ṹ��    : AT_MTA_SET_GSM_FREQLOCK_REQ_STRU
 �ṹ˵��  : AT����MTA������Gģ��Ƶ�������Ϣ�ṹ

  1.��    ��   : 2014��08��05��
    ��    ��   : j00174725
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_BOOL_ENUM_UINT8                  enableFlag;                             /* PS_TRUE:������PS_FALSE:ȥ���� */
    VOS_UINT8                           aucReserved[3];                         /* ����λ */
    VOS_UINT16                          usFreq;                                 /* Ƶ��ֵ */
    AT_MTA_GSM_BAND_ENUM_UINT16         enBand;                                 /* GSMƵ�� */
} AT_MTA_SET_GSM_FREQLOCK_REQ_STRU;

/*****************************************************************************
 �ṹ��    : MTA_AT_SET_GSM_FREQLOCK_CNF_STRU
 �ṹ˵��  : MTA�ظ���AT����Gģ��Ƶ�ظ��������Ϣ�ṹ

  1.��    ��   : 2014��08��05��
    ��    ��   : j00174725
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MTA_AT_RESULT_ENUM_UINT32           enResult;
} MTA_AT_SET_GSM_FREQLOCK_CNF_STRU;
/* Added by j00174725 for GU ROAD TEST, 2014-08-05, End */

/* Added by m00217266 for Xpass reselect, 2014-12-25, begin */
/*****************************************************************************
 �ṹ��    : MTA_AT_XPASS_INFO_IND_STRU
 �ṹ˵��  : MTA�����ϱ���XPASS��Ϣ����Ϣ�ṹ

  1.��    ��   : 2014��12��25��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PHY_MTA_GPHY_XPASS_MODE_ENUM_UINT16           enGphyXpassMode;
    VOS_UINT16                                    usResev1;
    PHY_MTA_WPHY_HIGHWAY_MODE_ENUM_UINT16         enWphyXpassMode;
    VOS_UINT16                                    usResev2;
} MTA_AT_XPASS_INFO_IND_STRU;
/* Added by m00217266 for Xpass reselect, 2014-12-25, end */

/* Added by l00198894 for NVWR Security Control, 2015-04-04, begin */
/*****************************************************************************
 �ṹ��    : AT_MTA_NVWRSECCTRL_SET_REQ_STRU
 �ṹ˵��  : AT����MTA������NVWR���ȫ���Ƶ���Ϣ�ṹ

  1.��    ��   : 2015��04��04��
    ��    ��   : l00198894
    �޸�����   : �����ṹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucSecType;                              /* ��ȫ�������� */
    VOS_UINT8                           ucSecStrFlg;                            /* �Ƿ�Я����ȫУ������ */
    VOS_UINT8                           aucReserved[2];
    VOS_UINT8                           aucSecString[AT_RSA_CIPHERTEXT_LEN];    /* ��ȫУ������ */
} AT_MTA_NVWRSECCTRL_SET_REQ_STRU;
/* Added by l00198894 for NVWR Security Control, 2015-04-04, end */



/*****************************************************************************
  8 UNION����
*****************************************************************************/
/*****************************************************************************
  9 OTHERS����
*****************************************************************************/

/*****************************************************************************
  H2ASN������Ϣ�ṹ����
*****************************************************************************/
typedef struct
{
    AT_MTA_MSG_TYPE_ENUM_UINT32         ulMsgId;                                /*_H2ASN_MsgChoice_Export AT_MTA_MSG_TYPE_ENUM_UINT32*/
    AT_APPCTRL_STRU                     stAppCtrl;
    VOS_UINT8                           aucMsgBlock[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          AT_MTA_MSG_TYPE_ENUM_UINT32
    ****************************************************************************/
}AT_MTA_MSG_DATA;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    AT_MTA_MSG_DATA                     stMsgData;
}AtMtaInterface_MSG;

/*****************************************************************************
  10 ��������
*****************************************************************************/


#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
