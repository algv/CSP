#ifndef CSP_TOOL_H
#define CSP_TOOL_H
//�Ƿ��¼��־	0.No 1.Yes
#define LOG_LEVEL 1
//��־�ļ���С
#define MAX_LOG_SIZE (2048*1024)
#define LINELEN 4096
#define LOGFILE "csp_zhuheng.log"
#define CONFIGFILE "csp_config_zhuheng.cfg"

//������־
void LogEntry(char *functionName, char *processDes, int rv, int level);

void VarLogEntry(char *functionName, char *processDes, int rv, int level,...);

//�ж��ļ���С
unsigned long fileLength(char *fname);

//��õ�ǰʱ��
char * GetTime(char *Buffer, int Len, const char *format);

int GetConfigString(char *pSectionName,char* pFieldname,char **ppValue);

int Z_GetProfileString(const char *configFileName,const char *Section,const char *FieldName,char *value,int MaxValueLen,BOOL NormalizeNames);

char *NormalizeStringUpCase(char *pszString);

void NormalizeString(char *s);

#endif