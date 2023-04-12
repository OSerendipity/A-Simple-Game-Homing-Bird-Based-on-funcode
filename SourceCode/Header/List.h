/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _LISTX_H_
#define _LISTX_H_
//
#include <windows.h>
#include "CommonAPI.h"
#include"virusplane.h"

struct SpriteStruct
{
    SGameSprite  *pSprite;
    SpriteStruct *pNext;
    SpriteStruct *pPrev;
};
// 根据名字获取 Sprite
extern int   GList_GetListSize();
// 根据索引获取 Sprite，如果要遍历链表并删除其中的某个元素，请从后面往前面遍历 (即索引初始化为链表大小然后递减)，否则必然出错
extern SGameSprite *GList_GetSpriteByName( const char *szName );
// 添加一个 Sprite 到链表里
extern SGameSprite *GList_GetSpriteByIndex( const int iIndex );
// 根据名字删除 Sprite. bDeleteImage : 是否删除该 Sprite 在地图上的图片显示
extern SpriteStruct *GList_AddSprite( SGameSprite *pSprite );
// 根据指针删除 Sprite. bDeleteImage : 是否删除该 Sprite 在地图上的图片显示
extern void GList_DeleteSprite( const char *szName, bool bDeleteImage = true );
// 删除所有 Sprite. bDeleteImage : 是否删除该 Sprite 在地图上的图片显示
extern void GList_DeleteSprite( SGameSprite *pSprite, bool bDeleteImage = true );
extern void GList_DeleteAllSprite( bool bDeleteImage = true );
#endif // _LESSON_X_H_
