#ifndef CSP_TOOL_H
#define CSP_TOOL_H
//�Ƿ��¼��־	0.No 1.Yes
#define LOG_LEVEL 1
//��־�ļ���С
#define MAX_LOG_SIZE (2048*1024)

//������־
void LogEntry(char *functionName, char *processDes, int rv, int level);

//�ж��ļ���С
unsigned long fileLength(char *fname);

//��õ�ǰʱ��
char * GetTime(char *Buffer, int Len, const char *format);
#endif