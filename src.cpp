/*
*	�t�x�݉ۑ�̃v���O����	j1318_spring.cpp
*
*	����27�N4��20��	J1318	���c����
*
*			4��22��	�v���O�����C��
*						���m���d�Ȃ�����ԂœG��|�����ꍇ, ���m�����̏�ɂƂǂ܂��Ă��܂����
*						�K�E�Z���g�p���Ă�������������Ȃ����
*						���ԕ\���������ɂ������
*			5��28��	�Q�[���o�����X����
*						��(�T�[�o)�ϋv�x�F����C��(100000��1000000)
*						�ŉ��i���m�̃X�^�~�i�F����C��(1000��2000)
*						�ŉ��i�E���i���m�̍U���́F����C��(���ۂ̈ʒu�ɑΉ�)
*						�G�̍U���́E�X�^�~�i�F�Œ�ł͂Ȃ������ɂ���Ĕ��ω�
*						�G�̏o���p�x�F�㏸(1/300��1/250)
*						Lv5���x���A�b�v���̃���������F����(300��400)
*			6��2��	�v���O�����C��
*						���m�������֐��Ɗe�평�����֐��̕�����
*						�X�R�A�\��(�|�[�Y���, �N���A���)
*					�v�f�ǉ�
*						�A�C�e��
*			6��16��	�v���O�����C��
*						���Ԍv�Z, �X�R�A�v�Z���֐���
*						���m�E�G���\��
*						�n�C�X�R�A�\��
*			6��23��	�Q�[���o�����X�C��
*						�K�E�Z�̃���������F�啝����
*
*	<�摜>
*	[�t���[�C���X�g�f��] �N���b�v�A�[�g, �Ɠd�@�� / �Ɠd���i, PC / �p�\�R�� / �R���s���[�^, �f�B�X�v���C / ���j�^, �D�F / �O���[ ID:201310161600 - GATAG�b�t���[�C���X�g�f�ޏW
*		http://free-illustrations.gatag.net/2013/10/16/160000.html
*	aozora biyori | Gallery
*		http://labo.denpa.ac.jp/web-course/15/gal.html
*	�X�|�b�g���C�g�ŏƂ炵���W���� indoor wall decoration �C���X�g�f�� | ai eps �C���X�g���[�^�[
*		http://aieps.blogspot.jp/2014/09/indoor-wall-decoration.html
*	�T�C�o�[�_�C�o�[ �I�t�B�V�����T�C�g
*		http://cyberdiver.jp/support/op_pop.html
*	�T�[�o�[�� Linux �{�b�N�X �N���b�v�A�[�g �x�N�^�[ �N���b�v �A�[�g - �����x�N�^�[
*		http://free-designer.net/archive/entry19219.html
*	GATAG�b�t���[�C���X�g�f�ޏW &raquo; �T�[�o �^�O�̃t�B�[�h
*		http://free-illustrations.gatag.net/tag/�T�[�o
*	640x480 �e�N�X�`�� �ǎ��_�E�����[�h - ���摜, �͗l�̕ǎ�, �e�N�X�`���x�N�g��, �J���t���Ȕw�i, �w�i�f��, �e�N�X�`���ʐ^
*		http://www.anawalls.com/���摜-�͗l�̕ǎ�-�e�N�X�`���x�N�g��-�J���t��/6401221480/
*	�y�f�ށz�Q�[���p�f�� : �Q�[���J�����L
*		http://dvdm.blog134.fc2.com/blog-entry-100.html
*	�ꖇ�G�u�V���v���Q�[���N���A��ʁv - �Q�[���f�[�^/�f�� - Rmake
*		http://rmake.jp/published_items/43507
*
*	<���y>
*	�t���[���y�f��/������
*		http://maoudamashii.jokersounds.com
*/

//////////////////////////////////////////////////////
//
//	KeyBoarDefense Ver. 2.01
//
//	���g�p�L�[
//
//		<���m>
//		Q,W,E,R,T,Y,U,I,O,P
//		 A,S,D,F,G,H,J,K,L
//		  Z,X,C,V,B,N,M
//
//		<���x���A�b�v>
//							[ENTER]
//
//		<�K�E�Z>
//		     [SPACE]
//
//	���g�p������
//
//		<�㋉���m>
//		Q:100,W:90,E:80,R:70,T:60,Y:50,U:40,I:30,O:20,P:10
//
//		<�������m>
//		A:72,S:64,D:56,F:48,G:40,H:32,J:24,K:16,L:8
//
//		<�������m>
//		Z:35,X:30,C:25,V:20,B:15,N:10,M:5
//
//	���A�C�e��
//
//		<���m�X�e�[�^�X�㏸>
//		�E�U���̓A�b�v
//		�E�X�^�~�i�A�b�v
//		�E�X�s�[�h�A�b�v
//
//		<��>
//		�E�T�[�o��
//		�E�������S��
//
//		<���̑�>
//		�E��
//		�E�S����
//
//////////////////////////////////////////////////////

#include "DxLib.h"

/* �y�}�N����`�z */
#define GROUND 400		//�n�ʂ�y���W
#define TARGET_X 580	//�G��
#define USER_X 60		//����
#define MEMORY_Q 100	//�g�p������
#define MEMORY_W 90		//
#define MEMORY_E 80		//
#define MEMORY_R 70		//
#define MEMORY_T 60		//
#define MEMORY_Y 50		//
#define MEMORY_U 40		//
#define MEMORY_I 30		//
#define MEMORY_O 20		//
#define MEMORY_P 10		//
#define MEMORY_A 72		//
#define MEMORY_S 64		//
#define MEMORY_D 56		//
#define MEMORY_F 48		//
#define MEMORY_G 40		//
#define MEMORY_H 32		//
#define MEMORY_J 24		//
#define MEMORY_K 16		//
#define MEMORY_L 8		//
#define MEMORY_Z 35		//
#define MEMORY_X 30		//
#define MEMORY_C 25		//
#define MEMORY_V 20		//
#define MEMORY_B 15		//
#define MEMORY_N 10		//
#define MEMORY_M 5		//

/* �y�\���̌^�z */
struct grData	//�摜�f�[�^
{
	int Back, Title, Title_Start, Title_Menu, Title_Option;
	int Map1, Map2, Map3, Map4, Map5;
	int Pause;
	int Server1, Server2;
	int Cursor, KeyBack, Space;
	int Level, Star, Memory;
	int Wall;
	int ScoreBoard, HighScoreBoard;
	int GameOver, GameClear;
};
struct seData	//���f�[�^
{
	int Start, Select, Decide, Back;
	int KeyPush;
	int Space;
	int LvUp;
	int ItemPut, ItemGet;
	int GameOver, GameClear;
};
struct solData	//���m�f�[�^
{
	int Num, Power, Stamina;
	int Down, Forward;
	int Attack, Attacknum, DAttack;
	int x, y;
	int grp, grpnum;
};
struct eneData	//�G�f�[�^
{
	int Num, Power, Stamina;
	int Attack, Attacknum, DAttack;
	int x;
	int grp, grpnum;
};
struct itemData	//�A�C�e���f�[�^
{
	int Num, x;
};

/* �y�񋓌^�z */
enum eScene		//���
{
	TITLE,
	SELECT,
	MAINGAME,
	PAUSE,
	GAMEOVER,
	GAMECLEAR
};
enum eTitle		//�^�C�g�����
{
	START,
	MENU,
	OPTION
};
enum eSelect	//�}�b�v�I��
{
	MONITOR,
	NOTE,
	DESK,
	CYBER,
	CMD
};
enum eSolnum	//���m�ԍ�
{
	Q,W,E,R,T,Y,U,I,O,P,
	A,S,D,F,G,H,J,K,L,
	Z,X,C,V,B,N,M,
	SP
};
enum eItem
{
	EMPTY,
	POWER,
	STAMINA,
	SPEED,
	SERVER,
	MEMORY,
	WALL,
	ALL
};

/* �y�O���[�o���ϐ��z */
struct grData grp = {0};		//�摜�f�[�^
struct seData se = {0};			//���f�[�^
struct solData sol[20];			//���m�f�[�^
struct eneData ene[20];			//�G�f�[�^
struct itemData item[3];		//�A�C�e���f�[�^
int winMode = 1;				//�E�B���h�E���[�h(1:�E�B���h�E, 0:�t���X�N���[��)
int exitFlag = 0;				//�\�t�g�I���t���O
int scene = TITLE;				//���
int map = MONITOR;				//�}�b�v
int starttime, time;			//����
int loopcount = 0;				//�A�\�r�p�J�E���^�[
int spFlag = 0, space_y;		//�K�E�Z
int memory, memory_max;			//������
int lv;							//���x��
int life, enemy_life;			//���C�t
int music = 1;					//���y
int putitem;					//�A�C�e���o���t���O
int effect_power, effect_stamina, effect_speed;	//�A�C�e������
int wall_count = 0;				//�ǃJ�E���^�[
int wall_num;					//�ǔԍ�
int solcount, enecount;			//���m�J�E���^�[
int score, highscore = 0;		//�n�C�X�R�A
int key_QWER[16], key_TYUI[16], key_OPAS[16], key_DFGH[16], key_JKLZ[16], key_XCVB[16], key_NM[16];	//�������m�摜
int enemy[16];					//�����G�摜
int itemgrp[7];					//�����A�C�e���摜
int statuslv[3];				//�����X�e�[�^�XLv�摜
int solene[2];					//�������m�E�G���摜
char Key[256];					//�L�[���͏��

/* �y�֐��v���g�^�C�v�z */
void InitGrp();					//������
void InitSe();					//
void StartInit();				//
void SolInit();					//
void EneInit();					//
void ItemInit();				//
void Input();					//����
void Fullscreen();				//�X�N���[���؂�ւ�
void Title();					//��ʁF�^�C�g��
void Title_Draw( int, int );	//�`��F�^�C�g��
void Select();					//��ʁF�}�b�v�I��
void Select_Draw();				//�`��F�}�b�v�I��
void Maingame();				//��ʁF���C���Q�[��
void Calc();					//
void MemoryRecovery();			//
void CheckKey();				//
void LvUp();					//
void Special();					//
int MemoryCheck( int );			//
void PutSol( int );				//
void PutEne();					//
void PutItem();					//
int KeyDef_X( int, int );		//
int KeyDef_Y( int, int );		//
void SolCheck();				//
void AttackCheck();				//
void DownMoveSol();				//
void ForwardMoveSol();			//
void EnemyMove();				//
void GetItem();					//
void EffectItem( int );			//
void Wall();					//
void Attack();					//
void ExistJudge();				//
void LifeJudge();				//
void MainGame_Draw();			//�`��F���C���Q�[��
void Pause();					//��ʁF�|�[�Y
void Gameover();				//��ʁF�Q�[���I�[�o�[
void Gameclear();				//��ʁF�Q�[���N���A
void PlayMusic( int );			//���y�Đ�

/* �y���C���֐��z */
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	SetGraphMode( 640 , 480 , 16 );					//��ʃ��[�h�̃Z�b�g
	SetOutApplicationLogValidFlag(false);			//Log.txt�̏o�͂�}��
	SetMainWindowText( "KeyBoarDefense" );			//�^�C�g���o�[�̕ύX
	ChangeWindowMode( winMode );					//�E�B���h�E���[�h�ŋN��
	if( DxLib_Init() == -1 )						//�c�w���C�u��������������
	{
		return -1;
	}
	InitGrp();										//�摜�f�[�^�̃��[�h
	InitSe();										//���ʉ��f�[�^�̃��[�h

	StartInit();										//�e���񏉊���
	SolInit();										//���m��񏉊���
	EneInit();										//�G��񏉊���
	ItemInit();										//�A�C�e����񏉊���

	PlayMusic( 0 );									//���y�Đ�

	while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 && exitFlag == 0 )
	{
		Input();			//����
		ClearDrawScreen();	//��ʃN���A

		switch( scene )		//��ʕ���
		{
		case TITLE:			//�^�C�g��
			Title();
			break;
		case SELECT:		//�}�b�v�I��
			Select();
			break;
		case MAINGAME:		//���C���Q�[��
			Maingame();
			break;
		case PAUSE:			//�|�[�Y���
			Pause();
			break;
		case GAMEOVER:		//�Q�[���I�[�o�[
			Gameover();
			break;
		case GAMECLEAR:		//�Q�[���N���A
			Gameclear();
			break;
		}
		ScreenFlip();		//����ʏo��

		loopcount++;		//�J�E���g
		if( loopcount > 10000 )
			loopcount = 1;
	}

	DxLib_End();			//DX���C�u�����I������
	return 0;
}

/* �y�֐��z�摜�ǂݍ��� */
void InitGrp()
{
	SetDrawScreen( DX_SCREEN_BACK );				//����ʐݒ�
	SetTransColor( 0, 255, 0 );						//���ߐF�̕ύX
	grp.Back = LoadGraph( "KeyBoarDefense_Data/Graphic/back.png" );
	grp.Title = LoadGraph( "KeyBoarDefense_Data/Graphic/back_title.png" );
	grp.Title_Start = LoadGraph( "KeyBoarDefense_Data/Graphic/back_start.png" );
	grp.Title_Menu = LoadGraph( "KeyBoarDefense_Data/Graphic/back_menu.png" );
	grp.Title_Option = LoadGraph( "KeyBoarDefense_Data/Graphic/back_option.png" );
	grp.Map1 = LoadGraph( "KeyBoarDefense_Data/Graphic/map01.jpg" );
	grp.Map2 = LoadGraph( "KeyBoarDefense_Data/Graphic/map02.jpg" );
	grp.Map3 = LoadGraph( "KeyBoarDefense_Data/Graphic/map03.jpg" );
	grp.Map4 = LoadGraph( "KeyBoarDefense_Data/Graphic/map04.jpg" );
	grp.Map5 = LoadGraph( "KeyBoarDefense_Data/Graphic/map05.jpg" );
	grp.Pause = LoadGraph( "KeyBoarDefense_Data/Graphic/pause.jpg" );
	grp.Server1 = LoadGraph( "KeyBoarDefense_Data/Graphic/server01.png" );
	grp.Server2 = LoadGraph( "KeyBoarDefense_Data/Graphic/server02.png" );
	grp.Cursor = LoadGraph( "KeyBoarDefense_Data/Graphic/cursor.png" );
	grp.KeyBack = LoadGraph( "KeyBoarDefense_Data/Graphic/keyback.png" );
	grp.Space = LoadGraph( "KeyBoarDefense_Data/Graphic/space.png" );
	grp.Level = LoadGraph( "KeyBoarDefense_Data/Graphic/level.png" );
	grp.Star = LoadGraph( "KeyBoarDefense_Data/Graphic/star.png" );
	grp.Memory = LoadGraph( "KeyBoarDefense_Data/Graphic/memory.png" );
	grp.Wall = LoadGraph( "KeyBoarDefense_Data/Graphic/wall.png" );
	grp.GameOver = LoadGraph( "KeyBoarDefense_Data/Graphic/gameover.png" );
	grp.GameClear = LoadGraph( "KeyBoarDefense_Data/Graphic/gameclear.png" );
	grp.ScoreBoard = LoadGraph( "KeyBoarDefense_Data/Graphic/scoreboard.png" );
	grp.HighScoreBoard = LoadGraph( "KeyBoarDefense_Data/Graphic/highscoreboard.png" );
	LoadDivGraph( "KeyBoarDefense_Data/Graphic/key01.png", 16, 4, 4, 32, 32, key_QWER );
	LoadDivGraph( "KeyBoarDefense_Data/Graphic/key02.png", 16, 4, 4, 32, 32, key_TYUI );
	LoadDivGraph( "KeyBoarDefense_Data/Graphic/key03.png", 16, 4, 4, 32, 32, key_OPAS );
	LoadDivGraph( "KeyBoarDefense_Data/Graphic/key04.png", 16, 4, 4, 32, 32, key_DFGH );
	LoadDivGraph( "KeyBoarDefense_Data/Graphic/key05.png", 16, 4, 4, 32, 32, key_JKLZ );
	LoadDivGraph( "KeyBoarDefense_Data/Graphic/key06.png", 16, 4, 4, 32, 32, key_XCVB );
	LoadDivGraph( "KeyBoarDefense_Data/Graphic/key07.png", 16, 4, 4, 32, 32, key_NM );
	LoadDivGraph( "KeyBoarDefense_Data/Graphic/enemy.png", 16, 4, 4, 32, 32, enemy );
	LoadDivGraph( "KeyBoarDefense_Data/Graphic/item.png", 7, 7, 1, 30, 30, itemgrp );
	LoadDivGraph( "KeyBoarDefense_Data/Graphic/statuslv.png", 3, 1, 3, 150, 30, statuslv );
	LoadDivGraph( "KeyBoarDefense_Data/Graphic/solene.png", 2, 1, 2, 100, 30, solene );
}

/* �y�֐��z���ǂݍ��� */
void InitSe()
{
	se.Start = LoadSoundMem( "KeyBoarDefense_Data/Sound/start.wav" );
	se.Select = LoadSoundMem( "KeyBoarDefense_Data/Sound/select.wav" );
	se.Decide = LoadSoundMem( "KeyBoarDefense_Data/Sound/decide.wav" );
	se.Back = LoadSoundMem( "KeyBoarDefense_Data/Sound/back.wav" );
	se.KeyPush = LoadSoundMem( "KeyBoarDefense_Data/Sound/keypush.wav" );
	se.Space = LoadSoundMem( "KeyBoarDefense_Data/Sound/space.wav" );
	se.LvUp = LoadSoundMem( "KeyBoarDefense_Data/Sound/lvup.wav" );
	se.ItemPut = LoadSoundMem( "KeyBoarDefense_Data/Sound/itemput.wav" );
	se.ItemGet = LoadSoundMem( "KeyBoarDefense_Data/Sound/itemget.wav" );
	se.GameOver = LoadSoundMem( "KeyBoarDefense_Data/Sound/gameover.wav" );
	se.GameClear = LoadSoundMem( "KeyBoarDefense_Data/Sound/gameclear.wav" );
}

/* �y�֐��z�e���񏉊��� */
void StartInit()
{
	memory_max = 100;		//�ő僁����

	memory = memory_max;	//������

	lv = 1;					//���x��

	life = 1000000;			//�������C�t

	enemy_life = 1000000;	//�G���C�t

	space_y = 231;			//�K�E�Z

	putitem = 1;
}

/* �y�֐��z���m��񏉊��� */
void SolInit()
{
	int i;

	for( i = 0; i < 20; i++ )
	{
		sol[i].Num = -1;
		sol[i].Down = 0;
		sol[i].Forward = 0;
		sol[i].Attack = 0;
		sol[i].Attacknum = 0;
		sol[i].DAttack = 0;
		sol[i].x = 0;
		sol[i].y = 0;
	}
}

/* �y�֐��z�G��񏉊��� */
void EneInit()
{
	int i;

	for( i = 0; i < 20; i++ )
	{
		ene[i].Num = -1;
		ene[i].Attack = 0;
		ene[i].Attacknum = 0;
		ene[i].DAttack = 0;
		ene[i].x = 0;
	}
}

/* �y�֐��z�A�C�e����񏉊��� */
void ItemInit()
{
	int i;

	for( i = 0; i < 3; i++ )
		item[i].Num = EMPTY;//���e

	item[0].x = 110;		//���W
	item[1].x = 330;		//
	item[2].x = 480;		//

	putitem = 1;

	effect_power = 0;		//�U���͋���
	effect_stamina = 0;		//�X�^�~�i����
	effect_speed = 0;		//�X�s�[�h����
	wall_count = 0;			//��
}

/* �y�֐��z���� */
void Input()
{
	GetHitKeyStateAll( Key );	//���ׂẴL�[�����擾
}

/* �y�֐��z�X�N���[�����[�h�؂�ւ� */
void Fullscreen()
{	
	if ( winMode == 1 )
		winMode = 0;
	else
		winMode = 1;
	ChangeWindowMode( winMode );
	InitGrp();
}

/* �y�֐��z�^�C�g�� */
void Title()
{
	static int titlescene = START;		//�^�C�g���ł̏��
	static int menu = 0;				//�J�[�\���l

	if( titlescene == START )			//�X�^�[�g���
	{
		if( Key[ KEY_INPUT_RETURN ] )
		{
			titlescene = MENU;
			PlaySoundMem( se.Start, DX_PLAYTYPE_NORMAL );
		}
	}
	else if( titlescene == MENU )		//���j���[���
	{
		if( Key[ KEY_INPUT_RETURN ] )
		{
			switch( menu )
			{
			case 0:						//SELECT
				scene = SELECT;
				break;
			case 1:						//OPTION
				titlescene = OPTION;
				menu = 0;
				break;
			case 2:						//EXIT
				exitFlag = 1;
				break;
			}
			PlaySoundMem( se.Decide, DX_PLAYTYPE_NORMAL );
		}
		else if( Key[ KEY_INPUT_UP ] )
		{
			menu--;
			if( menu < 0 )
				menu = 2;
			PlaySoundMem( se.Select, DX_PLAYTYPE_NORMAL );
		}
		else if( Key[ KEY_INPUT_DOWN ] )
		{
			menu++;
			if( menu > 2 )
				menu = 0;
			PlaySoundMem( se.Select, DX_PLAYTYPE_NORMAL );
		}
	}
	else if( titlescene == OPTION )		//�I�v�V�������
	{
		if( Key[ KEY_INPUT_RETURN ] )
		{
			switch( menu )
			{
			case 0:						//�t���X�N���[��
				Fullscreen();
				break;
			case 1:						//���y
				music++;
				if( music > 3 )
					music = 0;
				PlayMusic( 1 );
				break;
			case 2:						//BACK
				titlescene = MENU;
				menu = 0;
				PlayMusic( 0 );
				break;
			}
			PlaySoundMem( se.Decide, DX_PLAYTYPE_NORMAL );
		}
		else if( Key[ KEY_INPUT_UP ] )
		{
			menu--;
			if( menu < 0 )
				menu = 2;
			PlaySoundMem( se.Select, DX_PLAYTYPE_NORMAL );
		}
		else if( Key[ KEY_INPUT_DOWN ] )
		{
			menu++;
			if( menu > 2 )
				menu = 0;
			PlaySoundMem( se.Select, DX_PLAYTYPE_NORMAL );
		}
	}

	Title_Draw( titlescene, menu );		//�`��
}

/* �y�֐��z�^�C�g���`�� */
void Title_Draw( int titlescene, int menu )
{
	DrawGraph( 0, 0, grp.Back, false );							//�ǎ�
	DrawGraph( 0, 0, grp.Title, true );							//�^�C�g�����S
	switch( titlescene )										//�w�i�摜
	{
	case START:
		DrawGraph( 0, 0, grp.Title_Start, true );
		break;
	case MENU:
		DrawGraph( 0, 0, grp.Title_Menu, true );
		break;
	case OPTION:
		DrawGraph( 0, 0, grp.Title_Option, true );
		break;
	}

	if( titlescene )
		DrawGraph( 450, 250 + (45 * menu), grp.Cursor, true );	//�J�[�\��
}

/* �y�֐��z�}�b�v�I�� */
void Select()
{
	if( Key[ KEY_INPUT_RETURN ] )
	{
		scene = MAINGAME;
		starttime = GetNowCount();
		PlaySoundMem( se.Decide, DX_PLAYTYPE_NORMAL );
		PlayMusic( 0 );
	}
	else if( Key[ KEY_INPUT_RIGHT ] )
	{
		map++;
		if( map > 4 )
			map = 0;
		PlaySoundMem( se.Select, DX_PLAYTYPE_NORMAL );
	}
	else if( Key[ KEY_INPUT_LEFT ] )
	{
		map--;
		if( map < 0 )
			map = 4;
		PlaySoundMem( se.Select, DX_PLAYTYPE_NORMAL );
	}

	Select_Draw();	//�`��
}

/* �y�֐��z�}�b�v�I��`�� */
void Select_Draw()
{
	static int num = 0;

	switch( map )	//�w�i�摜
	{
	case MONITOR:
		DrawGraph( 0, 0, grp.Map1, false );
		break;
	case NOTE:
		DrawGraph( 0, 0, grp.Map2, false );
		break;
	case DESK:
		DrawGraph( 0, 0, grp.Map3, false );
		break;
	case CYBER:
		DrawGraph( 0, 0, grp.Map4, false );
		break;
	case CMD:
		DrawGraph( 0, 0, grp.Map5, false );
		break;
	}

	DrawTriangle( 0 + num, 240, 40 + num, 220, 40 + num,  260, GetColor( 200, 200, 200 ), true );
	DrawTriangle( 640 - num, 240, 600 - num, 220, 600 - num, 260, GetColor( 200, 200, 200 ), true );

	num--;
	if( num < 0 )
		num = 10;
}

/* �y�֐��z���C���Q�[�� */
void Maingame()
{
	Calc();				//�v�Z

	MemoryRecovery();	//��������

	CheckKey();			//�L�[���͊m�F

	PutEne();			//�G�o��

	PutItem();			//�A�C�e���o��

	SolCheck();			//���m�̏�Ԋm�F

	AttackCheck();		//�U����Ԋm�F

	DownMoveSol();		//���m�ړ�(���~)

	ForwardMoveSol();	//���m�ړ�(�O�i)

	EnemyMove();		//�G�ړ�

	GetItem();			//�A�C�e���擾
	
	Wall();				//�Ǐ���

	Attack();			//�U��

	if( spFlag )
		Special();		//�K�E�Z

	ExistJudge();		//���ݔ���

	LifeJudge();		//���s����

	MainGame_Draw();	//�`��
}

/* �y�֐��z�v�Z */
void Calc()
{
	int i;

	time = GetNowCount() - starttime;	//���Ԍv�Z

	score = ( life - time ) / 100;		//�X�R�A�v�Z

	solcount = 0;						//���m��������
	enecount = 0;						//�G��������
	for( i = 0; i < 20; i++ )
	{
		if( sol[i].Num >= 0 )
			solcount++;					//���m���J�E���g
		if( ene[i].Num >= 0 )
			enecount++;					//�G���J�E���g
	}
}

/* �y�֐��z�������� */
void MemoryRecovery()
{
	if( memory < memory_max && loopcount % 10 == 0 )	//���������ő�l��菬�������A�\�r
	{
		memory += lv;	//���x���̒l�������Z�����
		if( memory > memory_max )
			memory = memory_max;
	}
}

/* �y�֐��z�L�[���͊m�F */
void CheckKey()
{
	if( Key[ KEY_INPUT_RETURN ] && ( lv == 1 && memory >= 50 || lv == 2 && memory >= 100 || lv == 3 && memory >= 200 || lv == 4 && memory >= 400 ) )	//���x���A�b�v
		LvUp();

	if( Key[ KEY_INPUT_SPACE ] && !( spFlag ) && space_y + 32 <= GROUND && MemoryCheck( SP ) )	//�K�E�Z
	{
		memory -= 20 * lv;
		spFlag = 1;
		PlaySoundMem( se.KeyPush, DX_PLAYTYPE_BACK );
	}

	if( Key[ KEY_INPUT_TAB ] )			//�|�[�Y���
	{
		scene = PAUSE;
		PlaySoundMem( se.Back, DX_PLAYTYPE_NORMAL );
	}

	if( Key[ KEY_INPUT_Q ] && MemoryCheck( Q ) )
		PutSol( Q );
	else if( Key[ KEY_INPUT_W ] && MemoryCheck( W ) )
		PutSol( W );
	else if( Key[ KEY_INPUT_E ] && MemoryCheck( E ) )
		PutSol( E );
	else if( Key[ KEY_INPUT_R ] && MemoryCheck( R ) )
		PutSol( R );
	else if( Key[ KEY_INPUT_T ] && MemoryCheck( T ) )
		PutSol( T );
	else if( Key[ KEY_INPUT_Y ] && MemoryCheck( Y ) )
		PutSol( Y );
	else if( Key[ KEY_INPUT_U ] && MemoryCheck( U ) )
		PutSol( U );
	else if( Key[ KEY_INPUT_I ] && MemoryCheck( I ) )
		PutSol( I );
	else if( Key[ KEY_INPUT_O ] && MemoryCheck( O ) )
		PutSol( O );
	else if( Key[ KEY_INPUT_P ] && MemoryCheck( P ) )
		PutSol( P );
	else if( Key[ KEY_INPUT_A ] && MemoryCheck( A ) )
		PutSol( A );
	else if( Key[ KEY_INPUT_S ] && MemoryCheck( S ) )
		PutSol( S );
	else if( Key[ KEY_INPUT_D ] && MemoryCheck( D ) )
		PutSol( D );
	else if( Key[ KEY_INPUT_F ] && MemoryCheck( F ) )
		PutSol( F );
	else if( Key[ KEY_INPUT_G ] && MemoryCheck( G ) )
		PutSol( G );
	else if( Key[ KEY_INPUT_H ] && MemoryCheck( H ) )
		PutSol( H );
	else if( Key[ KEY_INPUT_J ] && MemoryCheck( J ) )
		PutSol( J );
	else if( Key[ KEY_INPUT_K ] && MemoryCheck( K ) )
		PutSol( K );
	else if( Key[ KEY_INPUT_L ] && MemoryCheck( L ) )
		PutSol( L );
	else if( Key[ KEY_INPUT_Z ] && MemoryCheck( Z ) )
		PutSol( Z );
	else if( Key[ KEY_INPUT_X ] && MemoryCheck( X ) )
		PutSol( X );
	else if( Key[ KEY_INPUT_C ] && MemoryCheck( C ) )
		PutSol( C );
	else if( Key[ KEY_INPUT_V ] && MemoryCheck( V ) )
		PutSol( V );
	else if( Key[ KEY_INPUT_B ] && MemoryCheck( B ) )
		PutSol( B );
	else if( Key[ KEY_INPUT_N ] && MemoryCheck( N ) )
		PutSol( N );
	else if( Key[ KEY_INPUT_M ] && MemoryCheck( M ) )
		PutSol( M );
}

/* �y�֐��z���x���A�b�v */
void LvUp()
{
	if( lv < 5 )
	{
		lv++;

		switch( lv )
		{
		case 2:
			memory -= 50;
			memory_max = 200;
			break;
		case 3:
			memory -= 100;
			memory_max = 500;
			break;
		case 4:
			memory -= 200;
			memory_max = 700;
			break;
		case 5:
			memory -= 400;
			memory_max = 1000;
			break;
		}

		space_y = 231;	//�K�E�Z���ēx������悤�ɂ���

		PlaySoundMem( se.LvUp, DX_PLAYTYPE_BACK );
	}
}

/* �y�֐��z�K�E�Z */
void Special()
{
	int i;

	space_y += 10;

	if( space_y + 32 > GROUND )
	{
		for( i = 0; i < 20; i++ )
		{
			if( ene[i].x + 32 > 160 && ene[i].x < 160 + 128 )
			{
				ene[i].Stamina = 0;
				PlaySoundMem( se.Space, DX_PLAYTYPE_NORMAL );
			}
		}
		spFlag = 0;
	}
}

/* �y�֐��z�������m�F */
int MemoryCheck( int key )	//�����F�m�F����L�[�ԍ�
{
	switch( key )
	{
	case Q:
		if( memory >= MEMORY_Q )
			return 1;
		else
			return 0;
	case W:
		if( memory >= MEMORY_W )
			return 1;
		else
			return 0;
	case E:
		if( memory >= MEMORY_E )
			return 1;
		else
			return 0;
	case R:
		if( memory >= MEMORY_R )
			return 1;
		else
			return 0;
	case T:
		if( memory >= MEMORY_T )
			return 1;
		else
			return 0;
	case Y:
		if( memory >= MEMORY_Y )
			return 1;
		else
			return 0;
	case U:
		if( memory >= MEMORY_U )
			return 1;
		else
			return 0;
	case I:
		if( memory >= MEMORY_I )
			return 1;
		else
			return 0;
	case O:
		if( memory >= MEMORY_O )
			return 1;
		else
			return 0;
	case P:
		if( memory >= MEMORY_P )
			return 1;
		else
			return 0;
	case A:
		if( memory >= MEMORY_A )
			return 1;
		else
			return 0;
	case S:
		if( memory >= MEMORY_S )
			return 1;
		else
			return 0;
	case D:
		if( memory >= MEMORY_D )
			return 1;
		else
			return 0;
	case F:
		if( memory >= MEMORY_F )
			return 1;
		else
			return 0;
	case G:
		if( memory >= MEMORY_G )
			return 1;
		else
			return 0;
	case H:
		if( memory >= MEMORY_H )
			return 1;
		else
			return 0;
	case J:
		if( memory >= MEMORY_J )
			return 1;
		else
			return 0;
	case K:
		if( memory >= MEMORY_K )
			return 1;
		else
			return 0;
	case L:
		if( memory >= MEMORY_L )
			return 1;
		else
			return 0;
	case Z:
		if( memory >= MEMORY_Z )
			return 1;
		else
			return 0;
	case X:
		if( memory >= MEMORY_X )
			return 1;
		else
			return 0;
	case C:
		if( memory >= MEMORY_C )
			return 1;
		else
			return 0;
	case V:
		if( memory >= MEMORY_V )
			return 1;
		else
			return 0;
	case B:
		if( memory >= MEMORY_B )
			return 1;
		else
			return 0;
	case N:
		if( memory >= MEMORY_N )
			return 1;
		else
			return 0;
	case M:
		if( memory >= MEMORY_M )
			return 1;
		else
			return 0;
	case SP:
		if( memory >= 20 * lv )
			return 1;
		else
			return 0;
	}
}

/* �y�֐��z���m�o�� */
void PutSol( int key )	//�����F�L�[�ԍ�
{
	int i;

	for( i = 0; i < 20; i++ )
	{
		if( sol[i].Num == -1 )
		{
			sol[i].Num = key;

			sol[i].x = KeyDef_X( sol[i].Num, 0 );	//���m�̏������W���`
			sol[i].y = KeyDef_Y( sol[i].Num, 0 );	//

			switch( sol[i].Num )
			{
			case Q:
				sol[i].Power = 50 + effect_power;
				sol[i].Stamina = 5000 + effect_stamina;
				memory -= MEMORY_Q;
				break;
			case W:
				sol[i].Power = 45 + effect_power;
				sol[i].Stamina = 5000 + effect_stamina;
				memory -= MEMORY_W;
				break;
			case E:
				sol[i].Power = 40 + effect_power;
				sol[i].Stamina = 5000 + effect_stamina;
				memory -= MEMORY_E;
				break;
			case R:
				sol[i].Power = 35 + effect_power;
				sol[i].Stamina = 5000 + effect_stamina;
				memory -= MEMORY_R;
				break;
			case T:
				sol[i].Power = 30 + effect_power;
				sol[i].Stamina = 5000 + effect_stamina;
				memory -= MEMORY_T;
				break;
			case Y:
				sol[i].Power = 25 + effect_power;
				sol[i].Stamina = 5000 + effect_stamina;
				memory -= MEMORY_Y;
				break;
			case U:
				sol[i].Power = 20 + effect_power;
				sol[i].Stamina = 5000 + effect_stamina;
				memory -= MEMORY_U;
				break;
			case I:
				sol[i].Power = 15 + effect_power;
				sol[i].Stamina = 5000 + effect_stamina;
				memory -= MEMORY_I;
				break;
			case O:
				sol[i].Power = 10 + effect_power;
				sol[i].Stamina = 5000 + effect_stamina;
				memory -= MEMORY_O;
				break;
			case P:
				sol[i].Power = 5 + effect_power;
				sol[i].Stamina = 5000 + effect_stamina;
				memory -= MEMORY_P;
				break;
			case A:
				sol[i].Power = 48 + effect_power;
				sol[i].Stamina = 3000 + effect_stamina;
				memory -= MEMORY_A;
				break;
			case S:
				sol[i].Power = 43 + effect_power;
				sol[i].Stamina = 3000 + effect_stamina;
				memory -= MEMORY_S;
				break;
			case D:
				sol[i].Power = 38 + effect_power;
				sol[i].Stamina = 3000 + effect_stamina;
				memory -= MEMORY_D;
				break;
			case F:
				sol[i].Power = 33 + effect_power;
				sol[i].Stamina = 3000 + effect_stamina;
				memory -= MEMORY_F;
				break;
			case G:
				sol[i].Power = 28 + effect_power;
				sol[i].Stamina = 3000 + effect_stamina;
				memory -= MEMORY_G;
				break;
			case H:
				sol[i].Power = 23 + effect_power;
				sol[i].Stamina = 3000 + effect_stamina;
				memory -= MEMORY_H;
				break;
			case J:
				sol[i].Power = 18 + effect_power;
				sol[i].Stamina = 3000 + effect_stamina;
				memory -= MEMORY_J;
				break;
			case K:
				sol[i].Power = 13 + effect_power;
				sol[i].Stamina = 3000 + effect_stamina;
				memory -= MEMORY_K;
				break;
			case L:
				sol[i].Power = 8 + effect_power;
				sol[i].Stamina = 3000 + effect_stamina;
				memory -= MEMORY_L;
				break;
			case Z:
				sol[i].Power = 42 + effect_power;
				sol[i].Stamina = 2000 + effect_stamina;
				memory -= MEMORY_Z;
				break;
			case X:
				sol[i].Power = 37 + effect_power;
				sol[i].Stamina = 2000 + effect_stamina;
				memory -= MEMORY_X;
				break;
			case C:
				sol[i].Power = 32 + effect_power;
				sol[i].Stamina = 2000 + effect_stamina;
				memory -= MEMORY_C;
				break;
			case V:
				sol[i].Power = 27 + effect_power;
				sol[i].Stamina = 2000 + effect_stamina;
				memory -= MEMORY_V;
				break;
			case B:
				sol[i].Power = 22 + effect_power;
				sol[i].Stamina = 2000 + effect_stamina;
				memory -= MEMORY_B;
				break;
			case N:
				sol[i].Power = 17 + effect_power;
				sol[i].Stamina = 2000 + effect_stamina;
				memory -= MEMORY_N;
				break;
			case M:
				sol[i].Power = 12 + effect_power;
				sol[i].Stamina = 2000 + effect_stamina;
				memory -= MEMORY_M;
				break;
			}

			PlaySoundMem( se.KeyPush, DX_PLAYTYPE_NORMAL );

			break;
		}
	}
}

/* �y�֐��z�G�o�� */
void PutEne()
{
	int i, r1, r2, r3;
	static int num = 0;

	r1 = GetRand( 250 );		//0-250�̗����擾

	if( r1 == 0 )
	{
		for( i = 0; i < 20; i++ )
		{
			if( ene[i].Num == -1 )
			{
				r2 = GetRand( 9 );	//0-9�̗����擾
				r3 = GetRand( 5 );	//0-5�̗����擾

				switch( r2 )
				{
				case 0:
				case 1:
				case 2:
				case 3:
				case 4:				//1/5�̊m��
					ene[i].Num = 0;
					ene[i].x = TARGET_X;
					ene[i].Power = 10 + r3 * 2;
					ene[i].Stamina = 3000 + r3 * 100;
					ene[i].grp = enemy[0 + num];
					break;
				case 5:
				case 6:
				case 7:
				case 8:				//2/5�̊m��
					ene[i].Num = 1;
					ene[i].x = TARGET_X;
					ene[i].Power = 20 + r3 * 2;
					ene[i].Stamina = 5000 + r3 * 100;
					ene[i].grp = enemy[4 + num];
					break;
				case 9:				//1/10�̊m��
					ene[i].Num = 2;
					ene[i].x = TARGET_X;
					ene[i].Power = 50 + r3 * 2;
					ene[i].Stamina = 10000 + r3 * 100;
					ene[i].grp = enemy[8 + num];
					break;
				}
				break;
			}
		}
	}
}

/* �y�֐��z�A�C�e���o�� */
void PutItem()
{
	int r_exis, r_pos, r_eff;

	r_exis = GetRand( 500 );	//0-500�̗����擾

	if( r_exis == 0 && putitem )
	{
		do{
			r_pos = GetRand( 2 );	//0-2�̗����擾
		}while( wall_count && r_pos == wall_num );

		r_eff = GetRand( 6 );	//0-6�̗����擾

		item[ r_pos ].Num = r_eff + 1;	//�A�C�e������

		putitem = 0;			//�A�C�e���o���t���O

		PlaySoundMem( se.ItemPut, DX_PLAYTYPE_BACK );
	}
}

/* �y�֐��z�L�[���W��` */
int KeyDef_X( int key, int back )	//�����F�L�[�ԍ�, �w�i�摜���ǂ���
{
	switch( key )
	{
	case Q:
	case W:
	case E:
	case R:
	case T:
	case Y:
	case U:
	case I:
	case O:
	case P:
		if( back )
			return ( 6 + 45 * key );
		else
			return ( 10 + 45 * key );
		break;
	case A:
	case S:
	case D:
	case F:
	case G:
	case H:
	case J:
	case K:
	case L:
		if( back )
			return ( 26 + 45 * ( key - A ) );
		else
			return ( 30 + 45 * ( key - A ) );
		break;
	case Z:
	case X:
	case C:
	case V:
	case B:
	case N:
	case M:
		if( back )
			return ( 46 + 45 * ( key - Z ) );
		else
			return ( 50 + 45 * ( key - Z ) );
		break;
	}
}
int KeyDef_Y( int key, int back )	//�����F�L�[�ԍ�, �w�i�摜���ǂ���
{
	switch( key )
	{
	case Q:
	case W:
	case E:
	case R:
	case T:
	case Y:
	case U:
	case I:
	case O:
	case P:
		if( back )
			return 66;
		else
			return 70;
		break;
	case A:
	case S:
	case D:
	case F:
	case G:
	case H:
	case J:
	case K:
	case L:
		if( back )
			return 121;
		else
			return 125;
		break;
	case Z:
	case X:
	case C:
	case V:
	case B:
	case N:
	case M:
		if( back )
			return 176;
		else
			return 180;
		break;
	}
}

/* �y�֐��z���m��Ԋm�F */
void SolCheck()
{
	int i;

	for( i = 0; i < 20; i++ )
	{
		if( sol[i].Num >= 0 )
		{
			if( sol[i].y < (GROUND - 32) )							//���~���f
			{
				sol[i].Down = 1;
				sol[i].Forward = 0;
			}
			else if( sol[i].y == (GROUND - 32) )					//�O�i���f
			{
				sol[i].Down = 0;
				sol[i].Forward = 1;
			}
			if( sol[i].x + 32 > TARGET_X )							//�G��U�����f
				sol[i].DAttack = 1;
		}
	}
}

/* �y�֐��z�U���m�F */
void AttackCheck()
{
	int i, j;

	for( i = 0; i < 20; i++ )
	{
		for( j = 0; j < 20; j++ )
		{
			if( sol[i].Forward && sol[i].Num >= 0 && ene[j].Num >= 0 && sol[i].x < ene[j].x && sol[i].x + 32 > ene[j].x )	//�U�����f
			{
				sol[i].Attack = 1;
				sol[i].Attacknum = j;
				ene[j].Attack = 1;
				ene[j].Attacknum = i;
			}
		}
	}
}

/* �y�֐��z���m�ړ�(���~) */
void DownMoveSol()
{
	int i;

	for( i = 0; i < 20; i++ )
	{
		if( sol[i].Down )
		{
			sol[i].y++;
			if( sol[i].y > (GROUND - 32) )
				sol[i].y = GROUND - 32;

			switch( sol[i].Num )								//�摜
			{
			case Q:
			case W:
			case E:
			case R:
				sol[i].grp = key_QWER[ 1 + sol[i].Num * 4 ];
				break;
			case T:
			case Y:
			case U:
			case I:
				sol[i].grp = key_TYUI[ 1 + ( sol[i].Num - T ) * 4 ];
				break;
			case O:
			case P:
			case A:
			case S:
				sol[i].grp = key_OPAS[ 1 + ( sol[i].Num - O ) * 4 ];
				break;
			case D:
			case F:
			case G:
			case H:
				sol[i].grp = key_DFGH[ 1 + ( sol[i].Num - D ) * 4 ];
				break;
			case J:
			case K:
			case L:
			case Z:
				sol[i].grp = key_JKLZ[ 1 + ( sol[i].Num - J ) * 4 ];
				break;
			case X:
			case C:
			case V:
			case B:
				sol[i].grp = key_XCVB[ 1 + ( sol[i].Num - X ) * 4 ];
				break;
			case N:
			case M:
				sol[i].grp = key_NM[ 1 + ( sol[i].Num - N ) * 4 ];
				break;
			}
		}
	}
}

/* �y�֐��z���m�ړ�(�O�i) */
void ForwardMoveSol()
{
	int i;

	for( i = 0; i < 20; i++ )
	{
		if( sol[i].Forward )
		{
			if( !( sol[i].Attack ) && !( sol[i].DAttack ) )
				sol[i].x += 1 + effect_speed;

			switch( sol[i].Num )								//�摜
			{
			case Q:
			case W:
			case E:
			case R:
				sol[i].grp = key_QWER[ 1 + sol[i].Num * 4 + sol[i].grpnum ];
				break;
			case T:
			case Y:
			case U:
			case I:
				sol[i].grp = key_TYUI[ 1 + ( sol[i].Num - T ) * 4 + sol[i].grpnum ];
				break;
			case O:
			case P:
			case A:
			case S:
				sol[i].grp = key_OPAS[ 1 + ( sol[i].Num - O ) * 4 + sol[i].grpnum ];
				break;
			case D:
			case F:
			case G:
			case H:
				sol[i].grp = key_DFGH[ 1 + ( sol[i].Num - D ) * 4 + sol[i].grpnum ];
				break;
			case J:
			case K:
			case L:
			case Z:
				sol[i].grp = key_JKLZ[ 1 + ( sol[i].Num - J ) * 4 + sol[i].grpnum ];
				break;
			case X:
			case C:
			case V:
			case B:
				sol[i].grp = key_XCVB[ 1 + ( sol[i].Num - X ) * 4 + sol[i].grpnum ];
				break;
			case N:
			case M:
				sol[i].grp = key_NM[ 1 + ( sol[i].Num - N ) * 4 + sol[i].grpnum ];
				break;
			}

			if( loopcount % 10 == 0 )
			{
				switch( sol[i].grpnum )
				{
				case 0:
					if( !( sol[i].Attack || sol[i].DAttack ) )
						sol[i].grpnum = 1;
					else
						sol[i].grpnum = 2;
					break;
				case 1:
				case 2:
					sol[i].grpnum = 0;
					break;
				}
			}
		}
	}
}

/* �y�֐��z�G�ړ� */
void EnemyMove()
{
	int i;

	for( i = 0; i < 20; i++ )
	{
		if( ene[i].Num >= 0 && ene[i].x < USER_X )			//���݂��{���n���B
			ene[i].DAttack = 1;
		else if( ene[i].Num >= 0 && ene[i].x >= USER_X )	//���݂��{���n�����B
			ene[i].DAttack = 0;

		if( ene[i].Num >= 0 && !( ene[i].Attack ) && !( ene[i].DAttack ) )	//���݂���U�������{���n�����B
			ene[i].x--;

		switch( ene[i].Num )								//�摜
		{
		case 0:
			ene[i].grp = enemy[ 0 + ene[i].grpnum ];
			break;
		case 1:
			ene[i].grp = enemy[ 4 + ene[i].grpnum ];
			break;
		case 2:
			ene[i].grp = enemy[ 8 + ene[i].grpnum ];
			break;
		}

		if( loopcount % 10 == 0 )
		{
			switch( ene[i].grpnum )
			{
			case 0:
				ene[i].grpnum = 1;
				break;
			case 1:
				ene[i].grpnum = 2;
				break;
			case 2:
				if( !( ene[i].Attack || ene[i].DAttack ) )
					ene[i].grpnum = 0;
				else
					ene[i].grpnum = 3;
				break;
			case 3:
				ene[i].grpnum = 0;
				break;
			}
		}
	}
}

/* �y�֐��z�A�C�e���擾 */
void GetItem()
{
	int i, j;
	static int itemget = 0;	//�A�C�e���擾�t���O

	for( i = 0; i < 20; i++ )
	{
		if( sol[i].Num >= 0 && sol[i].Forward )
		{
			for( j = 0; j < 3; j++ )
			{
				if( item[j].Num && sol[i].x < item[j].x && sol[i].x + 32 > item[j].x )
				{
					itemget = 1;

					if( item[j].Num == WALL )
						wall_num = j;

					PlaySoundMem( se.ItemGet, DX_PLAYTYPE_BACK );
				}
			}
		}
	}

	if( itemget )
	{
		for( i = 0; i < 3; i++ )
			EffectItem( item[i].Num );

		itemget = 0;

		putitem = 1;
	}
}

/* �y�֐��z�A�C�e������ */
void EffectItem( int itemnum )
{
	int i;

	switch( itemnum )
	{
	case EMPTY:		//��
		return;
	case POWER:		//�U���͋���
		effect_power += 10;
		break;
	case STAMINA:	//�X�^�~�i����
		effect_stamina += 500;
		break;
	case SPEED:		//�X�s�[�h����
		effect_speed++;
		break;
	case SERVER:	//�T�[�o��
		life += 200000;
		if( life > 1000000 )
			life = 1000000;
		break;
	case MEMORY:	//�������[�S��
		memory = memory_max;
		break;
	case WALL:		//�ǐ���
		wall_count = 10;
		break;
	case ALL:		//�S����
		SolInit();
		EneInit();
		break;
	}

	for( i = 0; i < 3; i++ )
		item[i].Num = EMPTY;	//�A�C�e���g�p��A��ɂ���
}

/* �y�֐��z�Ǐ��� */
void Wall()
{
	int i;

	if( wall_count )
	{
		if( loopcount % 100 == 0 )
			wall_count--;

		for( i = 0; i < 20; i++ )
		{
			if( sol[i].Forward && sol[i].x + 32 > item[ wall_num ].x && sol[i].x < item[ wall_num ].x )
			{
				sol[i].x = item[ wall_num ].x - 32;
				sol[i].Attack = 0;
			}
			if( ene[i].x + 32 > item[ wall_num ].x + 20 && ene[i].x < item[ wall_num ].x + 20 )
			{
				ene[i].x = item[ wall_num ].x + 20;
				ene[i].Attack = 0;
			}
		}
	}
}

/* �y�֐��z�U�� */
void Attack()
{
	int i;

	for( i = 0; i < 20; i++ )
	{
		if( sol[i].Attack )		//�X�^�~�i�v�Z
		{
			ene[ sol[i].Attacknum ].Stamina -= sol[i].Power;
		}
		if( ene[i].Attack )		//
		{
			sol[ ene[i].Attacknum ].Stamina -= ene[i].Power;
		}
		if( sol[i].DAttack )	//���C�t�v�Z
			enemy_life -= sol[i].Power;
		if( ene[i].DAttack )	//
			life -= ene[i].Power;
	}
}

/* �y�֐��z���ݔ��� */
void ExistJudge()
{
	int i, j;

	for( i = 0; i < 20; i++ )
	{
		if( sol[i].Stamina <= 0 )	//�X�^�~�i��0�ȉ��̎��ɑ��݂��Ȃ��Ȃ�
		{
			sol[i].Num = -1;
			sol[i].Attack = 0;
			sol[i].DAttack = 0;
			sol[i].x = 0;

			for( j = 0; j < 20; j++ )
			{
				if( ene[j].Attacknum == i )
					ene[j].Attack = 0;
			}
		}
		if( ene[i].Stamina <= 0 )	//
		{
			ene[i].Num = -1;
			ene[i].Attack = 0;
			ene[i].DAttack = 0;
			ene[i].x = 0;

			for( j = 0; j < 20; j++ )
			{
				if( sol[j].Attacknum == i )
					sol[j].Attack = 0;
			}
		}
	}
}

/* �y�֐��z���s���� */
void LifeJudge()
{
	if( life <= 0 )			//�����̃��C�t��0�ȉ��̎��ɃQ�[���I�[�o�[
	{
		scene = GAMEOVER;
		PlaySoundMem( se.GameOver, DX_PLAYTYPE_BACK );
		StopMusic();
	}

	if( enemy_life <= 0 )	//�G�̃��C�t��0�ȉ��̎��ɃQ�[���N���A
	{
		scene = GAMECLEAR;
		PlaySoundMem( se.GameClear, DX_PLAYTYPE_BACK );
		StopMusic();
	}
}

/* �y�֐��z���C���Q�[���`�� */
void MainGame_Draw()
{
	int i;

	switch( map )							//�w�i�\��
	{
	case MONITOR:
		DrawGraph( 0, 0, grp.Map1, false );
		break;
	case NOTE:
		DrawGraph( 0, 0, grp.Map2, false );
		break;
	case DESK:
		DrawGraph( 0, 0, grp.Map3, false );
		break;
	case CYBER:
		DrawGraph( 0, 0, grp.Map4, false );
		break;
	case CMD:
		DrawGraph( 0, 0, grp.Map5, false );
		break;
	}

	for( i = 0; i < 26; i++ )
	{
		DrawGraph( KeyDef_X( i, 1 ), KeyDef_Y( i, 1 ), grp.KeyBack, true );									//�L�[�w�i�\��

		switch( i )																							//�L�[�����\��
		{
		case Q:
		case W:
		case E:
		case R:
			DrawGraph( KeyDef_X( i, 0 ), KeyDef_Y( i, 0 ), key_QWER[ i * 4 ], true );
			break;
		case T:
		case Y:
		case U:
		case I:
			DrawGraph( KeyDef_X( i, 0 ), KeyDef_Y( i, 0 ), key_TYUI[ ( i - T ) * 4 ], true );
			break;
		case O:
		case P:
		case A:
		case S:
			DrawGraph( KeyDef_X( i, 0 ), KeyDef_Y( i, 0 ), key_OPAS[ ( i - O ) * 4 ], true );
			break;
		case D:
		case F:
		case G:
		case H:
			DrawGraph( KeyDef_X( i, 0 ), KeyDef_Y( i, 0 ), key_DFGH[ ( i - D ) * 4 ], true );
			break;
		case J:
		case K:
		case L:
		case Z:
			DrawGraph( KeyDef_X( i, 0 ), KeyDef_Y( i, 0 ), key_JKLZ[ ( i - J ) * 4 ], true );
			break;
		case X:
		case C:
		case V:
		case B:
			DrawGraph( KeyDef_X( i, 0 ), KeyDef_Y( i, 0 ), key_XCVB[ ( i - X ) * 4 ], true );
			break;
		case N:
		case M:
			DrawGraph( KeyDef_X( i, 0 ), KeyDef_Y( i, 0 ), key_NM[ ( i - N ) * 4 ], true );
			break;
		}
	}

	if( space_y + 32 <= GROUND )
		DrawGraph( 160, space_y, grp.Space, true );

	DrawGraph( 0, GROUND - 92, grp.Server1, true );
	DrawGraph( TARGET_X, GROUND - 75, grp.Server2, true );


	DrawGraph( 278, 430, grp.KeyBack, true );
	DrawGraph( 330, 430, grp.KeyBack, true );
	DrawString( 286, 455, "min", GetColor( 255, 255, 255 ) );
	DrawString( 338, 455, "sec", GetColor( 255, 255, 255 ) );
	DrawFormatString( 286, 440, GetColor( 255, 255, 255 ), "%2d", time / 60000 );	//���ԕ\��
	DrawFormatString( 338, 440, GetColor( 255, 255, 255 ), "%2d", time % 60000 / 1000 );

	for( i = 0; i < 3; i++ )
	{
		if( item[i].Num )
			DrawGraph( item[i].x, GROUND - 30, itemgrp[item[i].Num - 1], true );							//�A�C�e���\��
	}

	if( wall_count )
	{
		DrawGraph( item[ wall_num ].x, GROUND - 60, grp.Wall, true );										//�Ǖ\��
		DrawFormatString( item[ wall_num ].x, GROUND - 75, GetColor( 50, 80, 80 ), "%2d", wall_count );		//
	}

	for( i = 0; i < 20; i++ )
	{
		if( sol[i].Num >= 0 )
			DrawGraph( sol[i].x, sol[i].y, sol[i].grp, true);												//���m�\��
		if( ene[i].Num >= 0 )
			DrawGraph( ene[i].x, GROUND - 32, ene[i].grp, true );											//�G�\��
	}

	DrawGraph( 10, 10, grp.Level, true );																	//�e�ڍ׏��\��
	for( i = 0; i < lv; i++ )
		DrawGraph( 130 + 40 * i, 10, grp.Star, true );														//
	DrawGraph( 400, 10, grp.Memory, true );																	//
	DrawFormatString( 400, 50, GetColor( 200, 200, 200 ), "%d/%d", memory, memory_max );					//
	switch( lv )
	{
	case 1:
		DrawBox( 520, 15, 520 + memory, 45, GetColor( 50, 200, 50 ), true );
		break;
	case 2:
		DrawBox( 520, 15, 520 + memory / 2, 45, GetColor( 50, 200, 50 ), true );
		break;
	case 3:
		DrawBox( 520, 15, 520 + memory / 5, 45, GetColor( 50, 200, 50 ), true );
		break;
	case 4:
		DrawBox( 520, 15, 520 + memory / 7, 45, GetColor( 50, 200, 50 ), true );
		break;
	case 5:
		DrawBox( 520, 15, 520 + memory / 10, 45, GetColor( 50, 200, 50 ), true );
		break;
	}
	for( i = 0; i < 3; i++ )
		DrawGraph( 470, 70 + i * 30, statuslv[i], true );													//
	DrawFormatString( 620, 80, GetColor( 200, 50, 50 ), "%2d", effect_power / 10 + 1 );						//
	DrawFormatString( 620, 110, GetColor( 200, 180, 50 ), "%2d", effect_stamina / 500 + 1 );				//
	DrawFormatString( 620, 140, GetColor( 50, 50, 200 ), "%2d", effect_speed + 1 );							//

	for( i = 0; i < 2; i++ )
		DrawGraph( 470, 180 + i * 30, solene[i], true );													//
	DrawFormatString( 570, 187, GetColor( 50, 100, 50 ), "%2d/20", solcount );								//
	DrawFormatString( 570, 217, GetColor( 20, 20, 20 ), "%2d/20", enecount );								//

	DrawBox( 10, GROUND + 20, 10 + life / 10000, GROUND + 50, GetColor( 200, 50, 50 ), true );				//���C�t�\��
	DrawBox( 530, GROUND + 20, 530 + enemy_life / 10000, GROUND + 50, GetColor( 50, 50, 200 ), true );		//
}

/* �y�֐��z�|�[�Y��� */
void Pause()
{
	DrawGraph( 0, 0, grp.Pause, false );

	if( Key[ KEY_INPUT_TAB ] )	//�^�u�L�[�Ő؂�ւ�
	{
		PlaySoundMem( se.Back, DX_PLAYTYPE_NORMAL );
		scene = MAINGAME;
	}

	DrawGraph( 220, 300, grp.HighScoreBoard, true );						//�n�C�X�R�A�\��
	DrawFormatString( 243, 325, GetColor( 0, 0, 0 ), "%4d", highscore );	//
	DrawGraph( 340, 300, grp.ScoreBoard, true );							//�X�R�A�\��
	DrawFormatString( 363, 325, GetColor( 0, 0, 0 ), "%4d", score );		//
}

/* �y�֐��z�Q�[���I�[�o�[ */
void Gameover()
{
	if( Key[ KEY_INPUT_RETURN ] )
	{
		scene = TITLE;
		StartInit();	//������
		SolInit();		//
		EneInit();		//
		ItemInit();		//
		PlaySoundMem( se.Decide, DX_PLAYTYPE_NORMAL );
		PlayMusic( 0 );
	}

	DrawGraph( 0, 0, grp.GameOver, false );
}

/* �y�֐��z�Q�[���N���A */
void Gameclear()
{
	if( Key[ KEY_INPUT_RETURN ] )
	{
		scene = TITLE;
		StartInit();	//������
		SolInit();		//
		EneInit();		//
		ItemInit();		//
		PlaySoundMem( se.Decide, DX_PLAYTYPE_NORMAL );
		PlayMusic( 0 );

		if( score > highscore )
			highscore = score;	//�n�C�X�R�A�X�V
	}

	DrawGraph( 0, 0, grp.GameClear, false );

	DrawGraph( 280, 300, grp.ScoreBoard, true );										//�X�R�A�\��
	DrawFormatString( 303, 325, GetColor( 0, 0, 0 ), "%4d", score );	//
}

/* �y�֐��z���y�Đ� */
void PlayMusic( int select )	//�����F���y�I����ʂ��ǂ���
{
	if( select )
	{
		if( music == 0 )
			StopMusic();
		else if( music == 1 )
			PlayMusic( "KeyBoarDefense_Data/Sound/bgm01.mp3", DX_PLAYTYPE_LOOP );
		else if( music == 2 )
			PlayMusic( "KeyBoarDefense_Data/Sound/bgm02.mp3", DX_PLAYTYPE_LOOP );
		else if( music == 3 )
			PlayMusic( "KeyBoarDefense_Data/Sound/bgm03.mp3", DX_PLAYTYPE_LOOP );
	}
	else
	{
		switch( scene )
		{
		case TITLE:
		case SELECT:
			PlayMusic( "KeyBoarDefense_Data/Sound/titlebgm.mp3", DX_PLAYTYPE_LOOP );
			break;
		case MAINGAME:
			if( music == 0 )
				StopMusic();
			else if( music == 1 )
				PlayMusic( "KeyBoarDefense_Data/Sound/bgm01.mp3", DX_PLAYTYPE_LOOP );
			else if( music == 2 )
				PlayMusic( "KeyBoarDefense_Data/Sound/bgm02.mp3", DX_PLAYTYPE_LOOP );
			else if( music == 3 )
				PlayMusic( "KeyBoarDefense_Data/Sound/bgm03.mp3", DX_PLAYTYPE_LOOP );
			break;
		}
	}
}