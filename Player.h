#pragma once
#include "Engine/GameObject.h"
#include "CDTimer.h"

namespace
{
	enum MOVEDIR
	{
		MLEFT,MRIGHT,MNONE,MMAX
	};
	XMVECTOR moveVec[MMAX] = { {2,0,0},{-2,0,0},{ 0,0,0 } };
	const float DTIME{ 1.0 };
}


class Player :
    public GameObject
{
	int hModel_;
	void GetInputData();
	MOVEDIR moveDir_;
	XMVECTOR V[2];
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
	CDTimer* cdtimer_;
};

