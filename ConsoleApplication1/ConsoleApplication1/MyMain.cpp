#include <Windows.h>
#include <stdio.h>
#include "MyMain.h"
#include "csp.h"

#pragma comment(lib,"GMNCSP.lib")

int main(){
	HCRYPTPROV hProv = 0;
	BOOL bf = FALSE;
	int count = 0;

	puts("CSP TEST.");
	//1 CPAcquireContext
	bf = CPAcquireContext(
		//���ص�CSP��Կ�����ľ��
		&hProv,
		//ָ����Կ��������
		NULL,
		//�Ƿ񴴽�/ɾ������
		NULL,
		//�ص������б�
		NULL
		);
	 if (bf){
		 printf("SUCCESS COUNT: %d\n",(++count));
	 }
	 else {
		 printf("ERROR %d\n",__LINE__);
	 }
	 DWORD dwLen = 1024;
	 BYTE bValue [1024];
	 DWORD dwFlag = 0;
	//2 CPGetProvParam
	 bf = CPGetProvParam(
		//ָ��CSP��Կ����
		hProv,
		//��ѯ��
		 (DWORD)"zhuheng001",
		//��ֵ����
		 bValue,
		//��ֵ����
		&dwLen,
		//ָ�����ؼ�ֵ��һЩ����
		dwFlag
		);
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }
	   printf("-------------> len: %u flag: %u buff;%s\n ",dwLen,dwFlag,(char*)bValue);

	//4 CPSetProvParam
	   bf = CPSetProvParam(
		//ָ��CSP��Կ�������
		hProv,
		//���ò����ļ�
		(DWORD)"zhuheng001",
		//���ò����ļ�ֵ
		(BYTE*)"zhuheng",
		//ָ��һЩ��ֵ��صĲ���
		REG_SZ
		);
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//5 CPDeriveKey
	   bf = CPDeriveKey(
		//ָ��CSP��Կ�������
		   hProv,
		//ָ��������Կ���㷨��ʶ
		NULL,
		//�������ݵ�HASHֵ���
		NULL,
		//ָ��session key��һЩ����
		NULL,
		//������Կ������
		NULL
		);
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//6 CPDestroyKey
	   bf = CPDestroyKey(
		//ָ��CSP��Կ�������
		   hProv,
		//ָ��������Կ������
		NULL
		);
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//7 CPExportKey
	   bf = CPExportKey(
		//ָ��CSP��Կ�������
		   hProv,
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
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//8 CPGenKey
	   bf = CPGenKey(
		//ָ��CSP��Կ�������
		   hProv,
		//ָ��������Կ�㷨��ʶ
		NULL,
		//ָ��������Կ��һЩ����
		NULL,
		//������Կ������
		NULL
		);
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//9 CPGenRandom
	   bf = CPGenRandom(
		//ָ��CSP��Կ�������
		   hProv,
		//
		NULL,
		//
		NULL
		);
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//10 CPGetKeyParam
	   bf = CPGetKeyParam(
		//ָ��CSP��Կ�������
		   hProv,
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
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//11 CPGetUserKey
	   bf = CPGetUserKey(
		//ָ��CSP��Կ�������
		   hProv,
		//ָ����Կ���
		NULL,
		//�����û���Կ���
		NULL
		);
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//12 CPImportKey
	   bf = CPImportKey(
		//ָ��CSP��Կ�������
		   hProv,
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
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//13 CPSetKeyParam
	   bf = CPSetKeyParam(
		//ָ��CSP��Կ�������
		   hProv,
		//ָ��Ŀ�������
		NULL,
		//������Կ�����
		NULL,
		//������Կ����ֵ
		NULL,
		//������Կ����ֵ����
		NULL
		);
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//14 CPDecrypt
	   bf = CPDecrypt(
		//ָ��CSP��Կ�������
		   hProv,
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
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//15 CPEncrypt
	   bf = CPEncrypt(
		//ָ��CSP��Կ�������
		   hProv,
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
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//16 CPCreateHash
	   bf = CPCreateHash(
		//ָ��CSP��Կ�������
		   hProv,
		//ָ���㷨��ʶ
		NULL,
		//ָ����Կ���
		NULL,
		//
		NULL,
		//����HASH������
		NULL
		);
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//17 CPDestroyHash
	   bf = CPDestroyHash(
		//ָ��CSP��Կ�������
		   hProv,
		//ָ���ͷ�HASH������
		NULL
		);
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//18 CPDuplicateHash ���Ӻ���
	   bf = CPDuplicateHash(
		//ָ��CSP��Կ�������
		   hProv,
		//ָ�������Ƶ�HASH����
		NULL,
		//������NULL
		NULL,
		//������0
		NULL,
		//���Ƶ�HASH����
		NULL
		);
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//19 CPGetHashParam
	   bf = CPGetHashParam(
		//ָ��CSP��Կ�������
		   hProv,
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
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//20 CPHashData
	   bf = CPHashData(
		//ָ��CSP��Կ�������
		   hProv,
		//ָ��HASH������
		NULL,
		//��Ҫ����HASH������
		NULL,
		//��ҪHASH�����ݳ���
		NULL,
		//
		NULL
		);
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//21 CPSetHashParam
	   bf = CPSetHashParam(
		//ָ��CSP��Կ�������
		   hProv,
		//ָ��HASH������
		NULL,
		//���ò����ļ�
		NULL,
		//���ò�����ֵ
		NULL,
		//
		NULL
		);
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//22 CPSignHash
	   bf = CPSignHash(
		//ָ��CSP��Կ�������
		   hProv,
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
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//23 CPVerifySignature
	   bf = CPVerifySignature(
		//ָ��CSP��Կ�������
		   hProv,
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
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }

	//24 CPDuplicateKey ���Ӻ���
	   bf = CPDuplicateKey(
		//ָ��CSP��Կ�������
		hProv,
		//��������Կ������
		NULL,
		//������NULL
		NULL,
		//������0
		NULL,
		//���Ƶ���Կ������
		NULL
		);
	   if (bf) {
		    printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }
	  
	   //25 CPHashSessionKey
	   bf = CPHashSessionKey(
		//ָ��CSP��Կ�������
		hProv,
		//ָ��HASH������
		NULL,
		//ָ��SESSION KEY������
		NULL,
		//
		NULL
		);
	   if (bf) {
		   printf("SUCCESS COUNT: %d\n",(++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }


	   //3 CPReleaseContext
	   bf = CPReleaseContext(
		   //�ͷ�CSP��Կ�������
		   hProv,
		   //flag
		   NULL
	   );
	   if (bf) {
		   printf("SUCCESS COUNT: %d\n", (++count));
	   }
	   else {
		   printf("ERROR %d\n",__LINE__);
	   }


	getchar();
}