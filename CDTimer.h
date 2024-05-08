#pragma once
#include "Engine/GameObject.h"

class CDTimer :
    public GameObject
{
private:
	double CountDownTimer_;  //���݂̎c�莞��
	double TIMER_INIT_TIME_; //��������
	bool isTimerRun_;//�^�C�}�[�������Ă��邩�ǂ����H
	DWORD oldTime_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	CDTimer(GameObject *parent);
	CDTimer(GameObject *parent, double _initTime);


	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

public:

	bool IsTimeOver();//�^�C�}�[�͂O�ɂȂ�܂������H�x�d�r�H�m�n�H
	void ResetTimer();//�^�C�}�[���������Ԃɖ߂�
	void StartTimer();//�^�C�}�[���X�^�[�g���܂�
	void StopTimer();//�^�C�}�[���X�g�b�v���܂�
	bool IsTimerRun() { return(isTimerRun_); }
	void SetInitTime(double cdTime) { TIMER_INIT_TIME_ = cdTime; ResetTimer(); }
	double GetTime() { return(CountDownTimer_); }
};

