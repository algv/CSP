// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�: 
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <process.h>
#include <wincrypt.h>
#include <winerror.h>
#include <errno.h>
#include <WinSock2.h>


// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include "csp.h"
#include "cspdef.h"
#include "mutex.h"
#include "log.h"
#include "cspService.h"
#include "common_util.h"
#include "tcptools.h"
#include "config.h"
#include "regedit.h"
#include "sjl22api.h"