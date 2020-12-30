#include <configs/s5p_goni.h>
 
/*
参数1：通道号
参数2：从SD卡的哪个扇区开始拷贝
参数3：拷贝多少个扇区
参数4：拷贝到内存的哪里
参数5：不知道具体用途
*/
//typedef bool (*CopySDMMCtoMemTypeDef)(int, unsigned int, unsigned short, unsigned int*, bool);
 
void CopySDMMCtoMem(void)
{
    /*CopySDMMCtoMemTypeDef pFuncCopySDMMCtoMem;
 
    pFuncCopySDMMCtoMem = (CopySDMMCtoMemTypeDef)(*((volatile unsigned int *)0xD0037F98));
    unsigned int ch = *((volatile unsigned int*)(0xd0037488));
 
    if(ch == 0xeb000000)
    {
        //通道0，iNand
    }
    else if(ch == 0xeb200000)
    {
        //通道2，SD卡
        pFuncCopySDMMCtoMem(2, 33, 1000,(unsigned int*)CONFIG_SYS_TEXT_BASE, 0); 
    }*/

    (((bool(*)(int, unsigned int, unsigned short, unsigned int*, bool)) (*((unsigned int *)0xD0037F98)))     (2,33,1000,(unsigned int*)0x34800000,0));
}

//#define CopySDMMCtoMem(z,a,b,c,e)(((bool(*)(int, unsigned int, unsigned short, unsigned int*, bool)) (*((unsigned int *)0xD0037F98)))(z,a,b,c,e)) 


/*void copytomem(void){
    //CopySDMMCtoMem(2,33,1000,(unsigned int*)0x34800000, 0);
    (((bool(*)(int, unsigned int, unsigned short, unsigned int*, bool)) (*((unsigned int *)0xD0037F98)))     (2,49,1000,(unsigned int*)0x34800000,0));
    //(((u8_t(*)(s32_t, u32_t, u16_t, u32_t *, s32_t))(*((u32_t *)(0xd0037f98))))(2,49,1000,(unsigned int*)0x34800000,0))
}*/