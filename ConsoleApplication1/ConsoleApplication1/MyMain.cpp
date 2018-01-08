#include <Windows.h>
#include <stdio.h>
#include "MyMain.h"
#include "csp.h"

#pragma comment(lib,"GMNCSP.lib")

int main(){
	HCRYPTPROV phProv;
	BOOL bv = FALSE;
		 

	puts("CSP TEST.");
	//1 CPAcquireContext
	bv =  CPAcquireContext(
		//���ص�CSP��Կ�����ľ��
		&phProv,
		//ָ����Կ��������
		NULL,
		//�Ƿ񴴽�/ɾ������
		NULL,
		//�ص������б�
		NULL
		);
	 if (bv){
		 puts("CPAcquireContext SUCCESS.");
	 }

	//2 CPGetProvParam
	   CPGetProvParam(
		//ָ��CSP��Կ����
		NULL,
		//��ѯ��
		NULL,
		//��ֵ����
		NULL,
		//��ֵ����
		NULL,
		//ָ�����ؼ�ֵ��һЩ����
		NULL
		);

	//3 CPReleaseContext
	   CPReleaseContext(
		//�ͷ�CSP��Կ�������
		NULL,
		//flag
		NULL
		);

	//4 CPSetProvParam
	   CPSetProvParam(
		//ָ��CSP��Կ�������
		NULL,
		//���ò����ļ�
		NULL,
		//���ò����ļ�ֵ
		NULL,
		//ָ��һЩ��ֵ��صĲ���
		NULL
		);

	//5 CPDeriveKey
	   CPDeriveKey(
		//ָ��CSP��Կ�������
		NULL,
		//ָ��������Կ���㷨��ʶ
		NULL,
		//�������ݵ�HASHֵ���
		NULL,
		//ָ��session key��һЩ����
		NULL,
		//������Կ������
		NULL
		);

	//6 CPDestroyKey
	   CPDestroyKey(
		//ָ��CSP��Կ�������
		NULL,
		//ָ��������Կ������
		NULL
		);

	//7 CPExportKey
	   CPExportKey(
		//ָ��CSP��Կ�������
		NULL,
		//ָ����Ҫ��������Կ������
		NULL,
		//���ܵ�������Կ
		NULL,
		//ָ��key BLOB����
		NULL,
		//
		NULL,
		//������Կ��������
		NULL,
		//��Կ���泤��
		NULL
		);

	//8 CPGenKey
	   CPGenKey(
		//ָ��CSP��Կ�������
		NULL,
		//ָ��������Կ�㷨��ʶ
		NULL,
		//ָ��������Կ��һЩ����
		NULL,
		//������Կ������
		NULL
		);

	//9 CPGenRandom
	   CPGenRandom(
		//ָ��CSP��Կ�������
		NULL,
		//
		NULL,
		//
		NULL
		);

	//10 CPGetKeyParam
	   CPGetKeyParam(
		//ָ��CSP��Կ�������
		NULL,
		//ָ����Կ������
		NULL,
		//������
		NULL,
		//��ֵ����
		NULL,
		//��ֵ����
		NULL,
		//
		NULL
		);

	//11 CPGetUserKey
	   CPGetUserKey(
		//ָ��CSP��Կ�������
		NULL,
		//ָ����Կ���
		NULL,
		//�����û���Կ���
		NULL
		);

	//12 CPImportKey
	   CPImportKey(
		//ָ��CSP��Կ�������
		NULL,
		//��Կ���ݣ�key BLOB��
		NULL,
		//key BLOB�ֽ���
		NULL,
		//
		NULL,
		//ָ��һЩ������Կ�Ĳ���
		NULL,
		//���ص�����Կ�ľ��
		NULL
		);

	//13 CPSetKeyParam
	   CPSetKeyParam(
		//ָ��CSP��Կ�������
		NULL,
		//ָ��Ŀ�������
		NULL,
		//������Կ�����
		NULL,
		//������Կ����ֵ
		NULL,
		//������Կ����ֵ����
		NULL
		);

	//14 CPDecrypt
	   CPDecrypt(
		//ָ��CSP��Կ�������
		NULL,
		//������Կ���
		NULL,	
		//������ܺ���Ҫ����HASH ָ��HASH������
		NULL,
		//�Ƿ����һ��
		NULL,
		//
		NULL,
		//����ǰ�� �ֱ��� �������� �������� 
		NULL,
		//���ݳ���
		NULL
		);

	//15 CPEncrypt
	   CPEncrypt(
		//ָ��CSP��Կ�������
		NULL,
		//������Կ���
		NULL,
		//�������ǰ��Ҫ����HASH ָ��HASH������
		NULL,
		//�Ƿ��Ǽ��ܵ����һ��
		NULL,
		//
		NULL,
		//����ǰ�� �ֱ��� �������� ��������
		NULL,
		//���ݳ���
		NULL,
		//pbData���ܳ���
		NULL
		);

	//16 CPCreateHash
	   CPCreateHash(
		//ָ��CSP��Կ�������
		NULL,
		//ָ���㷨��ʶ
		NULL,
		//ָ����Կ���
		NULL,
		//
		NULL,
		//����HASH������
		NULL
		);

	//17 CPDestroyHash
	   CPDestroyHash(
		//ָ��CSP��Կ�������
		NULL,
		//ָ���ͷ�HASH������
		NULL
		);

	//18 CPDuplicateHash ���Ӻ���
	   CPDuplicateHash(
		//ָ��CSP��Կ�������
		NULL,
		//ָ�������Ƶ�HASH����
		NULL,
		//������NULL
		NULL,
		//������0
		NULL,
		//���Ƶ�HASH����
		NULL
		);

	//19 CPGetHashParam
	   CPGetHashParam(
		//ָ��CSP��Կ�������
		NULL,
		//ָ��HASH������
		NULL,
		//������
		NULL,
		//���ؼ�ֵ��Ӧ�����ݻ���
		NULL,
		//�������ݳ���
		NULL,
		//
		NULL
		);

	//20 CPHashData
	   CPHashData(
		//ָ��CSP��Կ�������
		NULL,
		//ָ��HASH������
		NULL,
		//��Ҫ����HASH������
		NULL,
		//��ҪHASH�����ݳ���
		NULL,
		//
		NULL
		);

	//21 CPSetHashParam
	   CPSetHashParam(
		//ָ��CSP��Կ�������
		NULL,
		//ָ��HASH������
		NULL,
		//���ò����ļ�
		NULL,
		//���ò�����ֵ
		NULL,
		//
		NULL
		);

	//22 CPSignHash
	   CPSignHash(
		//ָ��CSP��Կ�������
		NULL,
		//ָ��HASH������
		NULL,
		//��ʹ�õ���Կ���
		NULL,
		//ѯ���û��Ƿ�֪��ʲô��Ϣ��ǩ��ʱ����ʾ����
		NULL,
		//
		NULL,
		// ǩ�����
		NULL,
		//ǩ���������
		NULL
		);

	//23 CPVerifySignature
	   CPVerifySignature(
		//ָ��CSP��Կ�������
		NULL,
		//ָ��HASH������
		NULL,
		//ǩ�����
		NULL,
		//ǩ���������
		NULL,
		//��ǩ��Կ
		NULL,
		//��ʾ����
		NULL,
		//
		NULL
		);

	//24 CPDuplicateKey ���Ӻ���
	   CPDuplicateKey(
		//ָ��CSP��Կ�������
		NULL,
		//��������Կ������
		NULL,
		//������NULL
		NULL,
		//������0
		NULL,
		//���Ƶ���Կ������
		NULL
		);

	//25 CPHashSessionKey
	   CPHashSessionKey(
		//ָ��CSP��Կ�������
		NULL,
		//ָ��HASH������
		NULL,
		//ָ��SESSION KEY������
		NULL,
		//
		NULL
		);



	getchar();
}