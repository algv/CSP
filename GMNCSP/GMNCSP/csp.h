//Version1.0 zhuheng20171721100300
/*
//1 CPAcquireContext	SUCCESS
//2 CPGetProvParam		SUCCESS
//3 CPReleaseContext	SUCCESS
//4 CPSetProvParam		SUCCESS
//5 CPDeriveKey			SUCCESS
//6 CPDestroyKey		SUCCESS
//7 CPExportKey			SUCCESS
//8 CPGenKey			SUCCESS
//9 CPGenRandom			SUCCESS
//10 CPGetKeyParam		SUCCESS
//11 CPGetUserKey		SUCCESS
//12 CPImportKey		SUCCESS
//13 CPSetKeyParam		SUCCESS
//14 CPDecrypt			SUCCESS
//15 CPEncrypt			SUCCESS
//16 CPCreateHash		SUCCESS	
//17 CPDestroyHash		SUCCESS
//18 CPDuplicateHash	SUCCESS			���Ӻ���
//19 CPGetHashParam		SUCCESS
//20 CPHashData			SUCCESS
//21 CPSetHashParam		SUCCESS
//22 CPSignHash			SUCCESS	
//23 CPVerifySignature	SUCCESS
//24 CPDuplicateKey		SUCCESS 		���Ӻ���
//25 CPHashSessionKey	SUCCESS
*/

#ifndef CSP_SPI
#define CSP_SPI

//DEBUG��ӡ��ʾ��Ϣ
#define DEBUG

#define EXPORT
#ifdef EXPORT
#define CSPINTERFACE extern "C" _declspec(dllexport)
//#define CSPINTERFACE 
#else
#define CSPINTERFACE extern "C" _declspec(dllimport)
#endif

typedef struct _key {
	UCHAR ALGID[64];
	UCHAR BLOCKLEN[64]; 
	UCHAR KEYLEN[64]; 
	UCHAR SALT[64]; 
	UCHAR PERMISSIONS[64];
	UCHAR IV[64]; 
	UCHAR PADDING[64]; 
	UCHAR MODE[64]; 
	UCHAR MODE_BITS[64]; 
	UCHAR EFFECTIVE_KEYLEN[64];

	int len;
	UCHAR key[256];
	UCHAR cv[64];
	UCHAR keyType[8];
	int puLen;
	UCHAR puKey[4096];
	int pvLen;
	UCHAR pvKey[4096];
	int derPuLen;
	UCHAR derPuKey[4096];
}HKEY_Z,* PHKEY_Z, HPKEY_Z, *PHPKEY_Z;

typedef struct _hash {
	UCHAR ALGID[64];
	UCHAR HASHVAL[64];
	UCHAR HASHSIZE[64];
	UCHAR HMAC_INFO[64];
	UCHAR TLS1PRF_LABEL[64];
	UCHAR TLS1PRF_SEED[64];
	
	PHKEY_Z phKey;
	UCHAR keyHashValue[256];
}HHASH_Z, * PHHASH_Z;

typedef struct _VTableProvStruc {
	DWORD   Version;
	FARPROC FuncVerifyImage;
	FARPROC FuncReturnhWnd;
	DWORD   dwProvType;
	BYTE    *pbContextInfo;
	DWORD   cbContextInfo;
	LPSTR   pszProvName;
} VTableProvStruc, *PVTableProvStruc;

//1 CPAcquireContext
CSPINTERFACE BOOL WINAPI CPAcquireContext(
	//���ص�CSP��Կ�����ľ��
	__out HCRYPTPROV *phProv,
	//ָ����Կ��������
	__in CHAR *pszContainer,
	//�Ƿ񴴽�/ɾ������
	__in DWORD dwFlags,
	//�ص������б�
	__in PVTableProvStruc pVTable
	);

//2 CPGetProvParam
CSPINTERFACE BOOL WINAPI   CPGetProvParam(
	//ָ��CSP��Կ����
	__in HCRYPTPROV hProv,
	//��ѯ��
	__in DWORD dwParam,
	//��ֵ����
	__out BYTE *pbData,
	//��ֵ����
	__inout DWORD *pdwDataLen,
	//ָ�����ؼ�ֵ��һЩ����
	__in DWORD dwFlags
	);

//3 CPReleaseContext
CSPINTERFACE BOOL WINAPI   CPReleaseContext(
	//�ͷ�CSP��Կ�������
	__in HCRYPTPROV hProv,
	//flag
	__in DWORD dwFlags
	);

//4 CPSetProvParam
CSPINTERFACE BOOL WINAPI   CPSetProvParam(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//���ò����ļ�
	__in DWORD dwParam,
	//���ò����ļ�ֵ
	__in BYTE *pbData,
	//ָ��һЩ��ֵ��صĲ���
	__in DWORD dwFlags
	);

//5 CPDeriveKey
CSPINTERFACE BOOL WINAPI   CPDeriveKey(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//ָ��������Կ���㷨��ʶ
	__in ALG_ID Algid,
	//�������ݵ�HASHֵ���
	__in HCRYPTHASH hBaseData,
	//ָ��session key��һЩ����
	__in DWORD dwFlags,
	//������Կ������
	__out HCRYPTKEY *phKey
	);

//6 CPDestroyKey
CSPINTERFACE BOOL WINAPI   CPDestroyKey(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//ָ��������Կ������
	__in HCRYPTKEY hKey
	);

//7 CPExportKey
CSPINTERFACE BOOL WINAPI   CPExportKey(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//ָ����Ҫ��������Կ������
	__in HCRYPTKEY hKey,
	//���ܵ�������Կ
	__in HCRYPTKEY hPubKey,
	//ָ��key BLOB����
	__in DWORD dwBlobType,
	//
	__in DWORD dwFlags,
	//������Կ��������
	__out BYTE *pbData,
	//��Կ���泤��
	__inout DWORD *pdwDataLen
	);

//8 CPGenKey
CSPINTERFACE BOOL WINAPI   CPGenKey(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//ָ��������Կ�㷨��ʶ
	__in ALG_ID Algid,
	//ָ��������Կ��һЩ����
	__in DWORD dwFlags,
	//������Կ������
	__out HCRYPTKEY *phKey
	);

//9 CPGenRandom
CSPINTERFACE BOOL WINAPI   CPGenRandom(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//
	__in DWORD dwLen,
	//
	__inout BYTE *pbBuffer
	);

//10 CPGetKeyParam
CSPINTERFACE BOOL WINAPI   CPGetKeyParam(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//ָ����Կ������
	__in HCRYPTKEY hKey,
	//������
	__in DWORD dwParam,
	//��ֵ����
	__out LPBYTE pbData,
	//��ֵ����
	__inout LPDWORD pcbDataLen,
	//
	__in DWORD dwFlags
	);

//11 CPGetUserKey
CSPINTERFACE BOOL WINAPI   CPGetUserKey(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//ָ����Կ���
	__in DWORD dwKeySpec,
	//�����û���Կ���
	__out HCRYPTKEY *phUserKey
	);

//12 CPImportKey
CSPINTERFACE BOOL WINAPI   CPImportKey(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//��Կ���ݣ�key BLOB��
	__in const BYTE *pbData,
	//key BLOB�ֽ���
	__in DWORD dwDataLen,
	//
	__in HCRYPTKEY hPubKey,
	//ָ��һЩ������Կ�Ĳ���
	__in DWORD dwFlags,
	//���ص�����Կ�ľ��
	__out HCRYPTKEY *phKey
	);

//13 CPSetKeyParam
CSPINTERFACE BOOL WINAPI   CPSetKeyParam(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//ָ��Ŀ�������
	__in HCRYPTKEY hKey,
	//������Կ�����
	__in DWORD dwParam,
	//������Կ����ֵ
	__in BYTE *pbData,
	//������Կ����ֵ����
	__in DWORD dwFlags
	);

//14 CPDecrypt
CSPINTERFACE BOOL WINAPI   CPDecrypt(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//������Կ���
	__in HCRYPTKEY hKey,
	//������ܺ���Ҫ����HASH ָ��HASH������
	__in HCRYPTHASH hHash,
	//�Ƿ����һ��
	__in BOOL Final,
	//
	__in DWORD dwFlags,
	//����ǰ�� �ֱ��� �������� �������� 
	__inout BYTE *pbData,
	//���ݳ���
	__inout DWORD *pdwDataLen
	);

//15 CPEncrypt
CSPINTERFACE BOOL WINAPI   CPEncrypt(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//������Կ���
	__in HCRYPTKEY hKey,
	//�������ǰ��Ҫ����HASH ָ��HASH������
	__in HCRYPTHASH hHash,
	//�Ƿ��Ǽ��ܵ����һ��
	__in BOOL Final,
	//
	__in DWORD dwFlags,
	//����ǰ�� �ֱ��� �������� ��������
	__inout BYTE *pbData,
	//���ݳ���
	__inout DWORD *pdwDataLen,
	//pbData���ܳ���
	__in DWORD dwBufLen
	);

//16 CPCreateHash
CSPINTERFACE BOOL WINAPI   CPCreateHash(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//ָ���㷨��ʶ
	__in ALG_ID Algid,
	//ָ����Կ���
	__in HCRYPTKEY hKey,
	//
	__in DWORD dwFlags,
	//����HASH������
	__out HCRYPTHASH *phHash
	);

//17 CPDestroyHash
CSPINTERFACE BOOL WINAPI   CPDestroyHash(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//ָ���ͷ�HASH������
	__in HCRYPTHASH hHash
	);

//18 CPDuplicateHash ���Ӻ���
CSPINTERFACE BOOL WINAPI   CPDuplicateHash(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//ָ�������Ƶ�HASH����
	__in HCRYPTHASH hHash,
	//������NULL
	__reserved DWORD *pdwReserved,
	//������0
	__in DWORD dwFlags,
	//���Ƶ�HASH����
	__out HCRYPTHASH *phHash
	);

//19 CPGetHashParam
CSPINTERFACE BOOL WINAPI   CPGetHashParam(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//ָ��HASH������
	__in HCRYPTHASH hHash,
	//������
	__in DWORD dwParam,
	//���ؼ�ֵ��Ӧ�����ݻ���
	__out BYTE *pbData,
	//�������ݳ���
	__inout DWORD *pdwDataLen,
	//
	__in DWORD dwFlags
	);

//20 CPHashData
CSPINTERFACE BOOL WINAPI   CPHashData(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//ָ��HASH������
	__in HCRYPTHASH hHash,
	//��Ҫ����HASH������
	__in const BYTE *pbData,
	//��ҪHASH�����ݳ���
	__in DWORD dwDataLen,
	//
	__in DWORD dwFlags
	);

//21 CPSetHashParam
CSPINTERFACE BOOL WINAPI   CPSetHashParam(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//ָ��HASH������
	__in HCRYPTHASH hHash,
	//���ò����ļ�
	__in DWORD dwParam,
	//���ò�����ֵ
	__in BYTE *pbData,
	//
	__in DWORD dwFlags
	);

//22 CPSignHash
CSPINTERFACE BOOL WINAPI   CPSignHash(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//ָ��HASH������
	__in HCRYPTHASH hHash,
	//��ʹ�õ���Կ���
	__in DWORD dwKeySpec,
	//ѯ���û��Ƿ�֪��ʲô��Ϣ��ǩ��ʱ����ʾ����
	__in LPCWSTR sDescription,
	//
	__in DWORD dwFlags,
	// ǩ�����
	__out BYTE *pbSignature,
	//ǩ���������
	__inout DWORD *pdwSigLen
	);

//23 CPVerifySignature
CSPINTERFACE BOOL WINAPI   CPVerifySignature(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//ָ��HASH������
	__in HCRYPTHASH hHash,
	//ǩ�����
	__in const BYTE *pbSignature,
	//ǩ���������
	__in DWORD dwSigLen,
	//��ǩ��Կ
	__in HCRYPTKEY hPubKey,
	//��ʾ����
	__in LPCWSTR sDescription,
	//
	__in DWORD dwFlags
	);

//24 CPDuplicateKey ���Ӻ���
CSPINTERFACE BOOL WINAPI   CPDuplicateKey(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hUID,
	//��������Կ������
	__in HCRYPTKEY hKey,
	//������NULL
	__in DWORD *pdwReserved,
	//������0
	__in DWORD dwFlags,
	//���Ƶ���Կ������
	__out HCRYPTKEY *phKey
	);

//25 CPHashSessionKey
CSPINTERFACE BOOL WINAPI   CPHashSessionKey(
	//ָ��CSP��Կ�������
	__in HCRYPTPROV hProv,
	//ָ��HASH������
	__in HCRYPTHASH hHash,
	//ָ��SESSION KEY������
	__in HCRYPTKEY hKey,
	//
	__in DWORD dwFlags
	);

#endif