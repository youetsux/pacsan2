#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"




Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1), moveDir_(MNONE),cdtimer_(nullptr)
{
}

void Player::Initialize()
{
	cdtimer_ = new CDTimer(this, DTIME);
	cdtimer_->StopTimer();
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);
}

void Player::GetInputData()
{
	//moveDir_ = MNONE;
	
	if (Input::IsKeyDown(DIK_LEFT) || Input::IsKeyDown(DIK_D))
	{
		moveDir_ = MLEFT;
		cdtimer_->ResetTimer();
		cdtimer_->StartTimer();
		V[0] = XMLoadFloat3(&transform_.position_);
		V[1] = V[0] + moveVec[moveDir_];
	}
	if (Input::IsKeyDown(DIK_RIGHT) || Input::IsKeyDown(DIK_A))
	{
		moveDir_ = MRIGHT;
		cdtimer_->ResetTimer();
		cdtimer_->StartTimer();
		V[0] = XMLoadFloat3(&transform_.position_);
		V[1] = V[0] + moveVec[moveDir_];
	}
}

void Player::Update()
{
	cdtimer_->Update();//�J�E���g�_�E��
	//Debug::Log(cdtimer_->IsTimerRun(), true);

	GetInputData();
	if (moveDir_ == MNONE)
		return;

	if (cdtimer_->IsTimerRun())
	{
		float lerpRate = 1.0f - cdtimer_->GetTime() / DTIME;
		XMVECTOR pos = XMVectorLerp(V[0], V[1], lerpRate);
		XMStoreFloat3(&transform_.position_, pos);
		//�����̃R�����g���O���Ɖ�]�p��
		// ��ԃ��[�g���� 0�`0.5�`1�̎���
		// Sin�֐����g����0�` 90�`0�x�̋Ȑ���Ԃ�����
		//float rotAngle = 90.0 * sin(lerpRate * XM_PI);
		//
		//if (XMVectorGetX(V[1]) < XMVectorGetX(V[0]))
		//{
		//	rotAngle = -rotAngle;
		//}
		//transform_.rotate_.y = rotAngle;
	}

	if (cdtimer_->GetTime() <= 0) {
		moveDir_ = MNONE;
		cdtimer_->StopTimer();
	}
	//���E�L�[�iA,D)�ō��E�i�����W�Łj2.0�ړ�����
}

void Player::Draw()
{
	Model::SetTransform(hModel_, this->transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
