#ifndef __HITINY_SYS_H__
#define __HITINY_SYS_H__

#include "hi_common.h"

int hitiny_MPI_SYS_Init();
void hitiny_MPI_SYS_Done();

int hitiny_sys_bind_VPSS_GROUP(int vpss_dev_id, int vpss_chn_id, int grp_id);
int hitiny_sys_unbind_VPSS_GROUP(int vpss_dev_id, int vpss_chn_id, int grp_id);

int hitiny_sys_bind_VI_VDA(int vi_dev, int vi_chn, int vda_chn);
int hitiny_sys_unbind_VI_VDA(int vi_dev, int vi_chn, int vda_chn);

int hitiny_open_dev(const char* fname);

void* hitiny_MPI_SYS_Mmap(HI_U32 u32PhyAddr, HI_U32 u32Size);
int hitiny_MPI_SYS_Munmap(HI_VOID* pVirAddr, HI_U32 u32Size);

int hitiny_MPI_SYS_MmzAlloc(HI_U32 *pu32PhyAddr, HI_VOID **ppVirtAddr, const HI_CHAR *strMmb, const HI_CHAR *strZone, HI_U32 u32Len);
int hitiny_MPI_SYS_MmzAlloc_Cached(HI_U32 *pu32PhyAddr, HI_VOID **ppVirtAddr, const HI_CHAR *strMmb, const HI_CHAR *strZone, HI_U32 u32Len);
int hitiny_MPI_SYS_MmzFree(HI_U32 u32PhyAddr, HI_VOID *pVirtAddr);
int hitiny_MPI_SYS_MmzFlushCache(HI_U32 u32PhyAddr, HI_VOID *pVirtAddr, HI_U32 u32Size);



#endif // __HITINY_SYS_H__

