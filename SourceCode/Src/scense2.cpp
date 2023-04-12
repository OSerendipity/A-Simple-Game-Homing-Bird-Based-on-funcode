#include "CommonAPI.h"
#include "scenseX.h"
#include<stdio.h>

int g_ispiderCount =0;
int g_imushroom2Count=0;
int g_iblockbarCount=0;
int g_iblockCount=0;
int g_ivirusCount=0;
int g_ipotionCount=0;
int g_ijumpblockCount=0;
int g_iblockbarToLeft=0;
float g_fblockbarRotation=0;
int iblockbarstart0 = 0;
int iblockbarstart1 = 0;
int flag=0;
//定义控制地图生成的二维数组
const int m_iLevelData21[GRID_COUNTROW][GRID_COUNTCOL]=
{
    {0,     0,           0,    0,     0,          0,    0,          0,           0,          0,           0,          0,          0,          0,          0,           0,    0, 0, ENTER2,0},
    {0,     0,           0,     0,    0,          0,    0,          0,          0,           0,          0,          0,          0,0,          0, BLOCK,    0, 0,BLOCK, 0},
    {0,     0,           0,     0,HEART,          0,    0,          0,          0,           0,          0,          0,          0,          0,           0,          0, 0, 0, 0},
    {0,     0,0,RIGID_BLOCK,RIGID_BLOCK,RIGID_BLOCK,    0,          0,RIGID_BLOCK,RIGID_BLOCK,         0,0,RIGID_BLOCK,          0,          0,           0,          0, 0, 0, 0},
    {0,     MUSHROOM_TWO,           0,POTION,     0,RIGID_BLOCK,    0,          0,           0,          0,MUSHROOM_TWO,HEART,          0,          0,          0,           0,          0,   0, 0,0},
    {0, BLOCK,           0,    0, BLOCK,          0,    0,          0,           0,      BLOCK,           0,          0,      BLOCK,          0,          0,           0,          0,          0, 0,   0},
    {0,     0,           0,    0,     0,          0,    JUMP_BLOCK, 0,           0,          0,           0,          0,          0,          0,          0,           0,0, 0,          0,     0},
    {0,     0,           0,BLOCK,     0,          0,BLOCK,          0,           0,          0,           0,          0,          0,          0,          0,           0,BLOCK,0,0,0},
    {0,     0,           0,    0,     0,          0,    0,          0,           0,          0,MUSHROOM_TWO,          0,          0,          0,          0,           0,          0, 0, 0, 0},
    {0,     0,           0,    0,     0,          0,    0,          0,           0,          0,MUSHROOM_TWO,          0,          0,      BLOCK,          0,           0,          0, 0, 0, 0},
    {0,     0,           0,    0,     0,          0,    0,          0,           0,          0,MUSHROOM_TWO,          0,          0,          0,          0,           0,          0,          0, 0, 0},
    {0,     0,MUSHROOM_TWO,    0,     0,          0,    0,          0,           0, JUMP_BLOCK,MUSHROOM_TWO,          0,          0,          0,          0,           0,    0,0, 0, 0},
    {0, BLOCK,           0,    0,     0,          SPIDER,    0,          0,           0,      BLOCK,           0,          0,      BLOCK,          0,          0,       BLOCK,    0, 0,0, 0},
    {0,     0,           0,    0,     0,          0,    0,          0,           0,          0,           0,          0,          0,          0,          0,           0,    0, 0, 0, 0},
    {0,     0,           0,    0, BLOCK,          0,    0,      BLOCK,           0,          0,       BLOCK,          0,          0,      BLOCK,          0,           0,BLOCK, 0, 0,BLOCK}
};

const int m_iLevelData22[GRID_COUNTROW][GRID_COUNTCOL]=
{
    {          0,     0,           0,     0,     0,          0,    0,          0,           0,          0,           0,          0,          0,          0,          0,           0,    0, 0, 0,0},
    {RIGID_BLOCK,     0,           0,     0,     0,          0,    0,          0,           0,          0,           0,          0,          0,          0,          0,           0,    0, 0,0, 0},
    {          0,     0,           0,     0,     0,          0,    0,          0,           0,          0,           0,          0,          0,          0,          0,           0, 0, 0, 0},
    {          0,     0,           0,     0,     0,          0,    0,          0,           0,          0,           0,          0,          0,          0,          0,           0,          0, 0, 0, 0},
    {          0,     0,           0,     0,     0,          0,    0,          0,           0,          0,           0,          0,          0,          0,          0,           0,          0,   0, 0,0},
    {          0,     0,           0,     0,     0,          0,    0,          0,           0,          0,           0,          0,          0,          0,          0,           0,          0,          0, 0,   0},
    {          0,     0,           0,     0,     0,          0,    0,          0,           0,          0,           0,          0,          0,          0,          0,           0, 0, 0,          0,     0},
    {          0,     0,           0,     0,     0,          0,    0,          0,           0,          0,           0,          0,          0,          0,          0,           0, 0,0,0,0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,          0, 0, 0, 0},
    {          MUSHROOM_TWO,     0,           0,           BLOCK_BAR,           0,           0,          MUSHROOM_TWO,          0,           0,          0,           0,          0,           0,          0,          0,          BLOCK_BAR,          0, 0, 0, MUSHROOM_TWO},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,          0,           0,          0,           0,          0,          0,           0,          0,          0, 0, 0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,      VIRUS,           0,          0,           0,  0,          0,           0,    0,0, 0, 0},
    {          0,     0,           0,           0,           0,           0,           0,          0,           0,      BLOCK,           0,          0,           0,          0,          0,           0,    0, 0,0, 0},
    {         MUSHROOM_TWO,     MUSHROOM_TWO,           MUSHROOM_TWO,           MUSHROOM_TWO,MUSHROOM_TWO,MUSHROOM_TWO,MUSHROOM_TWO,MUSHROOM_TWO,           0,      BLOCK,           0,          MUSHROOM_TWO,MUSHROOM_TWO,MUSHROOM_TWO,MUSHROOM_TWO,MUSHROOM_TWO, MUSHROOM_TWO, MUSHROOM_TWO, 0, EXIT},
    {          0, BLOCK,           0,           0,       BLOCK,           0,           0,      BLOCK,           0,          0,       BLOCK,          0,           0,      BLOCK,          0,           0,BLOCK, 0, 0,BLOCK}
};


//初始化制造精灵
void MakeInitSprite2()
{
    MakeInitSprite1();
    char* szName = NULL;
    int iLoopX = 0, iLoopY = 0;
    for( iLoopY = 0; iLoopY < GRID_COUNTROW; iLoopY++ )
    {
        for( int iLoopX = 0; iLoopX < GRID_COUNTCOL; iLoopX++ )
        {
            if( 0 == g_iGridData[iLoopY][iLoopX] )
                continue;

            else if( SPIDER == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "spid", g_ispiderCount );
                dCloneSprite( "spid", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_ispiderCount++;
                up_and_rightmove(szName,2,9,10,16);
            }
            else if( MUSHROOM_TWO == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "mushroom2", g_imushroom2Count );
                dCloneSprite( "mushroom2", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_imushroom2Count++;
            }
            else if( BLOCK_BAR == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "blockbar", g_iblockbarCount );
                dCloneSprite( "blockbar", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_iblockbarCount++;
            }
            else if( BLOCK == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "block", g_iblockCount );
                dCloneSprite( "block", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_iblockCount++;
            }
            else if( ENTER2 == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "enter2", g_ienter2Count );
                dCloneSprite( "enter2", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_ienter2Count++;
            }
            else if( POTION == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "potion", g_ipotionCount );
                dCloneSprite( "potion", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_ipotionCount++;
            }
            else if(VIRUS == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "virus", g_ivirusCount );
                dCloneSprite( "virus", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_ivirusCount++;
            }
            else if(JUMP_BLOCK == g_iGridData[iLoopY][iLoopX] )
            {
                szName = dMakeSpriteName( "jumpblock", g_ijumpblockCount );
                dCloneSprite( "jumpblock", szName );
                MoveSpriteToBlock( szName, iLoopX, iLoopY );
                g_ijumpblockCount++;
            }
        }
    }
    if(!flag)
        dSetSpriteVisible( "baohu1", 0 );
    dSetSpriteLinearVelocity( "WaterDrop", 0.f, 0.f );
    MoveSpriteToBlock( "WaterDrop", iControlStartX, iControlStartY );
    dSetSpriteConstantForce("WaterDrop",0,10,0);
}

//判断小水滴位置
void coljugde2(int iIndexX,int iIndexY)
{
    if(( EXIT == g_iGridData[iIndexY][iIndexX] )&&flag)
    {
        // 将游戏状态设置为 1，开始新关卡
        g_iGameState = 1; // 往下一关卡，如果已经是最大值，则返回第一关
        g_iCurLevel=13;
        GameInit();
    }
    if( JUMP_BLOCK == g_iGridData[iIndexY][iIndexX] )
    {
        dSetSpriteLinearVelocityY("WaterDrop",-90.f);
    }

}

//设置碰撞
void SpriteColSet2()
{
    SpriteColSet1();

    //mushroom
    dSetSpriteCollisionReceive("mushroom2",true);
    dSetSpriteCollisionPhysicsReceive("mushroom2",true);
    //heart
    dSetSpriteCollisionReceive("spid",true);
    dSetSpriteCollisionPhysicsReceive("spid",true);
    //firetree
    dSetSpriteCollisionReceive("potion",true);
    dSetSpriteCollisionPhysicsReceive("potion",true);
    //heart
    dSetSpriteCollisionReceive("virus",true);
    dSetSpriteCollisionPhysicsReceive("virus",true);
    //firetree
    dSetSpriteCollisionReceive("blockbar",true);
    dSetSpriteCollisionPhysicsReceive("blockbar",true);
    //firetree
    dSetSpriteCollisionReceive("block",true);
    dSetSpriteCollisionPhysicsReceive("block",true);
}

void OnSpriteColSprite2( const char *szSrcName, const char *szTarName )
{
    if(strstr(szTarName,"heart")&&(g_iCurLevel==3||g_iCurLevel==4))
    {
        dPlaySound("hp+.wav",0,1);
        dDeleteSprite(szTarName);
        hp++;
        dSetTextValue("hp1",hp);
    }
    else if(strstr(szTarName,"mushroom2")&&(g_iCurLevel==3||g_iCurLevel==4))
    {
        hp--;
        dSetTextValue("hp1",hp);
        dPlayEffect("wavebang",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
    }
    else if(strstr(szTarName,"spid")&&(g_iCurLevel==3||g_iCurLevel==4))
    {
        dPlayEffect("wavebang",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
        hp--;
      dSetTextValue("hp1",hp);
    }
    else if(strstr(szTarName,"blockbar0")&&strstr(szSrcName,"WaterDrop")&&(g_iCurLevel==3||g_iCurLevel==4))
    {
        iblockbarstart0=1;
    }
    else if(strstr(szTarName,"blockbar1")&&strstr(szSrcName,"WaterDrop")&&(g_iCurLevel==3||g_iCurLevel==4))
    {
        iblockbarstart1=1;
    }
    else if(strstr(szTarName,"potion")&&(g_iCurLevel==3||g_iCurLevel==4))
    {
        dPlayEffect("shockwave",3.f, dGetSpritePositionX(szSrcName), dGetSpritePositionY(szSrcName), 0.f );
        dPlaySound("hp+.wav",0,1);
        dDeleteSprite(szTarName);
        flag=1;
        dSetSpriteVisible( "baohu1", 1 );
    }
    else if(strstr(szTarName,"virus")&&(g_iCurLevel==3||g_iCurLevel==4))
    {
        dDeleteSprite(szTarName);
        if (flag==0)
        {
            hp=0;
            dPlaySound("baozha.wav",0,1);
        }
        if (flag==1)
        {
            dDeleteSprite("baohu1");
            dPlaySound("baozha.wav",0,1);
            dPlayEffect("enemyExplode",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
            dPlayEffect("bigExplode",3.f, dGetSpritePositionX(szTarName), dGetSpritePositionY(szTarName), 0.f );
        }
    }
}

//清除之前的精灵
void ClsPreSprite2()
{
    ClsPreSprite1();
    int  iLoop = 0;
    char* szName = NULL;
    for( iLoop = 0; iLoop < g_ispiderCount; iLoop++ )
    {
        szName = dMakeSpriteName( "spid", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_ienter2Count; iLoop++ )
    {
        szName = dMakeSpriteName( "enter2", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_imushroom2Count; iLoop++ )
    {
        szName = dMakeSpriteName( "mushroom2", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_iblockbarCount; iLoop++ )
    {
        szName = dMakeSpriteName( "blockbar", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_iblockCount; iLoop++ )
    {
        szName = dMakeSpriteName( "block", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_ivirusCount; iLoop++ )
    {
        szName = dMakeSpriteName( "virus", iLoop );
        dDeleteSprite( szName );
    }
    for( iLoop = 0; iLoop < g_ipotionCount; iLoop++ )
    {
        szName = dMakeSpriteName( "potion", iLoop );
        dDeleteSprite( szName );
    }

    // 总数置 0，重新创建
}

// 控制蜘蛛的上下左右移动
void OnspiderWorldLimit( const char *szName, const int iColSide )
{
    bool	bFlip;
    float	fSpeedX;
    float	fSpeedY;
    float	fPosY;
    if(strstr(szName, "spid"))
    {
        if(iColSide == 1)  // 右边
        {
            bFlip = false;
            fSpeedX = -dRandomRange(10, 15);
            fSpeedY = dRandomRange(-15, 15);	// 随机速度
        }
        else if(iColSide == 0)   // 左边
        {
            bFlip = true;
            fSpeedX = dRandomRange(10, 15);
             //fSpeedY = dRandomRange(10, 15);    // 随机速度
        }
        if(iColSide == 2)  // up边
        {
            bFlip = false;
            fSpeedY = dRandomRange(10, 15);
            fSpeedX = -dRandomRange(10, 15);// 随机速度
        }
        else if(iColSide == 3)   // down边
        {
            bFlip = true;
            fSpeedY = -dRandomRange(15, 20);  // 随机速度
        }
        dSetSpriteFlipX(szName, bFlip);
        dSetSpriteLinearVelocity(szName, fSpeedX, fSpeedY);
        // 每次调头时，位置是随机的
    }

}

//控制木板的旋转
void blockbarRotation(float fDeltaTime)
{
    if(g_iCurLevel==4)
    {
        const  float fRotateSpeed =  30.f;   // 摇摆速度，单位 度/秒
        float fThisRotate = fRotateSpeed * fDeltaTime; // 本次旋转的度数
        if( g_iblockbarToLeft==0)    // ni转动
        {
            g_fblockbarRotation -= fThisRotate;
            if( g_fblockbarRotation <= -35.f )
            {
                g_fblockbarRotation = -35.f;
                g_iblockbarToLeft = 1;
            }
        }
        else           // shun转动
        {
            g_fblockbarRotation += fThisRotate;
            if( g_fblockbarRotation >= 50.f )
            {
                g_fblockbarRotation = 50.f;
                g_iblockbarToLeft = 0;
            }

        }
        if(iblockbarstart0)
        {
            dSetSpriteRotation( "blockbar0", g_fblockbarRotation );
        }
        if(iblockbarstart1)
        {
            dSetSpriteRotation( "blockbar1", g_fblockbarRotation );
        }

    }
}
