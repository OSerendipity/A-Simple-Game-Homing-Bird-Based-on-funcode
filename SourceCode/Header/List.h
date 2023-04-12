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
// �������ֻ�ȡ Sprite
extern int   GList_GetListSize();
// ����������ȡ Sprite�����Ҫ��������ɾ�����е�ĳ��Ԫ�أ���Ӻ�����ǰ����� (��������ʼ��Ϊ�����СȻ��ݼ�)�������Ȼ����
extern SGameSprite *GList_GetSpriteByName( const char *szName );
// ���һ�� Sprite ��������
extern SGameSprite *GList_GetSpriteByIndex( const int iIndex );
// ��������ɾ�� Sprite. bDeleteImage : �Ƿ�ɾ���� Sprite �ڵ�ͼ�ϵ�ͼƬ��ʾ
extern SpriteStruct *GList_AddSprite( SGameSprite *pSprite );
// ����ָ��ɾ�� Sprite. bDeleteImage : �Ƿ�ɾ���� Sprite �ڵ�ͼ�ϵ�ͼƬ��ʾ
extern void GList_DeleteSprite( const char *szName, bool bDeleteImage = true );
// ɾ������ Sprite. bDeleteImage : �Ƿ�ɾ���� Sprite �ڵ�ͼ�ϵ�ͼƬ��ʾ
extern void GList_DeleteSprite( SGameSprite *pSprite, bool bDeleteImage = true );
extern void GList_DeleteAllSprite( bool bDeleteImage = true );
#endif // _LESSON_X_H_
