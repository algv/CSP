// csp_service_program_interface.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"

//1 CPAcquireContext
CSPINTERFACE BOOL WINAPI CPAcquireContext(
	__out HCRYPTPROV *phProv,
	__in CHAR *pszContainer,
	__in DWORD dwFlags,
	__in PVTableProvStruc pVTable
	)
{
#ifdef DEBUG
	puts("CPAcquireContext");
#endif
	int rv;

	LogEntry("CPAcquireContext","start" , 0, 10 );
	//��ʼ���߳�ͬ��
	if ((rv = CSP_InitMutex())!=0){
		return FALSE;
	}
	CSP_LockMutex();
	
	//���������ļ�
	if (initCSP()<0){
		return FALSE;
	}
	
	//���ܻ�״̬
	if (testSjl22()<0){
		return FALSE;
	}

	CSP_UnlockMutex();
	LogEntry("CPAcquireContext", "end", 0, 10);
	return TRUE;
}

//2 CPGetProvParam
CSPINTERFACE BOOL WINAPI CPGetProvParam(
	__in HCRYPTPROV hProv,
	__in DWORD dwParam,
	__out BYTE *pbData,
	__inout DWORD *pdwDataLen,
	__in DWORD dwFlags
	)
{
#ifdef DEBUG
	puts("CPGetProvParam");
#endif
	LogEntry("CPGetProvParam", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPGetProvParam", "end", 0, 10);
	return TRUE;
}


//3 CPReleaseContext
CSPINTERFACE BOOL WINAPI CPReleaseContext(
	__in HCRYPTPROV hProv,
	__in DWORD dwFlags
	)
{
#ifdef DEBUG
	puts("CPReleaseContext");
#endif
	LogEntry("CPReleaseContext", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	//�����߳�ͬ��
	CSP_Destroy_Mutex();
	LogEntry("CPReleaseContext", "end", 0, 10);
	return TRUE;
}


//4 CPSetProvParam
CSPINTERFACE BOOL WINAPI CPSetProvParam(
	__in HCRYPTPROV hProv,
	__in DWORD dwParam,
	__in BYTE *pbData,
	__in DWORD dwFlags
	)
{
#ifdef DEBUG
	puts("CPSetProvParam");
#endif
	LogEntry("CPSetProvParam", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPSetProvParam", "end", 0, 10);
	return TRUE;
}


//5 CPDeriveKey
CSPINTERFACE BOOL WINAPI CPDeriveKey(
	__in HCRYPTPROV hProv,
	__in ALG_ID Algid,
	__in HCRYPTHASH hBaseData,
	__in DWORD dwFlags,
	__out HCRYPTKEY *phKey
	)
{
#ifdef DEBUG
	puts("CPDeriveKey");
#endif
	LogEntry("CPDeriveKey", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPDeriveKey", "end", 0, 10);

	return TRUE;
}


//6 CPDestroyKey
CSPINTERFACE BOOL WINAPI CPDestroyKey(
	__in HCRYPTPROV hProv,
	__in HCRYPTKEY hKey
	)
{
#ifdef DEBUG
	puts("CPDestroyKey");
#endif
	LogEntry("CPDestroyKey", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPDestroyKey", "end", 0, 10);
	return TRUE;
}


//7 CPExportKey
CSPINTERFACE BOOL WINAPI CPExportKey(
	__in HCRYPTPROV hProv,
	__in HCRYPTKEY hKey,
	__in HCRYPTKEY hPubKey,
	__in DWORD dwBlobType,
	__in DWORD dwFlags,
	__out BYTE *pbData,
	__inout DWORD *pdwDataLen
	)
{
#ifdef DEBUG
	puts("CPExportKey");
#endif
	LogEntry("CPExportKey", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPExportKey", "end", 0, 10);
	return TRUE;
}


//8 CPGenKey
CSPINTERFACE BOOL WINAPI CPGenKey(
	__in HCRYPTPROV hProv,
	__in ALG_ID Algid,
	__in DWORD dwFlags,
	__out HCRYPTKEY *phKey
	)
{
#ifdef DEBUG
	puts("CPGenKey");
#endif
	LogEntry("CPGenKey", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPGenKey", "end", 0, 10);
	return TRUE;
}


//9 CPGenRandom
CSPINTERFACE BOOL WINAPI CPGenRandom(
	__in HCRYPTPROV hProv,
	__in DWORD dwLen,
	__inout BYTE *pbBuffer
	)
{
#ifdef DEBUG
	puts("CPGenRandom");
#endif
	LogEntry("CPGenRandom", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPGenRandom", "end", 0, 10);
	return TRUE;
}


//10 CPGetKeyParam
CSPINTERFACE BOOL WINAPI CPGetKeyParam(
	__in HCRYPTPROV hProv,
	__in HCRYPTKEY hKey,
	__in DWORD dwParam,
	__out LPBYTE pbData,
	__inout LPDWORD pcbDataLen,
	__in DWORD dwFlags
	)
{
#ifdef DEBUG
	puts("CPGetKeyParam");
#endif
	LogEntry("CPGetKeyParam", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPGetKeyParam", "end", 0, 10);

	return TRUE;
}


//11 CPGetUserKey
CSPINTERFACE BOOL WINAPI CPGetUserKey(
	__in HCRYPTPROV hProv,
	__in DWORD dwKeySpec,
	__out HCRYPTKEY *phUserKey
	)
{
#ifdef DEBUG
	puts("CPGetUserKey");
#endif
	LogEntry("CPGetUserKey", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPGetUserKey", "end", 0, 10);
	return TRUE;
}


//12 CPImportKey
CSPINTERFACE BOOL WINAPI CPImportKey(
	__in HCRYPTPROV hProv,
	__in const BYTE *pbData,
	__in DWORD dwDataLen,
	__in HCRYPTKEY hPubKey,
	__in DWORD dwFlags,
	__out HCRYPTKEY *phKey
	)
{
#ifdef DEBUG
	puts("CPImportKey");
#endif
	LogEntry("CPImportKey", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPImportKey", "end", 0, 10);
	return TRUE;
}


//13 CPSetKeyParam
CSPINTERFACE BOOL WINAPI CPSetKeyParam(
	__in HCRYPTPROV hProv,
	__in HCRYPTKEY hKey,
	__in DWORD dwParam,
	__in BYTE *pbData,
	__in DWORD dwFlags
	)
{
#ifdef DEBUG
	puts("CPSetKeyParam");
#endif
	LogEntry("CPSetKeyParam", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPSetKeyParam", "end", 0, 10);
	return TRUE;
}


//14 CPDecrypt
CSPINTERFACE BOOL WINAPI CPDecrypt(
	__in HCRYPTPROV hProv,
	__in HCRYPTKEY hKey,
	__in HCRYPTHASH hHash,
	__in BOOL Final,
	__in DWORD dwFlags,
	__inout BYTE *pbData,
	__inout DWORD *pdwDataLen
	)
{
#ifdef DEBUG
	puts("CPDecrypt");
#endif
	LogEntry("CPDecrypt", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPDecrypt", "end", 0, 10);
	return TRUE;
}


//15 CPEncrypt
CSPINTERFACE BOOL WINAPI CPEncrypt(
	__in HCRYPTPROV hProv,
	__in HCRYPTKEY hKey,
	__in HCRYPTHASH hHash,
	__in BOOL Final,
	__in DWORD dwFlags,
	__inout BYTE *pbData,
	__inout DWORD *pdwDataLen,
	__in DWORD dwBufLen
	)
{
#ifdef DEBUG
	puts("CPEncrypt");
#endif
	LogEntry("CPEncrypt", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPEncrypt", "end", 0, 10);
	return TRUE;
}


//16 CPCreateHash
CSPINTERFACE BOOL WINAPI CPCreateHash(
	__in HCRYPTPROV hProv,
	__in ALG_ID Algid,
	__in HCRYPTKEY hKey,
	__in DWORD dwFlags,
	__out HCRYPTHASH *phHasg
	)
{
#ifdef DEBUG
	puts("CPCreateHash");
#endif
	LogEntry("CPCreateHash", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPCreateHash", "end", 0, 10);
	return TRUE;
}


//17 CPDestroyHash
CSPINTERFACE BOOL WINAPI CPDestroyHash(
	__in HCRYPTPROV hProv,
	__in HCRYPTHASH hHash
	)
{
#ifdef DEBUG
	puts("CPDestroyHash");
#endif
	LogEntry("CPDestroyHash", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPDestroyHash", "end", 0, 10);
	return TRUE;
}


//18 CPDuplicateHash ���Ӻ���
CSPINTERFACE BOOL WINAPI CPDuplicateHash(
	__in HCRYPTPROV hProv,
	__in HCRYPTHASH hHash,
	__reserved DWORD *pdwReserved,
	__in DWORD dwFlags,
	__out HCRYPTHASH *phHash
	)
{
#ifdef DEBUG
	puts("CPDuplicateHash");
#endif
	LogEntry("CPDuplicateHash", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPDuplicateHash", "end", 0, 10);
	return TRUE;
}


//19 CPGetHashParam
CSPINTERFACE BOOL WINAPI CPGetHashParam(
	__in HCRYPTPROV hProv,
	__in HCRYPTHASH hHash,
	__in DWORD dwParam,
	__out BYTE *pbData,
	__inout DWORD *pdwDataLen,
	__in DWORD dwFlags
	)
{
#ifdef DEBUG
	puts("CPGetHashParam");
#endif
	LogEntry("CPGetHashParam", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPGetHashParam", "end", 0, 10);

	return TRUE;
}


//20 CPHashData
CSPINTERFACE BOOL WINAPI CPHashData(
	__in HCRYPTPROV hProv,
	__in HCRYPTHASH hHash,
	__in const BYTE *pbData,
	__in DWORD dwDataLen,
	__in DWORD dwFlags
	)
{
#ifdef DEBUG
	puts("CPHashData");
#endif
	LogEntry("CPHashData", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPHashData", "end", 0, 10);

	return TRUE;
}


//21 CPSetHashParam
CSPINTERFACE BOOL WINAPI CPSetHashParam(
	__in HCRYPTPROV hProv,
	__in HCRYPTHASH hHash,
	__in DWORD dwParam,
	__in BYTE *pbData,
	__in DWORD dwFlags
	)
{
#ifdef DEBUG
	puts("CPSetHashParam");
#endif
	LogEntry("CPSetHashParam", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPSetHashParam", "end", 0, 10);

	return TRUE;
}


//22 CPSignHash
CSPINTERFACE BOOL WINAPI CPSignHash(
	__in HCRYPTPROV hProv,
	__in HCRYPTHASH hHash,
	__in DWORD dwKeySpec,
	__in LPCWSTR sDescription,
	__in DWORD dwFlags,
	__out BYTE *pbSignature,
	__inout DWORD *pdwSigLen
	)
{
#ifdef DEBUG
	puts("CPSignHash");
#endif
	LogEntry("CPSignHash", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPSignHash", "end", 0, 10);
	return TRUE;
}


//23 CPVerifySignature
CSPINTERFACE BOOL WINAPI CPVerifySignature(
	__in HCRYPTPROV hProv,
	__in HCRYPTHASH hHash,
	__in const BYTE *pbSignature,
	__in DWORD dwSigLen,
	__in HCRYPTKEY hPubKey,
	__in LPCWSTR sDescription,
	__in DWORD dwFlags
	)
{
#ifdef DEBUG
	puts("CPVerifySignature");
#endif
	LogEntry("CPVerifySignature", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPVerifySignature", "end", 0, 10);
	return TRUE;
}


//24 CPDuplicateKey ���Ӻ���
CSPINTERFACE BOOL WINAPI CPDuplicateKey(
	__in HCRYPTPROV hUID,
	__in HCRYPTKEY hKey,
	__in DWORD *pdwReserved,
	__in DWORD dwFlags,
	__out HCRYPTKEY *phKey
	)
{
#ifdef DEBUG
	puts("CPDuplicateKey");
#endif
	LogEntry("CPDuplicateKey", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPDuplicateKey", "end", 0, 10);
	return TRUE;
}


//25 CPHashSessionKey
CSPINTERFACE BOOL WINAPI CPHashSessionKey(
	__in HCRYPTPROV hProv,
	__in HCRYPTHASH hHash,
	__in HCRYPTKEY hKey,
	__in DWORD dwFlags
	)
{
#ifdef DEBUG
	puts("CPHashSessionKey");
#endif
	LogEntry("CPHashSessionKey", "start", 0, 10);
	CSP_LockMutex();
	CSP_UnlockMutex();
	LogEntry("CPHashSessionKey", "end", 0, 10);
	return TRUE;
}




