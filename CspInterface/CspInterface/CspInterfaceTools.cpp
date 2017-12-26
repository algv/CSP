#include "stdafx.h"

static	char *logFile = "csp.log";

void LogEntry(char *functionName, char *processDes, int rv, int level){
	FILE *log = NULL;
	
	//�Ƿ��¼log
	if (!level || LOG_LEVEL == 0){
		return ;
	}

	//��ǰʱ��
	char fileName[MAX_PATH];
	char timePad[4+2+2+2+2+2+1];
	GetTime(timePad,sizeof(timePad),"%Y%m%d%H%M%S");
	timePad[4+2+2+2+2+2] = 0;
	
	//��ȡ��־�ļ�
	if (fileLength(logFile)>MAX_LOG_SIZE){
		strcpy(fileName,logFile);
		strcpy(fileName+sizeof(logFile),timePad);

		remove(fileName);
		rename(logFile,fileName);
	}

	//��־�ļ�
	log = fopen(logFile, "a");
	if (NULL == log){
		return;
	}

	functionName = (NULL == functionName) ? "NULL" : functionName;
	processDes = (NULL == processDes) ? "NULL" : processDes;

	fprintf(log,"[0x%08X]",_getpid());
	fprintf(log,"/* %s()",functionName);
	fprintf(log," %s ",processDes);
	fprintf(log, "(%d) %s */\n", rv, timePad);
	
	fclose(log);
	return;
}

unsigned long fileLength(char *fname){
	HFILE handle;
	long start, end;

	//�ж��ļ���ʼ and ����	
	handle = _lopen(fname,OF_READ);
	start = _llseek(handle,0L,SEEK_SET);
	end = _llseek(handle,0L,SEEK_END);
	_lclose(handle);
	return (end-start);
}

char * GetTime(char *Buffer, int Len, const char *format){
	time_t clock;
	clock = time((time_t)0);
	strftime(Buffer, Len, format, localtime(&clock));
	return (Buffer);
}