/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include "scenseX.h"
#include <Stdio.h>
#include "CommonAPI.h"
#include "string.h"
#include "List.h"
#include "Virusplane.h"

int n=0;
int hp=3;
int jump=0;
int music1;
int music2;
int music3;
int music4;
int music0;
int music5;
int music6;
int g_iGameState = 1;
int g_iCurLevel = 0; // ��ǰ�ؿ�
int g_iRigidBlockCount = 0;
int g_iExitCount = 0;
float countdown;
float  g_fWorldLeft   = -49.f;
float  g_fWorldRight   = 49.f;
float  g_fWorldTop   = -37.f;
float  g_fWorldBottom   =  37.f;
float  g_fVelocityLeft   = 0.f;
float  g_fVelocityRight   =  0.f;
float  g_fVelocityUp   = 0.f;
float  g_fVelocityDown   =  0.f;
const float  g_fGridStartX =  -47.0f;
const float g_fGridStartY =  -34.0f;
const float g_fGridSize =  5.f;
int g_iGridData[GRID_COUNTROW][GRID_COUNTCOL];// ��ά����
int iControlStartX = 0, iControlStartY = 0;

//15ROW��,20COL��
void		GameInit();
void		GameRun( float fDeltaTime );
void        ClsPreSprite();
void        MapSet();
void        SpriteColSet();
void        SpriteHPset(float fDeltaTime);


void GameMainLoop( float	fDeltaTime )
{
    switch( g_iGameState )
    {
    // ��ʼ����Ϸ�������һ���������
    case 1:
    {
        GameInit();
        g_iGameState	=	2; // ��ʼ��֮�󣬽���Ϸ״̬����Ϊ������
    }
    break;

    // ��Ϸ�����У����������Ϸ�߼�
    case 2:
    {
        // TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
        if( 1 )
        {
             GameRun( fDeltaTime );

        }
        else
        {
            // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
           g_iGameState	=	0;
        }
    }
    break;

    // ��Ϸ����/�ȴ����ո����ʼ
    case 0:
    default:
        break;
    };
}


//==============================================================================


//==============================================================================
//
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
void GameInit()
{
    InitTemplateData();
    MapSet();
    if (g_iCurLevel==0)
    {
        dLoadMap("chushi.t2d");
        music0=dPlaySound("chushi.wav",1,1);
    }
    if(g_iCurLevel==1||g_iCurLevel==2)
    {
        dStopSound(music0);
        ClsPreSprite1();
        dLoadMap("one.t2d");
        music1=dPlaySound("senlin.wav",1,1);
        dSetTextValue("hp1",hp);
        SpriteColSet1();
        MakeInitSprite1();
    }
    else if(g_iCurLevel==3||g_iCurLevel==4)
    {
        dStopSound(music1);
        music2=dPlaySound("shidi.wav",1,1);
        ClsPreSprite2();
        dLoadMap("two.t2d");
        dSetTextValue("hp1",hp);
        SpriteColSet2();
        MakeInitSprite2();

    }
    else if(g_iCurLevel==5||g_iCurLevel==6)
    {
        dStopSound(music2);
        music3=dPlaySound("huoshan.wav",1,1);
        ClsPreSprite2();
        ClsPreSprite3();
        dLoadMap("three.t2d");
        dSetTextValue("hp1",hp);
        SpriteColSet3();
        MakeInitSprite3();

    }
    else if(g_iCurLevel==7)
    {
        dStopSound(music3);
        dLoadMap("four.t2d");
        music4=dPlaySound("shamo.wav",1,1);
        SpriteColSet4();
        ClsPreSprite3();
        ClsPreSprite4();
        MakeInitSprite4();
        dSetTextValue("hp1",hp);
    }
    else if(g_iCurLevel==8)
    {
        dStopSound(music3);
        music4=dPlaySound("shamo.wav",1,1);
        dLoadMap("five.t2d");
        dSetTextValue("hp1",hp);
        SpriteColSet4();
        ClsPreSprite4();
        MakeInitSprite4();
    }
    else if(g_iCurLevel==9)
    {
        dLoadMap("shibai.t2d");
        dStopSound(music1);
        dStopSound(music2);
        dStopSound(music3);
        dStopSound(music4);
        music5=dPlaySound("shibai.wav",0,1);
    }
    else if(g_iCurLevel==10)
    {
        dLoadMap("tongguan.t2d");
        dStopSound(music1);
        dStopSound(music2);
        dStopSound(music3);
        dStopSound(music4);
        music6=dPlaySound("tongguan.ogg",1,1);
    }
    else if(g_iCurLevel==11)
    {
        dLoadMap("senlin.t2d");
    }
    else if(g_iCurLevel==12)
    {
        dLoadMap("shidi.t2d");
    }
    else if(g_iCurLevel==13)
    {
        dLoadMap("huoshan.t2d");
    }
    else if(g_iCurLevel==14)
    {
        dLoadMap("shamo.t2d");
    }
    virusinit();
}



//==============================================================================
//

//==============================================================================
// ÿ����Ϸ������

void GameRun( float fDeltaTime )
{
    coljugde();
    SpriteHPset(fDeltaTime);
    blockbarRotation(fDeltaTime);
    longblockbarRotation(fDeltaTime);
    virusrun( fDeltaTime);
}
//==============================================================================

// ����ƶ�
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void OnMouseMove( const float fMouseX, const float fMouseY )
{

}
//==========================================================================
//
// �����
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{

    if(dIsPointInSprite("kaishi",fMouseX,fMouseY)&&g_iCurLevel==0)
    {
        dPlaySound("anniu.ogg",0,1);
        g_iCurLevel=11;
        GameInit();
    }
    if(dIsPointInSprite("wanfa",fMouseX,fMouseY))
    {
        dPlaySound("anniu.ogg",0,1);
        dLoadMap("wanfa.t2d");
    }
    if(dIsPointInSprite("fanhui",fMouseX,fMouseY))
    {
        dPlaySound("anniu.ogg",0,1);
        g_iCurLevel=0;
        GameInit();
    }
    if(dIsPointInSprite("chongkai",fMouseX,fMouseY))
    {
        dStopSound(music5);
        dPlaySound("anniu.ogg",0,1);
        hp=3;
        countdown=0;
        g_iCurLevel=1;
        GameInit();
    }
    if(dIsPointInSprite("fanhui2",fMouseX,fMouseY))
    {
        dStopSound(music5);
        dPlaySound("anniu.ogg",0,1);
        hp=3;
        countdown=0;
        g_iCurLevel=0;
        GameInit();
    }
    if(dIsPointInSprite("qveding",fMouseX,fMouseY))
    {
        dPlaySound("anniu.ogg",0,1);
        hp=3;
        countdown=0;
        g_iCurLevel=0;
        GameInit();
    }
    if(dIsPointInSprite("qveding1",fMouseX,fMouseY))
    {
        dPlaySound("anniu.ogg",0,1);
        g_iCurLevel=1;
        GameInit();
    }
    if(dIsPointInSprite("qveding2",fMouseX,fMouseY))
    {
        dPlaySound("anniu.ogg",0,1);
        g_iCurLevel=3;
        GameInit();
    }
    if(dIsPointInSprite("qveding3",fMouseX,fMouseY))
    {
        dPlaySound("anniu.ogg",0,1);
        g_iCurLevel=5;
        GameInit();
    }
    if(dIsPointInSprite("qveding4",fMouseX,fMouseY))
    {
        dPlaySound("anniu.ogg",0,1);
        g_iCurLevel=7;
        GameInit();
    }

}
//==========================================================================
//
// ��굯��
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{



}
//==========================================================================


//==========================================================================
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{
    // ���¿ո���Ϸ��ʼ
    if( KEY_SPACE == iKey && 0 == g_iGameState )
    {
        g_iGameState = 1;
    }
    else if( 2 == g_iGameState )
    {
        // W A S D �������ƶ����������£���ĳ������ٶȱ�����ֵ
        if( KEY_A == iKey )
            g_fVelocityLeft = -25.f;   // ��
        else if( KEY_D == iKey )
            g_fVelocityRight = 25.f;  // ��
        else if( KEY_W == iKey&&(jump==0||jump==1) )
        {
            g_fVelocityUp = -25.f;   // ��
            jump++;
        }

        else if( KEY_S == iKey )
            g_fVelocityDown = 25.f;   // ��
        if( KEY_J == iKey )
            g_bControlCanFire = true;
    }
    dSetSpriteLinearVelocity("WaterDrop",g_fVelocityLeft + g_fVelocityRight,g_fVelocityUp+ g_fVelocityDown);
    movespriteFlipset();

}
//==========================================================================

void OnKeyUp( const int iKey )
{
    if( 2 == g_iGameState )
    {
        if( KEY_A == iKey )
        {
            g_fVelocityLeft = 0.f;
        }
        else if( KEY_D == iKey )
        {
            g_fVelocityRight = 0.f;
        }
        else if( KEY_W == iKey )
        {
            g_fVelocityUp = 0.f;
        }
        else if( KEY_S == iKey )
        {
            g_fVelocityDown = 0.f;
        }
        if( KEY_J == iKey )
            g_bControlCanFire  =  false;
    }
    dSetSpriteLinearVelocity("WaterDrop",g_fVelocityLeft + g_fVelocityRight,g_fVelocityUp+ g_fVelocityDown);
    movespriteFlipset();

}
//===========================================================================
//

// �����뾫����ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
void OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
    jump=0;
    dSetSpriteCollisionResponse("WaterDrop",COL_RESPONSE_CLAMP);
    OnSpriteColSprite1(szSrcName,szTarName);
    OnSpriteColSprite2(szSrcName,szTarName);
    OnSpriteColSprite3(szSrcName,szTarName);
    OnSpriteColSprite4(szSrcName,szTarName);
    virusspritecolsprite(szSrcName,szTarName);
}
//===========================================================================
//
// ����������߽���ײ
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
    if(g_iCurLevel==1)
    {
        OnfiretreeWorldLimit( szName, iColSide );
    }
    else if(g_iCurLevel==3)
    {
        OnspiderWorldLimit( szName,iColSide );
    }
    else if(g_iCurLevel==7)
    {
        Onclouda1WorldLimit( szName,iColSide );
        Oncloudb2WorldLimit(szName,iColSide);
        clouda3upright(szName,iColSide );
    }
    OnsnakeWorldLimit(szName,iColSide);
   OnotherWorldLimit(szName, iColSide );
    virusworldlimit(szName, iColSide );
}

void MoveSpriteToBlock( const char *szName, const int iIndexX, const int iIndexY )
{
    float fPosX = g_fGridStartX + iIndexX * g_fGridSize;
    float fPosY = g_fGridStartY + iIndexY * g_fGridSize;
    dSetSpritePosition( szName, fPosX, fPosY );
}

int SpritePosXToIndexX ( const float fPosX )
{
    const  float fLeftSide = g_fGridStartX - g_fGridSize / 2.f;
    const  float fRightSide  =  fLeftSide + g_fGridSize * GRID_COUNTCOL;
    if( fPosX < fLeftSide || fPosX > fRightSide )
        return -1;
    int iIndexX = (int)( (fPosX - fLeftSide) / g_fGridSize );
    return iIndexX;
}


int SpriteIndexXToPosX( int iIndexX )
{
    const  float fLeftSide = g_fGridStartX - g_fGridSize / 2.f;
    float fPosX=(iIndexX+1)*g_fGridSize+fLeftSide-g_fGridSize / 2.f;
    return fPosX;
}


int SpritePosYToIndexY( const float fPosY )
{
    const float fTopSide = g_fGridStartY - g_fGridSize / 2.f;
    const float fBottomSide = fTopSide + g_fGridSize * GRID_COUNTROW;
    if( fPosY < fTopSide || fPosY > fBottomSide )
        return -1;
    int iIndexY = (int)( (fPosY - fTopSide) / g_fGridSize );
    return iIndexY;
}

int SpriteIndexYToPosY( int iIndexY )
{
    const float fTopSide = g_fGridStartY - g_fGridSize / 2.f;
    float fPosY=(iIndexY+1)*g_fGridSize+fTopSide-g_fGridSize / 2.f;
    return fPosY;
}


void coljugde()
{
    float fPosX = dGetSpritePositionX( "WaterDrop" );
    float fPosY = dGetSpritePositionY( "WaterDrop" );
    int  iIndexX = SpritePosXToIndexX( fPosX );
    int  iIndexY = SpritePosYToIndexY( fPosY );
    if(( 19 == iIndexX )&&(g_iCurLevel==1)&&(coindeletecount>6))
    {
        g_iGameState = 1;
        g_iCurLevel++;
    }
    else if(g_iCurLevel==3&&(19 == iIndexX)&&(0 == iIndexY))
    {
        g_iGameState = 1;
        g_iCurLevel++;

    }
    else if((0 == iIndexY)&&( 19 == iIndexX )&&(g_iCurLevel==5))
    {
        g_iGameState = 1;
        g_iCurLevel++;
    }
    if(g_iCurLevel==1||g_iCurLevel==2)
        coljugde1(iIndexX,iIndexY);
    else if(g_iCurLevel==3||g_iCurLevel==4)
        coljugde2(iIndexX,iIndexY);
    else if(g_iCurLevel==5||g_iCurLevel==6)
        coljugde3(iIndexX,iIndexY);
    else if(g_iCurLevel==7||g_iCurLevel==8)
        coljugde4(iIndexX,iIndexY);
}



void MapSet()
{
    switch( g_iCurLevel )
    {
    case 2:
    {
        coindeletecount=0;
        iControlStartX = 1;
        iControlStartY = 1;
        memcpy( g_iGridData, m_iLevelData12, sizeof(int) * GRID_COUNTCOL *     GRID_COUNTROW );
    }
    break;
    case 3:
    {
        iControlStartX = 0;
        iControlStartY = 10;
        memcpy( g_iGridData, m_iLevelData21, sizeof(int)  * GRID_COUNTCOL *     GRID_COUNTROW);
    }
    break;
    case 4:
    {
        iControlStartX = 0;
        iControlStartY = 0;
        memcpy( g_iGridData, m_iLevelData22, sizeof(int) * GRID_COUNTCOL *     GRID_COUNTROW );
    }
    break;
    case 5:
    {
        iControlStartX = 0;
        iControlStartY = 10;
        memcpy( g_iGridData, m_iLevelData31, sizeof(int) * GRID_COUNTCOL *     GRID_COUNTROW );
    }
    break;
    case 6:
    {
        iControlStartX = 0;
        iControlStartY = 0;
        memcpy( g_iGridData, m_iLevelData32, sizeof(int) * GRID_COUNTCOL *     GRID_COUNTROW );
    }
    break;
    case 7:
    {
        iControlStartX = 0;
        iControlStartY = 0;
        memcpy( g_iGridData, m_iLevelData41, sizeof(int) * GRID_COUNTCOL *     GRID_COUNTROW );
    }
    break;
    case 8:
    {
        iControlStartX = 0;
        iControlStartY = 3;
        memcpy( g_iGridData, m_iLevelData42, sizeof(int) * GRID_COUNTCOL *     GRID_COUNTROW );
    }
    break;
    case 1:
    default:
    {
        iControlStartX = 1;
        iControlStartY = 13;
        memcpy( g_iGridData, m_iLevelData11, sizeof(int)  * GRID_COUNTCOL *     GRID_COUNTROW);
    }
    break;
    };
}




void SpriteHPset(float fDeltaTime)
{
    if (g_iCurLevel==5||g_iCurLevel==6)
    {
        countdown = fDeltaTime+countdown;
        dSetTextValue("time",countdown);
        if (countdown>=10)
        {
            countdown=0;
            hp--;
            dSetTextValue("hp1",hp);
        }
    }
    if (hp<=0)
    {
        g_iCurLevel=9;
        GameInit();
    }
    else if( hp <2 )
    {
        dSetSpriteColorGreen( "WaterDrop", 0 );
        dSetSpriteColorBlue( "WaterDrop", 0 );
    }
    else if( hp< 3 )
    {
        dSetSpriteColorGreen("WaterDrop", 128 );
        dSetSpriteColorBlue( "WaterDrop", 128 );
    }
    else
    {
        // ����
        dSetSpriteColorGreen( "WaterDrop", 255 );
        dSetSpriteColorBlue( "WaterDrop", 255 );
    }
}

