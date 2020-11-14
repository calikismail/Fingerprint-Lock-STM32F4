#ifndef __USMART_H
#define __USMART_H
#include "usmart_str.h"
//////////////////////////////////////////////////////////////////////////////////
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
// ALIENTEK STM32������
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�汾��V3.1
//��Ȩ���У�����ؾ���
// Copyright(C) ����ԭ�� 2011-2021
// All rights reserved
//********************************************************************************
//����˵��
// V1.4
//�����˶Բ���Ϊstring���͵ĺ�����֧��.���÷�Χ������.
//�Ż����ڴ�ռ��,��̬�ڴ�ռ��Ϊ79���ֽ�@10������.��̬��Ӧ���ּ��ַ�������
// V2.0
// 1,�޸���listָ��,��ӡ��������������ʽ.
// 2,������idָ��,��ӡÿ����������ڵ�ַ.
// 3,�޸��˲���ƥ��,֧�ֺ��������ĵ���(������ڵ�ַ).
// 4,�����˺��������Ⱥ궨��.
// V2.1 20110707
// 1,����dec,hex����ָ��,�������ò�����ʾ����,��ִ�н���ת��.
//ע:��dec,hex����������ʱ��,���趨��ʾ��������.�����������ʱ��,��ִ�н���ת��.
//��:"dec 0XFF" ��Ὣ0XFFתΪ255,�ɴ��ڷ���.
//��:"hex 100" 	��Ὣ100תΪ0X64,�ɴ��ڷ���
// 2,����usmart_get_cmdname����,���ڻ�ȡָ������.
// V2.2 20110726
// 1,������void���Ͳ����Ĳ���ͳ�ƴ���.
// 2,�޸�������ʾ��ʽĬ��Ϊ16����.
// V2.3 20110815
// 1,ȥ���˺�����������"("������.
// 2,�������ַ��������в�����"("��bug.
// 3,�޸��˺���Ĭ����ʾ������ʽ���޸ķ�ʽ.
// V2.4 20110905
// 1,�޸���usmart_get_cmdname����,������������������.����������������ʱ����������.
// 2,����USMART_ENTIM2_SCAN�궨��,���������Ƿ�ʹ��TIM2��ʱִ��scan����.
// V2.5 20110930
// 1,�޸�usmart_init����Ϊvoid usmart_init(u8
// sysclk),���Ը���ϵͳƵ���Զ��趨ɨ��ʱ��.(�̶�100ms)
// 2,ȥ����usmart_init�����е�uart_init����,���ڳ�ʼ���������ⲿ��ʼ��,�����û����й���.
// V2.6 20111009
// 1,������read_addr��write_addr��������.��������������������д�ڲ������ַ(��������Ч��ַ).���ӷ������.
// 2,read_addr��write_addr������������ͨ������USMART_USE_WRFUNSΪ��ʹ�ܺ͹ر�.
// 3,�޸���usmart_strcmp,ʹ��淶��.
// V2.7 20111024
// 1,�����˷���ֵ16������ʾʱ�����е�bug.
// 2,�����˺����Ƿ��з���ֵ���ж�,���û�з���ֵ,�򲻻���ʾ.�з���ֵʱ����ʾ�䷵��ֵ.
// V2.8 20111116
// 1,������list�Ȳ���������ָ��ͺ���ܵ���������bug.
// V2.9 20120917
// 1,�޸������磺void*xxx(void)���ͺ�������ʶ���bug��
// V3.0 20130425
// 1,�������ַ���������ת�����֧�֡�
// V3.1 20131120
// 1,����runtimeϵͳָ��,��������ͳ�ƺ���ִ��ʱ��.
//�÷�:
//����:runtime 1 ,��������ִ��ʱ��ͳ�ƹ���
//����:runtime 0 ,��رպ���ִ��ʱ��ͳ�ƹ���
/// runtimeͳ�ƹ���,��������:USMART_ENTIMX_SCAN Ϊ1,�ſ���ʹ��!!
/////////////////////////////////////////////////////////////////////////////////////
// USMART��Դռ�����@MDK 3.80A@2.0�汾��
// FLASH:4K~K�ֽ�(ͨ��USMART_USE_HELP��USMART_USE_WRFUNS����)
// SRAM:72�ֽ�(���ٵ������)
// SRAM���㹫ʽ:   SRAM=PARM_LEN+72-4  ����PARM_LEN������ڵ���4.
//Ӧ�ñ�֤��ջ��С��100���ֽ�.
////////////////////////////////////////////�û����ò���////////////////////////////////////////////////////
#define MAX_FNAME_LEN 30 //��������󳤶ȣ�Ӧ������Ϊ��С����������ĳ��ȡ�
#define MAX_PARM 10 //���Ϊ10������ ,�޸Ĵ˲���,�����޸�usmart_exe��֮��Ӧ.
#define PARM_LEN                                                               \
  200 //���в���֮�͵ĳ��Ȳ�����PARM_LEN���ֽ�,ע�⴮�ڽ��ղ���Ҫ��֮��Ӧ(��С��PARM_LEN)

#define USMART_ENTIMX_SCAN                                                     \
  1 //ʹ��TIM�Ķ�ʱ�ж���ɨ��SCAN����,�������Ϊ0,��Ҫ�Լ�ʵ�ָ�һ��ʱ��ɨ��һ��scan����.
    //ע��:���Ҫ��runtimeͳ�ƹ���,��������USMART_ENTIMX_SCANΪ1!!!!

#define USMART_USE_HELP                                                        \
  1 //ʹ�ð�������ֵ��Ϊ0�����Խ�ʡ��700���ֽڣ����ǽ������޷���ʾ������Ϣ��
#define USMART_USE_WRFUNS                                                      \
  1 //ʹ�ö�д����,ʹ������,���Զ�ȡ�κε�ַ��ֵ,������д�Ĵ�����ֵ.
///////////////////////////////////////////////END///////////////////////////////////////////////////////////

#define USMART_OK 0         //�޴���
#define USMART_FUNCERR 1    //��������
#define USMART_PARMERR 2    //��������
#define USMART_PARMOVER 3   //�������
#define USMART_NOFUNCFIND 4 //δ�ҵ�ƥ�亯��

#define SP_TYPE_DEC 0 // 10���Ʋ�����ʾ
#define SP_TYPE_HEX 1 // 16���Ʋ�����ʾ

//�������б�
struct _m_usmart_nametab {
  void *func;     //����ָ��
  const u8 *name; //������(���Ҵ�)
};
// usmart���ƹ�����
struct _m_usmart_dev {
  struct _m_usmart_nametab *funs; //������ָ��

  void (*init)(u8);       //��ʼ��
  u8 (*cmd_rec)(u8 *str); //ʶ������������
  void (*exe)(void);      //ִ��
  void (*scan)(void);     //ɨ��
  u8 fnum;                //��������
  u8 pnum;                //��������
  u8 id;                  //����id
  u8 sptype;    //������ʾ����(���ַ�������):0,10����;1,16����;
  u16 parmtype; //����������
  u8 plentbl[MAX_PARM]; //ÿ�������ĳ����ݴ��
  u8 parm[PARM_LEN];    //�����Ĳ���
  u8 runtimeflag; // 0,��ͳ�ƺ���ִ��ʱ��;1,ͳ�ƺ���ִ��ʱ��,ע��:�˹��ܱ�����USMART_ENTIMX_SCANʹ�ܵ�ʱ��,������
  u32 runtime; //����ʱ��,��λ:0.1ms,�����ʱʱ��Ϊ��ʱ��CNTֵ��2��*0.1ms
};
extern struct _m_usmart_nametab usmart_nametab[]; //��usmart_config.c���涨��
extern struct _m_usmart_dev usmart_dev; //��usmart_config.c���涨��

void usmart_init(u8 sysclk);        //��ʼ��
u8 usmart_cmd_rec(u8 *str);         //ʶ��
void usmart_exe(void);              //ִ��
void usmart_scan(void);             //ɨ��
u32 read_addr(u32 addr);            //��ȡָ����ַ��ֵ
void write_addr(u32 addr, u32 val); //��ָ����ַд��ָ����ֵ
u32 usmart_get_runtime(void);       //��ȡ����ʱ��
void usmart_reset_runtime(void);    //��λ����ʱ��

#endif