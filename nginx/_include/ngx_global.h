
#ifndef __NGX_GBLDEF_H__
#define __NGX_GBLDEF_H__

#include <signal.h> 

#include "ngx_c_slogic.h"
#include "ngx_c_threadpool.h"


//结构定义
//该结构体用于存储配置文件中=两边的名称和内容
typedef struct _CConfItem
{
	char ItemName[50];
	char ItemContent[500];
}CConfItem,*LPCConfItem;

//和运行日志相关 
typedef struct
{
	int    log_level;   //日志级别 或者日志类型，ngx_macro.h里分0-8共9个级别
	int    fd;          //日志文件描述符
}ngx_log_t;


//外部全局量声明
extern size_t        g_argvneedmem;
extern size_t        g_envneedmem; 
extern int           g_os_argc; 
extern char          **g_os_argv;
extern char          *gp_envmem; 
extern int           g_daemonized;
extern CLogicSocket  g_socket;  
extern CThreadPool   g_threadpool;

extern pid_t         ngx_pid;
extern pid_t         ngx_parent;
extern ngx_log_t     ngx_log; // 存储日志对象的全局变量
extern int           ngx_process;   
extern sig_atomic_t  ngx_reap;   
extern int           g_stopEvent;

#endif
