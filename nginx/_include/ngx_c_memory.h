
#ifndef __NGX_MEMORY_H__
#define __NGX_MEMORY_H__

#include <stddef.h>  //NULL
class CMemory 
{
private:
	CMemory() {}  

public:
	~CMemory(){};

private:
	static CMemory *m_instance;

public:	
	static CMemory* GetInstance() //单例
	{			
		if(m_instance == NULL)
		{
			//锁
			if(m_instance == NULL)
			{				
				m_instance = new CMemory();
				static CGarhuishou cl; 
			}
			//放锁
		}
		return m_instance;
	}	
	class CGarhuishou 
	{
	public:				
		~CGarhuishou()
		{
			if (CMemory::m_instance)
			{						
				delete CMemory::m_instance;
				CMemory::m_instance = NULL;				
			}
		}
	};
	//-------

public:
 // 声明一个名为 AllocMemory 的函数，用于分配指定大小的内存
void *AllocMemory(int memCount,bool ifmemset); 
// 声明一个名为 FreeMemory 函数，用于释放先前分配的内存地址
void FreeMemory(void *point); 

	
};

#endif
