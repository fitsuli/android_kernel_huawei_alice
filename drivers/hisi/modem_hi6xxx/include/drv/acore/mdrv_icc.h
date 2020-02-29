#ifndef __MDRV_ACORE_ICC_H__
#define __MDRV_ACORE_ICC_H__
#ifdef __cplusplus
extern "C"
{
#endif

#include "mdrv_public.h"
/* will implement at moment of unified icc project */
//#include "mdrv_icc_common.h"

/************************************************************************
 * �� �� ��  : mdrv_icc_register_resume_cb
 * ��������  : ע��ipf ����A��ʱ�Ĺ��Ӻ�����AP��˯��״̬�±�CP����
 * ���㶨λ�Ǳ�ʲô�¼����ѵ�
 * �������  :
 *            u32ChanId: icc channel id
 *            FUNCPTR_1: �ص�����
 *            param    : �ص���������
 * �������  : ��
 * �� �� ֵ  :  0          �����ɹ���
 *             ����        ����ʧ�ܡ�
 **************************************************************************/
void mdrv_icc_register_resume_cb(unsigned int u32ChanId, FUNCPTR_1 debug_routine, int param);

#ifdef __cplusplus
}
#endif
#endif
